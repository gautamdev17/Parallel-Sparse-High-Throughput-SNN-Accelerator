"""
compare_sparsity.py -- sparsity of the real pruned QCFS VGG-16 traces (INT8 weights, T = 8 and T = 16) against the
synthetic sparse90 workload of the main results (workload.rand_weights / rand_spikes: weight density 0.10 scattered,
10% non-silent neurons, each active neuron fires with q = 0.3 per timestep, T = 8).

Per layer (the 15 spiking layers; the first layer's input is the analog image): weight density of the INT8 weights,
fraction of non-silent input neurons and spike-bit density (input X, or the pre-pool spikes P for a layer after an
AvgPool). Averages are weighted by the layer's dense GEMM work M x K x N (where the cycles are), and also plain.

  python compare_sparsity.py   -> results/sparsity_real_vs_synthetic.md, .png, .pdf
"""
import json, os, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
R = os.path.join(os.path.dirname(HERE), "results")
SYN = dict(wd=0.10, ns=0.10, q=0.3, T=8)


def syn_bit_density():
    """exact expected bit density of rand_spikes: active neurons get Bernoulli(q) bits, an all-zero train gets one
    random spike."""
    q, T = SYN["q"], SYN["T"]
    p0 = (1 - q) ** T
    return SYN["ns"] * (q + p0 / T)


def real(tag):
    d = np.load(os.path.join(R, tag + ".npz"))
    meta = json.load(open(os.path.join(R, tag + "_meta.json")))
    T = meta["T"]
    rows = []
    for li, l in enumerate(meta["layers"]):
        if l["analog"]:
            continue
        W = d[f"W{li}"]
        X = d[f"P{li}"] if f"P{li}" in d.files else d[f"X{li}"]
        bits = sum(int(((X >> t) & 1).sum()) for t in range(T))
        if l["kind"] == "conv":
            work = l["co"] * l["ci"] * l["k"] ** 2 * l["h"] ** 2       # per image
        else:
            work = l["co"] * l["ci"]
        rows.append(dict(name=l["name"], work=work, wd=float((W != 0).mean()), ns=float((X != 0).mean()),
                         bits=bits / (X.size * T), fire=bits / max(int((X != 0).sum()), 1) / T))
    return T, rows


def avg(rows, k, weighted):
    w = np.array([r["work"] for r in rows], float) if weighted else np.ones(len(rows))
    return float(np.dot(w, [r[k] for r in rows]) / w.sum())


def main():
    sets = [("T = 8", *real("qcfs_vgg16_cifar10_T8")), ("T = 16", *real("qcfs_vgg16_cifar10_T16"))]
    syn = dict(wd=SYN["wd"], ns=SYN["ns"], bits=syn_bit_density(), fire=syn_bit_density() / SYN["ns"])
    L = ["# Real pruned QCFS VGG-16 vs synthetic sparse90", "",
         "Real: SNN-QCFS-Pruning VGG-16 (DepGraph group_sl, L = 8), INT8 weights (test_quantize.py pipeline), spikes "
         "of 16 CIFAR-10 test images. Synthetic: weight density 0.10 (scattered), 10% non-silent neurons, q = 0.3, "
         "T = 8. 'work-weighted' = weighted by each layer's dense M x K x N (where the cycles are).", "",
         "| | Weight density | Non-silent neurons | Spike-bit density | Firing rate of an active neuron |",
         "|---|---|---|---|---|",
         f"| Synthetic sparse90 | {syn['wd']:.3f} | {syn['ns']:.3f} | {syn['bits']:.4f} | {syn['fire']:.2f} |"]
    for lab, T, rows in sets:
        for wt in (True, False):
            L.append(f"| Real {lab}, {'work-weighted' if wt else 'plain mean'} | {avg(rows, 'wd', wt):.3f} | "
                     f"{avg(rows, 'ns', wt):.3f} | {avg(rows, 'bits', wt):.4f} | {avg(rows, 'fire', wt):.2f} |")
    L += ["", "Per layer (T = 16):", "", "| Layer | Share of work | Weight density | Non-silent | Spike-bit density |",
          "|---|---|---|---|---|"]
    rows16 = sets[1][2]
    tw = sum(r["work"] for r in rows16)
    for r in rows16:
        L.append(f"| {r['name']} | {100 * r['work'] / tw:.1f}% | {r['wd']:.3f} | {r['ns']:.3f} | {r['bits']:.4f} |")
    open(os.path.join(R, "sparsity_real_vs_synthetic.md"), "w").write("\n".join(L) + "\n")
    print("\n".join(L))
    plot(syn, sets)


