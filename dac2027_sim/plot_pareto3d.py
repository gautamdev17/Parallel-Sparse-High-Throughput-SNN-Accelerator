"""
plot_pareto3d.py -- latency, energy and throughput of all designs in one 3-D plot per network. Same synthetic sparse90
data as plot_pareto.py: latency and energy per image at batch 1 (results/system_breakdown_b1.json), throughput in
images/s at batch 16 (results/system_breakdown.json), as in the speed-up / throughput figure. All three are normalized
to PTB and plotted on log10 axes.

Each design is a marker on a stem down to the latency-energy floor, where its shadow is drawn. A design is
Pareto-optimal if no other design is at least as good on all three axes (lower latency, lower energy, higher
throughput) and better on one.

  python3 plot_pareto3d.py   -> results/pareto3d_energy_latency_throughput.png/.pdf
"""
import json, os
import numpy as np
import figstyle as FS
from plot_pareto import ORDER, NAME, MARK, NETS, R

plt = FS.plt


def dominated(p, q):
    """True if q dominates p: (latency, energy) lower or equal, throughput higher or equal, one strictly better."""
    ge = q[0] <= p[0] and q[1] <= p[1] and q[2] >= p[2]
    gt = q[0] < p[0] or q[1] < p[1] or q[2] > p[2]
    return ge and gt


# label placement where the default (above the marker) would collide
PLACE = {("VGG16", "spikex"): "below", ("ResNet18", "spikex"): "below", ("ResNet18", "sato"): "right",
         ("VGG16", "loas_zip"): "right", ("ResNet18", "loas_zip"): "right"}


def log_ticks(ax_set, lo, hi):
    """1-2-5 ticks on a log10 axis that is plotted linearly."""
    vals = [m * 10 ** e for e in range(int(np.floor(lo)), int(np.ceil(hi)) + 1) for m in (1, 2, 5)]
    vals = [v for v in vals if lo <= np.log10(v) <= hi]
    ax_set([np.log10(v) for v in vals], [f"{v:g}" for v in vals])


def main():
    b1 = json.load(open(os.path.join(R, "system_breakdown_b1.json")))
    b16 = json.load(open(os.path.join(R, "system_breakdown.json")))
    fig = plt.figure(figsize=(FS.TEXT, 3.0))
    for n, net in enumerate(NETS):
        ax = fig.add_subplot(1, 2, n + 1, projection="3d")
        pts = [(b1[f"{net}|{k}"]["t_s"] * 1e3, sum(b1[f"{net}|{k}"]["energy_J"].values()) * 1e6,
                1.0 / b16[f"{net}|{k}"]["t_s"]) for k in ORDER]
        front = [i for i, p in enumerate(pts) if not any(dominated(p, q) for q in pts)]
        L = np.log10(np.array(pts) / pts[ORDER.index("ptb")])     # normalized to PTB
        lo, hi = L.min(axis=0) - 0.15, L.max(axis=0) + 0.15
        # mark TIDES as the Pareto front
        x, y, z = L[ORDER.index("ours")]
        ax.text(x, y, z, "Pareto front      ", fontsize=7, style="italic", ha="right", va="center")
        for i, k in enumerate(ORDER):
            x, y, z = L[i]
            ours = k == "ours"
            ax.plot([x, x], [y, y], [lo[2], z], color="#7F7F7F", lw=0.7, ls=":")
            ax.scatter(x, y, lo[2], marker=MARK[k], s=18, color="#BFBFBF", edgecolors="none", depthshade=False)
            ax.scatter(x, y, z, marker=MARK[k], s=110 if ours else 34, color="#111111" if ours else "#FFFFFF",
                       edgecolors="#111111", linewidths=0.9, depthshade=False)
            pl = PLACE.get((net, k), "above")
            dz, ha, va, lab = {"above": (0.07, "center", "bottom", NAME[k]), "below": (-0.07, "center", "top", NAME[k]),
                               "right": (0.0, "left", "center", "   " + NAME[k])}[pl]
            ax.text(x, y, z + dz, lab, fontsize=6.5, fontweight="bold" if ours else "normal", ha=ha, va=va)
        log_ticks(lambda t, l: (ax.set_xticks(t), ax.set_xticklabels(l)), lo[0], hi[0])
        log_ticks(lambda t, l: (ax.set_yticks(t), ax.set_yticklabels(l)), lo[1], hi[1])
        log_ticks(lambda t, l: (ax.set_zticks(t), ax.set_zticklabels(l)), lo[2], hi[2])
        ax.set_xlim(lo[0], hi[0])
        ax.set_ylim(lo[1], hi[1])
        ax.set_zlim(lo[2], hi[2])
        ax.set_xlabel("Normalized latency", labelpad=-4, fontsize=7)
        ax.set_ylabel("Normalized energy", labelpad=-4, fontsize=7)
        ax.set_zlabel("Normalized throughput", labelpad=-4, fontsize=7)
        ax.tick_params(labelsize=6, pad=-2)
        for a in (ax.xaxis, ax.yaxis, ax.zaxis):
            a.pane.set_facecolor("#F7F7F7")
            a.pane.set_edgecolor("#999999")
            a._axinfo["grid"].update(color="#D0D0D0", linewidth=0.5, linestyle=":")
        ax.view_init(elev=22, azim=-58)
        ax.set_title(net, fontsize=8, fontweight="bold", pad=0)
        print(net, "Pareto-optimal:", [NAME[ORDER[i]] for i in front])
    fig.subplots_adjust(left=0.0, right=0.97, bottom=0.04, top=0.95, wspace=0.08)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"pareto3d_energy_latency_throughput.{ext}"), dpi=300)


if __name__ == "__main__":
    main()
