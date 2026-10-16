"""
memory_model.py -- version 2 of the latency/throughput comparison: off-chip (DRAM) traffic included for every design.

Common rule for all designs (the rule of the official Prosperity simulator, which already applies it to Prosperity
and to its PTB model):
  DRAM interface 1024 bits/cycle (Prosperity simulator `mem_if_width`; env DRAM_BITS_PER_CYCLE to change),
  loads double-buffered:  layer cycles = compute + first-tile load + max(0, DRAM cycles - compute)

DRAM traffic per layer, per design:
  Prosperity, PTB : the official Prosperity-repo simulators (already included in their cycle counts).
  LoAS            : after the team's own LoAS DRAM model (EnergySpeedupSim.zip / memory.py), T = 8: no on-chip
                    im2col, every output position fetches its fiber A (16-byte bitmask per 128-chunk + non-silent
                    spike trains); weight fiber B = bitmask + non-zero weights per filter; 256 KB SRAM; same
                    statistics as the zip latency model (26.1% non-silent, dense weights). One correction: memory.py
                    charges ALL weights once per weight tile (fBt * mt * nt), counting them nt times over (74x on
                    VGG16 fc2); here the same two-loop-order rule as the other designs is used.
  Ours, SpikeX, SpikeFlow, SATO : generic tiled-GEMM traffic with on-chip im2col. Input = raw input feature map
                    (T bits per neuron), output = output spikes (T bits per neuron), weights in the design's format.
                    With half the staging buffer per operand (double buffering), the cheaper of the two loop orders:
                      weights outer : W + I * ceil(W / half);   inputs outer : I + W * ceil(I / half)
    format / buffer :  Ours      packed columns: per (m-block, K-tile) column R x (8-bit weight + 2-bit filter label)
                                 + F x 6-bit filter ids; staging 64 KB (the 192 KB output buffer holds partial sums
                                 on chip and never spills, since an output tile completes on chip)
                       SpikeX    dense 8-bit weights; GLB 54 KB (SpikeX Sec. V-A)
                       SpikeFlow dense 8-bit weights; only non-silent input neurons are transferred (+1 label bit per
                                 neuron, Sec. 4.2); on-chip memory 18.5 KB (Table 1)
                       SATO      dense 8-bit weights; buffer not given in the paper -> PTB/SpikeX's 54 KB (assumption)

  python3 memory_model.py   (needs torch: run with the venv python) -> results/main_v2_summary.json, main_v2_tables.md
"""
import json, math, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import workload as wl
from ours import Cfg, LayerPlan
from baselines import loas_layer_cycles, LOAS_P_ZIP

R = os.path.join(HERE, "results")
F_HZ = 800e6
BW = int(os.environ.get("DRAM_BITS_PER_CYCLE", 1024))   # bits per cycle (1024 = Prosperity simulator)
TAG = "" if BW == 1024 else f"_bw{BW}"
T = 8
KB = 1024
BUF = {"ours": 64 * KB, "spikex": 54 * KB, "spikeflow": int(18.5 * KB), "sato": 54 * KB}
WORK = {"sparse90": (0.10, 0.10, 0.3), "zipstats": (1.00, LOAS_P_ZIP, 0.3)}


def tiled_traffic(I, W, O, buf):
    half = buf / 2
    a = W + I * math.ceil(W / half) if W > 0 else I
    b = I + W * math.ceil(I / half) if I > 0 else W
    return min(a, b) + O, min(half, I + W)


def stall_rule(compute, traffic_bytes, first_bytes):
    mem = traffic_bytes * 8 / BW
    init = first_bytes * 8 / BW
    return compute + init + max(0.0, mem - compute), mem


