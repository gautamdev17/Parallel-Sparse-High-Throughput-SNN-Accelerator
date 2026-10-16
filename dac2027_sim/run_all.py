"""
run_all.py -- VGG16 / ResNet18 latency and throughput: Ours vs LoAS vs PTB vs SpikeX.

  python3 run_all.py                 # main workloads, batch 1 and 16
  python3 run_all.py sweep           # weight-density sweep (VGG16 + ResNet18, batch 1 and 16)

Every design sees the same layers and, for the trace-driven models, the same spike tensors
(seeded per network/layer/batch/workload). Common clock 800 MHz (the clock of the LoAS model in the zip).
latency    = cycles(batch 1) / f
throughput = 16 * f / cycles(batch 16)   [images/s]   (LoAS: no batching gain in its closed form)
Results are cached in results/*.json.
"""
import json, math, os, sys, time, zlib
from multiprocessing import Pool
import numpy as np

import workload as wl
from ours import Cfg, run_layer_fast
from baselines import loas_layer_cycles, ptb_layer_cycles, spikex_layer_cycles, prosperity_layer_cycles, spikeflow_layer_cycles, LOAS_P_ZIP

F_HZ = 800e6
HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, "results")

WORKLOADS = {
    # name: (weight density, non-silent density, per-timestep fire prob of a non-silent neuron)
    "sparse90": (0.10, 0.10, 0.3),   # REPORT.md sec. 15: weights and activations 90%+ sparse
    "zipstats": (1.00, LOAS_P_ZIP, 0.3),  # the zip's LoAS statistics: 26.1% non-silent, dense weights
}
OURS = Cfg()  # 4x4 PEs x 8 adders = 128 adders (= LoAS 16 TPPE x 8, = PTB 128 PE x 1)


def run_layer(task):
    net, li, batch, wname, wd, ns, q, cfg = task
    layer = wl.NETWORKS[net]()[li]
    M, K, N = wl.gemm_shape(layer, batch)
    seed = zlib.crc32(f"{net}|{li}|{batch}|{wd}|{ns}|{q}".encode())
    W, S = wl.layer_tensors(layer, batch, wd, ns, q, seed)
    t0 = time.time()
    o = run_layer_fast(W, S, cfg)
    ptb = ptb_layer_cycles(S, M)
    spx = spikex_layer_cycles(S, M)
    pro = prosperity_layer_cycles(S, M)
    pro_opt = prosperity_layer_cycles(S, M, skip_empty=True)
    return dict(net=net, li=li, name=layer[0], batch=batch, workload=wname, M=M, K=K, N=N,
                ours=o["cycles"], ours_stats={k: v for k, v in o.items() if k != "cycles"},
                loas_zip=loas_layer_cycles(M, K, N, LOAS_P_ZIP),
                ptb=ptb[0], ptb_tws=ptb[1], spikex=spx[0], spikex_mode=spx[1],
                prosperity=pro, prosperity_opt=pro_opt, spikeflow=spikeflow_layer_cycles(S, M),
                nonsilent=float((S != 0).mean()), secs=time.time() - t0)


def run(tasks, cache_file):
    path = os.path.join(OUT, cache_file)
    cache = json.load(open(path)) if os.path.exists(path) else {}
    key = lambda t: f"{t[0]}|{t[1]}|{t[2]}|{t[3]}"
    todo = [t for t in tasks if key(t) not in cache or "spikeflow" not in cache[key(t)]]
    todo.sort(key=lambda t: -np.prod(wl.gemm_shape(wl.NETWORKS[t[0]]()[t[1]], t[2])))
    print(f"{len(todo)} layer runs ({len(tasks) - len(todo)} cached)", flush=True)
    t0 = time.time()
    if todo:
        with Pool(os.cpu_count()) as pool:
            for r in pool.imap_unordered(run_layer, todo):
                cache[f"{r['net']}|{r['li']}|{r['batch']}|{r['workload']}"] = r
                json.dump(cache, open(path, "w"))
                print(f"  {r['workload']:9s} {r['net']:8s} b{r['batch']:<2d} {r['name']:9s} LoAS {r['loas_zip']:>11,.0f} "
                      f"SpikeX {r['spikex']:>10,d} PTB {r['ptb']:>10,d} ours {r['ours']:>10,d} "
                      f"({r['secs']:.0f}s, {time.time() - t0:.0f}s)", flush=True)
    return cache


