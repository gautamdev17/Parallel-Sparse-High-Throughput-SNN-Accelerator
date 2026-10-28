"""
plot_lm_bounds.py -- BERT on one real sentence (lm_chain.py, LMC_REAL=1), latency per sequence vs weight sparsity,
for the two bounds of how activation sparsity follows pruning:
  (a) BN re-estimated for each pruned model (results/lm_chain_real.json): activation sparsity stays ~79-81 %
  (b) BN frozen at the dense model's statistics (results/lm_chain_real_bnfrozen.json): pruning lowers the currents,
      activation sparsity rises (76 % -> 99.7 %)
The activation sparsity of each point is printed under the x tick.

  python3 plot_lm_bounds.py   -> results/lm_bert_bounds.png/.pdf
"""
import json, os
import figstyle as FS
from plot_lm_sweep import ORDER, NAME, MARK, GREY, CLK

plt = FS.plt
HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
PANELS = [("lm_chain_real.json", "(a) BN re-estimated: activation sparsity flat"),
          ("lm_chain_real_bnfrozen.json", "(b) BN frozen: activation sparsity rises with pruning")]


def main():
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.4), sharey=True)
    for ax, (f, title) in zip(axes, PANELS):
        d = json.load(open(os.path.join(R, f)))["BERT"]
        pts = sorted(d["points"].items(), key=lambda kv: float(kv[0]))
        xs = list(range(len(pts)))
        for k in ORDER:
            ys = [v["cycles"][k] / CLK * 1e3 for _, v in pts]
            ours = k == "ours"
            ax.plot(xs, ys, marker=MARK[k], ms=7 if ours else 4, lw=1.8 if ours else 0.9, color=GREY[k],
                    mfc=GREY[k] if ours else "white", mec=GREY[k], label=NAME[k], zorder=5 if ours else 3)
        ax.set_yscale("log")
        ax.set_xticks(xs, [f"{100 * float(w):g}\n{100 * (1 - v['mean_nonsilent']):.0f}" for w, v in pts], fontsize=6.5)
        ax.set_xlabel("Weight sparsity (%)  /  activation sparsity (%)", fontsize=7)
        ax.set_title(title, fontsize=7.5, fontweight="bold")
        ax.grid(True, which="major", ls=":", lw=0.6, color="#999999")
    axes[0].set_ylabel("Latency per sentence (ms)")
    h, l = axes[0].get_legend_handles_labels()
    fig.legend(h, l, loc="upper center", ncol=len(ORDER), frameon=False, fontsize=7, bbox_to_anchor=(0.5, 1.05))
    fig.tight_layout(rect=(0, 0, 1, 0.91), w_pad=0.6)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"lm_bert_bounds.{ext}"), dpi=300, bbox_inches="tight")


if __name__ == "__main__":
    main()
