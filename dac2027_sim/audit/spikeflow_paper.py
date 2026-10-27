"""Paper-faithful per-layer cycle model of SpikeFlow (Wang et al., J. Syst. Archit. 169 (2025) 103604).

Line numbers refer to scratchpad/papers/Spikeflow.txt.

Hardware taken from the paper
  * 16 x 16 PE array, 16 LIF-PEs in ONE row (Table 1, l.824-825); OS systolic array (Sec. 4.3.1, l.659).
  * PE: 1-bit image gates the accumulator; image enters from the top and passes down (img-out),
    weight enters from the left and passes right (Fig. 10b). Gating saves power only (l.666-670):
    no cycle is saved by a zero spike inside a streamed K entry, and zero weights are never skipped
    (nothing in the paper; LoAS is excluded as "dual-sparse", l.961-965).
  * Columns = parallel computation dimension (PCD = 16): T < PCD -> PCD/T spatial positions x T
    timesteps share the columns (Sec. 4.1, l.526-531); T > PCD -> time split into ceil(T/PCD)
    sequential chunks with the membrane stored between them (l.536-545, l.748-752).
    Rows = output channels (weights stream per row, Fig. 10b).
  * Silence (Sec. 4.2): T < PCD -> Silence Cell Group: an input (im2col row k) is skipped for a
    column group only when every neuron of the group is zero at all timesteps (l.581-586, l.605-611);
    T = PCD -> Silence Cell (l.587-591); T > PCD -> Partial Silence Cell per time chunk (l.592-597).
    Silence processing "reduc[es] the dimension of K" (l.948-950): a pass streams K' non-silent
    entries, one per cycle.
  * SA results leave the array row by row "in a stepped time sequence" into the single LIF-PE row
    (l.713-715, Fig. 9/11): the LIF row absorbs one SA row (16 columns) per cycle, so a 16-row tile
    needs >= 16 LIF cycles.
  * Silence processing / data migration / computation are pipelined (Sec. 4.4, Fig. 13) and the
    paper asserts computation dominates (l.786-789) -> no memory stall is modelled.

Not stated in the paper (variants)
  * Whether consecutive passes (tiles) overlap their fill/drain. The only double buffering mentioned
    is of on-chip memory (l.646-652, l.683-687), not of PE accumulators; 272 accumulators = 256 PE +
    16 LIF (l.827), i.e. one per PE.
      lenient : passes back to back, one fill per layer (as baselines.py), but each pass is bounded
                by the single LIF row: max(K', R) cycles. Fully silent passes skipped.
      medium  : no inter-pass overlap; each non-silent pass costs K' + R + C - 2 (skewed fill/drain).
      strict  : SCALE-Sim OS fold: K' + 2R + C - 2 per pass (extra R-cycle shift-out drain to the
                LIF row); fully silent passes still cost R LIF cycles (output neurons still activated).
  * current : exact re-implementation of baselines.spikeflow_layer_cycles (for checking the cache).
"""
import math
import numpy as np


def pass_K(S, T, pcd=16):
    """Per-pass non-silent K count for one output-channel tile. S: (K, N) uint (bit t = timestep t)."""
    K, N = S.shape
    if T <= pcd:
        g = pcd // T                                   # spatial positions sharing the columns
        nz = S != 0                                    # neuron fires at least once over T
        pad = (-N) % g
        if pad:
            nz = np.concatenate([nz, np.zeros((K, pad), bool)], 1)
        return nz.reshape(K, -1, g).any(2).sum(0)      # (n_groups,)
    # T > pcd: Partial Silence Cell, one pass per (pixel, time chunk)
    out = []
    S64 = S.astype(np.uint64)
    for c in range(math.ceil(T / pcd)):
        lo, hi = c * pcd, min(T, (c + 1) * pcd)
        mask = np.uint64(((1 << (hi - lo)) - 1) << lo)
        out.append(((S64 & mask) != 0).sum(0))
    return np.concatenate(out)


def spikeflow_paper_cycles(W, S, T, rows=16, pcd=16, variant="medium"):
    """W: (M_out, K) weights (only its shape is used: zero weights are not skipped). S: (K, N) spikes."""
    M = W.shape[0]
    R, C = rows, pcd
    kp = pass_K(S, T, pcd)
    ct = math.ceil(M / R)                              # output-channel tiles; spikes re-streamed per tile
    fill = R + C - 2
    if variant == "current":
        return ct * int(kp.sum()) + fill
    if variant == "lenient":
        return ct * int(np.where(kp > 0, np.maximum(kp, R), 0).sum()) + fill
    if variant == "medium":
        return ct * int(np.where(kp > 0, kp + fill, 0).sum())
    if variant == "strict":
        return ct * int(np.where(kp > 0, kp + fill + R, R).sum())
    raise ValueError(variant)


VARIANTS = ("current", "lenient", "medium", "strict")

if __name__ == "__main__":
    import json, os, sys
    SIM = "/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/dac2027_sim"
    SD = os.path.join(SIM, "results/prune_chain")
    cache = json.load(open(os.path.join(SIM, "results/prune_chain_cache.json")))
    net = sys.argv[1] if len(sys.argv) > 1 else "VGG16"
    T = 8
    summary = {}
    for lvl in ("dense", "sp90", "sp95", "sp98"):
        d = np.load(os.path.join(SD, f"{net}_{lvl}.npz"))
        meta = json.load(open(os.path.join(SD, f"{net}_{lvl}.json")))["layers"]
        tot = {v: 0 for v in VARIANTS}
        tot["cache"] = 0
        npass = nsil = nsmall = 0
        print(f"\n== {net} {lvl}")
        print(f"{'li':>3} {'name':14} {'M':>5} {'K':>6} {'N':>5} {'cache':>9} " +
              " ".join(f"{v:>9}" for v in VARIANTS) + "  meanK'  %K'<16  %silent")
        for li, m in enumerate(meta):
            if m.get("analog"):
                continue
            W, S = d[f"W{li}"], d[f"S{li}"]
            kp = pass_K(S, T)
            ct = math.ceil(W.shape[0] / 16)
            npass += ct * kp.size; nsil += ct * int((kp == 0).sum()); nsmall += ct * int(((kp > 0) & (kp < 16)).sum())
            cy = {v: spikeflow_paper_cycles(W, S, T, variant=v) for v in VARIANTS}
            key = str((net, lvl, li))
            cc = cache[key]["cycles"]["spikeflow"] if key in cache else -1
            for v in VARIANTS:
                tot[v] += cy[v]
            tot["cache"] += cc
            print(f"{li:>3} {m['name']:14} {W.shape[0]:>5} {W.shape[1]:>6} {S.shape[1]:>5} {cc:>9} " +
                  " ".join(f"{cy[v]:>9}" for v in VARIANTS) +
                  f"  {kp.mean():6.1f}  {100*((kp>0)&(kp<16)).mean():5.1f}  {100*(kp==0).mean():5.1f}")
        print("TOTAL", {k: v for k, v in tot.items()},
              {v: round(tot[v] / tot["cache"], 3) for v in VARIANTS},
              f"passes={npass} silent={nsil} K'<16={nsmall}")
        summary[lvl] = dict(tot, passes=npass, silent=nsil, small=nsmall)
    json.dump(summary, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), f"summary_{net}.json"), "w"),
              indent=1)
