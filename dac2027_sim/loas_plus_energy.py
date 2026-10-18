"""
loas_plus_energy.py -- power, energy and EDP of LoAS vs LoAS+ (same flow as hw/energy_v2.py / hw/same_node_table.py).

Power: 16 x the TPPE, Yosys + ABC on Nangate45, OpenSTA report_power with gate-level activity at 800 MHz, both on the
same stimulus (tb_loas.v / tb_loas_plus.v: 128-chunks, dense weights, 26.1 % non-silent, spike-bit prob. 0.3).
  LoAS : hw/build/loas_power.rpt     (hw/rtl/loas -- note: this RTL fails its own reference check, see below)
  LoAS+: hw/build_lp/loas_plus_power.rpt  (hw/rtl/loas_plus/tppe_plus.v, bit-exact RTL and gate level)
SRAM: the 256 KB global cache of LoAS Table III, CACTI 7 at 45 nm, leakage 299.58 mW (hw/same_node_table.py);
the same for both. Read/write energy is not counted (as in the repo's other tables); LoAS+ makes no more cache
accesses than LoAS (same matches, skipped empty weight chunks) but needs 4 read ports per TPPE.
Latency: cycle models at 800 MHz (results/loas_plus.json, results/loas_plus_real.json).
Energy (batch 1) = power x latency; EDP = energy x latency; energy/image at batch 16 = power x cycles_b16 / 16.

  python3 loas_plus_energy.py   -> results/loas_plus_energy.{json,md}, results/loas_plus_energy.{pdf,png}
"""
import json, os, re
import numpy as np
import figstyle as FS
import matplotlib.pyplot as plt

HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
F_HZ = 800e6
N_TPPE = 16
SRAM_LEAK_W = 299.58e-3
DESIGNS = {"LoAS": ("build", "loas", "LoAS"), "LoAS+": ("build_lp", "loas_plus", "+C1+C2+C3")}


def tppe(d):
    b, n, _ = DESIGNS[d]
    rpt = open(os.path.join(HERE, "hw", b, f"{n}_power.rpt")).read()
    assert re.search(r"unannotated\s+0", rpt), f"{n}: unannotated pins"
    p = float([l for l in rpt.splitlines() if l.startswith("Total")][0].split()[4])
    log = open(os.path.join(HERE, "hw", b, f"{n}_synth.log")).read()
    a = float(re.findall(r"Chip area for module '\\\S+': ([\d.]+)", log)[-1]) / 1e6
    return p, a


def main():
    syn = json.load(open(os.path.join(R, "loas_plus.json")))["totals"]
    real = json.load(open(os.path.join(R, "loas_plus_real.json")))
    P = {}
    for d in DESIGNS:
        p, a = tppe(d)
        P[d] = dict(tppe_mw=p * 1e3, tppe_area_mm2=a, core_mw=N_TPPE * p * 1e3, total_mw=(N_TPPE * p + SRAM_LEAK_W) * 1e3)
    rows = {}
    for src in (syn, real):
        for key, cyc in src.items():
            w, net, b = key.split("|")
            if b == "16":
                continue
            r = {}
            for d, (_, _, var) in DESIGNS.items():
                c1 = cyc[var]
                c16 = syn.get(f"{w}|{net}|16", {}).get(var)
                t = c1 / F_HZ
                r[d] = dict(cycles_b1=c1, latency_ms=t * 1e3,
                            energy_core_mj=P[d]["core_mw"] * t, energy_mj=P[d]["total_mw"] * t,
                            edp=P[d]["total_mw"] * t * t * 1e3,
                            energy_img_b16_mj=None if c16 is None else P[d]["total_mw"] * c16 / 16 / F_HZ)
            rows[f"{w}|{net}"] = r
    json.dump(dict(power=P, rows=rows), open(os.path.join(R, "loas_plus_energy.json"), "w"), indent=1)

    L = ["# LoAS vs LoAS+: power, energy, EDP (Nangate45, 800 MHz, gate-level activity; 256 KB cache leakage incl.)", "",
         "| Design | TPPE area (mm²) | TPPE power (mW) | 16 TPPEs (mW) | + cache leakage (mW) |", "|---|---:|---:|---:|---:|"]
    for d in DESIGNS:
        p = P[d]
        L.append(f"| {d} | {p['tppe_area_mm2']:.4f} | {p['tppe_mw']:.2f} | {p['core_mw']:.1f} | {p['total_mw']:.1f} |")
    L += ["", "| Workload | Network | LoAS latency (ms) | LoAS+ latency (ms) | LoAS energy (mJ) | LoAS+ energy (mJ) | "
          "Energy gain | Core-only energy gain | LoAS EDP (mJ·ms) | LoAS+ EDP (mJ·ms) | EDP gain |",
          "|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|"]
    for key, r in rows.items():
        w, net = key.split("|")
        a, b = r["LoAS"], r["LoAS+"]
        L.append(f"| {w} | {net} | {a['latency_ms']:.3f} | {b['latency_ms']:.3f} | {a['energy_mj']:.4f} | "
                 f"{b['energy_mj']:.4f} | **{a['energy_mj'] / b['energy_mj']:.2f}x** | "
                 f"{a['energy_core_mj'] / b['energy_core_mj']:.2f}x | {a['edp']:.4f} | {b['edp']:.5f} | "
                 f"**{a['edp'] / b['edp']:.1f}x** |")
    L += ["", "Energy = (16 TPPEs + cache leakage) x batch-1 latency. LoAS power is measured on hw/rtl/loas, which runs at "
          "~6.3 cycles/match and fails its own reference check (tb_loas.v: 400/400 mismatches over 50 chunks), so its "
          "measured activity is low; LoAS+ power is measured at full activity (0.77 cycles/match, bit-exact). Both "
          "choices favour LoAS. Neither TPPE closes 800 MHz unplaced (register-to-register: LoAS 3.14 ns, LoAS+ "
          "2.42 ns); both are evaluated at the same 800 MHz, as in the other tables."]
    open(os.path.join(R, "loas_plus_energy.md"), "w").write("\n".join(L) + "\n")
    print("\n".join(L))
    plot(P, rows)


