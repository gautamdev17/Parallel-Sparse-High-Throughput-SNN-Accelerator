"""
ours.py -- cycle model of the DAC2027 design (DAC2027_accelerator_explained_rows.pdf):
weight-stationary R x C array, spike trains stream RIGHT along rows, running sums move DOWN columns,
every PE has T gated adders (all timesteps in one cycle), filters packed offline into shared columns
(filter label per weight), pixels packed at run time into groups of up to G (pixel label per spike bit).

Two implementations that must agree cycle for cycle (verify.py checks it):
  run_layer_stepped : cycle-stepped PE-level simulator. Moves spike groups and running-sum bundles through
                      PE registers, adds with the T adders, routes by (filter label, pixel label), checks that
                      no adder is used twice in a cycle and that every PE holds the right weight, runs the edge
                      FIFOs and the LIF sweep, and returns bit-exact output spikes. Small layers only.
  run_layer_fast    : the same schedule computed per pass (no per-PE stepping). Used for VGG16/ResNet18.

Timing rules (both implementations):
  * Layer = output tiles of Mt filters x Nt pixels (output buffer Mt*Nt*T*24 bit = 192 KB at 64x128),
    processed one after another. Each output tile walks all K-tiles (R consecutive inputs).
  * K-tile: filters of the m-block with >=1 non-zero weight in the K-tile are packed offline (first-fit
    decreasing, <= F per column, at most one non-zero per row per column) -> P_w packed columns ->
    ceil(P_w / C) passes. K-tiles with no non-zero weight are skipped (known offline, nothing is read).
  * Packer: reads the K-tile's pixel spike trains at pp pixel slices/cycle, one K-tile at a time (a K-tile of n
    pixels takes ceil(n/pp) cycles, as in the RTL packer), drops pixels with no spike in the K-tile, first-fit
    into <= G pixels/group with a window of W_open open groups. Double-buffered: packing K-tile i starts when
    K-tile i-1 is packed and K-tile i-2's groups have all entered the array (released the cycle after its last one).
  * Pass j with P_j groups, one group per cycle: a group injected at cycle x enters row k at x + k and PE (k,c) at
    x + k + c; its running sums leave column c and reach the edge FIFO at x + R + c. Without backpressure stalls
    group g of pass j is injected at s_j + g.
    s_j >= pack done of its K-tile;  s_{j+1} >= max(e_j + 1, s_j + L) with e_j the injection of pass j's last group
    and L = ceil(R*C/Lw) when weights are double-buffered (shadow register per PE, loaded along the wavefront right
    after the PE swaps), or s_{j+1} >= e_j + 1 + (R-1) + (C-1) + L without shadow registers.
  * Edge-FIFO backpressure (D entries per column): a group is injected at cycle x only if, for every column c,
    FIFO occupancy at the end of x-1 + entries of the groups injected in [x-R-c, x-1] (still above the FIFO) +
    the group's own entries for column c <= D; otherwise the feeder holds it (a stall cycle). A group's entries for
    a column are the distinct (filter, pixel) slots it adds to, known at injection from the group's spike bits and
    labels and the pass's weights. No pop is assumed, so the FIFO never overflows.
  * Edge unit: one FIFO per column, up to E read-modify-writes per column per cycle into the output buffer,
    only for running sums that received at least one addition. An entry arriving at cycle a is written into the
    FIFO at the end of a and can be served from a+1. Same-address arbiter (as in the RTL): column 0 first, then
    FIFO order; an entry whose (filter, pixel) equals an earlier offered entry's waits, with the entries behind it.
    Injection, packer and edge entry by entry, per output tile, in edge_sim.c (ctypes).
  * After the last K-tile of an output tile (including the packer finishing K-tiles that turn out empty) and empty
    edge FIFOs: LIF sweep over the dirty entries, lif_units per cycle. Then the next output tile starts (single output buffer) or, with obuf_double,
    the next tile's passes start right away and only the buffer reuse two tiles later waits.
"""
import math
from dataclasses import dataclass, replace
import numpy as np

from workload import lif as lif_ref


