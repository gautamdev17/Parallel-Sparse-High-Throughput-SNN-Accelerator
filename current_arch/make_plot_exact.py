"""Plot LoAS vs Ours (weight-stationary Mentha, T=8 parallel, one-cycle IF) from the EXACT cycle-stepped runs
(results_cyclesim.json, produced by network_cyclesim.py) on the layers of cycle_compare.py.
Throughput = batch * f / cycles(batch)  (NOT 1 / latency)."""
import json, numpy as np, matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

CLK = 800e6
R = json.load(open("results_cyclesim.json"))
SW = json.load(open("results_sparse.json"))["sweep"]          # fast-model sweep (validated), VGG16 90%
NETS = ["AlexNet", "VGG16", "ResNet18"]
INK, MUTE, GRID = "#0b0b0b", "#52514e", "#e4e3df"
C_LOAS, C_OURS = "#eb6834", "#2a78d6"                          # categorical slots 2 and 1 (validated)
plt.rcParams.update({"font.size": 9.5, "axes.edgecolor": "#c9c8c3", "axes.labelcolor": MUTE, "xtick.color": MUTE,
                     "ytick.color": MUTE, "figure.facecolor": "#fcfcfb", "axes.facecolor": "#fcfcfb"})


def tot(net, b, key):
    rows = [v for k, v in R.items() if k.startswith(f"{net}|{b}|")]
    n = len(__import__("cycle_compare").NETWORKS[net])
    return sum(v[key] for v in rows) if len(rows) == n else None


def clean(a, gx=False):
    a.grid(axis="y", color=GRID, lw=.7, zorder=0)
    if gx: a.grid(axis="x", color=GRID, lw=.7, zorder=0)
    a.set_axisbelow(True)
    for s in ("top", "right"): a.spines[s].set_visible(False)


def fmt(v):
    return f"{v:,.0f}" if v >= 100 else (f"{v:.1f}" if v >= 10 else f"{v:.2f}")


def bars(a, loas, ours, ylabel, title, ratio):
    x = np.arange(len(NETS)); w = .38
    a.bar(x - w/2, loas, w, color=C_LOAS, label="LoAS (cycle_compare.py)", zorder=3)
    a.bar(x + w/2, ours, w, color=C_OURS, label="Ours: WS + Mentha (cycle-accurate sim = RTL)", zorder=3)
    for xi, l, o in zip(x, loas, ours):
        a.annotate(fmt(l), (xi - w/2, l), xytext=(0, 2), textcoords="offset points", ha="center", fontsize=8, color=MUTE)
        a.annotate(fmt(o), (xi + w/2, o), xytext=(0, 2), textcoords="offset points", ha="center", fontsize=8, color=MUTE)
        a.annotate(f"{ratio(l, o):.1f}x", (xi, max(l, o)), xytext=(0, 14), textcoords="offset points",
                   ha="center", fontsize=10, color=INK, fontweight="bold")
    a.set_yscale("log"); a.set_xticks(x); a.set_xticklabels(NETS)
    a.set_ylabel(ylabel); a.set_title(title, loc="left", color=INK, fontweight="bold", fontsize=10.5); clean(a)
    lo, hi = a.get_ylim(); a.set_ylim(lo, hi * 1.7)


have16 = all(tot(n, 16, "ours") for n in NETS)
fig, ax = plt.subplots(2, 2, figsize=(13, 9.2))

l1 = [tot(n, 1, "loas") / CLK * 1e3 for n in NETS]
o1 = [tot(n, 1, "ours") / CLK * 1e3 for n in NETS]
bars(ax[0, 0], l1, o1, "ms per inference (log), lower is better",
     "Latency, batch 1\n(label = LoAS time / Ours time)", lambda l, o: l / o)

if have16:
    l16 = [16 * CLK / tot(n, 16, "loas") for n in NETS]
    o16 = [16 * CLK / tot(n, 16, "ours") for n in NETS]
    bars(ax[0, 1], l16, o16, "inferences / s (log), higher is better",
         "Throughput, batch 16 = 16 x f / cycles(16)\n(label = Ours / LoAS)", lambda l, o: o / l)
