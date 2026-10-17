"""
packing_gains.py -- how much each design's packing / compression step reduces its work, on the SAME weight matrix W
(M x K) and spike matrix S (K x N, T-bit trains). Gain = work of the design WITHOUT its packing step / work WITH it.

  Ours (dual)      filter packing (offline, <= F=4 filters per column, no shared non-zero row) x pixel packing
                   (run time, <= G=4 pixels per group, no shared (row, timestep) bit, 4 open groups), per K-tile of
                   R=4 inputs, per output tile (64 filters x 128 pixels). Work = sum over K-tiles of columns x groups;
                   unpacked = non-zero filters x non-silent pixels (F = G = 1). Filter-only / pixel-only shown too.
  PTB (StSAP)      pairs two non-bursting inputs of a pixel whose time-window tags do not overlap (greedy, 1's
                   complement first). Work = slots per pixel; unpacked = non-silent inputs. Best TWS of {1, 2, 4}.
  LoAS (temporal)  packs the T timesteps of a neuron into one word (one match per non-silent neuron instead of one
                   per spike). Work = non-silent neurons; unpacked = spikes (neuron x timestep).
  Prosperity       product sparsity: in a tile of 256 spike rows x 16 inputs (rows = timestep x pixel), a row reuses
                   the result of its largest subset row (Prefix) and adds only the difference. Work = sum of
                   popcount(row) - popcount(prefix); unpacked = spikes.
  Phi              pattern-based hierarchical sparsity (ISCA'25, arXiv 2505.10909): per 16-input segment, 128 binary
                   patterns from k-means (Hamming) on calibration spikes (an independent draw of the same
                   distribution); each row segment takes the pattern with the fewest +-1 corrections, or none if the
                   raw bits are fewer. Work = corrections + one pattern-product lookup per patterned segment;
                   unpacked = spikes.
  SpikeX, SATO, SpikeFlow: no packing (gain 1).

  python3 packing_gains.py        -> results/packing_gains.json
  python3 packing_gains.py plot   -> results/packing_gains.png/.pdf
"""
import json, os, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import workload as wl
from ours import Cfg, pack_weights, pack_spikes, tile_masks
from baselines import _tags, ptb_pairs_count, _popc16

R_OUT = os.path.join(HERE, "results")
T, Q = 8, 0.3
M, K, N = 128, 1152, 256          # a VGG16 b2c2-sized layer (batch 1)


