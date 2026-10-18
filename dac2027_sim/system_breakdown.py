"""
system_breakdown.py -- power -> energy -> EDP per design, each split into core / SRAM / DRAM, and the data traffic of
every design at three levels (off-chip, on-chip, PE), each split into weights / activations / partial sums.
All designs at 45 nm, 500 MHz, workload sparse90, per image at batch 16 (steady state).

Power (W), averaged over the run (t = time per image = cycles_b16 / 16 / 500 MHz):
  core = gate-level power of our RTL of the design (hw/same_node_table.core)
  SRAM = CACTI 45 nm LSTP/LOP leakage + read/write energy per image / t   (hw/same_node_table.sram)
  DRAM = 12.45 pJ/bit x DRAM traffic per image / t                         (hw/same_node_table.dram_J)
Energy per image = power x t;  EDP = energy per image x t.

Traffic per image (bits -> MB):
  off-chip  DRAM reads + writes (results/mem_traffic_*.json at batch 16; output spikes count as activations)
  on-chip   every SRAM read and write: the same access counts that set the SRAM energy
            (hw/same_node_table.sram_access_bits; reads from mem_levels.py, writes = DRAM fills + output spikes,
            ours: + group buffer and the output buffer's read-modify-writes; Prosperity: its simulator's counters)
  PE        bits entering a PE from outside it (buffer, broadcast or a neighbouring PE), mem_levels.py; partial sums:
            ours = the F x G x T running-sum bundle passed down each column (ours_core.v), Prosperity = prefix
            partial sums read from its psum buffer; the output-stationary designs keep sums inside the PE (0).

  python3 system_breakdown.py   -> results/system_breakdown.md/.json, power_breakdown, energy_breakdown, edp,
                                   traffic_levels (.png/.pdf)
"""
import json, os, sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, "hw"))
R = os.path.join(HERE, "results")
NETS = ("VGG16", "ResNet18")
ORDER = ["ptb", "spikex", "loas_zip", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "loas_zip": "LoAS", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "Ours"}
CLK = 500e6
B = int(os.environ.get("SNB", 16))                 # 16: per image at batch 16; 1: batch-1 inference
SFX = "" if B == 16 else f"_b{B}"
MBb = 8e6


