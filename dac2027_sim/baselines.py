"""
baselines.py -- LoAS, PTB and SpikeX on the same layers and the same spike tensors as ours.py.

LoAS   : the closed form of EnergySpeedupSim.zip / cycle_compare.py, unchanged:
           16 TPPEs, 128-element chunks, cycles/chunk = matches + 21, +1 (P-LIF) per neuron,
           ceil(M*N/16) waves. matches = chunk_len * p.
         'LoAS (zip)'          p = 0.261 (the zip's non-silent density, weights treated as dense)
         'LoAS (weight-aware)' p = ns * wd, i.e. LoAS also skips the zero weights (fair to LoAS).
PTB    : Lee et al., MICRO'21 (ptb.pdf), 16x8 = 128 PEs, one 8-bit adder each (Table 4).
         Rows = 16 output channels of one output pixel, columns = time windows (T/TWS of them).
         The receptive field of the pixel streams through the array: silent inputs are trimmed, StSAP pairs
         two non-bursting inputs whose TB-tags do not overlap (greedy: exact 1's complement first, then the
         nearest non-overlapping tag), bursting inputs are not packed. One packed input = TWS cycles
         (one adder per PE, TWS time points per TB). cycles = ceil(M/16) * sum_pixels(slots * TWS)
         + one fill/drain (16+8-2) per layer. TWS in {1,2,4,8}, the best one is reported.
SpikeX : Xu et al. (spikex.pdf), 8x8 = 64 PEs, one accumulator each (Sec. V-A). A PE processes one NTWU
         (neuron, time window). Weights enter rows from the left and are shared along a row (lock-step),
         inputs enter columns from the top. Per batch of 8 output channels x 8 NTWUs the row walks the
         inputs that are active in at least one of its 8 NTWUs (activation tags + weight tailoring), TWS
         cycles each. Temporal mode: the 8 columns are the TWs of one pixel. Spatial mode: the 8 columns
         are 8 consecutive active (pixel, TW) units of one TW grid. Best of mode x TWS per layer.
Both PTB and SpikeX: no weight sparsity (as in the papers), memory stalls not modelled (both papers
assume double-buffered, stall-free arrays), clock = the common clock of the comparison.
"""
import math
import numpy as np

# ----------------------------------------------------------------------------- LoAS (zip, unchanged)
LOAS_TPPES, LOAS_CHUNK, LOAS_OVERHEAD, LOAS_P_ZIP = 16, 128, 21, 0.261


def loas_layer_cycles(M, K, N, p, tppes=LOAS_TPPES, chunk=LOAS_CHUNK, overhead=LOAS_OVERHEAD):
    """identical to cycle_compare.compute_layer_cycles (K = KH*KW*C_in, M*N output neurons)."""
    cpn = 0.0
    for c in range(math.ceil(K / chunk)):
        cl = min(chunk, K - c * chunk)
        cpn += cl * p + overhead
    cpn += 1
    return math.ceil(M * N / tppes) * cpn


# ----------------------------------------------------------------------------- helpers
def _tags(S, tws, T=8):
    """(K,N) uint8 trains -> (K,N) tags with T/tws bits (bit w = any spike in window w)."""
    nw = T // tws
    tag = np.zeros(S.shape, dtype=np.uint8)
    for w in range(nw):
        win = ((1 << tws) - 1) << (w * tws)
        tag |= (((S & win) != 0).astype(np.uint8) << w)
    return tag, nw


def _popc(x):
    return np.unpackbits(np.asarray(x, dtype=np.uint8)[..., None], axis=-1).sum(-1)


# ----------------------------------------------------------------------------- PTB
def ptb_slots(S, tws, T=8):
    """packed input slots per pixel (silent trimmed, StSAP pairs of non-bursting inputs)."""
    tag, nw = _tags(S, tws, T)
    return ptb_pairs_count(tag, nw)


def ptb_pairs_count(tag, nw):
    """tag: (K, N) nw-bit TB-tags -> packed slots per pixel (greedy StSAP: 1's complement first, then nearest)."""
    full = (1 << nw) - 1
    K, N = tag.shape
    H = np.zeros((N, 1 << nw), dtype=np.int64)
    np.add.at(H, (np.broadcast_to(np.arange(N), (K, N)).ravel(), np.asarray(tag).astype(np.int64).ravel()), 1)
    bursting = H[:, full].copy()
    H[:, 0] = 0
    H[:, full] = 0
    pairs = np.zeros(N, dtype=np.int64)
    vals = np.arange(1 << nw)
    pc = _popc(vals).astype(np.int64)
    for a in sorted(range(1, full), key=lambda v: -pc[v]):
        cands = [b for b in vals[1:full] if (b & a) == 0]
        cands.sort(key=lambda b: (b != (full ^ a), -pc[b]))
        for b in cands:
            m = np.minimum(H[:, a], H[:, b])
            H[:, a] -= m
            H[:, b] -= m
            pairs += m
    return bursting + pairs + H.sum(1)


