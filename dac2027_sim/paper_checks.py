"""
paper_checks.py -- do our PTB / SpikeX cycle models reproduce what the papers (and a third party) report?

  1. SpikeX paper, Fig. 10: CONV2 of DVS-Gesture Medium (Table II: H=32, R=8, E=5, C=8, M=16, T=300), random
     input spikes at firing rates 0.01%..5%, SpikeX agile NTWU dispatch vs the PTB baseline on the same 8x8 array
     (PTB with its best fixed TWS, found by exhaustive search, as the SpikeX paper states). Paper: 7.11x at 0.01%
     falling to 1.30x at 5%.
  2. PTB vs the PTB model inside the official Prosperity simulator (HPCA'25), on the authors' REAL spike data
     (VGG16 / ResNet18, CIFAR10/100): compute cycles of both models.

The models here are the long-T generalization of baselines.ptb_layer_cycles / spikex_layer_cycles (identical
when T/TWS <= array width, the T=8 case used everywhere else):
  PTB    : per output pixel and channel block, the TWs are mapped 'cols' at a time onto the columns; per such time
           block the active inputs (tag != 0 in the block) are StSAP-paired and stream through, TWS cycles each.
  SpikeX : agile dispatch packs only ACTIVE NTWUs onto the 8 columns. Temporal mode: a pixel's active TWs, 8 at
           a time; spatial mode: one TW's active pixels, 8 at a time. Each batch walks the union of active inputs
           of its 8 NTWUs, TWS cycles per input. Best of mode x TWS.
"""
import json, math, os, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
from baselines import ptb_pairs_count


def tags_long(X, tws):
    """X: (K, N, T) bool -> (K, N, nw) bool, TW tag = any spike in the window."""
    K, N, T = X.shape
    nw = math.ceil(T / tws)
    pad = nw * tws - T
    if pad:
        X = np.concatenate([X, np.zeros((K, N, pad), dtype=bool)], 2)
    return X.reshape(K, N, nw, tws).any(3)


def ptb_long(X, M, rows=16, cols=8, tws_list=None):
    """PTB: an input is trimmed only if silent over the WHOLE time stride (PTB Sec. 4.4.1); the remaining
    (StSAP-paired) inputs stream through every time block of 'cols' TWs, TWS cycles each."""
    K, N, T = X.shape
    tws_list = tws_list or [d for d in range(1, T + 1) if T % d == 0]
    best = None
    for tws in tws_list:
        tag = tags_long(X, tws)                       # K, N, nw
        nw = tag.shape[2]
        nblk = math.ceil(nw / cols)
        if nw <= cols:
            code = (tag * (1 << np.arange(nw))).sum(2)
            slots = int(ptb_pairs_count(code, nw).sum())
        else:
            slots = sum(stsap_slots_big(tag[:, n, :]) for n in range(N))
        cyc = math.ceil(M / rows) * slots * nblk * tws + rows + cols - 2
        if best is None or cyc < best[0]:
            best = (cyc, tws)
    return best


def stsap_slots_big(tag):
    """StSAP for long TB-tags (python ints): bursting alone, others paired greedily, complement first then the
    non-overlapping tag with most bits."""
    full = (1 << tag.shape[1]) - 1
    codes = [int(sum(1 << i for i in np.nonzero(r)[0])) for r in tag]
    codes = [x for x in codes if x]
    slots = sum(1 for x in codes if x == full)
    rest = sorted((x for x in codes if x != full), key=lambda x: -bin(x).count("1"))
    used = [False] * len(rest)
    for i, a in enumerate(rest):
        if used[i]:
            continue
        used[i] = True
        slots += 1
        best, bj = -1, None
        for j in range(i + 1, len(rest)):
            if not used[j] and not (rest[j] & a):
                sc = 10**6 if rest[j] == full ^ a else bin(rest[j]).count("1")
                if sc > best:
                    best, bj = sc, j
        if bj is not None:
            used[bj] = True
    return slots


