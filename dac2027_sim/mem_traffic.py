"""
mem_traffic.py -- off-chip (DRAM) traffic per inference, split into weights / input activations / output spikes,
workload sparse90, VGG16 and ResNet18, batch 1 and 16 (per image).

  Prosperity : the OFFICIAL Prosperity simulator (third_party/prosperity, simulator.py), run on our layers
               (prosperity_official.our_ops). Its DRAM counter adds activation tiles (on-chip im2col: / k^2 for
               conv) and weight tiles in separate branches, depending on what fits in its 8/32 KB act/wgt buffers;
               here those branches add to separate act / wgt counters (no other change). Outputs: its LIF stage's
               DRAM write.
  PTB        : the official Prosperity-repo PTB model (baselines.run_PTB_convfc): every layer reads its
               activation tensor and weight tensor once and writes the output tensor (get_size() // 8).
  LoAS       : its own formats (fibres of 128: 16-byte bitmask + values), on this workload.
  Ours, SpikeX, SpikeFlow, SATO, LoAS : the tiled rule of memory_model.py (the same rule the official simulator
               applies): with half the on-chip staging buffer per operand, the cheaper of the two loop orders
                 weights outer : wgt = W,             act = I * ceil(W / half)
                 inputs outer  : act = I,             wgt = W * ceil(I / half)
               + output O. Formats / buffers as in memory_model.py (ours: packed columns, 64 KB staging; SpikeX
               54 KB; SpikeFlow non-silent neurons + labels, 18.5 KB; SATO 54 KB (assumed); LoAS fibres, 256 KB).

  python3 mem_traffic.py base         -> results/mem_traffic_base.json   (all but Prosperity; no torch)
  python3 mem_traffic.py prosperity   -> results/mem_traffic_prosperity.json (needs torch)
  python3 mem_traffic.py table        -> results/mem_traffic.md, results/mem_traffic.png/.pdf
"""
import json, math, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
R = os.path.join(HERE, "results")
T = 8
KB = 1024
WD, NS, Q = 0.10, 0.10, 0.3
NETS = ("VGG16", "ResNet18")


def split_tiled(I, W, O, buf):
    half = buf / 2
    a = (W + I * math.ceil(W / half), I * math.ceil(W / half), W) if W > 0 else (I, I, 0)   # (total, act, wgt)
    b = (I + W * math.ceil(I / half), I, W * math.ceil(I / half)) if I > 0 else (W, 0, W)
    tot, act, wgt = min(a, b)
    return act, wgt, O


