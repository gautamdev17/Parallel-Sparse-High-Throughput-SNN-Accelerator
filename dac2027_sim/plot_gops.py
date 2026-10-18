"""
plot_gops.py -- GOP/s and GOP/J of every design at 45 nm, 500 MHz, workload sparse90 (results/same_node_45nm.json,
written by hw/same_node_table.py). GOP/J = system: core + SRAM (leakage, read/write) + DRAM energy.
Also the energy-per-image breakdown (core / SRAM / DRAM).

  python3 plot_gops.py   -> results/gops_gopj.png/.pdf, results/energy_breakdown.png/.pdf
"""
import json, os, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
R = os.path.join(HERE, "results")
NETS = ("VGG16", "ResNet18")
ORDER = ["ptb", "spikex", "loas_zip", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "loas_zip": "LoAS", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "Ours"}


def main():
    d = json.load(open(os.path.join(R, "same_node_45nm.json")))
    import plot_ptb_style as PS
    plt, FS = PS.plt, PS.FS
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.05))
    w = 0.112
    for ax, key, ylab, tag in ((axes[0], "gops", "GOP/s", "(a)"),
                               (axes[1], "gopj_system", "GOP/J", "(b)")):
        top = max(d[k][n][key] for k in ORDER for n in NETS)
        for i, k in enumerate(ORDER):
            x = np.arange(2) + (i - (len(ORDER) - 1) / 2) * (w + 0.008)
            v = [d[k][n][key] for n in NETS]
            st = PS.STYLE[k]
            ax.bar(x, v, w, color=st["color"], hatch=st["hatch"], edgecolor=PS.EDGE, linewidth=0.5, label=NAME[k],
                   zorder=3)
            if k == "ours":
                for xi, vi in zip(x, v):
                    ax.annotate(f"{vi:.0f}", (xi, vi), xytext=(0, 2), textcoords="offset points", ha="center",
                                va="bottom", fontsize=6.8, color=FS.OURS_TEXT, zorder=5,
                                bbox=dict(boxstyle="square,pad=0.06", fc="white", ec="none"))
        ax.set_ylim(0, top * 1.55)
        ax.set_xticks(range(2), NETS)
        ax.set_xlim(-0.55, 1.55)
        ax.set_ylabel(ylab)
        ax.yaxis.grid(True, zorder=0)
        FS.panel_tag(ax, tag, y=-0.15)
    h, l = axes[0].get_legend_handles_labels()
    FS.inside_legend(axes[0], h, l, ncol=4)
    fig.subplots_adjust(left=0.065, right=0.995, top=0.985, bottom=0.235, wspace=0.22)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"gops_gopj.{ext}"))


def breakdown():
    d = json.load(open(os.path.join(R, "same_node_45nm.json")))
    import plot_ptb_style as PS
    from matplotlib.patches import Patch
    plt, FS = PS.plt, PS.FS
    comp = (("e_core_J", "Core", "#4d4d4d", "#a0520a"), ("e_sram_J", "SRAM", "#9a9a9a", "#e8871e"),
            ("e_dram_J", "DRAM", "#dcdcdc", "#f6c48e"))
    fig, ax = plt.subplots(figsize=(FS.TEXT, 2.3))
    cap = 3600.0
    xs, labels = [], []
    for gi, n in enumerate(NETS):
        for i, k in enumerate(ORDER):
            x = gi * (len(ORDER) + 1.2) + i
            xs.append(x); labels.append(NAME[k])
            bot = 0.0
            for key, _, c, co in comp:
                v = d[k][n][key] * 1e6
                h = min(v, max(cap - bot, 0))
                ax.bar(x, h, 0.72, bottom=bot, color=co if k == "ours" else c, edgecolor=PS.EDGE, linewidth=0.5,
                       zorder=3)
                bot += v
            tot = bot
            if tot > cap:
                ax.text(x, cap * 1.01, f"{tot / 1e3:.1f} mJ", ha="center", va="bottom", fontsize=6.3, color="#333333")
                ax.plot([x - 0.36, x + 0.36], [cap * 0.965, cap * 0.985], color="white", lw=2.2, zorder=4)
            elif k == "ours":
                ax.annotate(f"{tot:.0f}", (x, tot), xytext=(0, 2), textcoords="offset points", ha="center", va="bottom",
                            fontsize=6.8, color=FS.OURS_TEXT, zorder=5)
        ax.text(gi * (len(ORDER) + 1.2) + (len(ORDER) - 1) / 2, -0.27, n, transform=ax.get_xaxis_transform(),
                ha="center", va="top", fontsize=8)
    ax.set_xticks(xs, labels, rotation=35, ha="right", fontsize=6.8)
    ax.set_ylim(0, cap * 1.12)
    ax.set_ylabel("Energy per image (µJ)")
    ax.yaxis.grid(True, zorder=0)
    h = [Patch(facecolor=c, edgecolor=PS.EDGE, linewidth=0.5, label=l) for _, l, c, _ in comp]
    FS.inside_legend(ax, h, [x.get_label() for x in h], ncol=3, loc="upper right")
    fig.subplots_adjust(left=0.07, right=0.995, top=0.985, bottom=0.27)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"energy_breakdown.{ext}"))


if __name__ == "__main__":
    main()
    breakdown()
