"""
ablation_dataflow.py -- why weight-stationary: WS vs IS vs OS on the same array (4 x 4 PEs, T = 8 adders per PE),
the same workload (sparse90, batch 1) and the same packers, analytical (ideal: no stalls, no fill), per layer.

  WS (ours)  packed weight columns (offline weight packing, <= F = 4 filters per column) stay in the PEs;
             packed spike groups (run-time pixel packing, <= G = 4 pixels) stream along the rows; one group per cycle.
             cycles = sum over (filter block, K-tile, pixel block) of ceil(columns / 4) x groups
             reads: each packed column once per pixel block; each group once per pass; partial sums: RMW of every
             touched (filter, pixel) entry per K-tile
  IS         the same two packings, roles swapped: packed spike groups stay (4 per pass, one per array column),
             packed weight columns stream, one per cycle.
             cycles = sum of ceil(groups / 4) x columns
             reads: each group once per filter block; each column once per group pass; partial sums: same RMW
  OS         each PE owns T accumulators of one output (filter, pixel): 4 filters x 4 pixels per pass; a common
             input k is broadcast per cycle and skipped only if all 4 filters' weights or all 4 pixels' trains are
             zero. Packing is not possible without F x G x T accumulators per PE (16x), so OS runs unpacked.
             cycles = sum over 4x4 output blocks of #k with a non-zero weight AND a spike in the block
             reads: per cycle 4 weights + 4 spike trains; partial sums: none (accumulated in place)

Effectual work = adds of a non-zero weight for a '1' spike bit (same for all); utilization = work / (cycles x 128).

  python3 ablation_dataflow.py   -> results/ablation_dataflow.json/.md, results/ablation_dataflow.png/.pdf
"""
import json, math, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
R_ = os.path.join(HERE, "results")
NETS = ("VGG16", "ResNet18")
T, MB = 8, 8e6
GBITS, CBITS, PSUM = 4 * 8 + 4 * 8 * 2 + 4 * 7 + 3, 4 * 10 + 4 * 6, 8 * 24


