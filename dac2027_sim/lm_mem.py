"""
lm_mem.py -- DRAM traffic and weight reuse added to the latency of every design for the layer-chained BERT runs
(lm_chain.py, LMC_REAL=1), with the common rule of memory_model.py (version 2 of the main results), which is the rule
of the official Prosperity simulator:
  DRAM interface BW bits/cycle (1024, Prosperity's mem_if_width; env DRAM_BITS_PER_CYCLE), loads double-buffered:
      GEMM cycles = compute + first-tile load + max(0, DRAM cycles - compute)
  Reuse: each design keeps half its on-chip staging buffer per operand and uses the cheaper of the two loop orders
      weights outer : W + I * ceil(W / half)        inputs outer : I + W * ceil(I / half)        (+ outputs O)
  so a weight is re-read only when the inputs that use it do not fit on chip.

Traffic per GEMM (W: M x K INT8 pruned, S: K x N spike trains, T = 8, outputs = output spikes M x N x T bits):
  TIDES      packed weight columns: per column R x (8-bit weight + 2-bit filter label) + F x 6-bit filter ids
             (LayerPlan, the offline filter packing); input spikes T bits each; staging buffer 64 KB
  LoAS       fiber A per position: per 128-input chunk a 16-byte bitmask + T bits per non-silent train; fiber B per
             filter: per chunk a 16-byte bitmask + its non-zero weights (pruned weights are not fetched); 256 KB SRAM
  SpikeX     dense 8-bit weights, input spikes T bits each; 54 KB
  SATO       dense 8-bit weights, input spikes T bits each; 54 KB (buffer not given in its paper, as PTB / SpikeX)
  SpikeFlow  dense 8-bit weights; only non-silent trains + 1 silence-label bit per input neuron; 18.5 KB
  Prosperity, PTB  already in their official cycle counts (dense weights, same 1024-bit interface)
Compute cycles: the cached results of lm_chain.py (all seven designs).

  python3 lm_mem.py   -> results/lm_chain_real_mem.json (+ printed table)
"""
import json, math, os, sys
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
os.environ.setdefault("LMC_REAL", "1")
import lm_chain as L
from memory_model import tiled_traffic, ours_weight_bytes, KB

R = os.path.join(HERE, "results")
BW = int(os.environ.get("DRAM_BITS_PER_CYCLE", 1024))
T = 8
BUF = {"ours": 64 * KB, "spikex": 54 * KB, "sato": 54 * KB, "spikeflow": int(18.5 * KB), "loas": 256 * KB}
DESIGNS = L.DESIGNS


def cycles_with_dram(compute, traffic_bytes, first_bytes):
    mem = traffic_bytes * 8 / BW
    return compute + first_bytes * 8 / BW + max(0.0, mem - compute), mem


def gemm(t):
    model, ws, blk, g, M, K = t
    W = L.pruned_weights(model, blk, g, M, K, ws)
    S = np.load(os.path.join(L.SD, f"{model.replace(' ', '_')}_{ws:.2f}.npz"))[f"{blk}_{g}"]
    N = S.shape[1]
    I_raw = K * N * T / 8
    O = M * N * T / 8
    Wd = M * K
    nsil = int((S != 0).sum())
    nch = math.ceil(K / 128)
    tr = {"ours": tiled_traffic(I_raw, ours_weight_bytes(W), O, BUF["ours"]),
          "spikex": tiled_traffic(I_raw, Wd, O, BUF["spikex"]),
          "sato": tiled_traffic(I_raw, Wd, O, BUF["sato"]),
          "spikeflow": tiled_traffic(nsil * T / 8 + K * N / 8, Wd, O, BUF["spikeflow"]),
          "loas": tiled_traffic(N * nch * 16 + nsil * T / 8, M * nch * 16 + int((W != 0).sum()), O, BUF["loas"])}
    r = {d: dict(bytes=b, first=f) for d, (b, f) in tr.items()}
    if BW != 1024:                      # Prosperity / PTB: re-run the official models at this DRAM interface
        import contextlib, io
        import baselines  # noqa: F401  (ours, before the official repo's module of that name)
        import prosperity_official as P
        from lm_sweep import fc_op
        pb = sys.modules["p_baselines"]
        with contextlib.redirect_stdout(io.StringIO()):
            lif = lambda: P.NW.LIFNeuron(f"lif_{g}", M * N, 1, T)
            r["prosperity_total"] = int(P.run_model_ops([fc_op(P, g, S, M), lif()], f"m{blk}{g}{ws}"))
            Sp = np.pad(S, ((0, 0), (0, -N % 8))) if N % 8 else S
            r["ptb_total"] = int(pb.run_simulation_PTB([fc_op(P, g, Sp, M), lif()]).total_cycles)
    return t, r


def main():
    cache = json.load(open(L.CACHE))
    d, h, Lb, _, _ = L.MODELS["BERT"]
    wss = sorted({__import__("ast").literal_eval(k)[1] for k in cache if k.startswith("('BERT'")})
    todo = [("BERT", ws, b, g, M, K) for ws in wss for b in range(Lb) for g, M, K in L.gemms(d, h)]
    with Pool(min(8, os.cpu_count())) as pool:
        traffic = dict(pool.map(gemm, todo))
    out = {}
    for ws in wss:
        tot = {k: 0.0 for k in DESIGNS}
        comp = {k: 0.0 for k in DESIGNS}
        dram = {k: 0.0 for k in DESIGNS}
        for t in [x for x in todo if x[1] == ws]:
            c = cache[repr(t)]
            for k in DESIGNS:
                comp[k] += c[k]
                if k in ("prosperity", "ptb"):                      # official: DRAM already inside
                    tot[k] += traffic[t][f"{k}_total"] if BW != 1024 else c[k]
                else:
                    cyc, _ = cycles_with_dram(c[k], traffic[t][k]["bytes"], traffic[t][k]["first"])
                    tot[k] += cyc
                    dram[k] += traffic[t][k]["bytes"]
        out[f"{ws:.2f}"] = dict(cycles=tot, compute_cycles=comp, dram_MB={k: v / 1e6 for k, v in dram.items()})
    res = dict(BERT=dict(bw_bits_per_cycle=BW, T=T, points=out))
    json.dump(res, open(os.path.join(R, f"lm_chain_real_mem{'' if BW == 1024 else f'_bw{BW}'}.json"), "w"), indent=1)
    print(f"DRAM {BW} bits/cycle ({BW * 500e6 / 8e9:.0f} GB/s at 500 MHz); ms per sentence (compute -> with memory)")
    for ws, v in out.items():
        c, p = v["cycles"], v["compute_cycles"]
        print(f"w{float(ws)*100:3.0f}% " + " ".join(f"{k} {p[k]/5e5:.2f}->{c[k]/5e5:.2f}" for k in DESIGNS)
              + f" | TIDES vs Prosperity {c['prosperity']/c['ours']:.2f}x")


if __name__ == "__main__":
    main()
