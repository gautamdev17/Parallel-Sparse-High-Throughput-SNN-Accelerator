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
    full = (1 << nw) - 1
    K, N = tag.shape
    H = np.zeros((N, 1 << nw), dtype=np.int64)
    np.add.at(H, (np.broadcast_to(np.arange(N), (K, N)).ravel(), tag.ravel()), 1)
    bursting = H[:, full].copy()
    H[:, 0] = 0
    H[:, full] = 0
    pairs = np.zeros(N, dtype=np.int64)
    vals = np.arange(1 << nw)
    pc = _popc(vals).astype(np.int64)
    for a in sorted(range(1, full), key=lambda v: -pc[v]):
        # candidates: exact complement first, then the non-overlapping tag with most bits ("nearest")
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