def loas_traffic(layer, batch, spa_pk=1 - LOAS_P_ZIP, spb=0.0, sram=256 * KB):
    name, ci, co, k, s, h = layer
    Mpos = (h // s) ** 2 * batch
    K = ci * k * k
    nch = math.ceil(K / 128)
    fA = nch * (16 + 128 * (1 - spa_pk) * (T / 8))
    fB = nch * (16 + 128 * (1 - spb) * 1)
    I, Wt = Mpos * fA, co * fB
    out = Mpos * co * T / 8
    return tiled_traffic(I, Wt, out, sram)


def layer_inputs(net, li, batch, wd, ns, q):
    """the same draws as workload.layer_tensors (weights, then input feature map)."""
    layer = wl.NETWORKS[net]()[li]
    seed = zlib.crc32(f"{net}|{li}|{batch}|{wd}|{ns}|{q}".encode())
    rng = np.random.default_rng(seed)
    M, K, N = wl.gemm_shape(layer, batch)
    W = wl.rand_weights(rng, M, K, wd)
    X = wl.rand_spikes(rng, (batch, layer[1], layer[5], layer[5]), ns, q)
    return layer, W, X


def ours_weight_bytes(W, cfg=Cfg()):
    plan = LayerPlan(W, cfg)
    ncols = sum(len(c) for c, _ in plan.cols.values())
    return ncols * (cfg.R * 10 + cfg.F * 6) / 8


def sato_layer_compute(net, batch, wname):
    """per-layer SATO compute cycles from the official Prosperity-repo model (run_sato_conv_fc + run_sato_lif)."""
    import contextlib, io
    import prosperity_official as P
    wd, ns, q = WORK[wname]
    ops = P.our_ops(net, batch, wd, ns, q)
    mod = sys.modules["p_baselines"]
    out = []
    with contextlib.redirect_stdout(io.StringIO()):
        for i in range(0, len(ops), 2):
            out.append(mod.run_sato_conv_fc(ops[i]).compute_cycles + mod.run_sato_lif(ops[i + 1]).compute_cycles)
    return out


def main():
    cache = json.load(open(os.path.join(R, "main.json")))
    official = {d: json.load(open(os.path.join(R, f.replace(".json", f"{TAG}.json")))) for d, f in
                (("prosperity", "prosperity_official.json"), ("ptb", "ptb_official.json"))}
    sato_cmp = {(net, b, w): sato_layer_compute(net, b, w)
                for w in WORK for net in ("VGG16", "ResNet18") for b in (1, 16)}
    out = {}
    for w, (wd, ns, q) in WORK.items():
        for net in ("VGG16", "ResNet18"):
            layers = wl.NETWORKS[net]()
            for b in (1, 16):
                tot = dict(ours=0.0, loas_zip=0.0, spikex=0.0, spikeflow=0.0, sato=0.0)
                memb = dict(tot)
                for li, layer in enumerate(layers):
                    c = cache[f"{net}|{li}|{b}|{w}"]
                    M, K, N = c["M"], c["K"], c["N"]
                    lay, Wm, X = layer_inputs(net, li, b, wd, ns, q)
                    name, ci, co, k, s, h = lay
                    I_raw = ci * h * h * T / 8 * b
                    O = co * (h // s) ** 2 * T / 8 * b
                    Wdense = M * K
                    nsil = int((X != 0).sum())
                    I_sf = nsil * T / 8 + ci * h * h * b / 8
                    for d, comp, (tr, first) in (
                            ("ours", c["ours"], tiled_traffic(I_raw, ours_weight_bytes(Wm), O, BUF["ours"])),
                            ("spikex", c["spikex"], tiled_traffic(I_raw, Wdense, O, BUF["spikex"])),
                            ("spikeflow", c["spikeflow"], tiled_traffic(I_sf, Wdense, O, BUF["spikeflow"])),
                            ("sato", sato_cmp[net, b, w][li], tiled_traffic(I_raw, Wdense, O, BUF["sato"])),
                            ("loas_zip", loas_layer_cycles(M, K, N, LOAS_P_ZIP), loas_traffic(lay, b))):
                        cyc, _ = stall_rule(comp, tr, first)
                        tot[d] += cyc
                        memb[d] += tr
                for d in ("prosperity", "ptb"):
                    tot[d] = official[d][f"{net}|{b}|{w}"]
                for d, v in tot.items():
                    e = out.setdefault(w, {}).setdefault(f"{net}|{d}", {})
                    e[f"cycles_b{b}"] = v
                    if d in memb:
                        e[f"dram_MB_b{b}"] = memb[d] / 1e6
    for w in out:
        for v in out[w].values():
            v["latency_ms"] = v["cycles_b1"] / F_HZ * 1e3
            v["throughput"] = 16 * F_HZ / v["cycles_b16"]
    json.dump(out, open(os.path.join(R, f"main_v2{TAG}_summary.json"), "w"), indent=1)
    v1 = json.load(open(os.path.join(R, "main_summary.json")))
    names = {"loas_zip": "LoAS", "spikex": "SpikeX (8x8)", "ptb": "PTB (16x8, Prosperity-repo model)",
             "sato": "SATO (128 PE)", "spikeflow": "SpikeFlow (16x16)", "prosperity": "Prosperity (official sim)",
             "ours": "Ours (4x4, T=8)"}
    lines = []
    for w in out:
        lines += [f"### v2 (DRAM included, {BW} bits/cycle = {BW * F_HZ / 8e9:.1f} GB/s), workload `{w}`", "",
                  "| Network | Design | Latency b=1 (ms) | v1 latency (compute only) | Throughput b=16 (img/s) | v1 throughput "
                  "| DRAM traffic b=1 (MB) | Ours speed-up |", "|---|---|---:|---:|---:|---:|---:|---:|"]
        for net in ("VGG16", "ResNet18"):
            o = out[w][f"{net}|ours"]
            for d in names:
                r, r1 = out[w][f"{net}|{d}"], v1[w][f"{net}|{d}"]
                dm = f"{r['dram_MB_b1']:.2f}" if "dram_MB_b1" in r else "(in official sim)"
                lines.append(f"| {net} | {names[d]} | {r['latency_ms']:.3f} | {r1['latency_ms']:.3f} | {r['throughput']:,.0f} | "
                             f"{r1['throughput']:,.0f} | {dm} | {r['latency_ms'] / o['latency_ms']:.2f}x |")
        lines.append("")
    open(os.path.join(R, f"main_v2{TAG}_tables.md"), "w").write("\n".join(lines))
    print("\n".join(lines))


if __name__ == "__main__":
    main()