DESIGNS = [("loas_zip", "LoAS"), ("spikex", "SpikeX (8x8)"), ("ptb", "PTB (16x8)"), ("sato", "SATO (128 PE)"),
           ("spikeflow", "SpikeFlow (16x16)"), ("prosperity", "Prosperity (official sim)"), ("ours", "Ours (4x4, T=8)")]
ADDERS = {"ours": 128, "loas_zip": 128, "ptb": 128, "spikex": 64, "prosperity": 128, "sato": 128, "spikeflow": 256}


def summarize(cache, wname, nets=("VGG16", "ResNet18")):
    rows = {}
    official = {}
    for d, f in (("prosperity", "prosperity_official.json"), ("sato", "sato_official.json")):
        p = os.path.join(OUT, f)                               # official Prosperity-repo simulators
        if os.path.exists(p):
            official[d] = json.load(open(p))
    for net in nets:
        nl = len(wl.NETWORKS[net]())
        for d, _ in DESIGNS:
            if d in official:
                c1, c16 = official[d][f"{net}|1|{wname}"], official[d][f"{net}|16|{wname}"]
            else:
                c1 = sum(cache[f"{net}|{li}|1|{wname}"][d] for li in range(nl))
                c16 = sum(cache[f"{net}|{li}|16|{wname}"][d] for li in range(nl))
            rows[net, d] = dict(cycles_b1=c1, cycles_b16=c16, latency_ms=c1 / F_HZ * 1e3,
                                throughput=16 * F_HZ / c16, thr_per_adder=16 * F_HZ / c16 / ADDERS[d])
    return rows


def table(rows, wname, nets=("VGG16", "ResNet18")):
    wd, ns, q = WORKLOADS[wname]
    lines = [f"### Workload `{wname}`: weight density {wd}, non-silent {ns}, fire prob {q} (T=8, INT8, 800 MHz)", "",
             "| Network | Design | Cycles (b=1) | Latency (ms) | Ours speed-up (latency) | Throughput (img/s, b=16) "
             "| Ours gain (throughput) | img/s per adder |",
             "|---|---|---:|---:|---:|---:|---:|---:|"]
    for net in nets:
        o = rows[net, "ours"]
        for d, label in DESIGNS:
            r = rows[net, d]
            lines.append(f"| {net} | {label} | {r['cycles_b1']:,.0f} | {r['latency_ms']:.3f} | "
                         f"{r['latency_ms'] / o['latency_ms']:.2f}x | {r['throughput']:,.0f} | "
                         f"{o['throughput'] / r['throughput']:.2f}x | {r['thr_per_adder']:.2f} |")
    return "\n".join(lines)


def main_tasks(workloads, batches=(1, 16), nets=("VGG16", "ResNet18"), cfg=OURS):
    tasks = []
    for wname in workloads:
        wd, ns, q = WORKLOADS[wname]
        for net in nets:
            for li in range(len(wl.NETWORKS[net]())):
                for b in batches:
                    tasks.append((net, li, b, wname, wd, ns, q, cfg))
    return tasks


if __name__ == "__main__":
    os.makedirs(OUT, exist_ok=True)
    mode = sys.argv[1] if len(sys.argv) > 1 else "main"
    if mode == "sweep":
        for wd in (1.0, 0.5, 0.3, 0.2, 0.1, 0.05, 0.02):
            WORKLOADS[f"wd{wd}"] = (wd, 0.10, 0.3)
        names = [w for w in WORKLOADS if w.startswith("wd")]
        cache = run(main_tasks(names), "sweep.json")
        out = {}
        for w in names:
            rows = summarize(cache, w)
            out[w] = {f"{n}|{d}": v for (n, d), v in rows.items()}
        json.dump(out, open(os.path.join(OUT, "sweep_summary.json"), "w"), indent=1)
        for w in names:
            print(table(summarize(cache, w), w), "\n")
    else:
        names = list(WORKLOADS)
        cache = run(main_tasks(names), "main.json")
        md = []
        out = {}
        for w in names:
            rows = summarize(cache, w)
            out[w] = {f"{n}|{d}": v for (n, d), v in rows.items()}
            md.append(table(rows, w))
        json.dump(out, open(os.path.join(OUT, "main_summary.json"), "w"), indent=1)
        open(os.path.join(OUT, "main_tables.md"), "w").write("\n\n".join(md) + "\n")
        print("\n\n".join(md))