def compute():
    import same_node_table as SN
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    own = json.load(open(os.path.join(R, "loas_own.json")))
    lv = {}
    for f in ("base", "sato", "prosperity"):
        lv.update(json.load(open(os.path.join(R, f"mem_levels_{f}{SN.LVS}.json"))))
    lv.update(json.load(open(os.path.join(R, "mem_levels_ptb.json"))))
    off = json.load(open(os.path.join(R, "mem_traffic_base.json")))
    off.update(json.load(open(os.path.join(R, "mem_traffic_prosperity.json"))))
    out = {}
    for d in ORDER:
        _, p_core = SN.core(d)
        for n in NETS:
            cyc = own[f"sparse90|{n}|{B}"] if d == "loas_zip" else s[f"{n}|{d}"][f"cycles_b{B}"]
            t = cyc / CLK / B
            _, leak, edyn = SN.sram(d, n)
            edram = SN.dram_J(d, n)
            pw = dict(core=p_core, sram=leak + edyn / t, dram=edram / t)
            en = {k: v * t for k, v in pw.items()}
            # traffic, bits per image
            o = off[f"{n}|{B}|{d}"]
            offc = dict(wgt=o["wgt_MB"] * MBb, act=(o["act_MB"] + o["out_MB"]) * MBb, psum=0.0)
            r = lv[f"{n}|{d}"]
            acc = SN.sram_access_bits(d, n)
            if d == "prosperity":
                onc = dict(wgt=sum(acc["g_wgt"]), act=sum(acc["g_act"]), psum=sum(acc["g_psum"]))
                pe = dict(wgt=r["pe_wgt_MB"] * MBb, act=0.0, psum=acc["g_psum"][0])
            elif d == "ours":
                onc = dict(wgt=r["onchip_wgt_MB"] * MBb + o["wgt_MB"] * MBb,
                           act=sum(acc["staging"]) - r["onchip_wgt_MB"] * MBb - o["wgt_MB"] * MBb + sum(acc["group"]),
                           psum=sum(acc["obuf"]))
                pe = dict(wgt=r["pe_wgt_MB"] * MBb, act=r["pe_act_MB"] * MBb, psum=r["pe_psum_MB"] * MBb)
            else:
                onc = dict(wgt=(r["onchip_wgt_MB"] + o["wgt_MB"]) * MBb,
                           act=(r["onchip_act_MB"] + o["act_MB"] + o["out_MB"]) * MBb, psum=0.0)
                assert abs(onc["wgt"] + onc["act"] - sum(acc["glb"])) < 1e-3 * sum(acc["glb"])
                pe = dict(wgt=r["pe_wgt_MB"] * MBb, act=r["pe_act_MB"] * MBb, psum=0.0)
            tr = {lvl: {k: v / MBb for k, v in x.items()} for lvl, x in (("off", offc), ("on", onc), ("pe", pe))}
            out[f"{n}|{d}"] = dict(t_s=t, power_W=pw, energy_J=en, edp_Js=sum(en.values()) * t, traffic_MB=tr,
                                   dram_MB=dict(wgt=o["wgt_MB"], act=o["act_MB"], out=o["out_MB"]))
    json.dump(out, open(os.path.join(R, f"system_breakdown{SFX}.json"), "w"), indent=1)
    L = [f"# Power -> energy -> EDP and three-level traffic (45 nm, 500 MHz, sparse90, per image at batch {B})", "",
         "See system_breakdown.py for every rule. EDP = energy per image x time per image.", "",
         "| Network | Design | Time/img (ms) | Power core / SRAM / DRAM (mW) | Energy core / SRAM / DRAM (uJ) | "
         "EDP (uJ*ms) | Off-chip wgt / act (MB) | On-chip wgt / act / psum (MB) | PE wgt / act / psum (MB) |",
         "|---|---|---:|---:|---:|---:|---:|---:|---:|"]
    for n in NETS:
        for d in ORDER:
            x = out[f"{n}|{d}"]
            p, e, tr = x["power_W"], x["energy_J"], x["traffic_MB"]
            L.append(f"| {n} | {NAME[d]} | {x['t_s'] * 1e3:.3f} | "
                     f"{p['core'] * 1e3:.0f} / {p['sram'] * 1e3:.0f} / {p['dram'] * 1e3:.0f} | "
                     f"{e['core'] * 1e6:.0f} / {e['sram'] * 1e6:.0f} / {e['dram'] * 1e6:.0f} | "
                     f"{x['edp_Js'] * 1e9:.0f} | {tr['off']['wgt']:.2f} / {tr['off']['act']:.2f} | "
                     f"{tr['on']['wgt']:.1f} / {tr['on']['act']:.1f} / {tr['on']['psum']:.1f} | "
                     f"{tr['pe']['wgt']:.1f} / {tr['pe']['act']:.1f} / {tr['pe']['psum']:.1f} |")
    open(os.path.join(R, f"system_breakdown{SFX}.md"), "w").write("\n".join(L) + "\n")
    print("\n".join(L))
    return out


PALETTES = {   # bottom, middle, top (top is hatched, PTB Fig. 10 style); same colours for every design
    "grey": ("#111111", "#8C8C8C", "#FFFFFF"),
    "slate": ("#2B2D42", "#8D99AE", "#EDF2F4"),
    "teal": ("#1D3557", "#457B9D", "#A8DADC"),
    "terracotta": ("#3D405B", "#E07A5F", "#F2CC8F"),
    "okabe": ("#0B3C5D", "#328CC1", "#F2B134"),
}
PAL = os.environ.get("STACK_PAL", "grey")


