"""
same_node_table.py -- every design at the same technology node (45 nm, Nangate45 typical), same clock, same workload.

Core area / power: our RTL of each design (LoAS: 16 x the given TPPE RTL; SpikeFlow: core with its buffer as external
SRAM), Yosys + ABC, OpenSTA power from gate-level activity (hw/build/<design>_power.rpt measured at 800 MHz; ours:
hw/build_buf, pipelined core, measured at 500 MHz). Power at the common clock: internal + switching scale with the
clock, leakage does not.
SRAM: each design's on-chip buffers as given in its paper, CACTI 7 at 45 nm (Prosperity's sram_config.json):
area and leakage counted; SRAM read/write energy is not counted for any design (access counts are not modelled
for the baselines).
Cycles: cycle models / official simulators (results/main_summary.json, LoAS: results/loas_own.json), workload
sparse90. OP = one accumulation per '1' spike bit per output channel (Phi's definition), identical for all designs.

  python3 same_node_table.py   -> ../results/same_node_45nm.md
"""
import json, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
RES = os.path.join(ROOT, "results")
sys.path.insert(0, ROOT); sys.path.insert(0, HERE)
import workload as wl
import energy_v2 as E2

CLK = 500e6
ORDER = ["ptb", "spikex", "sato", "spikeflow", "loas_zip", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "sato": "SATO", "spikeflow": "SpikeFlow", "loas_zip": "LoAS",
        "prosperity": "Prosperity", "ours": "Ours"}
# on-chip SRAM from each paper; CACTI 7, 45 nm: (KB, area mm^2, leakage mW)
SRAM = {"ptb": ("54 KB GLB + 2 KB L1 (Table IV)", 0.20747, 75.76),
        "spikex": ("54 KB + 2 KB (Sec. V-A)", 0.20747, 75.76),
        "sato": ("54 KB (assumed, not given)", 0.20747, 75.76),
        "spikeflow": ("18.5 KB (Table 1)", 0.06468, 25.15),
        "loas_zip": ("256 KB global cache (Table III)", 0.97711, 299.58),
        "prosperity": ("8 + 32 + 96 KB (Table III)", 0.02860 + 0.21880 + 0.40846, 11.03 + 39.40 + 113.75),
        "ours": ("192 + 64 + 4 KB", 0.70543 + 0.23356 + 0.01598, 265.47 + 86.69 + 5.94)}
HWN = {"ptb": ("ptb", 1), "spikex": ("spikex", 1), "sato": ("sato", 1), "spikeflow": ("spikeflow_ext", 1),
       "loas_zip": ("loas", 16), "prosperity": ("prosperity", 1)}
F_LIF = 0.0401


def rpt_total(path):
    for l in open(path):
        if l.startswith("Total"):
            v = [float(x) for x in l.split()[1:5]]
            return v[0] + v[1], v[2]             # dynamic (internal + switching), leakage  [W]


def core(d):
    """-> (area mm^2, power W at CLK)"""
    if d == "ours":
        import re
        t = open(os.path.join(HERE, "build_buf", "ours_buf_synth.log")).read()
        area = float(re.findall(r"Chip area for top module '\\ours_core': ([\d.]+)", t)[-1]) / 1e6
        (ds, ls), (dl, ll) = (rpt_total(os.path.join(HERE, "build_buf", f)) for f in ("pw_stream.rpt", "pw_lif.rpt"))
        dyn, leak = (1 - F_LIF) * ds + F_LIF * dl, (1 - F_LIF) * ls + F_LIF * ll
        return area, dyn * CLK / 500e6 + leak
    n, mult = HWN[d]
    dyn, leak = rpt_total(os.path.join(HERE, "build", f"{n}_power.rpt"))
    return E2.area_mm2(n) * mult, mult * (dyn * CLK / 800e6 + leak)


def ops_per_image(net):
    tot = 0
    for li, layer in enumerate(wl.NETWORKS[net]()):
        seed = zlib.crc32(f"{net}|{li}|1|0.1|0.1|0.3".encode())
        W, S = wl.layer_tensors(layer, 1, 0.1, 0.1, 0.3, seed)
        tot += int(wl.popcount8(S).sum()) * W.shape[0]
    return tot


def main():
    s = json.load(open(os.path.join(RES, "main_summary.json")))["sparse90"]
    own = json.load(open(os.path.join(RES, "loas_own.json")))
    ops = {n: ops_per_image(n) for n in ("VGG16", "ResNet18")}
    L = ["# All designs at 45 nm (Nangate45), 500 MHz, workload sparse90", "",
         f"OP = one accumulation per '1' spike bit per output channel; VGG16 {ops['VGG16'] / 1e6:.1f} M OP/image, "
         f"ResNet18 {ops['ResNet18'] / 1e6:.1f} M OP/image (same for every design). GOP/s from batch-16 throughput. "
         "Core: our RTL of each design, gate-level power. SRAM: CACTI 7 at 45 nm (area + leakage; read/write energy "
         "not counted for any design). Phi has no RTL here and is not in this table.", "",
         "| Design | Node | Clock | Core area (mm^2) | SRAM | SRAM area (mm^2) | Total area (mm^2) | Core power (mW) | "
         "Core + SRAM leak. (mW) | VGG16 GOP/s | VGG16 GOP/J (core) | VGG16 GOP/J (core+SRAM) | ResNet18 GOP/s | "
         "ResNet18 GOP/J (core) | ResNet18 GOP/J (core+SRAM) |",
         "|---|---|---|---:|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|"]
    out = {}
    for d in ORDER:
        a, p = core(d)
        kb, sa, sl = SRAM[d]
        pt = p + sl * 1e-3
        row = [NAME[d], "45 nm", "500 MHz", f"{a:.3f}", kb, f"{sa:.3f}", f"{a + sa:.3f}", f"{1e3 * p:.1f}", f"{1e3 * pt:.1f}"]
        out[d] = dict(core_area=a, sram_area=sa, core_W=p, total_W=pt)
        for n in ("VGG16", "ResNet18"):
            c16 = own[f"sparse90|{n}|16"] if d == "loas_zip" else s[f"{n}|{d}"]["cycles_b16"]
            gops = ops[n] * 16 / (c16 / CLK) / 1e9
            row += [f"{gops:.1f}", f"{gops / p:.0f}", f"{gops / pt:.0f}"]
            out[d][n] = dict(gops=gops, gopj_core=gops / p, gopj_total=gops / pt)
        L.append("| " + " | ".join(row) + " |")
    L += ["", "All core power numbers are from the same flow; baselines were measured at 800 MHz activity and rescaled "
          "(internal + switching x 500/800, leakage unchanged). Clock 500 MHz is the one our pipelined core meets at "
          "45 nm (synthesis-level timing); the baselines' RTL was not timing-closed and is assumed to run at the same clock."]
    open(os.path.join(RES, "same_node_45nm.md"), "w").write("\n".join(L) + "\n")
    json.dump(out, open(os.path.join(RES, "same_node_45nm.json"), "w"), indent=1)
    print("\n".join(L))


if __name__ == "__main__":
    main()
