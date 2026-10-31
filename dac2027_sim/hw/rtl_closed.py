"""
rtl_closed.py -- closed-loop RTL verification of our design on whole layers (tb/tb_ours_closed.v + ours_core.v,
Verilator). Only offline data go to the RTL (packed weight columns per pass, raw spike slices); the RTL packer
makes the groups and the testbench controller schedules from RTL signals (packer outputs, edge-FIFO occupancy).

Checks per layer:
  values : every output (filter, pixel) of every output tile -- 8 partial sums (24 bit) == dense W @ bit_t(S),
           and the 8 LIF output spikes from the RTL LIF units == integer IF reference (V = V + x)
  cycles : total RTL cycles of the layer == ours.run_layer_fast(W, S, Cfg())["cycles"]
  hazards: no output-buffer RMW conflict, no edge-FIFO overflow
  backpressure: feeder stall cycles and peak FIFO occupancy RTL == model; every predicted per-column entry count
           (the controller's credit) == the entries the RTL bundle actually writes

  python3 rtl_closed.py random [n]              # n random small layers (several output tiles each)
  python3 rtl_closed.py net VGG16 1 [layers]    # every layer (or a list like 0,3,7) of VGG16 at batch 1
  python3 rtl_closed.py net VGG16 1 all 0.3     # same at weight density 0.3 (the sweep's dense points, where the
                                                # edge FIFOs would reach 110-147 entries without backpressure)
"""
import json, os, subprocess, sys, time, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import workload as wl
from ours import Cfg, LayerPlan, _passes, tile_masks, run_layer_fast

BUILD = os.path.join(HERE, "build")
CDIR = os.path.join(BUILD, "closed")
OBJ = os.path.join(BUILD, "obj_closed")
EXE = os.path.join(OBJ, "Vtb_ours_closed")
THETA = 64


def build():
    src = [os.path.join(HERE, "tb", "tb_ours_closed.v"), os.path.join(HERE, "rtl", "ours", "ours_core.v")]
    if os.path.exists(EXE) and all(os.path.getmtime(EXE) > os.path.getmtime(s) for s in src):
        return
    cmd = ["verilator", "--binary", "--timing", "-O3", "-Wno-fatal", "-Wno-lint", "-Wno-style", "-Wno-MULTIDRIVEN",
           "--top-module", "tb_ours_closed", "-Mdir", OBJ, "-j", "8", "--x-assign", "0", "--x-initial", "0"] + src
    subprocess.run(cmd, check=True, stdout=subprocess.DEVNULL)


def lif_int(sums, theta):
    V = np.zeros(sums.shape[:-1], dtype=np.int64)
    out = np.zeros(sums.shape[:-1], dtype=np.int64)
    for t in range(sums.shape[-1]):
        V = V + sums[..., t]
        f = V >= theta
        out |= f.astype(np.int64) << t
        V = np.where(f, V - theta, V)
    return out


def gen(W, S, cfg):
    """offline data for the testbench -> list of tiles (m0, m1, n0, n1)."""
    R, C, T = cfg.R, cfg.C, cfg.T
    plan = LayerPlan(W, cfg)
    K, N = S.shape
    Sp = np.zeros((plan.nK * R, N), dtype=np.uint8)
    Sp[:K] = S
    nblocks = [(n0, min(n0 + cfg.Nt, N)) for n0 in range(0, N, cfg.Nt)]
    tiles, trows, krows, prows, slices, sbase = [], [], [], [], [], {}
    for bi, (m0, m1) in enumerate(plan.mblocks):
        for ni, (n0, n1) in enumerate(nblocks):
            ti = len(tiles)
            tiles.append((m0, m1, n0, n1))
            kf, npass0 = len(krows), len(prows)
            for kt in range(plan.nK):
                cols, Wt = plan.cols[bi, kt]
                if not cols:
                    continue
                if (ni, kt) not in sbase:
                    sbase[ni, kt] = len(slices)
                    slices += tile_masks(Sp[kt * R:(kt + 1) * R, n0:n1], T)
                pf = len(prows)
                for pas in _passes(cols, C):
                    pe_w = [[0, 0] for _ in range(R * C)]
                    fid = [0] * (C * cfg.F)
                    for c, fl in enumerate(pas):
                        for fi, f in enumerate(fl):
                            fid[c * cfg.F + fi] = f
                            for k in np.nonzero(Wt[f])[0]:
                                pe_w[int(k) * C + c] = [int(Wt[f, k]), fi]
                    prows.append(" ".join(f"{w} {fl} {fd}" for (w, fl), fd in zip(pe_w, fid)))
                krows.append(f"{ti} {n1 - n0} {sbase[ni, kt]} {pf} {len(prows) - pf}")
            trows.append(f"{kf} {len(krows) - kf} {len(prows) - npass0}")
    os.makedirs(CDIR, exist_ok=True)
    open(os.path.join(CDIR, "cfg.txt"), "w").write(f"{len(tiles)} {len(krows)} {len(prows)} {len(slices)} {THETA}\n")
    open(os.path.join(CDIR, "tiles.txt"), "w").write("\n".join(trows) + "\n")
    open(os.path.join(CDIR, "kt.txt"), "w").write("\n".join(krows) + "\n")
    open(os.path.join(CDIR, "pass.txt"), "w").write("\n".join(prows) + "\n")
    open(os.path.join(CDIR, "slices.hex"), "w").write("\n".join(format(m, "08x") for m in slices) + "\n")
    return tiles, len(prows)


