"""
plot_prune_sweep.py -- normalized latency (batch 1) and normalized throughput (batch 16) of every design over the
pruning levels of the six networks, from results/prune_sweep.json (prune_sweep.py). Both are speed-ups over PTB
(PTB cycles / design cycles), one panel per network, x = weight density (firing rate) of each level.

  python3 plot_prune_sweep.py   -> results/prune_sweep_latency.png/.pdf, results/prune_sweep_throughput.png/.pdf,
                                   results/prune_sweep.md; core energy per inference (gate-level core power of the
                                   main results x batch-1 latency; no SRAM / DRAM): results/prune_sweep_energy.png/.pdf
                                   and results/prune_sweep_energy.md
"""
import json, os, sys
import figstyle as FS

plt = FS.plt
HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
ORDER = ["ptb", "spikex", "loas", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "loas": "LoAS", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "TIDES"}
MARK = {"ptb": "s", "spikex": "D", "loas": "^", "sato": "v", "spikeflow": "P", "prosperity": "o", "ours": "*"}
GREY = {"ptb": "#9A9A9A", "spikex": "#7A7A7A", "loas": "#5A5A5A", "sato": "#8A8A8A", "spikeflow": "#6A6A6A",
        "prosperity": "#3A3A3A", "ours": "#000000"}
NETS = ["CifarNet", "ResNet19-tdBN", "ResNet18", "VGGSNN-DVS", "ResNet18-ImageNet", "Spikformer-8-384"]
TITLE = {"CifarNet": "CifarNet (CIFAR-10)", "ResNet19-tdBN": "ResNet-19 (CIFAR-10)", "ResNet18": "ResNet-18 (CIFAR-10)",
         "VGGSNN-DVS": "VGGSNN (DVS-CIFAR10)", "ResNet18-ImageNet": "ResNet-18 (ImageNet)",
         "Spikformer-8-384": "Spikformer-8-384 (ImageNet)"}


# top-1 accuracy (mean +- std, %) of each level, from the same pruning table (Spikformer: no std given)
ACC = {"CifarNet": ["94.42±0.17", "94.42±0.01", "93.60±0.12", "92.46±0.23", "90.76±0.19", "89.25±0.49"],
       "ResNet19-tdBN": ["95.16±0.03", "94.71±0.11", "94.07±0.07", "92.48±0.10", "91.56±0.04", "90.61±0.10"],
       "ResNet18": ["94.43±0.15", "94.11±0.05", "93.73±0.18", "92.93±0.05", "92.38±0.23", "91.04±0.27"],
       "VGGSNN-DVS": ["83.50±0.48", "83.22±0.53", "82.18±0.67", "81.76±0.54", "80.90±0.54", "79.12±0.83"],
       "ResNet18-ImageNet": ["63.78±0.04", "61.89±0.12", "60.95±0.09", "60.58±0.05", "59.66±0.16"],
       "Spikformer-8-384": ["72.97", "72.21", "70.68", "68.29"]}


def tick_labels(n, lv):
    return [f"{e['density']:g}\n({e['firing_rate']:g})\n{a}" for e, a in zip(lv, ACC[n])]


def figure(d, key, ylabel, fname):
    nets = [n for n in NETS if n in d]
    fig, axes = plt.subplots(2, 3, figsize=(FS.TEXT, 4.3))
    for ax, n in zip(axes.flat, nets):
        lv = d[n]["levels"]
        xs = list(range(len(lv)))
        for k in ORDER:
            ys = [e[key]["ptb"] / e[key][k] for e in lv]
            ours = k == "ours"
            ax.plot(xs, ys, marker=MARK[k], ms=6 if ours else 3.5, lw=1.7 if ours else 0.8, color=GREY[k],
                    mfc=GREY[k] if ours else "white", mec=GREY[k], label=NAME[k], zorder=5 if ours else 3)
        ax.set_yscale("log")
        ax.set_xticks(xs, tick_labels(n, lv), fontsize=5)
        ax.set_title(TITLE[n], fontsize=7, fontweight="bold")
        ax.grid(True, which="major", ls=":", lw=0.5, color="#999999")
    for ax in axes.flat[len(nets):]:
        ax.axis("off")
    for ax in axes[:, 0]:
        ax.set_ylabel(ylabel, fontsize=7)
    for ax in axes[-1, :]:
        ax.set_xlabel("Weight density % (firing rate %)\naccuracy %", fontsize=6.5)
    h, l = axes.flat[0].get_legend_handles_labels()
    fig.legend(h, l, loc="upper center", ncol=len(ORDER), frameon=False, fontsize=7, bbox_to_anchor=(0.5, 1.03))
    fig.tight_layout(rect=(0, 0, 1, 0.95), h_pad=0.6, w_pad=0.6)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"{fname}.{ext}"), dpi=300, bbox_inches="tight")
    plt.close(fig)


CLK = 500e6