def spikex_long(X, M, rows=8, cols=8, tws_list=None):
    K, N, T = X.shape
    tws_list = tws_list or [d for d in range(1, T + 1) if T % d == 0]
    best = None
    for tws in tws_list:
        tag = tags_long(X, tws)                       # K, N, nw
        nw = tag.shape[2]
        act = tag.any(0)                              # N, nw : active NTWUs
        temporal = 0
        for n in range(N):
            tw = np.nonzero(act[n])[0]
            for g in range(0, len(tw), cols):
                temporal += int(tag[:, n, tw[g:g + cols]].any(1).sum())
        spatial = 0
        for w in range(nw):
            px = np.nonzero(act[:, w])[0]
            for g in range(0, len(px), cols):
                spatial += int(tag[:, px[g:g + cols], w].any(1).sum())
        for mode, c in (("temporal", temporal), ("spatial", spatial)):
            tot = math.ceil(M / rows) * c * tws + rows + cols - 2
            if best is None or tot < best[0]:
                best = (tot, f"{mode},TWS={tws}")
    return best


def im2col_long(X, k, s, p):
    """X: (C, H, W, T) bool -> (C*k*k, Ho*Wo, T)"""
    C, H, W, T = X.shape
    Xp = np.pad(X, ((0, 0), (p, p), (p, p), (0, 0)))
    Ho = (H + 2 * p - k) // s + 1
    cols = np.empty((C, k, k, Ho, Ho, T), dtype=bool)
    for i in range(k):
        for j in range(k):
            cols[:, i, j] = Xp[:, i:i + s * Ho:s, j:j + s * Ho:s, :]
    return cols.reshape(C * k * k, Ho * Ho, T)


PAPER_FIG10 = {0.0001: 7.11, 0.0002: 7.03, 0.0003: 7.02, 0.0004: 6.78, 0.0005: 6.51, 0.001: 5.43, 0.002: 3.96,
               0.003: 3.07, 0.004: 2.48, 0.005: 2.09, 0.01: 1.46, 0.02: 1.41, 0.03: 1.39, 0.04: 1.33, 0.05: 1.30}


def spikex_fig10():
    rng = np.random.default_rng(10)
    T, C, H, k, M = 300, 8, 32, 5, 16
    tws_list = [1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 25, 30, 50, 60, 75, 100, 150, 300]
    out = {}
    print("SpikeX Fig. 10 (CONV2, DVS-Gesture Medium, T=300, 8x8 array): SpikeX speed-up over PTB")
    print(f"{'firing rate':>12} {'paper':>7} {'ours':>7}   PTB best TWS | SpikeX best")
    for r, paper in PAPER_FIG10.items():
        X = rng.random((C, H, H, T)) < r
        S = im2col_long(X, k, 4, 1)                  # (32 + 2 - 5) // 4 + 1 = 8 -> 8x8 output
        ptb = ptb_long(S, M, rows=8, cols=8, tws_list=tws_list)
        spx = spikex_long(S, M, rows=8, cols=8, tws_list=tws_list)
        sp = ptb[0] / spx[0]
        out[r] = dict(paper=paper, ours=sp, ptb_cycles=ptb[0], ptb_tws=ptb[1], spikex_cycles=spx[0], spikex=spx[1])
        print(f"{r*100:11.2f}% {paper:6.2f}x {sp:6.2f}x   TWS={ptb[1]:<4d} | {spx[1]}", flush=True)
    return out


