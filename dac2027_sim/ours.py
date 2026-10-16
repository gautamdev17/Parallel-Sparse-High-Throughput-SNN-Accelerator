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
  * Packer: reads the K-tile's Nt pixel spike trains at pp pixel slices/cycle (continuous stream), drops pixels with no spike in the
    K-tile, first-fit into <= G pixels/group with a window of W_open open groups. Double-buffered:
    packing K-tile i starts when K-tile i-1 is packed and K-tile i-2's groups have all entered the array.
  * Pass j with P_j groups: group g enters row k at cycle s_j + g + k and PE (k,c) at s_j + g + k + c;
    its running sums leave column c and reach the edge FIFO at s_j + g + R + c.
    s_j >= pack done of its K-tile;  s_{j+1} >= s_j + max(P_j, L)  with L = ceil(R*C/Lw) when weights
    are double-buffered (shadow register per PE, loaded along the wavefront right after the PE swaps),
    or s_{j+1} >= s_j + P_j + (R-1) + (C-1) + L without shadow registers.
  * Edge unit: one FIFO per column, E read-modify-writes per cycle into the output buffer, only for
    running sums that received at least one addition. Arrivals can be served in the cycle they arrive.
  * After the last K-tile of an output tile and an empty edge FIFO: LIF sweep over the dirty entries,
    lif_units per cycle. Then the next output tile starts (single output buffer) or, with obuf_double,
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
    pp: int = 8           # packer: pixels scanned per cycle
    Mt: int = 64          # output tile: filters
    Nt: int = 128         # output tile: pixels
    E: int = 4            # edge unit: running-sum writes per column per cycle
    Lw: int = 16          # weights (+labels) loaded per cycle
    shadow: bool = True   # double-buffered weight registers
    obuf_double: bool = False
    lif_units: int = 16
    theta: float = 64.0
    leak: float = 0.5

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
    """double-buffered packer timing (transaction level, identical in both simulators).
    The packer reads pp pixel slices (R x T bits each) per cycle as one continuous stream, so a K-tile of
    n pixels costs n/pp cycles (several small K-tiles can share a cycle); a K-tile's groups are usable
    from the first whole cycle after its last slice was read."""

    def __init__(self, pp):
        self.pp, self.end, self.free = pp, 0.0, [0, 0]   # free[-2] = release of the buffer two K-tiles back

    def pack(self, n):
        start = max(self.end, self.free[-2])
        self.end = start + n / self.pp
        return math.ceil(self.end)

    def release(self, t):
        self.free.append(t)


def _edge_finish(arr, E, t0):
    """arr: list of (time, count) in increasing time for one column -> (last service cycle + 1, max queue)."""
    q, tp, qmax, last = 0, None, 0, t0 - 1
    for t, a in arr:
        if tp is not None:
            q = max(0, q - E * (t - tp - 1))
        q += a
        qmax = max(qmax, q)
        q = max(0, q - E)
        tp = t
        last = t
    if tp is None:
        return t0, 0
    return last + math.ceil(q / E) + 1, qmax


