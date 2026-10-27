"""
loas_paper.py -- paper-faithful per-layer LoAS model (Yin et al., LoAS, text in scratchpad/papers/LoAS.txt), for
auditing dac2027_sim/loas_model.py, mem_levels.loas_layer and the LoAS DRAM rule of prune_chain.layer_sim.
Writes nothing into the repo (run with python -B so no __pycache__ lands there).

Notation: our traces have W = M x K (M = output channels) and S = K x N (N = output pixels, im2col'd K).
The paper's A (M x K x T) is our S^T, its B (K x N) our W^T: paper rows of A = our pixels, paper fibre-B = our
weight row (one output channel).

Hardware from the paper (line numbers of LoAS.txt):
  16 TPPEs (l.1182), 128-bit bitmask buffers (l.877, l.1189), fast prefix sum: offsets in one cycle, one matched
  weight per cycle into the pseudo-accumulator (l.1063-1064, l.1185-1186), laggy prefix sum: 16 adders, all
  offsets of bm-A after 8 cycles (l.984-985, l.1187-1188), 2 depth-8 FIFOs (l.1188-1189), one correction check
  per buffered match after the laggy ready (l.1066-1071), fibre-B fetch overlapped with laggy + correction
  (l.1080-1083), each TPPE = one output neuron, distinct fibre-A per TPPE, one fibre-B broadcast (l.873-881,
  l.1113-1114), P-LIF all timesteps at once (l.888-889, l.1092-1095), 256 KB double-buffered global cache,
  16 banks 16-way (l.1153, l.1192), fibres = bitmask + pointer + non-zeros (l.853-860, l.1099-1104), fibre-A
  held as long as possible in the cache (l.1108-1112), outputs compressed by the compressor and written back
  on chip (l.754, l.795, l.1115-1120), HBM 128 GB/s (l.1155, l.1214).

Variants (cycles):
  strict  : mapping A only (paper), fibre-B load serialised with join+compute (= current formula, mapping A only)
  paper   : mapping A only, fibre-B load overlapped with the previous chunk's laggy/correction
            -> round = max(load, join + slowest TPPE compute)
  lenient : paper + best of mappings A/B per layer (as current) + chunks whose fibre-B chunk is empty skipped
Variants (memory):
  SRAM reads: fibre-B (bitmask [+16-bit ptr strict] + 8-bit nnz) once per round and chunk (broadcast); per TPPE
  bm-A (+ptr strict) per chunk + T bits per matched non-silent input. Writes = DRAM fills + compressed output;
  paper/strict add the read-out of the output for its DRAM write-back.
  DRAM: A = exact compressed im2col fibres from S (16-B bitmask per chunk + T bits per non-silent input),
        W = 16-B bitmask per chunk + 1 B per non-zero, [+2 B pointer per fibre-chunk in strict];
        out = compressed (bitmask + T bits per non-silent output, density from the next layer's raw map) in
              paper/lenient, dense T bits in strict (= current);
        reuse: lenient = current split_tiled (min of the two loop orders, 128 KB tiles);
               paper   = paper loop order (fibre-A group of 16 rows held, fibre-B streamed), 128 KB effective
                         (double-buffered 256 KB), weights kept up to the free capacity, the rest re-fetched per
                         16-pixel group (optimal replacement);
               strict  = same order, LRU: if W + A_group > 128 KB the whole W is re-fetched per group.
"""
import json, math, os, sys
sys.dont_write_bytecode = True
import numpy as np

REPO = "/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/dac2027_sim"
SD = os.path.join(REPO, "results", "prune_chain")
TPPES, CHUNK, LAGGY, BUS, T = 16, 128, 8, 16, 8
KB = 1024
PTR = 16                     # pointer bits per fibre-chunk (strict only; the paper gives no width)


def per_chunk(W, S):
    wnz, snz = (W != 0), (S != 0)
    for c0 in range(0, W.shape[1], CHUNK):
        wc = wnz[:, c0:c0 + CHUNK].astype(np.float32)
        m = np.rint(wc @ snz[c0:c0 + CHUNK].astype(np.float32)).astype(np.int64)   # (M, N) matches
        nnz = wnz[:, c0:c0 + CHUNK].sum(1).astype(np.int64)                         # (M,)
        yield m, nnz


