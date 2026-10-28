"""
gen_stim_t.py -- the power-run stimulus of every baseline at T timesteps (tsweep_synth). Same layer, workload and
seed as dac2027_sim/hw/gen_stim.py (VGG16 b2c2, sparse90: weights 10 % non-zero, 10 % non-silent neurons firing
w.p. 0.3 per timestep and at least once, batch 1); only the train length T changes (workload.py copy, any T).

  python3 gen_stim_t.py <design> <T> <outdir> [orig]
     design: ptb spikex sato spikeflow prosperity loas
     orig  : (T = 8 only) the unchanged dac2027_sim generator, for reproducing the existing T = 8 power runs

-> <outdir>/stim/<design>/...   (files and formats as gen_stim.py, plus meta.json with T)

Mappings at any T (the RTL of PTB, SpikeX, Prosperity is not sized by T; see CHANGES.md):
  ptb    : the PTB paper mapping (dac2027_sim/audit/ptb_paper.py): one output position per iteration, row = one
           post-synaptic neuron (output channel), column c = time window c, TW = max(1, T/8) time points, nw = T/TW
           windows (T = 4: 4 windows of TW = 1 on columns 0..3, columns 4..7 idle; T >= 8: 8 windows); StSAP on the
           nw-bit TB-tags (gen_stim.ptb_pairs' greedy). One packed slot = TW cycles: the TW time points are streamed
           as TW sub-iterations (tau), each with its own 'first' flag / scratchpad slot, so every PE psum is one
           (output, position, timestep) sum. At T = 8 (TW = 1) this is gen_stim.gen_array('ptb') byte for byte.
  spikex : temporal mode with the TWS the cycle model picks on this layer (baselines.spikex_layer_cycles):
           TWS = max(1, T/8), nw = T/TWS columns; an input active in any of the pixel's nw windows streams TWS cycles
           (one sub-iteration per time point tau, as for PTB).
  spikeflow: 16/T pixels x T timesteps on the 16 columns (T <= 16); T = 32: each pixel's train in 2 chunks of 16
           (two consecutive passes, each with its own non-silent entries; membrane carried by the LIF row).
  sato, prosperity, loas: the gen_stim.py generators with T (rows (t, pixel) / (pixel, t), T-bit fibre-A).
"""
import json, math, os, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import workload as wl
import gen_stim as G


def tensors(T):
    layer = wl.NETWORKS[G.NET]()[G.LI]
    import zlib
    seed = zlib.crc32(f"{G.NET}|{G.LI}|{G.BATCH}|{G.WD}|{G.NS}|{G.Q}".encode())    # same seed as gen_stim.py
    W, S = wl.layer_tensors(layer, G.BATCH, G.WD, G.NS, G.Q, seed, T=T)
    return layer, W, S


def stsap_pairs(tags, nbits):
    """greedy StSAP of gen_stim.ptb_pairs on nbits-bit tags: [(k, tag)] -> [(a, b|None)]"""
    full = (1 << nbits) - 1
    by, slots = {}, []
    for j, v in tags:
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


