"""plot_ptb_style.py -- normalized latency / throughput figures in the style of the PTB paper (Fig. 11):
grouped bars per network, grey-scale fills with hatching, ours in blue, boxed legend, heavy frame, inward ticks.

  python3 plot_ptb_style.py v1   -> results/v1_ptbstyle.png/.pdf      (equal adders; LoAS from loas_model.py)
  python3 plot_ptb_style.py v4   -> results/v4_ptbstyle.png/.pdf + results/v4_tables.md  (16 PEs in every design)
"""
import json, math, os, sys
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
F_HZ = 800e6
NETS = ["VGG16", "ResNet18"]
ORDER = ["loas_zip", "spikex", "ptb", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"loas_zip": "LoAS", "spikex": "SpikeX", "ptb": "PTB", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "Ours"}
# own palette: muted cool tones for the baselines (distinct fill + pattern, readable in grey-scale print),
# one warm accent for ours
STYLE = {"loas_zip":   dict(color="#e6e9ed", hatch="////"),
         "spikex":     dict(color="#c3d3e2", hatch=""),
         "ptb":        dict(color="#9bb7cf", hatch="...."),
         "sato":       dict(color="#6f93b3", hatch=""),
         "spikeflow":  dict(color="#4a7396", hatch="\\\\\\\\"),
         "prosperity": dict(color="#2c4f6e", hatch=""),
         "ours":       dict(color="#e8871e", hatch="")}
EDGE = "#2b2b2b"
LABEL = "#a85a0c"           # colour of ours' value labels

# palette options: (baseline colour/hatch per design, ours colour, ours label colour); PALETTE=<name> picks one
_G = {"ptb": "#f0f0f0", "spikex": "#d6d6d6", "loas_zip": "#ffffff", "sato": "#b0b0b0", "spikeflow": "#8c8c8c",
      "prosperity": "#5e5e5e"}
_H = {"ptb": "....", "spikex": "", "loas_zip": "////", "sato": "", "spikeflow": "\\\\\\\\", "prosperity": ""}
PALETTES = {
    "A_grey_black": ({d: dict(color=_G[d], hatch=_H[d]) for d in _G}, "#111111", "#111111"),
    "B_white_hatch_black": ({"ptb": dict(color="white", hatch="...."), "spikex": dict(color="white", hatch="----"),
                             "loas_zip": dict(color="white", hatch="////"), "sato": dict(color="white", hatch="xxxx"),
                             "spikeflow": dict(color="white", hatch="\\\\\\\\"),
                             "prosperity": dict(color="#bdbdbd", hatch="")}, "#1a1a1a", "#1a1a1a"),
    "C_grey_navy": ({d: dict(color=_G[d], hatch=_H[d]) for d in _G}, "#1f3d7a", "#1f3d7a"),
    "D_grey_teal": ({d: dict(color=_G[d], hatch=_H[d]) for d in _G}, "#13756f", "#13756f"),
    "E_blue_black": (None, "#111111", "#111111"),
}


def inside_legend(ax, h, l, ncol=3, loc="upper center", handlelength=1.0, fontsize=7.3):
    """compact boxed legend inside an axes: square patch handles, square-cornered black frame."""
    lg = ax.legend(h, l, ncol=ncol, loc=loc, frameon=True, fancybox=False, framealpha=1.0, edgecolor=EDGE,
                   fontsize=fontsize, handlelength=handlelength, handleheight=1.0, handletextpad=0.45,
                   columnspacing=0.9, borderpad=0.45, labelspacing=0.35, borderaxespad=0.5)
    lg.get_frame().set_linewidth(0.6)
    lg.set_zorder(10)
    return lg


def use_palette(name):
    global LABEL
    base, ours, lab = PALETTES[name]
    if base is not None:
        STYLE.update({d: dict(v) for d, v in base.items()})
    STYLE["ours"] = dict(color=ours, hatch="")
    LABEL = lab


if os.environ.get("PALETTE"):
    use_palette(os.environ["PALETTE"])

plt.rcParams.update({
    "font.family": "serif", "font.serif": ["Times New Roman", "Times", "DejaVu Serif"],
    "font.size": 10, "axes.linewidth": 1.0, "hatch.linewidth": 0.45, "hatch.color": EDGE,
    "xtick.direction": "in", "ytick.direction": "in", "xtick.major.width": 0.9, "ytick.major.width": 0.9,
    "xtick.major.size": 3.5, "ytick.major.size": 3.5, "xtick.top": True, "ytick.right": True,
    "ytick.minor.visible": True, "ytick.minor.size": 2, "ytick.minor.width": 0.6, "xtick.minor.visible": False,
})