@dataclass(frozen=True)
class Cfg:
    R: int = 4            # rows = inputs per K-tile
    C: int = 4            # columns
    T: int = 8            # timesteps = adders per PE
    F: int = 4            # max filters sharing one column
    G: int = 4            # max pixels per group
    W_open: int = 4       # packer: open groups searched per pixel
    pp: int = 8           # packer: pixel slices scanned per cycle (all lanes)
    pk_lanes: int = 8     # packer lanes, each packing its own K-tile at pp/pk_lanes slices per cycle
    lif_lat: int = None   # LIF result latency beyond the sweep: 1 (output-buffer read) + T/2 - 1 (ours_lif: T/2
                          # stages of 2 timesteps) = T/2; None -> T // 2 (4 at T = 8)
    Mt: int = 64          # output tile: filters
    Nt: int = 128         # output tile: pixels
    E: int = 4            # edge unit: running-sum writes per column per cycle
    D: int = 80           # edge FIFO entries per column (backpressure keeps occupancy <= D); 0 = unbounded
    Lw: int = 16          # weights (+labels) loaded per cycle
    shadow: bool = True   # double-buffered weight registers
    obuf_double: bool = False
    lif_units: int = 16
    theta: float = 64.0
    leak: float = 0.5

    def __post_init__(self):
        if self.lif_lat is None:
            object.__setattr__(self, "lif_lat", self.T // 2)

    @property
    def adders(self):
        return self.R * self.C * self.T

    @property
    def L(self):
        return math.ceil(self.R * self.C / self.Lw)


# ------------------------------------------------------------------ packing
def pack_weights(Wt, F):
    """Wt: (m, R) weights of one K-tile. -> list of columns, each a list of local filter ids.
    First-fit decreasing on row-occupancy masks; filters in a column never share a non-zero row."""
    R = Wt.shape[1]
    occ = ((Wt != 0) * (1 << np.arange(R))).sum(1)
    nnz = (Wt != 0).sum(1)
    order = [int(f) for f in np.argsort(-nnz, kind="stable") if nnz[f] > 0]
    cols, masks = [], []
    for f in order:
        m = int(occ[f])
        for i in range(len(cols)):
            if len(cols[i]) < F and not (masks[i] & m):
                cols[i].append(f)
                masks[i] |= m
                break
        else:
            cols.append([f])
            masks.append(m)
    return cols


def tile_masks(St, T):
    """St: (R, n) uint8 spike trains -> python ints, bit (r*T + t) = spike of row r at timestep t."""
    R = St.shape[0]
    m = np.zeros(St.shape[1], dtype=np.uint64)
    for r in range(R):
        m |= St[r].astype(np.uint64) << np.uint64(r * T)
    return m.tolist()


def pack_spikes(masks, G, W_open):
    """first-fit with a window of W_open open groups; pixels with no spike are dropped.
    -> list of groups (lists of local pixel ids), in the order they leave the packer."""
    done, open_g = [], []          # open_g entries: [mask, pixels]
    for p, m in enumerate(masks):
        if m == 0:
            continue
        for i, g in enumerate(open_g):
            if not (g[0] & m):
                g[0] |= m
                g[1].append(p)
                if len(g[1]) == G:
                    done.append(open_g.pop(i)[1])
                break
        else:
            if len(open_g) == W_open:
                done.append(open_g.pop(0)[1])
            open_g.append([m, [p]])
    done += [g[1] for g in open_g]
    return done


# ------------------------------------------------------------------ shared tile plan
class LayerPlan:
    """offline weight packing per (m-block, K-tile), cached and reused by every n-block."""

    def __init__(self, W, cfg):
        self.W, self.cfg = W, cfg
        M, K = W.shape
        self.nK = math.ceil(K / cfg.R)
        self.mblocks = [(m0, min(m0 + cfg.Mt, M)) for m0 in range(0, M, cfg.Mt)]
        self.cols = {}
        for bi, (m0, m1) in enumerate(self.mblocks):
            for kt in range(self.nK):
                k0, k1 = kt * cfg.R, min(kt * cfg.R + cfg.R, K)
                Wt = np.zeros((m1 - m0, cfg.R), dtype=W.dtype)
                Wt[:, :k1 - k0] = W[m0:m1, k0:k1]
                self.cols[bi, kt] = (pack_weights(Wt, cfg.F), Wt)


def _passes(cols, C):
    return [cols[i:i + C] for i in range(0, len(cols), C)]


class _Packer:
    """packer timing (transaction level, identical in all simulators and the RTL testbench). `lanes` independent
    lanes; each packs one K-tile at a time at ppl = pp / lanes pixel slices per cycle (a K-tile of n pixels takes
    ceil(n / ppl) cycles; its groups are usable from the cycle after its last slice). K-tiles start in scan order on
    the lane that is free first, once the group-buffer slot of K-tile i - NS (NS = lanes + 2 slots) is released."""

    def __init__(self, pp, lanes=1):
        self.lanes = max(1, min(lanes, pp))
        self.ppl = pp // self.lanes
        self.ns = self.lanes + 2
        self.lane, self.last, self.free = [0] * self.lanes, 0, [0] * self.ns

    def pack(self, n):
        i = min(range(self.lanes), key=lambda l: self.lane[l])
        start = max(self.last, self.lane[i], self.free[-self.ns])
        self.last = start
        self.lane[i] = start + -(-n // self.ppl)
        return self.lane[i]

    def release(self, t):
        self.free.append(t)

    def state(self):
        return [self.lanes, self.ns, self.last] + self.lane + self.free[-self.ns:]

    def set_state(self, st):
        self.last = st[2]
        self.lane = list(st[3:3 + self.lanes])
        self.free = list(st[3 + self.lanes:])


_EDGE = None


def _edge_lib():
    global _EDGE
    if _EDGE is None:
        import ctypes, os, subprocess
        here = os.path.dirname(os.path.abspath(__file__))
        src, lib = os.path.join(here, "edge_sim.c"), os.path.join(here, "libedge_sim.so")
        if not os.path.exists(lib) or os.path.getmtime(lib) < os.path.getmtime(src):
            subprocess.run(["cc", "-O2", "-shared", "-fPIC", "-o", lib, src], check=True)
        _EDGE = ctypes.CDLL(lib)
        L, P, I = ctypes.c_long, ctypes.c_void_p, ctypes.c_int
        _EDGE.tile_sim.restype = None
        _EDGE.tile_sim.argtypes = [I, P, P, L, P, P, I, I, I, I, I, I, L, P, P]
    return _EDGE


def tile_run(P, npass, pkc, n, addr, cfg, t0, packer):
    """one output tile: injection with edge-FIFO backpressure, packer, edge unit (edge_sim.c).
    P, npass: per scanned K-tile; n: entries per (unit, column); addr: their addresses in (unit, column, slot) order.
    -> dict(edge_end, arr_end, s_next, pk_last, qmax, conflicts, stalls); updates the packer state."""
    P = np.ascontiguousarray(P, dtype=np.int32)
    npass = np.ascontiguousarray(npass, dtype=np.int32)
    n = np.ascontiguousarray(n, dtype=np.int32)
    addr = np.ascontiguousarray(addr, dtype=np.int64)
    pk = np.array(packer.state(), dtype=np.int64)
    out = np.zeros(7, dtype=np.int64)
    _edge_lib().tile_sim(len(P), P.ctypes.data, npass.ctypes.data, pkc, n.ctypes.data, addr.ctypes.data,
                         cfg.R, cfg.C, cfg.E, cfg.D, cfg.L, int(cfg.shadow), t0, pk.ctypes.data, out.ctypes.data)
    packer.set_state([int(v) for v in pk])
    return dict(zip(("edge_end", "arr_end", "s_next", "pk_last", "qmax", "conflicts", "stalls"), map(int, out)))


# ------------------------------------------------------------------ fast model
def run_layer_fast(W, S, cfg, plan=None):
    """-> dict(cycles, passes, groups, pixel_steps, pixels_nonzero, fifo_max, ...) for one layer."""
    plan = plan or LayerPlan(W, cfg)
    R, C, T = cfg.R, cfg.C, cfg.T
    K, N = S.shape
    nblocks = [(n0, min(n0 + cfg.Nt, N)) for n0 in range(0, N, cfg.Nt)]
    Sp = np.zeros((plan.nK * R, N), dtype=S.dtype)
    Sp[:K] = S
    packer = _Packer(cfg.pp, cfg.pk_lanes)
    t_start, end_all = 0, 0
    obuf_free = [0, 0]
    st = dict(passes=0, groups=0, ktiles_run=0, pixels_nonzero=0, rmw=0, lif=0, fifo_max=0, edge_conflicts=0,
              fifo_stalls=0)
    G = cfg.G
    for bi, (m0, m1) in enumerate(plan.mblocks):
        for (n0, n1) in nblocks:
            nn = n1 - n0
            start = max(t_start, obuf_free[-2]) if cfg.obuf_double else t_start
            kP, kNP, ns, ads = [], [], [], []                   # per scanned K-tile; per-unit entry counts/addresses
            dirty = np.zeros((m1 - m0, nn), dtype=bool)
            for kt in range(plan.nK):
                cols, Wt = plan.cols[bi, kt]
                if not cols:
                    continue
                St = Sp[kt * R:(kt + 1) * R, n0:n1]
                masks = tile_masks(St, T)
                groups = pack_spikes(masks, cfg.G, cfg.W_open)
                st["pixels_nonzero"] += sum(1 for m in masks if m)
                if not groups:
                    kP.append(0); kNP.append(0)
                    continue
                st["ktiles_run"] += 1
                touched = ((Wt != 0).astype(np.float32) @ (St != 0).astype(np.float32)) > 0
                dirty |= touched
                P = len(groups)
                GP = np.full((P, G), -1, dtype=np.int64)
                for g, ps in enumerate(groups):
                    GP[g, :len(ps)] = ps
                fl_all, pj, cj, fij = [], [], [], []
                pas_list = _passes(cols, C)
                for j, pas in enumerate(pas_list):
                    for c, fl in enumerate(pas):
                        for fi, f in enumerate(fl):
                            fl_all.append(f); pj.append(j); cj.append(c); fij.append(fi)
                st["passes"] += len(pas_list)
                st["groups"] += P * len(pas_list)
                kP.append(P); kNP.append(len(pas_list))
                # running-sum entries: unit (pass j, group g) leaves column c R + c cycles after it entered,
                # slots in (fi, pos) order
                fl_all, pj, cj, fij = map(np.array, (fl_all, pj, cj, fij))
                sub = touched[fl_all][:, np.where(GP >= 0, GP, 0)] & (GP >= 0)[None]
                fx, g, pos = np.nonzero(sub)
                unit, col = pj[fx] * P + g, cj[fx]
                o = np.lexsort((fij[fx] * G + pos, col, unit))
                ns.append(np.bincount(unit * C + col, minlength=len(pas_list) * P * C))
                ads.append((fl_all[fx] * 4096 + GP[g, pos])[o])
            edge_end = arr_end = pk_last = array_end = start
            if kP:
                r = tile_run(kP, kNP, -(-nn // packer.ppl), np.concatenate(ns) if ns else np.zeros(0),
                             np.concatenate(ads) if ads else np.zeros(0), cfg, start, packer)
                edge_end, arr_end, pk_last, array_end = r["edge_end"], r["arr_end"], r["pk_last"], r["s_next"]
                st["fifo_max"] = max(st["fifo_max"], r["qmax"])
                st["edge_conflicts"] += r["conflicts"]
                st["fifo_stalls"] += r["stalls"]
                st["rmw"] += int(sum(int(x.sum()) for x in ns))
            nd = int(dirty.sum())
            lif_c = math.ceil(nd / cfg.lif_units)
            st["lif"] += lif_c
            end = max(edge_end, arr_end, start, pk_last) + lif_c + (cfg.lif_lat if lif_c else 0)
            end_all = max(end_all, end)
            if cfg.obuf_double:
                obuf_free.append(end)
                t_start = max(array_end - cfg.L, start)   # next tile's first pass may follow this tile's last pass
            else:
                t_start = end
    st["cycles"] = end_all
    return st


# ------------------------------------------------------------------ cycle-stepped reference
def run_layer_stepped(W, S, cfg):
    """PE-level cycle-stepped simulation. -> (output spike trains (M,N) uint8, sums (M,N,T), stats)."""
    R, C, T = cfg.R, cfg.C, cfg.T
    M, K = W.shape
    N = S.shape[1]
    plan = LayerPlan(W, cfg)
    Sp = np.zeros((plan.nK * R, N), dtype=S.dtype)
    Sp[:K] = S
    nblocks = [(n0, min(n0 + cfg.Nt, N)) for n0 in range(0, N, cfg.Nt)]
    obuf = np.zeros((M, N, T), dtype=np.int64)
    packer = _Packer(cfg.pp, cfg.pk_lanes)
    cyc, end_all, t_start = 0, 0, 0
    obuf_free = [0, 0]
    stats = dict(passes=0, adder_ops=0, fifo_max=0, fifo_stalls=0)

    for bi, (m0, m1) in enumerate(plan.mblocks):
        for (n0, n1) in nblocks:
            nn = n1 - n0
            # ---- build the pass list (what the controller will feed). Packer timing is evaluated lazily,
            # K-tile by K-tile in order, when the feeder reaches a K-tile (it depends on earlier releases).
            passes = []                       # dict(P, w, f, g, kt)
            kt_last = []
            ktq = []                          # K-tiles the packer scans, in order: (kt, first pass id or None)
            for kt in range(plan.nK):
                cols, Wt = plan.cols[bi, kt]
                if not cols:
                    continue
                St = Sp[kt * R:(kt + 1) * R, n0:n1]
                groups = pack_spikes(tile_masks(St, T), cfg.G, cfg.W_open)
                if not groups:
                    ktq.append((kt, None))
                    continue
                ktq.append((kt, len(passes)))
                # per group and row: combined T-bit train + pixel label per bit
                gl = []
                for ps in groups:
                    bits = np.zeros(R, dtype=np.int64)
                    lab = -np.ones((R, T), dtype=np.int64)
                    for p in ps:
                        for r in range(R):
                            v = int(St[r, p])
                            assert not (bits[r] & v), "packer produced a clash"
                            bits[r] |= v
                            for t in range(T):
                                if v >> t & 1:
                                    lab[r, t] = p + n0
                    gl.append((bits, lab))
                for pas in _passes(cols, C):
                    pe_w = np.zeros((R, C), dtype=np.int64)
                    pe_f = -np.ones((R, C), dtype=np.int64)
                    for c, fl in enumerate(pas):
                        for f in fl:
                            for r in np.nonzero(Wt[f])[0]:
                                assert pe_f[r, c] < 0, "two filters share a PE"
                                pe_w[r, c], pe_f[r, c] = Wt[f, r], f + m0
                    passes.append(dict(P=len(gl), w=pe_w, f=pe_f, g=gl, kt=kt,
                                       fi={(f + m0, c): i for c, fl in enumerate(pas) for i, f in enumerate(fl)},
                                       pos=[{p + n0: i for i, p in enumerate(ps)} for ps in groups]))
                kt_last.append(len(passes) - 1)
            first_of = {p0: None for _, p0 in ktq if p0 is not None}
            qi = [0]
            pk_last = [None]

            skipped = [-1]

            def pack_until(pass_id):
                """run the packer over queued K-tiles up to the one that owns pass_id; -> the cycle its first pass may
                start: its pack-done, and not in the cycle an empty K-tile just before it was found empty (the shadow
                weights loaded speculatively for that K-tile's pass are rewritten then)."""
                while qi[0] < len(ktq):
                    kt, p0 = ktq[qi[0]]
                    qi[0] += 1
                    pk = packer.pack(nn)
                    pk_last[0] = pk
                    if p0 is None:
                        packer.release(pk)
                        skipped[0] = max(skipped[0], pk)
                        continue
                    pk = max(pk, skipped[0] + 1)
                    skipped[0] = -1
                    first_of[p0] = pk
                    if p0 == pass_id:
                        return pk
                raise AssertionError

            def pk_of(pass_id):
                p0 = max(p for p in first_of if p <= pass_id)
                if first_of[p0] is None:
                    pack_until(p0)
                return first_of[p0]

            # ---- cycle loop for this output tile
            start = max(t_start, obuf_free[-2]) if cfg.obuf_double else t_start
            cyc = start
            if not passes:
                end = start
                while qi[0] < len(ktq):          # K-tiles scanned but empty: the tile ends when they are packed
                    pk = packer.pack(nn)
                    packer.release(pk)
                    end = max(end, pk)
                    qi[0] += 1
                end_all = max(end_all, end)
                if cfg.obuf_double:
                    obuf_free.append(end)
                t_start = end
                continue
            spk = [[None] * C for _ in range(R)]   # spike item in PE (k,c): (pass, group)
            bund = [[None] * C for _ in range(R)]  # running-sum bundle in PE (k,c)
            act = -np.ones((R, C), dtype=np.int64)  # active pass id per PE
            shadow = -np.ones((R, C), dtype=np.int64)
            shadow_t = np.zeros((R, C), dtype=np.int64)
            fifo = [[] for _ in range(C)]
            dirty = set()
            j, g = 0, 0                            # next pass / group to inject at row 0
            s = {}                                 # injection start cycle per pass
            allow = start + cfg.L                  # earliest cycle pass j may start
            if passes:
                shadow[:, :] = 0
                shadow_t[:, :] = start + cfg.L - 1
            feed = [[] for _ in range(R)]          # skew registers: row k sees row-0 injection k cycles later
            prev_iss, last_pop = set(), None       # addresses issued last cycle (write in flight); last issue cycle
            sent = {}                              # injection cycle -> entries per column (backpressure credits)

            def entries_of(pas, gj):
                """entries the group's bundle will write into each column FIFO: distinct (filter, pixel) slots that
                get at least one addition (weight != 0 and spike bit set), from the pass weights and the group."""
                bits, lab = pas["g"][gj]
                return tuple(len({(int(pas["f"][k, c]), int(lab[k, t])) for k in range(R) for t in range(T)
                                  if pas["w"][k, c] != 0 and bits[k] >> t & 1}) for c in range(C))

            while True:
                # injection decision at row 0 (spike items for rows k>0 are delayed k cycles by the skew)
                # backpressure: the group may enter only if, for every column, the FIFO occupancy (end of the last
                # cycle) + the entries of the bundles still in the array above it + this group's entries <= D
                inject = None
                if j < len(passes) and cyc >= max(allow, pk_of(j)):
                    need = entries_of(passes[j], g)
                    ok = cfg.D <= 0 or all(len(fifo[c]) + need[c] + sum(sent.get(y, (0,) * C)[c]
                                                                         for y in range(cyc - R - c, cyc)) <= cfg.D
                                           for c in range(C))
                    if not ok:
                        stats["fifo_stalls"] += 1
                    else:
                        if g == 0:
                            s[j] = cyc
                        inject = (j, g)
                        sent[cyc] = need
                        g += 1
                        if g == passes[j]["P"]:
                            nxt = max(cyc + 1, s[j] + cfg.L) if cfg.shadow else cyc + 1 + (R - 1) + (C - 1) + cfg.L
                            if j in kt_last:
                                packer.release(cyc + 1)
                            j, g, allow = j + 1, 0, nxt
                for k in range(R):
                    feed[k].append(inject)
                # shift: new register contents
                new_spk = [[None] * C for _ in range(R)]
                new_bund = [[None] * C for _ in range(R)]
                exits = [None] * C
                for k in range(R):
                    for c in range(C):
                        item = (feed[k][-1 - k] if len(feed[k]) > k else None) if c == 0 else spk[k][c - 1]
                        new_spk[k][c] = item
                for c in range(C):
                    if bund[R - 1][c] is not None:
                        exits[c] = bund[R - 1][c]
                for k in range(R):
                    for c in range(C):
                        item = new_spk[k][c]
                        if item is None:
                            continue
                        pj, gj = item
                        b = {} if k == 0 else bund[k - 1][c]
                        assert b is not None and (k == 0 or b["id"] == item), "sum bundle out of step"
                        if k == 0:
                            b = {"id": item, "sums": {}}
                        else:
                            b = {"id": item, "sums": dict(b["sums"])}
                        # weight swap / check
                        if act[k, c] != pj:
                            assert shadow[k, c] == pj and shadow_t[k, c] < cyc, f"PE({k},{c}) weight for pass {pj} not ready"
                            act[k, c] = pj
                            # load next pass into the freed shadow right behind the wavefront
                            if pj + 1 < len(passes):
                                shadow[k, c] = pj + 1
                                shadow_t[k, c] = cyc + cfg.L - 1
                        pas = passes[pj]
                        w, f = pas["w"][k, c], pas["f"][k, c]
                        bits, lab = pas["g"][gj]
                        if f >= 0 and bits[k]:
                            used = set()
                            for t in range(T):
                                if bits[k] >> t & 1:
                                    assert t not in used
                                    used.add(t)
                                    key = (int(f), int(lab[k, t]))
                                    v = b["sums"].get(key)
                                    v = np.zeros(T, dtype=np.int64) if v is None else v.copy()
                                    v[t] += w
                                    b["sums"][key] = v
                                    stats["adder_ops"] += 1
                        new_bund[k][c] = b
                spk, bund = new_spk, new_bund
                # edge unit: up to E read-modify-writes per column per cycle, from entries written before this
                # cycle; an entry whose (f, p) equals an earlier offered entry's (column 0 first) or an address
                # issued in the previous cycle (write still in flight) waits, with the entries behind it in its FIFO
                offered = [fifo[c][:cfg.E] for c in range(C)]
                seen = []
                pops = []
                for c in range(C):
                    n_ok = 0
                    for e, ((f, p), v) in enumerate(offered[c]):
                        if (f, p) in seen or (f, p) in prev_iss or any(k == (f, p) for k, _ in offered[c][:e]):
                            break
                        n_ok += 1
                    pops.append(n_ok)
                    seen += [k for k, _ in offered[c]]
                cur = set()
                for c in range(C):
                    for _ in range(pops[c]):
                        (f, p), v = fifo[c].pop(0)
                        obuf[f, p] += v
                        dirty.add((f, p))
                        cur.add((f, p))
                        last_pop = cyc
                prev_iss = cur
                # running sums leaving the array this cycle are written into the FIFOs at its end, in slot order
                for c in range(C):
                    if exits[c] is not None:
                        pj, gj = exits[c]["id"]
                        fi, pos = passes[pj]["fi"], passes[pj]["pos"][gj]
                        assert len(exits[c]["sums"]) == sent[cyc - R - c][c], "backpressure credit != entries"
                        fifo[c].extend(sorted(exits[c]["sums"].items(),
                                              key=lambda kv: (fi[kv[0][0], c], pos[kv[0][1]])))
                        assert cfg.D <= 0 or len(fifo[c]) <= cfg.D, "edge FIFO overflow"
                        stats["fifo_max"] = max(stats["fifo_max"], len(fifo[c]))
                busy = any(fifo)
                active = any(spk[k][c] is not None or bund[k][c] is not None for k in range(R) for c in range(C))
                cyc += 1
                if j >= len(passes) and not active and not busy and not any(fifo):
                    break
            while qi[0] < len(ktq):              # trailing K-tiles that were scanned but empty
                pk_last[0] = packer.pack(nn)
                packer.release(pk_last[0])
                qi[0] += 1
            stats["passes"] += len(passes)
            lif_c = math.ceil(len(dirty) / cfg.lif_units)
            end = max(cyc, pk_last[0], last_pop + 2 if last_pop is not None else start) + lif_c + \
                (cfg.lif_lat if lif_c else 0)
            end_all = max(end_all, end)
            if cfg.obuf_double:
                obuf_free.append(end)
                t_start = max((allow - cfg.L) if passes else start, start)
            else:
                t_start = end
    spikes = lif_ref(obuf, cfg.theta, cfg.leak)
    stats["cycles"] = end_all
    return spikes, obuf, stats
