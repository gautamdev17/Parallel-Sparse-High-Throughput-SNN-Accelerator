"""
gen_stim.py -- cycle-by-cycle RTL stimulus for the power runs, generated from the SAME schedules as the
cycle models (ours.py / baselines.py) on one representative layer: VGG16 b2c2 (M=128, K=1152, N=256),
workload sparse90, batch 1, same seed as run_all.py.

  python3 gen_stim.py            -> build/stim/{ours,ptb,spikex}/*.hex + meta.json + expected.npz

ours   : one full output tile (filters 0..63, pixels 0..127, all 288 K-tiles): array injections, shadow weight
         loads at the exact swap cycles, packer slice stream (same timing rule as ours._Packer), ids sideband.
         The testbench runs the edge unit and the LIF sweep itself and checks the output buffer.
ptb    : iterations (pixel n, 16-channel block) from the start of the layer, StSAP pairs, until ~NCYC cycles.
spikex : iterations (pixel n, 8-channel block), temporal mode TWS=1, until ~NCYC cycles.
"""
import json, math, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import workload as wl
from ours import Cfg, LayerPlan, pack_spikes, tile_masks, _passes, _Packer

NET, LI, BATCH = "VGG16", 3, 1
WD, NS, Q = 0.10, 0.10, 0.3
NCYC = 6000
OUT = os.path.join(HERE, "build", "stim")


def tensors():
    layer = wl.NETWORKS[NET]()[LI]
    seed = zlib.crc32(f"{NET}|{LI}|{BATCH}|{WD}|{NS}|{Q}".encode())
    W, S = wl.layer_tensors(layer, BATCH, WD, NS, Q, seed)
    return layer, W, S


def hexrows(path, rows, width):
    nd = (width + 3) // 4
    with open(path, "w") as f:
        for v in rows:
            f.write(format(int(v), f"0{nd}x") + "\n")


def pack_fields(fields):
    """fields: list of (value, width) from MSB to LSB -> int"""
    v = 0
    for x, w in fields:
        v = (v << w) | (int(x) & ((1 << w) - 1))
    return v


