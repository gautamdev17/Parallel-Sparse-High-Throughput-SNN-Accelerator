"""
plot_compression_cool.py -- storage compression ratio vs sparsity (results/compression.json from storage_compression.py)
in the style of Prosperity's Fig. 7: sans-serif text, no frame, light horizontal gridlines only, the y-axis title
written flat above the axis, round-marker lines in soft colours, frameless legend below; flat reference lines
(Prosperity, SpikeX) drawn without markers.

  python3 plot_compression_cool.py   -> results/compression_cool.png/.pdf
"""
import json, os
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D

HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
SANS = ["Helvetica", "Arial", "DejaVu Sans"]

# (key, label, colour, line width, marker)
SERIES = [("ours", "Ours", "#E8604C", 2.2, "o"),
          ("loas", "LoAS", "#4A8FE0", 1.5, "o"),
          ("phi", "Phi", "#8E5BB5", 1.5, "o"),
          ("spikeflow", "SpikeFlow", "#F2A7A0", 1.5, "o"),
          ("ptb", "PTB", "#86CDEB", 1.5, "o"),
          ("prosperity", "Prosperity", "#C4B9EE", 1.8, None),
          ("spikex", "SpikeX", "#9FDCF5", 1.8, None)]


def main():
    """our own clean style, only inspired by Prosperity Fig. 7: the paper's font (figstyle), open axes (left/bottom),
    light horizontal grid, log2 y so the low baselines separate, round markers, ours as the bold accent line,
    flat references dashed without markers, frameless legend below."""
    import sys
    sys.path.insert(0, HERE)
    import plot_ptb_style as PS
    from matplotlib.ticker import FixedLocator, FixedFormatter, NullLocator
    plt_, FS = PS.plt, PS.FS
    c = json.load(open(os.path.join(R, "compression.json")))
    sp = list(c)
    x = np.arange(len(sp))
    series = [("ours", "Ours", FS.OURS, 2.4, "o", "-"),
              ("loas", "LoAS", "#3F6FB5", 1.4, "o", "-"),
              ("phi", "Phi", "#7B5AA6", 1.4, "o", "-"),
              ("spikeflow", "SpikeFlow", "#2E9C8F", 1.4, "o", "-"),
              ("ptb", "PTB", "#C8506A", 1.4, "o", "-"),
              ("prosperity", "Prosperity", "#8C8C8C", 1.2, None, (0, (4, 2))),
              ("spikex", "SpikeX", "#B5B5B5", 1.2, None, (0, (1.5, 1.5)))]
    fig, ax = plt_.subplots(figsize=(FS.COL, 2.5))
    for k, lab, col, lw, mk, ls in series:
        y = np.array([c[s_][k]["ratio"] for s_ in sp])
        ax.plot(x, y, color=col, lw=lw, ls=ls, marker=mk, ms=5.2 if k == "ours" else 3.6, mfc=col,
                mec="white", mew=0.7, label=lab, zorder=5 if k == "ours" else 3, solid_capstyle="round")
        if k == "ours":
            ax.annotate(f"{y[-1]:.1f}×", (x[-1], y[-1]), xytext=(-6, 3), textcoords="offset points", ha="right",
                        va="bottom", fontsize=8, fontweight="bold", color=FS.OURS_TEXT)
    ax.set_yscale("log", base=2)
    ticks = [0.5, 1, 2, 4, 8, 16]
    ax.set_ylim(0.6, 14)
    ax.yaxis.set_major_locator(FixedLocator(ticks))
    ax.yaxis.set_major_formatter(FixedFormatter([f"{t:g}×" for t in ticks]))
    ax.yaxis.set_minor_locator(NullLocator())
    ax.set_xticks(x, [f"{float(s_) * 100:g}%" for s_ in sp])
    ax.set_xlim(-0.3, len(sp) - 0.7)
    ax.yaxis.grid(True, color="#E3E3E3", lw=0.7, zorder=0)
    ax.xaxis.grid(False)
    for side in ("top", "right"):
        ax.spines[side].set_visible(False)
    for side in ("left", "bottom"):
        ax.spines[side].set_color("#555555")
        ax.spines[side].set_linewidth(0.7)
    ax.tick_params(axis="both", which="both", direction="out", length=2.5, width=0.6, colors="#333333",
                   top=False, right=False)
    ax.set_xlabel("Sparsity")
    ax.set_ylabel("Compression ratio")
    h, l = ax.get_legend_handles_labels()
    FS.inside_legend(ax, h, l, ncol=2, loc="upper left", fontsize=6.6, handlelength=2.0)
    ax.set_ylim(0.6, 18)
    fig.subplots_adjust(left=0.14, right=0.97, top=0.97, bottom=0.17)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"compression_cool.{ext}"))


if __name__ == "__main__":
    main()
