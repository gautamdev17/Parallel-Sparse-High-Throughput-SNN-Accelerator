"""plots.py -- figures from results/*.json (run run_all.py main and sweep first)."""
import json, os
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import matplotlib.ticker
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
# fixed categorical order (reference palette slots 1-5); identity also carried by legend + direct labels
ORDER = ["loas_zip", "spikex", "ptb", "sato", "spikeflow", "prosperity", "ours"]
COL = {"loas_zip": "#2a78d6", "spikex": "#eb6834", "ptb": "#1baf7a", "ours": "#eda100", "prosperity": "#e87ba4",
       "sato": "#008300", "spikeflow": "#6250d6"}
LAB = {"loas_zip": "LoAS", "spikex": "SpikeX (8x8)", "ptb": "PTB (16x8, Prosperity-repo model)", "sato": "SATO (128 PE)",
       "spikeflow": "SpikeFlow (16x16)", "prosperity": "Prosperity (official sim)", "ours": "Ours (4x4 PE, T=8)"}
INK, INK2, GRID = "#0b0b0b", "#52514e", "#e4e3df"
plt.rcParams.update({"font.family": "serif", "font.size": 9, "axes.edgecolor": INK2, "axes.labelcolor": INK,
                     "xtick.color": INK2, "ytick.color": INK2, "axes.spines.top": False, "axes.spines.right": False})


def bars():
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    nets, ds = ["VGG16", "ResNet18"], ORDER
    fig, axes = plt.subplots(1, 2, figsize=(7.2, 3.3))
    for ax, (key, ylab, fmt) in zip(axes, [("latency_ms", "Latency, batch 1 (ms)", "{:.2f}"),
                                           ("throughput", "Throughput, batch 16 (img/s)", "{:,.0f}")]):
        w = 0.11
        for i, d in enumerate(ds):
            x = np.arange(len(nets)) + (i - (len(ds) - 1) / 2) * (w + 0.012)
            v = [s[f"{n}|{d}"][key] for n in nets]
            ax.bar(x, v, w, color=COL[d], label=LAB[d], zorder=3)
            for xi, vi in zip(x, v):
                ax.text(xi, vi, fmt.format(vi), ha="center", va="bottom", fontsize=5.5, color=INK, rotation=90)
        ax.set_xticks(range(len(nets)), nets)
        ax.set_ylabel(ylab)
        ax.yaxis.grid(True, color=GRID, lw=0.6, zorder=0)
        ax.set_ylim(0, ax.get_ylim()[1] * 1.15)
    h, l = axes[0].get_legend_handles_labels()
    fig.legend(h, l, fontsize=6.5, frameon=False, loc="lower center", ncol=4)
    fig.suptitle("Weights & activations 90% sparse, INT8, T=8, 800 MHz; 128 adders (SpikeX 64, SpikeFlow 256)",
                 fontsize=8, color=INK2)
    fig.tight_layout(rect=(0, 0.11, 1, 1))
    fig.savefig(os.path.join(R, "latency_throughput_sparse90.png"), dpi=300)


def bars_normalized():
    """same data as bars(), normalized to LoAS = 1x: speed-up = LoAS latency / latency, throughput / LoAS."""
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    nets, ds = ["VGG16", "ResNet18"], ORDER
    fig, axes = plt.subplots(1, 2, figsize=(7.2, 3.3))
    specs = [(lambda n, d: s[f"{n}|loas_zip"]["latency_ms"] / s[f"{n}|{d}"]["latency_ms"],
              "Speed-up over LoAS, batch 1 (x)"),
             (lambda n, d: s[f"{n}|{d}"]["throughput"] / s[f"{n}|loas_zip"]["throughput"],
              "Throughput over LoAS, batch 16 (x)")]
    for ax, (f, ylab) in zip(axes, specs):
        w = 0.11
        for i, d in enumerate(ds):
            x = np.arange(len(nets)) + (i - (len(ds) - 1) / 2) * (w + 0.012)
            v = [f(n, d) for n in nets]
            ax.bar(x, v, w, color=COL[d], label=LAB[d], zorder=3)
            for xi, vi in zip(x, v):
                ax.text(xi, vi, f"{vi:.1f}x", ha="center", va="bottom", fontsize=5.5, color=INK, rotation=90)
        ax.axhline(1, color=INK2, lw=0.8, ls="--", zorder=2)
        ax.set_xticks(range(len(nets)), nets)
        ax.set_ylabel(ylab)
        ax.yaxis.grid(True, color=GRID, lw=0.6, zorder=0)
        ax.set_ylim(0, ax.get_ylim()[1] * 1.15)
    h, l = axes[0].get_legend_handles_labels()
    fig.legend(h, l, fontsize=6.5, frameon=False, loc="lower center", ncol=4)
    fig.suptitle("Normalized to LoAS = 1x. Weights & activations 90% sparse, INT8, T=8, 800 MHz",
                 fontsize=8, color=INK2)
    fig.tight_layout(rect=(0, 0.11, 1, 1))
    fig.savefig(os.path.join(R, "latency_throughput_normalized.png"), dpi=300)


def sweep():
    s = json.load(open(os.path.join(R, "sweep_summary.json")))
    wds = sorted({float(k[2:]) for k in s}, reverse=True)
    ds = [d for d in ORDER if f"VGG16|{d}" in s[f"wd{wds[0]}"]]
    fig, axes = plt.subplots(1, 2, figsize=(7.2, 2.7))
    for ax, net in zip(axes, ["VGG16", "ResNet18"]):
        for d in ds:
            y = [s[f"wd{w}"][f"{net}|{d}"]["latency_ms"] for w in wds]
            ax.plot([1 - w for w in wds], y, color=COL[d], lw=2, marker="o", ms=4, label=LAB[d])
            dy = {"loas_zip": 5, "spikex": -5}.get(d, 0)
            ax.annotate(LAB[d].split(" (")[0], ((1 - wds[-1]), y[-1]), xytext=(4, dy), textcoords="offset points",
                        fontsize=6.5, color=INK, va="center")
        ax.set_yscale("log")
        ax.set_xlabel("Weight sparsity")
        ax.yaxis.set_major_formatter(matplotlib.ticker.FuncFormatter(lambda v, _: f"{v:g}"))
        ax.yaxis.set_minor_formatter(matplotlib.ticker.NullFormatter())
        ax.set_title(net, fontsize=9, color=INK)
        ax.grid(True, color=GRID, lw=0.6)
        ax.set_xlim(-0.03, 1.12)
    axes[0].set_ylabel("Latency, batch 1 (ms, log)")
    h, l = axes[0].get_legend_handles_labels()
    fig.legend(h, l, fontsize=7, frameon=False, loc="lower center", ncol=4)
    fig.suptitle("Batch-1 latency vs weight sparsity (activations 90% non-silent-sparse, INT8, T=8, 800 MHz)",
                 fontsize=8, color=INK2)
    fig.tight_layout(rect=(0, 0.08, 1, 1))
    fig.savefig(os.path.join(R, "weight_sparsity_sweep.png"), dpi=300)


if __name__ == "__main__":
    bars()
    bars_normalized()
    sweep()
