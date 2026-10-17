"""
audit_ours.py -- independent audit of the cycle model of our design (ours.py).

1. An INDEPENDENT simulator written from DAC2027_accelerator_explained_rows.pdf, sharing no code with ours.py:
   its own weight packer, spike packer, and a cycle-by-cycle loop over global time with explicit resources
   (packer, group feeder with edge-FIFO backpressure, shadow-weight loader, per-column edge FIFOs, LIF sweep). It is
   run on random layers (half of them with a 20-entry FIFO so that backpressure binds) and its cycle count must
   equal ours.run_layer_fast, and its output sums must equal the dense reference.
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
    R, C, T, F, G, OPEN, PP, MT, NT, E, LW, LIF, FIFO = 4, 4, 8, 4, 4, 4, 8, 64, 128, 4, 16, 16, 80


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
    pack_clock = 0                   # packer: one K-tile at a time, PP slices per cycle
    released = [0, 0]                # cycle each K-tile's group buffer is freed (double buffer)
    load = math.ceil(R * C / hw.LW)
    for (m0, m1, n0, n1, kts) in tiles:
        npx = n1 - n0
        tile_start = t
        dirty = set()
        # what every group of every pass puts into each column FIFO: the (f, p) it adds to, in slot order
        work = []                    # per K-tile: (groups, [per pass: [per group: [per column: [(f, p)]]]])
        for (kt, spk, wt, groups, passes) in kts:
            per_pass = []
            for cols in passes:
                per_group = []
                for px in groups:
                    per_col = []
                    for c, fl in enumerate(cols):
                        ents = []
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
                                    ents.append((f, p))
                                    sums[m0 + f, n0 + p] += contrib
                                    dirty.add((f, p))
                        per_col.append(ents)
                    per_col += [[] for _ in range(C - len(cols))]
                    per_group.append(per_col)
                per_pass.append(per_group)
            work.append((groups, per_pass))
        # cycle loop: feeder (one group per cycle, held when an edge FIFO could overflow), array delay, edge FIFOs.
        # Feeder credit: a group may enter at cycle x only if for each column c: FIFO entries now + entries of the
        # groups still above that FIFO (entered at s with s + R + c >= x) + its own entries <= FIFO depth.
        # Edge: a bundle that entered at s is written into FIFO c at the end of s + R + c and served from the next
        # cycle; each cycle every column offers its first E entries, column 0 first; an entry with the same (f, p)
        # as an earlier offered one waits (and the entries behind it in that FIFO).
        fifo = [[] for _ in range(C)]
        above = []                   # (entry cycle, per-column entries) of groups not yet in every FIFO
        ki, pi, gi = 0, 0, 0
        ready = None
        may_start = tile_start + load
        pass_start = None
        pk_last = last_bundle_exit = edge_done = tile_start

        def to_next_ktile():
            nonlocal ki, ready, pack_clock, pk_last
            while ki < len(work):
                pack_clock = max(pack_clock, released[-2]) + -(-npx // hw.PP)
                pk_last = pack_clock
                if work[ki][0]:
                    ready = pack_clock
                    return
                released.append(pack_clock)
                ki += 1

        to_next_ktile()
        x = tile_start
        while ki < len(work) or above or any(fifo):
            if not above and not any(fifo) and gi == 0 and ki < len(work):
                x = max(x, may_start, ready)
            # feeder
            if ki < len(work) and (gi > 0 or x >= max(may_start, ready)):
                groups, per_pass = work[ki]
                mine = per_pass[pi][gi]
                fits = all(len(fifo[c]) + len(mine[c]) + sum(len(e[c]) for s0, e in above if s0 + R + c >= x)
                           <= hw.FIFO for c in range(C))
                if fits:
                    above.append((x, mine))
                    if gi == 0:
                        pass_start = x
                    last_bundle_exit = max(last_bundle_exit, x + R + C)
                    gi += 1
                    if gi == len(groups):
                        gi, pi = 0, pi + 1
                        may_start = max(x + 1, pass_start + load)
                        if pi == len(per_pass):
                            released.append(x + 1)
                            ki, pi = ki + 1, 0
                            to_next_ktile()
            # edge service
            flat = []
            for c in range(C):
                offered = fifo[c][:hw.E]
                k = 0
                for e, a in enumerate(offered):
                    if a in flat or a in offered[:e]:
                        break
                    k += 1
                flat += offered
                if k:
                    del fifo[c][:k]
                    edge_done = max(edge_done, x + 1)
            # bundles reaching the FIFOs at the end of x
            for s0, e in above:
                for c in range(C):
                    if s0 + R + c == x:
                        fifo[c] += e[c]
                        assert len(fifo[c]) <= hw.FIFO
            above = [(s0, e) for s0, e in above if s0 + R + C - 1 > x]
            x += 1
        t = max(edge_done, last_bundle_exit, tile_start, pk_last) + -(-len(dirty) // hw.LIF)
    return t, sums


def random_check(n=60):
    """odd layers run with a 20-entry edge FIFO (independent sim and ours.py alike) so that backpressure binds."""
    import workload as wl
    from ours import Cfg, run_layer_fast

    class Small(Hw):
        FIFO = 20

    rng = np.random.default_rng(7)
    bad = stalled = 0
    for i in range(n):
        M = int(rng.integers(1, 90)); K = int(rng.integers(1, 40)); N = int(rng.integers(1, 200))
        wd, ns = [(0.1, 0.1), (0.3, 0.3), (1.0, 0.5), (0.05, 0.2)][i % 4]
        W = wl.rand_weights(rng, M, K, wd)
        S = wl.rand_spikes(rng, (K, N), ns, 0.3)
        hw = Small if i % 2 else Hw
        c_ind, sums = independent_sim(W, S, hw)
        fast = run_layer_fast(W, S, Cfg(D=hw.FIFO))
        c_fast = fast["cycles"]
        stalled += fast["fifo_stalls"] > 0
        ok_v = np.array_equal(sums, wl.dense_sums(W, S))
        if c_ind != c_fast or not ok_v:
            bad += 1
            print(f"  MISMATCH layer {i}: M{M} K{K} N{N} FIFO {hw.FIFO} independent {c_ind} ours.py {c_fast} "
                  f"values_ok={ok_v}")
    print(f"[{'ok' if bad == 0 else 'FAIL'}] independent simulator vs ours.run_layer_fast on {n} random layers: "
          f"{n - bad} identical cycle counts, sums bit-exact vs dense ({stalled} with backpressure stalls)")


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