def layer(t):
    import workload as wl
    from ours import Cfg, LayerPlan, tile_masks, pack_spikes
    net, li = t
    cfg = Cfg()
    R, C = cfg.R, cfg.C
    lay = wl.NETWORKS[net]()[li]
    seed = zlib.crc32(f"{net}|{li}|1|0.1|0.1|0.3".encode())
    W, S = wl.layer_tensors(lay, 1, 0.1, 0.1, 0.3, seed)
    M, K = W.shape
    N = S.shape[1]
    work = int(((W != 0).astype(np.int64) @ wl.popcount8(S).astype(np.int64)).sum())
    plan = LayerPlan(W, cfg)
    Sp = np.zeros((plan.nK * R, N), np.uint8)
    Sp[:K] = S
    ws = dict(cyc=0, w=0, a=0, p=0)
    is_ = dict(cyc=0, w=0, a=0, p=0)
    gcache = {}
    for bi, (m0, m1) in enumerate(plan.mblocks):
        for n0 in range(0, N, cfg.Nt):
            n1 = min(n0 + cfg.Nt, N)
            for kt in range(plan.nK):
                cols, Wt = plan.cols[bi, kt]
                if not cols:
                    continue
                key = (kt, n0)
                if key not in gcache:
                    St = Sp[kt * R:(kt + 1) * R, n0:n1]
                    gcache[key] = (len(pack_spikes(tile_masks(St, T), cfg.G, cfg.W_open)), St)
                P, St = gcache[key]
                raw = R * (n1 - n0) * T
                ws["r"] = ws.get("r", 0) + raw
                is_["r"] = is_.get("r", 0) + raw
                if P == 0:
                    continue
                nc = len(cols)
                touched = int((((Wt != 0).astype(np.float32) @ (St != 0).astype(np.float32)) > 0).sum())
                ws["cyc"] += math.ceil(nc / C) * P
                ws["w"] += nc * CBITS
                ws["a"] += math.ceil(nc / C) * P * GBITS
                ws["p"] += 2 * touched * PSUM
                is_["cyc"] += math.ceil(P / C) * nc
                is_["w"] += math.ceil(P / C) * nc * CBITS
                is_["a"] += P * GBITS
                is_["p"] += 2 * touched * PSUM
    # OS with both packings: PE (r, c) owns 4 filters x 4 pixels (F x G x T accumulators, the same slot count as
    # WS's running-sum bundle) for the whole K; an array tile covers 16 filters x 16 pixels. At each input k, row r
    # broadcasts its non-zero weights (one per cycle, with a 2-bit filter label) and column c its pixels' trains
    # merged into first-fit groups (one per cycle, with 2-bit pixel labels); lockstep: cycles(k) =
    # max_r nzF(r, k) x max_c groups(c, k), 0 if either is 0.
    nzF = np.zeros((-(-M // 4) * 4, K), np.int64); nzF[:M] = (W != 0)
    nzF = nzF.reshape(-1, 4, K).sum(1)                                   # (M/4, K): non-zero filters per quad
    Np4 = -(-N // 4) * 4
    Sq = np.zeros((K, Np4), np.uint8); Sq[:, :N] = S
    Sq = Sq.reshape(K, -1, 4)                                           # (K, N/4, 4) trains of each pixel quad
    g = np.zeros(Sq.shape[:2] + (4,), np.uint8); used = np.zeros(g.shape, bool)
    for i in range(4):                                                  # vectorized first-fit of the 4 trains
        x = Sq[:, :, i]
        todo = x != 0
        for j in range(4):
            ok = todo & ((~used[:, :, j]) | ((g[:, :, j] & x) == 0))
            g[:, :, j] = np.where(ok, g[:, :, j] | x, g[:, :, j])
            used[:, :, j] |= ok
            todo &= ~ok
    grp = used.sum(2)                                                   # (K, N/4): groups per pixel quad
    mF = nzF.reshape(-1, 4, K).max(1) if nzF.shape[0] % 4 == 0 else np.pad(nzF, ((0, (-nzF.shape[0]) % 4), (0, 0))).reshape(-1, 4, K).max(1)
    gq = grp.T                                                          # (N/4, K)
    gq = np.pad(gq, ((0, (-gq.shape[0]) % 4), (0, 0)))
    mS = gq.reshape(-1, 4, K).max(1)                                    # (N/16, K)
    oc = int((mF.sum(0).astype(np.int64) * mS.sum(0).astype(np.int64)).sum())
    nft, npt = mF.shape[0], mS.shape[0]
    tiles = nft * npt
    w_reads = int(nzF.sum()) * npt * 10                                 # each non-zero weight + label, per pixel tile
    a_reads = int(grp.sum()) * nft * (T + 2 * T)                        # each group (8 bits + labels), per filter tile
    os_ = dict(cyc=oc, cyc_real=oc + tiles * (6 + 4), w=w_reads, a=a_reads, p=M * N * T, r=K * N * T * nft)
    return net, dict(work=work, ws=ws, is_=is_, os=os_)


def main():
    import workload as wl
    from multiprocessing import Pool
    tasks = [(n, li) for n in NETS for li in range(len(wl.NETWORKS[n]()))]
    with Pool(8) as p:
        res = p.map(layer, tasks)
    out = {}
    for net, r in res:
        o = out.setdefault(net, dict(work=0, **{d: dict(cyc=0, cyc_real=0, w=0, a=0, p=0, r=0) for d in ("ws", "is_", "os")}))
        o["work"] += r["work"]
        for d in ("ws", "is_", "os"):
            for k in ("cyc", "cyc_real", "w", "a", "p", "r"):
                o[d][k] += r[d].get(k, 0)
    # realistic cycles: WS = the RTL-verified cycle count (closed-loop testbench, cycle-exact with the model);
    # IS shares WS's back end (edge FIFOs, output-buffer RMW, LIF) and gets the same double buffering, so it gets
    # WS's measured overhead ratio; OS: ideal + per-block fill/drain and LIF (above)
    summ = json.load(open(os.path.join(R_, "main_summary.json")))["sparse90"]
    for net in NETS:
        o = out[net]
        real = summ[f"{net}|ours"]["cycles_b1"]
        o["ws"]["cyc_real"] = real
        o["is_"]["cyc_real"] = round(o["is_"]["cyc"] * real / o["ws"]["cyc"])
    json.dump(out, open(os.path.join(R_, "ablation_dataflow.json"), "w"), indent=1)
    NAME = {"ws": "WS (TIDES)", "is_": "IS", "os": "OS"}
    L = ["# Dataflow ablation: WS vs IS vs OS (4x4 PEs, T = 8 adders, sparse90, batch 1, analytical)", "",
         "| Network | Dataflow | Packing used | Ideal cycles | Cycles with overheads | vs WS | Adder utilization | "
         "Weight reads (MB) | Spike reads, raw + packed (MB) | Partial sums / outputs (MB) | On-chip total (MB) |",
         "|---|---|---|---:|---:|---:|---:|---:|---:|---:|---:|"]
    for net in NETS:
        o = out[net]
        for d in ("ws", "is_", "os"):
            x = o[d]
            pk = "weights + spikes"
            L.append(f"| {net} | {NAME[d]} | {pk} | {x['cyc']:,} | {x['cyc_real']:,} | "
                     f"{x['cyc_real'] / o['ws']['cyc_real']:.2f}x | "
                     f"{100 * o['work'] / (x['cyc_real'] * 128):.1f}% | {x['w'] / MB:.2f} | {(x['a'] + x['r']) / MB:.2f} | "
                     f"{x['p'] / MB:.2f} | {(x['w'] + x['a'] + x['r'] + x['p']) / MB:.2f} |")
    open(os.path.join(R_, "ablation_dataflow.md"), "w").write("\n".join(L) + "\n")
    print("\n".join(L))
    plot(out)


def energy(out):
    """per image, batch 1, 45 nm, 500 MHz: core = our measured core power x time (same array for all);
    SRAM = CACTI 45 nm LSTP per-bit energy x bits (weights and spikes: 64 KB staging buffer read; partial sums:
    192 KB output buffer, half reads half writes; OS outputs: one write) + leakage x time;
    DRAM = our measured DRAM energy (same DRAM traffic for all dataflows)."""
    sb = json.load(open(os.path.join(R_, "system_breakdown_b1.json")))
    cac = json.load(open(os.path.join(HERE, "hw", "sram_45nm_lstp_lop.json")))
    st, ob = cac["16|65536"], cac["24|196608"]
    e_st = st["read_nJ"] * 1e-9 / 128
    e_ob = 0.5 * (ob["read_nJ"] + ob["write_nJ"]) * 1e-9 / 192
    leak = sum(cac[k]["leak_mW"] for k in ("24|196608", "16|65536", "16|4096")) * 1e-3
    for net in NETS:
        x = sb[f"{net}|ours"]
        p_core = x["power_W"]["core"]
        e_dram = x["energy_J"]["dram"]
        for d in ("ws", "is_", "os"):
            o = out[net][d]
            t = o["cyc_real"] / 500e6
            sram = (o["w"] + o["a"] + o["r"]) * e_st + o["p"] * e_ob + leak * t
            o["E"] = dict(core=p_core * t, sram=sram, dram=e_dram)
            o["t"] = t
            o["edp"] = sum(o["E"].values()) * t
    return out


def plot(out):
    import plot_ptb_style as PS
    from matplotlib.patches import Patch
    plt, FS = PS.plt, PS.FS
    out = energy(out)
    D = ("ws", "is_", "os")
    LAB = {"ws": "WS (TIDES)", "is_": "IS", "os": "OS"}
    sty = {"ws": ("#111111", ""), "is_": ("#8C8C8C", ""), "os": ("#FFFFFF", "////")}
    STK = ("#111111", "#8C8C8C", "#FFFFFF")
    HAT = ("", "", "////")

    def deco(ax, ylab, tag, top, ty=-0.3):
        ax.set_ylim(0, top * 1.22)
        ax.set_ylabel(ylab, fontweight="bold")
        ax.yaxis.grid(True, ls=":", lw=0.6, color="#777777", zorder=0)
        ax.xaxis.grid(False)
        FS.panel_tag(ax, tag, y=ty)

    fig, axes = plt.subplots(2, 3, figsize=(FS.TEXT, 4.3))
    x = np.arange(len(NETS))
    w = 0.24
    # ---- row 1: grouped bars (latency, utilization, EDP)
    for ax, fn, ylab, tag, fmt in (
            (axes[0, 0], lambda n, d: out[n][d]["cyc_real"] / out[n]["ws"]["cyc_real"], "Normalized latency",
             "(a) Latency", "{:.2f}"),
            (axes[0, 1], lambda n, d: 100 * out[n]["work"] / (out[n][d]["cyc_real"] * 128), "Adder utilization (%)",
             "(b) Adder utilization", "{:.1f}"),
            (axes[0, 2], lambda n, d: out[n][d]["edp"] / out[n]["ws"]["edp"], "Normalized EDP", "(c) EDP", "{:.2f}")):
        top = 0
        for i, d in enumerate(D):
            v = [fn(n, d) for n in NETS]
            xi = x + (i - 1) * (w + 0.02)
            ax.bar(xi, v, w, color=sty[d][0], hatch=sty[d][1], edgecolor="#111111", linewidth=0.6, zorder=3)
            for a_, b_ in zip(xi, v):
                ax.annotate(fmt.format(b_), (a_, b_), xytext=(0, 2), textcoords="offset points", ha="center",
                            va="bottom", fontsize=6, fontweight="bold")
            top = max(top, max(v))
        ax.set_xticks(x, NETS, fontweight="bold")
        deco(ax, ylab, tag, top)
    # ---- (d): each traffic type separately, log scale (they span 3 orders of magnitude)
    from matplotlib.ticker import FixedLocator, FixedFormatter, NullLocator
    legs = []
    ax = axes[1, 0]
    comp = (("w", "Wgt"), ("a", "Spk"), ("p", "Psum"))
    xs, labs = [], []
    for j, n in enumerate(NETS):
        for c, (key, lab) in enumerate(comp):
            xc = j * 3.6 + c * 1.05
            xs.append(xc); labs.append(lab)
            for i, d in enumerate(D):
                o = out[n][d]
                v = (o["a"] + o["r"]) if key == "a" else o[key]
                ax.bar(xc + (i - 1) * 0.3, max(v / MB, 1e-3), 0.28, color=sty[d][0], hatch=sty[d][1],
                       edgecolor="#111111", linewidth=0.5, zorder=3)
        ax.text(j * 3.6 + 1.05, -0.2, n, transform=ax.get_xaxis_transform(), ha="center", va="top", fontsize=7,
                fontweight="bold")
    ax.set_yscale("log")
    ax.set_ylim(0.1, 600)
    ax.yaxis.set_major_locator(FixedLocator([0.1, 1, 10, 100]))
    ax.yaxis.set_major_formatter(FixedFormatter(["0.1", "1", "10", "100"]))
    ax.yaxis.set_minor_locator(NullLocator())
    ax.set_xticks(xs, labs, fontsize=6.6, fontweight="bold")
    ax.set_ylabel("On-chip traffic (MB)", fontweight="bold")
    ax.yaxis.grid(True, ls=":", lw=0.6, color="#777777", zorder=0)
    ax.xaxis.grid(False)
    FS.panel_tag(ax, "(d) On-chip traffic", y=-0.36)
    # ---- (e): energy, stacked core / SRAM / DRAM
    ax = axes[1, 1]
    xs = np.array([i + j * 4 for j in range(len(NETS)) for i in range(3)], float)
    top = 0
    for j, n in enumerate(NETS):
        for i, d in enumerate(D):
            bot = 0
            for k, v in enumerate((out[n][d]["E"]["dram"] * 1e6, out[n][d]["E"]["sram"] * 1e6,
                                   out[n][d]["E"]["core"] * 1e6)):
                ax.bar(i + j * 4, v, 0.7, bottom=bot, color=STK[k], hatch=HAT[k], edgecolor="#111111",
                       linewidth=0.6, zorder=3)
                bot += v
            top = max(top, bot)
    ax.set_xticks(xs, [LAB[d].replace(" (TIDES)", "") for _ in NETS for d in D], fontsize=6.6, fontweight="bold")
    for j, n in enumerate(NETS):
        ax.text(j * 4 + 1, -0.2, n, transform=ax.get_xaxis_transform(), ha="center", va="top", fontsize=7,
                fontweight="bold")
    deco(ax, "Energy (µJ)", "(e) Energy", top, ty=-0.36)
    legs.append([Patch(facecolor=STK[k], hatch=HAT[k], edgecolor="#111111", linewidth=0.6, label=nm)
                 for k, nm in enumerate(("DRAM", "SRAM", "Core"))][::-1])
    # ---- legend for the dataflows in the last cell
    axes[1, 2].axis("off")
    h = [Patch(facecolor=sty[d][0], hatch=sty[d][1], edgecolor="#111111", linewidth=0.6, label=LAB[d]) for d in D]
    for hs, y, title in ((h, 0.98, "Dataflow (a)-(d)"), (legs[0], 0.45, "Energy (e)")):
        lg = axes[1, 2].legend(handles=hs, loc="upper left", bbox_to_anchor=(0.12, y), frameon=True, fancybox=False,
                               edgecolor="#111111", title=title, handlelength=1.6, handleheight=0.9, ncol=1,
                               labelspacing=0.2, borderpad=0.3, prop={"weight": "bold", "size": 6.2},
                               title_fontproperties={"weight": "bold", "size": 6.6})
        lg._legend_box.align = "left"
        lg.get_frame().set_linewidth(0.6)
        axes[1, 2].add_artist(lg)
    fig.subplots_adjust(left=0.075, right=0.99, top=0.97, bottom=0.15, wspace=0.42, hspace=0.62)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R_, f"ablation_dataflow.{ext}"))
    json.dump(out, open(os.path.join(R_, "ablation_dataflow.json"), "w"), indent=1)


if __name__ == "__main__":
    main()


def power_plot():
    """average power per image (core + SRAM + DRAM) = energy / time, from the energy split in energy()."""
    import plot_ptb_style as PS
    from matplotlib.patches import Patch
    plt, FS = PS.plt, PS.FS
    out = json.load(open(os.path.join(R_, "ablation_dataflow.json")))
    D = ("ws", "is_", "os")
    LAB = {"ws": "WS", "is_": "IS", "os": "OS"}
    STK, HAT = ("#111111", "#8C8C8C", "#FFFFFF"), ("", "", "////")
    fig, ax = plt.subplots(figsize=(FS.COL, 2.3))
    top = 0
    for j, n in enumerate(NETS):
        for i, d in enumerate(D):
            o = out[n][d]
            bot = 0
            for k, key in enumerate(("dram", "sram", "core")):
                v = o["E"][key] / o["t"] * 1e3
                ax.bar(i + j * 4, v, 0.7, bottom=bot, color=STK[k], hatch=HAT[k], edgecolor="#111111",
                       linewidth=0.6, zorder=3)
                bot += v
            ax.annotate(f"{bot / 1e3:.2f} W", (i + j * 4, bot), xytext=(0, 2), textcoords="offset points",
                        ha="center", va="bottom", fontsize=6.4, fontweight="bold")
            top = max(top, bot)
    ax.set_xticks([i + j * 4 for j in range(len(NETS)) for i in range(3)], [LAB[d] for _ in NETS for d in D],
                  fontsize=7, fontweight="bold")
    for j, n in enumerate(NETS):
        ax.text(j * 4 + 1, -0.13, n, transform=ax.get_xaxis_transform(), ha="center", va="top", fontsize=7.5,
                fontweight="bold")
    ax.set_ylim(0, top * 1.18)
    ax.set_ylabel("Power (mW)", fontweight="bold")
    ax.yaxis.grid(True, ls=":", lw=0.6, color="#777777", zorder=0)
    ax.xaxis.grid(False)
    h = [Patch(facecolor=STK[k], hatch=HAT[k], edgecolor="#111111", linewidth=0.6, label=nm)
         for k, nm in enumerate(("DRAM", "SRAM", "Core"))][::-1]
    lg = ax.legend(handles=h, loc="upper right", frameon=True, fancybox=False, edgecolor="#111111",
                   handlelength=1.5, prop={"weight": "bold", "size": 6.6})
    lg.get_frame().set_linewidth(0.6)
    fig.subplots_adjust(left=0.17, right=0.98, top=0.97, bottom=0.2)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R_, f"ablation_power.{ext}"))


