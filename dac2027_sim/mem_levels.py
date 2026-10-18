"""
mem_levels.py -- weight and activation traffic at three levels of the memory hierarchy, per inference (batch 1),
workload sparse90, VGG16 and ResNet18. All levels count data moving TOWARD the adders (reads; output spikes and
partial sums are not part of this figure).

  Off-chip  DRAM -> on-chip buffers                     (results/mem_traffic_*.json, see mem_traffic.py)
  On-chip   on-chip buffers (SRAM) -> PE array          (bits read out of the buffers that feed the array)
  PE        into the PEs: operand bits latched by the PEs, counted once per PE that receives them
            (a value broadcast to, or forwarded systolically through, n PEs counts n times)

Each design's dataflow is the one its cycle numbers come from:
  Prosperity  official simulator: on-chip = its own counters reads['g_act'] (spike tiles) and reads['g_wgt']
              (one weight row of the 128-wide output tile per processed spike row). PE: every weight read goes to
              one PE; spikes never enter the PEs (the detector/dispatcher turns them into weight-row addresses).
  PTB         official Prosperity-repo model (run_PTB_convfc: 16 x 8 systolic array, TWS = 4, 8 columns =
              (time window, pixel) units, StSAP slots). Per slot and 16-channel block: one 8-bit weight per row
              (two for a StSAP pair), forwarded across the 8 columns; 8 columns x 4 spike bits (+1 owner bit per
              column for a pair), forwarded down the 16 rows.
  SATO        official Prosperity-repo model (run_sato_conv_fc: 128 PEs, each takes whole (t, pixel) spike rows):
              each row's K-bit spike vector is read once; every spike reads the M weights of its input (one
              8-bit weight per output channel, sequentially). Point to point: PE = on-chip.
  SpikeX      baselines.spikex_layer_cycles (8 x 8; weights enter the rows and are forwarded along the 8
              columns; spike-window bits enter the columns and are forwarded down the 8 rows). Per walked input
              and 8-channel block: 8 weights; 8 columns x TWS bits.
  SpikeFlow   baselines.spikeflow_layer_cycles (16 x 16 output-stationary; one non-silent input per cycle; its
              16 weights enter the rows, forwarded along 16 columns; its 16 spike bits (2 pixels x T) enter the
              columns, forwarded down 16 rows).
  LoAS        loas_model.py (16 TPPEs, 128-chunk fibres, the mapping its cycle model picks per layer):
              A) 16 pixels share a broadcast weight fibre (128-bit bitmask + 8-bit non-zeros); each TPPE reads
                 its own spike bitmask and the T-bit trains of its matches;
              B) 16 channels share a broadcast spike bitmask; each TPPE reads its own weight fibre and the trains
                 of its matches.
  Ours        ours.py run_layer_fast loop (per m-block, n-block, K-tile, pass of 4 packed columns):
              on-chip weights = per pass, each column's R x (8-bit weight + 2-bit filter label) + F x 6-bit
              filter ids; on-chip activations = the packer's read of the raw R x n x T trains of every K-tile it
              packs + the group buffer's read of every group per pass (32 spike bits + 32 x 2-bit pixel labels +
              4 x 7-bit pixel ids + 3-bit count = 127 bits). PE: each weight + label once into its PE per pass;
              each row's 8 spike bits + 16 label bits forwarded through the 4 PEs of the row.

  venv-python mem_levels.py prosperity | ptb    (needs torch)   -> results/mem_levels_<mode>.json
  python3     mem_levels.py base                                 -> results/mem_levels_base.json
  python3     mem_levels.py table                                -> results/mem_levels.md, mem_levels.png/.pdf
"""
import json, math, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
R_ = os.path.join(HERE, "results")
T = 8
WD, NS, Q = 0.10, 0.10, 0.3
NETS = ("VGG16", "ResNet18")
MB = 8e6                                      # bits per MB
B = int(os.environ.get("MLB", 1))             # batch (results per image)
SFX = "" if B == 1 else f"_b{B}"


def tensors(net, li, layer, b=None):
    b = B if b is None else b
    import workload as wl
    seed = zlib.crc32(f"{net}|{li}|{b}|{WD}|{NS}|{Q}".encode())
    return wl.layer_tensors(layer, b, WD, NS, Q, seed)


