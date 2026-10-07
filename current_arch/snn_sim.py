"""
snn_sim.py -- cycle-stepped simulator of the Mentha-based, weight-stationary,
dual-sparse systolic array for SNNs (T-parallel accumulation, one-cycle IF).

NAMING (final, from the user):
    C = A x B
    A = WEIGHTS      (M x K, int8)         -> stationary in the PEs
    B = ACTIVATIONS  (K x N, 8-bit masks)  -> bit t of a mask = spike at timestep t
    C = M x N output, 8 spike bits per element (the next layer's B)

WHAT IS MODELLED (cycle by cycle, no shortcuts):
    Stage 2  pre-proc   : pack A and B per K-slab (Mentha offline graph colouring, threshold cap).
                          Index = original position + 1.  Index 0 = "this element is zero".
                          Packing itself takes NO cycles (assumed already done, kept in SRAM).
    Stage 3  load       : packed weights written into the PE array (one PE row per cycle).
    Stage 4  stream     : one packed activation column per cycle, skewed one cycle per array column.
    Stage 5  PE array   : skip-and-pass if either index is 0, else search the PE register file
                          (slots) for (row_idx, col_idx); hit -> add, miss -> take a free slot.
                          8 timestep sums updated in parallel (mask bit t gates the weight).
    Stage 6  exit stage : sets leave the last used column.  FIFO + 'ports' entries per cycle.
                          Not the last K-slab -> add into the partial buffer (PB).
                          Last K-slab        -> add stored partial, one-cycle IF, result buffer.
    Stage 7  sweep      : outputs touched in earlier slabs but not in the last one go through IF.
    Stage 8  post-proc  : unpack the packed result buffer into the dense spike matrix (-> HBM).

Run `python snn_sim.py` for the self tests.
"""
import collections
import math
import zlib
from dataclasses import dataclass

import numpy as np


# ----------------------------------------------------------------------------------------
# configuration
# ----------------------------------------------------------------------------------------
@dataclass
class Cfg:
    A: int = 4              # array is A x A PEs (rows = packed weight rows, cols = K positions)
    T: int = 8              # timesteps = bits per activation mask = gated adders per PE
    cap: int = 4            # Mentha threshold: max originals merged into one packed row/col
    slots: int = 4          # register-file entries per PE
    m_blk: int = 64         # weight window (rows packed together)      -> index <= 64  (7 bit)
    n_blk: int = 128        # activation window (columns packed together)-> index <= 128 (8 bit)
    load_per_row: int = 1   # cycles to write one PE row of weights
    shadow: bool = False    # True = shadow weight regs hide the load (except first pass of a tile)
    ports: int = 8          # exit-stage entries served per cycle (partial-buffer RMW / IF lanes)
    fifo_depth: int = 64    # exit FIFO depth (entries); array freezes when it could overflow
    theta: int = 0          # IF threshold, fire if v > theta  (theta >= 0)
    pp_rate: int = 16       # post-proc unpack rate (entries / cycle)
    clock_mhz: float = 800.0


# ----------------------------------------------------------------------------------------
# neuron (IF, soft reset) -- same function as the user's lif_model RTL (no leak)
# ----------------------------------------------------------------------------------------
def if_scalar(sums, theta, T=8):
    v, byte = 0, 0
    for t in range(T):
        v += int(sums[t])
        if v > theta:
            byte |= 1 << t
            v -= theta
    return byte


def if_vec(sums, theta, T=8):
    v = np.zeros(sums.shape[:-1], dtype=np.int64)
    out = np.zeros(sums.shape[:-1], dtype=np.int64)
    for t in range(T):
        v = v + sums[..., t]
        fire = v > theta
        out |= fire.astype(np.int64) << t
        v = np.where(fire, v - theta, v)
    return out.astype(np.uint8)


def dense_sums(W, Bm, T=8):
    """sums[m, n, t] = sum_k W[m,k] * bit_t(B[k,n])   (the dense reference)"""
    W = W.astype(np.int64)
    return np.stack([W @ ((Bm >> t) & 1).astype(np.int64) for t in range(T)], axis=-1)


def dense_layer(W, Bm, theta, T=8):
    return if_vec(dense_sums(W, Bm, T), theta, T)


