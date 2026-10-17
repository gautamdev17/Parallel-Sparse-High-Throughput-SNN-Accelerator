"""
storage_compression.py -- stored bits of weights + spikes after each design's packing / compression, on the SAME matrices.

  compression ratio = (dense weight bits + dense spike bits) / (packed weight bits + packed spike bits)  (higher =
  better); dense: int8 weights (M x K = 128 x 128) and T=8-bit spike trains (K x N = 128 x 128).
  x = sparsity s, applied independently to both matrices: exactly s of the weights are 0 (the rest non-zero int8);
      exactly s of the neurons are silent (all T bits 0), every other neuron has >= 1 spike in its T timesteps
      (each timestep fires with q = 0.3, as in the main sparse90 workload).

Formats (paper quotes: results/compression_formats.md). Where a paper leaves a field width open, the smallest
lossless width is used (favours that baseline):
  Ours        (RTL, hw/rtl/ours/ours_core.v + tb_ours_closed.v) weights: per packed column R x (8-bit weight + 2-bit
              filter label) + F x 6-bit filter id; spikes (packer output, the group buffer): per group R*T spike
              bits + R*T 2-bit pixel labels + G x 7-bit pixel id + 3-bit count.
  LoAS        bitmask fibres of 128 positions (Sec IV-A, Sec V): weights 1 bit/position + 8 bit per non-zero;
              spikes 1 bit/neuron + T bits per non-silent neuron; + one pointer per fibre (width not given:
              ceil(log2(fibre bits)) = 10 bits).
  PTB         weights dense 8-bit (Table 4, no weight compression). Spikes: "No data compression is applied to
              binary input data" (Sec 6.1.1) -- the StSAP stream (Sec 4.4): silent neurons trimmed, non-bursting
              TBs paired (greedy, 1's complement first); per slot T bits + 1 owner bit per TW when paired +
              ceil(log2 K)-bit address per neuron; plus the TB-tags (T/TWS bits per neuron) that the trimming reads.
              Layout not given in the paper; best TWS of {1, 2, 4}.
  Phi         weights dense 8-bit + all pattern-weight products (q=128 per 16-input partition and output), 8 bit:
              (8 + 128*8)/(16*8) = 9x the dense weights = the paper's "9x dense without the prefetcher" (Fig 12b).
              Spikes: L1 pattern index matrix as a bitmask (1 bit per row segment) + 7-bit index per patterned
              segment; L2 packs (Sec 4.2.2): one partial-sum unit per row segment with corrections + one unit per
              +-1 correction, unit = 1-bit label + 4-bit column + 1-bit value. Field widths are not given in the
              paper; this layout reproduces its measured activation traffic (Fig 12a, ~0.49 of dense) on real
              CIFAR-10 spikes: 0.475 (VGG16), 0.466 (ResNet18). Rows = timestep x pixel.
  Prosperity  dense 8-bit weights and dense spike bits (product sparsity reduces computation, not storage).
  SpikeX      dense 8-bit weights; dense spike bits + 1-bit activity tag per neuron per time window (TWS=4).
  SpikeFlow   dense weights; 1-bit silence label per neuron, T bits per non-silent neuron (Sec 4.2).
  SATO        storage format not specified in the paper -> not plotted.

  python3 storage_compression.py            -> results/compression.json + validation printout
  python3 storage_compression.py plot       -> results/compression.png/.pdf
"""
import json, math, os, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import workload as wl
from ours import Cfg, pack_weights, pack_spikes, tile_masks
from baselines import _tags, ptb_pairs_count

R_OUT = os.path.join(HERE, "results")
T = 8
M, K, N = 128, 128, 128
SPARSITY = [0.50, 0.70, 0.80, 0.90, 0.95, 0.98]