if __name__ == "__main__" and False:
    pass


def plot_ordered():
    """the five ablation panels in the paper order: latency, power, energy, EDP, on-chip traffic."""
    import plot_ptb_style as PS
    from matplotlib.patches import Patch
    from matplotlib.ticker import FixedLocator, FixedFormatter, NullLocator
    plt, FS = PS.plt, PS.FS
    out = json.load(open(os.path.join(R_, "ablation_dataflow.json")))
    D = ("ws", "is_", "os")
    LAB = {"ws": "WS (TIDES)", "is_": "IS", "os": "OS"}
    sty = {"ws": ("#111111", ""), "is_": ("#8C8C8C", ""), "os": ("#FFFFFF", "////")}
    STK, HAT = ("#111111", "#8C8C8C", "#FFFFFF"), ("", "", "////")
    grid = lambda ax: (ax.yaxis.grid(True, ls=":", lw=0.6, color="#777777", zorder=0), ax.xaxis.grid(False))
    fig, axes = plt.subplots(2, 3, figsize=(FS.TEXT, 4.3))
    x = np.arange(len(NETS))
    w = 0.24

    def grouped(ax, fn, ylab, tag):
        top = 0
        for i, d in enumerate(D):
            v = [fn(n, d) for n in NETS]
            xi = x + (i - 1) * (w + 0.02)
            ax.bar(xi, v, w, color=sty[d][0], hatch=sty[d][1], edgecolor="#111111", linewidth=0.6, zorder=3)
            for a_, b_ in zip(xi, v):
                ax.annotate(f"{b_:.2f}", (a_, b_), xytext=(0, 2), textcoords="offset points", ha="center",
                            va="bottom", fontsize=6, fontweight="bold")
            top = max(top, max(v))
        ax.set_xticks(x, NETS, fontweight="bold")
        ax.set_ylim(0, top * 1.22)
        ax.set_ylabel(ylab, fontweight="bold")
        grid(ax)
        FS.panel_tag(ax, tag, y=-0.3)

    def stacked(ax, fn, ylab, tag):
        top = 0
        for j, n in enumerate(NETS):
            for i, d in enumerate(D):
                bot = 0
                for k, v in enumerate(fn(out[n][d])):
                    ax.bar(i + j * 4, v, 0.7, bottom=bot, color=STK[k], hatch=HAT[k], edgecolor="#111111",
                           linewidth=0.6, zorder=3)
                    bot += v
                top = max(top, bot)
        ax.set_xticks([i + j * 4 for j in range(len(NETS)) for i in range(3)],
                      [LAB[d].split()[0] for _ in NETS for d in D], fontsize=6.6, fontweight="bold")
        for j, n in enumerate(NETS):
            ax.text(j * 4 + 1, -0.2, n, transform=ax.get_xaxis_transform(), ha="center", va="top", fontsize=7,
                    fontweight="bold")
        ax.set_ylim(0, top * 1.18)
        ax.set_ylabel(ylab, fontweight="bold")
        grid(ax)
        FS.panel_tag(ax, tag, y=-0.36)

    parts = lambda o, s: (o["E"]["dram"] * s, o["E"]["sram"] * s, o["E"]["core"] * s)
    grouped(axes[0, 0], lambda n, d: out[n][d]["cyc_real"] / out[n]["ws"]["cyc_real"], "Normalized latency",
            "(a) Latency")
    stacked(axes[0, 1], lambda o: parts(o, 1e3 / o["t"]), "Power (mW)", "(b) Power")
    stacked(axes[0, 2], lambda o: parts(o, 1e6), "Energy (µJ)", "(c) Energy")
    grouped(axes[1, 0], lambda n, d: out[n][d]["edp"] / out[n]["ws"]["edp"], "Normalized EDP", "(d) EDP")
    ax = axes[1, 1]
    comp = (("w", "Wgt"), ("a", "Spk"), ("p", "Psum"))
    xs, labs = [], []
    for j, n in enumerate(NETS):
        for c, (key, lab) in enumerate(comp):
            xc = j * 3.6 + c * 1.05
            xs.append(xc); labs.append(lab)
            for i, d in enumerate(D):
                o = out[n][d]
                v = (o["a"] + o["r"]) if key == "a" else o[key]
                ax.bar(xc + (i - 1) * 0.3, max(v / MB, 1e-3), 0.28, color=sty[d][0], hatch=sty[d][1],
                       edgecolor="#111111", linewidth=0.5, zorder=3)
        ax.text(j * 3.6 + 1.05, -0.2, n, transform=ax.get_xaxis_transform(), ha="center", va="top", fontsize=7,
                fontweight="bold")
    ax.set_yscale("log")
    ax.set_ylim(0.1, 600)
    ax.yaxis.set_major_locator(FixedLocator([0.1, 1, 10, 100]))
    ax.yaxis.set_major_formatter(FixedFormatter(["0.1", "1", "10", "100"]))
    ax.yaxis.set_minor_locator(NullLocator())
    ax.set_xticks(xs, labs, fontsize=6.6, fontweight="bold")
    ax.set_ylabel("On-chip traffic (MB)", fontweight="bold")
    grid(ax)
    FS.panel_tag(ax, "(e) On-chip traffic", y=-0.36)
    axes[1, 2].axis("off")
    h1 = [Patch(facecolor=sty[d][0], hatch=sty[d][1], edgecolor="#111111", linewidth=0.6, label=LAB[d]) for d in D]
    h2 = [Patch(facecolor=STK[k], hatch=HAT[k], edgecolor="#111111", linewidth=0.6, label=nm)
          for k, nm in enumerate(("DRAM", "SRAM", "Core"))][::-1]
    for hs, y, title in ((h1, 0.98, "Dataflow (a), (d), (e)"), (h2, 0.45, "Component (b), (c)")):
        lg = axes[1, 2].legend(handles=hs, loc="upper left", bbox_to_anchor=(0.12, y), frameon=True, fancybox=False,
                               edgecolor="#111111", title=title, handlelength=1.6, handleheight=0.9,
                               labelspacing=0.2, borderpad=0.3, prop={"weight": "bold", "size": 6.4},
                               title_fontproperties={"weight": "bold", "size": 6.4})
        lg._legend_box.align = "left"
        lg.get_frame().set_linewidth(0.6)
        axes[1, 2].add_artist(lg)
    fig.subplots_adjust(left=0.075, right=0.99, top=0.97, bottom=0.15, wspace=0.42, hspace=0.62)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R_, f"ablation_ordered.{ext}"))