# ------------------------------------------------------------------------------------------------ ours
def ours_layer(W, S):
    from ours import Cfg, LayerPlan, tile_masks, pack_spikes, _passes
    cfg = Cfg()
    R, C, F, G = cfg.R, cfg.C, cfg.F, cfg.G
    plan = LayerPlan(W, cfg)
    K, N = S.shape
    Sp = np.zeros((plan.nK * R, N), dtype=np.uint8)
    Sp[:K] = S
    oc_w = oc_a = pe_w = pe_a = 0
    rmw = lifr = gw = rawr = pe_s = 0
    SW = 10                                              # in-array running-sum width (ours_core.v SW)
    gbits = R * T + R * T * 2 + G * 7 + 3
    cache = {}
    for bi, (m0, m1) in enumerate(plan.mblocks):
        for n0 in range(0, N, cfg.Nt):
            n1 = min(n0 + cfg.Nt, N)
            dirty = np.zeros((m1 - m0, n1 - n0), dtype=bool)
            for kt in range(plan.nK):
                cols, Wt = plan.cols[bi, kt]
                if not cols:
                    continue
                oc_a += R * (n1 - n0) * T                      # packer reads the raw trains of this K-tile
                rawr += R * (n1 - n0) * T
                key = (kt, n0)
                if key not in cache:
                    cache[key] = len(pack_spikes(tile_masks(Sp[kt * R:(kt + 1) * R, n0:n1], T), G, cfg.W_open))
                P = cache[key]
                if P == 0:
                    continue
                St = Sp[kt * R:(kt + 1) * R, n0:n1]
                touched = ((Wt != 0).astype(np.float32) @ (St != 0).astype(np.float32)) > 0
                rmw += int(touched.sum())                        # running-sum entries written by the edge unit
                dirty |= touched
                gw += P * gbits                                  # packer writes the groups once
                for pas in _passes(cols, C):
                    oc_w += len(pas) * (R * 10 + F * 6)
                    pe_w += len(pas) * R * 10
                    oc_a += P * gbits
                    pe_a += P * R * C * 3 * T
                    # running-sum bundle (F x G x T sums of SW bits + F x G touch bits) passed down each loaded
                    # column into rows 1..R-1 (row 0 starts from zero), once per group (ours_pe b_sum / b_tch)
                    pe_s += len(pas) * P * (R - 1) * (F * G * T * SW + F * G)
            lifr += int(dirty.sum())
    return oc_w, oc_a, pe_w, pe_a, rmw, lifr, gw, rawr, pe_s


# ------------------------------------------------------------------------------------------------ SpikeX
def spikex_layer(W, S):
    from baselines import spikex_layer_cycles
    M = W.shape[0]
    tot, mode = spikex_layer_cycles(S, M)
    tws = int(mode.split("TWS=")[1])
    walked = (tot - (8 + 8 - 2)) / math.ceil(M / 8) / tws        # inputs walked per 8-channel block
    oc_w = M * walked * 8
    oc_a = math.ceil(M / 8) * walked * 8 * tws
    return oc_w, oc_a, oc_w * 8, oc_a * 8


# ------------------------------------------------------------------------------------------------ SpikeFlow
def spikeflow_layer(W, S):
    from baselines import spikeflow_layer_cycles
    M = W.shape[0]
    tot = spikeflow_layer_cycles(S, M)
    walked = (tot - (16 + 16 - 2)) / math.ceil(M / 16)
    oc_w = M * walked * 8
    oc_a = math.ceil(M / 16) * walked * 16
    return oc_w, oc_a, oc_w * 16, oc_a * 16


# ------------------------------------------------------------------------------------------------ LoAS
def loas_layer(W, S):
    from loas_model import _chunk_cycles, _rounds, TPPES, CHUNK, LAGGY, BUS
    M, K = W.shape
    N = S.shape[1]
    cyc = {}
    for axis in (1, 0):
        tot = rounds = 0
        for c in _chunk_cycles(W, S, CHUNK, LAGGY, BUS):
            t, r = _rounds(c, axis, TPPES)
            tot += t
            rounds = r
        cyc[axis] = tot + rounds
    axis = 1 if cyc[1] <= cyc[0] else 0                         # the model's min(); ties -> A (axis 1, first)
    wnz, snz = W != 0, S != 0
    oc_w = oc_a = pe_w = pe_a = 0
    for c0 in range(0, K, CHUNK):
        nnzw = wnz[:, c0:c0 + CHUNK].sum(1)                      # (M,)
        match = int(np.rint(wnz[:, c0:c0 + CHUNK].astype(np.float32).sum(0)
                            @ snz[c0:c0 + CHUNK].astype(np.float32)).sum())   # total matches over (m, n)
        fib_w = 128 + 8 * nnzw                                   # weight fibre bits per channel
        if axis == 1:        # A: 16 pixels share the weight fibre (broadcast)
            rounds = math.ceil(N / TPPES)
            oc_w += int(fib_w.sum()) * rounds
            pe_w += int(fib_w.sum()) * rounds * TPPES
            a = M * N * 128 + T * match
            oc_a += a
            pe_a += a
        else:                # B: 16 channels share the spike bitmask (broadcast)
            rounds = math.ceil(M / TPPES)
            oc_a += N * rounds * 128 + T * match
            pe_a += N * rounds * TPPES * 128 + T * match
            w = int(fib_w.sum()) * N
            oc_w += w
            pe_w += w
    return oc_w, oc_a, pe_w, pe_a