# ---------------------------------------------------------------------------------------- ours
def gen_ours(W, S):
    cfg = Cfg()
    R, C, T, F, G = cfg.R, cfg.C, cfg.T, cfg.F, cfg.G
    plan = LayerPlan(W, cfg)
    bi, (m0, m1) = 0, plan.mblocks[0]
    n0, n1 = 0, min(cfg.Nt, S.shape[1])
    nn = n1 - n0
    K = S.shape[0]
    Sp = np.zeros((plan.nK * R, S.shape[1]), dtype=np.uint8)
    Sp[:K] = S
    packer = _Packer(cfg.pp)
    events = {}                      # cycle -> dict of fields

    def ev(t):
        return events.setdefault(t, {"inj": None, "wl": {}, "sl": [], "flush": 0})

    s_next = cfg.L
    pass_id = 0
    first_pass_weights = None
    prev_pass = None                 # (s, P) of previous pass, for shadow-load timing
    expected_groups = []
    pk_cursor = 0.0
    for kt in range(plan.nK):
        cols, Wt = plan.cols[bi, kt]
        if not cols:
            continue
        St = Sp[kt * R:(kt + 1) * R, n0:n1]
        masks = tile_masks(St, T)
        start = max(packer.end, packer.free[-2])
        pk = packer.pack(nn)
        # packer slice stream: slice q at cycle floor(start*pp + q) // pp
        for q in range(nn):
            cyc = int(math.floor(start * cfg.pp + q)) // cfg.pp
            ev(cyc)["sl"].append((masks[q], q))
        ev(int(math.floor(start * cfg.pp + nn - 1)) // cfg.pp)["flush"] = 1
        groups = pack_spikes(masks, G, cfg.W_open)
        expected_groups.append([sorted(g) for g in groups])
        if not groups:
            packer.release(pk)
            continue
        gl = []
        for ps in groups:
            bits = [0] * R
            lab = [[0] * T for _ in range(R)]
            for gi, p in enumerate(ps):
                for r in range(R):
                    v = int(St[r, p])
                    bits[r] |= v
                    for t in range(T):
                        if v >> t & 1:
                            lab[r][t] = gi
            pid = list(ps) + [0] * (G - len(ps))
            gl.append((bits, lab, pid))
        P = len(gl)
        for pas in _passes(cols, C):
            s = max(s_next, pk)
            par = (pass_id + 1) & 1
            # PE weights of this pass
            pw = {}
            for k in range(R):
                for c in range(C):
                    pw[k, c] = (0, 0)
            fid = []
            for c in range(C):
                fl = pas[c] if c < len(pas) else []
                fid.append(list(fl) + [0] * (F - len(fl)))
                for fi, f in enumerate(fl):
                    for k in np.nonzero(Wt[f])[0]:
                        pw[int(k), c] = (int(Wt[f, k]), fi)
            # shadow load: pass 0 at cycle 0, pass j at the swap cycle of pass j-1 in that PE
            for k in range(R):
                for c in range(C):
                    tl = 0 if prev_pass is None else prev_pass[0] + k + c
                    ev(tl)["wl"][k * C + c] = (pw[k, c][0], pw[k, c][1], par)
            for g, (bits, lab, pid) in enumerate(gl):
                e = ev(s + g)
                assert e["inj"] is None
                e["inj"] = (par, bits, lab, pid, fid)
            prev_pass = (s, P)
            s_next = s + max(P, cfg.L)
            pass_id += 1
            last_in = s + P
        packer.release(last_in)
    ncyc = max(events) + 1
    # ---- encode
    rows = {k: [] for k in ("inj", "wl", "pk")}
    for t in range(ncyc):
        e = events.get(t, {"inj": None, "wl": {}, "sl": [], "flush": 0})
        if e["inj"] is None:
            rows["inj"].append(0)
        else:
            par, bits, lab, pid, fid = e["inj"]
            fl = [(1, 1), (par, 1)]
            fl += [(bits[r], T) for r in reversed(range(R))]
            for r in reversed(range(R)):
                fl += [(lab[r][t2], 2) for t2 in reversed(range(T))]
            fl += [(p, 7) for p in reversed(pid)]
            for c in reversed(range(C)):
                fl += [(x, 6) for x in reversed(fid[c])]
            rows["inj"].append(pack_fields(fl))
        en = [0] * (R * C); ww = [0] * (R * C); ff = [0] * (R * C); pp_ = [0] * (R * C)
        for p, (w, f, par) in e["wl"].items():
            en[p], ww[p], ff[p], pp_[p] = 1, w, f, par
        fl = [(x, 1) for x in reversed(en)] + [(x & 0xff, 8) for x in reversed(ww)] + \
             [(x, 2) for x in reversed(ff)] + [(x, 1) for x in reversed(pp_)]
        rows["wl"].append(pack_fields(fl))
        sl = e["sl"]
        assert len(sl) <= cfg.pp
        sv = [1] * len(sl) + [0] * (cfg.pp - len(sl))
        sm = [m for m, _ in sl] + [0] * (cfg.pp - len(sl))
        si = [q for _, q in sl] + [0] * (cfg.pp - len(sl))
        fl = [(e["flush"], 1)] + [(x, 1) for x in reversed(sv)] + [(x, R * T) for x in reversed(sm)] + \
             [(x, 7) for x in reversed(si)]
        rows["pk"].append(pack_fields(fl))
    d = os.path.join(OUT, "ours")
    os.makedirs(d, exist_ok=True)
    INJW = 2 + R * T + R * 2 * T + G * 7 + C * F * 6
    WLW = R * C * (1 + 8 + 2 + 1)
    PKW = 1 + cfg.pp * (1 + R * T + 7)
    hexrows(os.path.join(d, "inj.hex"), rows["inj"], INJW)
    hexrows(os.path.join(d, "wl.hex"), rows["wl"], WLW)
    hexrows(os.path.join(d, "pk.hex"), rows["pk"], PKW)
    # expected output buffer: partial sums of filters m0..m1 over pixels n0..n1, all K
    ref = wl.dense_sums(W[m0:m1], S[:, n0:n1])
    np.savez(os.path.join(d, "expected.npz"), sums=ref)
    json.dump(dict(ncyc=ncyc, INJW=INJW, WLW=WLW, PKW=PKW, passes=pass_id, m=[m0, m1], n=[n0, n1],
                   groups=expected_groups), open(os.path.join(d, "meta.json"), "w"))
    print(f"ours: {ncyc} stimulus cycles, {pass_id} passes")


# ---------------------------------------------------------------------------------------- PTB / SpikeX
def ptb_pairs(col):
    """explicit StSAP pairing of one pixel's receptive field (same greedy policy as baselines.ptb_slots)."""
    T = 8
    full = (1 << T) - 1
    by = {}
    slots = []
    for j, v in enumerate(col.tolist()):
        if v == 0:
            continue
        if v == full:
            slots.append((j, None))
        else:
            by.setdefault(v, []).append(j)
    pc = lambda x: bin(x).count("1")
    for a in sorted(range(1, full), key=lambda v: -pc(v)):
        cands = sorted([b for b in range(1, full) if (a & b) == 0], key=lambda b: (b != (full ^ a), -pc(b)))
        for b in cands:
            while by.get(a) and by.get(b):
                slots.append((by[a].pop(), by[b].pop()))
    for v, js in by.items():
        slots += [(j, None) for j in js]
    return slots


def gen_array(W, S, kind):
    rows_n = 16 if kind == "ptb" else 8
    M = W.shape[0]
    stim, checks = [], []
    t = 0
    for n in range(S.shape[1]):
        col = S[:, n]
        if kind == "ptb":
            slots = ptb_pairs(col)
        else:
            slots = [(j, None) for j in np.nonzero(col)[0].tolist()]
        for mb in range(math.ceil(M / rows_n)):
            if not slots:
                continue
            ch = list(range(mb * rows_n, min(M, (mb + 1) * rows_n)))
            for i, (a, b) in enumerate(slots):
                wa = [int(W[m, a]) if m < M else 0 for m in range(mb * rows_n, (mb + 1) * rows_n)]
                wb = [int(W[m, b]) if (b is not None and m < M) else 0 for m in range(mb * rows_n, (mb + 1) * rows_n)]
                stim.append((1, int(i == 0), len(checks) % 48, wa, wb, int(S[a, n]), int(S[b, n]) if b is not None else 0))
            checks.append((n, ch))
            t += len(slots)
        if t >= NCYC:
            break
    stim.append((1, 1, len(checks) % 48, [0] * rows_n, [0] * rows_n, 0, 0))     # flush the last iteration
    d = os.path.join(OUT, kind)
    os.makedirs(d, exist_ok=True)
    if kind == "ptb":
        width = 2 + 6 + 2 * rows_n * 8 + 16
        rows = [pack_fields([(v, 1), (f, 1), (a, 6)] + [(x & 0xff, 8) for x in reversed(wa)] +
                            [(x & 0xff, 8) for x in reversed(wb)] + [(sa, 8), (sb, 8)])
                for v, f, a, wa, wb, sa, sb in stim]
    else:
        width = 2 + 6 + rows_n * 8 + 8
        rows = [pack_fields([(v, 1), (f, 1), (a, 6)] + [(x & 0xff, 8) for x in reversed(wa)] + [(sa, 8)])
                for v, f, a, wa, wb, sa, sb in stim]
    hexrows(os.path.join(d, "in.hex"), rows, width)
    ref = wl.dense_sums(W, S)
    exp = np.array([[ref[m, n] if m < M else np.zeros(8, dtype=np.int64) for m in range(ch[0], ch[0] + rows_n)]
                    for n, ch in checks])
    np.savez(os.path.join(d, "expected.npz"), sums=exp)
    json.dump(dict(ncyc=len(rows), width=width, iterations=len(checks)), open(os.path.join(d, "meta.json"), "w"))
    print(f"{kind}: {len(rows)} stimulus cycles, {len(checks)} iterations")


if __name__ == "__main__" and len(sys.argv) == 1:
    layer, W, S = tensors()
    gen_ours(W, S)
    gen_array(W, S, "ptb")
    gen_array(W, S, "spikex")


def gen_spikeflow(W, S, npasses=64, T=8, pcd=16, rows=16):
    """SpikeFlow passes (channel block 0, consecutive pixel groups): only non-silent K entries, as in the model."""
    g = pcd // T
    M, K = W.shape
    words, hdr, checks = [], [], []
    for p0 in range(0, S.shape[1], g):
        if len(hdr) == npasses:
            break
        px = list(range(p0, min(p0 + g, S.shape[1])))
        ks = [k for k in range(K) if any(S[k, p] for p in px)]
        if not ks:
            continue
        hdr.append(len(ks))
        for k in ks:
            w = [int(W[r, k]) & 0xff for r in range(rows)]
            sp = 0
            for c in range(pcd):
                p = px[c // T] if c // T < len(px) else None
                if p is not None and (int(S[k, p]) >> (c % T)) & 1:
                    sp |= 1 << c
            words.append((w, sp))
        checks.append(px)
    d = os.path.join(OUT, "spikeflow")
    os.makedirs(d, exist_ok=True)
    with open(os.path.join(d, "passes.txt"), "w") as f:
        i = 0
        for n in hdr + [1]:                         # + one flush pass
            f.write(f"{n}\n")
            for _ in range(n):
                if i < len(words):
                    w, sp = words[i]
                else:
                    w, sp = [0] * rows, 0
                f.write("".join(f"{x:02x}" for x in reversed(w)) + f" {sp:04x}\n")
                i += 1
    ref = wl.dense_sums(W[:rows], S)
    exp = np.array([[[ref[r, px[c // T], c % T] if c // T < len(px) else 0 for c in range(pcd)] for r in range(rows)]
                    for px in checks])
    np.savez(os.path.join(d, "expected.npz"), sums=exp)
    model_cycles = sum(hdr) + rows + pcd - 2       # baselines.spikeflow_layer_cycles on these passes (one block)
    json.dump(dict(passes=len(hdr), entries=sum(hdr), model_cycles=model_cycles), open(os.path.join(d, "meta.json"), "w"))
    print(f"spikeflow: {len(hdr)} passes, {sum(hdr)} entries, model cycles {model_cycles}")


if __name__ == "__main__" and len(sys.argv) > 1 and sys.argv[1] == "spikeflow":
    layer, W, S = tensors()
    gen_spikeflow(W, S)


def gen_sato(W, S, nch=8, npe=128, T=8, iw=12):
    """SATO schedule of the Prosperity-repo model: rows (t, pixel) t-major, greedy least-loaded PE (first index on
    ties), then for each output channel every PE walks its rows' spikes; channel phase = max PE load."""
    K, N = S.shape
    rows = []
    for t in range(T):
        for p in range(N):
            rows.append([k for k in range(K) if (int(S[k, p]) >> t) & 1])
    load = np.zeros(npe, dtype=np.int64)
    owner = []
    for r in rows:
        i = int(np.argmin(load))
        owner.append(i)
        load[i] += len(r)
    maxload = int(load.max())
    per_pe = [[] for _ in range(npe)]
    for ri, i in enumerate(owner):
        if rows[ri]:
            per_pe[i].append(ri)
    stim, checks = [], []
    for n in range(nch):
        seq = [[(ri, k, j == len(rows[ri]) - 1) for ri in per_pe[i] for j, k in enumerate(rows[ri])] for i in range(npe)]
        for c in range(maxload):
            v = re = 0
            idx = [0] * npe
            ww = [0] * npe
            for i in range(npe):
                if c < len(seq[i]):
                    ri, k, last = seq[i][c]
                    v |= 1 << i
                    re |= (1 << i) if last else 0
                    idx[i], ww[i] = k, int(W[n, k]) & 0xff
                    if last:
                        t, p = divmod(ri, N)
                        checks.append((i, n, int(sum(int(W[n, kk]) for kk in rows[ri]))))
            stim.append((v, re, idx, ww))
    d = os.path.join(OUT, "sato")
    os.makedirs(d, exist_ok=True)
    width = 2 * npe + npe * iw + npe * 8
    hexrows(os.path.join(d, "in.hex"),
            [pack_fields([(v, npe), (re, npe)] + [(x, iw) for x in reversed(idx)] + [(x, 8) for x in reversed(ww)])
             for v, re, idx, ww in stim], width)
    # dispatcher stream: the rows of the layer, one per cycle (popcount of the first 16 inputs + count of the rest)
    drows = []
    for r in rows[:len(stim)]:
        lo = sum(1 << k for k in r if k < 16)
        drows.append(pack_fields([(1, 1), (lo, 16), (min(63, sum(1 for k in r if k >= 16)), 6)]))
    hexrows(os.path.join(d, "disp.hex"), drows, 23)
    json.dump(dict(ncyc=len(stim), maxload=maxload, channels=nch, rows=len(rows), owner=owner[:len(drows)],
                   checks=checks), open(os.path.join(d, "meta.json"), "w"))
    print(f"sato: {len(stim)} cycles = {nch} channels x max load {maxload}; {len(checks)} row integrations to check")


if __name__ == "__main__" and len(sys.argv) > 1 and sys.argv[1] == "sato":
    layer, W, S = tensors()
    gen_sato(W, S)


def gen_prosperity(W, S, ntiles=16, m=256, k=16, n=128, T=8):
    """tiles of the official simulator's layout (rows = (pixel, t), pixel-major), m-tile 0, k-tiles 0..ntiles-1,
    with the official find_product_sparsity result and cost per tile."""
    sys.path.insert(0, os.path.dirname(HERE))
    import prosperity_official as P                 # official code (needs torch)
    import torch
    K, N = S.shape
    rows = np.zeros((N * T, K), dtype=np.uint8)
    for p in range(N):
        for t in range(T):
            rows[p * T + t] = (S[:, p] >> t) & 1
    d = os.path.join(OUT, "prosperity")
    os.makedirs(d, exist_ok=True)
    tiles, wts, meta = [], [], []
    for kt in range(ntiles):
        act = rows[:m, kt * k:(kt + 1) * k]
        pre, prefix = P._orig(torch.from_numpy(act.astype(bool)))          # the simulator's own function
        pre = pre.numpy().astype(np.uint8)
        prefix = prefix.numpy().astype(int).tolist()
        nnz_pre = int(pre.sum())
        zero_pre = int((pre.sum(1) == 0).sum())
        zero_ori = int((act.sum(1) == 0).sum())
        compute = nnz_pre + zero_pre - zero_ori                             # simulator: cur_compute_cycles
        preprocess = int((act.sum(1) > 1).sum()) + m // 8                   # simulator: prosparsity_cycles
        tiles += [sum(int(b) << j for j, b in enumerate(r)) for r in act]
        Wt = W[:n, kt * k:(kt + 1) * k]                                     # (n, k)
        wts += [pack_fields([(int(Wt[c, j]) & 0xff, 8) for c in reversed(range(n))]) for j in range(k)]
        res = (Wt.astype(np.int64) @ act.T.astype(np.int64)).T             # (m, n) tile result per row
        meta.append(dict(compute=compute, preprocess=preprocess, prefix=prefix,
                         pattern=[sum(int(b) << j for j, b in enumerate(r)) for r in pre], res=res.tolist()))
    hexrows(os.path.join(d, "rows.hex"), tiles, k)
    hexrows(os.path.join(d, "wts.hex"), wts, n * 8)
    json.dump(dict(ntiles=ntiles, tiles=meta), open(os.path.join(d, "meta.json"), "w"))
    print(f"prosperity: {ntiles} tiles, official compute cycles {sum(t['compute'] for t in meta)}, "
          f"preprocess {sum(t['preprocess'] for t in meta)}")


if __name__ == "__main__" and len(sys.argv) > 1 and sys.argv[1] == "prosperity":
    layer, W, S = tensors()
    gen_prosperity(W, S)
