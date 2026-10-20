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
        "prosperity": "Prosperity", "ours": "TIDES"}


def main():
    """GOP/s and system GOP/J per design, PTB greyscale style (VGG16 black, ResNet18 hatched), legend outside right."""
    d = json.load(open(os.path.join(R, "same_node_45nm.json")))
    import plot_ptb_style as PS
    from matplotlib.patches import Patch
    plt, FS = PS.plt, PS.FS
    sty = (("#111111", ""), ("#FFFFFF", "////"))
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.1))
    w = 0.36
    for ax, key, ylab, tag in ((axes[0], "gops", "GOP/s", "(a) GOP/s"), (axes[1], "gopj_system", "GOP/J", "(b) GOP/J")):
        top = 0
        for j, n in enumerate(NETS):
            v = [d[k][n][key] for k in ORDER]
            x = np.arange(len(ORDER)) + (j - 0.5) * w
            ax.bar(x, v, w, color=sty[j][0], hatch=sty[j][1], edgecolor="#111111", linewidth=0.6, zorder=3)
            top = max(top, max(v))
            k = ORDER.index("ours")
            ax.annotate(f"{v[k]:.0f}", (x[k], v[k]), xytext=(0, 2), textcoords="offset points", ha="center",
                        va="bottom", fontsize=6.6, fontweight="bold", rotation=90, zorder=5)
        ax.set_xticks(range(len(ORDER)), [NAME[k] for k in ORDER], rotation=40, ha="right", fontsize=6.8,
                      fontweight="bold")
        ax.get_xticklabels()[ORDER.index("ours")].set_fontsize(7.6)
        ax.set_xlim(-0.6, len(ORDER) - 0.4)
        ax.set_ylim(0, top * 1.25)
        ax.set_ylabel(ylab, fontweight="bold")
        for t in ax.get_yticklabels():
            t.set_fontweight("bold")
        ax.yaxis.grid(True, ls=":", lw=0.6, color="#777777", zorder=0)
        ax.xaxis.grid(False)
        FS.panel_tag(ax, tag, y=-0.42)
    h = [Patch(facecolor=sty[j][0], hatch=sty[j][1], edgecolor="#111111", linewidth=0.6, label=n)
         for j, n in enumerate(NETS)]
    lg = fig.legend(h, list(NETS), loc="center right", frameon=True, fancybox=False, edgecolor="#111111",
                    handlelength=1.6, handleheight=1.0, borderpad=0.4, labelspacing=0.35,
                    prop={"weight": "bold", "size": 7})
    lg.get_frame().set_linewidth(0.6)
    fig.canvas.draw()
    lw = lg.get_window_extent().width / fig.bbox.width
    fig.subplots_adjust(left=0.065, right=0.985 - lw - 0.015, top=0.97, bottom=0.33, wspace=0.26)
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
    cap = 1e12                                       # no clipping: full scale, no axis break
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
            if k == "ours":
                ax.annotate(f"{tot:.0f}", (x, tot), xytext=(0, 2), textcoords="offset points", ha="center", va="bottom",
                            fontsize=6.8, color=FS.OURS_TEXT, zorder=5)
        ax.text(gi * (len(ORDER) + 1.2) + (len(ORDER) - 1) / 2, -0.27, n, transform=ax.get_xaxis_transform(),
                ha="center", va="top", fontsize=8)
    ax.set_xticks(xs, labels, rotation=35, ha="right", fontsize=6.8)
    top = max(sum(d[k][n][key] for key, *_ in comp) for k in ORDER for n in NETS) * 1e6
    ax.set_ylim(0, top * 1.08)
    ax.set_ylabel("Energy (µJ)")
    ax.yaxis.grid(True, zorder=0)
    h = [Patch(facecolor=c, edgecolor=PS.EDGE, linewidth=0.5, label=l) for _, l, c, _ in comp]
    FS.inside_legend(ax, h, [x.get_label() for x in h], ncol=3, loc="upper right")
    fig.subplots_adjust(left=0.07, right=0.995, top=0.985, bottom=0.27)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"energy_breakdown.{ext}"))


if __name__ == "__main__":
    main()
    breakdown()
