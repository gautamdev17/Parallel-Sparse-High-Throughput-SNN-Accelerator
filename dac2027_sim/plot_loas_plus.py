"""plot_loas_plus.py -- LoAS+ figures (DAC / ACM style from figstyle.py).

  results/loas_plus_speedup.{pdf,png} : speedup over LoAS, cumulative C1 -> C2 -> C3, synthetic + real spikes
  results/loas_plus_layers.{pdf,png}  : per-layer speedup on real spikes (VGG16, ResNet18, 90 % weight sparsity)

Inputs: results/loas_plus.json, results/loas_plus_real.json (python3 loas_plus.py; python3 loas_plus.py real).
The per-layer real-spike cycles are computed here and cached in results/loas_plus_real_layers.json.
"""
import json, os, zlib
import numpy as np
import figstyle as FS
import matplotlib.pyplot as plt
from matplotlib.patches import Patch

HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
EDGE = FS.EDGE
STAGES = [("LoAS-overlap", "LoAS (next fetch overlapped)", dict(color="#c3d3e2", hatch="////")),
          ("+C1", "+C1 prefix-free join", dict(color="#fbe4c9", hatch="")),
          ("+C1+C2", "+C2 4-match join", dict(color="#f4b870", hatch="")),
          ("+C1+C2+C3", "+C3 skip + elastic = LoAS+", dict(color=FS.OURS, hatch=""))]


def speedup_fig():
    syn = json.load(open(os.path.join(R, "loas_plus.json")))["totals"]
    real = json.load(open(os.path.join(R, "loas_plus_real.json")))
    sections = [("Synthetic: 90% weight, 90% spike sparsity", "sparse90", syn),
                ("Synthetic: dense weights (LoAS stats)", "zipstats", syn),
                ("Real spikes: 90% wt. sp.", "real-spikes wd=0.1", real),
                ("Real spikes: 98% wt. sp.", "real-spikes wd=0.02", real)]
    groups = []                                     # (section index, x label, cycles dict)
    for si, (_, w, src) in enumerate(sections):
        for key, cyc in src.items():
            ww, net, b = key.split("|")
            if ww == w:
                groups.append((si, f"{'VGG' if net == 'VGG16' else 'RN'}{'' if src is real else ' b' + b}", cyc))
    fig, ax = plt.subplots(figsize=(FS.TEXT, 2.05))
    fig.subplots_adjust(left=0.065, right=0.995, top=0.80, bottom=0.2)
    w, gap = 0.19, 0.55
    x, xs, prev = 0.0, [], None
    for si, _, _ in groups:
        if prev is not None and si != prev:
            x += gap
        xs.append(x); x += 1; prev = si
    xs = np.array(xs)
    for j, (v, lab, st) in enumerate(STAGES):
        val = np.array([g[2]["LoAS"] / g[2][v] for g in groups])
        pos = xs + (j - 1.5) * w
        ax.bar(pos, val, w, color=st["color"], hatch=st["hatch"], edgecolor=EDGE, linewidth=0.5, label=lab, zorder=3)
        if v == "+C1+C2+C3":
            for p, s in zip(pos, val):
                ax.text(p, s + 0.08, f"{s:.1f}" + r"$\times$", ha="center", va="bottom", fontsize=6.5,
                        color=FS.OURS_TEXT, zorder=4)
    ax.axhline(1, color=EDGE, lw=0.6, ls=(0, (3, 2)), zorder=2, label=r"LoAS = 1$\times$")
    ax.set_xticks(xs); ax.set_xticklabels([g[1] for g in groups])
    ax.set_xlim(xs[0] - 0.55, xs[-1] + 0.55)
    ax.set_ylim(0, 4.4); ax.set_yticks(range(0, 5))
    ax.set_ylabel(r"Speedup over LoAS ($\times$)")
    ax.grid(axis="y", zorder=0)
    for si, (title, _, _) in enumerate(sections):
        sx = xs[[g[0] == si for g in groups]]
        ax.text(sx.mean(), -0.2, title, transform=ax.get_xaxis_transform(), ha="center", va="top", fontsize=7)
        if si:
            ax.axvline(sx[0] - (1 + gap) / 2, color="#999999", lw=0.4, zorder=1)
    h, l = ax.get_legend_handles_labels()
    h, l = h[1:] + h[:1], l[1:] + l[:1]
    lg = ax.legend(h, l, ncol=5, loc="lower center", bbox_to_anchor=(0.5, 1.02), frameon=True, fancybox=False,
                   edgecolor=EDGE, fontsize=7, handlelength=1.0, handleheight=1.0, handletextpad=0.4,
                   columnspacing=1.0, borderpad=0.35)
    lg.get_frame().set_linewidth(0.5)
    for ext in ("pdf", "png"):
        fig.savefig(os.path.join(R, f"loas_plus_speedup.{ext}"))
    plt.close(fig)


