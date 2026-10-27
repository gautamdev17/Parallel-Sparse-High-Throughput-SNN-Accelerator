"""
spikex_paper.py -- paper-faithful per-layer cycle model of SpikeX (Xu et al., arXiv:2505.12292), audit only.

Line numbers L### refer to scratchpad/papers/spikex.txt.

Hardware facts used
  * 8x8 systolic array (L846, L1157-1158). PE = ONE reusable accumulator + comparator + scratchpad (L349-350).
  * weights enter rows from the left and are shared along a row; activations enter columns from the top
    (L355-358, L508-510)  -> the whole array walks one common input sequence; rows = 8 output channels.
  * PE processes one NTWU(n, tw) = neuron n over the TWS time points of window tw (L359-361, L404-412).
    One accumulator -> one input costs TWS accumulate cycles (time points serial).
  * after integration: step 2 Vmem[t] updated sequentially over the TW's time points (L364-368), step 3
    spike generation per time point (L368-369).  Step 2 needs the accumulator -> +TWS cycles per dispatched
    NTWU batch; step 3 runs on the comparator (overlapped in the lenient variant, +TWS in strict).
  * zero-skipping by activity tags: per presynaptic neuron per TW (Fig. 2, L414-420, L432-440);
    "data or work with a zero-valued activity tag are not loaded or processed" (L418-420); NTWU level
    (L481-483).  Weight tailoring at input-channel granularity for conv (SP-MB = one IC, L557-561).
  * no weight-sparsity / zero-weight skipping anywhere in the paper (tailoring is driven by activations only,
    L336-338, L534-536).  -> cycles independent of W except M.
  * modes: temporal (default) iff avg active NTWUs per neuron > array width (L502-503); otherwise spatial,
    which packs active NTWUs of different neurons AND different TW grids that need the same weights into a
    row (L515-520, Fig. 3 caption L500-501).
  * TWS reconfigurable per layer, chosen by HAS (L370-375, L1151-1152, L1175-1176) -> best TWS per layer.
  * latency = worst case of data access and array computation, summed over operations (L933-938);
    DRAM 30 GB/s (L853), GLB 54 KB, LBUF 2 KB double-buffered (L850-853).

Variants
  lenient : per-(input, TW) tag skipping, best of {temporal, spatial-per-TW-grid (= current model),
            spatial pool pixel-major, spatial pool TW-major} x TWS; +TWS per batch (step 2); fill/drain once.
  strict  : paper's mode rule (L502-503; at T=8 never temporal), spatial pool TW-major, input-channel
            granularity skipping (all K/ci rows of an active IC walked, L557-561), +2*TWS per batch
            (steps 2 and 3 serial), fill/drain (rows+cols-2) per 8-output-channel pass, best TWS.
  *_mem   : max(compute, DRAM bytes / (30 GB/s / 500 MHz = 60 B/cycle)).  lenient: tailored 8-bit weights +
            input bits + output bits once.  strict: repo's cached SpikeX DRAM traffic (54 KB GLB tiling,
            untailored) -- read from the cache, nothing in the repo is modified.
"""
import json
import math
import os
import sys

import numpy as np

REPO = "/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/dac2027_sim"
SD = os.path.join(REPO, "results/prune_chain")
CACHE = os.path.join(REPO, "results/prune_chain_cache.json")
ROWS = COLS = 8
CLK = 500e6
DRAM_BPC = 30e9 / CLK          # bytes per cycle at the comparison's 500 MHz clock


def tags(S, tws, T):
    nw = T // tws
    tag = np.zeros(S.shape, dtype=np.uint8)
    for w in range(nw):
        tag |= (((S & (((1 << tws) - 1) << (w * tws))) != 0).astype(np.uint8) << w)
    return tag, nw


