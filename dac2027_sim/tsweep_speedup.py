"""
tsweep_speedup.py -- VGG-16, CIFAR-10, IF neuron, snn-pruning-DAC dense / 90 / 95 / 98 %: speed-up over PTB at
T = 4, 8, 16, 32, DRAM 64 GB/s (1024 b/cycle at 500 MHz), batch 1. The same models as audited_vgg16.py, per T:

  traces      prune_chain.py spikes at PC_T = T (eval.json if_T<T>: per-layer W, A; one chained test image)
  PTB         audit/ptb_paper.py "paper" (TW = max(1, T / 8) on the 8 columns, StSAP, one fill per layer)
  SpikeX      prune_chain.py cache (current model = the paper's lenient reading)
  LoAS        audit/loas_paper.py "paper" (cycles and its own DRAM traffic)
  SATO        audit/sato_paper.py: max(loop-nest int_S, T-step tree bast_T)
  SpikeFlow   prune_chain.py cache
  Prosperity  prosperity_own_correct_final.py "paper_total" (per-tile pipeline >= m + 4)
  TIDES       prune_chain.py cache (ours.run_layer_fast, Cfg(T = T), RTL cycle-exact)
Latency per layer = max(compute cycles, DRAM bits / 1024), DRAM bits of prune_chain.py's cache (LoAS: its paper
model's), as audited_vgg16.evaluate.

  python3 tsweep_speedup.py        -> results/tsweep_speedup_VGG16.json/.md, results/tsweep_speedup_VGG16.png/.pdf
  python3 tsweep_speedup.py plot   -> redraw from the json
"""
import json, os, sys
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, "audit"))
R = os.path.join(HERE, "results")
TS = tuple(int(x) for x in os.environ.get("TS_T", "4,8,16,32").split(","))
LEVELS = ("dense", "sp90", "sp95", "sp98")
BW = 1024
OUT = os.path.join(R, "tsweep_speedup_VGG16")
DESIGNS = ("ptb", "spikex", "loas", "sato", "spikeflow", "pros", "ours")
NAME = dict(ptb="PTB", spikex="SpikeX", loas="LoAS", sato="SATO", spikeflow="SpikeFlow", pros="Prosperity",
            ours="TIDES")
MARK = dict(ptb="s", spikex="D", loas="^", sato="v", spikeflow="P", pros="o", ours="*")
GREY = dict(ptb="#9A9A9A", spikex="#7A7A7A", loas="#5A5A5A", sato="#8A8A8A", spikeflow="#6A6A6A", pros="#3A3A3A",
            ours="#000000")
DRAM_OF = dict(ptb="ptb", spikex="spikex", sato="sato", spikeflow="spikeflow", pros="prosperity", ours="ours")


def sd(T):
    return os.path.join(R, "prune_chain" if T == 8 else f"prune_chain_T{T}")


def audit_layer(a):
    """(T, level, layer index, raw_next) -> paper-model cycles of PTB, SATO and LoAS (+ LoAS DRAM bits)."""
    T, lv, li, raw_next = a
    import ptb_paper as PP, sato_paper as SP, loas_paper as LP
    LP.T = T
    d = np.load(os.path.join(sd(T), f"VGG16_{lv}.npz"))
    meta = json.load(open(os.path.join(sd(T), f"VGG16_{lv}.json")))["layers"][li]
    W, S = d[f"W{li}"].astype(np.int16), d[f"S{li}"]
    p = PP.ptb_paper_cycles(W, S, T, meta, "paper")
    s = SP.sato_paper(W, S, T)
    lo = LP.layer(W, S, raw_next)["paper"]
    return a[:3], dict(ptb=p["compute"] + p["overhead"], sato=max(s["int_S"], s["bast_T"]), loas=lo["cycles"],
                       loas_dram=lo["dram"])


