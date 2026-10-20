"""plot_real.py -- speedup (batch-1 latency) and throughput (batch 16) over PTB on real VGG-16 CIFAR-10 traces, PTB
greyscale style.
  plot_real.py                          NeuroFlex INT8 PASCAL, T = 8 (results/real_vgg16_cycles.json)
                                        -> results/real_vgg16_speedup.png/.pdf
  plot_real.py qcfs_vgg16_cifar10_T16   the lab's pruned QCFS VGG-16, INT8, T = 16 (results/<tag>_cycles.json,
                                        <tag>_acc.json) -> results/<tag>_speedup.png/.pdf"""
import json, os, sys
import numpy as np
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
R = os.path.join(os.path.dirname(HERE), "results")
ORDER = ["ptb", "spikex", "loas", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "loas": "LoAS", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "TIDES"}


def main(tag=None):
    import plot_ptb_style as PS
    plt, FS = PS.plt, PS.FS
    if tag is None:
        c = json.load(open(os.path.join(R, "real_vgg16_cycles.json")))
        a = json.load(open(os.path.join(R, "real_vgg16_cifar10_acc.json")))
        title = f"VGG-16, CIFAR-10 (NeuroFlex INT8 PASCAL SNN, T = 8, accuracy {a['accuracy']:.2f}%): real traces"
        out = "real_vgg16_speedup"
    else:
        c = json.load(open(os.path.join(R, f"{tag}_cycles.json")))
        fa = os.path.join(R, f"{tag}_acc.json")
        meta = json.load(open(os.path.join(R, f"{tag}_meta.json")))
        T_ = meta["T"]
        acc = f"accuracy {json.load(open(fa))['accuracy']:.2f}%" if os.path.exists(fa) else "accuracy not yet measured"
        title = meta.get("title") or f"VGG-16, CIFAR-10 (pruned QCFS SNN, INT8 weights, T = {T_}, {acc}): real traces"
        out = f"{tag}_speedup"
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.1))
    for ax, b, tag, ylab in ((axes[0], "1", "(a) Latency (batch 1)", "Speedup"),
                             (axes[1], "16", "(b) Throughput (batch 16)", "Throughput")):
        v = [c[b]["ptb"] / c[b][d] for d in ORDER]
        x = np.arange(len(ORDER))
        cols = ["#111111" if d != "ours" else "#FFFFFF" for d in ORDER]
        ax.bar(x, v, 0.55, color=cols, hatch=["" if d != "ours" else "////" for d in ORDER], edgecolor="#111111",
               linewidth=0.6, zorder=3)
        for xi, vi in zip(x, v):
            ax.annotate(f"{vi:.2f}×", (xi, vi), xytext=(0, 2), textcoords="offset points", ha="center", va="bottom",
                        fontsize=6.4, fontweight="bold")
        ax.axhline(1.0, color="#111111", lw=0.6, ls=(0, (4, 2)), zorder=4)
        ax.set_xticks(x, [NAME[d] for d in ORDER], rotation=40, ha="right", fontsize=6.8, fontweight="bold")
        ax.set_ylim(0, max(v) * 1.18)
        ax.set_ylabel(ylab, fontweight="bold")
        ax.yaxis.grid(True, ls=":", lw=0.6, color="#777777", zorder=0)
        ax.xaxis.grid(False)
        FS.panel_tag(ax, tag, y=-0.42)
    fig.suptitle(title, fontsize=7.5, y=0.995)
    fig.subplots_adjust(left=0.07, right=0.99, top=0.9, bottom=0.33, wspace=0.22)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"{out}.{ext}"))


if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else None)