def _walk(units, gran):
    """units: (K, G, COLS) bool activity of the batch columns; returns walked inputs per batch (G,)."""
    u = units.any(2)                                   # (K, G) union over the 8 columns (lock-step row)
    if gran == 1:
        return u.sum(0)
    K, G = u.shape
    return u.reshape(K // gran, gran, G).any(1).sum(0) * gran


def _batches(act_cols, gran):
    """act_cols: (K, U) activity of the active NTWUs in dispatch order -> (walked per batch, #batches)."""
    K, U = act_cols.shape
    if U == 0:
        return np.zeros(0, dtype=np.int64)
    pad = (-U) % COLS
    if pad:
        act_cols = np.concatenate([act_cols, np.zeros((K, pad), dtype=bool)], 1)
    return _walk(act_cols.reshape(K, -1, COLS), gran)


KNOBS = dict(lenient=dict(ic=False, lif=1, rule=False, fill_per_pass=False),
             strict=dict(ic=True, lif=2, rule=True, fill_per_pass=True))


def layer_cycles(W, S, T, geom, variant="lenient"):
    """W (M,K), S (K,N) uint8 spike trains; geom = dict(ci=...). Returns (cycles, config).
    variant: 'lenient' / 'strict' or a knob dict (ic, lif, rule, fill_per_pass) for ablations."""
    M, K = W.shape
    N = S.shape[1]
    kn = KNOBS[variant] if isinstance(variant, str) else variant
    gran = K // geom["ci"] if kn["ic"] else 1
    lif = kn["lif"]
    passes = math.ceil(M / ROWS)
    fill = (ROWS + COLS - 2) * (passes if kn["fill_per_pass"] else 1)
    best = None
    for tws in [1 << i for i in range(T.bit_length()) if (1 << i) <= T]:
        if T % tws:
            continue
        tag, nw = tags(S, tws, T)
        if nw > COLS:
            continue
        bits = [((tag >> w) & 1).astype(bool) for w in range(nw)]          # nw x (K, N)
        ntwu = np.stack([b.any(0) for b in bits], 1)                        # (N, nw) active NTWUs
        cands = {}
        # temporal: one neuron per row batch, its nw TWs on nw columns
        tcols = np.stack(bits, 2)                                           # (K, N, nw)
        keep = ntwu.any(1)
        if keep.any():
            tw = _walk(tcols[:, keep, :], gran)
            cands["temporal"] = int(tw.sum()) * tws + lif * tws * int(keep.sum())
        else:
            cands["temporal"] = 0
        # spatial pools
        order_pm = [(n, w) for n in range(N) for w in range(nw) if ntwu[n, w]]
        order_tm = [(n, w) for w in range(nw) for n in range(N) if ntwu[n, w]]
        for name, order in (("spatial_pm", order_pm), ("spatial_tm", order_tm)):
            if not order:
                cands[name] = 0
                continue
            cols = np.stack([bits[w][:, n] for n, w in order], 1)
            b = _batches(cols, gran)
            cands[name] = int(b.sum()) * tws + lif * tws * len(b)
        # spatial per TW grid (the current model's packing: no batch crosses a TW grid)
        tot = 0
        for w in range(nw):
            live = np.nonzero(ntwu[:, w])[0]
            if live.size:
                b = _batches(bits[w][:, live], gran)
                tot += int(b.sum()) * tws + lif * tws * len(b)
        cands["spatial_grid"] = tot
        if not kn["rule"]:
            allowed = cands
        else:
            avg = ntwu.sum() / max(N, 1)                                    # avg active NTWUs per neuron
            allowed = {"temporal": cands["temporal"]} if avg > COLS else {"spatial_tm": cands["spatial_tm"]}
        for mode, c in allowed.items():
            tot = passes * c + fill
            if best is None or tot < best[0]:
                best = (tot, f"{mode},TWS={tws}")
    return best


def current_cycles(S, M, T):
    sys.path.insert(0, REPO)
    import baselines as ob
    return ob.spikex_layer_cycles(S, M, T=T, tws_list=tuple(1 << i for i in range(T.bit_length())))


def mem_lenient_bytes(W, S, T, geom, meta):
    M, K = W.shape
    gran = K // geom["ci"]
    ic_act = (S != 0).reshape(geom["ci"], gran, -1).any((1, 2)).sum()      # ICs with any activity in the layer
    w_bytes = M * gran * ic_act                                              # tailored dense 8-bit weights
    return w_bytes + meta["raw_n"] * T / 8 + M * S.shape[1] * T / 8


def ablate(lvl="sp98", T=8):
    """one paper-strict knob at a time on top of lenient, layer totals."""
    d = np.load(os.path.join(SD, f"VGG16_{lvl}.npz"))
    meta = json.load(open(os.path.join(SD, f"VGG16_{lvl}.json")))["layers"]
    base = KNOBS["lenient"]
    tests = {"lenient": base, "+rule(spatial only)": dict(base, rule=True), "+IC granularity": dict(base, ic=True),
             "+LIF 2*TWS": dict(base, lif=2), "+fill per pass": dict(base, fill_per_pass=True),
             "no LIF (current-like)": dict(base, lif=0), "strict": KNOBS["strict"]}
    tot = {k: 0 for k in tests}
    for li, m in enumerate(meta):
        if m["analog"]:
            continue
        for k, v in tests.items():
            tot[k] += layer_cycles(d[f"W{li}"], d[f"S{li}"], T, dict(ci=m["ci"]), v)[0]
    for k, v in tot.items():
        print(f"{lvl} {k:24s} {v:>12,}  ({v / tot['lenient']:.3f}x lenient)")


def main():
    cache = json.load(open(CACHE))
    T = 8
    out = {}
    for lvl in ("dense", "sp90", "sp95", "sp98"):
        d = np.load(os.path.join(SD, f"VGG16_{lvl}.npz"))
        meta = json.load(open(os.path.join(SD, f"VGG16_{lvl}.json")))["layers"]
        rows = []
        for li, m in enumerate(meta):
            if m["analog"]:
                continue
            W, S = d[f"W{li}"], d[f"S{li}"]
            M = W.shape[0]
            geom = dict(ci=m["ci"])
            cached = cache[repr(("VGG16", lvl, li))]
            cur = cached["cycles"]["spikex"]
            re_cur = current_cycles(S, M, T)
            L = layer_cycles(W, S, T, geom, "lenient")
            St = layer_cycles(W, S, T, geom, "strict")
            mL = mem_lenient_bytes(W, S, T, geom, m) / DRAM_BPC
            mS = cached["counts"]["spikex"]["dram"] / 8 / DRAM_BPC
            rows.append(dict(li=li, name=m["name"], cur=cur, cur_cfg=re_cur[1], recomputed=int(re_cur[0]),
                             len=L[0], len_cfg=L[1], strict=St[0], strict_cfg=St[1],
                             len_mem=max(L[0], mL), strict_mem=max(St[0], mS), memL=mL, memS=mS))
            r = rows[-1]
            print(f"{lvl:5s} {li:2d} {m['name']:13s} cur {cur:>9,} ({r['cur_cfg']:<17s}) "
                  f"len {L[0]:>9,} ({L[1]:<20s}) strict {St[0]:>10,} ({St[1]:<18s}) "
                  f"memL {mL:>9,.0f} memS {mS:>10,.0f}", flush=True)
            assert r["recomputed"] == cur, "cache mismatch"
        tot = {k: sum(r[k] for r in rows) for k in ("cur", "len", "strict", "len_mem", "strict_mem")}
        out[lvl] = dict(layers=rows, totals=tot)
        print(f"{lvl} TOTAL " + "  ".join(f"{k} {v:,.0f} ({v / tot['cur']:.2f}x)" for k, v in tot.items()))
    json.dump(out, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "results.json"), "w"), indent=1)


if __name__ == "__main__":
    main()
    for lv in ("dense", "sp98"):
        ablate(lv)
