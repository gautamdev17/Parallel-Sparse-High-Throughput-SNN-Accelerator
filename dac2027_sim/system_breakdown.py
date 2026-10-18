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
            out[f"{n}|{d}"] = dict(t_s=t, power_W=pw, energy_J=en, edp_Js=sum(en.values()) * t, traffic_MB=tr)
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


def _stacked(out, comps, getter, ylab, fname, fmt, hatch_of=None, extra_legend=()):
    import plot_ptb_style as PS
    from matplotlib.patches import Patch
    plt, FS = PS.plt, PS.FS
    fig, ax = plt.subplots(figsize=(FS.TEXT, 2.3))
    xs, labels, top = [], [], 0.0
    for gi, n in enumerate(NETS):
        for i, d in enumerate(ORDER):
            x = gi * (len(ORDER) + 1.2) + i
            xs.append(x); labels.append(NAME[d])
            bot = 0.0
            for key, _, c, co in comps:
                parts = getter(out[f"{n}|{d}"], key)          # list of (value, hatched)
                for v, hat in parts:
                    ax.bar(x, v, 0.72, bottom=bot, color=co if d == "ours" else c, edgecolor=PS.EDGE,
                           linewidth=0.5, hatch="////" if hat else "", zorder=3)
                    bot += v
            top = max(top, bot)
            if d == "ours":
                ax.annotate(fmt(bot), (x, bot), xytext=(0, 2), textcoords="offset points", ha="center",
                            va="bottom", fontsize=6.8, color=FS.OURS_TEXT, zorder=5)
        ax.text(gi * (len(ORDER) + 1.2) + (len(ORDER) - 1) / 2, -0.27, n, transform=ax.get_xaxis_transform(),
                ha="center", va="top", fontsize=8)
    ax.set_xticks(xs, labels, rotation=35, ha="right", fontsize=6.8)
    ax.set_ylim(0, top * 1.28)
    ax.set_ylabel(ylab)
    ax.yaxis.grid(True, zorder=0)
    h = [Patch(facecolor=c, edgecolor=PS.EDGE, linewidth=0.5, label=l) for _, l, c, _ in comps]
    h += [Patch(facecolor="white", edgecolor=PS.EDGE, linewidth=0.5, hatch="////", label=l) for l in extra_legend]
    FS.inside_legend(ax, h, [x.get_label() for x in h], ncol=len(h), loc="upper right")
    fig.subplots_adjust(left=0.07, right=0.995, top=0.985, bottom=0.27)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"{fname}{SFX}.{ext}"))
    plt.close(fig)


def plots(out):
    import plot_ptb_style as PS
    plt, FS = PS.plt, PS.FS
    comps = (("core", "Core", "#4d4d4d", "#a0520a"), ("sram", "SRAM", "#9a9a9a", "#e8871e"),
             ("dram", "DRAM", "#dcdcdc", "#f6c48e"))
    _stacked(out, comps, lambda x, k: [(x["power_W"][k] * 1e3, False)], "Power (mW)", "power_breakdown",
             lambda v: f"{v:.0f}")
    _stacked(out, comps, lambda x, k: [(x["energy_J"][k] * 1e6, False)], "Energy (µJ)", "energy_breakdown",
             lambda v: f"{v:.0f}")
    lv = (("off", "Off-chip", "#dcdcdc", "#f6c48e"), ("on", "On-chip", "#9a9a9a", "#e8871e"),
          ("pe", "PE", "#4d4d4d", "#a0520a"))
    _stacked(out, lv, lambda x, k: [(sum(x["traffic_MB"][k].values()), False)],
             "Traffic (MB)", "traffic_levels", lambda v: f"{v:.0f}")
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


if __name__ == "__main__":
    plots(compute())
