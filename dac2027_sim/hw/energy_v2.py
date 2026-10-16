"""
energy_v2.py -- area, power, energy (= power x latency) and EDP (= energy x latency) for all seven designs.

Power / area: our RTL of each design, Yosys + Nangate45, OpenSTA report_power with gate-level switching activity
(VCD of the netlist running cycle-model stimulus) at 800 MHz; SRAM buffers outside the cores are excluded for every
design (SpikeFlow's 18.5 KB on-chip memory is included, as in its paper's synthesis). LoAS = 16 x the given TPPE RTL.
Latency: results/main_v2_summary.json (version 2, DRAM included), workload sparse90.
Paper reference numbers are listed next to ours (28 nm numbers scaled to 45 nm by area x (45/28)^2 and
power x (45/28) x (1.1/0.9)^2, a first-order scaling; Nangate45 at 1.1 V vs 28 nm at 0.9 V).
"""
import json, os, re
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
B = os.path.join(HERE, "build")
RES = os.path.join(os.path.dirname(HERE), "results")
F_HZ = 800e6
ORDER = ["loas_zip", "spikex", "ptb", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"loas_zip": "LoAS (16 TPPE)", "spikex": "SpikeX (8x8)", "ptb": "PTB (16x8)", "sato": "SATO (128 PE)",
        "spikeflow": "SpikeFlow (16x16)", "prosperity": "Prosperity", "ours": "Ours (4x4)"}
HW = {"loas_zip": ("loas", 16), "spikex": ("spikex", 1), "ptb": ("ptb", 1), "sato": ("sato", 1),
      "spikeflow": ("spikeflow", 1), "prosperity": ("prosperity", 1), "ours": ("ours", 1)}
COL = {"loas_zip": "#2a78d6", "spikex": "#eb6834", "ptb": "#1baf7a", "ours": "#eda100", "prosperity": "#e87ba4",
       "sato": "#008300", "spikeflow": "#6250d6"}
INK, INK2, GRID = "#0b0b0b", "#52514e", "#e4e3df"
A28, P28 = (45 / 28) ** 2, (45 / 28) * (1.1 / 0.9) ** 2
PAPER = {  # (what, area mm^2, power mW, clock MHz, node)
    "loas_zip": ("TPPE x 16 (zip synthesis)", 16 * 0.032841, 16 * 4.965, 560, "zip"),
    "sato": ("Core = PE array + adder-search tree (Sec. 4.1)", 0.0203, 47.73, 200, "28nm"),
    "spikeflow": ("whole design incl. 18.5 KB memory (Table 3)", 1.1946, 127.2, 100, "45nm"),
    "prosperity": ("PPU logic: detector+pruner+dispatcher+processor+other (Fig. 10)", 0.225, 367.1, 500, "28nm"),
}


def area_mm2(n):
    t = open(os.path.join(B, f"{n}_synth.log")).read()
    return float(re.findall(r"Chip area for module '\\\S+': ([\d.]+)", t)[-1]) / 1e6


def power_w(n):
    t = open(os.path.join(B, f"{n}_power.rpt")).read()
    if "unannotated     0" not in t and "unannotated 0" not in " ".join(t.split()):
        print(f"warning: {n} has unannotated pins")
    return float([l for l in t.splitlines() if l.startswith("Total")][0].split()[4])