def draw(norm, out, note=""):
    """norm[net][design] = (normalized latency, normalized throughput), LoAS = 1."""
    fig, axes = plt.subplots(1, 2, figsize=(7.16, 2.55))
    w = 0.112
    # the worst design (lowest mean throughput) is 1x; bars run from it to the best baseline, ours last
    base = min((d for d in ORDER if d != "ours"), key=lambda d: np.mean([norm[n][d][1] for n in NETS]))
    norm = {n: {d: (norm[n][d][0] / norm[n][base][0], norm[n][d][1] / norm[n][base][1]) for d in ORDER} for n in NETS}
    mid = [d for d in ORDER if d != "ours"]
    mid.sort(key=lambda d: np.mean([norm[n][d][1] for n in NETS]))
    order = mid + ["ours"]
    print(f"{out}: normalized to {NAME[base]} = 1x; order", [NAME[d] for d in order])
    for ax, idx, ylab, tag in ((axes[0], 0, "Normalized latency", "(a)"),
                               (axes[1], 1, "Normalized throughput", "(b)")):
        for i, d in enumerate(order):
            x = np.arange(len(NETS)) + (i - (len(order) - 1) / 2) * (w + 0.008)
            v = [norm[n][d][idx] for n in NETS]
            ax.bar(x, v, w, color=STYLE[d]["color"], hatch=STYLE[d]["hatch"], edgecolor=EDGE, linewidth=0.55,
                   label=NAME[d], zorder=3)
            if d == "ours":
                for xi, vi in zip(x, v):
                    ax.annotate(f"{vi:.2f}" if idx == 0 else f"{vi:.2f}\u00d7", (xi, vi), xytext=(0, 2),
                                textcoords="offset points", ha="center", va="bottom", fontsize=7.5,
                                rotation=90, color=LABEL, zorder=5,
                                bbox=dict(boxstyle="square,pad=0.08", fc="white", ec="none"))
        ax.axhline(1.0, color=EDGE, lw=0.6, ls=(0, (4, 2)), zorder=2)
        ax.set_xticks(range(len(NETS)), NETS)
        ax.set_xlim(-0.55, len(NETS) - 0.45)
        ax.set_ylabel(ylab)
        ax.yaxis.grid(True, ls=":", color="#b0b0b0", lw=0.5, zorder=0)
        top = max(norm[n][d][idx] for n in NETS for d in ORDER)
        ax.set_ylim(0, top * (1.95 if idx == 0 else 1.32))       # (a) leaves room for the legend
        ax.text(0.5, -0.17, tag, transform=ax.transAxes, ha="center", va="top", fontsize=10)
    h, l = axes[0].get_legend_handles_labels()
    inside_legend(axes[0], h, l, ncol=3)
    fig.subplots_adjust(left=0.075, right=0.99, top=0.97, bottom=0.2, wspace=0.27)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"{out}{os.environ.get('OUT_SUFFIX', '')}.{ext}"), dpi=300)


def v1():
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    own = json.load(open(os.path.join(R, "loas_own.json")))
    norm = {}
    for n in NETS:
        l0 = own[f"sparse90|{n}|1"] / F_HZ * 1e3
        t0 = 16 * F_HZ / own[f"sparse90|{n}|16"]
        norm[n] = {}
        for d in ORDER:
            lat = l0 if d == "loas_zip" else s[f"{n}|{d}"]["latency_ms"]
            thr = t0 if d == "loas_zip" else s[f"{n}|{d}"]["throughput"]
            norm[n][d] = (lat / l0, thr / t0)
    draw(norm, "v1_fig")


def v4():
    """16 PEs in every design (v3 totals) with LoAS from loas_model.py (16 TPPEs)."""
    tot = json.load(open(os.path.join(R, "v3_iso16_totals.json")))
    own = json.load(open(os.path.join(R, "loas_own.json")))
    norm, rows = {}, ["| Network | Design | Latency (ms) | Normalized latency | Throughput (img/s) | Normalized throughput |",
                      "|---|---|---:|---:|---:|---:|"]
    for n in NETS:
        c1 = {d: tot[f"sparse90|{n}|1|{d}"] for d in ORDER}
        c16 = {d: tot[f"sparse90|{n}|16|{d}"] for d in ORDER}
        c1["loas_zip"], c16["loas_zip"] = own[f"sparse90|{n}|1"], own[f"sparse90|{n}|16"]
        l0, t0 = c1["loas_zip"] / F_HZ * 1e3, 16 * F_HZ / c16["loas_zip"]
        norm[n] = {}
        for d in ORDER:
            lat, thr = c1[d] / F_HZ * 1e3, 16 * F_HZ / c16[d]
            norm[n][d] = (lat / l0, thr / t0)
            rows.append(f"| {n} | {NAME[d]} | {lat:.3f} | {lat / l0:.3f} | {thr:,.0f} | {thr / t0:.2f} |")
    open(os.path.join(R, "v4_tables.md"), "w").write(
        "### v4: 16 PEs in every design, LoAS from loas_model.py, workload sparse90 (T=8, 800 MHz)\n\n"
        + "\n".join(rows) + "\n\nOurs and LoAS PEs have 8 adders each (one per timestep); the other designs' PEs have 1.\n")
    print("\n".join(rows))
    draw(norm, "v4_fig")