def _stacked(out, comps, getter, ylab, fname, pal=None):
    """PTB Fig. 10 style: normalized stacked bars (PTB total = 1), one panel per network, bold axis labels, dotted
    grid, framed legend outside on the right listing the top component first; the top component is hatched; every
    design uses the same component colours and ours is marked by a bold label and its value."""
    import plot_ptb_style as PS
    from matplotlib.patches import Patch
    plt, FS = PS.plt, PS.FS
    cols = PALETTES[pal or PAL]
    hatches = ("", "", "////")
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.1))
    top = 0.0
    for ax, n, tag in ((axes[0], NETS[0], "(a) VGG16"), (axes[1], NETS[1], "(b) ResNet18")):
        ref = sum(getter(out[f"{n}|ptb"], k) for k, _ in comps)
        for i, d in enumerate(ORDER):
            bot = 0.0
            for j, (key, _) in enumerate(comps):
                v = getter(out[f"{n}|{d}"], key) / ref
                ax.bar(i, v, 0.5, bottom=bot, color=cols[j], edgecolor="#111111", linewidth=0.6, hatch=hatches[j],
                       zorder=3)
                bot += v
            top = max(top, bot)
            if d == "ours":
                ax.annotate(f"{bot:.3f}" if bot < 0.1 else f"{bot:.2f}", (i, bot), xytext=(0, 2),
                            textcoords="offset points", ha="center", va="bottom", fontsize=7, fontweight="bold",
                            color="#111111", zorder=5)
        ax.set_xticks(range(len(ORDER)), [NAME[d] for d in ORDER], rotation=40, ha="right", fontsize=6.8,
                      fontweight="bold")
        ax.get_xticklabels()[ORDER.index("ours")].set_fontsize(7.6)
        ax.set_xlim(-0.6, len(ORDER) - 0.4)
        ax.set_ylabel(ylab, fontweight="bold")
        for t in ax.get_yticklabels():
            t.set_fontweight("bold")
        ax.yaxis.grid(True, ls=":", lw=0.6, color="#777777", zorder=0)
        ax.xaxis.grid(False)
        FS.panel_tag(ax, tag, y=-0.42)
    for ax in axes:
        ax.set_ylim(0, top * 1.08)
    h = [Patch(facecolor=cols[j], edgecolor="#111111", linewidth=0.6, hatch=hatches[j], label=l)
         for j, (_, l) in enumerate(comps)][::-1]
    lg = fig.legend(h, [x.get_label() for x in h], loc="center right", frameon=True, fancybox=False,
                    edgecolor="#111111", fontsize=7, handlelength=1.6, handleheight=1.0, borderpad=0.4,
                    labelspacing=0.35, prop={"weight": "bold", "size": 7})
    lg.get_frame().set_linewidth(0.6)
    # leave exactly the legend's width (+ a gap) on the right, so the legend never overlaps a panel
    fig.canvas.draw()
    lw = lg.get_window_extent().width / fig.bbox.width
    fig.subplots_adjust(left=0.065, right=0.985 - lw - 0.015, top=0.97, bottom=0.33, wspace=0.26)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"{fname}{SFX}.{ext}"))
    plt.close(fig)


def plots(out):
    import plot_ptb_style as PS
    plt, FS = PS.plt, PS.FS
    comps = (("dram", "DRAM"), ("sram", "SRAM"), ("core", "Core"))
    _stacked(out, comps, lambda x, k: x["power_W"][k], "Normalized power", "power_breakdown")
    _stacked(out, comps, lambda x, k: x["energy_J"][k], "Normalized energy", "energy_breakdown")
    _stacked(out, (("off", "Off-chip"), ("on", "On-chip"), ("pe", "PE")),
             lambda x, k: sum(x["traffic_MB"][k].values()), "Normalized traffic", "traffic_levels")
    _stacked(out, comps, lambda x, k: x["energy_J"][k] * x["t_s"], "Normalized EDP", "edp_breakdown")
    _stacked(out, (("wgt", "Weights"), ("act", "Input spikes"), ("out", "Output spikes")),
             lambda x, k: x["dram_MB"][k], "Normalized DRAM traffic", "dram_breakdown")
    # EDP: totals, log scale (spans > 100x), designs in their usual styles
    import numpy as np
    fig, ax = plt.subplots(figsize=(FS.COL, 2.0))
    w = 0.112
    for i, d in enumerate(ORDER):
        x = np.arange(2) + (i - (len(ORDER) - 1) / 2) * (w + 0.008)
        v = [out[f"{n}|{d}"]["edp_Js"] * 1e9 for n in NETS]      # uJ * ms
        st = PS.STYLE[d]
        ax.bar(x, v, w, color=st["color"], hatch=st["hatch"], edgecolor=PS.EDGE, linewidth=0.5, label=NAME[d],
               zorder=3)
        if d == "ours":
            for xi, vi in zip(x, v):
                ax.annotate(f"{vi:.0f}", (xi, vi), xytext=(0, 2), textcoords="offset points", ha="center",
                            va="bottom", fontsize=6.5, rotation=90, color=FS.OURS_TEXT, zorder=5)
    ax.set_yscale("log")
    ax.set_ylim(1e2, 3e6)
    ax.set_xticks(range(2), NETS)
    ax.set_xlim(-0.55, 1.55)
    ax.set_ylabel("EDP (µJ·ms)")
    ax.yaxis.grid(True, zorder=0)
    ax.minorticks_off()
    h, l = ax.get_legend_handles_labels()
    FS.inside_legend(ax, h, l, ncol=4, loc="upper center", fontsize=6)
    fig.subplots_adjust(left=0.16, right=0.99, top=0.985, bottom=0.13)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"edp{SFX}.{ext}"))
    plt.close(fig)