def main():
    lat = json.load(open(os.path.join(RES, "main_v2_summary.json")))["sparse90"]
    rows, missing = {}, []
    for d in ORDER:
        n, mult = HW[d]
        try:
            a, p = area_mm2(n) * mult, power_w(n) * mult
        except (FileNotFoundError, IndexError):
            missing.append(d)
            continue
        for net in ("VGG16", "ResNet18"):
            r = lat[f"{net}|{d}"]
            t1 = r["cycles_b1"] / F_HZ
            e = p * t1
            rows[net, d] = dict(area_mm2=a, power_mw=p * 1e3, latency_ms=t1 * 1e3, energy_mj=e * 1e3,
                                edp=e * 1e3 * t1 * 1e3, energy_img_b16_mj=p * r["cycles_b16"] / 16 / F_HZ * 1e3)
    json.dump({f"{n}|{d}": v for (n, d), v in rows.items()}, open(os.path.join(RES, "energy_v2_summary.json"), "w"), indent=1)
    L = ["| Network | Design | Area (mm²) | Power (mW) | Latency b=1 (ms) | Energy b=1 (mJ) | EDP (mJ·ms) | Energy/img b=16 (mJ) |",
         "|---|---|---:|---:|---:|---:|---:|---:|"]
    for net in ("VGG16", "ResNet18"):
        for d in ORDER:
            if (net, d) in rows:
                r = rows[net, d]
                L.append(f"| {net} | {NAME[d]} | {r['area_mm2']:.3f} | {r['power_mw']:.1f} | {r['latency_ms']:.3f} | "
                         f"{r['energy_mj']:.4f} | {r['edp']:.5f} | {r['energy_img_b16_mj']:.4f} |")
    L += ["", "| Design | Paper reports | Paper area | Paper power | Ours (Nangate45, our clock 800 MHz) | Ours at the paper's clock |",
          "|---|---|---:|---:|---:|---:|"]
    for d, (what, pa, pp, mhz, node) in PAPER.items():
        if (("VGG16", d)) not in rows:
            continue
        a, p = rows["VGG16", d]["area_mm2"], rows["VGG16", d]["power_mw"]
        p_at = p * mhz / 800                                    # dynamic power scales with clock
        if node == "28nm":
            ref = f"{pa:.4f} mm² / {pp:.1f} mW @28nm,{mhz}MHz -> 45nm: {pa*A28:.4f} mm² / {pp*P28:.1f} mW"
        else:
            ref = f"{pa:.4f} mm² / {pp:.1f} mW @{node},{mhz}MHz"
        L.append(f"| {NAME[d]} | {what} | {ref.split(' / ')[0]} | {' / '.join(ref.split(' / ')[1:])} | "
                 f"{a:.4f} mm² / {p:.1f} mW | {p_at:.1f} mW |")
    if missing:
        L += ["", f"Missing (power not measured yet): {', '.join(missing)}"]
    open(os.path.join(RES, "energy_v2_tables.md"), "w").write("\n".join(L) + "\n")
    print("\n".join(L))
    plot(rows)


def plot(rows):
    plt.rcParams.update({"font.family": "serif", "font.size": 9, "axes.edgecolor": INK2, "axes.labelcolor": INK,
                         "xtick.color": INK2, "ytick.color": INK2, "axes.spines.top": False, "axes.spines.right": False})
    ds = [d for d in ORDER if ("VGG16", d) in rows]
    nets = ["VGG16", "ResNet18"]
    fig, axes = plt.subplots(1, 4, figsize=(11, 3.4))
    for ax, (key, ylab, fmt, per_net) in zip(axes, [("power_mw", "Power (mW)", "{:.0f}", False),
                                                     ("area_mm2", "Area (mm²)", "{:.2f}", False),
                                                     ("energy_mj", "Energy, batch 1 (mJ, log)", "{:.3f}", True),
                                                     ("edp", "EDP (mJ·ms, log)", "{:.3f}", True)]):
        if not per_net:
            x = np.arange(len(ds))
            v = [rows["VGG16", d][key] for d in ds]
            ax.bar(x, v, 0.65, color=[COL[d] for d in ds], zorder=3)
            for xi, vi in zip(x, v):
                ax.text(xi, vi, fmt.format(vi), ha="center", va="bottom", fontsize=6, color=INK, rotation=90)
            ax.set_xticks(x, [NAME[d].split(" (")[0] for d in ds], fontsize=6.5, rotation=45, ha="right")
            ax.set_ylim(0, max(v) * 1.25)
        else:
            w = 0.11
            for i, d in enumerate(ds):
                x = np.arange(2) + (i - (len(ds) - 1) / 2) * (w + 0.01)
                v = [rows[n, d][key] for n in nets]
                ax.bar(x, v, w, color=COL[d], label=NAME[d], zorder=3)
                for xi, vi in zip(x, v):
                    ax.text(xi, vi * 1.1, fmt.format(vi), ha="center", va="bottom", fontsize=5, color=INK, rotation=90)
            ax.set_yscale("log")
            ax.set_xticks(range(2), nets)
            ax.set_ylim(top=ax.get_ylim()[1] * 8)
        ax.set_ylabel(ylab)
        ax.yaxis.grid(True, color=GRID, lw=0.6, zorder=0)
    h, l = axes[2].get_legend_handles_labels()
    fig.legend(h, l, fontsize=6.5, frameon=False, loc="lower center", ncol=7)
    fig.suptitle("Our RTL of each design, Nangate45, 800 MHz, gate-level activity; latency v2 (DRAM incl.); "
                 "weights & activations 90% sparse, T=8", fontsize=8, color=INK2)
    fig.tight_layout(rect=(0, 0.08, 1, 1))
    fig.savefig(os.path.join(RES, "power_area_energy_edp_v2.png"), dpi=300)


if __name__ == "__main__":
    main()
