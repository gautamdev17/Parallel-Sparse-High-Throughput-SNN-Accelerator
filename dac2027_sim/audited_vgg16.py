"""
audited_vgg16.py -- VGG-16, CIFAR-10, IF T = 8, the snn-pruning-DAC models (dense / 90 / 95 / 98 %), one chained test
image (prune_chain.py), batch 1: every baseline with a cycle model audited against its own paper (audit/), next to
the simulator used so far, normalized to the paper-faithful PTB. TIDES = RTL cycle-exact (rtl_t4.py, RT_T=8).

Per design and layer (audit/<design>_paper.py, results in audit/*.json):
  PTB         paper: TW = 1 at T = 8 (8 TW columns), one post-synaptic neuron per row, StSAP 1's complement first,
              one fill per layer (audit/ptb_paper.py "paper", compute part); also the official Prosperity-repo model
  SpikeX      current model = the paper's lenient reading (audit/spikex_paper.py; strict reading ~2x more cycles)
  LoAS        paper: the single mapping of the paper (16 pixels share the broadcast weight fibre), fibre-B load
              overlapped with the laggy prefix sum (audit/loas_paper.py "paper")
  SATO        paper, lenient and strict (audit/sato_paper.py: neurons spread over the 128 PEs; strict = 16-neuron waves,
              T-cycle search tree after integration for multi-spike IF)
  SpikeFlow   paper "medium": fill/drain per pass (audit/spikeflow_paper.py)
  Prosperity  official simulator, and its paper's per-tile pipeline (prosperity_paper.py)
Latency per layer at bandwidth B = max(compute cycles, DRAM bits / B), for every design and every B (1024 b/cycle =
64 GB/s at 500 MHz, the official interface). Energy = prune_energy.energy (core x latency + SRAM + DRAM, 45 nm) with
each design's access counts of prune_chain.py and the audited latency; LoAS with its paper-model SRAM / DRAM traffic
and its Table IV "Others" power (crossbars, scheduler, compressor: core x (1 + 18.1 / 46.3)). SRAM: a read costs at
least one full block access, for every design (LoAS per-match 8-bit fetches, TIDES 64-bit weight records).

  python3 audited_vgg16.py        -> results/vgg16_audited_{speedup,energy,edp}.png/.pdf, results/vgg16_audited.md/.json
  python3 audited_vgg16.py plot   -> redraw the figures and tables from results/vgg16_audited.json
"""
import json, os, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, "hw"))
R = os.path.join(HERE, "results")
A = os.path.join(HERE, "audit")
CLK, T = 500e6, 8
LEVELS = ("dense", "sp90", "sp95", "sp98")
BWS = ((1024, "64 GB/s (1024 b/cycle)"), (256, "16 GB/s (256 b/cycle)"), (128, "8 GB/s (128 b/cycle)"))
# (key, label, power/counts of design, dashed)
SERIES = [("ptb_off", "PTB (official sim.)", "ptb", True), ("spikex", "SpikeX", "spikex", False),
          ("loas", "LoAS", "loas", False), ("sato_l", "SATO (paper, lenient)", "sato", False),
          ("sato_s", "SATO (paper, strict)", "sato", True), ("spikeflow", "SpikeFlow (paper)", "spikeflow", False),
          ("pros_off", "Prosperity (official sim.)", "prosperity", True),
          ("pros", "Prosperity (paper pipeline)", "prosperity", False), ("ours", "TIDES", "ours", False)]
# plotted: one line per design, our paper-faithful model (SATO: the lenient reading, the faster one for SATO);
# the official simulators and SATO's strict reading are kept in the tables for reference
PLOT = ("spikex", "loas", "sato_l", "spikeflow", "pros", "ours")
NAME = dict((k, n) for k, n, _, _ in SERIES)
NAME.update(sato_l="SATO", spikeflow="SpikeFlow", pros="Prosperity")
MARK = {"ptb": "s", "spikex": "D", "loas": "^", "sato": "v", "spikeflow": "P", "prosperity": "o", "ours": "*"}
GREY = {"ptb": "#9A9A9A", "spikex": "#7A7A7A", "loas": "#5A5A5A", "sato": "#8A8A8A", "spikeflow": "#6A6A6A",
        "prosperity": "#3A3A3A", "ours": "#000000"}