def core_power():
    """W per design at 500 MHz: the gate-level core power of the main results (hw/same_node_table.core)."""
    sys.path.insert(0, os.path.join(HERE, "hw"))
    import same_node_table as SN
    key = {"loas": "loas_zip"}
    return {k: SN.core(key.get(k, k))[1] for k in ORDER}


def add_energy(d):
    """energy per inference (J) at batch 1: full system (core + SRAM + DRAM) from results/prune_energy.json
    (prune_energy.py) when present, else core only (core power x latency). -> True if full system."""
    path = os.path.join(R, "prune_energy.json")
    full = os.path.exists(path)
    if full:
        pe = json.load(open(path))
        full = all(n in pe for n in d)
    P = None if full else core_power()
    for n in d:
        for lv, e in enumerate(d[n]["levels"]):
            if full:
                ej = pe[n]["levels"][lv]["energy_J"]
                e["energy_parts"] = ej
                e["core_energy_b1"] = {k: sum(ej[k].values()) for k in ORDER}
            elif "cycles_b1" in e:
                e["core_energy_b1"] = {k: P[k] * e["cycles_b1"][k] / CLK for k in ORDER}
    return full


def edp_figure(d):
    """EDP per inference (J x s) at batch 1 = energy x latency, normalized to PTB."""
    nets = [n for n in NETS if n in d]
    fig, axes = plt.subplots(2, 3, figsize=(FS.TEXT, 4.3))
    for ax, n in zip(axes.flat, nets):
        lv = d[n]["levels"]
        xs = list(range(len(lv)))
        for k in ORDER:
            ys = [e["edp_b1"][k] / e["edp_b1"]["ptb"] for e in lv]
            ours = k == "ours"
            ax.plot(xs, ys, marker=MARK[k], ms=6 if ours else 3.5, lw=1.7 if ours else 0.8, color=GREY[k],
                    mfc=GREY[k] if ours else "white", mec=GREY[k], label=NAME[k], zorder=5 if ours else 3)
        ax.set_yscale("log")
        ax.set_xticks(xs, tick_labels(n, lv), fontsize=5)
        ax.set_title(TITLE[n], fontsize=7, fontweight="bold")
        ax.grid(True, which="major", ls=":", lw=0.5, color="#999999")
    for ax in axes.flat[len(nets):]:
        ax.axis("off")
    for ax in axes[:, 0]:
        ax.set_ylabel("Norm. EDP (PTB = 1)", fontsize=7)
    for ax in axes[-1, :]:
        ax.set_xlabel("Weight density % (firing rate %)\naccuracy %", fontsize=6.5)
    h, l = axes.flat[0].get_legend_handles_labels()
    fig.legend(h, l, loc="upper center", ncol=len(ORDER), frameon=False, fontsize=7, bbox_to_anchor=(0.5, 1.03))
    fig.tight_layout(rect=(0, 0, 1, 0.95), h_pad=0.6, w_pad=0.6)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"prune_sweep_edp.{ext}"), dpi=300, bbox_inches="tight")
    plt.close(fig)


def edp_table(d, full):
    lines = [f"# Pruning sweep: EDP per inference (batch 1) = energy x latency, uJ x ms "
             f"({'core + SRAM + DRAM' if full else 'core-only'} energy, 45 nm, 500 MHz)", "",
             "| Network | Level | Weight density % | Firing rate % | Accuracy % | " + " | ".join(NAME[k] for k in ORDER)
             + " | TIDES vs best baseline |", "|---|---|---:|---:|---:|" + "---:|" * len(ORDER) + "---|"]
    for n in NETS:
        if n not in d:
            continue
        for e, a in zip(d[n]["levels"], ACC[n]):
            c = e["edp_b1"]
            best = min((k for k in ORDER if k != "ours"), key=lambda k: c[k])
            lines.append(f"| {n} | {e['label']} | {e['density']:g} | {e['firing_rate']:g} | {a} | "
                         + " | ".join(f"{c[k] * 1e9:,.0f}" for k in ORDER)
                         + f" | {c[best] / c['ours']:.2f}x lower than {NAME[best]} |")
    open(os.path.join(R, "prune_sweep_edp.md"), "w").write("\n".join(lines) + "\n")


def energy_figure(d, full):
    nets = [n for n in NETS if n in d]
    fig, axes = plt.subplots(2, 3, figsize=(FS.TEXT, 4.3))
    for ax, n in zip(axes.flat, nets):
        lv = d[n]["levels"]
        xs = list(range(len(lv)))
        for k in ORDER:
            ys = [e["core_energy_b1"][k] / e["core_energy_b1"]["ptb"] for e in lv]
            ours = k == "ours"
            ax.plot(xs, ys, marker=MARK[k], ms=6 if ours else 3.5, lw=1.7 if ours else 0.8, color=GREY[k],
                    mfc=GREY[k] if ours else "white", mec=GREY[k], label=NAME[k], zorder=5 if ours else 3)
        ax.set_yscale("log")
        ax.set_xticks(xs, tick_labels(n, lv), fontsize=5)
        ax.set_title(TITLE[n], fontsize=7, fontweight="bold")
        ax.grid(True, which="major", ls=":", lw=0.5, color="#999999")
    for ax in axes.flat[len(nets):]:
        ax.axis("off")
    for ax in axes[:, 0]:
        ax.set_ylabel("Norm. energy (PTB = 1)" if full else "Norm. core energy (PTB = 1)", fontsize=7)
    for ax in axes[-1, :]:
        ax.set_xlabel("Weight density % (firing rate %)\naccuracy %", fontsize=6.5)
    h, l = axes.flat[0].get_legend_handles_labels()
    fig.legend(h, l, loc="upper center", ncol=len(ORDER), frameon=False, fontsize=7, bbox_to_anchor=(0.5, 1.03))
    fig.tight_layout(rect=(0, 0, 1, 0.95), h_pad=0.6, w_pad=0.6)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"prune_sweep_energy.{ext}"), dpi=300, bbox_inches="tight")
    plt.close(fig)


