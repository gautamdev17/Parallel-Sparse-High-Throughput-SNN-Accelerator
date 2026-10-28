"""
plot_pareto.py -- energy vs latency Pareto plot of all designs, from the same data as the power / energy / EDP plots
of DAC2027_all_plots.pdf: results/system_breakdown_b1.json (system_breakdown.py with SNB=1: synthetic sparse90,
45 nm, 500 MHz, batch 1; energy = core + SRAM + DRAM per image, latency = time per image), both normalized to PTB.

A design is Pareto-optimal if no other design has both lower latency and lower energy; the staircase joins them.

  python3 plot_pareto.py   -> results/pareto_energy_latency.png/.pdf
"""
import json, os
import numpy as np
import figstyle as FS
from matplotlib import ticker

plt = FS.plt
HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
ORDER = ["ptb", "spikex", "loas_zip", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "loas_zip": "LoAS", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "TIDES"}
MARK = {"ptb": "s", "spikex": "D", "loas_zip": "^", "sato": "v", "spikeflow": "P", "prosperity": "o", "ours": "*"}
NETS = ["VGG16", "ResNet18"]
# label offsets (points) where the default (right of the marker) would collide
LABEL = {("VGG16", "spikeflow"): (-7, -9, "right"), ("VGG16", "sato"): (0, -15, "center"),
         ("ResNet18", "spikex"): (-7, -9, "right"), ("ResNet18", "spikeflow"): (-7, 4, "right")}


def pareto(pts):
    """indices of non-dominated points (lower latency and lower energy are better), sorted by latency."""
    idx = sorted(range(len(pts)), key=lambda i: (pts[i][0], pts[i][1]))
    front, best = [], float("inf")
    for i in idx:
        if pts[i][1] < best:
            front.append(i)
            best = pts[i][1]
    return front


def main():
    d = json.load(open(os.path.join(R, "system_breakdown_b1.json")))
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.35))
    for ax, net in zip(axes, NETS):
        pts = [(d[f"{net}|{k}"]["t_s"] * 1e3, sum(d[f"{net}|{k}"]["energy_J"].values()) * 1e6) for k in ORDER]
        base = pts[ORDER.index("ptb")]
        pts = [(x / base[0], y / base[1]) for x, y in pts]     # normalized to PTB
        front = pareto(pts)
        fx = [pts[i][0] for i in front]
        fy = [pts[i][1] for i in front]
        # staircase through the front, extended to the plot edges
        sx, sy = [fx[0]], [max(p[1] for p in pts) * 1.6]
        for i in range(len(fx)):
            sx += [fx[i], fx[i]]
            sy += [sy[-1], fy[i]]
            if i + 1 < len(fx):
                sx.append(fx[i + 1])
                sy.append(fy[i])
        sx.append(max(p[0] for p in pts) * 1.6)
        sy.append(fy[-1])
        ax.plot(sx[1:], sy[1:], color="#111111", lw=1.0, ls=(0, (4, 2)), zorder=2)
        # label under the first horizontal step of the front
        ax.text(np.sqrt(fx[0] * fx[1]) if len(fx) > 1 else fx[0] * 2, fy[0] / 1.07, "Pareto front", fontsize=7,
                style="italic", ha="center", va="top", zorder=5)
        ax.fill_between(sx[1:], sy[1:], max(p[1] for p in pts) * 1.6, step=None, color="#E6E6E6", zorder=1,
                        alpha=0.6)
        for k, (x, y) in zip(ORDER, pts):
            ours = k == "ours"
            ax.scatter(x, y, s=150 if ours else 42, marker=MARK[k], color="#111111" if ours else "#FFFFFF",
                       edgecolors="#111111", linewidths=0.9, zorder=4)
            dx, dy, ha = LABEL.get((net, k), (7, 3, "left"))
            ax.annotate(NAME[k], (x, y), xytext=(dx, dy), textcoords="offset points", fontsize=7,
                        fontweight="bold" if ours else "normal", ha=ha, zorder=5)
        ax.set_xscale("log")
        ax.set_yscale("log")
        ax.set_xlim(min(p[0] for p in pts) / 1.5, max(p[0] for p in pts) * 1.6)
        ax.set_ylim(min(p[1] for p in pts) / 1.5, max(p[1] for p in pts) * 1.6)
        for a in (ax.xaxis, ax.yaxis):
            a.set_major_locator(ticker.LogLocator(subs=(1, 2, 5)))
            a.set_major_formatter(ticker.FuncFormatter(lambda v, _: f"{v:g}"))
            a.set_minor_formatter(ticker.NullFormatter())
        ax.set_xlabel("Normalized latency")
        ax.set_ylabel("Normalized energy")
        ax.grid(True, which="major", ls=":", lw=0.6, color="#999999", zorder=0)
        ax.set_title(net, fontsize=8, fontweight="bold")
        print(net, "Pareto-optimal:", [NAME[ORDER[i]] for i in front])
    fig.tight_layout(w_pad=1.6)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"pareto_energy_latency.{ext}"), dpi=300)


if __name__ == "__main__":
    main()