def base():
    import workload as wl
    from multiprocessing import Pool
    tasks = [(net, li) for net in NETS for li in range(len(wl.NETWORKS[net]()))]
    with Pool(8) as p:
        res = p.map(_base_one, tasks)
    out = {}
    for (net, li), r in zip(tasks, res):
        for d, v in r.items():
            acc = out.setdefault(f"{net}|{d}", [0] * len(v))
            for i in range(len(v)):
                acc[i] += v[i]
    res = {}
    for k, v in out.items():
        res[k] = dict(onchip_wgt_MB=v[0] / MB / B, onchip_act_MB=v[1] / MB / B, pe_wgt_MB=v[2] / MB / B,
                      pe_act_MB=v[3] / MB / B)
        if len(v) > 4:
            res[k].update(obuf_rmw_entries=v[4] / B, lif_reads_entries=v[5] / B, group_write_MB=v[6] / MB / B,
                          packer_raw_read_MB=v[7] / MB / B, pe_psum_MB=v[8] / MB / B)
    out = res
    json.dump(out, open(os.path.join(R_, f"mem_levels_base{SFX}.json"), "w"), indent=1)
    for k, v in out.items():
        print(k, {x: round(y, 3) for x, y in v.items()}, flush=True)


def _base_one(t):
    import workload as wl
    net, li = t
    layer = wl.NETWORKS[net]()[li]
    W, S = tensors(net, li, layer)
    return {"ours": ours_layer(W, S), "spikex": spikex_layer(W, S), "spikeflow": spikeflow_layer(W, S),
            "loas_zip": loas_layer(W, S)}


# ------------------------------------------------------------------------------------------------ official models
def prosperity():
    import prosperity_official as P
    S = P.S
    out = {}
    for net in NETS:
        S.clear_global_stats()
        sim = S.Simulator(accelerator=P.prosperity_accel(), network=P.our_ops(net, B, WD, NS, Q),
                          benchmark_name=f"{net}_lv", use_cuda=False)
        import contextlib, io
        with contextlib.redirect_stdout(io.StringIO()):
            st = sim.sim()
        ga, gw = st.reads["g_act"] / B, st.reads["g_wgt"] / B      # bits (spikes 1 bit each; weights x nbits)
        out[f"{net}|prosperity"] = dict(onchip_wgt_MB=gw / MB, onchip_act_MB=ga / MB, pe_wgt_MB=gw / MB,
                                        pe_act_MB=0.0, cycles=int(st.total_cycles),
                                        reads_bits={k: float(v) / B for k, v in st.reads.items()},
                                        writes_bits={k: float(v) / B for k, v in st.writes.items()})
        print(net, out[f"{net}|prosperity"], flush=True)
    json.dump(out, open(os.path.join(R_, f"mem_levels_prosperity{SFX}.json"), "w"), indent=1)


def ptb():
    from multiprocessing import Pool
    with Pool(2) as p:
        res = p.map(_ptb_one, NETS)
    out = {}
    for net, (cyc, slots, pairs, wbits, abits) in zip(NETS, res):
        out[f"{net}|ptb"] = dict(onchip_wgt_MB=wbits / MB, onchip_act_MB=abits / MB, pe_wgt_MB=wbits * 8 / MB,
                                 pe_act_MB=abits * 16 / MB, cycles=cyc, slots=slots, pairs=pairs)
        print(net, out[f"{net}|ptb"], flush=True)
    json.dump(out, open(os.path.join(R_, "mem_levels_ptb.json"), "w"), indent=1)


