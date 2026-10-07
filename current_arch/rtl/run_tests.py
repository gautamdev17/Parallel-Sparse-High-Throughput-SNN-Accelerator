"""
run_tests.py -- drive the RTL (Icarus Verilog) and check it against the Python models.

For every test case it
  1. makes random int8 weights A (MxK) and 8-bit spike-mask activations B (KxN),
  2. runs the RTL testbench (tb_snn.v) tile by tile,
  3. compares the RTL output spikes with (a) the DENSE reference  dense_layer()  and (b) snn_sim.Sim,
  4. compares the RTL cycle counts per tile with snn_sim.Sim.run_tile(): cycles, passes, stalls,
     and the post-proc unpack cycles.
Usage:  python run_tests.py [quick|full]
"""
import os, re, subprocess, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, ".."))
from snn_sim import (Cfg, Sim, dense_layer, rand_weights, rand_masks, pick_theta)

SRC = ["lif.v", "pe.v", "systolic_array.v", "packer.v", "preproc.v", "exit_stage.v",
       "postproc.v", "snn_top.v", "tb_snn.v"]
VVP = os.path.join(HERE, "build", "snn.vvp")
os.makedirs(os.path.join(HERE, "build"), exist_ok=True)


def compile_rtl():
    cmd = ["iverilog", "-g2012", "-I", HERE, "-o", VVP] + [os.path.join(HERE, s) for s in SRC]
    subprocess.run(cmd, check=True)


def write_hex(path, arr):
    with open(path, "w") as f:
        for v in np.asarray(arr).reshape(-1):
            f.write("%02x\n" % (int(v) & 0xFF))


def run_rtl(W, Bm, theta, tag):
    M, K = W.shape
    N = Bm.shape[1]
    a, b, o = (os.path.join(HERE, "build", f"{tag}_{x}.hex") for x in "ABO")
    write_hex(a, W)
    write_hex(b, Bm)
    cmd = ["vvp", "-n", VVP, f"+M={M}", f"+K={K}", f"+N={N}", f"+THETA={theta}",
           f"+A={a}", f"+B={b}", f"+O={o}"]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=3600)
    out = r.stdout
    tiles = []
    for line in out.splitlines():
        t = line.split()
        if t and t[0] == "TILE":
            tiles.append(tuple(int(x) for x in t[1:]))
    ok = "DONE" in out and "TIMEOUT" not in out
    errs = re.search(r"errors (\d+)", out)
    vals = []
    if ok:
        with open(o) as f:
            vals = []
            for ln in f.read().splitlines():
                ln = ln.strip()
                if not ln or ln.startswith("//") or ln.startswith("@"):
                    continue
                vals.append(int(ln, 16) if "x" not in ln.lower() else -1)
    res = np.array(vals, dtype=np.uint8).reshape(M, N) if ok else None
    return ok, res, tiles, int(errs.group(1)) if errs else -1, out


def python_tiles(W, Bm, theta, cfg):
    """per-tile (cycles, passes, stalls, nres) from the stepped simulator, same tile order as the TB"""
    M, N = W.shape[0], Bm.shape[1]
    res = []
    for m0 in range(0, M, cfg.m_blk):
        for n0 in range(0, N, cfg.n_blk):
            s = Sim(cfg)
            o, c, nres = s.run_tile(W[m0:m0 + cfg.m_blk, :], Bm[:, n0:n0 + cfg.n_blk])
            res.append((m0, n0, c, s.stats["passes"], s.stats["stall_cycles"], nres))
    return res


def one_case(name, M, K, N, wd, ns, seed, target=0.25):
    rng = np.random.default_rng(seed)
    W = rand_weights(rng, M, K, wd)
    Bm = rand_masks(rng, K, N, ns)
    theta = pick_theta(W, Bm, target)
    cfg = Cfg(theta=theta)
    ref = dense_layer(W, Bm, theta)
    ok, out, tiles, nerr, log = run_rtl(W, Bm, theta, name)
    if not ok:
        print(f"{name:28s} RTL did not finish\n{log[-600:]}")
        return False
    py = python_tiles(W, Bm, theta, cfg)
    bits_ok = np.array_equal(out, ref)
    cyc_ok, rows = True, []
    for t, p in zip(tiles, py):
        m0, n0, mb, nb, cyc, pre, passes, stalls, ppc = t
        pm0, pn0, pc, ppass, pstall, pn = p
        good = (cyc == pc and passes == ppass and stalls == pstall and ppc == -(-pn // 16))
        cyc_ok &= good
        rows.append((m0, n0, cyc, pc, passes, ppass, stalls, pstall, ppc, -(-pn // 16), good))
    status = "PASS" if (bits_ok and cyc_ok and nerr == 0 and len(tiles) == len(py)) else "FAIL"
    tc, tp = sum(r[2] for r in rows), sum(r[3] for r in rows)
    print(f"{name:28s} {M:3d}x{K:3d}x{N:3d} wd={wd:.2f} ns={ns:.2f} theta={theta:5d} | "
          f"bits==dense:{bits_ok} | RTL cycles {tc:6d} py {tp:6d} | tiles {len(tiles)} | rtl err flags {nerr} | {status}")
    if status == "FAIL":
        for r in rows:
            print("   tile", r)
        if not bits_ok:
            bad = np.argwhere(out != ref)
            print("   first mismatches (m,n,rtl,ref):", [(int(i), int(j), int(out[i, j]), int(ref[i, j])) for i, j in bad[:6]])
    return status == "PASS"


QUICK = [
    ("tiny_dense",   4,  4,  4, 1.0, 1.0, 1),
    ("small_mixed",  10, 7,  9, 0.5, 0.5, 2),
    ("k_not_mult4",  12, 13, 11, 0.6, 0.6, 3),
    ("k_eq_1",        6,  1,  9, 0.9, 0.9, 4),
    ("sparse_a",     20, 16, 30, 0.1, 0.1, 5),
    ("wide_k",       16, 40, 20, 0.3, 0.3, 6),
]
FULL = QUICK + [
    ("example_64x16x128_50", 64, 16, 128, 0.5, 0.5, 7),
    ("example_64x16x128_30", 64, 16, 128, 0.3, 0.3, 8),
    ("example_64x16x128_10", 64, 16, 128, 0.1, 0.1, 9),
    ("example_64x16x128_100", 64, 16, 128, 1.0, 1.0, 10),
    ("multi_tile",    70, 21, 150, 0.3, 0.6, 11),
    ("multi_tile2",  130, 24, 140, 0.2, 0.2, 12),
    ("deep_k",        33, 40, 20, 0.8, 0.2, 13),
    ("very_sparse",   64, 64, 128, 0.05, 0.05, 14),
]

if __name__ == "__main__":
    mode = sys.argv[1] if len(sys.argv) > 1 else "quick"
    compile_rtl()
    cases = QUICK if mode == "quick" else FULL
    allok = True
    for c in cases:
        allok &= one_case(*c)
    print("ALL PASS" if allok else "SOME FAILED")
    sys.exit(0 if allok else 1)