def plot(P, rows):
    groups = [("sparse90|VGG16", "VGG16\nsynthetic"), ("sparse90|ResNet18", "ResNet18\nsynthetic"),
              ("real-spikes wd=0.1|VGG16", "VGG16\nreal spikes"), ("real-spikes wd=0.1|ResNet18", "ResNet18\nreal spikes")]
    base = dict(color="#c3d3e2", hatch="////")
    fig, axes = plt.subplots(1, 3, figsize=(FS.TEXT, 2.0), gridspec_kw=dict(width_ratios=[2.2, 4, 4]))
    fig.subplots_adjust(left=0.06, right=0.995, top=0.84, bottom=0.25, wspace=0.42)
    # (a) power: core + cache leakage, stacked
    ax = axes[0]
    for i, d in enumerate(DESIGNS):
        st = base if d == "LoAS" else dict(color=FS.OURS, hatch="")
        core, tot = P[d]["core_mw"], P[d]["total_mw"]
        ax.bar(i, core, 0.6, color=st["color"], hatch=st["hatch"], edgecolor=FS.EDGE, lw=0.5, zorder=3)
        ax.bar(i, tot - core, 0.6, bottom=core, color="#eeeeee", hatch="....", edgecolor=FS.EDGE, lw=0.5, zorder=3,
               label="256 KB cache leakage" if i == 0 else None)
        ax.text(i, tot + 8, f"{tot:.0f}", ha="center", va="bottom", fontsize=6.5,
                color=FS.OURS_TEXT if d != "LoAS" else "#333333")
        ax.text(i, core / 2, f"{core:.0f}", ha="center", va="center", fontsize=6, color="#111111", zorder=4)
    ax.set_xticks([0, 1]); ax.set_xticklabels(list(DESIGNS))
    ax.set_xlim(-0.6, 1.6); ax.set_ylim(0, 620); ax.set_yticks(range(0, 601, 200))
    ax.set_ylabel("Power (mW)")
    ax.grid(axis="y", zorder=0)
    FS.inside_legend(ax, *ax.get_legend_handles_labels(), ncol=1, loc="upper left", fontsize=6)
    FS.panel_tag(ax, "(a) Power: 16 TPPEs + cache", y=-0.27)
    # (b) energy and (c) EDP, log scale
    for ax, key, lab, tag in ((axes[1], "energy_mj", "Energy / image, b=1 (mJ)", "(b) Energy"),
                              (axes[2], "edp", "EDP (mJ·ms)", "(c) Energy-delay product")):
        x = np.arange(len(groups))
        for j, d in enumerate(DESIGNS):
            st = base if d == "LoAS" else dict(color=FS.OURS, hatch="")
            v = [rows[g][d][key] for g, _ in groups]
            ax.bar(x + (j - 0.5) * 0.36, v, 0.36, color=st["color"], hatch=st["hatch"], edgecolor=FS.EDGE, lw=0.5,
                   zorder=3, label=d)
        for xi, (g, _) in zip(x, groups):
            gain = rows[g]["LoAS"][key] / rows[g]["LoAS+"][key]
            ax.text(xi + 0.18, rows[g]["LoAS+"][key] * 1.25, f"{gain:.1f}" + r"$\times$", ha="center", va="bottom",
                    fontsize=6.5, color=FS.OURS_TEXT)
        ax.set_yscale("log")
        lo = min(rows[g]["LoAS+"][key] for g, _ in groups) / 3
        hi = max(rows[g]["LoAS"][key] for g, _ in groups) * 4
        ax.set_ylim(lo, hi)
        ax.set_xticks(x); ax.set_xticklabels([l for _, l in groups], fontsize=6.5)
        ax.set_ylabel(lab)
        ax.grid(axis="y", which="major", zorder=0)
        FS.panel_tag(ax, tag, y=-0.27)
    h, l = axes[1].get_legend_handles_labels()
    lg = fig.legend(h, l, ncol=2, loc="upper center", bbox_to_anchor=(0.62, 1.0), frameon=True, fancybox=False,
                    edgecolor=FS.EDGE, fontsize=7, handlelength=1.0, handleheight=1.0, handletextpad=0.4,
                    columnspacing=1.2, borderpad=0.35)
    lg.get_frame().set_linewidth(0.5)
    for ext in ("pdf", "png"):
        fig.savefig(os.path.join(R, f"loas_plus_energy.{ext}"))
    plt.close(fig)


if __name__ == "__main__":
    main()
