"""
plot_vgg16_chain.py -- VGG-16, CIFAR-10, IF neuron, T = 8, the snn-pruning-DAC models (dense / 90 / 95 / 98 % global
weight sparsity; per-layer W, A, C of eval.json), one test image chained through the network (prune_chain.py),
batch 1: speed-up, energy and EDP of every design normalized to PTB, at the official 1024-bit DRAM interface
(64 GB/s at 500 MHz) and with latency bounded by 256 / 128 bits per cycle (prune_chain.py PC_BW).

  python3 plot_vgg16_chain.py   -> results/vgg16_if_T8_{speedup,energy,edp}.png/.pdf, results/vgg16_if_T8.md
"""
import json, os
import figstyle as FS
from plot_prune_sweep import ORDER as _ORDER, NAME as _NAME, MARK as _MARK, GREY as _GREY

# Prosperity twice: the official simulator, and its paper's per-tile pipeline (prosperity_paper.py)
ORDER = _ORDER[:-1] + ["pros_paper", "ours"]
NAME = dict(_NAME, prosperity="Prosperity (official sim.)", pros_paper="Prosperity (paper pipeline)")
MARK = dict(_MARK, pros_paper="o")
GREY = dict(_GREY, pros_paper="#3A3A3A")

plt = FS.plt
HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
CLK = 500e6
BWS = (("prune_chain.json", "64 GB/s (1024 b/cycle, official)"), ("prune_chain_bw256.json", "16 GB/s (256 b/cycle)"),
       ("prune_chain_bw128.json", "8 GB/s (128 b/cycle)"))
LAB = {"dense": "dense", "sp90": "90", "sp95": "95", "sp98": "98"}
METRICS = (("speedup", "Speedup over PTB", "higher is better"),
           ("energy", "Energy (PTB = 1)", "lower is better"),
           ("edp", "EDP (PTB = 1)", "lower is better"))


def values(e):
    cyc = dict(e["cycles_b1"], pros_paper=e["cycles_b1_prosperity_paper"])
    ej = dict(e["energy_J"], pros_paper=e["energy_J_prosperity_paper"])
    lat = {k: cyc[k] / CLK for k in ORDER}
    E = {k: sum(ej[k].values()) for k in ORDER}
    return dict(speedup={k: lat["ptb"] / lat[k] for k in ORDER}, energy={k: E[k] / E["ptb"] for k in ORDER},
                edp={k: E[k] * lat[k] / (E["ptb"] * lat["ptb"]) for k in ORDER})


def main():
    data = [(t, json.load(open(os.path.join(R, f)))["VGG16"]["levels"]) for f, t in BWS]
    for key, ylabel, note in METRICS:
        fig, axes = plt.subplots(1, len(data), figsize=(FS.TEXT, 2.3), sharey=True)
        for ax, (title, lv) in zip(axes, data):
            xs = range(len(lv))
            for k in ORDER:
                ys = [values(e)[key][k] for e in lv]
                o = k == "ours"
                ax.plot(xs, ys, marker=MARK[k], ms=6 if o else 3.5, lw=1.7 if o else 0.8, color=GREY[k],
                        mfc=GREY[k] if (o or k == "pros_paper") else "white", mec=GREY[k], label=NAME[k],
                        ls="--" if k == "pros_paper" else "-", zorder=5 if o else 3)
            ax.set_yscale("log")
            ax.set_xticks(list(xs), [f"{LAB[e['level']]}\n{e['acc']:.2f}" for e in lv], fontsize=6)
            ax.set_title(f"DRAM {title}", fontsize=7)
            ax.set_xlabel("Weight sparsity %\nIF T = 8 accuracy %", fontsize=6.5)
            ax.grid(True, which="major", ls=":", lw=0.5, color="#999999")
        axes[0].set_ylabel(f"{ylabel} ({note})", fontsize=7)
        h, l = axes[0].get_legend_handles_labels()
        fig.legend(h, l, loc="upper center", ncol=4, frameon=False, fontsize=6.5, bbox_to_anchor=(0.5, 1.13))
        fig.tight_layout(rect=(0, 0, 1, 0.92), w_pad=0.6)
        for ext in ("png", "pdf"):
            fig.savefig(os.path.join(R, f"vgg16_if_T8_{key}.{ext}"), dpi=300, bbox_inches="tight")
        plt.close(fig)
    lines = ["# VGG-16, CIFAR-10, IF T = 8, snn-pruning-DAC models, batch 1 (plot_vgg16_chain.py)", "",
             "Same chained traces for every design (prune_chain.py; per-layer W exact, A within 0.07 pts, C within "
             "0.3 pts on the heavy layers of eval.json). TIDES cycles RTL-exact (rtl_t4.py, RT_T=8). Energy = core + "
             "SRAM + DRAM (45 nm, 500 MHz). Speed-up: higher is better; energy and EDP normalized to PTB: lower is better. "
             "Prosperity is given twice: its official simulator, and the per-tile pipeline of its paper (Sec. VI: "
             "ProSparsity phase m + 4 cycles, computation >= m + 4 cycles per tile of m rows; prosperity_paper.py), "
             "with the same memory traffic and power.",
             ""]
    for title, lv in data:
        for key, ylabel, note in METRICS:
            lines += [f"## {ylabel}, DRAM {title}", "", "| Level | Acc % | " + " | ".join(NAME[k] for k in ORDER)
                      + " | Best |", "|---|---:|" + "---:|" * len(ORDER) + "---|"]
            for e in lv:
                v = values(e)[key]
                best = (max if key == "speedup" else min)([k for k in ORDER if k != "prosperity"], key=lambda k: v[k])
                lines.append(f"| {LAB[e['level']]} | {e['acc']:.2f} | "
                             + " | ".join((f"**{v[k]:.3f}**" if k == best else f"{v[k]:.3f}") for k in ORDER)
                             + f" | {NAME[best]} |")
            lines.append("")
    open(os.path.join(R, "vgg16_if_T8.md"), "w").write("\n".join(lines) + "\n")


if __name__ == "__main__":
    main()