def group_max(c, axis):
    c = c if axis == 1 else c.T
    pad = (-c.shape[1]) % TPPES
    if pad:
        c = np.concatenate([c, np.zeros((c.shape[0], pad), dtype=c.dtype)], 1)
    g = c.reshape(c.shape[0], -1, TPPES).max(2)
    return int(g.sum()), g.size


def layer(W, S, raw_next=None):
    """-> {variant: dict(cycles, axis, sram_r, sram_w, dram, dram_parts)} (bits)."""
    M, K = W.shape
    N = S.shape[1]
    nch = math.ceil(K / CHUNK)
    snz = S != 0
    tot = {(v, ax): 0 for v in ("strict", "paper", "lenient") for ax in (0, 1)}
    rounds = {}
    sr = {(v, ax): 0 for v in ("strict", "paper", "lenient") for ax in (0, 1)}
    nacc = 0                 # paper mapping A, SRAM read ACCESSES (128-bit block each): fibre-B lines, bm-A, one per match
    nmatch = 0
    run = np.zeros((M, N), dtype=np.int64)   # per-output sum of overlapped chunk cycles (sync per output, not per chunk)
    for m, nnz in per_chunk(W, S):
        load = 1 + -(-nnz // BUS)                              # bitmasks + non-zero weights, 16 B per cycle
        comp = np.where(m > 0, LAGGY + m + 1, 0)               # laggy ready at 8, last correction, fibre-A latency
        c_ser = load[:, None] + 1 + comp
        c_ovl = np.maximum(load[:, None], 1 + comp)
        c_skp = np.where(nnz[:, None] > 0, c_ovl, 0)
        run += c_ovl
        T_match = T * int(m.sum())
        nmatch += int(m.sum())
        nacc += int((-(-(128 + 8 * nnz) // 128)).sum()) * math.ceil(N / TPPES) + M * N + int(m.sum())
        for ax in (0, 1):
            for v, c in (("strict", c_ser), ("paper", c_ovl), ("lenient", c_skp)):
                t, r = group_max(c, ax)
                tot[(v, ax)] += t
                rounds[ax] = r
            # SRAM reads
            for v in ("strict", "paper", "lenient"):
                p = PTR if v == "strict" else 0
                live = (nnz > 0) if v == "lenient" else np.ones(M, bool)
                fibw = (128 + p + 8 * nnz) * live
                if ax == 1:          # A: 16 pixels share the broadcast weight fibre
                    rA = math.ceil(N / TPPES)
                    sr[(v, ax)] += int(fibw.sum()) * rA + int(live.sum()) * N * (128 + p) + T_match
                else:                # B: 16 channels share the broadcast spike bitmask
                    rB = math.ceil(M / TPPES)
                    sr[(v, ax)] += N * rB * (128 + p) + int(fibw.sum()) * N + T_match
    for k in tot:
        tot[k] += rounds[k[1]]                                 # 1 P-LIF cycle per round of 16 outputs
    # ---------------- DRAM (bytes)
    nzrow = snz.sum(0)                                         # non-silent inputs per im2col row (pixel)
    A_rows = nch * 16 + nzrow * T / 8                          # per pixel row
    A = float(A_rows.sum())
    Wb = M * nch * 16 + float((W != 0).sum())
    ptrB = 2 * nch                                             # strict pointer bytes per fibre
    A_s, W_s = A + N * ptrB, Wb + M * ptrB
    O_dense = M * N * T / 8
    O_comp = (M * N / 8 + raw_next * T / 8) if raw_next is not None else O_dense
    ngrp = math.ceil(N / TPPES)
    A_grp = float(np.sort(A_rows)[::-1][:TPPES].sum())        # worst-case resident group
    cap = 128 * KB

    def paper_reuse(Ab, Wbb, lru):
        free = max(0.0, cap - A_grp)
        if Wbb <= free:
            return Ab, Wbb
        if lru:
            return Ab, Wbb * ngrp
        return Ab, Wbb + (ngrp - 1) * (Wbb - free)

    def split_tiled(I, Wt, buf=256 * KB):
        half = buf / 2
        a = (Wt + I * math.ceil(Wt / half), I * math.ceil(Wt / half), Wt) if Wt > 0 else (I, I, 0)
        b = (I + Wt * math.ceil(I / half), I, Wt * math.ceil(I / half)) if I > 0 else (Wt, 0, Wt)
        return min(a, b)[1:]

    dram = {"strict": paper_reuse(A_s, W_s, True) + (O_dense,),
            "paper": paper_reuse(A, Wb, False) + (O_comp,),
            "lenient": split_tiled(A, Wb) + (O_comp,)}
    out = {}
    for v in ("strict", "paper", "lenient"):
        axes = (1,) if v in ("strict", "paper") else (1, 0)
        ax = min(axes, key=lambda a: (tot[(v, a)], -a))
        a_, w_, o_ = dram[v]
        dbits = 8 * (a_ + w_ + o_)
        obits = 8 * (O_comp if v != "strict" else O_dense)
        rd = sr[(v, ax)] + (obits if v != "lenient" else 0)    # output read out of the cache for write-back
        wr = 8 * (a_ + w_) + obits                             # fills + compressed output write
        out[v] = dict(cycles=tot[(v, ax)], axis=ax, cycA=tot[(v, 1)], cycB=tot[(v, 0)], sram_r=rd, sram_w=wr,
                      dram=dbits, dram_parts=[8 * a_, 8 * w_, 8 * o_])
    out["paper"]["sram_r_access"] = nacc + math.ceil(out["paper"]["sram_w"] * 0 + 8 * O_comp / 128)
    out["paper"]["matches"] = nmatch
    t_os, r_os = group_max(run, 1)
    out["paper"]["cycles_outsync"] = t_os + r_os
    # current model reproduced (for checking against the cache)
    return out


def energy(cyc, rd, wr, dram, others=False):
    # core power = the repo's 16 x TPPE RTL power at 500 MHz, recovered from results/prune_chain.json
    # (core J / (cycles / 500 MHz)); SRAM = the same CACTI 256 KB, 16-B block entry the repo uses
    t = cyc / 500e6
    core = P_CORE * t * ((1 + 18.1 / 46.3) if others else 1)
    c = json.load(open(os.path.join(REPO, "hw", "sram_45nm_lstp_lop.json")))["16|262144"]
    sram = c["leak_mW"] * 1e-3 * t + (rd * c["read_nJ"] + wr * c["write_nJ"]) / 128 * 1e-9
    return dict(core=core, sram=sram, dram=dram * 12.45e-12)


def main(levels=("dense", "sp90", "sp95", "sp98")):
    cache = json.load(open(os.path.join(REPO, "results", "prune_chain_cache.json")))
    pcj = json.load(open(os.path.join(REPO, "results", "prune_chain.json")))["VGG16"]["levels"]
    global P_CORE
    e0 = pcj[0]
    P_CORE = e0["energy_J"]["loas"]["core"] / (e0["cycles_b1"]["loas"] / 500e6)
    print(f"core power (16 TPPE RTL, 500 MHz) = {P_CORE * 1e3:.2f} mW")
    res = {}
    for lv in levels:
        d = np.load(os.path.join(SD, f"VGG16_{lv}.npz"))
        meta = json.load(open(os.path.join(SD, f"VGG16_{lv}.json")))["layers"]
        acc = {k: dict(cycles=0, sram_r=0, sram_w=0, dram=0, parts=[0, 0, 0]) for k in
               ("current", "strict", "paper", "lenient")}
        rows = []
        for li, mt in enumerate(meta):
            if mt["analog"]:
                continue
            W, S = d[f"W{li}"].astype(np.int16), d[f"S{li}"]
            nxt = next((m for m in meta[li + 1:] if not m["analog"]), None)
            raw_next = nxt["raw_nz"] if (nxt is not None and nxt["raw_n"] == W.shape[0] * S.shape[1]) else None
            r = layer(W, S, raw_next)
            c = cache[repr(("VGG16", lv, li))]
            cur = dict(cycles=c["cycles"]["loas"], sram_r=c["counts"]["loas"]["bufs"]["glb"][0],
                       sram_w=c["counts"]["loas"]["bufs"]["glb"][1], dram=c["counts"]["loas"]["dram"])
            for k, v in [("current", cur)] + [(k, r[k]) for k in ("strict", "paper", "lenient")]:
                for f in ("cycles", "sram_r", "sram_w", "dram"):
                    acc[k][f] += v[f]
                if "dram_parts" in v:
                    acc[k]["parts"] = [a + b for a, b in zip(acc[k]["parts"], v["dram_parts"])]
            rows.append(dict(li=li, name=mt["name"], M=W.shape[0], K=W.shape[1], N=S.shape[1], current=cur,
                             **{k: r[k] for k in ("strict", "paper", "lenient")}))
        for k in acc:
            acc[k]["energy_uJ"] = {e: v * 1e6 for e, v in
                                   energy(acc[k]["cycles"], acc[k]["sram_r"], acc[k]["sram_w"], acc[k]["dram"]).items()}
        c = json.load(open(os.path.join(REPO, "hw", "sram_45nm_lstp_lop.json")))["16|262144"]
        na = sum(r_["paper"]["sram_r_access"] for r_ in rows)
        acc["paper"]["sram_read_accesses"] = na
        acc["paper"]["cycles_outsync"] = sum(r_["paper"]["cycles_outsync"] for r_ in rows)
        acc["paper"]["matches"] = sum(r_["paper"]["matches"] for r_ in rows)
        acc["paper"]["sram_uJ_access_granular"] = 1e6 * (c["leak_mW"] * 1e-3 * acc["paper"]["cycles"] / 500e6
                                                         + na * c["read_nJ"] * 1e-9
                                                         + acc["paper"]["sram_w"] / 128 * c["write_nJ"] * 1e-9)
        acc["paper"]["sram_uJ_tableIV_ratio"] = acc["paper"]["energy_uJ"]["core"] * 124.5 / 46.3
        acc["paper"]["energy_uJ_with_others"] = {e: v * 1e6 for e, v in energy(
            acc["paper"]["cycles"], acc["paper"]["sram_r"], acc["paper"]["sram_w"], acc["paper"]["dram"], True).items()}
        e_ref = next(e for e in pcj if e["level"] == lv)
        acc["current_json"] = dict(cycles=e_ref["cycles_b1"]["loas"],
                                   energy_uJ={k: v * 1e6 for k, v in e_ref["energy_J"]["loas"].items()},
                                   dram_MB=e_ref["dram_MB"]["loas"])
        res[lv] = dict(totals=acc, layers=rows)
        print(f"== VGG16 {lv}")
        for k in ("current", "strict", "paper", "lenient"):
            a = acc[k]
            print(f"  {k:8s} cyc {a['cycles']:>11,} sram_r {a['sram_r'] / 8e6:8.2f} MB sram_w {a['sram_w'] / 8e6:7.2f} MB"
                  f" dram {a['dram'] / 8e6:7.2f} MB  E(core,sram,dram) uJ "
                  + " ".join(f"{a['energy_uJ'][e]:8.1f}" for e in ("core", "sram", "dram")))
        print("  current_json", acc["current_json"])
        pa = acc["paper"]
        print(f"  paper, TPPEs synchronised per output instead of per chunk: {pa['cycles_outsync']:,} cycles")
        print(f"  paper: matches {pa['matches']:,}, read accesses {pa['sram_read_accesses']:,}, SRAM uJ bit-scaled "
              f"{pa['energy_uJ']['sram']:.1f} | access-granular {pa['sram_uJ_access_granular']:.1f} | at Table IV "
              f"cache/TPPE power ratio {pa['sram_uJ_tableIV_ratio']:.1f}; core+Others {pa['energy_uJ_with_others']['core']:.1f}")
    out = os.path.join(os.path.dirname(os.path.abspath(__file__)), "loas_paper_VGG16.json")
    json.dump(res, open(out, "w"), indent=1, default=float)
    print("->", out)


if __name__ == "__main__":
    main(tuple(sys.argv[1:]) or ("dense", "sp90", "sp95", "sp98"))
