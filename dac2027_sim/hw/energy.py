"""
energy.py -- area, power, energy and EDP for LoAS, SpikeX, PTB, Ours.

Area and power come from the synthesized Nangate45 netlists (build/*_synth.log, build/*_power.rpt: OpenSTA
report_power with gate-level switching activity at 800 MHz, no clock tree, SRAMs excluded for every design).
LoAS = 16 x one TPPE. Latency = results/main_summary.json (sparse90 workload, T=8, 800 MHz).

  energy (batch 1)  = power x latency(batch 1)
  EDP               = energy x latency
  energy / image at batch 16 = power x cycles(b=16) / 16 / f
"""
import json, os, re
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import matplotlib.ticker
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
B = os.path.join(HERE, "build")
RES = os.path.join(os.path.dirname(HERE), "results")
F_HZ = 800e6
ORDER = ["loas_zip", "spikex", "ptb", "ours"]
NAME = {"loas_zip": "LoAS", "spikex": "SpikeX (8x8)", "ptb": "PTB (16x8)", "ours": "Ours (4x4, T=8)"}
HW = {"loas_zip": ("loas", 16), "spikex": ("spikex", 1), "ptb": ("ptb", 1), "ours": ("ours", 1)}
COL = {"loas_zip": "#2a78d6", "spikex": "#eb6834", "ptb": "#1baf7a", "ours": "#eda100"}
INK, INK2, GRID = "#0b0b0b", "#52514e", "#e4e3df"


def area_um2(name):
    return float(re.findall(r"Chip area for module '\\\S+': ([\d.]+)", open(os.path.join(B, f"{name}_synth.log")).read())[-1])


def power_w(name):
    txt = open(os.path.join(B, f"{name}_power.rpt")).read()
    tot = [l for l in txt.splitlines() if l.startswith("Total")][0].split()
    assert "unannotated     0" in txt or "unannotated 0" in " ".join(txt.split()), f"{name}: unannotated pins"
    return float(tot[4])


def main():
    lat = json.load(open(os.path.join(RES, "main_summary.json")))["sparse90"]
    rows = {}
    for d in ORDER:
        n, mult = HW[d]
        a, p = area_um2(n) * mult, power_w(n) * mult
        for net in ("VGG16", "ResNet18"):
            r = lat[f"{net}|{d}"]
            t1 = r["cycles_b1"] / F_HZ
            e = p * t1
            rows[net, d] = dict(area_mm2=a / 1e6, power_mw=p * 1e3, latency_ms=t1 * 1e3, energy_mj=e * 1e3,
                                edp_mj_ms=e * 1e3 * t1 * 1e3, energy_img_b16_mj=p * r["cycles_b16"] / 16 / F_HZ * 1e3)
    json.dump({f"{n}|{d}": v for (n, d), v in rows.items()}, open(os.path.join(RES, "energy_summary.json"), "w"), indent=1)
    lines = ["| Network | Design | Area (mm²) | Power (mW) | Latency b=1 (ms) | Energy b=1 (mJ) | EDP (mJ·ms) "
             "| Energy/img b=16 (mJ) | Ours lower energy by | Ours lower EDP by |", "|---|---|---:|---:|---:|---:|---:|---:|---:|---:|"]
    for net in ("VGG16", "ResNet18"):
        o = rows[net, "ours"]
        for d in ORDER:
            r = rows[net, d]
            lines.append(f"| {net} | {NAME[d]} | {r['area_mm2']:.3f} | {r['power_mw']:.1f} | {r['latency_ms']:.3f} | "
                         f"{r['energy_mj']:.4f} | {r['edp_mj_ms']:.5f} | {r['energy_img_b16_mj']:.4f} | "
                         f"{r['energy_mj'] / o['energy_mj']:.2f}x | {r['edp_mj_ms'] / o['edp_mj_ms']:.2f}x |")
    open(os.path.join(RES, "energy_tables.md"), "w").write("\n".join(lines) + "\n")
    print("\n".join(lines))
    plot(rows)


def plot(rows):
    plt.rcParams.update({"font.family": "serif", "font.size": 9, "axes.edgecolor": INK2, "axes.labelcolor": INK,
                         "xtick.color": INK2, "ytick.color": INK2, "axes.spines.top": False, "axes.spines.right": False})
    nets = ["VGG16", "ResNet18"]
    fig, axes = plt.subplots(1, 4, figsize=(10, 2.9))
    specs = [("power_mw", "Power (mW)", "{:.1f}", False, None), ("area_mm2", "Area (mm²)", "{:.3f}", False, None),
             ("energy_mj", "Energy, batch 1 (mJ, log)", "{:.3f}", True, nets),
             ("edp_mj_ms", "EDP (mJ·ms, log)", "{:.4f}", True, nets)]
    for ax, (key, ylab, fmt, log, groups) in zip(axes, specs):
        w = 0.18
        if groups is None:                         # power / area do not depend on the network
            x = np.arange(len(ORDER))
            v = [rows["VGG16", d][key] for d in ORDER]
            ax.bar(x, v, 0.6, color=[COL[d] for d in ORDER], zorder=3)
            for xi, vi in zip(x, v):
                ax.text(xi, vi * 1.02, fmt.format(vi), ha="center", va="bottom", fontsize=6.5, color=INK)
            ax.set_xticks(x, [NAME[d].split(" (")[0] for d in ORDER], fontsize=7)
            ax.set_ylim(top=max(v) * 1.18)
        else:
            for i, d in enumerate(ORDER):
                x = np.arange(len(groups)) + (i - 1.5) * (w + 0.012)
                v = [rows[n, d][key] for n in groups]
                ax.bar(x, v, w, color=COL[d], label=NAME[d], zorder=3)
                for xi, vi in zip(x, v):
                    ax.text(xi, vi * 1.08, fmt.format(vi), ha="center", va="bottom", fontsize=5.5, color=INK, rotation=90)
            ax.set_yscale("log")
            ax.set_xticks(range(len(groups)), groups)
            ax.set_ylim(top=ax.get_ylim()[1] * 6)
            ax.yaxis.set_major_formatter(matplotlib.ticker.FuncFormatter(lambda v, _: f"{v:g}"))
        ax.set_ylabel(ylab)
        ax.yaxis.grid(True, color=GRID, lw=0.6, zorder=0)
    h, l = axes[2].get_legend_handles_labels()
    fig.legend(h, l, fontsize=7, frameon=False, loc="lower center", ncol=4)
    fig.suptitle("Nangate45, 800 MHz, gate-level switching activity, SRAM excluded; "
                 "weights and activations 90% sparse, T=8, INT8", fontsize=8, color=INK2)
    fig.tight_layout(rect=(0, 0.07, 1, 1))
    fig.savefig(os.path.join(RES, "power_area_energy_edp.png"), dpi=300)


if __name__ == "__main__":
    main()