def plot(syn, sets):
    import plot_ptb_style as PS
    plt, FS = PS.plt, PS.FS
    rows16 = sets[1][2]
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.2), gridspec_kw=dict(width_ratios=[1, 1.6]))
    # (a) work-weighted averages: density (lower = sparser)
    ax = axes[0]
    keys = [("wd", "Weights"), ("ns", "Active\nneurons"), ("bits", "Spike\nbits")]
    vals = [[syn[k] for k, _ in keys]] + [[avg(r, k, True) for k, _ in keys] for _, _, r in sets]
    labs = ["Synthetic (sparse90)", "Real, T = 8", "Real, T = 16"]
    sty = [dict(color="#FFFFFF", hatch="////"), dict(color="#8C8C8C"), dict(color="#111111")]
    x = np.arange(len(keys))
    w = 0.26
    for i, (v, lab, st) in enumerate(zip(vals, labs, sty)):
        b = ax.bar(x + (i - 1) * w, v, w, label=lab, edgecolor="#111111", linewidth=0.6, zorder=3, **st)
        for xi, vi in zip(x + (i - 1) * w, v):
            ax.annotate(f"{vi:.2f}" if vi >= 0.01 else f"{vi:.3f}", (xi, vi), xytext=(0, 1.5),
                        textcoords="offset points", ha="center", va="bottom", fontsize=5.6, rotation=90)
    ax.set_xticks(x, [k for _, k in keys], fontsize=6.8, fontweight="bold")
    ax.set_ylabel("Density (non-zero fraction)", fontweight="bold")
    ax.set_ylim(0, max(max(v) for v in vals) * 1.35)
    ax.yaxis.grid(True, ls=":", lw=0.6, color="#777777", zorder=0)
    ax.legend(fontsize=5.8, loc="upper right", frameon=True)
    FS.panel_tag(ax, "(a) Work-weighted average", y=-0.36)
    # (b) per layer, T = 16: weight density and active neurons vs the synthetic level
    ax = axes[1]
    n = len(rows16)
    xi = np.arange(n)
    tw = sum(r["work"] for r in rows16)
    ax.bar(xi, [100 * r["work"] / tw for r in rows16], 0.7, color="#E6E6E6", edgecolor="#9A9A9A", lw=0.5,
           zorder=1, label="Share of work (%)")
    ax2 = ax.twinx()
    ax2.plot(xi, [r["wd"] for r in rows16], "s-", color="#111111", ms=3, lw=1.1, zorder=4, label="Weight density")
    ax2.plot(xi, [r["ns"] for r in rows16], "o--", color="#666666", ms=3, lw=1.0, zorder=4, label="Active neurons")
    ax2.axhline(0.10, color="#111111", lw=0.8, ls=":", zorder=3)
    ax2.annotate("synthetic: 0.10", (n - 0.6, 0.10), xytext=(0, 2), textcoords="offset points", ha="right",
                 fontsize=5.8)
    ax2.set_ylim(0, 1.0)
    ax2.set_ylabel("Density", fontweight="bold")
    ax.set_ylabel("Share of work (%)", fontweight="bold")
    short = [r["name"].replace("layer", "L").replace("classifier.", "FC") for r in rows16]
    ax.set_xticks(xi, short, rotation=55, ha="right", fontsize=5.8)
    h1, l1 = ax.get_legend_handles_labels()
    h2, l2 = ax2.get_legend_handles_labels()
    ax2.legend(h1 + h2, l1 + l2, fontsize=5.6, loc="upper right", frameon=True)
    FS.panel_tag(ax, "(b) Per layer, real T = 16", y=-0.36)
    fig.subplots_adjust(left=0.07, right=0.94, top=0.96, bottom=0.34, wspace=0.32)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"sparsity_real_vs_synthetic.{ext}"))


if __name__ == "__main__":
    main()
