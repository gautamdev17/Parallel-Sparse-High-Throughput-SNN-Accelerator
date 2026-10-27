"""
prosperity_own.py -- our own cycle model of Prosperity (HPCA'25, prosperity.pdf), written from the paper (numpy only,
no code of the official simulator), the way ours.py models TIDES. Checked against the paper's published numbers on the
authors' own spike traces (`python prosperity_own.py validate`).

Hardware and rules (prosperity.txt line numbers):
  * spike GEMM tiled m = 256 rows (pixel-major: row = position x T + t) x k = 16 columns x n = 128 output channels
    (Table III, l.1311-1318: 128 8-b adders, 256 x 16 TCAM tile); rows of a tile issue one at a time.
  * ProSparsity (Sec. III/V): each row takes the largest proper subset row of the tile as its prefix (exact-match rows
    of higher index take an equal row), and computes only the remaining pattern bits.
  * Processor: a row costs popcount(pattern) cycles; an exact-match row "still takes one cycle to process"
    (l.1543-1545); an all-zero row is not issued.
  * Detector: 8 popcount units -> m / 8 cycles per tile (Table III l.1314); one TCAM search per query row, one cycle
    each (l.793); a row with fewer than two spikes has no non-empty proper subset and is not searched.
  * inter-phase pipeline: the ProSparsity phase of a tile overlaps the computation of the previous tile (l.1167-1176)
    -> a tile costs max(compute, detection).
  * spiking neuron array: 32 LIF cells, 2 cycles per neuron and timestep, pipelined with the processor: only the last
    tile's neurons add latency.
  * memory: 8 KB spike, 32 KB weight, 96 KB output buffers, 64 GB/s DDR4 = 1024 bits / cycle at 500 MHz (Table III);
    the spike map is fetched raw for convolutions (on-chip im2col); a buffer that cannot hold its whole operand
    re-fetches it per tile pass; latency = compute + max(0, DRAM bits / bandwidth - compute).
  * max pooling is free (applied when spikes are written back).

  python prosperity_own.py validate   -> the authors' 4 CNN traces vs the paper's latencies (time_reference.xlsx)
"""
import math, os, sys
import numpy as np

MT, KT, NT = 256, 16, 128
POPC, LIF_CELLS = 8, 32
BUF = dict(spike=8 * 1024 * 8, wgt=32 * 1024 * 8)          # bits
MEMW = 1024


def prosparsity(tile):
    """tile: (m, 16) bool -> pattern (m, 16) bool after taking each row's largest proper-subset prefix."""
    a = tile
    m = a.shape[0]
    nnz = a.sum(1)
    if not (nnz >= 2).any():
        return a
    sub = ~(a[None, :, :] & ~a[:, None, :]).any(-1)          # sub[i, j]: row j is a subset of row i
    eq = (a[None, :, :] == a[:, None, :]).all(-1)
    later = np.arange(m)[None, :] >= np.arange(m)[:, None]
    cand = sub & ~(eq & later)                               # equal rows: only an earlier one is a prefix
    size = np.where(cand, nnz[None, :], -1)
    best = size.argmax(1)
    ok = (nnz >= 2) & (size[np.arange(m), best] >= 1)
    pat = a.copy()
    pat[ok] = a[ok] ^ a[best[ok]]
    return pat


def layer(rows, M, k=1, T=8, memw=MEMW):
    """rows: (T*N, K) bool spike matrix, pixel-major (row = position * T + t); M output channels; k: conv kernel
    size (spikes fetched raw, im2col on chip). -> dict(cycles, compute, detect, lif, stall, dram_bits)."""
    R, K = rows.shape
    Kp = -(-K // KT) * KT
    if Kp != K:
        rows = np.pad(rows, ((0, 0), (0, Kp - K)))
    nN = math.ceil(M / NT)
    comp = det = tile_cost = 0
    for r0 in range(0, R, MT):
        for k0 in range(0, Kp, KT):
            t = rows[r0:r0 + MT, k0:k0 + KT]
            if not t.any():
                continue
            pat = prosparsity(t)
            pc, nz = pat.sum(1), t.sum(1)
            c = int(pc.sum() + ((pc == 0) & (nz > 0)).sum())
            d = int((nz > 1).sum()) + t.shape[0] // POPC
            comp += c
            det += d
            tile_cost += max(c, d)
    comp, det, tile_cost = comp * nN, det * nN, tile_cost * nN
    mt = math.ceil(R / MT)
    neurons = M * R // T
    lif = min(math.ceil(min(MT * NT // T, neurons) / LIF_CELLS), math.ceil(neurons / LIF_CELLS)) * T * 2
    w_bits = M * K * 8
    s_bits = R * K / (k * k)
    dram = (w_bits * (1 if w_bits <= BUF["wgt"] else mt) + s_bits * (1 if s_bits <= BUF["spike"] else nN)
            + neurons * T)
    stall = max(0.0, dram / memw - tile_cost)
    return dict(cycles=int(tile_cost + stall + lif), compute=comp, detect=det, tile_cost=tile_cost, lif=lif,
                stall=int(stall), dram_bits=dram)


def from_trains(S, M, k=1, T=8, memw=MEMW):
    """our traces: S (K, N) uint8 trains (bit t = timestep t) -> layer()."""
    K, N = S.shape
    bits = ((S[None] >> np.arange(T)[:, None, None]) & 1).astype(bool)      # T, K, N
    return layer(bits.transpose(2, 0, 1).reshape(N * T, K), M, k, T, memw)


def validate():
    """the authors' traces (third_party/prosperity_data, T = 32) vs the paper's latencies (time_reference.xlsx)."""
    HERE = os.path.dirname(os.path.abspath(__file__))
    sys.path.insert(0, HERE)
    import prosperity_official as P
    REF = P.REF
    from multiprocessing import Pool
    names = list(REF)
    with Pool(4) as pool:
        res = pool.map(_validate_one, names)
    print(f"{'benchmark':18s} {'paper (ms)':>10s} {'ours (ms)':>10s} {'error':>7s} | speedup over PTB: paper, ours")
    for name, ms in zip(names, res):
        ref = REF[name]
        print(f"{name:18s} {ref['Prosperity'] * 1e3:10.3f} {ms:10.3f} {100 * (ms / (ref['Prosperity'] * 1e3) - 1):+6.1f}% | "
              f"{ref['PTB'] / ref['Prosperity']:6.2f}, {ref['PTB'] * 1e3 / ms:6.2f}")


def _validate_one(name):
    HERE = os.path.dirname(os.path.abspath(__file__))
    sys.path.insert(0, HERE)
    import prosperity_official as P
    ops = P.NW.create_network(name.split("_")[0], os.path.join(HERE, "third_party", "prosperity_data", name + ".pkl"))
    tot = 0
    for op in ops:
        kind = type(op).__name__
        if kind not in ("Conv2D", "FC"):
            continue                                         # LIF counted per layer; max pooling is free
        k = op.kernel_size if kind == "Conv2D" else 1
        fc = P.NW.conv2d_2_fc(op) if kind == "Conv2D" else op
        T, N, K = fc.time_steps, fc.sequence_length * fc.batch_size, fc.input_dim
        sm = fc.activation_tensor.sparse_map.reshape(T, N, K).numpy() != 0
        rows = sm.transpose(1, 0, 2).reshape(N * T, K)
        tot += layer(rows, fc.output_dim, k, T)["cycles"]
    return tot / 500e6 * 1e3


if __name__ == "__main__":
    validate() if sys.argv[1:] == ["validate"] else print(__doc__)
