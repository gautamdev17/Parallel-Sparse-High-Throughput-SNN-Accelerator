"""
syn_sweep_t4.py -- latency (batch 1) speed-up over PTB of every design on the synthetic ResNet-19 workload of the T = 4
figure (realtraces/run_real.py RR_SYN=ResNet19,0.0732,0.1351,0.3 RR_T=4: CIFAR-10 shapes of workload.resnet19_layers,
INT8 weights, workload.rand_spikes trains), swept around that point:

  wgt  weight sparsity 0 .. 99 %, activity fixed at the figure's (86.49 % silent neurons, fire prob. 0.3 per timestep)
  act  silent neurons 70 .. 97 %, weight sparsity fixed at the figure's 92.68 %

Every layer is included (as in the figure); tensors = workload.layer_tensors seeded as run_real.py RR_SYN. The designs
run through prune_chain.layer_sim (TIDES ours.run_layer_fast = RTL cycle-exact at T = 4, see rtl_t4.py; SpikeX,
SpikeFlow, LoAS; PTB / SATO / Prosperity official models, Prosperity with the main results' operator names).
The figure's point (92.68 %, 86.49 %) reproduces its bars exactly.

  ~/torch-env/bin/python syn_sweep_t4.py run    -> results/syn_sweep_t4.json (cached per layer)
  python3 syn_sweep_t4.py plot                   -> results/syn_sweep_t4.png/.pdf, results/syn_sweep_t4.md
"""
import json, os, sys, zlib
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
os.environ["PC_T"] = "4"
R = os.path.join(HERE, "results")
SD = os.path.join(R, "syn_sweep_t4")
OUT = os.path.join(R, "syn_sweep_t4.json")
CACHE = os.path.join(R, "syn_sweep_t4_cache.json")
T, Q = 4, 0.3
FIG = (0.0732, 0.1351)                                    # weight density, non-silent fraction of the figure
WD = (1.0, 0.5, 0.3, 0.2, 0.1, 0.0732, 0.05, 0.02, 0.01)
NS = (0.30, 0.20, 0.1351, 0.10, 0.05, 0.03)
POINTS = [("wgt", wd, FIG[1]) for wd in WD] + [("act", FIG[0], ns) for ns in NS if ns != FIG[1]]
DESIGNS = ("ptb", "spikex", "loas", "sato", "spikeflow", "prosperity", "ours")


def tag(wd, ns):
    return f"wd{wd:g}_ns{ns:g}"


def make(wd, ns):
    """layer tensors of one point -> SD/ResNet19_<tag>.npz + .json (prune_chain trace format)."""
    import workload as wl
    stem = os.path.join(SD, f"ResNet19_{tag(wd, ns)}")
    if os.path.exists(stem + ".json"):
        return
    store, meta = {}, []
    for li, layer in enumerate(wl.NETWORKS["ResNet19"]()):
        name, ci, co, k, s, h = layer
        seed = zlib.crc32(f"ResNet19|{li}|1|{wd}|{ns}|{Q}|T{T}".encode())       # = run_real.py RR_SYN seeds
        W, S = wl.layer_tensors(layer, 1, wd, ns, Q, seed, T=T)
        store[f"W{li}"], store[f"S{li}"] = W, S
        # raw input map of the layer (im2col source): same draws as layer_tensors
        rng = np.random.default_rng(seed)
        wl.rand_weights(rng, *wl.gemm_shape(layer, 1)[:2], wd)
        X = wl.rand_spikes(rng, (1, ci, h, h), ns, Q, T)
        meta.append(dict(name=name, analog=False, kind="conv" if k > 1 or h > 1 else "fc", k=k, ci=ci, s=s, h=h,
                         pool=1, M=int(W.shape[0]), K=int(S.shape[0]), N=int(S.shape[1]), raw_n=int(X.size),
                         raw_nz=int((X != 0).sum())))
    os.makedirs(SD, exist_ok=True)
    np.savez_compressed(stem + ".npz", **store)
    json.dump(dict(weight_density=wd, nonsilent=ns, q=Q, T=T, layers=meta), open(stem + ".json", "w"))


def work(t):
    import prune_chain as PC
    PC.SD = SD
    _, r = PC.layer_sim(("ResNet19", t[0], t[1]))
    return t, r["cycles"]


