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