def ptb_vs_prosperity_repo():
    """our PTB model vs the PTB model of the official Prosperity simulator, on the authors' real spikes."""
    import torch, contextlib, io
    sys.path.insert(0, os.path.join(HERE, "third_party", "prosperity"))
    import prosperity_official  # noqa: F401  (installs the engine stub)
    import networks as NW
    from baselines import ptb_layer_cycles
    import baselines as B
    DATA = os.path.join(HERE, "third_party", "prosperity_data")
    third = __import__("baselines", fromlist=["run_PTB_convfc"])
    out = {}
    for name in ("vgg16_cifar10", "vgg16_cifar100", "resnet18_cifar10", "resnet18_cifar100"):
        ops = NW.create_network(name.split("_")[0], os.path.join(DATA, name + ".pkl"))
        theirs = ours = 0
        for op in ops:
            if not isinstance(op, (NW.Conv2D, NW.FC)):
                continue
            fc = NW.conv2d_2_fc(op) if isinstance(op, NW.Conv2D) else op
            T, L, K = fc.time_steps, fc.sequence_length, fc.input_dim
            x = fc.activation_tensor.sparse_map.reshape(T, L, K).bool().numpy()   # T, L, K
            Xl = x.transpose(2, 1, 0)                                            # K, L, T
            # theirs: TWS=4, StSAP, 16x8 array, + cold start; compute cycles only
            with contextlib.redirect_stdout(io.StringIO()):
                st = third_party_ptb(op)
            theirs += st
            c, tws = ptb_long(Xl, fc.output_dim, rows=16, cols=8, tws_list=[4])
            ours += c
        out[name] = dict(theirs=theirs, ours_tws4=ours, ratio=ours / theirs)
        print(f"{name:18s} PTB compute cycles: Prosperity repo {theirs:>12,}  ours (TWS=4) {ours:>12,}  ours/theirs {ours/theirs:.2f}",
              flush=True)
    return out


def third_party_ptb(op):
    """compute cycles of the official simulator's run_PTB_convfc (without its DRAM stall term)."""
    import importlib.util
    spec = importlib.util.spec_from_file_location("p_baselines", os.path.join(HERE, "third_party", "prosperity", "baselines.py"))
    mod = sys.modules.get("p_baselines")
    if mod is None:
        mod = importlib.util.module_from_spec(spec)
        sys.modules["p_baselines"] = mod
        spec.loader.exec_module(mod)
    return mod.run_PTB_convfc(op).compute_cycles


if __name__ == "__main__":
    res = {}
    what = sys.argv[1:] or ["fig10", "ptbrepo"]
    if "fig10" in what:
        res["spikex_fig10"] = spikex_fig10()
    if "ptbrepo" in what:
        res["ptb_vs_prosperity_repo"] = ptb_vs_prosperity_repo()
    path = os.path.join(HERE, "results", "paper_checks.json")
    old = json.load(open(path)) if os.path.exists(path) else {}
    old.update({k: {str(a): b for a, b in v.items()} for k, v in res.items()})
    json.dump(old, open(path, "w"), indent=1)