def base():
    import workload as wl
    import memory_model as MM
    out = {}
    for net in NETS:
        for b in (1, 16):
            acc = {d: [0.0, 0.0, 0.0] for d in ("ours", "spikex", "spikeflow", "sato", "loas_zip", "ptb")}
            for li, layer in enumerate(wl.NETWORKS[net]()):
                lay, Wm, X = MM.layer_inputs(net, li, b, WD, NS, Q)
                name, ci, co, k, s, h = lay
                M, K, N = wl.gemm_shape(layer, b)
                I_raw = ci * h * h * T / 8 * b
                O = co * (h // s) ** 2 * T / 8 * b
                Wd = M * K
                I_sf = int((X != 0).sum()) * T / 8 + ci * h * h * b / 8
                parts = {"ours": split_tiled(I_raw, MM.ours_weight_bytes(Wm), O, MM.BUF["ours"]),
                         "spikex": split_tiled(I_raw, Wd, O, MM.BUF["spikex"]),
                         "spikeflow": split_tiled(I_sf, Wd, O, MM.BUF["spikeflow"]),
                         "sato": split_tiled(I_raw, Wd, O, MM.BUF["sato"])}
                # LoAS: its fibre formats (memory_model.loas_traffic: no on-chip im2col, each output position fetches
                # its fibre A = 16-byte bitmask per 128-chunk + T bits per non-silent neuron; fibre B = bitmask +
                # 8-bit non-zero weights), on THIS workload (measured non-silent and weight densities)
                Mpos = (h // s) ** 2 * b
                nch = math.ceil(K / 128)
                fA = nch * (16 + 128 * float((X != 0).mean()) * (T / 8))
                fB = nch * (16 + 128 * float((Wm != 0).mean()))
                parts["loas_zip"] = split_tiled(Mpos * fA, co * fB, Mpos * co * T / 8, 256 * KB)
                # PTB official rule (run image by image): activation (T bits per input neuron) + weights (8 bit) per
                # image, output get_size() // 8
                parts["ptb"] = (ci * h * h * T / 8 * b, Wd * b, co * (h // s) ** 2 * T / 8 / 8 * b)
                for d, (a, w, o) in parts.items():
                    acc[d][0] += a; acc[d][1] += w; acc[d][2] += o
            for d, (a, w, o) in acc.items():
                out[f"{net}|{b}|{d}"] = dict(act_MB=a / 1e6 / b, wgt_MB=w / 1e6 / b, out_MB=o / 1e6 / b)
    json.dump(out, open(os.path.join(R, "mem_traffic_base.json"), "w"), indent=1)
    for k, v in out.items():
        print(k, {x: round(y, 3) for x, y in v.items()})


def prosperity():
    import re
    import prosperity_official as P
    S = P.S
    src = open(os.path.join(P.SIM, "simulator.py")).read()
    ACC = {"act": 0, "wgt": 0, "out": 0}
    S.__dict__["_ACC"] = ACC
    src = re.sub(r"(\n(\s*)stats\.reads\['dram'\] \+= (cur_tile_size_M \* cur_tile_size_K[^\n]*))",
                 lambda m: m.group(1) + f"\n{m.group(2)}_ACC['act'] += {m.group(3).split('#')[0].strip()}", src)
    src = re.sub(r"(\n(\s*)stats\.reads\['dram'\] \+= (cur_tile_size_K \* cur_tile_size_N \* operator\.weight_tensor\.nbits))",
                 lambda m: m.group(1) + f"\n{m.group(2)}_ACC['wgt'] += {m.group(3)}", src)
    src = re.sub(r"(\n(\s*)stats\.writes\['dram'\] = (operator\.output_tensor\.get_size\(\)))",
                 lambda m: m.group(1) + f"\n{m.group(2)}_ACC['out'] += {m.group(3)}", src)
    saved = sys.modules.get("baselines")
    sys.modules["baselines"] = sys.modules["p_baselines"]          # the official module, as when it was imported
    try:
        exec(compile(src, os.path.join(P.SIM, "simulator.py"), "exec"), S.__dict__)
    finally:
        if saved is not None:
            sys.modules["baselines"] = saved
    S.find_product_sparsity = P.fast_find_product_sparsity
    out = {}
    for net in NETS:
        for b in (1, 16):
            for k in ACC:
                ACC[k] = 0
            ops = P.our_ops(net, b, WD, NS, Q)
            P.run_model_ops(ops, f"{net}_{b}")
            out[f"{net}|{b}|prosperity"] = dict(act_MB=ACC["act"] / 8 / 1e6 / b, wgt_MB=ACC["wgt"] / 8 / 1e6 / b,
                                                out_MB=ACC["out"] / 8 / 1e6 / b)
            print(net, b, out[f"{net}|{b}|prosperity"], flush=True)
    json.dump(out, open(os.path.join(R, "mem_traffic_prosperity.json"), "w"), indent=1)


if __name__ == "__main__" and sys.argv[1] in ("base", "prosperity"):
    {"base": base, "prosperity": prosperity}[sys.argv[1]]()


ORDER = ["ptb", "spikex", "loas_zip", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "loas_zip": "LoAS", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "Ours"}


def table():
    d = json.load(open(os.path.join(R, "mem_traffic_base.json")))
    d.update(json.load(open(os.path.join(R, "mem_traffic_prosperity.json"))))
    L = ["# DRAM traffic per inference (MB), workload sparse90", "",
         "Weights / input activations / output spikes; batch 16 is per image. See mem_traffic.py for each design's rule "
         "(Prosperity: official simulator; PTB: official model; others: the same tiled rule with each design's format "
         "and buffer).", "",
         "| Network | Design | b1 weights | b1 activations | b1 outputs | b1 total | b16 weights | b16 activations | "
         "b16 outputs | b16 total |", "|---|---|---:|---:|---:|---:|---:|---:|---:|---:|"]
    for net in NETS:
        for k in ORDER:
            r1, r16 = d[f"{net}|1|{k}"], d[f"{net}|16|{k}"]
            t1 = r1["act_MB"] + r1["wgt_MB"] + r1["out_MB"]
            t16 = r16["act_MB"] + r16["wgt_MB"] + r16["out_MB"]
            L.append(f"| {net} | {NAME[k]} | {r1['wgt_MB']:.2f} | {r1['act_MB']:.3f} | {r1['out_MB']:.3f} | {t1:.2f} | "
                     f"{r16['wgt_MB']:.2f} | {r16['act_MB']:.3f} | {r16['out_MB']:.3f} | {t16:.2f} |")
    open(os.path.join(R, "mem_traffic.md"), "w").write("\n".join(L) + "\n")
    print("\n".join(L))
    # figure: (a) weight traffic, (b) activation traffic, batch 1, log scale
    import plot_ptb_style as PS
    from matplotlib.ticker import FixedLocator, FixedFormatter, NullLocator
    plt, FS = PS.plt, PS.FS
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.05))
    w = 0.112
    for ax, key, ylab, tag in ((axes[0], "wgt_MB", "Weight traffic (MB)", "(a)"),
                               (axes[1], "act_MB", "Activation traffic (MB)", "(b)")):
        ax.set_yscale("log")
        for i, k in enumerate(ORDER):
            x = np.arange(2) + (i - (len(ORDER) - 1) / 2) * (w + 0.008)
            v = [d[f"{n}|1|{k}"][key] for n in NETS]
            st = PS.STYLE[k]
            ax.bar(x, v, w, color=st["color"], hatch=st["hatch"], edgecolor=PS.EDGE, linewidth=0.5, label=NAME[k],
                   zorder=3)
            if k == "ours":
                for xi, vi in zip(x, v):
                    ax.annotate(f"{vi:.2f}", (xi, vi), xytext=(0, 2), textcoords="offset points", ha="center",
                                va="bottom", fontsize=6.8, rotation=90, color=FS.OURS_TEXT, zorder=5,
                                bbox=dict(boxstyle="square,pad=0.06", fc="white", ec="none"))
        vals = [d[f"{n}|1|{k}"][key] for n in NETS for k in ORDER]
        lo, hi = math.floor(math.log10(min(vals) * 0.6)), math.ceil(math.log10(max(vals) * 1.5)) + 1
        ticks = [10.0 ** e for e in range(lo, hi + 1)]
        ax.yaxis.set_major_locator(FixedLocator(ticks))
        ax.yaxis.set_major_formatter(FixedFormatter([f"{t:g}" for t in ticks]))
        ax.yaxis.set_minor_locator(NullLocator())
        ax.set_ylim(10.0 ** lo, 10.0 ** hi)
        ax.set_xticks(range(2), NETS)
        ax.set_xlim(-0.55, 1.55)
        ax.set_ylabel(ylab)
        ax.yaxis.grid(True, zorder=0)
        FS.panel_tag(ax, tag, y=-0.15)
    h, l = axes[0].get_legend_handles_labels()
    FS.inside_legend(axes[1], h, l, ncol=4)
    fig.subplots_adjust(left=0.065, right=0.995, top=0.985, bottom=0.235, wspace=0.22)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"mem_traffic.{ext}"))


if __name__ == "__main__" and sys.argv[1] == "table":
    table()
