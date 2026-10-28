"""
plot_lm_sweep.py -- every design on NeuroFlex's transformer / language models vs activation sparsity, from
results/lm_sweep.json (lm_sweep.py), batch 1 (one sequence). One panel per model.

  python3 plot_lm_sweep.py           -> results/lm_sweep_speedup.png/.pdf  (speed-up over PTB)
  python3 plot_lm_sweep.py latency   -> results/lm_sweep_latency.png/.pdf  (latency per sequence in ms, all
                                        designs at the common 500 MHz clock of the main results)
  python3 plot_lm_sweep.py <mode> wgt -> the weight-sparsity sweep (results/lm_sweep_wgt.json, activation sparsity
                                        90 %) -> results/lm_sweep_wgt_<mode>.png/.pdf
  python3 plot_lm_sweep.py <mode> chain -> weight sparsity with layer-chained activations of one sample
                                        (results/lm_chain.json, lm_chain.py) -> results/lm_chain_<mode>.png/.pdf
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


CLK = 500e6


def main(mode="speedup", sweep="act"):
    src, stem = {"act": ("lm_sweep.json", "lm_sweep"), "wgt": ("lm_sweep_wgt.json", "lm_sweep_wgt"),
                 "chain": ("lm_chain.json", "lm_chain"), "real": ("lm_chain_real.json", "lm_chain_real")}[sweep]
    d = json.load(open(os.path.join(R, src)))
    models = [m for m in ("BERT", "ViT-B", "GPT-2 XL", "OPT-6.7B") if m in d]
    fig, axes = plt.subplots(1, len(models), figsize=(FS.TEXT, 2.1), sharey=(mode != "latency"))
    axes = axes if len(models) > 1 else [axes]
    for ax, m in zip(axes, models):
        pts = sorted(d[m]["points"].items(), key=lambda kv: float(kv[0]))
        xv = [100 * float(k) for k, _ in pts]
        xs = list(range(len(pts))) if sweep == "real" else xv          # even spacing for the dense high-sparsity end
        for k in ORDER:
            ys = [(v["cycles"][k] / CLK * 1e3) if mode == "latency" else v["cycles"]["ptb"] / v["cycles"][k]
                  for _, v in pts]
            ours = k == "ours"
            ax.plot(xs, ys, marker=MARK[k], ms=7 if ours else 4, lw=1.8 if ours else 0.9, color=GREY[k],
                    mfc=GREY[k] if ours else "white", mec=GREY[k], label=NAME[k], zorder=5 if ours else 3)
        ax.set_yscale("log")
        ax.set_title(m, fontsize=8, fontweight="bold")
        ax.set_xticks(xs, [f"{v:g}" for v in xv])
        ax.set_xlabel("Activation sparsity (%)" if sweep == "act" else "Weight sparsity (%)")
        ax.grid(True, which="major", ls=":", lw=0.6, color="#999999")
    axes[0].set_ylabel("Latency per sequence (ms)" if mode == "latency" else "Speedup over PTB")
    if mode == "latency":
        for ax in axes:
            ax.tick_params(labelleft=True)
    h, l = axes[0].get_legend_handles_labels()
    fig.legend(h, l, loc="upper center", ncol=len(ORDER), frameon=False, fontsize=7, bbox_to_anchor=(0.5, 1.04))
    fig.tight_layout(rect=(0, 0, 1, 0.92), w_pad=0.8)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"{stem}_{mode}.{ext}"), dpi=300, bbox_inches="tight")


if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else "speedup", sys.argv[2] if len(sys.argv) > 2 else "act")
