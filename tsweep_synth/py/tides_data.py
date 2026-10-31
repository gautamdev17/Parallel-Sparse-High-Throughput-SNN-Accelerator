"""
tides_data.py -- offline data for the closed-loop TIDES testbench (tb/tb_ours_closed.v) at any T, and the value check.
Same as dac2027_sim/hw/rtl_closed.py gen() / run_check(), with T-generic spike masks (Python ints, R*T bits; the
original tile_masks packs into uint64, which overflows at R*T = 128) and slices.hex words of R*T bits.

  python3 tides_data.py gen <dir> <T> <net> <layer> [batch] [wd]   -> <dir>/closed/{cfg,tiles,kt,pass}.txt, slices.hex
  python3 tides_data.py check <dir> <T> <net> <layer> [batch] [wd] -> compares <dir>/closed/out_closed.txt with the
                                                                      dense reference (sums and LIF spikes)
"""
import os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import workload as wl
from ours import Cfg, LayerPlan, _passes

THETA = 64


def tile_masks(St, T):
    """St: (R, n) T-bit trains -> python ints, bit (r*T + t) = spike of row r at timestep t."""
    return [sum(int(St[r, p]) << (r * T) for r in range(St.shape[0])) for p in range(St.shape[1])]


def tensors(net, li, batch, wd, T):
    layer = wl.NETWORKS[net]()[li]
    seed = zlib.crc32(f"{net}|{li}|{batch}|{wd}|0.1|0.3".encode())     # same tensors as run_all.py / rtl_closed.py
    return wl.layer_tensors(layer, batch, wd, 0.1, 0.3, seed, T=T)


def gen(W, S, cfg, cdir):
    R, C, T = cfg.R, cfg.C, cfg.T
    plan = LayerPlan(W, cfg)
    K, N = S.shape
    Sp = np.zeros((plan.nK * R, N), dtype=S.dtype)
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
    os.makedirs(cdir, exist_ok=True)
    nd = R * T // 4
    open(os.path.join(cdir, "cfg.txt"), "w").write(f"{len(tiles)} {len(krows)} {len(prows)} {len(slices)} {THETA}\n")
    open(os.path.join(cdir, "tiles.txt"), "w").write("\n".join(trows) + "\n")
    open(os.path.join(cdir, "kt.txt"), "w").write("\n".join(krows) + "\n")
    open(os.path.join(cdir, "pass.txt"), "w").write("\n".join(prows) + "\n")
    open(os.path.join(cdir, "slices.hex"), "w").write("\n".join(format(m, f"0{nd}x") for m in slices) + "\n")
    return tiles


def lif_int(sums, theta):
    V = np.zeros(sums.shape[:-1], dtype=np.int64)
    out = np.zeros(sums.shape[:-1], dtype=object)
    for t in range(sums.shape[-1]):
        V = V + sums[..., t]
        f = V >= theta
        out = out + np.where(f, 1 << t, 0).astype(object)
        V = np.where(f, V - theta, V)
    return out


def check(W, S, cfg, cdir, tiles, upto=None):
    """values of every output tile written to out_closed.txt (all tiles, or the first `upto`)."""
    T = cfg.T
    got = {}
    for l in open(os.path.join(cdir, "out_closed.txt")):
        v = l.split()
        sums = [int(x, 16) for x in v[2:2 + T]]
        got[int(v[0]), int(v[1])] = ([x - (1 << 24) if x >> 23 else x for x in sums], int(v[2 + T]))
    ref = wl.dense_sums(W, S, T)
    bad_sum = bad_spk = entries = 0
    for ti, (m0, m1, n0, n1) in enumerate(tiles[:upto]):
        rs = ref[m0:m1, n0:n1]
        rk = lif_int(rs, THETA)
        gs = np.zeros_like(rs)
        gk = np.zeros(rk.shape, dtype=object)
        for f in range(m1 - m0):
            for p in range(n1 - n0):
                e = got.get((ti, (f << 7) | p))
                if e is not None:
                    gs[f, p] = e[0]
                    gk[f, p] = e[1]
        bad_sum += int((gs != rs).any(-1).sum())
        bad_spk += int((gk != rk).sum())
        entries += rs.shape[0] * rs.shape[1]
    return entries, bad_sum, bad_spk


if __name__ == "__main__":
    mode, d, T, net, li = sys.argv[1], sys.argv[2], int(sys.argv[3]), sys.argv[4], int(sys.argv[5])
    batch = int(sys.argv[6]) if len(sys.argv) > 6 else 1
    wd = float(sys.argv[7]) if len(sys.argv) > 7 else 0.1
    cfg = Cfg(T=T)
    W, S = tensors(net, li, batch, wd, T)
    cdir = os.path.join(d, "closed")
    if mode == "gen":
        tiles = gen(W, S, cfg, cdir)
        print(f"{net} L{li} T={T}: M{W.shape[0]} K{W.shape[1]} N{S.shape[1]}, {len(tiles)} tiles -> {cdir}")
    else:
        tiles = gen(W, S, cfg, os.path.join(d, "closed_chk"))          # tile list only (same data)
        e, bs, bk = check(W, S, cfg, cdir, tiles)
        print(f"TIDES T={T} {net} L{li}: {e} outputs x {T} sums checked, sums wrong {bs}, LIF spikes wrong {bk}")
        sys.exit(0 if (bs == 0 and bk == 0) else 1)
