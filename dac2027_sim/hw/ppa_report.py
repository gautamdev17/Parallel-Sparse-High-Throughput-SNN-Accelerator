"""
ppa_report.py -- area / power breakdown of our core and the cross-paper comparison table.

Inputs (all produced by this repository's flows):
  build_hier/ours_hier_synth.log   Yosys + ABC, Nangate45 typical, hierarchy kept -> area per block
  build_hier/pw_stream.rpt         OpenSTA power, gate-level activity of 1000 streaming cycles (VGG16 L3, closed loop)
  build_hier/pw_lif.rpt            OpenSTA power, gate-level activity of the drain + LIF sweep (ResNet18 L7 tile 0)
  build_hier/sta_end.rpt           OpenSTA setup timing at 1.25 ns -> worst path per block
  CACTI 7 (HewlettPackard/cacti, Prosperity's sram_config.json) at 28 nm for the SRAM buffers (values below)
Power of the core = (1 - f) P_stream + f P_lif, f = LIF share of VGG16 batch-1 cycles (cycle model).

45 nm -> 28 nm (no 28 nm library available here): area x (28/45)^2 = 0.387 (Stillmaker & Baas 2017 Table 4
log-interpolated gives 0.37); energy/power at the same clock x 0.486 and delay x 0.899 (Stillmaker & Baas 2017
Table 2, 45 -> 32 nm high-performance, 28 nm taken as 32 nm; the paper has no 28 nm node).

  python3 ppa_report.py   -> ../results/ppa_breakdown.md, ../results/comparison_table.md, ../results/ppa.json
"""
import json, math, os, re

HERE = os.path.dirname(os.path.abspath(__file__))
B = os.path.join(HERE, os.environ.get("PPA_DIR", "build_buf"))
RES = os.path.join(os.path.dirname(HERE), "results")
SP_COUNTS = os.environ.get("COUNTS", "")
A28, E28, D28 = (28 / 45) ** 2, 0.486, 0.899
F_LIF = float(os.environ.get("F_LIF", "0.0338"))   # LIF share of VGG16 batch-1 cycles (main.json ours_stats)
CLK45 = float(os.environ.get("CLK", "500e6"))     # clock of the activity windows and of the timing check
PERIOD = 1e9 / CLK45

# CACTI 7 at 28 nm (itrs-hp, Prosperity's config): area mm2, read nJ, write nJ, leakage mW
SRAM = {"output buffer (192 KB, 24 B entries)": (0.33139, 0.0322515, 0.03484, 94.214),
        "staging buffer (64 KB, 16 B)": (0.10094, 0.0128332, 0.0145589, 33.1624),
        "group buffer (2 x 2 KB, 16 B)": (0.00619, 0.00182368, 0.00466557, 2.47614)}

# VGG16 batch-1 counts from the cycle model (sparse90): ops in Phi's definition (one accumulation per '1' spike
# bit per output channel), cycles, and SRAM accesses
VGG = dict(ops=65397188, eff=6546561, cyc=433561, rmw=2637541, lif_entries=234304, passes=157977,
           groups_inj=339839, slices=1298419)
try:   # cycles of the current model (packing, passes, RMW and LIF counts do not depend on the timing rules)
    _m = json.load(open(os.path.join(RES, "main.json")))
    VGG["cyc"] = sum(_m[f"VGG16|{i}|1|sparse90"]["ours"] for i in range(16))
except (OSError, KeyError):
    pass