def gen_array_t(W, S, kind, T, out, ncyc=G.NCYC):
    """PTB / SpikeX at any T on the unchanged RTL (8 columns, 1-bit spike lanes, one psum slot per iteration).
    stim row: (valid, first, addr, weights a, weights b, spike lanes a, spike lanes b); one row per cycle."""
    rows_n = 16 if kind == "ptb" else 8
    M, K = W.shape
    N = S.shape[1]
    bit = lambda k, p, t: (int(S[k, p]) >> t) & 1
    iters = []                                             # [(columns [(p, t0) or None] , tws, slots)]
    if kind == "ptb":
        tws = max(1, T // 8)
        nw = T // tws
        win = (1 << tws) - 1
        for n in range(N):
            cols = [(n, c * tws) if c < nw else None for c in range(8)]
            tags = [(k, sum(1 << c for c in range(nw) if (int(S[k, n]) >> (c * tws)) & win)) for k in range(K)]
            iters.append((cols, tws, stsap_pairs(tags, nw)))
    else:
        tws = max(1, T // 8)
        nw = T // tws
        for n in range(N):
            cols = [(n, c * tws) if c < nw else None for c in range(8)]
            win = (1 << tws) - 1
            slots = [(k, None) for k in range(K)
                     if any((int(S[k, n]) >> (c * tws)) & win for c in range(nw))]
            iters.append((cols, tws, slots))
    stim, checks, t = [], [], 0
    for cols, tws, slots in iters:
        if not slots:
            continue
        for mb in range(math.ceil(M / rows_n)):
            ch = list(range(mb * rows_n, (mb + 1) * rows_n))
            for tau in range(tws):
                for i, (a, b) in enumerate(slots):
                    wa = [int(W[m, a]) if m < M else 0 for m in ch]
                    wb = [int(W[m, b]) if (b is not None and m < M) else 0 for m in ch]
                    sa = sum(bit(a, cc[0], cc[1] + tau) << c for c, cc in enumerate(cols) if cc)
                    sb = sum(bit(b, cc[0], cc[1] + tau) << c for c, cc in enumerate(cols) if cc) if b is not None else 0
                    assert sa & sb == 0
                    stim.append((1, int(i == 0), len(checks) % 48, wa, wb, sa, sb))
                checks.append(([cc if cc is None else (cc[0], cc[1] + tau) for cc in cols], ch))
                t += len(slots)
            if t >= ncyc and kind != "ptb":        # PTB: all channel blocks of the position, as gen_stim.gen_array
                break
        if t >= ncyc:
            break
    stim.append((1, 1, len(checks) % 48, [0] * rows_n, [0] * rows_n, 0, 0))      # flush the last iteration
    d = os.path.join(out, "stim", kind)
    os.makedirs(d, exist_ok=True)
    if kind == "ptb":
        width = 2 + 6 + 2 * rows_n * 8 + 16
        rows = [G.pack_fields([(v, 1), (f, 1), (a, 6)] + [(x & 0xff, 8) for x in reversed(wa)] +
                              [(x & 0xff, 8) for x in reversed(wb)] + [(sa, 8), (sb, 8)])
                for v, f, a, wa, wb, sa, sb in stim]
    else:
        width = 2 + 6 + rows_n * 8 + 8
        rows = [G.pack_fields([(v, 1), (f, 1), (a, 6)] + [(x & 0xff, 8) for x in reversed(wa)] + [(sa, 8)])
                for v, f, a, wa, wb, sa, sb in stim]
    G.hexrows(os.path.join(d, "in.hex"), rows, width)
    ref = wl.dense_sums(W, S, T)
    exp = np.array([[[ref[m, cc[0], cc[1]] if (cc is not None and m < M) else 0 for cc in cols] for m in ch]
                    for cols, ch in checks])
    np.savez(os.path.join(d, "expected.npz"), sums=exp)
    json.dump(dict(ncyc=len(rows), width=width, iterations=len(checks), T=T, tws=tws),
              open(os.path.join(d, "meta.json"), "w"))
    print(f"{kind} T={T}: TWS={tws}, {len(rows)} stimulus cycles, {len(checks)} (sub-)iterations")


def gen_spikeflow_t(W, S, T, out, npasses=None, pcd=16, rows=16):
    """SpikeFlow passes (channel block 0, consecutive pixel groups / time chunks); passes.txt header per pass:
    'n seg carry' (entries, LIF segment length = min(T, 16), carry = the pass continues the previous pass's
    membranes (T > 16, chunk > 0)). Entries: 16 weights + 16 spike bits."""
    if npasses is None:                # 4 passes as gen_stim.py at T <= 8; T = 16 / 32: 8 / 16 passes (similar window)
        npasses = 4 * max(1, T // 8)
    M, K = W.shape
    seg = min(T, pcd)
    g = max(1, pcd // T)
    nch = max(1, T // pcd)
    words, hdr, checks = [], [], []
    for p0 in range(0, S.shape[1], g):
        if len(hdr) >= npasses:
            break
        px = list(range(p0, min(p0 + g, S.shape[1])))
        for q in range(nch):                                   # time chunk q: timesteps q*16 .. q*16+15
            col = lambda c: (px[c // seg], q * pcd + c % seg) if c // seg < len(px) else None
            ks = [k for k in range(K) if any(col(c) and (int(S[k, col(c)[0]]) >> col(c)[1]) & 1 for c in range(pcd))]
            if not ks:
                continue                                       # (silent chunk: never at this density)
            hdr.append((len(ks), seg, int(q > 0)))
            for k in ks:
                w = [int(W[r, k]) & 0xff for r in range(rows)]
                sp = sum(1 << c for c in range(pcd) if col(c) and (int(S[k, col(c)[0]]) >> col(c)[1]) & 1)
                words.append((w, sp))
            checks.append([col(c) for c in range(pcd)])
    d = os.path.join(out, "stim", "spikeflow")
    os.makedirs(d, exist_ok=True)
    with open(os.path.join(d, "passes.txt"), "w") as f:
        i = 0
        for n, sg, cy in hdr + [(1, seg, 0)]:                  # + one flush pass
            f.write(f"{n} {sg} {cy}\n")
            for _ in range(n):
                w, sp = words[i] if i < len(words) else ([0] * rows, 0)
                f.write("".join(f"{x:02x}" for x in reversed(w)) + f" {sp:04x}\n")
                i += 1
    ref = wl.dense_sums(W[:rows], S, T)
    exp = np.array([[[ref[r, cc[0], cc[1]] if cc else 0 for cc in cols] for r in range(rows)] for cols in checks])
    np.savez(os.path.join(d, "expected.npz"), sums=exp)
    json.dump(dict(passes=len(hdr), entries=sum(h[0] for h in hdr), T=T, seg=seg, chunks=nch),
              open(os.path.join(d, "meta.json"), "w"))
    print(f"spikeflow T={T}: {len(hdr)} passes, {sum(h[0] for h in hdr)} entries, LIF segment {seg}, chunks {nch}")


if __name__ == "__main__":
    kind, T, out = sys.argv[1], int(sys.argv[2]), sys.argv[3]
    orig = len(sys.argv) > 4 and sys.argv[4] == "orig"
    G.OUT = os.path.join(out, "stim")
    layer, W, S = tensors(T)
    if orig:
        assert T == 8
        {"ptb": lambda: G.gen_array(W, S, "ptb"), "spikex": lambda: G.gen_array(W, S, "spikex"),
         "spikeflow": lambda: G.gen_spikeflow(W, S, npasses=4), "sato": lambda: G.gen_sato(W, S),
         "prosperity": lambda: G.gen_prosperity(W, S), "loas": lambda: G.gen_loas(W, S)}[kind]()
    elif kind in ("ptb", "spikex"):
        gen_array_t(W, S, kind, T, out)
    elif kind == "spikeflow":
        gen_spikeflow_t(W, S, T, out)
    elif kind == "sato":
        G.gen_sato(W, S, T=T)
    elif kind == "prosperity":
        G.gen_prosperity(W, S, T=T)
    elif kind == "loas":
        G.gen_loas(W, S, T=T)
    meta = os.path.join(out, "stim", kind, "meta.json")
    m = json.load(open(meta))
    m["T"] = T
    json.dump(m, open(meta, "w"))
