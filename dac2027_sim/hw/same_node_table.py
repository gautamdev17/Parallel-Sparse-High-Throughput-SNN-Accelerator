"""
same_node_table.py -- every design at the same technology node (45 nm, Nangate45 typical), same clock, same workload.

Core area / power: our RTL of each design (LoAS: 16 x the given TPPE RTL; SpikeFlow: core with its buffer as external
SRAM), Yosys + ABC, OpenSTA power from gate-level activity (hw/build/<design>_power.rpt measured at 800 MHz; ours:
hw/build_buf, pipelined core, measured at 500 MHz). Power at the common clock: internal + switching scale with the
clock, leakage does not.
SRAM: each design's on-chip buffers as given in its paper, CACTI 7 at 45 nm, ITRS LSTP cells + LOP periphery,
300 K (every buffer meets 500 MHz; hw/sram_45nm_lstp_lop.json): area, leakage AND read/write energy. Access counts
per image at batch 16 (results/mem_levels_*_b16.json, mem_traffic_*.json): reads = the on-chip -> array traffic of
mem_levels.py; writes = DRAM fills + output spikes; ours adds the group buffer (packer writes, array reads) and the
output buffer (read-modify-write per running-sum entry + one LIF read per output); Prosperity uses its official
simulator's own buffer counters (act / wgt / psum reads and writes). Energy per access scales with the bits moved
(E_access / block bits per bit). DRAM energy is not counted.
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
# on-chip SRAM from each paper: (label, [(buffer, block bytes, size bytes)])
SRAM = {"ptb": ("54 KB GLB + 2 KB L1 (Table IV)", [("glb", 16, 57344)]),
        "spikex": ("54 KB + 2 KB (Sec. V-A)", [("glb", 16, 57344)]),
        "sato": ("54 KB (assumed, not given)", [("glb", 16, 57344)]),
        "spikeflow": ("18.5 KB (Table 1)", [("glb", 16, 18944)]),
        "loas_zip": ("256 KB global cache (Table III)", [("glb", 16, 262144)]),
        "prosperity": ("8 + 32 + 96 KB (Table III)", [("g_act", 4, 8192), ("g_wgt", 128, 32768), ("g_psum", 128, 98304)]),
        "ours": ("192 + 64 + 4 KB", [("obuf", 24, 196608), ("staging", 16, 65536), ("group", 16, 4096)])}
CACTI = json.load(open(os.path.join(HERE, "sram_45nm_lstp_lop.json")))


def sram_access_bits(d, net):
    """-> {buffer: (read bits, write bits)} per image at batch 16."""
    M = 8e6
    lv = {}
    for f in ("base_b16", "sato_b16", "prosperity_b16", "ptb"):
        lv.update(json.load(open(os.path.join(RES, f"mem_levels_{f}.json"))))
    off = json.load(open(os.path.join(RES, "mem_traffic_base.json")))
    r = lv[f"{net}|{d}"]
    if d == "prosperity":
        rd, wr = r["reads_bits"], r["writes_bits"]
        return {b: (rd[b], wr[b]) for b in ("g_act", "g_wgt", "g_psum")}
    o = off[f"{net}|16|{d}"]
    fills = (o["wgt_MB"] + o["act_MB"] + o["out_MB"]) * M
    if d == "ours":
        grp_rd = (r["onchip_act_MB"] - r["packer_raw_read_MB"]) * M
        return {"staging": ((r["onchip_wgt_MB"] + r["packer_raw_read_MB"]) * M, fills),
                "group": (grp_rd, r["group_write_MB"] * M),
                "obuf": ((r["obuf_rmw_entries"] + r["lif_reads_entries"]) * 24 * 8, r["obuf_rmw_entries"] * 24 * 8)}
    return {"glb": ((r["onchip_wgt_MB"] + r["onchip_act_MB"]) * M, fills)}


DRAM_PJ_BIT = 12.45


def dram_J(d, net):
    t = json.load(open(os.path.join(RES, "mem_traffic_base.json")))
    t.update(json.load(open(os.path.join(RES, "mem_traffic_prosperity.json"))))
    o = t[f"{net}|16|{d}"]
    return (o["wgt_MB"] + o["act_MB"] + o["out_MB"]) * 8e6 * DRAM_PJ_BIT * 1e-12


def sram(d, net):
    """-> (area mm^2, leakage W, dynamic energy J per image)"""
    area = leak = e = 0.0
    acc = sram_access_bits(d, net)
    for name, blk, size in SRAM[d][1]:
        c = CACTI[f"{blk}|{size}"]
        area += c["area"]
        leak += c["leak_mW"] * 1e-3
        rb, wb = acc[name]
        e += (rb * c["read_nJ"] + wb * c["write_nJ"]) / (blk * 8) * 1e-9
    return area, leak, e


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
         f"ResNet18 {ops['ResNet18'] / 1e6:.1f} M OP/image (same for every design). GOP/s and energy per image from "
         "batch-16 throughput. Core: our RTL of each design, gate-level power. SRAM: CACTI 7 at 45 nm, LSTP cells + "
         "LOP periphery, 300 K: area, leakage and read/write energy from each design's access counts "
         "(mem_levels.py). DRAM: 12.45 pJ/bit (Prosperity repo, DRAMsim3) x DRAM traffic per image. Phi has no RTL here "
         "and is not in this table.", "",
         "| Design | Core area (mm^2) | SRAM | SRAM area (mm^2) | Total area (mm^2) | Core power (mW) | SRAM leak. (mW) | "
         "VGG16 GOP/s | VGG16 energy core / SRAM / DRAM (uJ/img) | VGG16 GOP/J core | VGG16 GOP/J core+SRAM | "
         "VGG16 GOP/J system | ResNet18 GOP/s | ResNet18 energy core / SRAM / DRAM (uJ/img) | ResNet18 GOP/J core | "
         "ResNet18 GOP/J core+SRAM | ResNet18 GOP/J system |",
         "|---|---:|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|"]
    out = {}
    for d in ORDER:
        a, p = core(d)
        sa, sl, _ = sram(d, "VGG16")
        row = [NAME[d], f"{a:.3f}", SRAM[d][0], f"{sa:.3f}", f"{a + sa:.3f}", f"{1e3 * p:.1f}", f"{1e3 * sl:.2f}"]
        out[d] = dict(core_area=a, sram_area=sa, core_W=p, sram_leak_W=sl)
        for n in ("VGG16", "ResNet18"):
            c16 = own[f"sparse90|{n}|16"] if d == "loas_zip" else s[f"{n}|{d}"]["cycles_b16"]
            t = c16 / CLK / 16                                   # s per image
            _, _, edyn = sram(d, n)
            e_core, e_sram, e_dram = p * t, sl * t + edyn, dram_J(d, n)
            e_tot = e_core + e_sram
            gops = ops[n] / t / 1e9
            row += [f"{gops:.1f}", f"{e_core * 1e6:.0f} / {e_sram * 1e6:.0f} / {e_dram * 1e6:.0f}",
                    f"{ops[n] / e_core / 1e9:.0f}", f"{ops[n] / e_tot / 1e9:.0f}", f"{ops[n] / (e_tot + e_dram) / 1e9:.0f}"]
            out[d][n] = dict(gops=gops, sram_dyn_J=edyn, e_core_J=e_core, e_sram_J=e_sram, e_dram_J=e_dram,
                             gopj_core=ops[n] / e_core / 1e9, gopj_total=ops[n] / e_tot / 1e9,
                             gopj_system=ops[n] / (e_tot + e_dram) / 1e9, t_img=t)
        L.append("| " + " | ".join(row) + " |")
    L += ["", "Core power numbers are all from the same flow; baselines were measured at 800 MHz activity and rescaled "
          "(internal + switching x 500/800, leakage unchanged). Clock 500 MHz is the one our pipelined core meets at "
          "45 nm (synthesis-level timing); the baselines' RTL was not timing-closed and is assumed to run at the same clock "
          "(LoAS's TPPE does not: 3.14 ns). Previous version with ITRS-HP SRAM at 360 K and no access energy: "
          "same_node_45nm_hpsram_old.md."]
    open(os.path.join(RES, "same_node_45nm.md"), "w").write("\n".join(L) + "\n")
    json.dump(out, open(os.path.join(RES, "same_node_45nm.json"), "w"), indent=1)
    print("\n".join(L))


if __name__ == "__main__":
    main()