def energy_table(d, full):
    head = ("# Pruning sweep: energy per inference (batch 1) = core + on-chip SRAM + DRAM, 45 nm, 500 MHz "
            "(prune_energy.py; the memory models of the main results)" if full else
            "# Pruning sweep: core energy per inference (batch 1) = gate-level core power x latency, 45 nm, 500 MHz")
    note = ("Per design: total uJ (core / SRAM / DRAM in the second table)." if full else
            "Core only: on-chip SRAM and DRAM are not included.")
    lines = [head, "", note, "",
             "| Network | Level | Weight density % | Firing rate % | " + " | ".join(f"{NAME[k]} (uJ)" for k in ORDER)
             + " | TIDES vs PTB | TIDES vs Prosperity |", "|---|---|---:|---:|" + "---:|" * len(ORDER) + "---:|---:|"]
    for n in NETS:
        if n not in d:
            continue
        for e in d[n]["levels"]:
            c = e["core_energy_b1"]
            lines.append(f"| {n} | {e['label']} | {e['density']:g} | {e['firing_rate']:g} | "
                         + " | ".join(f"{c[k] * 1e6:,.1f}" for k in ORDER)
                         + f" | {c['ptb'] / c['ours']:.2f}x less | {c['prosperity'] / c['ours']:.2f}x |")
    if full:
        lines += ["", "## Breakdown: core / SRAM / DRAM (uJ)", "",
                  "| Network | Level | " + " | ".join(NAME[k] for k in ORDER) + " |", "|---|---|" + "---|" * len(ORDER)]
        for n in NETS:
            if n not in d:
                continue
            for e in d[n]["levels"]:
                p = e["energy_parts"]
                lines.append(f"| {n} | {e['label']} | " + " | ".join(
                    "/".join(f"{p[k][x] * 1e6:,.0f}" for x in ("core", "sram", "dram")) for k in ORDER) + " |")
    open(os.path.join(R, "prune_sweep_energy.md"), "w").write("\n".join(lines) + "\n")


def table(d):
    lines = ["# Pruning sweep: speed-up over PTB (normalized latency at batch 1, normalized throughput at batch 16)",
             "", "| Network | Level | Weight density % | Firing rate % | " + " | ".join(NAME[k] for k in ORDER)
             + " | TIDES vs best baseline |", "|---|---|---:|---:|" + "---:|" * len(ORDER) + "---|"]
    for key, tag in (("cycles_b1", "latency"), ("cycles_b16", "throughput")):
        if not all(key in e for n in d for e in d[n]["levels"]):
            continue
        lines.append(f"| **{tag}** | | | |" + " |" * len(ORDER) + " |")
        for n in NETS:
            if n not in d:
                continue
            for e in d[n]["levels"]:
                c = e[key]
                sp = {k: c["ptb"] / c[k] for k in ORDER}
                best = max((k for k in ORDER if k != "ours"), key=lambda k: sp[k])
                lines.append(f"| {n} | {e['label']} | {e['density']:g} | {e['firing_rate']:g} | "
                             + " | ".join(f"{sp[k]:.2f}" for k in ORDER)
                             + f" | {sp['ours'] / sp[best]:.2f}x vs {NAME[best]} |")
    open(os.path.join(R, "prune_sweep.md"), "w").write("\n".join(lines) + "\n")


def main():
    d = json.load(open(os.path.join(R, "prune_sweep.json")))
    have = lambda key: all(key in e for n in d for e in d[n]["levels"])
    if have("cycles_b1"):
        figure(d, "cycles_b1", "Norm. latency (speedup over PTB)", "prune_sweep_latency")
    if have("cycles_b16"):
        figure(d, "cycles_b16", "Norm. throughput (over PTB)", "prune_sweep_throughput")
    table(d)
    full = add_energy(d)
    energy_figure(d, full)
    energy_table(d, full)
    for n in d:
        for e in d[n]["levels"]:
            e["edp_b1"] = {k: e["core_energy_b1"][k] * e["cycles_b1"][k] / CLK for k in ORDER}
    edp_figure(d)
    edp_table(d, full)


if __name__ == "__main__":
    main()
