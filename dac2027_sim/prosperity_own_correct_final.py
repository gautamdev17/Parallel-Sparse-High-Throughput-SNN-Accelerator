"""
prosperity_own_correct_final.py -- Prosperity's per-tile pipeline as described in its own paper (prosperity.pdf, HPCA'25, Sec. VI
"Pipeline Scheduling"), against the official simulator (third_party/prosperity simulator.run_fc), on the chained traces
of prune_chain.py.

Paper, Sec. VI-A/B, per tile of m spike rows x k = 16 columns (and per 128-wide output tile, as the simulator):
  ProSparsity phase (Detector -> Pruner -> Dispatcher, 5-stage pipeline, 1 spike row per cycle): m + 4 cycles
  computation phase (Processor, 4 stages: issue, decode/load, execute, write back): >= m + 4 cycles; a row takes
      popcount(ProSparsity pattern) cycles, at least 1 (an issued row occupies an issue slot)
  inter-phase pipeline: the ProSparsity phase of tile n overlaps the computation of tile n-1
  -> cycles per tile = max(m + 4, sum_rows max(1, popcount) + 4)
The official simulator instead charges sum_rows popcount (0 for an all-zero row, 1 for an exact match) for the
compute and sum(#searched rows + m/8) for the ProSparsity phase, each summed over the whole layer, then the max of
the two sums. Everything else (DRAM stalls at the 1024-bit interface, LIF) is kept as the simulator does it.

  variant "paper"     every row >= 1 cycle (Sec. VI-A: "for m rows ... >= m + 4")
  variant "skipzero"  all-zero rows not issued (0 cycles), still m + 4 for the ProSparsity phase

  ~/torch-env/bin/python prosperity_own_correct_final.py VGG16 [T]   -> results/prosperity_own_correct_final_<net>_T<T>.json
"""
import json, math, os, sys
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
R = os.path.join(HERE, "results")
MT, KT, NT, MEMW = 256, 16, 128, 1024


def layer(a):
    sd, net, lvl, li, T = a
    import torch
    import prosperity_official as P
    d = np.load(os.path.join(sd, f"{net}_{lvl}.npz"))
    W, S = d[f"W{li}"], d[f"S{li}"]
    M, K = W.shape
    N = S.shape[1]
    bits = ((S[None] >> np.arange(T)[:, None, None]) & 1).astype(bool)
    rows = bits.transpose(2, 0, 1).reshape(N * T, K)           # pixel-major, as the simulator
    Kp = -(-K // KT) * KT
    rows = np.pad(rows, ((0, 0), (0, Kp - K)))
    nN = math.ceil(M / NT)
    sim_comp = sim_pre = paper = skip = 0
    for r0 in range(0, rows.shape[0], MT):
        for k0 in range(0, Kp, KT):
            t = rows[r0:r0 + MT, k0:k0 + KT]
            m = t.shape[0]
            pa, _ = P.fast_find_product_sparsity(torch.from_numpy(t).float())
            pa = pa.numpy() != 0
            pc = pa.sum(1)
            nz = t.sum(1) > 0
            sim_comp += int(pc.sum() + ((pc == 0) & nz).sum())
            sim_pre += int((t.sum(1) > 1).sum()) + m // 8
            paper += max(m + 4, int(np.maximum(pc, 1).sum()) + 4)
            skip += max(m + 4, int(pc.sum() + ((pc == 0) & nz).sum()) + 4)
    sim_comp, sim_pre, paper, skip = sim_comp * nN, sim_pre * nN, paper * nN, skip * nN
    return (net, lvl, li), dict(M=int(M), K=int(K), N=int(N), sim=max(sim_comp, sim_pre), sim_compute=sim_comp,
                                sim_preprocess=sim_pre, paper=paper, skipzero=skip)


def main():
    net = sys.argv[1]
    T = int(sys.argv[2]) if len(sys.argv) > 2 else 8
    sd = os.path.join(R, "prune_chain" if T == 8 else f"prune_chain_T{T}")
    cache_path = os.path.join(R, "prune_chain_cache.json" if T == 8 else f"prune_chain_T{T}_cache.json")
    cache = json.load(open(cache_path))
    todo = []
    for lvl in ("dense", "sp90", "sp95", "sp98"):
        p = os.path.join(sd, f"{net}_{lvl}.json")
        if os.path.exists(p):
            todo += [(sd, net, lvl, li, T) for li, m in enumerate(json.load(open(p))["layers"]) if not m["analog"]]
    with Pool(7) as pool:
        res = dict(pool.map(layer, todo))
    out = {}
    for (n, lvl, li), r in res.items():
        c = cache[repr((n, lvl, li))]["cycles"]
        # the simulator's layer total (FC + mem stalls + LIF) with its compute replaced by the paper's per-tile pipeline
        extra = c["prosperity"] - r["sim"]                     # DRAM stalls + LIF + pipeline fill of the simulator
        r.update(sim_total=c["prosperity"], paper_total=r["paper"] + max(0, extra),
                 skipzero_total=r["skipzero"] + max(0, extra), ours=c["ours"], ptb=c["ptb"])
        out.setdefault(lvl, {})[str(li)] = r
    json.dump(out, open(os.path.join(R, f"prosperity_own_correct_final_{net}_T{T}.json"), "w"), indent=1)
    for lvl, L in out.items():
        s = {k: sum(v[k] for v in L.values()) for k in ("sim_total", "paper_total", "skipzero_total", "ours", "ptb")}
        print(f"{net} {lvl}: Prosperity official {s['sim_total']:,} | paper pipeline {s['paper_total']:,} "
              f"({s['paper_total'] / s['sim_total']:.2f}x) | skip-zero-rows {s['skipzero_total']:,} "
              f"({s['skipzero_total'] / s['sim_total']:.2f}x) | TIDES {s['ours']:,} | speedup over PTB: official "
              f"{s['ptb'] / s['sim_total']:.2f}, paper {s['ptb'] / s['paper_total']:.2f}, skip {s['ptb'] / s['skipzero_total']:.2f}, "
              f"TIDES {s['ptb'] / s['ours']:.2f}", flush=True)


if __name__ == "__main__":
    main()
