"""Paper-faithful PTB (Lee et al., MICRO'21) per-layer cycle model + comparison with the official Prosperity-repo
PTB model as used in dac2027_sim/prune_chain.py.  Audit script: reads repo files, writes nothing in the repo.

Paper facts used (line numbers = papers/ptb.txt):
  * 128 PEs, 16 x 8 array (H16/W8)                                   L1013, L1036-1042, L1199, L1285-1287
  * row = one post-synaptic neuron (output channel at a pixel), its TWs on the columns;
    column = one TW for different post-synaptic neurons                 L735-740, L1239-1243, Fig.6
  * spikes flow vertically (shared down a column), weights horizontally (reused along a row)  L649-650, L801-806
  * # of TWs = array width; TW ranges from 1 to "cover all time-points with given array width"  L917-918, L1005-1006
    -> TW = T / 8 ; at T = 8 this forces TW = 1 (8 TWs of 1 timestep on the 8 columns)
  * silent inputs (all-zero TB-tag over the TS) are trimmed, not fetched    L672-676, L962-965
  * StSAP: pair non-bursting TBs, 1's complement first, else nearest non-overlapping tag, max 2 per slot  L976-980
  * PE = one 8-bit AC + comparator + scratchpad; Step B local; paper models only Step A   L637-645, L651-654, L1014
  * latency per array iteration = max(data access, compute), double buffered, sum over iterations  L1080-1087
  * DRAM 30 GB/s, GLB 54 KB (clock not given -> 500 MHz, our CLK)      L1015-1018
Open points (lenient / strict):
  * fill/drain per array iteration: lenient = one 16+8-2 fill per layer (iterations overlap, psums in scratchpad);
    strict = SCALE-Sim [29] output-stationary fold overhead 2*16+8-2 = 38 per (pixel, 16-channel) iteration
  * StSAP "nearest": lenient = ideal (bursting + ceil(nonbursting/2)); paper = histogram greedy
    (complement, then fullest non-overlapping tag); strict = same greedy (no better reading found)
  * cycles per TB: TW (one adder per PE, strict) vs 1 (lenient); identical at TW = 1
"""
import contextlib, io, json, math, os, sys
import numpy as np

REPO = "/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/dac2027_sim"
ROWS, COLS = 16, 8
BPC = 30e9 / 500e6                        # DRAM bytes / cycle (30 GB/s, 500 MHz)
POPC = np.array([bin(v).count("1") for v in range(256)])


def tags(S, T, tw):
    """(K,N) uint8 trains -> (K,N) TB-tags with T/tw bits (bit w = any spike in window w)."""
    nw = T // tw
    g = np.zeros(S.shape, np.uint8)
    for w in range(nw):
        g |= ((S & (((1 << tw) - 1) << (w * tw))) != 0).astype(np.uint8) << w
    return g, nw


def stsap_slots(tag, nw, ideal=False):
    """per-pixel packed input slots: bursting + pairs + unpaired non-bursting (silent trimmed)."""
    full = (1 << nw) - 1
    K, N = tag.shape
    H = np.zeros((N, 1 << nw), np.int64)
    np.add.at(H, (np.broadcast_to(np.arange(N), (K, N)).ravel(), tag.astype(np.int64).ravel()), 1)
    burst = H[:, full].copy()
    H[:, 0] = H[:, full] = 0
    if ideal:
        return burst + (H.sum(1) + 1) // 2
    pairs = np.zeros(N, np.int64)
    for a in sorted(range(1, full), key=lambda v: (-POPC[v], v)):          # start from the fullest TBs
        cand = [b for b in range(1, full) if b & a == 0 and b != a]
        cand.sort(key=lambda b: (b != full ^ a, -POPC[b], abs(b - a)))      # complement, then nearest
        for b in cand:
            m = np.minimum(H[:, a], H[:, b])
            H[:, a] -= m; H[:, b] -= m; pairs += m
    return burst + pairs + H.sum(1)