def areas():
    t = open(os.path.join(B, [f for f in os.listdir(B) if f.endswith("_synth.log")][0])).read()
    last = t[t.rindex("=== design hierarchy ==="):] if "=== design hierarchy ===" in t else t
    mod = {}
    for m in re.finditer(r"Chip area for module '\\?\$?([^']+)': ([\d.]+)", t):
        name = m.group(1).split("\\")[-1]
        mod[name] = float(m.group(2))
    lanes = int(os.environ.get("LANES", "8"))
    a = {"PE array (16 PEs)": 16 * mod["ours_pe"],
         "edge FIFOs (4 x 80 entries)": 4 * mod["ours_edge_fifo"],
         "packer (8 slices/cycle)": lanes * (mod["ours_packer"] + (8 // lanes) * mod["pk_step"]),
         "LIF units (16)": 16 * mod["ours_lif"],
         "arbiter, skew, id sideband, RMW adders": mod["ours_core"]}
    return a


def power(rpt):
    """-> dict block -> W (total), from report_power sections written by power_blocks.tcl."""
    out, cur = {}, None
    ann = None
    for line in open(os.path.join(B, rpt)):
        p = line.split()
        if line.startswith("unannotated"):
            ann = int(p[-1])
        if line.startswith("BLOCK"):
            cur = p[1]; continue
        if cur and p and p[0] == "Total" and len(p) >= 5:
            out[cur] = float(p[4]); cur = None if cur == "total" else cur
        elif cur and cur != "total" and len(p) == 5:
            try:
                out[cur] = out.get(cur + "_sum", 0) + float(p[3]); out[cur + "_sum"] = out[cur]
            except ValueError:
                pass
    return {k: v for k, v in out.items() if not k.endswith("_sum")}, ann


def worst_paths():
    w = {}
    grp = None
    for l in open(os.path.join(B, os.environ.get("STA_RPT", "sta_end2.rpt"))):
        if l.startswith("max_delay/setup group"):
            grp = l.split()[-1]; continue
        p = l.split()
        if grp != "clk" or len(p) < 5 or p[-1] not in ("(MET)", "(VIOLATED)"):
            continue
        n, s = p[0], float(p[-2])
        k = ("PE array (16 PEs)" if ".pe/" in n else "edge FIFOs (4 x 80 entries)" if ".fifo/" in n else
             "LIF units (16)" if n.startswith("lif[") else "packer (8 slices/cycle)" if n.startswith(("packer/", "lane["))
             else "output-buffer RMW ports" if "/" not in n and not n.startswith("_") else
             "arbiter, skew, id sideband, RMW adders")
        w[k] = min(w.get(k, 9e9), s)
    return {k: PERIOD - v for k, v in w.items()}


def main():
    a45 = areas()
    ps, ann_s = power("pw_stream.rpt")
    pl, ann_l = power("pw_lif.rpt")
    names = {"pe": "PE array (16 PEs)", "fifo": "edge FIFOs (4 x 80 entries)", "packer": "packer (8 slices/cycle)",
             "lif": "LIF units (16)"}
    p45 = {}
    for k, n in names.items():
        p45[n] = (1 - F_LIF) * ps.get(k, 0) + F_LIF * pl.get(k, 0)
    tot45 = (1 - F_LIF) * ps["total"] + F_LIF * pl["total"]
    p45["arbiter, skew, id sideband, RMW adders"] = tot45 - sum(p45.values())
    paths = worst_paths()
    fmax45 = 1e3 / max(paths.values())
    # ---- 28 nm core (scaled) + SRAM (CACTI 28 nm)
    a28 = {k: v * 1e-6 * A28 for k, v in a45.items()}           # mm2
    sram_area = {k: v[0] for k, v in SRAM.items()}
    out = dict(area45_um2=a45, power45_W=p45, power45_total_W=tot45, annotated_unannotated=[ann_s, ann_l],
               worst_path_ns=paths, fmax45_MHz=fmax45)
    lines = ["# Our design: area and power breakdown", "",
             "Core: Yosys + ABC, Nangate45 typical, hierarchy kept; power: OpenSTA with gate-level activity from the "
             "closed-loop testbench (1000 streaming cycles of VGG16 L3 + the drain/LIF sweep of a ResNet18 tile, "
             f"weighted {1 - F_LIF:.3f} / {F_LIF:.3f} by the LIF share of VGG16 cycles), at {CLK45 / 1e6:.0f} MHz. "
             "SRAM: CACTI 7 at 28 nm. 28 nm core = 45 nm x (28/45)^2 area, x 0.486 energy (Stillmaker & Baas 2017).", "",
             f"| Block | Area 45 nm (mm^2) | Area 28 nm (mm^2) | Share | Power 45 nm @{CLK45 / 1e6:.0f} MHz (mW) | Share | Worst path 45 nm (ns) |",
             "|---|---:|---:|---:|---:|---:|---:|"]
    at = sum(a45.values())
    for k in a45:
        lines.append(f"| {k} | {a45[k] / 1e6:.4f} | {a28[k]:.4f} | {100 * a45[k] / at:.1f}% | {1e3 * p45[k]:.1f} | "
                     f"{100 * p45[k] / tot45:.1f}% | {paths.get(k, float('nan')):.2f} |")
    lines.append(f"| **Core total** | **{at / 1e6:.4f}** | **{at * 1e-6 * A28:.4f}** | 100% | **{1e3 * tot45:.1f}** | 100% | "
                 f"**{max(paths.values()):.2f}** ({fmax45:.0f} MHz) |")
    lines += ["", f"Activity annotation: {ann_s} / {ann_l} unannotated pins (stream / LIF window).", "",
              "SRAM buffers (outside the core), CACTI 7, 28 nm:", "",
              "| Buffer | Area (mm^2) | Read (pJ) | Write (pJ) | Leakage (mW) |", "|---|---:|---:|---:|---:|"]
    for k, (ar, rd, wr, lk) in SRAM.items():
        lines.append(f"| {k} | {ar:.4f} | {1e3 * rd:.2f} | {1e3 * wr:.2f} | {lk:.1f} |")
    # ---- SRAM energy per VGG16 image (accesses from the cycle model)
    o, s, g = SRAM["output buffer (192 KB, 24 B entries)"], SRAM["staging buffer (64 KB, 16 B)"], SRAM["group buffer (2 x 2 KB, 16 B)"]
    e_sram = (VGG["rmw"] * (o[1] + o[2]) + VGG["lif_entries"] * o[1]                       # RMW + LIF reads
              + VGG["passes"] * 2 * s[1] + VGG["slices"] / 4 * s[1]                         # weights (32 B/pass) + spikes
              + VGG["groups_inj"] * g[1] + VGG["groups_inj"] * g[2] * 0.5) * 1e-9          # group reads + writes (approx.)
    def ppa(freq, core_scale_energy=E28):
        t = VGG["cyc"] / freq
        p_core = tot45 * core_scale_energy * freq / CLK45                                  # dynamic-dominated: P ~ f
        p_leak = sum(v[3] for v in SRAM.values()) * 1e-3
        p = p_core + p_leak + e_sram / t
        gops = VGG["ops"] / t / 1e9
        return dict(freq_MHz=freq / 1e6, latency_ms=t * 1e3, gops=gops, power_W=p, gopj=gops / p,
                    area_mm2=at * 1e-6 * A28 + sum(sram_area.values()), core_W=p_core, sram_W=p_leak + e_sram / t)
    f28 = fmax45 / D28 * 1e6
    rows = {"500 MHz (timing met at 45 nm)": ppa(500e6), "fmax (510 MHz at 45 nm, scaled)": ppa(f28)}
    out["ours_28nm"] = rows
    lines += ["", "Ours at 28 nm on VGG16 (batch 1, sparse90), operations in Phi's definition "
              f"({VGG['ops'] / 1e6:.1f} M per image; {VGG['eff'] / 1e6:.2f} M touch a non-zero weight):", "",
              "| Clock | Latency (ms) | GOP/s | Power core + SRAM (mW) | GOP/J | Area core + SRAM (mm^2) |",
              "|---|---:|---:|---:|---:|---:|"]
    for k, r in rows.items():
        lines.append(f"| {k}: {r['freq_MHz']:.0f} MHz | {r['latency_ms']:.3f} | {r['gops']:.1f} | "
                     f"{1e3 * r['power_W']:.1f} ({1e3 * r['core_W']:.1f} + {1e3 * r['sram_W']:.1f}) | {r['gopj']:.0f} | {r['area_mm2']:.3f} |")
    open(os.path.join(RES, "ppa_breakdown.md"), "w").write("\n".join(lines) + "\n")
    json.dump(out, open(os.path.join(RES, "ppa.json"), "w"), indent=1)
    print("\n".join(lines))
    # ---- comparison table
    r = rows["500 MHz (timing met at 45 nm)"]
    rf = rows["fmax (510 MHz at 45 nm, scaled)"]
    C = ["# Comparison with published SNN accelerators", "",
         "Baseline numbers are as reported in each paper (GOP/s, GOP/J only where the paper reports them; Phi Table 2 "
         "for PTB / SATO / Stellar so one column has one source). 'OP' = one accumulation per '1' spike bit per output "
         "channel (Phi's definition; Prosperity and SATO do not define it).", "",
         "| Design | Venue | Node | Clock | Area (mm^2) | Power (mW) | GOP/s | GOP/J | Workload of the GOP numbers | Notes |",
         "|---|---|---|---|---:|---:|---:|---:|---|---|",
         "| PTB | HPCA'22 | 32 nm (CACTI only) | - | - | - | 18.12* | 10.65* | VGG16/CIFAR100 (from Phi Table 2) | no synthesis reported |",
         "| SpikeX | TCAD | 32 nm (CACTI only) | - | - | - | - | - | - | only normalized results |",
         "| SATO | DAC'22 | 28 nm | 200 MHz | 1.13 (core 0.0203) | 127.8 (core 47.73) | 36.01* (own: 3970.1) | 53.22* | VGG16/CIFAR100 (Phi Table 2) | own GOP/s undefined OP |",
         "| SpikeFlow | JSA'25 | 45 nm (Nangate) | 100 MHz | 1.195 | 127.2 | - | - | - | only normalized results |",
         "| LoAS | MICRO'24 | 32 nm | 800 MHz | 2.08 (incl. 256 KB SRAM) | 188.9 | - | - | - | only normalized results |",
         "| Prosperity | HPCA'25 | 28 nm | 500 MHz | 0.529 (incl. buffers) | 915 (incl. DRAM) | 390.10 | 299.80 | VGG16/CIFAR100 (own Table IV) | OP not defined |",
         "| Phi | ISCA'25 | 28 nm | 500 MHz | 0.662 (incl. 240 KB buffers) | 346.6 (on-chip) | 242.80 | 285.81 | VGG16/CIFAR100 (own Table 2) | GOP/J likely incl. DRAM |",
         f"| **Ours** (target clock) | - | 28 nm (scaled from 45 nm) | 500 MHz | {r['area_mm2']:.3f} (incl. 260 KB SRAM) | {1e3 * r['power_W']:.1f} (core + SRAM) | {r['gops']:.1f} | {r['gopj']:.0f} | VGG16, sparse90 synthetic | timing met at 500 MHz (45 nm, synthesis) |",
         f"| Ours (as synthesized) | - | 28 nm (scaled) | {rf['freq_MHz']:.0f} MHz | {rf['area_mm2']:.3f} | {1e3 * rf['power_W']:.1f} | {rf['gops']:.1f} | {rf['gopj']:.0f} | VGG16, sparse90 synthetic | fmax scaled to 28 nm |",
         "", "\\* PTB, SATO numbers as re-simulated by Phi (Table 2, 500 MHz, 28 nm); Prosperity's Table IV gives different values "
         "for the same baselines (PTB 41.37 / 34.15, SATO 33.63 / 49.70), so sources are not mixed within a column.",
         "Workloads differ: the baselines' VGG16/CIFAR100 spikes are ~10% (Phi) to 34% (Prosperity) dense with dense weights; "
         "our sparse90 workload has 90%-sparse weights and ~4% spike bits, so GOP/s (which counts every output channel per "
         "spike) is not a like-for-like speed comparison -- the latency/throughput figures are."]
    open(os.path.join(RES, "comparison_table.md"), "w").write("\n".join(C) + "\n")
    print("\n".join(C))


if __name__ == "__main__":
    main()
