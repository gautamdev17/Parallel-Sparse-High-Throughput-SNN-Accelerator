"""
network_cyclesim.py -- run the CYCLE-STEPPED simulator (snn_sim.Sim, whose cycle counts and output bits
are identical to the RTL in rtl/, see rtl/run_tests.py) on the EXACT layers of cycle_compare.py.

Workload (same as the LoAS closed form uses):
    every layer of AlexNet / VGG16 / ResNet18 from cycle_compare.NETWORKS
    M = C_out, K = KH*KW*C_in, N = OH*OW*batch  (im2col), T = 8, INT8 weights, 8-bit spike masks
    weights and activations are WD / NS dense (default 0.10 / 0.10 = 90% sparse each)

For each layer it
  1. builds random int8 weights and 8-bit masks with those densities,
  2. runs Sim.run_layer (packs both operands, steps the array, exit stage, IF, post-proc),
  3. checks the output spikes against the DENSE result  W @ bit_t(B)  followed by the IF neuron
     (dense sums are computed with float32 BLAS, exact because |sum| < 2^24),
  4. records the cycles, plus LoAS cycles from cycle_compare.compute_layer_cycles for the same layer.
Results go to results_cyclesim.json (cached per network/batch so reruns are cheap).
"""
import json, math, os, sys, time, zlib
from multiprocessing import Pool
import numpy as np

import cycle_compare as cc
from snn_sim import Cfg, Sim, if_vec, rand_weights, rand_masks

WD = NS = 0.10
CLK = cc.CLOCK_MHZ * 1e6
OUT = "results_cyclesim.json"


def dense_sums_f32(W, Bm, T=8):
    Wf = W.astype(np.float32)
    s = np.empty((W.shape[0], Bm.shape[1], T), dtype=np.int64)
    for t in range(T):
        s[..., t] = np.rint(Wf @ ((Bm >> t) & 1).astype(np.float32)).astype(np.int64)
    assert np.abs(s).max() < (1 << 24)
    return s


def pick_theta_fast(sums, target=0.25, T=8):
    lo, hi = 0, int(np.abs(sums).max()) + 1
    while lo < hi:
        mid = (lo + hi) // 2
        rate = np.unpackbits(if_vec(sums, mid, T)[..., None], axis=-1).mean()
        if rate > target:
            lo = mid + 1
        else:
            hi = mid
    return lo


def run_one(task):
    net, li, batch, wd, ns = task
    name, Ci, Co, KH, KW, OH, OW = cc.NETWORKS[net][li]
    M, K, N = Co, KH * KW * Ci, OH * OW * batch
    rng = np.random.default_rng(zlib.crc32(f"{net}-{li}-{batch}".encode()))
    W = rand_weights(rng, M, K, wd)
    Bm = rand_masks(rng, K, N, ns)
    sums = dense_sums_f32(W, Bm)
    theta = pick_theta_fast(sums)
    ref = if_vec(sums, theta)
    t0 = time.time()
    sim = Sim(Cfg(theta=theta))
    out, cyc = sim.run_layer(W, Bm)
    ok = bool(np.array_equal(out, ref))
    p = wd * ns
    loas, _, _ = cc.compute_layer_cycles(Ci, Co, KH, KW, OH * batch, OW, p, cc.LOAS_OVERHEAD, cc.NUM_TPPES)
    st = sim.stats
    return dict(net=net, li=li, name=name, batch=batch, M=M, K=K, N=N, theta=int(theta), ok=ok,
                ours=int(cyc), loas=float(loas), passes=int(st["passes"]), stalls=int(st["stall_cycles"]),
                spike_rate=float(np.unpackbits(ref[..., None], axis=-1).mean()), secs=time.time() - t0)


if __name__ == "__main__":
    batches = [int(b) for b in (sys.argv[1].split(",") if len(sys.argv) > 1 else ["1", "16"])]
    cache = json.load(open(OUT)) if os.path.exists(OUT) else {}
    tasks = []
    for net in ("AlexNet", "VGG16", "ResNet18"):
        for b in batches:
            for li in range(len(cc.NETWORKS[net])):
                if f"{net}|{b}|{li}" not in cache:
                    tasks.append((net, li, b, WD, NS))
    # big layers first so the pool stays busy
    tasks.sort(key=lambda t: -(cc.NETWORKS[t[0]][t[1]][2] * cc.NETWORKS[t[0]][t[1]][1] * cc.NETWORKS[t[0]][t[1]][3]
                               * cc.NETWORKS[t[0]][t[1]][4] * cc.NETWORKS[t[0]][t[1]][5] * cc.NETWORKS[t[0]][t[1]][6] * t[2]))
    print(f"{len(tasks)} layer runs to do", flush=True)
    t0 = time.time()
    with Pool(os.cpu_count()) as pool:
        for r in pool.imap_unordered(run_one, tasks):
            cache[f"{r['net']}|{r['batch']}|{r['li']}"] = r
            json.dump(cache, open(OUT, "w"), indent=0)
            print(f"{r['net']:9s} b{r['batch']:<2d} {r['name']:7s} M{r['M']:5d} K{r['K']:5d} N{r['N']:6d} "
                  f"ours {r['ours']:>9,d} LoAS {r['loas']:>10,.0f}  bit-exact={r['ok']}  ({r['secs']:.0f}s, total {time.time()-t0:.0f}s)", flush=True)
    bad = [k for k, v in cache.items() if not v["ok"]]
    print("ALL LAYERS BIT-EXACT vs dense" if not bad else f"MISMATCH in {bad}")
