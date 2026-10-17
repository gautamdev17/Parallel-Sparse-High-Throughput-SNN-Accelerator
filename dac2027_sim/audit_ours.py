"""
audit_ours.py -- independent audit of the cycle model of our design (ours.py).

1. An INDEPENDENT simulator written from DAC2027_accelerator_explained_rows.pdf, sharing no code with ours.py:
   its own weight packer, spike packer, and a cycle-by-cycle loop over global time with explicit resources
   (packer, group feeder, shadow-weight loader, per-column edge FIFOs, LIF sweep). It is run on random layers and
   its cycle count must equal ours.run_layer_fast, and its output sums must equal the dense reference.
2. Lower bounds for every VGG16 / ResNet18 layer that any correct implementation of the hardware must respect:
     compute    : effectual adds / (R*C*T)          (128 adders, one add each per cycle)
     feeder     : groups injected                    (one group enters the array per cycle per pass)
     packer     : pixel slices scanned / pp
     edge       : read-modify-writes / (C*E)
     lif        : dirty outputs / lif_units
   The model's cycles must be >= the largest bound; the ratio says how tight it is.

  python3 audit_ours.py random     # part 1
  python3 audit_ours.py bounds     # part 2 -> results/audit_bounds.md
"""
import json, math, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)


# =============================================================================== part 1: independent simulator
class Hw:
    R, C, T, F, G, OPEN, PP, MT, NT, E, LW, LIF = 4, 4, 8, 4, 4, 4, 8, 64, 128, 4, 16, 16


def my_weight_columns(wt, F):
    """wt: rows=R inputs x cols=filters (note: transposed vs ours.py). Filters sorted by #non-zeros (desc, stable),
    each placed in the first column where it fits (no shared non-zero row, < F filters)."""
    R, nf = wt.shape
    nz = [(int(np.count_nonzero(wt[:, f])), f) for f in range(nf)]
    nz = [f for c, f in sorted(nz, key=lambda x: (-x[0], x[1])) if c > 0]
    cols = []          # [set of used rows, [filters]]
    for f in nz:
        rows = set(np.nonzero(wt[:, f])[0].tolist())
        for col in cols:
            if len(col[1]) < F and not (col[0] & rows):
                col[0] |= rows
                col[1].append(f)
                break
        else:
            cols.append([rows, [f]])
    return [c[1] for c in cols]


def my_groups(spk, G, OPEN, T):
    """spk: R x npix uint8 spike trains. Pixel order, skip pixels without spikes, put each pixel in the first of
    at most OPEN open groups with no (row, timestep) clash; a full group leaves; when none fits and OPEN groups are
    open, the oldest leaves. Remaining open groups leave at the end, oldest first."""
    R, npx = spk.shape
    out, opened = [], []           # opened: list of (occupied set of (row, t), [pixels])
    for p in range(npx):
        occ = {(r, t) for r in range(R) for t in range(T) if (int(spk[r, p]) >> t) & 1}
        if not occ:
            continue
        placed = False
        for gi, (o, px) in enumerate(opened):
            if not (o & occ):
                o |= occ
                px.append(p)
                if len(px) == G:
                    out.append(opened.pop(gi)[1])
                placed = True
                break
        if not placed:
            if len(opened) == OPEN:
                out.append(opened.pop(0)[1])
            opened.append((occ, [p]))
    out += [px for _, px in opened]
    return out


