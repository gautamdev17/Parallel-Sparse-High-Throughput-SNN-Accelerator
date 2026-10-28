"""
plot_lm_mem.py -- BERT on one real sentence (layer-chained spikes), latency per sentence vs weight sparsity with DRAM
traffic and weight reuse modelled for every design (lm_mem.py), at three common DRAM interfaces: 1024, 256 and 128
bits/cycle (64, 16 and 8 GB/s at 500 MHz).

  python3 plot_lm_mem.py   -> results/lm_bert_mem.png/.pdf
"""
import json, os
import figstyle as FS
from plot_lm_sweep import ORDER, NAME, MARK, GREY, CLK

plt = FS.plt
HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
PANELS = [("lm_chain_real_mem.json", "(a) DRAM 64 GB/s"), ("lm_chain_real_mem_bw256.json", "(b) DRAM 16 GB/s"),
          ("lm_chain_real_mem_bw128.json", "(c) DRAM 8 GB/s")]


def main():
    fig, axes = plt.subplots(1, 3, figsize=(FS.TEXT, 2.3), sharey=True)
    for ax, (f, title) in zip(axes, PANELS):
        pts = sorted(json.load(open(os.path.join(R, f)))["BERT"]["points"].items(), key=lambda kv: float(kv[0]))
        xs = list(range(len(pts)))
        for k in ORDER:
            ys = [v["cycles"][k] / CLK * 1e3 for _, v in pts]
            ours = k == "ours"
            ax.plot(xs, ys, marker=MARK[k], ms=6 if ours else 3.5, lw=1.7 if ours else 0.9, color=GREY[k],
                    mfc=GREY[k] if ours else "white", mec=GREY[k], label=NAME[k], zorder=5 if ours else 3)
        ax.set_yscale("log")
        ax.set_xticks(xs, [f"{100 * float(w):g}" for w, _ in pts], fontsize=6.5)
        ax.set_xlabel("Weight sparsity (%)", fontsize=7)
        ax.set_title(title, fontsize=7.5, fontweight="bold")
        ax.grid(True, which="major", ls=":", lw=0.6, color="#999999")
    axes[0].set_ylabel("Latency per sentence (ms)")
    h, l = axes[0].get_legend_handles_labels()
    fig.legend(h, l, loc="upper center", ncol=len(ORDER), frameon=False, fontsize=7, bbox_to_anchor=(0.5, 1.05))
    fig.tight_layout(rect=(0, 0, 1, 0.91), w_pad=0.5)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"lm_bert_mem.{ext}"), dpi=300, bbox_inches="tight")


if __name__ == "__main__":
    main()