# ----------------------------------------------------------------------------------------
# pre-proc: Mentha offline grouping (Alg. 1/2) on 4-bit "position masks"
# ----------------------------------------------------------------------------------------
def mentha_group(masks, cap):
    """masks[i] = bit k set if vertex i has a nonzero at K-position k of the slab.
    Two vertices conflict if their masks share a bit.  All-zero vertices are dropped.
    Highest-degree vertex first, then fill the group with non-conflicting vertices
    (in degree order) until the group holds `cap` members.  Returns list of groups."""
    masks = [int(x) for x in masks]
    verts = [i for i, m in enumerate(masks) if m]
    if not verts:
        return []
    mv = np.array([masks[i] for i in verts])
    deg = ((mv[:, None] & mv[None, :]) != 0).sum(1) - 1
    alive = sorted(range(len(verts)), key=lambda j: (-int(deg[j]), j))
    groups = []
    while alive:
        p = alive[0]
        grp, union = [p], int(mv[p])
        for j in alive[1:]:
            if len(grp) >= cap:
                break
            if int(mv[j]) & union == 0:
                grp.append(j)
                union |= int(mv[j])
        gs = set(grp)
        alive = [j for j in alive if j not in gs]
        groups.append([verts[j] for j in grp])
    return groups


def pack_weights(Ws, cap):
    """Ws: (mb x keff) int.  Returns packed rows: (idx[keff], val[keff], members).
    idx = original row + 1, or 0 where no merged row has a nonzero at that K position."""
    mb, keff = Ws.shape
    nz = Ws != 0
    masks = (nz * (1 << np.arange(keff))).sum(1)
    out = []
    for g in mentha_group(masks, cap):
        idx, val = [0] * keff, [0] * keff
        for m in g:
            for k in range(keff):
                if nz[m, k]:
                    assert idx[k] == 0, "merge conflict (packer bug)"
                    idx[k], val[k] = m + 1, int(Ws[m, k])
        out.append((idx, val, g))
    return out


def pack_acts(Bs, cap):
    """Bs: (keff x nb) uint8 masks.  Returns packed columns: (idx[keff], mask[keff], members)."""
    keff, nb = Bs.shape
    nz = Bs != 0
    masks = (nz * (1 << np.arange(keff))[:, None]).sum(0)
    out = []
    for g in mentha_group(masks, cap):
        idx, msk = [0] * keff, [0] * keff
        for n in g:
            for k in range(keff):
                if nz[k, n]:
                    assert idx[k] == 0, "merge conflict (packer bug)"
                    idx[k], msk[k] = n + 1, int(Bs[k, n])
        out.append((idx, msk, g))
    return out