def evaluate():
    todo = []
    for T in TS:
        for lv in LEVELS:
            meta = json.load(open(os.path.join(sd(T), f"VGG16_{lv}.json")))["layers"]
            for li, m in enumerate(meta):
                if m["analog"]:
                    continue
                nxt = next((x for x in meta[li + 1:] if not x["analog"]), None)
                raw_next = nxt["raw_nz"] if (nxt is not None and nxt["raw_n"] == m["M"] * m["N"]) else None
                todo.append((T, lv, li, raw_next))
    cp = os.path.join(R, "tsweep_audit_cache.json")                    # per-layer paper-model results
    ac = json.load(open(cp)) if os.path.exists(cp) else {}
    todo = [a for a in todo if repr(a[:3]) not in ac]
    todo.sort(key=lambda a: -a[0])                                     # largest T first
    with Pool(int(os.environ.get("TS_WORKERS", 8))) as pool:
        for key, r in pool.imap_unordered(audit_layer, todo):
            ac[repr(key)] = r
            json.dump(ac, open(cp, "w"))
    aud = {eval(k): v for k, v in ac.items()}
    out = {}
    for T in [T for T in TS if os.path.exists(os.path.join(R, f"prosperity_own_correct_final_VGG16_T{T}.json"))]:
        cache = json.load(open(os.path.join(R, "prune_chain_cache.json" if T == 8 else f"prune_chain_T{T}_cache.json")))
        pros = json.load(open(os.path.join(R, f"prosperity_own_correct_final_VGG16_T{T}.json")))
        for lv in LEVELS:
            info = json.load(open(os.path.join(sd(T), f"VGG16_{lv}.json")))
            lat = dict.fromkeys(DESIGNS, 0.0)
            for li, m in enumerate(info["layers"]):
                if m["analog"]:
                    continue
                c, a = cache[repr(("VGG16", lv, li))], aud[(T, lv, li)]
                cyc = dict(ptb=a["ptb"], spikex=c["cycles"]["spikex"], loas=a["loas"], sato=a["sato"],
                           spikeflow=c["cycles"]["spikeflow"], pros=pros[lv][str(li)]["paper_total"],
                           ours=c["cycles"]["ours"])
                for k in DESIGNS:
                    dram = a["loas_dram"] if k == "loas" else c["counts"][DRAM_OF[k]]["dram"]
                    lat[k] += max(cyc[k], dram / BW)
            out.setdefault(str(T), {})[lv] = dict(acc=info["acc"], latency_s={k: v / 500e6 for k, v in lat.items()})
    json.dump(out, open(OUT + ".json", "w"), indent=1)
    return out


def plot(out):
    import figstyle as FS
    plt = FS.plt
    lab = {"dense": "dense", "sp90": "90", "sp95": "95", "sp98": "98"}
    sp = {T: {lv: {k: out[str(T)][lv]["latency_s"]["ptb"] / out[str(T)][lv]["latency_s"][k] for k in DESIGNS}
              for lv in LEVELS} for T in TS}
    fig, axes = plt.subplots(1, len(TS), figsize=(FS.TEXT, 2.4), sharey=True)
    for ax, T in zip(axes, TS):
        ax.axhline(1, ls="--", lw=0.8, color=GREY["ptb"], zorder=2, label="PTB")
        for k in DESIGNS[1:]:
            o = k == "ours"
            ax.plot(range(4), [sp[T][lv][k] for lv in LEVELS], marker=MARK[k], ms=6 if o else 3.2,
                    lw=1.7 if o else 0.8, color=GREY[k], mfc=GREY[k] if o else "white", mec=GREY[k], label=NAME[k],
                    zorder=5 if o else 3)
        ax.set_yscale("log")
        ax.set_xticks(range(4), [f"{lab[lv]}\n{out[str(T)][lv]['acc']:.2f}" for lv in LEVELS], fontsize=6)
        ax.set_title(f"T = {T}", fontsize=7)
        ax.set_xlabel(f"Weight sparsity %\nIF T = {T} accuracy %", fontsize=6.5)
        ax.grid(True, which="major", ls=":", lw=0.5, color="#999999")
    axes[0].set_ylabel("Speedup over PTB", fontsize=7)
    h, l = axes[0].get_legend_handles_labels()
    fig.tight_layout(rect=(0, 0, 1, 0.86), w_pad=0.6)
    fig.legend(h, l, loc="upper center", ncol=7, frameon=False, fontsize=6.5, bbox_to_anchor=(0.5, 0.95))
    fig.suptitle("VGG-16, CIFAR-10, IF, DRAM 64 GB/s, batch 1", fontsize=7, y=1.0)
    for ext in ("png", "pdf"):
        fig.savefig(OUT + f".{ext}", dpi=300, bbox_inches="tight")
    plt.close(fig)
    lines = ["# VGG-16, CIFAR-10, IF: speed-up over PTB at T = 4 / 8 / 16 / 32, DRAM 64 GB/s, batch 1 "
             "(tsweep_speedup.py)", "",
             "Models as audited_vgg16.py at every T. Latency per layer = max(compute, DRAM bits / 1024 b per cycle).", ""]
    for T in TS:
        lines += [f"## T = {T}", "", "| Level | Acc % | PTB latency (ms) | " + " | ".join(NAME[k] for k in DESIGNS[1:])
                  + " | Best |", "|---|---:|---:|" + "---:|" * (len(DESIGNS) - 1) + "---|"]
        for lv in LEVELS:
            v = sp[T][lv]
            best = max(DESIGNS[1:], key=lambda k: v[k])
            lines.append(f"| {lab[lv]} | {out[str(T)][lv]['acc']:.2f} | {out[str(T)][lv]['latency_s']['ptb'] * 1e3:.3f} | "
                         + " | ".join(f"**{v[k]:.2f}**" if k == best else f"{v[k]:.2f}" for k in DESIGNS[1:])
                         + f" | {NAME[best]} |")
        lines.append("")
    open(OUT + ".md", "w").write("\n".join(lines) + "\n")


if __name__ == "__main__":
    plot(json.load(open(OUT + ".json")) if sys.argv[1:] == ["plot"] else evaluate())