def perf_plot():
    """speed-up (latency, batch 1) and throughput (batch 16) over PTB, PTB greyscale style, paper array sizes."""
    import numpy as np
    import plot_ptb_style as PS
    from matplotlib.patches import Patch
    plt, FS = PS.plt, PS.FS
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    own = json.load(open(os.path.join(R, "loas_own.json")))
    cyc = lambda n, d, b: own[f"sparse90|{n}|{b}"] if d == "loas_zip" else s[f"{n}|{d}"][f"cycles_b{b}"]
    sty = (("#111111", ""), ("#FFFFFF", "////"))
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.1))
    w = 0.36
    for ax, b, ylab, tag in ((axes[0], 1, "Speedup over PTB", "(a) Latency (batch 1)"),
                             (axes[1], 16, "Throughput over PTB", "(b) Throughput (batch 16)")):
        top = 0
        for j, n in enumerate(NETS):
            v = [cyc(n, "ptb", b) / cyc(n, d, b) for d in ORDER]
            x = np.arange(len(ORDER)) + (j - 0.5) * w
            ax.bar(x, v, w, color=sty[j][0], hatch=sty[j][1], edgecolor="#111111", linewidth=0.6, zorder=3)
            top = max(top, max(v))
            k = ORDER.index("ours")
            ax.annotate(f"{v[k]:.1f}×", (x[k], v[k]), xytext=(0, 2), textcoords="offset points", ha="center",
                        va="bottom", fontsize=6.6, fontweight="bold", rotation=90, zorder=5)
        ax.axhline(1.0, color="#111111", lw=0.6, ls=(0, (4, 2)), zorder=4)
        ax.set_xticks(range(len(ORDER)), [NAME[d] for d in ORDER], rotation=40, ha="right", fontsize=6.8,
                      fontweight="bold")
        ax.get_xticklabels()[ORDER.index("ours")].set_fontsize(7.6)
        ax.set_xlim(-0.6, len(ORDER) - 0.4)
        ax.set_ylim(0, top * 1.22)
        ax.set_ylabel(ylab, fontweight="bold")
        for t in ax.get_yticklabels():
            t.set_fontweight("bold")
        ax.yaxis.grid(True, ls=":", lw=0.6, color="#777777", zorder=0)
        ax.xaxis.grid(False)
        FS.panel_tag(ax, tag, y=-0.42)
    h = [Patch(facecolor=sty[j][0], hatch=sty[j][1], edgecolor="#111111", linewidth=0.6, label=n)
         for j, n in enumerate(NETS)]
    lg = fig.legend(h, list(NETS), loc="center right", frameon=True, fancybox=False, edgecolor="#111111",
                    handlelength=1.6, handleheight=1.0, borderpad=0.4, labelspacing=0.35,
                    prop={"weight": "bold", "size": 7})
    lg.get_frame().set_linewidth(0.6)
    fig.canvas.draw()
    lw = lg.get_window_extent().width / fig.bbox.width
    fig.subplots_adjust(left=0.065, right=0.985 - lw - 0.015, top=0.97, bottom=0.33, wspace=0.26)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"speedup_throughput.{ext}"))
    plt.close(fig)


if __name__ == "__main__":
    plots(compute())
    perf_plot()