def layer_cycles():
    """-> {level: [ {series key: compute cycles} per spiking layer ]} and the per-layer DRAM bits / counts."""
    sys.path.insert(0, A)
    import spikeflow_paper as SF
    cache = json.load(open(os.path.join(R, "prune_chain_cache.json")))
    ptb = json.load(open(os.path.join(A, "ptb_paper_results.json")))
    sato = json.load(open(os.path.join(A, "sato_paper_VGG16.json")))
    pros = json.load(open(os.path.join(R, "prosperity_paper_VGG16_T8.json")))
    loas = json.load(open(os.path.join(A, "loas_paper_VGG16.json")))
    # SRAM access granularity (same rule for every design: a logical read costs at least one full block access).
    # Only LoAS and TIDES move reads narrower than their block: LoAS fetches each matched 8-bit value from its
    # 128-bit global cache (paper, per-match fetch; audit/loas_paper.py sram_r_access); TIDES loads 64-bit
    # weight-column records from the 128-bit staging buffer and 127-bit group records from the group buffer
    # (audit/ours_access.py). Every other design reads full rows. -> extra SRAM energy (J) per level.
    import same_node_table as SN
    ca = lambda d, b: [SN.CACTI[f"{blk}|{size}"] for bn, blk, size in SN.SRAM[d][1] if bn == b][0]
    st, gr, lo = ca("ours", "staging"), ca("ours", "group"), ca("loas_zip", "glb")
    oa = json.load(open(os.path.join(A, "ours_access_VGG16.json")))
    out = {}
    for lv in LEVELS:
        meta = json.load(open(os.path.join(R, "prune_chain", f"VGG16_{lv}.json")))["layers"]
        d = np.load(os.path.join(R, "prune_chain", f"VGG16_{lv}.npz"))
        lis = [li for li, m in enumerate(meta) if not m["analog"]]
        rows = []
        for j, li in enumerate(lis):
            c = cache[repr(("VGG16", lv, li))]
            pl = ptb[lv]["layers"][j]
            la = loas[lv]["layers"][j]
            assert pl["name"] == sato[lv][j]["name"] == la["name"] == meta[li]["name"] and la["li"] == li
            W, S = d[f"W{li}"], d[f"S{li}"]
            r = dict(ptb=pl["paper"]["compute"] + pl["paper"]["overhead"], ptb_off=c["cycles"]["ptb"],
                     spikex=c["cycles"]["spikex"], loas=c["cycles"]["loas"],
                     sato_l=sato[lv][j]["paper_lenient"], sato_s=sato[lv][j]["paper_strict"],
                     spikeflow=int(SF.spikeflow_paper_cycles(W, S, T, variant="medium")),
                     pros_off=c["cycles"]["prosperity"], pros=pros[lv][str(li)]["paper_total"],
                     ours=c["cycles"]["ours"])
            r["loas"] = la["paper"]["cycles"]
            counts = dict(c["counts"])
            # LoAS: the paper's single mapping and loop order -> its own SRAM / DRAM traffic (bits)
            counts["loas"] = dict(dram=la["paper"]["dram"], bufs={"glb": (la["paper"]["sram_r"], la["paper"]["sram_w"])})
            rows.append(dict(cyc=r, counts=counts))
        ow = sum(v["oc_w"] for k, v in oa.items() if k.startswith(lv + "|"))
        gr_r = sum(v["oc_a"] - v["rawr"] for k, v in oa.items() if k.startswith(lv + "|"))
        gr_w = sum(v["gw"] for k, v in oa.items() if k.startswith(lv + "|"))
        L = loas[lv]["layers"]
        extra = dict(ours=1e-9 * ((ow / 64 - ow / 128) * st["read_nJ"] + (gr_r / 127 - gr_r / 128) * gr["read_nJ"]
                                  + (gr_w / 127 - gr_w / 128) * gr["write_nJ"]),
                     loas=1e-9 * (sum(l["paper"]["sram_r_access"] for l in L)
                                  - sum(l["paper"]["sram_r"] for l in L) / 128) * lo["read_nJ"])
        out[lv] = dict(rows=rows, sram_extra=extra)
    return out


def evaluate(level, bw):
    """level -> {series: (latency s, energy J, parts)} at DRAM bandwidth bw (bits / cycle)."""
    import prune_energy as PE
    rows = level["rows"]
    acc = {}
    for r in rows:
        PE.add(acc, r["counts"])
    keys = ["ptb"] + [k for k, _, _, _ in SERIES]
    dram_of = lambda k: dict(ptb="ptb", ptb_off="ptb", sato_l="sato", sato_s="sato", pros="prosperity",
                             pros_off="prosperity").get(k, k)
    cyc = {k: sum(max(r["cyc"][k], r["counts"][dram_of(k)]["dram"] / bw) for r in rows) for k in keys}
    res = {}
    for k in keys:
        d = dram_of(k)
        e = dict(PE.energy(acc, {x: (cyc[k] if x == d else cyc.get(x, 1)) for x in PE.DESIGNS})[d])
        if d == "loas":                          # LoAS Table IV: "Others" 18.1 mW next to 46.3 mW of TPPEs
            e["core"] *= 1 + 18.1 / 46.3
        e["sram"] += level["sram_extra"].get(d, 0.0)
        res[k] = (cyc[k] / CLK, sum(e.values()), e)
    return res