def _ptb_one(net):
    """the official run_simulation_PTB on image 0, with run_PTB_convfc / StSAP wrapped to record per layer the
    StSAP slots (input_length), the non-empty input rows (so pairs = rows - slots) and the output channels."""
    import contextlib, io
    import prosperity_official as P
    pb = sys.modules["p_baselines"]
    rec = []
    orig_st, orig_conv = pb.StSAP, pb.run_PTB_convfc

    def st_wrap(act):
        n = orig_st(act)
        a = act != 0
        full = a.all(-1)
        nz = a.any(-1)
        rec.append([n, int(nz.sum()), int(full.sum())])       # slots, non-empty rows, all-nonzero (unpaired) rows
        return n

    def conv_wrap(op):
        s = orig_conv(op)
        rec[-1].append(op.output_channel if hasattr(op, "output_channel") else op.output_dim)
        return s

    pb.StSAP, pb.run_PTB_convfc = st_wrap, conv_wrap
    try:
        with contextlib.redirect_stdout(io.StringIO()):
            cyc = int(pb.run_simulation_PTB(P.ptb_ops_image(net, 1, 0, WD, NS, Q)).total_cycles)
    finally:
        pb.StSAP, pb.run_PTB_convfc = orig_st, orig_conv
    slots = pairs = wbits = abits = 0
    for n, nz, full, M in rec:
        pr = nz - n                                            # each pair removes one slot
        slots += n
        pairs += pr
        wbits += (n + pr) * M * 8                              # one weight per row per slot, two for a pair
        abits += math.ceil(M / 16) * (n * 8 * 4 + pr * 8)      # 8 columns x TWS=4 bits, + owner bit for a pair
    return cyc, slots, pairs, wbits, abits


# ------------------------------------------------------------------------------------------------ SATO (official)
def sato():
    import workload as wl
    out = {}
    for net in NETS:
        w = a = 0
        for li, layer in enumerate(wl.NETWORKS[net]()):
            Wm, S = tensors(net, li, layer)
            M, K = Wm.shape
            N = S.shape[1]
            spikes = int(wl.popcount8(S).sum())
            a += T * N * K                                     # every (t, pixel) row's K-bit spike vector once
            w += spikes * M * 8                                # each spike: its input's M weights, 8 bits each
        w, a = w / B, a / B
        out[f"{net}|sato"] = dict(onchip_wgt_MB=w / MB, onchip_act_MB=a / MB, pe_wgt_MB=w / MB, pe_act_MB=a / MB)
        print(net, out[f"{net}|sato"], flush=True)
    json.dump(out, open(os.path.join(R_, f"mem_levels_sato{SFX}.json"), "w"), indent=1)


if __name__ == "__main__" and len(sys.argv) > 1 and sys.argv[1] in ("base", "prosperity", "ptb", "sato"):
    {"base": base, "prosperity": prosperity, "ptb": ptb, "sato": sato}[sys.argv[1]]()


# ------------------------------------------------------------------------------------------------ table + figure
ORDER = ["ptb", "spikex", "loas_zip", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "loas_zip": "LoAS", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "Ours"}
LEVELS = (("off", "Off-chip"), ("onchip", "On-chip"), ("pe", "PE"))


def load():
    d = {}
    for m in ("base", "prosperity", "ptb", "sato"):
        d.update(json.load(open(os.path.join(R_, f"mem_levels_{m}.json"))))
    off = json.load(open(os.path.join(R_, "mem_traffic_base.json")))
    off.update(json.load(open(os.path.join(R_, "mem_traffic_prosperity.json"))))
    for net in NETS:
        for k in ORDER:
            o = off[f"{net}|1|{k}"]
            d[f"{net}|{k}"].update(off_wgt_MB=o["wgt_MB"], off_act_MB=o["act_MB"])
    return d