else:
    t1l = [CLK / tot(n, 1, "loas") for n in NETS]
    t1o = [CLK / tot(n, 1, "ours") for n in NETS]
    bars(ax[0, 1], t1l, t1o, "inferences / s (log)", "Throughput, batch 1", lambda l, o: o / l)

B = [s["B"] for s in SW]
a = ax[1, 0]
a.plot(B, [b * CLK / s["loas"] for b, s in zip(B, SW)], color=C_LOAS, lw=2, marker="o", ms=5, label="LoAS")
a.plot(B, [b * CLK / s["ours"] for b, s in zip(B, SW)], color=C_OURS, lw=2, marker="o", ms=5, label="Ours (sampled model)")
ex = [(b, tot("VGG16", b, "ours")) for b in (1, 16) if tot("VGG16", b, "ours")]
a.scatter([b for b, _ in ex], [b * CLK / c for b, c in ex], s=70, facecolor="none", edgecolor=INK, lw=1.6, zorder=5,
          label="Ours (exact cycle-stepped run)")
a.set_xscale("log", base=2); a.set_xticks(B); a.set_xticklabels(B); a.set_ylim(0, None)
a.set_xlabel("batch size"); a.set_ylabel("inferences / s")
a.set_title("VGG16 throughput vs batch: LoAS is flat, Ours climbs\n(so throughput is not 1 / latency)",
            loc="left", color=INK, fontweight="bold", fontsize=10.5)
a.legend(frameon=False, loc="center right"); clean(a, gx=True)

# where Ours wins / loses: VGG16 batch 1, LoAS cycles / Ours cycles per layer
a = ax[1, 1]
rows = sorted([v for k, v in R.items() if k.startswith("VGG16|1|")], key=lambda v: v["li"])
names = [f"{v['name']} (N={v['N']})" for v in rows]
sp = [v["loas"] / v["ours"] for v in rows]
y = np.arange(len(rows))[::-1]
a.barh(y, sp, .62, color=[C_OURS if s >= 1 else C_LOAS for s in sp], zorder=3)
for yi, s in zip(y, sp):
    a.annotate(f"{s:.2f}x", (s, yi), xytext=(3, -3), textcoords="offset points", fontsize=7.5, color=INK)
a.axvline(1, color=MUTE, lw=1, ls="--"); a.set_xscale("log")
a.set_yticks(y); a.set_yticklabels(names, fontsize=7.5)
a.set_xlabel("LoAS cycles / Ours cycles, VGG16 batch 1 (blue = Ours faster, orange = Ours slower)")
a.set_title("Per layer: big-N conv layers win; N=1 fully-connected layers lose",
            loc="left", color=INK, fontweight="bold", fontsize=10.5); clean(a, gx=True)

h, l = ax[0, 0].get_legend_handles_labels()
fig.legend(h, l, loc="upper center", ncol=2, frameon=False, bbox_to_anchor=(0.5, 1.0))
ok = all(v["ok"] for v in R.values())
fig.suptitle("LoAS vs Ours (weight-stationary Mentha), INT8 weights + 8-bit spike masks (T=8), weights and activations 90% sparse, 16 PEs, 800 MHz\n"
             f"Ours = cycle-stepped simulator, cycle-identical to the RTL; every simulated layer bit-exact vs dense: {ok}",
             y=1.065, color=INK, fontweight="bold", fontsize=11)
fig.tight_layout(); fig.savefig("loas_vs_ours_exact.png", dpi=160, bbox_inches="tight")
print("saved loas_vs_ours_exact.png", "(batch 16 included)" if have16 else "(batch 16 not finished yet)")
for n in NETS:
    for b in (1, 16):
        o, l_ = tot(n, b, "ours"), tot(n, b, "loas")
        if o:
            print(f"{n:9s} b{b:<2d} LoAS {l_/CLK*1e3:9.3f} ms  Ours {o/CLK*1e3:9.3f} ms  ({l_/o:5.2f}x) | thr LoAS {b*CLK/l_:8.1f}  Ours {b*CLK/o:8.1f} img/s")