def main():
    import figstyle as FS
    plt = FS.plt
    acc = {lv: json.load(open(os.path.join(R, "prune_chain", f"VGG16_{lv}.json")))["acc"] for lv in LEVELS}
    saved = os.path.join(R, "vgg16_audited.json")
    if sys.argv[1:] == ["plot"] and os.path.exists(saved):     # redraw from the last evaluation
        j = json.load(open(saved))
        tab = {bw: {lv: {k: (v["latency_s"], v["energy_J"], v["parts_J"]) for k, v in j[str(bw)][lv].items()}
                    for lv in LEVELS} for bw, _ in BWS}
    else:
        L = layer_cycles()
        tab = {bw: {lv: evaluate(L[lv], bw) for lv in LEVELS} for bw, _ in BWS}
    metrics = (("speedup", "Speedup over PTB (paper model)", lambda r, k: r["ptb"][0] / r[k][0]),
               ("energy", "Energy (PTB paper model = 1)", lambda r, k: r[k][1] / r["ptb"][1]),
               ("edp", "EDP (PTB paper model = 1)", lambda r, k: r[k][0] * r[k][1] / (r["ptb"][0] * r["ptb"][1])))
    lab = {"dense": "dense", "sp90": "90", "sp95": "95", "sp98": "98"}
    lines = ["# VGG-16, IF T = 8, snn-pruning-DAC dense/90/95/98 %: baselines audited against their papers "
             "(audited_vgg16.py)", "",
             "Normalized to the paper-faithful PTB. TIDES RTL cycle-exact. Batch 1, 500 MHz, 45 nm. Speed-up: higher is "
             "better; energy, EDP: lower is better. 'official sim.' = the models used before the audit.", ""]
    for key, ylabel, f in metrics:
        fig, axes = plt.subplots(1, len(BWS), figsize=(FS.TEXT, 2.4), sharey=True)
        for ax, (bw, title) in zip(axes, BWS):
            ax.axhline(1, ls="--", lw=0.8, color=GREY["ptb"], zorder=2,
                       label="PTB" if bw == BWS[0][0] else None)
            for k, name, d, dashed in [x for x in SERIES if x[0] in PLOT]:
                name = NAME[k]
                ys = [f(tab[bw][lv], k) for lv in LEVELS]
                o = k == "ours"
                ax.plot(range(4), ys, marker=MARK[d], ms=6 if o else 3.2, lw=1.7 if o else 0.8, color=GREY[d],
                        ls="-", mfc=GREY[d] if o else "white", mec=GREY[d], label=name,
                        zorder=5 if o else 3)
            ax.set_yscale("log")
            ax.set_xticks(range(4), [f"{lab[lv]}\n{acc[lv]:.2f}" for lv in LEVELS], fontsize=6)
            ax.set_title(f"DRAM {title}", fontsize=7)
            ax.set_xlabel("Weight sparsity %\nIF T = 8 accuracy %", fontsize=6.5)
            ax.grid(True, which="major", ls=":", lw=0.5, color="#999999")
        axes[0].set_ylabel(ylabel, fontsize=7)
        h, l = axes[0].get_legend_handles_labels()
        fig.legend(h, l, loc="upper center", ncol=7, frameon=False, fontsize=6.5, bbox_to_anchor=(0.5, 1.06))
        fig.tight_layout(rect=(0, 0, 1, 0.93), w_pad=0.6)
        for ext in ("png", "pdf"):
            fig.savefig(os.path.join(R, f"vgg16_audited_{key}.{ext}"), dpi=300, bbox_inches="tight")
        plt.close(fig)
        for bw, title in BWS:
            lines += [f"## {ylabel}, DRAM {title}", "", "| Level | Acc % | " + " | ".join(n for _, n, _, _ in SERIES)
                      + " | Best (paper models) |", "|---|---:|" + "---:|" * len(SERIES) + "---|"]
            for lv in LEVELS:
                v = {k: f(tab[bw][lv], k) for k, _, _, _ in SERIES}
                cand = [k for k in v if k not in ("ptb_off", "pros_off")]
                best = (max if key == "speedup" else min)(cand, key=lambda k: v[k])
                lines.append(f"| {lab[lv]} | {acc[lv]:.2f} | " + " | ".join(
                    (f"**{v[k]:.3f}**" if k == best else f"{v[k]:.3f}") for k, _, _, _ in SERIES)
                             + f" | {dict((k, n) for k, n, _, _ in SERIES)[best]} |")
            lines.append("")
    open(os.path.join(R, "vgg16_audited.md"), "w").write("\n".join(lines) + "\n")
    json.dump({str(bw): {lv: {k: dict(latency_s=v[0], energy_J=v[1], parts_J=v[2]) for k, v in tab[bw][lv].items()}
                         for lv in LEVELS} for bw, _ in BWS},
              open(os.path.join(R, "vgg16_audited.json"), "w"), indent=1)


if __name__ == "__main__":
    main()