def table():
    d = load()
    L = ["# Weight and activation traffic per inference at three levels (MB), sparse90, batch 1", "",
         "Off-chip: DRAM -> on-chip buffers (mem_traffic.py). On-chip: buffers -> PE array (reads). PE: operand bits "
         "latched by the PEs, once per receiving PE (broadcast / systolic forwarding counted per PE). Rules per design "
         "in mem_levels.py. Normalized = (weights + activations) / PTB at the same level.", "",
         "| Network | Design | Off-chip wgt | Off-chip act | On-chip wgt | On-chip act | PE wgt | PE act | "
         "Off-chip total (norm.) | On-chip total (norm.) | PE total (norm.) |",
         "|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|"]
    for net in NETS:
        p = d[f"{net}|ptb"]
        for k in ORDER:
            r = d[f"{net}|{k}"]
            tot = {lv: r[f"{lv}_wgt_MB"] + r[f"{lv}_act_MB"] for lv, _ in LEVELS}
            ref = {lv: p[f"{lv}_wgt_MB"] + p[f"{lv}_act_MB"] for lv, _ in LEVELS}
            L.append(f"| {net} | {NAME[k]} | " + " | ".join(f"{r[f'{lv}_{x}_MB']:.2f}" for lv, _ in LEVELS
                                                           for x in ("wgt", "act")) + " | " +
                     " | ".join(f"{tot[lv]:.2f} ({tot[lv] / ref[lv]:.2f}x)" for lv, _ in LEVELS) + " |")
    open(os.path.join(R_, "mem_levels.md"), "w").write("\n".join(L) + "\n")
    print("\n".join(L))
    # one figure: per network x level, bars normalized to PTB; weights (solid) + activations (light) stacked
    import plot_ptb_style as PS
    from matplotlib.patches import Patch
    from matplotlib.colors import to_rgb
    plt, FS = PS.plt, PS.FS
    fig, ax = plt.subplots(figsize=(FS.TEXT, 2.3))
    w, gap = 0.112, 0.008
    xs = []
    for gi, (net, (lv, lname)) in enumerate([(n, l) for n in NETS for l in LEVELS]):
        x0 = gi + (0.35 if gi >= 3 else 0)
        xs.append(x0)
        p = d[f"{net}|ptb"]
        ref = p[f"{lv}_wgt_MB"] + p[f"{lv}_act_MB"]
        for i, k in enumerate(ORDER):
            r = d[f"{net}|{k}"]
            x = x0 + (i - (len(ORDER) - 1) / 2) * (w + gap)
            vw, va = r[f"{lv}_wgt_MB"] / ref, r[f"{lv}_act_MB"] / ref
            st = PS.STYLE[k]
            light = tuple(0.55 + 0.45 * c for c in to_rgb(st["color"]))
            ax.bar(x, vw, w, color=st["color"], hatch=st["hatch"], edgecolor=PS.EDGE, linewidth=0.5, zorder=3)
            ax.bar(x, va, w, bottom=vw, color=light, hatch=st["hatch"], edgecolor=PS.EDGE, linewidth=0.5, zorder=3)
            if k == "ours":
                ax.annotate(f"{vw + va:.2f}", (x, vw + va), xytext=(0, 2), textcoords="offset points", ha="center",
                            va="bottom", fontsize=6.5, rotation=90, color=FS.OURS_TEXT, zorder=5,
                            bbox=dict(boxstyle="square,pad=0.06", fc="white", ec="none"))
    ax.set_xticks(xs, [l for _, l in LEVELS] * 2)
    for xc, net in ((xs[1], NETS[0]), (xs[4], NETS[1])):
        ax.text(xc, -0.16, net, transform=ax.get_xaxis_transform(), ha="center", va="top", fontsize=8)
    ax.axvline((xs[2] + xs[3]) / 2, color=PS.EDGE, lw=0.5, zorder=1)
    ax.set_xlim(xs[0] - 0.55, xs[-1] + 0.55)
    ax.set_ylabel("Normalized traffic (PTB = 1)")
    top = max((d[f"{n}|{k}"][f"{lv}_wgt_MB"] + d[f"{n}|{k}"][f"{lv}_act_MB"]) /
              (d[f"{n}|ptb"][f"{lv}_wgt_MB"] + d[f"{n}|ptb"][f"{lv}_act_MB"])
              for n in NETS for k in ORDER for lv, _ in LEVELS)
    ax.set_ylim(0, top * 1.45)
    ax.yaxis.grid(True, zorder=0)
    h = [Patch(facecolor=PS.STYLE[k]["color"], hatch=PS.STYLE[k]["hatch"], edgecolor=PS.EDGE, linewidth=0.5,
               label=NAME[k]) for k in ORDER]
    h += [Patch(facecolor="#6f6f6f", edgecolor=PS.EDGE, linewidth=0.5, label="Weights"),
          Patch(facecolor="#d4d4d4", edgecolor=PS.EDGE, linewidth=0.5, label="Activations")]
    FS.inside_legend(ax, h, [x.get_label() for x in h], ncol=5, loc="upper center")
    fig.subplots_adjust(left=0.065, right=0.995, top=0.985, bottom=0.2)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R_, f"mem_levels.{ext}"))


if __name__ == "__main__" and len(sys.argv) > 1 and sys.argv[1] == "table":
    table()
