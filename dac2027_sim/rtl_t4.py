"""
rtl_t4.py -- TIDES at T = 4: closed-loop RTL run (tsweep_synth/tb/tb_ours_closed.v + rtl/ours/ours_core.v, Verilator,
-DTB_T=4) on every layer whose cycles enter the T = 4 latency results, checked against the cycle model.

Per layer: the RTL cycle count == ours.run_layer_fast(W, S, Cfg(T=4))["cycles"] (the number used for the speed-ups),
every partial sum (T x 24 bit) == the dense reference W @ bit_t(S), every LIF output spike == the integer LIF
reference (tsweep_synth/py/tides_data.py gen / check: offline data and value check at any T).

Layer sets:
  chain  the chained-trace sweep (prune_chain.py, PC_T=4): ResNet18 / ResNet19 / VGG16 x dense / sp90 / sp95
  syn    the synthetic ResNet-19 figure (realtraces/run_real.py RR_SYN=ResNet19,0.0732,0.1351,0.3 RR_T=4), batch 1

  python3 rtl_t4.py chain [net ...] | syn      -> results/rtl_t4_<set>.json (cached per layer)
"""
import json, os, re, subprocess, sys, time, zlib
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
TS = os.path.join(os.path.dirname(HERE), "tsweep_synth")
BUILD = os.path.join(HERE, "hw", "build_t4")
EXE = os.path.join(BUILD, "obj", "Vtb_ours_closed")
R = os.path.join(HERE, "results")
T = 4
sys.path.insert(0, HERE)


def build():
    src = [os.path.join(TS, "tb", "tb_ours_closed.v"), os.path.join(TS, "rtl", "ours", "ours_core.v")]
    if os.path.exists(EXE) and all(os.path.getmtime(EXE) > os.path.getmtime(s) for s in src):
        return
    os.makedirs(BUILD, exist_ok=True)
    subprocess.run(["verilator", "--binary", "--timing", "-O3", "-Wno-fatal", "-Wno-lint", "-Wno-style",
                    "-Wno-MULTIDRIVEN", "--top-module", "tb_ours_closed", "-Mdir", os.path.join(BUILD, "obj"),
                    "-j", "8", "--x-assign", "0", "--x-initial", "0", f"-DTB_T={T}"] + src,
                   check=True, stdout=subprocess.DEVNULL)


def layers(which, nets):
    """-> [(tag, loader args)]"""
    out = []
    if which == "chain":
        sd = os.path.join(R, "prune_chain_T4")
        for n in nets:
            for lv in ("dense", "sp90", "sp95"):
                meta = json.load(open(os.path.join(sd, f"{n}_{lv}.json")))["layers"]
                out += [(f"{n}|{lv}|{li}", ("chain", n, lv, li)) for li, m in enumerate(meta) if not m["analog"]]
    else:
        import workload as wl
        out = [(f"ResNet19syn|{li}", ("syn", li)) for li in range(len(wl.NETWORKS["ResNet19"]()))]
    return out


def tensors(a):
    if a[0] == "chain":
        _, n, lv, li = a
        d = np.load(os.path.join(R, "prune_chain_T4", f"{n}_{lv}.npz"))
        return d[f"W{li}"].astype(np.int16), d[f"S{li}"]
    import workload as wl
    li = a[1]
    wd, ns, q = 0.0732, 0.1351, 0.3
    layer = wl.NETWORKS["ResNet19"]()[li]
    return wl.layer_tensors(layer, 1, wd, ns, q, zlib.crc32(f"ResNet19|{li}|1|{wd}|{ns}|{q}|T{T}".encode()), T=T)


def run(item):
    tag, a = item
    from ours import Cfg, run_layer_fast          # dac2027_sim's cycle model and workload, loaded first so that
    import workload                               # tides_data uses them too (ours.py is identical in tsweep_synth)
    sys.path.append(os.path.join(TS, "py"))
    import tides_data as TD                       # T-generic offline data + value check
    W, S = tensors(a)
    cfg = Cfg(T=T)
    d = os.path.join(BUILD, "runs", tag.replace("|", "_"))
    cdir = os.path.join(d, "closed")
    tiles = TD.gen(W, S, cfg, cdir)
    t0 = time.time()
    r = subprocess.run([EXE], cwd=d, capture_output=True, text=True)
    line = [l for l in r.stdout.splitlines() if l.startswith("CLOSED_DONE")]
    assert line, tag + r.stdout[-1500:] + r.stderr[-1500:]
    kv = dict(x.split("=") for x in line[0].split()[1:])
    entries, bad_sum, bad_spk = TD.check(W, S, cfg, cdir, tiles)
    model = run_layer_fast(W, S, cfg)
    res = dict(M=int(W.shape[0]), K=int(W.shape[1]), N=int(S.shape[1]), rtl=int(kv["cycles"]),
               model=int(model["cycles"]), entries=entries, sums_wrong=bad_sum, spikes_wrong=bad_spk,
               conflicts=int(kv["conflicts"]), overflow=kv["overflow"], pred_err=int(kv["pred_err"]),
               sim_s=round(time.time() - t0, 1))
    res["ok"] = (res["rtl"] == res["model"] and bad_sum == 0 and bad_spk == 0 and res["conflicts"] == 0
                 and "1" not in res["overflow"] and res["pred_err"] == 0)
    for f in os.listdir(cdir):                    # keep the run directory small
        if f.endswith(".hex") or f == "out_closed.txt":
            os.remove(os.path.join(cdir, f))
    return tag, res


def main():
    which = sys.argv[1]
    nets = sys.argv[2:] or ["ResNet18", "ResNet19", "VGG16"]
    build()
    out_path = os.path.join(R, f"rtl_t4_{which}.json")
    done = json.load(open(out_path)) if os.path.exists(out_path) else {}
    todo = [it for it in layers(which, nets) if it[0] not in done or not done[it[0]]["ok"]]
    print(f"{len(done)} cached, {len(todo)} to run", flush=True)
    t0 = time.time()
    with Pool(int(os.environ.get("RT_WORKERS", 6))) as p:
        for i, (tag, r) in enumerate(p.imap_unordered(run, todo)):
            done[tag] = r
            json.dump(done, open(out_path, "w"), indent=1)
            print(f"[{i + 1}/{len(todo)} {time.time() - t0:.0f}s] [{'ok' if r['ok'] else 'FAIL'}] {tag} "
                  f"M{r['M']} K{r['K']} N{r['N']} RTL {r['rtl']:,} model {r['model']:,} | sums wrong "
                  f"{r['sums_wrong']}/{r['entries']} spikes wrong {r['spikes_wrong']} | {r['sim_s']}s", flush=True)
    bad = [k for k, v in done.items() if not v["ok"]]
    print(f"{len(done)} layers, {len(bad)} failing: {bad[:10]}")


if __name__ == "__main__":
    main()