def spikeflow_fig17():
    """SpikeFlow Fig. 17: T=4, all designs with SpikeFlow's 256 PEs (Table 1). Paper averages (LeNet-MNIST,
    VGG-CIFAR10, VGG-CIFAR100): SpikeFlow vs Eyeriss +117% (2.17x), vs PTB +49.6% (1.50x).
    Data here: the real VGG9-CIFAR10 (T=4) spike traces of the Prosperity repo (the paper's own models are not
    released). Eyeriss at 256 PEs: dense, ceil(M/16) x K*T*L/16 (the Prosperity repo's Eyeriss rule, 16x16)."""
    import prosperity_official  # noqa: F401
    import networks as NW
    from baselines import ptb_layer_cycles, spikeflow_layer_cycles
    DATA = os.path.join(HERE, "third_party", "prosperity_data")
    ops = NW.create_network("vgg9", os.path.join(DATA, "vgg9_cifar10.pkl"))
    tot = dict(spikeflow=0, ptb=0, ptb_repo_rules=0, eyeriss=0, ptb_lif=0, eyeriss_lif=0)
    for op in ops:
        if not isinstance(op, (NW.Conv2D, NW.FC)):
            continue
        fc = NW.conv2d_2_fc(op) if isinstance(op, NW.Conv2D) else op
        T, L, K, M = fc.time_steps, fc.sequence_length, fc.input_dim, fc.output_dim
        x = fc.activation_tensor.sparse_map.reshape(T, L, K).bool().numpy()
        S = np.zeros((K, L), dtype=np.uint8)
        for t in range(T):
            S |= (x[t].T.astype(np.uint8) << t)
        tot["spikeflow"] += spikeflow_layer_cycles(S, M, T=T)
        tot["ptb"] += ptb_layer_cycles(S, M, T=T, rows=16, cols=16, tws_list=(1, 2, 4))[0]
        tot["eyeriss"] += math.ceil(M / 16) * (K * T * L // 16)
        # Sec. 5.2.1: the control groups use an independent LIF module (16 LIF units, Table 1) that runs after
        # the systolic array, time step by time step; SpikeFlow's LIF-PE row is pipelined with the array.
        lif = math.ceil(M * L * T / 16)
        tot["ptb_lif"] += ptb_layer_cycles(S, M, T=T, rows=16, cols=16, tws_list=(1, 2, 4))[0] + lif
        tot["eyeriss_lif"] += math.ceil(M / 16) * (K * T * L // 16) + lif
        # PTB with the Prosperity repo's rules: fixed TWS=4, per-pixel cold start of 2 x rows cycles
        tot["ptb_repo_rules"] += ptb_layer_cycles(S, M, T=T, rows=16, cols=16, tws_list=(4,))[0] + L * 16 * 2
    r = dict(cycles=tot, spikeflow_vs_eyeriss=tot["eyeriss"] / tot["spikeflow"],
             spikeflow_vs_ptb=tot["ptb"] / tot["spikeflow"],
             spikeflow_vs_ptb_repo_rules=tot["ptb_repo_rules"] / tot["spikeflow"],
             spikeflow_vs_eyeriss_lif=tot["eyeriss_lif"] / tot["spikeflow"], spikeflow_vs_ptb_lif=tot["ptb_lif"] / tot["spikeflow"],
             paper_vs_eyeriss=2.17, paper_vs_ptb=1.496)
    print(f"SpikeFlow Fig. 17 (VGG9-CIFAR10 real spikes, T=4, 256 PEs): SpikeFlow vs Eyeriss "
          f"{r['spikeflow_vs_eyeriss']:.2f}x (paper avg 2.17x), vs PTB {r['spikeflow_vs_ptb']:.2f}x / "
          f"{r['spikeflow_vs_ptb_repo_rules']:.2f}x with the Prosperity repo's PTB rules (paper avg 1.50x)\n"
          f"  + independent LIF module in the control groups (Sec. 5.2.1): vs Eyeriss {r['spikeflow_vs_eyeriss_lif']:.2f}x "
          f"(paper 2.17x), vs PTB {r['spikeflow_vs_ptb_lif']:.2f}x (paper 1.50x)")
    return r


if __name__ == "__main__" and "fig17" in sys.argv[1:]:
    path = os.path.join(HERE, "results", "paper_checks.json")
    old = json.load(open(path)) if os.path.exists(path) else {}
    old["spikeflow_fig17"] = spikeflow_fig17()
    json.dump(old, open(path, "w"), indent=1)


PAPER_FIG9 = {2: 93.9, 3: 92.0, 5: 91.1, 10: 90.4}   # % latency reduction, firing rate 0.5% -> 0.01%


def spikex_fig9(seeds=(0, 1, 2)):
    """SpikeX Fig. 9: CONV1 of N-MNIST (Table II: H=34, R=16, E=3, C=2, M=12, T=30 -> stride 2, no padding),
    random inputs, SpikeX latency at fixed TWS for firing rates 0.5% and 0.01%; paper reports the reduction."""
    T, C, H, k, M = 30, 2, 34, 3, 12
    out = {}
    print("SpikeX Fig. 9 (CONV1 N-MNIST, T=30): latency reduction 0.5% -> 0.01% firing rate")
    for tws, paper in PAPER_FIG9.items():
        red = []
        for sd in seeds:
            rng = np.random.default_rng(100 + sd)
            lat = {}
            for r in (0.005, 0.0001):
                X = rng.random((C, H, H, T)) < r
                S = im2col_long(X, k, 2, 0)                 # (34 - 3) // 2 + 1 = 16
                lat[r] = spikex_long(S, M, rows=8, cols=8, tws_list=[tws])[0]
            red.append(100 * (1 - lat[0.0001] / lat[0.005]))
        out[tws] = dict(paper=paper, ours=float(np.mean(red)))
        print(f"  TWS={tws:2d}: paper {paper:.1f}%   ours {np.mean(red):.1f}%")
    return out


if __name__ == "__main__" and "fig9" in sys.argv[1:]:
    path = os.path.join(HERE, "results", "paper_checks.json")
    old = json.load(open(path)) if os.path.exists(path) else {}
    old["spikex_fig9"] = {str(a): b for a, b in spikex_fig9().items()}
    json.dump(old, open(path, "w"), indent=1)


def spikex_fig10_variants():
    """Fig. 10 under the two readings the paper's text supports:
      A) 'with- and without agile NTWU dispatch' at the SAME TWS (only the dispatch differs);
      B) PTB at ONE fixed TWS for the layer (exhaustive search over the whole firing-rate sweep), SpikeX best."""
    rng = np.random.default_rng(10)
    T, C, H, k, M = 300, 8, 32, 5, 16
    tws_list = [1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 25, 30, 50, 60, 75, 100, 150, 300]
    rows = []
    for r in PAPER_FIG10:
        X = rng.random((C, H, H, T)) < r
        S = im2col_long(X, k, 4, 1)
        ptb = {t: ptb_long(S, M, rows=8, cols=8, tws_list=[t])[0] for t in tws_list}
        spx = {t: spikex_long(S, M, rows=8, cols=8, tws_list=[t])[0] for t in tws_list}
        rows.append((r, ptb, spx))
    # A: same TWS for both; report the TWS whose curve is closest to the paper (RMS of log ratio) and all others
    def rms(curve):
        return float(np.sqrt(np.mean([np.log(c / PAPER_FIG10[r]) ** 2 for r, c in curve])))
    curvesA = {t: [(r, p[t] / s[t]) for r, p, s in rows] for t in tws_list}
    # B: PTB fixed at the TWS minimising its total cycles over the sweep; SpikeX free per rate
    tb = min(tws_list, key=lambda t: sum(p[t] for _, p, _ in rows))
    curveB = [(r, p[tb] / min(s.values())) for r, p, s in rows]
    out = {"A_same_tws": {str(t): {"rms_log_err": rms(c), "curve": {str(r): v for r, v in c}} for t, c in curvesA.items()},
           "B_ptb_fixed_tws": {"tws": tb, "rms_log_err": rms(curveB), "curve": {str(r): v for r, v in curveB}}}
    print(f"{'rate':>7} {'paper':>6} | B: PTB fixed TWS={tb} | A same TWS=" + " ".join(f"{t:>5d}" for t in (1, 2, 5, 10, 30)))
    for i, r in enumerate(PAPER_FIG10):
        print(f"{r*100:6.2f}% {PAPER_FIG10[r]:6.2f} | {curveB[i][1]:6.2f}            | " +
              " ".join(f"{curvesA[t][i][1]:5.2f}" for t in (1, 2, 5, 10, 30)))
    print("RMS log error  B:", f"{rms(curveB):.2f}", " A:", " ".join(f"TWS{t}={rms(curvesA[t]):.2f}" for t in (1, 2, 5, 10, 30)),
          " current (both re-optimized per rate):", f"{rms([(r, min(p.values()) / min(s.values())) for r, p, s in rows]):.2f}")
    return out


if __name__ == "__main__" and "fig10v" in sys.argv[1:]:
    path = os.path.join(HERE, "results", "paper_checks.json")
    old = json.load(open(path)) if os.path.exists(path) else {}
    old["spikex_fig10_variants"] = spikex_fig10_variants()
    json.dump(old, open(path, "w"), indent=1)