def ptb_layer_cycles(S, M, T=8, rows=16, cols=8, tws_list=(1, 2, 4, 8)):
    best = None
    for tws in tws_list:
        if T // tws > cols:
            continue
        slots = ptb_slots(S, tws, T)
        cyc = math.ceil(M / rows) * int(slots.sum()) * tws + (rows + cols - 2)
        if best is None or cyc < best[0]:
            best = (cyc, tws)
    return best


# ----------------------------------------------------------------------------- SpikeX
def spikex_layer_cycles(S, M, T=8, rows=8, cols=8, tws_list=(1, 2, 4, 8)):
    K, N = S.shape
    best = None
    for tws in tws_list:
        tag, nw = _tags(S, tws, T)
        if nw > cols:
            continue
        # temporal mode: one pixel per row-batch, its nw TWs on nw columns -> walk inputs active in any TW
        temporal = int((tag != 0).sum()) * tws
        # spatial mode: per TW grid, consecutive active pixels 8 at a time; walk the union of their inputs
        spatial = 0
        for w in range(nw):
            act = ((tag >> w) & 1).astype(bool)           # (K, N)
            live = np.nonzero(act.any(0))[0]
            if live.size == 0:
                continue
            a = act[:, live]
            pad = (-a.shape[1]) % cols
            if pad:
                a = np.concatenate([a, np.zeros((K, pad), dtype=bool)], 1)
            spatial += int(a.reshape(K, -1, cols).any(2).sum()) * tws
        for mode, cyc in (("temporal", temporal), ("spatial", spatial)):
            tot = math.ceil(M / rows) * cyc + (rows + cols - 2)
            if best is None or tot < best[0]:
                best = (tot, f"{mode},TWS={tws}")
    return best


# ----------------------------------------------------------------------------- Prosperity
def prosperity_layer_cycles(S, M, T=8, m=256, k=16, n=128, pipe=4, skip_empty=False):
    """Prosperity (HPCA'25, prosperity.pdf), product sparsity, Tbl. III config: tile m=256 spike rows x k=16
    input columns x n=128 output channels, 128 8-bit-add PEs (one weight row of n per cycle).
    Spike matrix = (T x L) x d_in, time-major rows (Sec. II). Per (m,k) tile every row takes one Prefix: the row
    in the tile whose spikes are the largest subset of its own (proper subset, or an exact match with a smaller
    index); it then costs popcount(row XOR prefix) cycles, at least 1 (Sec. VI-A: >= m + 4 per tile).
    The detector/pruner/dispatcher phase (m+4 cycles) overlaps with the previous tile's computation, so only the
    first tile's is added. The computation repeats for each of ceil(M/n) output-channel tiles.
    skip_empty=True: rows with no spike in the tile cost nothing (an optimistic upper bound for Prosperity)."""
    K, N = S.shape
    rows = np.empty((T * N, K), dtype=np.uint8)
    for t in range(T):
        rows[t * N:(t + 1) * N] = ((S >> t) & 1).T
    R_ = rows.shape[0]
    nmt = math.ceil(R_ / m)
    pad = nmt * m - R_
    total = 0
    pw = (1 << np.arange(k)).astype(np.int64)
    idx = np.arange(m)
    for k0 in range(0, K, k):
        blk = rows[:, k0:k0 + k].astype(np.int64)
        v = blk @ pw[:blk.shape[1]]
        valid_row = np.ones(R_, dtype=bool)
        if pad:
            v = np.concatenate([v, np.zeros(pad, dtype=np.int64)])
            valid_row = np.concatenate([valid_row, np.zeros(pad, dtype=bool)])
        v = v.reshape(nmt, m)
        vr = valid_row.reshape(nmt, m)
        pop = _popc16(v)
        # cand[t, i, j]: row j can be the Prefix of row i
        sub = (v[:, None, :] & ~v[:, :, None]) == 0
        earlier = (pop[:, None, :] < pop[:, :, None]) | ((v[:, None, :] == v[:, :, None]) & (idx[None, :] < idx[:, None])[None])
        cand = sub & earlier & vr[:, None, :]
        best = np.where(cand, pop[:, None, :], 0).max(2)
        cost = pop - best
        if skip_empty:
            cost = np.where(pop == 0, 0, np.maximum(cost, 1))
        else:
            cost = np.maximum(cost, 1)
        cost = np.where(vr, cost, 0)
        total += int(cost.sum()) + pipe * nmt
    return total * math.ceil(M / n) + (m + 4)


def _popc16(x):
    x = x.astype(np.int64)
    c = np.zeros_like(x)
    for b in range(16):
        c += (x >> b) & 1
    return c
