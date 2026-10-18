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


def main(src="compression.json", dst="compression_cool"):
    """our own clean style, only inspired by Prosperity Fig. 7: the paper's font (figstyle), open axes (left/bottom),
    light horizontal grid, log2 y so the low baselines separate, round markers, ours as the bold accent line,
    flat references dashed without markers, frameless legend below."""
    import sys
    sys.path.insert(0, HERE)
    import plot_ptb_style as PS
    from matplotlib.ticker import FixedLocator, FixedFormatter, NullLocator
    plt_, FS = PS.plt, PS.FS
    c = json.load(open(os.path.join(R, src)))
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
        fig.savefig(os.path.join(R, f"{dst}.{ext}"))


if __name__ == "__main__":
    main()


def two_panel():
    """(a) compression vs sparsity (results/compression.json), (b) compression vs spikes per active neuron at 90%
    sparsity (results/compression_intra.json); same series and style as main()."""
    import sys
    sys.path.insert(0, HERE)
    import plot_ptb_style as PS
    from matplotlib.ticker import FixedLocator, FixedFormatter, NullLocator
    plt_, FS = PS.plt, PS.FS
    c = json.load(open(os.path.join(R, "compression.json")))
    ci = json.load(open(os.path.join(R, "compression_intra.json")))
    series = [("ours", "Ours", FS.OURS, 2.4, "o", "-"), ("loas", "LoAS", "#3F6FB5", 1.4, "o", "-"),
              ("phi", "Phi", "#7B5AA6", 1.4, "o", "-"), ("spikeflow", "SpikeFlow", "#2E9C8F", 1.4, "o", "-"),
              ("ptb", "PTB", "#C8506A", 1.4, "o", "-"), ("prosperity", "Prosperity", "#8C8C8C", 1.2, None, (0, (4, 2))),
              ("spikex", "SpikeX", "#B5B5B5", 1.2, None, (0, (1.5, 1.5)))]
    fig, axes = plt_.subplots(1, 2, figsize=(FS.TEXT, 2.5))
    sp = list(c)
    qs = list(ci)
    panels = ((axes[0], np.arange(len(sp)), lambda k: [c[s_][k]["ratio"] for s_ in sp],
               [f"{float(s_) * 100:g}%" for s_ in sp], "Sparsity (weights and neurons)", "(a)"),
              (axes[1], np.array([ci[q]["spikes_per_active"] for q in qs]), lambda k: [ci[q][k] for q in qs],
               None, "Spikes per active neuron (of T = 8), 90% sparsity", "(b)"))
    for ax, x, gety, xt, xl, tag in panels:
        for k, lab, col, lw, mk, ls in series:
            y = np.array(gety(k))
            ax.plot(x, y, color=col, lw=lw, ls=ls, marker=mk, ms=5.0 if k == "ours" else 3.4, mfc=col,
                    mec="white", mew=0.7, label=lab, zorder=5 if k == "ours" else 3)
        ax.set_yscale("log", base=2)
        ticks = [0.5, 1, 2, 4, 8, 16]
        ax.yaxis.set_major_locator(FixedLocator(ticks))
        ax.yaxis.set_major_formatter(FixedFormatter([f"{t:g}×" for t in ticks]))
        ax.yaxis.set_minor_locator(NullLocator())
        if xt:
            ax.set_xticks(x, xt)
            ax.set_xlim(-0.3, len(x) - 0.7)
            ax.set_ylim(0.6, 18)
        else:
            ax.set_xlim(0.8, 7.6)
            ax.set_ylim(0.8, 6.5)
        ax.yaxis.grid(True, color="#E3E3E3", lw=0.7, zorder=0)
        ax.xaxis.grid(False)
        for side in ("top", "right"):
            ax.spines[side].set_visible(False)
        for side in ("left", "bottom"):
            ax.spines[side].set_color("#555555")
            ax.spines[side].set_linewidth(0.7)
        ax.tick_params(axis="both", which="both", direction="out", length=2.5, width=0.6, top=False, right=False)
        ax.set_xlabel(xl)
        ax.set_ylabel("Compression ratio")
        FS.panel_tag(ax, tag, y=-0.3)
    h, l = axes[0].get_legend_handles_labels()
    FS.inside_legend(axes[0], h, l, ncol=2, loc="upper left", fontsize=6.4, handlelength=2.0)
    fig.subplots_adjust(left=0.075, right=0.99, top=0.97, bottom=0.27, wspace=0.25)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"compression_two.{ext}"))