# ------------------------------------------------------------------ fast model
def run_layer_fast(W, S, cfg, plan=None):
    """-> dict(cycles, passes, groups, pixel_steps, pixels_nonzero, fifo_max, ...) for one layer."""
    plan = plan or LayerPlan(W, cfg)
    R, C, T = cfg.R, cfg.C, cfg.T
    K, N = S.shape
    nblocks = [(n0, min(n0 + cfg.Nt, N)) for n0 in range(0, N, cfg.Nt)]
    Sp = np.zeros((plan.nK * R, N), dtype=np.uint8)
    Sp[:K] = S
    packer = _Packer(cfg.pp)
    t_start, end_all = 0, 0
    obuf_free = [0, 0]
    st = dict(passes=0, groups=0, ktiles_run=0, pixels_nonzero=0, rmw=0, lif=0, fifo_max=0)
    for bi, (m0, m1) in enumerate(plan.mblocks):
        for (n0, n1) in nblocks:
            nn = n1 - n0
            start = max(t_start, obuf_free[-2]) if cfg.obuf_double else t_start
            s_next = start + cfg.L
            arr_end = start
            arr = [[] for _ in range(C)]
            dirty = np.zeros((m1 - m0, nn), dtype=bool)
            for kt in range(plan.nK):
                cols, Wt = plan.cols[bi, kt]
                if not cols:
                    continue
                St = Sp[kt * R:(kt + 1) * R, n0:n1]
                masks = tile_masks(St, T)
                pk = packer.pack(nn)
                groups = pack_spikes(masks, cfg.G, cfg.W_open)
                st["pixels_nonzero"] += sum(1 for m in masks if m)
                if not groups:
                    packer.release(pk)
                    continue
                st["ktiles_run"] += 1
                touched = ((Wt != 0).astype(np.float32) @ (St != 0).astype(np.float32)) > 0
                dirty |= touched
                B = np.zeros((nn, len(groups)), dtype=np.float32)
                for g, ps in enumerate(groups):
                    B[ps, g] = 1
                tg = touched.astype(np.float32) @ B           # (m, P): sums written per (filter, group)
                P = len(groups)
                for pas in _passes(cols, C):
                    s = max(s_next, pk)
                    for c, fl in enumerate(pas):
                        cnt = tg[fl].sum(0)
                        for g in np.nonzero(cnt)[0]:
                            arr[c].append((s + int(g) + R + c, int(cnt[g])))
                    st["passes"] += 1
                    st["groups"] += P
                    s_next = s + max(P, cfg.L) if cfg.shadow else s + P + (R - 1) + (C - 1) + cfg.L
                    last_in = s + P
                    # the last group's (possibly empty) bundle leaves the last column at s+P-1+R+C-1
                    arr_end = max(arr_end, s + P + R + C - 1)
                packer.release(last_in)
            array_end = s_next  # no pass entered after this point
            edge_end = start
            for c in range(C):
                if arr[c]:
                    f, qm = _edge_finish(arr[c], cfg.E, start)
                    edge_end = max(edge_end, f)
                    st["fifo_max"] = max(st["fifo_max"], qm)
                    st["rmw"] += sum(a for _, a in arr[c])
            nd = int(dirty.sum())
            lif_c = math.ceil(nd / cfg.lif_units)
            st["lif"] += lif_c
            end = max(edge_end, arr_end, start) + lif_c
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
    Sp = np.zeros((plan.nK * R, N), dtype=np.uint8)
    Sp[:K] = S
    nblocks = [(n0, min(n0 + cfg.Nt, N)) for n0 in range(0, N, cfg.Nt)]
    obuf = np.zeros((M, N, T), dtype=np.int64)
    packer = _Packer(cfg.pp)
    cyc, end_all, t_start = 0, 0, 0
    obuf_free = [0, 0]
    stats = dict(passes=0, adder_ops=0, fifo_max=0)

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
                    passes.append(dict(P=len(gl), w=pe_w, f=pe_f, g=gl, kt=kt))
                kt_last.append(len(passes) - 1)
            first_of = {p0: None for _, p0 in ktq if p0 is not None}
            qi = [0]

            def pack_until(pass_id):
                """run the packer over queued K-tiles up to the one that owns pass_id; -> its pack-done cycle."""
                while qi[0] < len(ktq):
                    kt, p0 = ktq[qi[0]]
                    qi[0] += 1
                    pk = packer.pack(nn)
                    if p0 is None:
                        packer.release(pk)
                        continue
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
                while qi[0] < len(ktq):          # K-tiles scanned but empty
                    packer.release(packer.pack(nn))
                    qi[0] += 1
                end_all = max(end_all, start)
                if cfg.obuf_double:
                    obuf_free.append(start)
                t_start = start
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
            in_flight = 0
            while True:
                # injection decision at row 0 (spike items for rows k>0 are delayed k cycles by the skew)
                inject = None
                if j < len(passes) and cyc >= max(allow, pk_of(j)):
                    if g == 0:
                        s[j] = cyc
                    inject = (j, g)
                    g += 1
                    if g == passes[j]["P"]:
                        P = passes[j]["P"]
                        nxt = s[j] + max(P, cfg.L) if cfg.shadow else s[j] + P + (R - 1) + (C - 1) + cfg.L
                        if j in kt_last:
                            packer.release(s[j] + P)
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
                for c in range(C):
                    if exits[c] is not None:
                        fifo[c].extend(exits[c]["sums"].items())
                        stats["fifo_max"] = max(stats["fifo_max"], len(fifo[c]))
                # edge unit: E read-modify-writes per column per cycle
                busy = False
                for c in range(C):
                    for _ in range(min(cfg.E, len(fifo[c]))):
                        (f, p), v = fifo[c].pop(0)
                        obuf[f, p] += v
                        dirty.add((f, p))
                    busy |= bool(fifo[c])
                active = any(spk[k][c] is not None or bund[k][c] is not None for k in range(R) for c in range(C))
                cyc += 1
                if j >= len(passes) and not active and not busy and not any(fifo):
                    break
            while qi[0] < len(ktq):              # trailing K-tiles that were scanned but empty
                packer.release(packer.pack(nn))
                qi[0] += 1
            stats["passes"] += len(passes)
            end = cyc + math.ceil(len(dirty) / cfg.lif_units)
            end_all = max(end_all, end)
            if cfg.obuf_double:
                obuf_free.append(end)
                t_start = max((allow - cfg.L) if passes else start, start)
            else:
                t_start = end
    spikes = lif_ref(obuf, cfg.theta, cfg.leak)
    stats["cycles"] = end_all
    return spikes, obuf, stats