# ----------------------------------------------------------------------------------------
# the machine
# ----------------------------------------------------------------------------------------
class Sim:
    def __init__(self, cfg=None):
        self.cfg = cfg or Cfg()
        self.stats = collections.Counter()

    # ---------------- one pass: load a chunk of <=A packed weight rows, stream all packed columns
    def run_pass(self, wrows, acols, keff, final, pb, results, first):
        cfg, A, T = self.cfg, self.cfg.A, self.cfg.T
        R, P = len(wrows), len(acols)
        load = 0 if (cfg.shadow and not first) else R * cfg.load_per_row

        widx = [[0] * A for _ in range(A)]
        wval = [[0] * A for _ in range(A)]
        for i, (idx, val, _) in enumerate(wrows):
            for k in range(keff):
                widx[i][k], wval[i][k] = idx[k], val[k]

        a_cur = [[None] * A for _ in range(A)]       # activation element at PE(i,k) this cycle
        ps_out = [[None] * A for _ in range(A)]      # registered psum-set output of PE(i,k)
        fifo = collections.deque()
        need = P + R + keff - 1                      # unfrozen iterations until the last set is captured
        kt = keff - 1                                # exit tap column
        c = cycles = stalls = 0

        while not (c >= need and not fifo):
            cycles += 1
            frozen = len(fifo) > cfg.fifo_depth - R * cfg.slots
            if frozen:
                stalls += 1
            elif c < need:
                # (1) capture sets that left the tap column last cycle
                for i in range(R):
                    s = ps_out[i][kt]
                    if s is not None:
                        for (m, n), sums in s[1].items():
                            fifo.append((m, n, sums))
                        self.stats['max_set'] = max(self.stats['max_set'], len(s[1]))
                # (2) compute one cycle of the array
                a_now = [[None] * A for _ in range(A)]
                for k in range(keff):
                    n = c - k
                    if 0 <= n < P:                    # feeder skew: column k gets packed col n one cycle later per k
                        a_now[0][k] = (n, acols[n][0][k], acols[n][1][k])
                for i in range(1, R):
                    for k in range(keff):
                        a_now[i][k] = a_cur[i - 1][k]  # activations move down one register per cycle
                ps_new = [[None] * A for _ in range(A)]
                for i in range(R):
                    for k in range(keff):
                        a = a_now[i][k]
                        if k == 0:
                            sset = {} if a is not None else None
                            tag = a[0] if a is not None else None
                        else:
                            prev = ps_out[i][k - 1]    # psum set moves right one register per cycle
                            sset, tag = (prev[1], prev[0]) if prev is not None else (None, None)
                        assert (a is None) == (sset is None), "psum / activation misaligned"
                        if a is None:
                            continue
                        assert tag == a[0], "psum / activation misaligned"
                        wi, ai = widx[i][k], a[1]
                        if wi != 0 and ai != 0:       # skip-and-pass otherwise
                            ent = sset.get((wi, ai))
                            if ent is None:
                                assert len(sset) < cfg.slots, "register-file overflow"
                                ent = [0] * T
                                sset[(wi, ai)] = ent
                            w, mask = wval[i][k], a[2]
                            assert mask != 0
                            for t in range(T):        # T gated adders, all in one cycle
                                if (mask >> t) & 1:
                                    ent[t] += w
                                    assert -32768 <= ent[t] <= 32767, "16-bit psum overflow"
                            self.stats['macs_fired'] += 1
                        else:
                            self.stats['skipped'] += 1
                        ps_new[i][k] = (tag, sset)
                a_cur, ps_out = a_now, ps_new
                c += 1
            # (3) exit stage: serve up to `ports` entries this cycle
            self.stats['max_fifo'] = max(self.stats['max_fifo'], len(fifo))
            served = 0
            while fifo and served < cfg.ports:
                m, n, sums = fifo.popleft()
                served += 1
                self.stats['entries'] += 1
                if not final:                         # partial buffer read-modify-write
                    old = pb.get((m, n))
                    pb[(m, n)] = list(sums) if old is None else [x + y for x, y in zip(old, sums)]
                    for v in pb[(m, n)]:
                        assert -(1 << 23) <= v < (1 << 23), "24-bit partial overflow"
                else:                                 # last slab: add partial, IF, result buffer
                    old = pb.pop((m, n), None)
                    tot = list(sums) if old is None else [x + y for x, y in zip(old, sums)]
                    results.append((m, n, if_scalar(tot, cfg.theta, T)))
        self.stats['load_cycles'] += load
        self.stats['stream_cycles'] += cycles
        self.stats['stall_cycles'] += stalls
        self.stats['passes'] += 1
        return load + cycles

    # ---------------- one output tile: all K slabs, sweep, unpack
    def run_tile(self, Wt, Bt):
        cfg, A = self.cfg, self.cfg.A
        mb, K = Wt.shape
        nb = Bt.shape[1]
        assert mb <= cfg.m_blk and nb <= cfg.n_blk and mb < 256 and nb < 256   # 8-bit indices, 0 reserved
        S = math.ceil(K / A)
        pb, results = {}, []
        total, first = 0, True
        for s in range(S):
            Ws, Bs = Wt[:, s * A:(s + 1) * A], Bt[s * A:(s + 1) * A, :]
            keff = Ws.shape[1]
            final = (s == S - 1)
            wp, ap = pack_weights(Ws, cfg.cap), pack_acts(Bs, cfg.cap)   # 0 cycles (pre-proc, in SRAM)
            self.stats['slabs'] += 1
            self.stats['R_sum'] += len(wp)
            self.stats['P_sum'] += len(ap)
            if not wp or not ap:
                self.stats['skipped_slabs'] += 1
                continue
            for c0 in range(0, len(wp), A):
                total += self.run_pass(wp[c0:c0 + A], ap, keff, final, pb, results, first)
                first = False
        sweep = math.ceil(len(pb) / cfg.ports) if pb else 0
        self.stats['sweep_entries'] += len(pb)
        for (m, n), sums in pb.items():
            results.append((m, n, if_scalar(sums, cfg.theta, cfg.T)))
        self.stats['sweep_cycles'] += sweep
        total += sweep + (1 if results else 0)       # +1: registered IF output
        out = np.zeros((mb, nb), dtype=np.uint8)     # post-proc: unpack into dense spike matrix
        for m, n, byte in results:
            out[m - 1, n - 1] = byte
        self.stats['result_entries'] += len(results)
        return out, total, len(results)

    # ---------------- a whole layer (tiled in HBM into m_blk x n_blk output tiles)
    def run_layer(self, W, Bm):
        cfg = self.cfg
        M, N = W.shape[0], Bm.shape[1]
        out = np.zeros((M, N), dtype=np.uint8)
        cycles, last = 0, 0
        for m0 in range(0, M, cfg.m_blk):
            for n0 in range(0, N, cfg.n_blk):
                o, c, nres = self.run_tile(W[m0:m0 + cfg.m_blk, :], Bm[:, n0:n0 + cfg.n_blk])
                out[m0:m0 + o.shape[0], n0:n0 + o.shape[1]] = o
                cycles += c
                last = nres
        cycles += math.ceil(last / cfg.pp_rate)      # unpack tail of the last tile (others overlap)
        return out, cycles