def power_edp():
    """v1 latency (equal adders; LoAS from loas_model.py) x power of our RTL of each design (hw/build/*_power.rpt,
    Nangate45, gate-level activity, 800 MHz; LoAS = 16 x the given TPPE RTL).
    energy = power x batch-1 latency, EDP = energy x latency. Plots power and EDP, normalized to the worst design by
    mean EDP = 1x (energy is in the table)."""
    sys.path.insert(0, os.path.join(HERE, "hw"))
    import energy_v2 as E2
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    own = json.load(open(os.path.join(R, "loas_own.json")))
    val, rows = {}, ["| Network | Design | Power (mW) | Latency b=1 (ms) | Energy (mJ) | EDP (mJ*ms) |",
                     "|---|---|---:|---:|---:|---:|"]
    for n in NETS:
        val[n] = {}
        for d in ORDER:
            hw, mult = ("spikeflow_ext", 1) if d == "spikeflow" else E2.HW[d]
            p = E2.power_w(hw) * mult * 1e3
            lat = own[f"sparse90|{n}|1"] / F_HZ * 1e3 if d == "loas_zip" else s[f"{n}|{d}"]["latency_ms"]
            e = p * lat * 1e-3
            val[n][d] = (p, e, e * lat)
            rows.append(f"| {n} | {NAME[d]} | {p:.1f} | {lat:.3f} | {e:.4f} | {e * lat:.5f} |")
    keep = list(ORDER)
    base = max((d for d in keep if d != "ours"), key=lambda d: np.mean([val[n][d][2] for n in NETS]))
    mid = sorted((d for d in keep if d != "ours"), key=lambda d: -np.mean([val[n][d][2] / val[n][base][2] for n in NETS]))
    order = mid + ["ours"]
    norm = {n: {d: tuple(val[n][d][i] / val[n][base][i] for i in range(3)) for d in keep} for n in NETS}
    print(f"normalized to {NAME[base]} = 1x; order", [NAME[d] for d in order])
    for n in NETS:
        print(n, {NAME[d]: tuple(round(x, 3) for x in norm[n][d]) for d in order})
    open(os.path.join(R, "v1_power_edp.md"), "w").write(
        "### v1 power, energy, EDP (sparse90, batch 1, 800 MHz; power from our RTL of each design, Nangate45)\n\n"
        + "\n".join(rows) + f"\n\nNormalized to {NAME[base]} = 1x in v1_power_edp.png (log scale). SpikeFlow power: core with its "
        "18.5 KB buffer as external SRAM, like every other design.\n")
    print("\n".join(rows))
    # power is a property of the design, not of the network: one group in (a)
    fig, axes = plt.subplots(1, 2, figsize=(7.16, 2.55), gridspec_kw=dict(width_ratios=[1, 2]))
    w = 0.125
    for ax, idx, ylab, tag in ((axes[0], 0, "Normalized power", "(a)"), (axes[1], 2, "Normalized EDP", "(b)")):
        ax.set_yscale("log")
        nets = NETS[:1] if idx == 0 else NETS
        lo = min(norm[n][d][idx] for n in nets for d in keep)
        bot = 10 ** math.floor(math.log10(lo * 0.6))
        for i, d in enumerate(order):
            x = np.arange(len(nets)) + (i - (len(order) - 1) / 2) * (w + 0.008)
            v = [norm[n][d][idx] for n in nets]
            ax.bar(x, [vi - bot for vi in v], w, bottom=bot, color=STYLE[d]["color"], hatch=STYLE[d]["hatch"],
                   edgecolor=EDGE, linewidth=0.55, label=NAME[d], zorder=3)
            for xi, vi in zip(x, v):
                if d == "ours":
                    ax.annotate(f"{vi:.2f}" if vi >= 0.095 else f"{vi:.3f}", (xi, vi), xytext=(0, 2),
                                textcoords="offset points", ha="center", va="bottom", rotation=90,
                                fontsize=6.3 if d != "ours" else 7, zorder=5,
                                color=LABEL if d == "ours" else "#333333",
                                fontweight="bold" if d == "ours" else "normal",
                                bbox=dict(boxstyle="square,pad=0.06", fc="white", ec="none"))
        ax.axhline(1.0, color=EDGE, lw=0.6, ls=(0, (4, 2)), zorder=2)
        if idx == 0:
            ax.set_xticks([])
        else:
            ax.set_xticks(range(len(nets)), nets)
        ax.set_xlim(-0.55, len(nets) - 0.45)
        ax.set_ylabel(ylab + " (log)")
        ax.yaxis.grid(True, which="major", ls=":", color="#b0b0b0", lw=0.5, zorder=0)
        ax.set_ylim(bot, 6.0 if idx == 0 else 1e3)               # (b) leaves room for the legend
        ax.text(0.5, -0.17, tag, transform=ax.transAxes, ha="center", va="top", fontsize=10)
    h, l = axes[0].get_legend_handles_labels()
    inside_legend(axes[1], h, l, ncol=4)
    fig.subplots_adjust(left=0.085, right=0.99, top=0.97, bottom=0.2, wspace=0.3)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R, f"v1_power_edp.{ext}"), dpi=300)


if __name__ == "__main__":
    {"v1": v1, "v4": v4, "pe": power_edp}[sys.argv[1]]()