def run_check(W, S, tag):
    cfg = Cfg()
    tiles, npass = gen(W, S, cfg)
    t0 = time.time()
    r = subprocess.run([EXE], cwd=BUILD, capture_output=True, text=True)
    line = [l for l in r.stdout.splitlines() if l.startswith("CLOSED_DONE")]
    assert line, r.stdout[-2000:] + r.stderr[-2000:]
    kv = dict(x.split("=") for x in line[0].split()[1:])
    # values
    got = {}
    for l in open(os.path.join(CDIR, "out_closed.txt")):
        v = l.split()
        sums = [int(x, 16) for x in v[2:10]]
        got[int(v[0]), int(v[1])] = ([x - (1 << 24) if x >> 23 else x for x in sums], int(v[10]))
    ref = wl.dense_sums(W, S)
    bad_sum = bad_spk = 0
    entries = 0
    for ti, (m0, m1, n0, n1) in enumerate(tiles):
        rs = ref[m0:m1, n0:n1]
        rk = lif_int(rs, THETA)
        gs = np.zeros_like(rs)
        gk = np.zeros_like(rk)
        for f in range(m1 - m0):
            for p in range(n1 - n0):
                e = got.get((ti, (f << 7) | p))
                if e is not None:
                    gs[f, p] = e[0]
                    gk[f, p] = e[1]
        bad_sum += int((gs != rs).any(-1).sum())
        bad_spk += int((gk != rk).sum())
        entries += rs.shape[0] * rs.shape[1]
    model = run_layer_fast(W, S, cfg)
    res = dict(layer=tag, M=W.shape[0], K=W.shape[1], N=S.shape[1], tiles=len(tiles), passes=npass,
               rtl_cycles=int(kv["cycles"]), model_cycles=int(model["cycles"]), entries=entries,
               sum_mismatch=bad_sum, spike_mismatch=bad_spk, conflicts=int(kv["conflicts"]),
               overflow=kv["overflow"], fifo_max_rtl=int(kv["fifo_max"]), fifo_max_model=int(model["fifo_max"]),
               stalls_rtl=int(kv["stalls"]), stalls_model=int(model["fifo_stalls"]), pred_err=int(kv["pred_err"]),
               sim_s=round(time.time() - t0, 1))
    ok = (bad_sum == 0 and bad_spk == 0 and res["rtl_cycles"] == res["model_cycles"] and res["conflicts"] == 0
          and "1" not in res["overflow"] and res["pred_err"] == 0 and res["stalls_rtl"] == res["stalls_model"]
          and res["fifo_max_rtl"] == res["fifo_max_model"])
    res["ok"] = ok
    print(f"[{'ok' if ok else 'FAIL'}] {tag}: M{res['M']} K{res['K']} N{res['N']} tiles {res['tiles']} "
          f"passes {npass} | RTL {res['rtl_cycles']} vs model {res['model_cycles']} cycles | "
          f"sums wrong {bad_sum}/{entries}, spikes wrong {bad_spk} | conflicts {res['conflicts']} "
          f"overflow {res['overflow']} fifo_max {res['fifo_max_rtl']}/{res['fifo_max_model']} "
          f"stalls {res['stalls_rtl']}/{res['stalls_model']} pred_err {res['pred_err']} | {res['sim_s']} s", flush=True)
    return res


def random_layers(n):
    rng = np.random.default_rng(11)
    out = []
    for i in range(n):
        M = int(rng.integers(1, 150)); K = int(rng.integers(1, 120)); N = int(rng.integers(1, 300))
        wd, ns = [(0.1, 0.1), (0.3, 0.3), (1.0, 0.5), (0.05, 0.2), (0.5, 1.0)][i % 5]
        W = wl.rand_weights(rng, M, K, wd)
        S = wl.rand_spikes(rng, (K, N), ns, 0.3)
        out.append(run_check(W, S, f"random{i}(wd={wd},ns={ns})"))
    return out


def net_layers(net, batch, which=None, wd=0.1):
    out = []
    for li, layer in enumerate(wl.NETWORKS[net]()):
        if which is not None and li not in which:
            continue
        seed = zlib.crc32(f"{net}|{li}|{batch}|{wd}|0.1|0.3".encode())     # same tensors as run_all.py
        W, S = wl.layer_tensors(layer, batch, wd, 0.1, 0.3, seed)
        out.append(run_check(W, S, f"{net} b{batch} L{li}" + (f" wd{wd}" if wd != 0.1 else "")))
    return out


if __name__ == "__main__":
    build()
    if sys.argv[1] == "random":
        res = random_layers(int(sys.argv[2]) if len(sys.argv) > 2 else 20)
        name = "rtl_closed_random"
    else:
        net, batch = sys.argv[2], int(sys.argv[3])
        which = set(map(int, sys.argv[4].split(","))) if len(sys.argv) > 4 and sys.argv[4] != "all" else None
        wd = float(sys.argv[5]) if len(sys.argv) > 5 else 0.1
        res = net_layers(net, batch, which, wd)
        name = f"rtl_closed_{net}_b{batch}" + (f"_wd{wd}" if wd != 0.1 else "")
    allok = all(r["ok"] for r in res)
    tot_r = sum(r["rtl_cycles"] for r in res); tot_m = sum(r["model_cycles"] for r in res)
    print(f"{'ALL OK' if allok else 'FAILURES'}: {len(res)} layers, RTL {tot_r:,} vs model {tot_m:,} cycles")
    if sys.argv[1] != "random" and which is None:
        json.dump(res, open(os.path.join(os.path.dirname(HERE), "results", name + ".json"), "w"), indent=1)
