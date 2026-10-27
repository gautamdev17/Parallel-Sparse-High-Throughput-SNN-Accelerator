import json, sys, numpy as np
from multiprocessing import Pool
sys.path.insert(0, "/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/dac2027_sim")
R = "/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/dac2027_sim/results"
def one(a):
    lv, li = a
    import mem_levels as ML
    d = np.load(f"{R}/prune_chain/VGG16_{lv}.npz")
    oc_w, oc_a, _, _, rmw, lifr, gw, rawr, _ = ML.ours_layer(d[f"W{li}"].astype(np.int16), d[f"S{li}"])
    return a, dict(oc_w=oc_w, oc_a=oc_a, rmw=rmw, lifr=lifr, gw=gw, rawr=rawr)
if __name__ == "__main__":
    todo = []
    for lv in ("dense", "sp90", "sp95", "sp98"):
        meta = json.load(open(f"{R}/prune_chain/VGG16_{lv}.json"))["layers"]
        todo += [(lv, li) for li, m in enumerate(meta) if not m["analog"]]
    with Pool(7) as p:
        res = dict(p.map(one, todo))
    json.dump({f"{lv}|{li}": v for (lv, li), v in res.items()}, open(f"{R}/../audit/ours_access_VGG16.json", "w"), indent=1)
    print("done", len(res))