# ------------------------------------------------------------------ inputs
def spikes(rng, K, N, s, T=T, q=0.3):
    """exactly round((1-s) K N) non-silent neurons, each with a T-bit train of >= 1 spike."""
    n = round((1 - s) * K * N)
    S = np.zeros(K * N, np.uint8)
    pos = rng.choice(K * N, n, replace=False)
    bits = np.zeros((n, T), bool)
    todo = np.arange(n)
    while len(todo):
        bits[todo] = rng.random((len(todo), T)) < q
        todo = todo[~bits[todo].any(1)]
    S[pos] = (bits * (1 << np.arange(T))).sum(1).astype(np.uint8)
    return S.reshape(K, N)


def weights(rng, M, K, s):
    """exactly round((1-s) M K) non-zero int8 weights."""
    n = round((1 - s) * M * K)
    W = np.zeros(M * K, np.int16)
    v = rng.integers(1, 128, n) * rng.choice([-1, 1], n)
    W[rng.choice(M * K, n, replace=False)] = v
    return W.reshape(M, K).astype(np.int8)


# ------------------------------------------------------------------ formats
def ours_bits(W, S, cfg=Cfg()):
    R, F, G = cfg.R, cfg.F, cfg.G
    nK = -(-K // R)
    Wp = np.zeros((M, nK * R), W.dtype); Wp[:, :K] = W
    Sp = np.zeros((nK * R, N), S.dtype); Sp[:K] = S
    wb = ab = 0
    used = set()
    for m0 in range(0, M, cfg.Mt):
        for kt in range(nK):
            cols = pack_weights(Wp[m0:m0 + cfg.Mt, kt * R:(kt + 1) * R], F)
            if cols:
                wb += len(cols) * (R * (8 + 2) + F * 6) + 4
                used.add(kt)
    for kt in sorted(used):
        for n0 in range(0, N, cfg.Nt):
            g = pack_spikes(tile_masks(Sp[kt * R:(kt + 1) * R, n0:n0 + cfg.Nt], T), G, cfg.W_open)
            ab += len(g) * (R * T + 2 * R * T + G * 7 + 3)
    return wb, ab


def loas_bits(W, S, fib=128):
    ptr = math.ceil(math.log2(fib * 8))
    wb = ab = 0
    for k0 in range(0, K, fib):
        L = min(fib, K - k0)
        wb += M * (L + ptr) + 8 * int((W[:, k0:k0 + L] != 0).sum())
        ab += N * (L + ptr) + T * int((S[k0:k0 + L] != 0).sum())
    return wb, ab


def ptb_bits(W, S):
    addr = math.ceil(math.log2(K))
    best = None
    for tws in (1, 2, 4):
        tag, nw = _tags(S, tws, T)
        slots = int(ptb_pairs_count(tag, nw).sum())
        nonsilent = int((tag != 0).sum())
        paired = nonsilent - slots                       # each pair saves one slot
        ab = K * N * nw + slots * T + paired * nw + nonsilent * addr
        best = ab if best is None else min(best, ab)
    return 8 * M * K, best


def spike_rows(S):
    return np.concatenate([((S >> t) & 1).T for t in range(T)], 0).astype(np.uint8)   # (T*N, K)


def kmeans_patterns(X, q=128, iters=20, seed=0):
    """Phi Alg. 1: k-means on Hamming distance, all-zero and one-hot rows left out, centres rounded to {0,1}."""
    X = X[X.sum(1) >= 2]
    if len(X) == 0:
        return np.zeros((0, X.shape[1]), np.uint8)
    rng = np.random.default_rng(seed)
    C = X[rng.choice(len(X), min(q, len(X)), replace=False)].astype(np.float32)
    Xf = X.astype(np.float32)
    for _ in range(iters):
        a = (Xf.sum(1)[:, None] + C.sum(1)[None] - 2 * Xf @ C.T).argmin(1)
        for j in range(len(C)):
            sel = Xf[a == j]
            if len(sel):
                C[j] = sel.mean(0) >= 0.5
    C = np.unique(C.astype(np.uint8), axis=0)
    return C[C.sum(1) >= 1]


def phi_decompose(X, Xcal=None, k=16, q=128):
    """-> per partition list of (pattern matrix rows (n,k), L2 +1 mask, L2 -1 mask). Xcal None: calibrate on X."""
    Xcal = X if Xcal is None else Xcal
    out = []
    for k0 in range(0, X.shape[1], k):
        A = X[:, k0:k0 + k].astype(np.float32)
        P = kmeans_patterns(Xcal[:, k0:k0 + k], q).astype(np.float32)
        raw = A.sum(1)
        if len(P):
            diff = A.sum(1)[:, None] + P.sum(1)[None] - 2 * A @ P.T
            j = diff.argmin(1)
            use = diff[np.arange(len(A)), j] < raw
            pat = np.where(use[:, None], P[j], 0)
        else:
            use, pat = np.zeros(len(A), bool), np.zeros_like(A)
        out.append((use, (A == 1) & (pat == 0), (A == 0) & (pat == 1), pat))
    return out


def phi_act_bits(X, Xcal=None, k=16, q=128, idx_bits=7, unit=6):
    bits = 0
    for use, plus, minus, _ in phi_decompose(X, Xcal, k, q):
        nnz = plus.sum(1) + minus.sum(1)
        bits += len(use) + idx_bits * int(use.sum()) + unit * int(nnz.sum() + (nnz > 0).sum())
    return bits


def phi_bits(W, S, q=128, k=16, pwp_bits=8):
    wb = 8 * M * K + q * math.ceil(K / k) * M * pwp_bits
    return wb, phi_act_bits(spike_rows(S).T.T, None, k, q)        # rows = timestep x pixel, columns = K


def prosperity_bits(W, S):
    return 8 * M * K, T * K * N


def spikex_bits(W, S, tws=4):
    return 8 * M * K, T * K * N + K * N * (T // tws)


def spikeflow_bits(W, S):
    return 8 * M * K, K * N + T * int((S != 0).sum())


DESIGNS = [("ours", "Ours", ours_bits), ("loas", "LoAS", loas_bits), ("ptb", "PTB", ptb_bits),
           ("phi", "Phi", phi_bits), ("prosperity", "Prosperity", prosperity_bits),
           ("spikex", "SpikeX", spikex_bits), ("spikeflow", "SpikeFlow", spikeflow_bits)]


def run():
    out = {}
    dense = 8 * M * K + T * K * N
    for s in SPARSITY:
        rng = np.random.default_rng(int(s * 1000))
        W, S = weights(rng, M, K, s), spikes(rng, K, N, s)
        row = {"weight_density": float((W != 0).mean()), "bit_density": float(wl.popcount8(S).sum() / (K * N * T)),
               "nonsilent": float((S != 0).mean())}
        for key, _, fn in DESIGNS:
            wb, ab = fn(W, S)
            row[key] = dict(w=int(wb), a=int(ab), ratio=dense / (wb + ab), w_ratio=8 * M * K / wb,
                            a_ratio=T * K * N / ab)
        out[str(s)] = row
        print(f"s={s:.0%} bit {row['bit_density']:.3f} ns {row['nonsilent']:.3f} | " +
              " ".join(f"{k} {row[k]['ratio']:.3f}" for k, _, _ in DESIGNS), flush=True)
    json.dump(out, open(os.path.join(R_OUT, "compression.json"), "w"), indent=1)


# ------------------------------------------------------------------ validation against the papers
def validate():
    lines = []
    # Phi Table 4, random matrices (k=16, q=128, no PAFT): bit / L1 / L2+ / L2- density, speed-up over bit
    paper = {0.05: (5.0, 2.4, 2.6, 0.0, 2.0), 0.10: (10.0, 6.6, 3.4, 0.0, 2.9), 0.20: (19.9, 13.9, 6.4, 0.4, 2.9),
             0.50: (50.0, 49.8, 7.9, 7.7, 3.2)}
    lines.append("Phi Table 4 (random), paper vs ours [bit / L1 / L2+ / L2- %, over-bit x]:")
    for d, ref in paper.items():
        X = (np.random.default_rng(1).random((1024, 512)) < d).astype(np.uint8)
        dec = phi_decompose(X)
        n = X.size
        l1 = sum(p.sum() for *_, p in dec) / n
        lp = sum(pl.sum() for _, pl, _, _ in dec) / n
        lm = sum(mi.sum() for _, _, mi, _ in dec) / n
        got = (100 * X.mean(), 100 * l1, 100 * lp, 100 * lm, X.mean() / (lp + lm))
        lines.append(f"  {d:.0%}: paper {ref[0]:.1f}/{ref[1]:.1f}/{ref[2]:.1f}/{ref[3]:.1f}/{ref[4]:.1f}x   "
                     f"ours {got[0]:.1f}/{got[1]:.1f}/{got[2]:.1f}/{got[3]:.1f}/{got[4]:.1f}x")
    print("\n".join(lines))
    return lines


LINES = [  # key, label, colour, line style, marker
    ("ours", "Ours", "#e8871e", "-", "o"),
    ("loas", "LoAS", "#5f5f5f", "-", "D"),
    ("spikeflow", "SpikeFlow", "#4a7396", "-", "v"),
    ("ptb", "PTB", "#8fb0cf", "-", "s"),
    ("prosperity", "Prosperity", "#2c4f6e", (0, (3, 2)), None),
    ("spikex", "SpikeX", "#9a9a9a", (0, (1, 1.5)), None),
    ("phi", "Phi", "#4a7396", (0, (5, 1.5, 1, 1.5)), "x"),
]


def plot():
    import plot_ptb_style as PS
    from matplotlib.ticker import FixedLocator, NullLocator, FixedFormatter
    plt = PS.plt
    d = json.load(open(os.path.join(R_OUT, "compression.json")))
    fig, ax = plt.subplots(figsize=(3.5, 2.6))
    x = np.arange(len(SPARSITY))
    for k, lab, col, ls, mk in LINES:
        y = [d[str(s)][k]["ratio"] for s in SPARSITY]
        ours = k == "ours"
        ax.plot(x, y, color=col, ls=ls, lw=1.9 if ours else 1.0, marker=mk, ms=4.3 if ours else 3.2,
                mfc=col if ours else "white", mec=col, mew=0.9, label=lab, zorder=5 if ours else 3)
        if ours:
            ax.annotate(f"{y[-1]:.1f}\u00d7", (x[-1], y[-1]), xytext=(-4, 4), textcoords="offset points",
                        ha="right", va="bottom", fontsize=7.5, color="#a85a0c", fontweight="bold")
    ax.set_yscale("log")
    ticks = [0.2, 0.5, 1, 2, 5, 10, 20]
    ax.yaxis.set_major_locator(FixedLocator(ticks))
    ax.yaxis.set_major_formatter(FixedFormatter([f"{t:g}\u00d7" for t in ticks]))
    ax.yaxis.set_minor_locator(NullLocator())
    ax.set_ylim(0.15, 25)
    ax.set_xticks(x, [f"{100 * s:g}%" for s in SPARSITY])
    ax.set_xlim(-0.25, len(x) - 0.75)
    ax.tick_params(labelsize=8)
    ax.set_xlabel("Sparsity of weights and spikes", fontsize=8.5)
    ax.set_ylabel("Compression ratio (dense / packed)", fontsize=8.5)
    ax.yaxis.grid(True, ls="-", color="#e6e6e6", lw=0.6, zorder=0)
    h, l = ax.get_legend_handles_labels()
    PS.inside_legend(ax, h, l, ncol=2, loc="upper left", handlelength=2.0, fontsize=6.8)
    fig.subplots_adjust(left=0.15, right=0.97, top=0.97, bottom=0.16)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R_OUT, f"compression.{ext}"), dpi=300)


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "validate":
        validate()
    elif len(sys.argv) > 1 and sys.argv[1] == "plot":
        plot()
    elif len(sys.argv) == 1:
        run()
