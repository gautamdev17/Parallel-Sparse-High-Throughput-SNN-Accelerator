"""
loas_model.py -- our own cycle model of LoAS (Yin et al., LoAS.pdf), built from the paper only
(no zip formula, no LoAS RTL from the repo folders).

Hardware (Sec. IV, Sec. V Table III): 16 TPPEs, 128-bit bitmasks (chunk of 128 along K), one inner-join unit per
TPPE with a fast prefix-sum (one match per cycle) and a laggy prefix-sum (16 adders: all offsets of the 128-bit
bm-A after 128/16 = 8 cycles), two depth-8 FIFOs, T correction accumulators, P-LIF.

Mapping (Sec. IV-B): each TPPE produces the full sum of one output neuron. The bitmask and non-zeros of a weight
fiber (fiber-B, one output channel, one 128-chunk of K) are read once and BROADCAST to all TPPEs; each TPPE holds
the bitmask of a different spike row (fiber-A = one output pixel). So 16 TPPEs = 16 pixels of one output channel,
processed chunk by chunk in lock step with the shared fiber-B.

Per TPPE and chunk (Sec. IV-C, Fig. 10), with m = #matches (weight != 0 AND neuron non-silent):
  load      : 1 cycle for the bitmasks + ceil(nnz(fiber-B chunk) / BUS) cycles for the non-zero weights (BUS bytes/cycle)
  join      : 1 cycle (AND + priority encoder)
  fast      : one matched weight per cycle into the pseudo-accumulator
  laggy     : ready after 8 cycles; then one correction per cycle from FIFO-mp/FIFO-B (fiber-A fetched from the
              global cache, 1 cycle latency). The FIFO fills exactly while the laggy circuit runs (depth 8), so the
              fast circuit never stalls; the chunk ends with the last correction: 8 + m + 1 cycles (0 if m = 0)
  chunk cycles = load + join + (8 + m + 1 if m > 0 else 0)
A round (one chunk for 16 TPPEs) lasts the slowest TPPE's chunk; after the last chunk, 1 cycle of P-LIF.

  python3 loas_model.py   -> results/loas_own.json and a comparison with the zip formula
"""
import json, math, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import workload as wl

TPPES, CHUNK, LAGGY, BUS = 16, 128, 8, 16


def _chunk_cycles(W, S, chunk, laggy, bus):
    """per chunk: (M, N) cycles of one TPPE computing output (m, n) on that chunk."""
    wnz, snz = (W != 0), (S != 0)                      # snz: non-silent neuron (fires at least once)
    for c0 in range(0, W.shape[1], chunk):
        m = np.rint(wnz[:, c0:c0 + chunk].astype(np.float32) @ snz[c0:c0 + chunk, :].astype(np.float32)
                    ).astype(np.int64)                 # matches per (output channel, pixel)
        load = 1 + -(-wnz[:, c0:c0 + chunk].sum(1) // bus)   # bitmasks + this channel's weights over the bus
        yield load[:, None] + 1 + np.where(m > 0, laggy + m + 1, 0)


def _rounds(cyc, axis, tppes):
    """lock-step rounds: groups of `tppes` along `axis` (1 = pixels share a weight fiber, 0 = channels share a
    spike fiber); a round lasts its slowest TPPE."""
    c = cyc if axis == 1 else cyc.T
    pad = (-c.shape[1]) % tppes
    if pad:
        c = np.concatenate([c, np.zeros((c.shape[0], pad), dtype=c.dtype)], 1)
    g = c.reshape(c.shape[0], -1, tppes).max(2)
    return int(g.sum()), g.size


def loas_layer_cycles_own(W, S, tppes=TPPES, chunk=CHUNK, laggy=LAGGY, bus=BUS):
    """best of the two mappings per layer (the scheduler's choice, favouring LoAS):
       A) 16 pixels of one output channel share the broadcast weight fiber (Sec. IV-B);
       B) 16 output channels of one pixel share the broadcast spike fiber, each TPPE getting its own weight fiber
          through the 16x16 crossbar (Table III) -- used when a layer has few pixels (late conv, FC)."""
    best = None
    for axis in (1, 0):
        tot = rounds = 0
        for cyc in _chunk_cycles(W, S, chunk, laggy, bus):
            t, r = _rounds(cyc, axis, tppes)
            tot += t
            rounds = r
        tot += rounds                                  # + 1 P-LIF cycle per round of 16 outputs
        best = tot if best is None else min(best, tot)
    return best


def main():
    from baselines import loas_layer_cycles, LOAS_P_ZIP
    WORK = {"sparse90": (0.10, 0.10, 0.3), "zipstats": (1.00, 0.261, 0.3)}
    out, lines = {}, ["| Workload | Network | Batch | LoAS own model (cycles) | zip formula (cycles) | own / zip |",
                      "|---|---|---|---:|---:|---:|"]
    for w, (wd, ns, q) in WORK.items():
        for net in ("VGG16", "ResNet18"):
            for b in (1, 16):
                own = zipc = 0
                for li, layer in enumerate(wl.NETWORKS[net]()):
                    M, K, N = wl.gemm_shape(layer, b)
                    seed = zlib.crc32(f"{net}|{li}|{b}|{wd}|{ns}|{q}".encode())
                    W, S = wl.layer_tensors(layer, b, wd, ns, q, seed)
                    own += loas_layer_cycles_own(W, S)
                    zipc += loas_layer_cycles(M, K, N, LOAS_P_ZIP)
                out[f"{w}|{net}|{b}"] = own
                lines.append(f"| {w} | {net} | {b} | {own:,} | {zipc:,.0f} | {own / zipc:.2f} |")
    json.dump(out, open(os.path.join(HERE, "results", "loas_own.json"), "w"), indent=1)
    print("\n".join(lines))


if __name__ == "__main__":
    main()
