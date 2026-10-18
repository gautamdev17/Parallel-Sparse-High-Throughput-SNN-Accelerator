"""
roofline.py -- roofline of every design, workload sparse90, batch 16, common clock 500 MHz and DRAM 64 GB/s
(Prosperity's DDR4 setting; = 1024 bits/cycle at 500 MHz).

  work  W   = effectual operations per image: accumulations of a NON-ZERO weight for a '1' spike bit (the same useful
              work for every design; designs that do not skip zero weights spend extra cycles, not extra W)
  traffic Q = DRAM bytes per image (results/mem_traffic_*.json: weights + activations + outputs)
  operational intensity = W / Q;  attainable = W * images / time (cycles from main_summary.json / loas_own.json)
  compute roof = adders x 500 MHz (one effectual accumulation per adder per cycle at best)

  python3 roofline.py   -> results/roofline.md, results/roofline.png/.pdf
"""
import json, math, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
R = os.path.join(HERE, "results")
CLK, BW = 500e6, 64e9
NETS = ("VGG16", "ResNet18")
ORDER = ["ptb", "spikex", "loas_zip", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "loas_zip": "LoAS", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "Ours"}
ADDERS = {"ptb": 128, "spikex": 64, "loas_zip": 128, "sato": 128, "spikeflow": 256, "prosperity": 128, "ours": 128}
MARK = {"ptb": "o", "spikex": "s", "loas_zip": "D", "sato": "^", "spikeflow": "v", "prosperity": "P", "ours": "*"}


def effectual(net):
    import workload as wl
    tot = 0
    for li, layer in enumerate(wl.NETWORKS[net]()):
        seed = zlib.crc32(f"{net}|{li}|1|0.1|0.1|0.3".encode())
        W, S = wl.layer_tensors(layer, 1, 0.1, 0.1, 0.3, seed)
        tot += int(((W != 0).astype(np.int64) @ wl.popcount8(S).astype(np.int64)).sum())
    return tot


def main():
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    own = json.load(open(os.path.join(R, "loas_own.json")))
    tr = json.load(open(os.path.join(R, "mem_traffic_base.json")))
    tr.update(json.load(open(os.path.join(R, "mem_traffic_prosperity.json"))))
    Wk = {n: effectual(n) for n in NETS}
    pts = {}
    L = ["# Roofline (sparse90, batch 16, 500 MHz, DRAM 64 GB/s)", "",
         f"Work = effectual accumulations (non-zero weight x spike bit): VGG16 {Wk['VGG16'] / 1e6:.2f} M, "
         f"ResNet18 {Wk['ResNet18'] / 1e6:.2f} M per image. Compute roof = adders x 500 MHz; memory roof = 64 GB/s x OI. "
         "Ridge point = compute roof / 64 GB/s.", "",
         "| Network | Design | DRAM (MB/img) | OI (op/B) | Attained (GOP/s) | Compute roof (GOP/s) | Memory roof at OI (GOP/s) | Bound | % of roof |",
         "|---|---|---:|---:|---:|---:|---:|---|---:|"]
    for n in NETS:
        for d in ORDER:
            t = tr[f"{n}|16|{d}"]
            q = (t["act_MB"] + t["wgt_MB"] + t["out_MB"]) * 1e6
            c16 = own[f"sparse90|{n}|16"] if d == "loas_zip" else s[f"{n}|{d}"]["cycles_b16"]
            perf = Wk[n] * 16 / (c16 / CLK) / 1e9
            oi = Wk[n] / q
            croof, mroof = ADDERS[d] * CLK / 1e9, BW * oi / 1e9
            roof = min(croof, mroof)
            bound = "memory" if mroof < croof else "compute"
            pts[n, d] = (oi, perf, croof)
            L.append(f"| {n} | {NAME[d]} | {q / 1e6:.2f} | {oi:.3f} | {perf:.2f} | {croof:.0f} | {mroof:.2f} | "
                     f"{bound} | {100 * perf / roof:.0f}% |")
    open(os.path.join(R, "roofline.md"), "w").write("\n".join(L) + "\n")
    print("\n".join(L))
    import plot_ptb_style as PS
    plt, FS = PS.plt, PS.FS
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.4))
    x = np.logspace(-2, 2, 200)
    for ax, n, tag in ((axes[0], "VGG16", "(a) VGG16"), (axes[1], "ResNet18", "(b) ResNet18")):
        for adders, ls in ((256, (0, (1, 1.5))), (128, "-"), (64, (0, (4, 2)))):
            ax.plot(x, np.minimum(adders * CLK / 1e9, BW * x / 1e9), color="#7a7a7a" if adders != 128 else FS.EDGE,
                    lw=0.8 if adders != 128 else 1.0, ls=ls, zorder=2)
            ax.text(60, adders * CLK / 1e9 * 1.12, f"{adders} adders", fontsize=6.3, ha="right", va="bottom",
                    color="#555555")
        for d in ORDER:
            oi, perf, _ = pts[n, d]
            st = PS.STYLE[d]
            ours = d == "ours"
            ax.scatter([oi], [perf], s=70 if ours else 26, marker=MARK[d], color=st["color"], edgecolor=PS.EDGE,
                       linewidth=0.6, zorder=5 if ours else 4, label=NAME[d])
        ax.set_xscale("log"); ax.set_yscale("log")
        ax.set_xlim(1e-2, 1e2); ax.set_ylim(1e-1, 4e2)
        ax.set_xlabel("Operational intensity (effectual op / DRAM byte)")
        ax.set_ylabel("Performance (GOP/s)")
        ax.grid(True, which="major", zorder=0)
        ax.minorticks_off()
        FS.panel_tag(ax, tag, y=-0.27)
    h, l = axes[0].get_legend_handles_labels()
    FS.inside_legend(axes[0], h, l, ncol=2, loc="upper left", handlelength=1.0, fontsize=6.5)
    fig.subplots_adjust(left=0.065, right=0.985, top=0.985, bottom=0.28, wspace=0.22)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"roofline.{ext}"))


if __name__ == "__main__":
    main()