if __name__ == "__main__":
    two_panel()


def intra(src="compression_intra.json", dst="compression_intra"):
    """compression vs spike sparsity inside active neurons (1 - spikes / T), 90% weight and neuron sparsity."""
    import sys
    sys.path.insert(0, HERE)
    import plot_ptb_style as PS
    from matplotlib.ticker import FixedLocator, FixedFormatter, NullLocator
    plt_, FS = PS.plt, PS.FS
    ci = json.load(open(os.path.join(R, src)))
    qs = [q for q in ci if 1 - ci[q]["spikes_per_active"] / 8 >= 0.49]
    x = np.array([100 * (1 - ci[q]["spikes_per_active"] / 8) for q in qs])
    o = np.argsort(x)
    series = [("ours", "Ours", FS.OURS, 2.4, "o", "-"), ("loas", "LoAS", "#3F6FB5", 1.4, "o", "-"),
              ("phi", "Phi", "#7B5AA6", 1.4, "o", "-"), ("spikeflow", "SpikeFlow", "#2E9C8F", 1.4, "o", "-"),
              ("ptb", "PTB", "#C8506A", 1.4, "o", "-"), ("prosperity", "Prosperity", "#8C8C8C", 1.2, None, (0, (4, 2))),
              ("spikex", "SpikeX", "#B5B5B5", 1.2, None, (0, (1.5, 1.5)))]
    fig, ax = plt_.subplots(figsize=(FS.COL, 2.5))
    for k, lab, col, lw, mk, ls in series:
        y = np.array([ci[q][k] for q in qs])[o]
        ax.plot(x[o], y, color=col, lw=lw, ls=ls, marker=mk, ms=5.0 if k == "ours" else 3.4, mfc=col, mec="white",
                mew=0.7, label=lab, zorder=5 if k == "ours" else 3)
    ax.set_yscale("log", base=2)
    ticks = [1, 2, 4, 8]
    ax.yaxis.set_major_locator(FixedLocator(ticks))
    ax.yaxis.set_major_formatter(FixedFormatter([f"{t:g}×" for t in ticks]))
    ax.yaxis.set_minor_locator(NullLocator())
    ax.set_ylim(0.85, 11)
    ax.set_xlim(48, 87)
    ax.set_xticks([50, 60, 70, 80], ["50%", "60%", "70%", "80%"])
    ax.yaxis.grid(True, color="#E3E3E3", lw=0.7, zorder=0)
    ax.xaxis.grid(False)
    for side in ("top", "right"):
        ax.spines[side].set_visible(False)
    for side in ("left", "bottom"):
        ax.spines[side].set_color("#555555")
        ax.spines[side].set_linewidth(0.7)
    ax.tick_params(axis="both", which="both", direction="out", length=2.5, width=0.6, top=False, right=False)
    ax.set_xlabel("Spike sparsity inside active neurons")
    ax.set_ylabel("Compression ratio")
    h, l = ax.get_legend_handles_labels()
    FS.inside_legend(ax, h, l, ncol=2, loc="upper left", fontsize=6.4, handlelength=2.0)
    fig.subplots_adjust(left=0.14, right=0.97, top=0.97, bottom=0.17)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"{dst}.{ext}"))


if __name__ == "__main__":
    intra()


if __name__ == "__main__":
    main("compression_16.json", "compression_16")


if __name__ == "__main__":
    intra("compression_16_intra.json", "compression_16_intra")