def ours_work(W, S, cfg=Cfg()):
    R = cfg.R
    nK = -(-K // R)
    Wp = np.zeros((M, nK * R), W.dtype); Wp[:, :K] = W
    Sp = np.zeros((nK * R, N), S.dtype); Sp[:K] = S
    w = dict(none=0, filt=0, pix=0, dual=0)
    for m0 in range(0, M, cfg.Mt):
        for kt in range(nK):
            Wt = Wp[m0:m0 + cfg.Mt, kt * R:(kt + 1) * R]
            nzf = int((Wt != 0).any(1).sum())
            if nzf == 0:
                continue
            cols = len(pack_weights(Wt, cfg.F))
            for n0 in range(0, N, cfg.Nt):
                masks = tile_masks(Sp[kt * R:(kt + 1) * R, n0:n0 + cfg.Nt], T)
                nzp = sum(1 for m in masks if m)
                grp = len(pack_spikes(masks, cfg.G, cfg.W_open))
                w["none"] += nzf * nzp; w["filt"] += cols * nzp; w["pix"] += nzf * grp; w["dual"] += cols * grp
    return {k: w["none"] / max(w[k], 1) for k in ("filt", "pix", "dual")}


def ptb_gain(S):
    best = 1.0
    for tws in (1, 2, 4):
        tag, nw = _tags(S, tws, T)
        best = max(best, int((tag != 0).sum()) / int(ptb_pairs_count(tag, nw).sum()))
    return best


def spike_rows(S):
    """(T*N, K) 0/1 rows, time-major (as in Prosperity / Phi)."""
    return np.concatenate([((S >> t) & 1).T for t in range(T)], 0).astype(np.uint8)


def loas_gain(S):
    return float(wl.popcount8(S).sum()) / max(int((S != 0).sum()), 1)


def prosperity_gain(S, m=256, k=16):
    rows = spike_rows(S)
    pw = (1 << np.arange(k)).astype(np.int64)
    spikes = work = 0
    idx = np.arange(m)
    for k0 in range(0, K, k):
        v = rows[:, k0:k0 + k].astype(np.int64) @ pw[:min(k, K - k0)]
        v = np.concatenate([v, np.zeros((-len(v)) % m, np.int64)]).reshape(-1, m)
        pop = _popc16(v)
        sub = (v[:, None, :] & ~v[:, :, None]) == 0
        earlier = (pop[:, None, :] < pop[:, :, None]) | ((v[:, None, :] == v[:, :, None]) & (idx[None, :] < idx[:, None])[None])
        best = np.where(sub & earlier, pop[:, None, :], 0).max(2)
        spikes += int(pop.sum()); work += int((pop - best).sum())
    return spikes / max(work, 1)


def _kmeans_patterns(X, q=128, iters=12, seed=0):
    """binary k-means with Hamming distance; X: (n, k) 0/1. Zero and one-hot rows are left out (as in Phi)."""
    X = X[X.sum(1) >= 2]
    if len(X) == 0:
        return np.zeros((0, 16), np.uint8)
    rng = np.random.default_rng(seed)
    C = X[rng.choice(len(X), min(q, len(X)), replace=False)].astype(np.float32)
    Xf = X.astype(np.float32)
    for _ in range(iters):
        d = Xf.sum(1)[:, None] + C.sum(1)[None] - 2 * Xf @ C.T          # Hamming distance
        a = d.argmin(1)
        for j in range(len(C)):
            sel = Xf[a == j]
            if len(sel):
                C[j] = (sel.mean(0) >= 0.5)
    C = np.unique(C.astype(np.uint8), axis=0)
    return C[C.sum(1) >= 1]


def phi_gain(S, S_cal, k=16, q=128):
    rows, cal = spike_rows(S), spike_rows(S_cal)
    spikes = work = 0
    for k0 in range(0, K, k):
        X = rows[:, k0:k0 + k]
        P = _kmeans_patterns(cal[:, k0:k0 + k], q)
        raw = X.sum(1).astype(np.int64)
        spikes += int(raw.sum())
        if len(P):
            Xf, Pf = X.astype(np.float32), P.astype(np.float32)
            diff = (Xf.sum(1)[:, None] + Pf.sum(1)[None] - 2 * Xf @ Pf.T).min(1).astype(np.int64)
            use = diff < raw
            work += int(np.where(use, diff + 1, raw).sum())
        else:
            work += int(raw.sum())
    return spikes / max(work, 1)


def point(wd, ns, seed):
    rng = np.random.default_rng(seed)
    W = wl.rand_weights(rng, M, K, wd)
    S = wl.rand_spikes(rng, (K, N), ns, Q)
    S_cal = wl.rand_spikes(np.random.default_rng(seed + 999), (K, N), ns, Q)
    o = ours_work(W, S)
    return dict(ours_dual=o["dual"], ours_filter=o["filt"], ours_pixel=o["pix"], ptb=ptb_gain(S),
                loas=loas_gain(S), prosperity=prosperity_gain(S), phi=phi_gain(S, S_cal))


ACT = [0.02, 0.05, 0.1, 0.2, 0.3, 0.5]          # non-silent fraction (weights 10% dense)
WGT = [0.02, 0.05, 0.1, 0.2, 0.3, 0.5, 1.0]     # weight density (activations 10% non-silent)


def main():
    out = {"act": {}, "wgt": {}}
    for ns in ACT:
        out["act"][str(ns)] = point(0.1, ns, 1)
        print("act", ns, {k: round(v, 2) for k, v in out["act"][str(ns)].items()}, flush=True)
    for wd in WGT:
        out["wgt"][str(wd)] = point(wd, 0.1, 2)
        print("wgt", wd, {k: round(v, 2) for k, v in out["wgt"][str(wd)].items()}, flush=True)
    json.dump(out, open(os.path.join(R_OUT, "packing_gains.json"), "w"), indent=1)


if __name__ == "__main__" and len(sys.argv) == 1:
    main()


LINES = [  # key, label, colour, style, marker, width
    ("ours_dual", "Ours (filter + pixel)", "#e8871e", "-", "o", 2.0),
    ("ours_pixel", "Ours (pixel only)", "#f0b26a", (0, (4, 2)), "v", 1.1),
    ("ours_filter", "Ours (filter only)", "#f0b26a", (0, (1, 1.5)), "^", 1.1),
    ("prosperity", "Prosperity", "#2c4f6e", "-", "P", 1.1),
    ("loas", "LoAS", "#8c8c8c", "-", "D", 1.1),
    ("ptb", "PTB", "#7fa2c3", "-", "s", 1.1),
    ("phi", "Phi", "#4a7396", (0, (5, 1.5, 1, 1.5)), "X", 1.1),
]


def plot():
    import plot_ptb_style as PS                      # same fonts, ticks and frame as the other figures
    plt = PS.plt
    d = json.load(open(os.path.join(R_OUT, "packing_gains.json")))
    fig, axes = plt.subplots(1, 2, figsize=(7.16, 2.7))
    for ax, key, xs, xl, tag in ((axes[0], "act", ACT, "Activation sparsity (weights 90% sparse)", "(a)"),
                                 (axes[1], "wgt", WGT, "Weight sparsity (activations 90% sparse)", "(b)")):
        xs_sorted = sorted(xs, reverse=True)         # sparsity increases to the right
        x = np.arange(len(xs_sorted))
        for k, lab, col, ls, mk, lw in LINES:
            y = [d[key][str(v)][k] for v in xs_sorted]
            ax.plot(x, y, color=col, ls=ls, marker=mk, ms=4.2 if k == "ours_dual" else 3.6, lw=lw,
                    mec=PS.EDGE, mew=0.5, label=lab, zorder=4 if k == "ours_dual" else 3)
        ax.axhline(1.0, color="#9a9a9a", lw=0.9, ls=(0, (6, 2, 1, 2)), zorder=2,
                   label="SpikeX / SATO / SpikeFlow")
        ax.set_xticks(x, [f"{100 * (1 - v):g}%" for v in xs_sorted])
        ax.set_xlim(-0.3, len(x) - 0.7)
        ax.set_ylim(0, 15)
        ax.set_xlabel(xl, fontsize=8.5)
        ax.set_ylabel("Packing gain (×)")
        ax.yaxis.grid(True, ls=":", color="#b0b0b0", lw=0.5, zorder=0)
        ax.text(0.5, -0.27, tag, transform=ax.transAxes, ha="center", va="top", fontsize=10)
    h, l = axes[1].get_legend_handles_labels()
    PS.inside_legend(axes[1], h, l, ncol=2, loc="upper left", handlelength=2.4, fontsize=6.9)
    fig.subplots_adjust(left=0.065, right=0.99, top=0.97, bottom=0.25, wspace=0.22)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R_OUT, f"packing_gains.{ext}"), dpi=300)


if __name__ == "__main__" and len(sys.argv) > 1 and sys.argv[1] == "plot":
    plot()