def real_layers(wd=0.10):
    path = os.path.join(R, "loas_plus_real_layers.json")
    if os.path.exists(path):
        return json.load(open(path))
    import loas_plus as lp, workload as wl
    out = {}
    for net in ("VGG16", "ResNet18"):
        rows = []
        for key, co, S in lp.real_layers(net):
            rng = np.random.default_rng(zlib.crc32(f"real|{net}|{key}|{wd}".encode()))   # same tensors as loas_plus.real
            W = wl.rand_weights(rng, co, S.shape[0], wd)
            rows.append(dict(layer=key, density=float((S > 0).mean()),
                             **{v: lp.layer_cycles(W, S, v) for v in ("LoAS", "LoAS-overlap", "+C1+C2+C3")}))
            print(net, rows[-1], flush=True)
        out[net] = rows
    json.dump(out, open(path, "w"), indent=1)
    return out


def layers_fig():
    data = real_layers()
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 1.85), gridspec_kw=dict(width_ratios=[14, 16]))
    fig.subplots_adjust(left=0.06, right=0.995, top=0.83, bottom=0.27, wspace=0.12)
    for ax, (net, tag) in zip(axes, (("VGG16", "(a) VGG16"), ("ResNet18", "(b) ResNet18 (Prosperity variant)"))):
        rows = data[net]
        x = np.arange(len(rows))
        base = np.array([r["LoAS"] for r in rows], float)
        for j, (v, lab, st) in enumerate([STAGES[0], STAGES[3]]):
            s = base / np.array([r[v] for r in rows])
            ax.bar(x + (j - 0.5) * 0.36, s, 0.36, color=st["color"], hatch=st["hatch"], edgecolor=EDGE, lw=0.5,
                   label=lab if v != "+C1+C2+C3" else "LoAS+ (C1+C2+C3)", zorder=3)
        tot = base.sum() / sum(r["+C1+C2+C3"] for r in rows)
        ax.axhline(1, color=EDGE, lw=0.6, ls=(0, (3, 2)), zorder=2, label=r"LoAS = 1$\times$")
        ax.text(0.01, 0.95, f"whole network: {tot:.2f}" + r"$\times$", transform=ax.transAxes, ha="left", va="top",
                fontsize=7, color=FS.OURS_TEXT)
        ax.set_xticks(x)
        ax.set_xticklabels([r["layer"].replace("conv2d_", "c").replace("fc_", "fc") for r in rows], rotation=90)
        ax.set_xlim(-0.6, len(rows) - 0.4)
        ax.set_ylim(0, 5.2); ax.set_yticks(range(0, 6))
        ax.grid(axis="y", zorder=0)
        FS.panel_tag(ax, tag, y=-0.3)
    axes[0].set_ylabel(r"Speedup over LoAS ($\times$)")
    h, l = axes[0].get_legend_handles_labels()
    h, l = h[1:] + h[:1], l[1:] + l[:1]
    lg = fig.legend(h, l, ncol=3, loc="upper center", bbox_to_anchor=(0.5, 1.0), frameon=True, fancybox=False,
                    edgecolor=EDGE, fontsize=7, handlelength=1.0, handleheight=1.0, handletextpad=0.4,
                    columnspacing=1.2, borderpad=0.35)
    lg.get_frame().set_linewidth(0.5)
    for ext in ("pdf", "png"):
        fig.savefig(os.path.join(R, f"loas_plus_layers.{ext}"))
    plt.close(fig)


if __name__ == "__main__":
    speedup_fig()
    layers_fig()
    print("wrote results/loas_plus_speedup.{pdf,png}, results/loas_plus_layers.{pdf,png}")
