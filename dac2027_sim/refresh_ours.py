"""refresh_ours.py -- recompute only our design's cycles in a run_all cache (results/main.json or sweep.json) with
the current ours.py; the baselines in the cache are left untouched.

  python3 refresh_ours.py main.json
  python3 refresh_ours.py sweep.json
"""
import json, os, sys, time, zlib
from multiprocessing import Pool

import workload as wl
from ours import Cfg, run_layer_fast
from run_all import WORKLOADS, OURS

OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "results")


def params(wname):
    if wname in WORKLOADS:
        return WORKLOADS[wname]
    return (float(wname[2:]), 0.10, 0.3)          # sweep entries "wd<density>"


def one(key):
    net, li, batch, wname = key.split("|")
    li, batch = int(li), int(batch)
    wd, ns, q = params(wname)
    layer = wl.NETWORKS[net]()[li]
    seed = zlib.crc32(f"{net}|{li}|{batch}|{wd}|{ns}|{q}".encode())
    W, S = wl.layer_tensors(layer, batch, wd, ns, q, seed)
    t0 = time.time()
    o = run_layer_fast(W, S, OURS)
    return key, o, time.time() - t0


if __name__ == "__main__":
    path = os.path.join(OUT, sys.argv[1])
    cache = json.load(open(path))
    keys = sorted(cache, key=lambda k: -cache[k]["M"] * cache[k]["K"] * cache[k]["N"])
    t0 = time.time()
    with Pool(os.cpu_count()) as pool:
        for i, (key, o, secs) in enumerate(pool.imap_unordered(one, keys)):
            old = cache[key]["ours"]
            cache[key]["ours"] = o["cycles"]
            cache[key]["ours_stats"] = {k: v for k, v in o.items() if k != "cycles"}
            print(f"[{i + 1}/{len(keys)}] {key}: {old:,} -> {o['cycles']:,} cycles, fifo_max {o['fifo_max']}, "
                  f"conflicts {o['edge_conflicts']} ({secs:.0f}s, {time.time() - t0:.0f}s)", flush=True)
    json.dump(cache, open(path, "w"))