def ptb_paper_cycles(W, S, T, geom=None, variant="paper", tw=None):
    """W (M,K), S (K,N) uint8 trains. Returns dict(cycles, compute, overhead, mem, tw).
    variant: 'lenient' (ideal packing, one fill), 'paper' (greedy StSAP, one fill), 'strict' (greedy, 38/iter)."""
    M, K = W.shape
    N = S.shape[1]
    tw = tw or max(1, T // COLS)
    g, nw = tags(S, T, tw)
    slots = stsap_slots(g, nw, ideal=(variant == "lenient"))
    tiles = math.ceil(M / ROWS)
    compute = tiles * int(slots.sum()) * tw                       # tw cycles per TB (1 at TW=1)
    if variant == "strict":
        over = N * tiles * (2 * ROWS + COLS - 2)
    else:
        over = ROWS + COLS - 2
    raw_in = (geom or {}).get("raw_n", K * N) * T / 8
    mem = (M * K + raw_in + M * N * T / 8) / BPC                  # dense 8-bit weights once + spikes in/out
    return dict(cycles=max(compute + over, int(mem)), compute=compute, overhead=over, mem=int(mem), tw=tw)


def official_breakdown(W, S, T, M):
    """replicates prune_chain.layer_sim PTB block, split into StSAP compute / cold start / mem stall / LIF."""
    sys.path.insert(0, REPO)
    os.chdir(REPO)
    import baselines  # noqa: F401  (ours first, as prune_chain does)
    import prosperity_official as P
    import prune_sweep as PS
    PS.T = T
    pb = sys.modules["p_baselines"]
    K, N = S.shape
    out = dict(stsap=0, cold=0, stall=0, lif=0)
    al = max(1, 32 // T)
    with contextlib.redirect_stdout(io.StringIO()):
        for a, b in PS.chunks(N, K, al):
            Sc = S[:, a:b]
            if Sc.shape[1] > 1 and Sc.shape[1] % al:
                Sc = np.pad(Sc, ((0, 0), (0, -Sc.shape[1] % al)))
            st = pb.run_PTB_convfc(PS.fc_op(P, "fc", Sc, M))
            cold = Sc.shape[1] * 32
            out["cold"] += cold
            out["stsap"] += st.compute_cycles - cold
            out["stall"] += st.mem_stall_cycles
            out["lif"] += pb.run_PTB_lif(P.NW.LIFNeuron("lif", M * (b - a), 1, T)).compute_cycles
    out["total"] = sum(out.values())
    return out


def main(levels=("dense", "sp90", "sp95", "sp98"), net="VGG16", T=8):
    cache = json.load(open(os.path.join(REPO, "results/prune_chain_cache.json")))
    res = {}
    for lvl in levels:
        d = np.load(os.path.join(REPO, f"results/prune_chain/{net}_{lvl}.npz"))
        meta = json.load(open(os.path.join(REPO, f"results/prune_chain/{net}_{lvl}.json")))["layers"]
        rows = []
        for li, e in enumerate(meta):
            if e["analog"]:
                continue
            W, S = d[f"W{li}"].astype(np.int16), d[f"S{li}"]
            cur = cache[str((net, lvl, li))]["cycles"]["ptb"]
            r = dict(name=e["name"], M=W.shape[0], K=W.shape[1], N=S.shape[1], current=cur)
            for v in ("lenient", "paper", "strict"):
                r[v] = ptb_paper_cycles(W, S, T, e, v)
            r["tw4_paper_map"] = ptb_paper_cycles(W, S, T, e, "paper", tw=4)["cycles"]
            r["official"] = official_breakdown(W, S, T, W.shape[0])
            rows.append(r)
            print(f"{lvl:5s} {e['name']:13s} M{r['M']:5d} K{r['K']:5d} N{r['N']:5d} cur {cur:9d} "
                  f"(rep {r['official']['total']:9d}: st {r['official']['stsap']:8d} cold {r['official']['cold']:7d} "
                  f"stall {r['official']['stall']:6d} lif {r['official']['lif']:7d}) | "
                  f"len {r['lenient']['cycles']:9d} pap {r['paper']['cycles']:9d} str {r['strict']['cycles']:9d} "
                  f"mem {r['paper']['mem']:7d} tw4 {r['tw4_paper_map']:9d}", flush=True)
        tot = {k: sum(r[k]["cycles"] if isinstance(r[k], dict) and "cycles" in r[k] else 0 for r in rows)
               for k in ("lenient", "paper", "strict")}
        tot["current"] = sum(r["current"] for r in rows)
        tot["tw4_paper_map"] = sum(r["tw4_paper_map"] for r in rows)
        for k in ("stsap", "cold", "stall", "lif"):
            tot["off_" + k] = sum(r["official"][k] for r in rows)
        res[lvl] = dict(layers=rows, total=tot)
        print(f"== {lvl}: current {tot['current']}  lenient {tot['lenient']} ({tot['lenient']/tot['current']:.3f}x)  "
              f"paper {tot['paper']} ({tot['paper']/tot['current']:.3f}x)  strict {tot['strict']} "
              f"({tot['strict']/tot['current']:.3f}x)  | official parts " +
              " ".join(f"{k[4:]} {tot[k]}" for k in tot if k.startswith("off_")), flush=True)
    json.dump(res, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "ptb_paper_results.json"), "w"),
              indent=1, default=int)


if __name__ == "__main__":
    main(tuple(sys.argv[1:]) or ("dense", "sp90", "sp95", "sp98"))