def run():
    for _, wd, ns in POINTS:
        make(wd, ns)
    nl = len(json.load(open(os.path.join(SD, f"ResNet19_{tag(*FIG)}.json")))["layers"])
    todo = [(tag(wd, ns), li) for _, wd, ns in POINTS for li in range(nl)]
    cache = json.load(open(CACHE)) if os.path.exists(CACHE) else {}
    todo = [t for t in dict.fromkeys(todo) if repr(t) not in cache]
    print(f"{len(cache)} cached, {len(todo)} to run", flush=True)
    with Pool(int(os.environ.get("SS_WORKERS", 7))) as p:
        for i, (t, c) in enumerate(p.imap_unordered(work, todo)):
            cache[repr(t)] = c
            json.dump(cache, open(CACHE, "w"))
            if i % 20 == 0:
                print(f"[{i + 1}/{len(todo)}] {t}", flush=True)
    out = []
    for sweep, wd, ns in POINTS:
        cyc = {d: sum(cache[repr((tag(wd, ns), li))][d] for li in range(nl)) for d in DESIGNS}
        out.append(dict(sweep=sweep, weight_density=wd, nonsilent=ns, cycles_b1=cyc))
        print(f"{sweep} wsp {100 * (1 - wd):5.2f}% silent {100 * (1 - ns):5.2f}% | speedup over PTB: "
              + " ".join(f"{d} {cyc['ptb'] / cyc[d]:.2f}" for d in DESIGNS), flush=True)
    json.dump(dict(net="ResNet19", T=T, q=Q, batch=1, figure_point=FIG, points=out), open(OUT, "w"), indent=1)


def plot():
    import figstyle as FS
    from plot_prune_sweep import ORDER, NAME, MARK, GREY
    plt = FS.plt
    d = json.load(open(OUT))["points"]
    fig, axes = plt.subplots(1, 2, figsize=(FS.TEXT, 2.4))
    for ax, sweep in zip(axes, ("wgt", "act")):
        pts = sorted([p for p in d if p["sweep"] == sweep or (p["weight_density"], p["nonsilent"]) == FIG],
                     key=lambda p: (1 - p["weight_density"]) if sweep == "wgt" else (1 - p["nonsilent"]))
        xs = list(range(len(pts)))
        lab = [f"{100 * (1 - (p['weight_density'] if sweep == 'wgt' else p['nonsilent'])):g}" for p in pts]
        for k in ORDER:
            ys = [p["cycles_b1"]["ptb"] / p["cycles_b1"][k] for p in pts]
            ours = k == "ours"
            ax.plot(xs, ys, marker=MARK[k], ms=6 if ours else 3.5, lw=1.7 if ours else 0.8, color=GREY[k],
                    mfc=GREY[k] if ours else "white", mec=GREY[k], label=NAME[k], zorder=5 if ours else 3)
        fi = [i for i, p in enumerate(pts) if (p["weight_density"], p["nonsilent"]) == FIG][0]
        ax.axvline(fi, ls="--", lw=0.6, color="#777777", zorder=1)
        ax.set_yscale("log")
        ax.set_xticks(xs, lab, fontsize=6)
        ax.set_xlabel("Weight sparsity (%), 86.49 % silent neurons" if sweep == "wgt"
                      else "Silent neurons (%), 92.68 % weight sparsity", fontsize=7)
        ax.grid(True, which="major", ls=":", lw=0.5, color="#999999")
    axes[0].set_ylabel("Speedup over PTB (batch 1)", fontsize=7)
    h, l = axes[0].get_legend_handles_labels()
    fig.legend(h, l, loc="upper center", ncol=len(ORDER), frameon=False, fontsize=7, bbox_to_anchor=(0.5, 1.0))
    fig.suptitle("ResNet-19, CIFAR-10 shapes, synthetic INT8 weights and spike trains, T = 4 (dashed: figure point)",
                 fontsize=7, y=1.06)
    fig.tight_layout(rect=(0, 0, 1, 0.9), w_pad=1.0)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"syn_sweep_t4.{ext}"), dpi=300, bbox_inches="tight")
    lines = ["# Synthetic ResNet-19 (CIFAR-10 shapes), T = 4, batch 1: latency speed-up over PTB (syn_sweep_t4.py)", "",
             "| Sweep | Weight sparsity % | Silent neurons % | " + " | ".join(NAME[k] for k in ORDER)
             + " | TIDES vs best baseline |", "|---|---:|---:|" + "---:|" * len(ORDER) + "---|"]
    for p in d:
        c = p["cycles_b1"]
        sp = {k: c["ptb"] / c[k] for k in ORDER}
        best = max((k for k in ORDER if k != "ours"), key=lambda k: sp[k])
        lines.append(f"| {p['sweep']} | {100 * (1 - p['weight_density']):g} | {100 * (1 - p['nonsilent']):g} | "
                     + " | ".join(f"{sp[k]:.2f}" for k in ORDER) + f" | {sp['ours'] / sp[best]:.2f}x vs {NAME[best]} |")
    open(os.path.join(R, "syn_sweep_t4.md"), "w").write("\n".join(lines) + "\n")


if __name__ == "__main__":
    {"run": run, "plot": plot}[sys.argv[1]]()
