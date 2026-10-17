"""
sensitivity.py -- design knobs of Ours at a fixed budget of 128 adders (R*C*T = 128, T = 8),
on the sparse90 workload, VGG16 + ResNet18, batch 1 (latency) and 16 (throughput).

Only Ours is re-run; the baselines do not change. Writes results/sensitivity.json and prints a table.
"""
import json, os, sys, time, zlib
from multiprocessing import Pool
from dataclasses import replace

import workload as wl
from ours import Cfg, run_layer_fast
from run_all import F_HZ, OUT, WORKLOADS

BASE = Cfg()
VARIANTS = {
    "base 4x4 F4 G4 E4": BASE,
    "shape 2x8": replace(BASE, R=2, C=8),
    "shape 8x2": replace(BASE, R=8, C=2),
    "shape 16x1": replace(BASE, R=16, C=1),
    "F2 G2 (smaller sum bundle)": replace(BASE, F=2, G=2),
    "F4 G2": replace(BASE, G=2),
    "F2 G4": replace(BASE, F=2),
    "E2 (fewer edge ports)": replace(BASE, E=2),
    "E8": replace(BASE, E=8),
    "edge FIFO 40 entries": replace(BASE, D=40),
    "edge FIFO 160 entries": replace(BASE, D=160),
    "edge FIFO unbounded (no backpressure)": replace(BASE, D=0),
    "no shadow weights": replace(BASE, shadow=False),
    "Lw=4 (one row/cycle)": replace(BASE, Lw=4),
    "packer pp=4": replace(BASE, pp=4),
    "double output buffer": replace(BASE, obuf_double=True),
}


def one(task):
    vname, net, li, batch = task
    cfg = VARIANTS[vname]
    wd, ns, q = WORKLOADS["sparse90"]
    layer = wl.NETWORKS[net]()[li]
    seed = zlib.crc32(f"{net}|{li}|{batch}|{wd}|{ns}|{q}".encode())   # same tensors as run_all.py
    W, S = wl.layer_tensors(layer, batch, wd, ns, q, seed)
    return vname, net, li, batch, run_layer_fast(W, S, cfg)["cycles"]


if __name__ == "__main__":
    path = os.path.join(OUT, "sensitivity.json")
    cache = json.load(open(path)) if os.path.exists(path) else {}
    tasks = [(v, n, li, b) for v in VARIANTS for n in ("VGG16", "ResNet18")
             for li in range(len(wl.NETWORKS[n]())) for b in (1, 16) if f"{v}|{n}|{li}|{b}" not in cache]
    t0 = time.time()
    with Pool(os.cpu_count()) as pool:
        for v, n, li, b, cyc in pool.imap_unordered(one, tasks):
            cache[f"{v}|{n}|{li}|{b}"] = cyc
            json.dump(cache, open(path, "w"))
    print(f"{len(tasks)} runs in {time.time() - t0:.0f}s")
    print("| Variant (128 adders) | VGG16 latency (ms) | VGG16 img/s (b=16) | ResNet18 latency (ms) | ResNet18 img/s (b=16) |")
    print("|---|---:|---:|---:|---:|")
    for v in VARIANTS:
        cells = []
        for n in ("VGG16", "ResNet18"):
            nl = len(wl.NETWORKS[n]())
            c1 = sum(cache[f"{v}|{n}|{li}|1"] for li in range(nl))
            c16 = sum(cache[f"{v}|{n}|{li}|16"] for li in range(nl))
            cells += [f"{c1 / F_HZ * 1e3:.3f}", f"{16 * F_HZ / c16:,.0f}"]
        print(f"| {v} | " + " | ".join(cells) + " |")