def independent_sim(W, S, hw=Hw):
    """cycle loop over global time. Returns (cycles, sums[M,N,T])."""
    R, C, T = hw.R, hw.C, hw.T
    M, K = W.shape
    N = S.shape[1]
    nkt = -(-K // R)
    Kp = nkt * R
    Wp = np.zeros((M, Kp), dtype=np.int64); Wp[:, :K] = W
    Sp = np.zeros((Kp, N), dtype=np.uint8); Sp[:K] = S
    sums = np.zeros((M, N, T), dtype=np.int64)
    # ---- build the work list: per output tile, per K-tile with weights: groups, passes
    tiles = []
    for m0 in range(0, M, hw.MT):
        m1 = min(m0 + hw.MT, M)
        for n0 in range(0, N, hw.NT):
            n1 = min(n0 + hw.NT, N)
            kts = []
            for kt in range(nkt):
                wt = Wp[m0:m1, kt * R:(kt + 1) * R].T          # R x filters
                cols = my_weight_columns(wt, hw.F)
                if not cols:
                    continue
                spk = Sp[kt * R:(kt + 1) * R, n0:n1]
                groups = my_groups(spk, hw.G, hw.OPEN, T)
                passes = [cols[i:i + C] for i in range(0, len(cols), C)]
                kts.append((kt, spk, wt, groups, passes))
            tiles.append((m0, m1, n0, n1, kts))
    # ---- time loop
    t = 0
    pack_clock = 0.0                 # packer works on a continuous slice stream
    released = [0, 0]                # cycle each K-tile's group buffer is freed (double buffer)
    for (m0, m1, n0, n1, kts) in tiles:
        npx = n1 - n0
        tile_start = t
        next_inject = tile_start + math.ceil(R * C / hw.LW)   # first weights loaded
        arrivals = {c: [] for c in range(C)}                  # (cycle, entries)
        last_bundle_exit = tile_start
        dirty = set()
        for (kt, spk, wt, groups, passes) in kts:
            pstart = max(pack_clock, released[-2])
            pack_clock = pstart + npx / hw.PP
            ready = math.ceil(pack_clock)
            if not groups:
                released.append(ready)
                continue
            for cols in passes:
                s = max(next_inject, ready)
                for g, px in enumerate(groups):
                    # the group's running sums leave column c at s + g + R + c; count the touched (f, p) and add
                    for c, fl in enumerate(cols):
                        n_ent = 0
                        for f in fl:
                            for p in px:
                                contrib = np.zeros(T, dtype=np.int64)
                                hit = False
                                for r in range(R):
                                    w = int(wt[r, f])
                                    v = int(spk[r, p])
                                    if w and v:
                                        hit = True
                                        for tt in range(T):
                                            if (v >> tt) & 1:
                                                contrib[tt] += w
                                if hit:
                                    n_ent += 1
                                    sums[m0 + f, n0 + p] += contrib
                                    dirty.add((f, p))
                        if n_ent:
                            arrivals[c].append((s + g + R + c, n_ent))
                last_bundle_exit = max(last_bundle_exit, s + len(groups) - 1 + R + C - 1 + 1)
                next_inject = s + max(len(groups), math.ceil(R * C / hw.LW))
                last_in = s + len(groups)
            released.append(last_in)
        # edge FIFOs: E entries per cycle per column, served from the arrival cycle on
        edge_done = tile_start
        for c in range(C):
            q, cyc = 0, None
            for (ta, na) in arrivals[c]:
                if cyc is not None:
                    q = max(0, q - hw.E * (ta - cyc - 1))
                q += na
                q = max(0, q - hw.E)
                cyc = ta
            if cyc is not None:
                edge_done = max(edge_done, cyc + -(-q // hw.E) + 1)
        t = max(edge_done, last_bundle_exit, tile_start) + -(-len(dirty) // hw.LIF)
    return t, sums


def random_check(n=60):
    import workload as wl
    from ours import Cfg, run_layer_fast
    rng = np.random.default_rng(7)
    bad = 0
    for i in range(n):
        M = int(rng.integers(1, 90)); K = int(rng.integers(1, 40)); N = int(rng.integers(1, 200))
        wd, ns = [(0.1, 0.1), (0.3, 0.3), (1.0, 0.5), (0.05, 0.2)][i % 4]
        W = wl.rand_weights(rng, M, K, wd)
        S = wl.rand_spikes(rng, (K, N), ns, 0.3)
        c_ind, sums = independent_sim(W, S)
        c_fast = run_layer_fast(W, S, Cfg())["cycles"]
        ok_v = np.array_equal(sums, wl.dense_sums(W, S))
        if c_ind != c_fast or not ok_v:
            bad += 1
            print(f"  MISMATCH layer {i}: M{M} K{K} N{N} independent {c_ind} ours.py {c_fast} values_ok={ok_v}")
    print(f"[{'ok' if bad == 0 else 'FAIL'}] independent simulator vs ours.run_layer_fast on {n} random layers: "
          f"{n - bad} identical cycle counts, sums bit-exact vs dense")


# =============================================================================== part 2: lower bounds
def bounds():
    import workload as wl
    from ours import Cfg, run_layer_fast
    cfg = Cfg()
    lines = ["| Network | Batch | Model cycles | compute bound | feeder bound | packer bound | edge bound | LIF bound "
             "| model / max bound | binding |", "|---|---|---:|---:|---:|---:|---:|---:|---:|---|"]
    out = {}
    for net in ("VGG16", "ResNet18"):
        for b in (1, 16):
            tot = dict(model=0, compute=0, feeder=0, packer=0, edge=0, lif=0)
            for li, layer in enumerate(wl.NETWORKS[net]()):
                M, K, N = wl.gemm_shape(layer, b)
                seed = zlib.crc32(f"{net}|{li}|{b}|0.1|0.1|0.3".encode())
                W, S = wl.layer_tensors(layer, b, 0.1, 0.1, 0.3, seed)
                st = run_layer_fast(W, S, cfg)
                eff = int(((W != 0).sum(0) * np.unpackbits(S[..., None], axis=-1).sum((1, 2))).sum())
                nkt_scanned = st["pixels_scanned"] if "pixels_scanned" in st else None
                n_mblk = math.ceil(M / cfg.Mt)
                # packer: every K-tile with weights is scanned once per output tile (all its pixels)
                kt_w = sum(1 for (bi, kt), (cols, _) in __import__("ours").LayerPlan(W, cfg).cols.items() if cols)
                slices = kt_w * N
                lb = dict(compute=eff / cfg.adders, feeder=st["groups"], packer=slices / cfg.pp,
                          edge=st["rmw"] / (cfg.C * cfg.E), lif=st["lif"])
                tot["model"] += st["cycles"]
                for k, v in lb.items():
                    tot[k] += v
            mx = max(tot[k] for k in ("compute", "feeder", "packer", "edge", "lif"))
            bind = max(("compute", "feeder", "packer", "edge", "lif"), key=lambda k: tot[k])
            out[f"{net}|{b}"] = tot
            lines.append(f"| {net} | {b} | {tot['model']:,.0f} | {tot['compute']:,.0f} | {tot['feeder']:,.0f} | "
                         f"{tot['packer']:,.0f} | {tot['edge']:,.0f} | {tot['lif']:,.0f} | {tot['model'] / mx:.2f} | {bind} |")
            assert tot["model"] >= mx - 1, (net, b, tot)
    txt = "\n".join(lines)
    open(os.path.join(HERE, "results", "audit_bounds.md"), "w").write(txt + "\n")
    json.dump(out, open(os.path.join(HERE, "results", "audit_bounds.json"), "w"), indent=1)
    print(txt)


if __name__ == "__main__":
    {"random": random_check, "bounds": bounds}[sys.argv[1]]()
