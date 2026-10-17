"""plot_ptb_style.py -- normalized latency / throughput figures in the style of the PTB paper (Fig. 11):
grouped bars per network, grey-scale fills with hatching, ours in blue, boxed legend, heavy frame, inward ticks.

  python3 plot_ptb_style.py v1   -> results/v1_ptbstyle.png/.pdf      (equal adders; LoAS from loas_model.py)
  python3 plot_ptb_style.py v4   -> results/v4_ptbstyle.png/.pdf + results/v4_tables.md  (16 PEs in every design)
"""
import json, os, sys
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
F_HZ = 800e6
NETS = ["VGG16", "ResNet18"]
ORDER = ["loas_zip", "spikex", "ptb", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"loas_zip": "LoAS", "spikex": "SpikeX", "ptb": "PTB", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "Ours"}
# grey-scale + hatching like PTB's figures; ours is the single coloured series
STYLE = {"loas_zip": dict(color="#000000", hatch=""),
         "spikex": dict(color="#7f7f7f", hatch=""),
         "ptb": dict(color="#ffffff", hatch=""),
         "sato": dict(color="#c8c8c8", hatch="////"),
         "spikeflow": dict(color="#ffffff", hatch="\\\\\\\\"),
         "prosperity": dict(color="#9a9a9a", hatch="xxx"),
         "ours": dict(color="#1d3fd6", hatch="")}

plt.rcParams.update({
    "font.family": "serif", "font.serif": ["Times New Roman", "Times", "DejaVu Serif"],
    "font.weight": "bold", "axes.labelweight": "bold", "axes.titleweight": "bold",
    "font.size": 11, "axes.linewidth": 1.4, "hatch.linewidth": 0.7,
    "xtick.direction": "in", "ytick.direction": "in", "xtick.major.width": 1.2, "ytick.major.width": 1.2,
    "xtick.major.size": 4, "ytick.major.size": 4, "xtick.top": True, "ytick.right": True,
    "legend.frameon": True, "legend.edgecolor": "black", "legend.fancybox": False, "legend.framealpha": 1.0,
})


def draw(norm, out, note=""):
    """norm[net][design] = (normalized latency, normalized throughput), LoAS = 1."""
    fig, axes = plt.subplots(1, 2, figsize=(10.5, 3.9))
    w = 0.11
    for ax, idx, ylab, tag in ((axes[0], 0, "Normalized Latency", "(a)"),
                               (axes[1], 1, "Normalized Throughput", "(b)")):
        for i, d in enumerate(ORDER):
            x = np.arange(len(NETS)) + (i - (len(ORDER) - 1) / 2) * w
            v = [norm[n][d][idx] for n in NETS]
            ax.bar(x, v, w, color=STYLE[d]["color"], hatch=STYLE[d]["hatch"], edgecolor="black", linewidth=0.9,
                   label=NAME[d], zorder=3)
        ax.set_xticks(range(len(NETS)), NETS, fontsize=13)
        ax.set_xlim(-0.6, len(NETS) - 0.4)
        ax.set_ylabel(ylab, fontsize=14)
        ax.yaxis.grid(True, ls=(0, (3, 3)), color="#9e9e9e", lw=0.6, zorder=0)
        top = max(norm[n][d][idx] for n in NETS for d in ORDER)
        ax.set_ylim(0, top * 1.45)
        ax.legend(ncol=4, fontsize=9.5, loc="upper center", handlelength=1.6, columnspacing=0.9,
                  borderpad=0.4, labelspacing=0.3)
        ax.text(0.5, -0.2, tag, transform=ax.transAxes, ha="center", va="top", fontsize=14, fontweight="normal")
        for lab in ax.get_yticklabels():
            lab.set_fontweight("bold")
    if note:
        fig.suptitle(note, fontsize=12)
    fig.subplots_adjust(left=0.07, right=0.99, top=0.9 if note else 0.97, bottom=0.2, wspace=0.22)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"{out}.{ext}"), dpi=300)


def v1():
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    own = json.load(open(os.path.join(R, "loas_own.json")))
    norm = {}
    for n in NETS:
        l0 = own[f"sparse90|{n}|1"] / F_HZ * 1e3
        t0 = 16 * F_HZ / own[f"sparse90|{n}|16"]
        norm[n] = {}
        for d in ORDER:
            lat = l0 if d == "loas_zip" else s[f"{n}|{d}"]["latency_ms"]
            thr = t0 if d == "loas_zip" else s[f"{n}|{d}"]["throughput"]
            norm[n][d] = (lat / l0, thr / t0)
    draw(norm, "v1_ptbstyle")


def v4():
    """16 PEs in every design (v3 totals) with LoAS from loas_model.py (16 TPPEs)."""
    tot = json.load(open(os.path.join(R, "v3_iso16_totals.json")))
    own = json.load(open(os.path.join(R, "loas_own.json")))
    norm, rows = {}, ["| Network | Design | Latency (ms) | Normalized latency | Throughput (img/s) | Normalized throughput |",
                      "|---|---|---:|---:|---:|---:|"]
    for n in NETS:
        c1 = {d: tot[f"sparse90|{n}|1|{d}"] for d in ORDER}
        c16 = {d: tot[f"sparse90|{n}|16|{d}"] for d in ORDER}
        c1["loas_zip"], c16["loas_zip"] = own[f"sparse90|{n}|1"], own[f"sparse90|{n}|16"]
        l0, t0 = c1["loas_zip"] / F_HZ * 1e3, 16 * F_HZ / c16["loas_zip"]
        norm[n] = {}
        for d in ORDER:
            lat, thr = c1[d] / F_HZ * 1e3, 16 * F_HZ / c16[d]
            norm[n][d] = (lat / l0, thr / t0)
            rows.append(f"| {n} | {NAME[d]} | {lat:.3f} | {lat / l0:.3f} | {thr:,.0f} | {thr / t0:.2f} |")
    open(os.path.join(R, "v4_tables.md"), "w").write(
        "### v4: 16 PEs in every design, LoAS from loas_model.py, workload sparse90 (T=8, 800 MHz)\n\n"
        + "\n".join(rows) + "\n\nOurs and LoAS PEs have 8 adders each (one per timestep); the other designs' PEs have 1.\n")
    print("\n".join(rows))
    draw(norm, "v4_ptbstyle")


if __name__ == "__main__":
    {"v1": v1, "v4": v4}[sys.argv[1]]()