# ----------------------------------------------------------------------------------------
# random data helpers
# ----------------------------------------------------------------------------------------
def rand_weights(rng, M, K, wd):
    w = rng.integers(-127, 128, size=(M, K))
    w[w == 0] = 1
    return (w * (rng.random((M, K)) < wd)).astype(np.int16)


def rand_masks(rng, K, N, ns):
    m = rng.integers(1, 256, size=(K, N))
    return (m * (rng.random((K, N)) < ns)).astype(np.uint8)


def pick_theta(W, Bm, target=0.25, T=8):
    """threshold so about `target` of the output spike bits are 1 (keeps layers alive)"""
    s = dense_sums(W, Bm, T)
    lo, hi = 0, int(np.abs(s).max()) + 1
    while lo < hi:
        mid = (lo + hi) // 2
        rate = np.unpackbits(if_vec(s, mid, T)[..., None], axis=-1).mean()
        if rate > target:
            lo = mid + 1
        else:
            hi = mid
    return lo


# ----------------------------------------------------------------------------------------
# fast model (sampled slabs) used for whole networks.  Same rules as the stepped sim.
# ----------------------------------------------------------------------------------------
_slab_cache = {}


def slab_stats(mb, nb, wd, ns, keff, cfg, nsamp=200):
    nsamp = min(3000, nsamp * max(1, 64 // nb))      # narrow tiles are mostly empty slabs -> need more samples
    key = (mb, nb, round(wd, 6), round(ns, 6), keff, cfg.cap, cfg.A, cfg.ports, cfg.shadow, cfg.load_per_row, nsamp)
    if key in _slab_cache:
        return _slab_cache[key]
    rng = np.random.default_rng(zlib.crc32(repr(key).encode()))
    A = cfg.A
    cyc, Rs, Ps, ents = [], [], [], []
    for _ in range(nsamp):
        Wnz = rng.random((mb, keff)) < wd
        Anz = rng.random((keff, nb)) < ns
        wm = (Wnz * (1 << np.arange(keff))).sum(1)
        am = (Anz * (1 << np.arange(keff))[:, None]).sum(0)
        gw, ga = mentha_group(wm, cfg.cap), mentha_group(am, cfg.cap)
        R, P = len(gw), len(ga)
        Rs.append(R); Ps.append(P)
        if R == 0 or P == 0:
            cyc.append(0); ents.append(0)
            continue
        rowcnt = ((Wnz.astype(np.int32) @ Anz.astype(np.int32)) > 0).sum(1)   # outputs touched per weight row
        t, e_tot = 0, 0
        for c0 in range(0, R, A):
            ch = gw[c0:c0 + A]
            Rc = len(ch)
            ent = int(sum(rowcnt[m] for g in ch for m in g))
            e_tot += ent
            load = 0 if cfg.shadow else Rc * cfg.load_per_row
            t += load + max(P + Rc + keff - 1, keff + math.ceil(ent / cfg.ports))
        cyc.append(t); ents.append(e_tot)
    r = dict(cyc=float(np.mean(cyc)), R=float(np.mean(Rs)), P=float(np.mean(Ps)), ent=float(np.mean(ents)))
    _slab_cache[key] = r
    return r


def fast_tile(mb, nb, K, wd, ns, cfg, nsamp=200):
    A = cfg.A
    S, full, rem = math.ceil(K / A), K // A, K % A
    t = 0.0
    if full:
        t += full * slab_stats(mb, nb, wd, ns, A, cfg, nsamp)['cyc']
    if rem:
        t += slab_stats(mb, nb, wd, ns, rem, cfg, nsamp)['cyc']
    q = 1 - (1 - wd * ns) ** A                      # chance an output is touched by one slab
    dirty = mb * nb * (1 - q) * (1 - (1 - q) ** (S - 1)) if S > 1 else 0.0
    t += math.ceil(dirty / cfg.ports) + 1
    touched = mb * nb * (1 - (1 - q) ** S)
    return t, touched


def fast_layer(M, K, N, wd, ns, cfg, nsamp=200):
    mfull, mrem = divmod(M, cfg.m_blk)
    nfull, nrem = divmod(N, cfg.n_blk)
    ms = [(cfg.m_blk, mfull)] * (mfull > 0) + [(mrem, 1)] * (mrem > 0)
    ns_ = [(cfg.n_blk, nfull)] * (nfull > 0) + [(nrem, 1)] * (nrem > 0)
    total, last = 0.0, 0.0
    for mb, mc in ms:
        for nb, nc in ns_:
            t, touched = fast_tile(mb, nb, K, wd, ns, cfg, nsamp)
            total += t * mc * nc
            last = touched
    return total + math.ceil(last / cfg.pp_rate)


# ----------------------------------------------------------------------------------------
# self tests
# ----------------------------------------------------------------------------------------
def _selftest():
    rng = np.random.default_rng(7)
    cfg = Cfg()
    print("1) tiny hand example from the chat (4x4 weights, packed rows / columns)")
    W = np.array([[3, 0, 0, 0], [0, 0, -2, 0], [0, 5, 0, 1], [4, -1, 0, 0]], dtype=np.int16)
    for r in pack_weights(W, 4):
        print("   packed weight row  idx", r[0], "val", r[1], "members(rows)", [m + 1 for m in r[2]])
    Bm = np.zeros((4, 16), dtype=np.uint8)
    Bm[0, 1], Bm[1, 6], Bm[3, 6], Bm[2, 10] = 0x05, 0xC0, 0x10, 0x03     # cols 2, 7, 7, 11 (1-based)
    sim = Sim(Cfg(theta=2))
    out, cyc = sim.run_layer(W, Bm)
    ref = dense_layer(W, Bm, 2)
    print("   spike byte of output (m=3,n=7):", hex(out[2, 6]), " dense ref:", hex(ref[2, 6]), " equal:", np.array_equal(out, ref))
    assert np.array_equal(out, ref)

    print("2) pass latency formula  P+R+K-1  (no stalls) on dense data")
    for (R, P) in [(1, 1), (2, 5), (4, 20), (3, 7)]:
        Wd = rand_weights(rng, R, 4, 1.0)
        Wd[:, :] = np.where(np.eye(4, dtype=bool)[:R] | True, Wd, Wd)
        # make every weight row conflict with every other so no merging happens: all positions nonzero
        Bd = rand_masks(rng, 4, P, 1.0)
        s = Sim(Cfg(ports=64, fifo_depth=512))
        wp, ap = pack_weights(Wd, 4), pack_acts(Bd, 4)
        assert len(wp) == R and len(ap) == P
        pb, res = {}, []
        c = s.run_pass(wp, ap, 4, True, pb, res, True) - R * s.cfg.load_per_row
        print(f"   R={R} P={P}: sim pass cycles {c}  formula {P + R + 4 - 1}")
        assert c == P + R + 3

    print("3) random layers: simulator == dense reference (bit exact)")
    for (M, K, N, wd, ns) in [(10, 7, 9, .5, .5), (64, 16, 128, .5, .5), (70, 21, 150, .3, .6), (33, 40, 20, .8, .2), (5, 3, 4, 1, 1)]:
        W = rand_weights(rng, M, K, wd)
        Bm = rand_masks(rng, K, N, ns)
        th = pick_theta(W, Bm)
        s = Sim(Cfg(theta=th))
        out, cyc = s.run_layer(W, Bm)
        ref = dense_layer(W, Bm, th)
        ok = np.array_equal(out, ref)
        print(f"   M={M:3d} K={K:3d} N={N:3d} wd={wd} ns={ns} theta={th:5d} spikes={np.unpackbits(ref[..., None], axis=-1).mean():.2f}  cycles={cyc:7d}  equal={ok}")
        assert ok
    print("4) 3-layer chain (spikes of layer L = masks of layer L+1)")
    x = rand_masks(rng, 32, 40, .6)
    xd = x.copy()
    for li, (M, K) in enumerate([(48, 32), (24, 48), (10, 24)]):
        W = rand_weights(rng, M, K, .4)
        th = pick_theta(W, xd, .2)
        out, cyc = Sim(Cfg(theta=th)).run_layer(W, x)
        ref = dense_layer(W, xd, th)
        print(f"   layer {li + 1}: {M}x{K}  theta={th}  equal={np.array_equal(out, ref)}  nonzero outputs={np.mean(ref > 0):.2f}")
        assert np.array_equal(out, ref)
        x, xd = out, ref
    print("ALL SELF TESTS PASSED")


if __name__ == "__main__":
    _selftest()
