"""plot_v1_normalized.py -- v1 (equal adders) latency and throughput normalized to LoAS = 1, in the style of
SATO's Fig. 7: grouped bars per network, design names under each bar, network name under each group, boxed axes.
Reads results/main_summary.json (sparse90). Writes results/v1_normalized.png (+ .pdf)."""
import json, os
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
ORDER = ["loas_zip", "spikex", "ptb", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"loas_zip": "LoAS", "spikex": "SpikeX", "ptb": "PTB", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "Ours"}
COL = {"loas_zip": "#2a78d6", "spikex": "#eb6834", "ptb": "#1baf7a", "sato": "#008300", "spikeflow": "#6250d6",
       "prosperity": "#e87ba4", "ours": "#eda100"}
HATCH = {"loas_zip": "////", "spikex": "\\\\\\\\", "ptb": "xxxx", "sato": "....", "spikeflow": "----",
         "prosperity": "||||", "ours": ""}
NETS = ["VGG16", "ResNet18"]
INK = "#0b0b0b"

plt.rcParams.update({"font.family": "serif", "font.serif": ["Times New Roman", "Times", "DejaVu Serif"],
                     "font.size": 9, "hatch.linewidth": 0.5, "axes.linewidth": 0.9})


LOAS_OWN = "--loas-own" in __import__("sys").argv     # LoAS from loas_model.py instead of the zip formula


def main():
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    if LOAS_OWN:
        own = json.load(open(os.path.join(R, "loas_own.json")))
        for net in NETS:
            s[f"{net}|loas_zip"] = dict(s[f"{net}|loas_zip"], latency_ms=own[f"sparse90|{net}|1"] / 800e6 * 1e3,
                                        throughput=16 * 800e6 / own[f"sparse90|{net}|16"])
        rows = ["| Network | Design | Latency (ms) | Normalized latency | Throughput (img/s) | Normalized throughput |",
                "|---|---|---:|---:|---:|---:|"]
        for net in NETS:
            b = s[f"{net}|loas_zip"]
            for d in ORDER:
                r = s[f"{net}|{d}"]
                rows.append(f"| {net} | {NAME[d]} | {r['latency_ms']:.3f} | {r['latency_ms'] / b['latency_ms']:.3f} | "
                            f"{r['throughput']:,.0f} | {r['throughput'] / b['throughput']:.2f} |")
        open(os.path.join(R, "v1_loas_own_tables.md"), "w").write("\n".join(rows) + "\n")
        print("\n".join(rows))
    fig, axes = plt.subplots(1, 2, figsize=(7.2, 2.9))
    specs = [("latency_ms", lambda v, b: v / b, "Normalized latency", "(a) Latency"),
             ("throughput", lambda v, b: v / b, "Normalized throughput",
              "(b) Throughput")]
    nd = len(ORDER)
    gap = 1.2
    for ax, (key, f, ylab, title) in zip(axes, specs):
        xt, xl = [], []
        for g, net in enumerate(NETS):
            base = s[f"{net}|loas_zip"][key]
            x0 = g * (nd + gap)
            for i, d in enumerate(ORDER):
                v = f(s[f"{net}|{d}"][key], base)
                x = x0 + i
                ax.bar(x, v, 0.78, color=COL[d], edgecolor="black", linewidth=0.6, hatch=HATCH[d], zorder=3,
                       label=NAME[d] if g == 0 else None)
                txt = f"{v:.2f}" if v < 10 else f"{v:.1f}"
                ax.text(x, v, txt, ha="center", va="bottom", fontsize=5.6, color=INK, rotation=90,
                        fontweight="bold" if d == "ours" else "normal")
                xt.append(x)
                xl.append(NAME[d])
            # network label under the group, with a bracket line like SATO Fig. 7
            ax.annotate(net, xy=(x0 + (nd - 1) / 2, 0), xycoords=("data", "axes fraction"),
                        xytext=(0, -46), textcoords="offset points", ha="center", va="top", fontsize=8.5)
        ax.set_xticks(xt, xl, rotation=90, fontsize=7)
        ax.tick_params(axis="x", length=0, pad=3)
        ax.tick_params(axis="y", direction="in", labelsize=7.5, right=True)
        for sp in ax.spines.values():
            sp.set_visible(True)
        top = ax.get_ylim()[1] * 1.12
        ax.set_ylim(0, top)
        ax.set_xlim(-0.8, (nd + gap) * len(NETS) - gap - 0.2)
        # separator between the two network groups
        ax.axvline(nd - 1 + (gap + 1) / 2, color="black", lw=0.6, zorder=2)
        ax.axhline(1, color="black", lw=0.7, ls="--", zorder=4)
        ax.yaxis.grid(True, color="#d9d9d9", lw=0.5, zorder=0)
        ax.set_ylabel(ylab, fontsize=8)
        ax.set_title(title, fontsize=9, fontweight="bold", y=-0.52)
    fig.subplots_adjust(left=0.085, right=0.99, top=0.97, bottom=0.36, wspace=0.28)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"v1_normalized{'_loas_own' if LOAS_OWN else ''}.{ext}"), dpi=300)


if __name__ == "__main__":
    main()
