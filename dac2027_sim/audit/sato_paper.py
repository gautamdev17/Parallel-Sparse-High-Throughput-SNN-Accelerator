"""
sato_paper.py -- paper-faithful per-layer cycle model of SATO (Liu et al., DAC'22, sato.pdf), independent of the
Prosperity-repo model (run_sato_conv_fc + run_sato_lif), with that model re-implemented here for a side-by-side.

GEMM view of a layer: W (M x K, output neurons x pre-synaptic inputs), S (K x N spike trains, bit t = timestep t).
A "row" of the paper's sparse spike matrix (Sec 3.3 Step 1) is (timestep t, output position n): the K-long spike
vector seen by every output neuron (m, n). nnz[t, n] = popcount of that row.

Hardware facts used (sato.txt line numbers):
  * 128 PEs, 8-bit, one 8-b Add per PE (Table 2 l.655-657; Table 3 l.803-815) -> one weight add per PE per cycle.
  * PE parallelism is over time steps, neuron loop outer (Fig 2b pseudocode l.297-312; l.383-386
    "the PE parallelism is converted from M to T"), but neurons are also parallel (l.374-377).
  * A row is the atomic workload unit: "a PE may process one or more rows" (l.485-486); balance target
    dnnz = #nnz/#PE (l.491-497); "performance is bounded by the slowest PE" (l.357-359).
  * ONE binary adder-search tree (Fig 2b table l.313-317 "#Modules 1"; Table 2 l.660-663: one adder/reg/comparator)
    takes the T integrations of a neuron and binary-searches the first-spike time: log2(T) search cycles + the leaf
    check "Cycle 0" (Fig 6b l.558-621, l.636-643: T = 8 -> cycles 0..3). Valid for SNN-T: "the spike train only has a
    single spike" (l.396-398).
  * No weight-sparsity support anywhere in the paper (only spike sparsity, l.547-549) -> zero weights cost an add.

Variants (the paper leaves these open):
  integration  L (lenient): any (t, n, m) task on any PE, perfect balance: max(ceil(M*sum(nnz)/128), max nnz)
               S (loop nest): literal Fig 2b: each neuron's T time-step rows on T PEs, 128//T neurons per wave
                            (the 16 output channels of one position p, which share the input rows = PE-group
                            sharing l.507-509), barrier per wave (BAST needs all T results):
                            sum_p ceil(M / (128//T)) * max_t nnz[t, p]
  BAST         log2T+1 per neuron (paper, first spike only) | T per neuron (exact multi-spike soft-reset IF:
               sequential compare-subtract scan, one comparator) | (k+1)(log2T+1) (re-search after every output
               spike, k = output spikes of that neuron, simulated with the trace's calibrated thresholds)
  overlap      lenient: BAST pipelined behind integration -> max(int, bast); strict: serial -> int + bast
  paper_lenient = int_L  max  bast(log2T+1)
  paper_strict  = int_S   +   bast(T)
"""
import heapq, json, math, os, sys
import numpy as np

NPE = 128
REPO = "/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/dac2027_sim"
SD = os.path.join(REPO, "results", "prune_chain")
CHUNK = 40_000_000                    # prune_sweep.CHUNK


def row_nnz(S, T):
    """nnz[t, n] = spikes of input row (t, n)."""
    return np.stack([((S >> t) & 1).sum(0, dtype=np.int64) for t in range(T)])


def official_chunked(nnz, M, K, T):
    """re-implementation of the repo's call: per column chunk, run_sato_conv_fc (rows t-major, each row to the
    first least-loaded of 128 PEs, cycles = max load x M) + run_sato_lif (M*n x (log2 T + 1))."""
    N = nnz.shape[1]
    step = max(32, (CHUNK // (T * K)) // 32 * 32)
    tot = 0
    for a in range(0, N, step):
        b = min(N, a + step)
        rows = nnz[:, a:b].reshape(-1)                     # (T, n) -> t-major, as sparse_map.reshape(-1, K)
        h = [(0, i) for i in range(NPE)]                   # (load, PE index): heap pop = torch.argmin (first min)
        mx = 0
        for r in rows:
            ld, i = heapq.heappop(h)
            ld += int(r)
            mx = max(mx, ld)
            heapq.heappush(h, (ld, i))
        tot += mx * M + int(M * (b - a) * (math.log2(T) + 1))
    return tot


def if_out_spikes(W, S, T, theta):
    """output spikes per neuron (M x N) of the QCFS IF neuron (mem0 = theta/2, soft reset) on the integer sums."""
    mem = np.full((W.shape[0], S.shape[1]), theta / 2)
    k = np.zeros(mem.shape, np.int64)
    Wf = W.astype(np.float64)
    for t in range(T):
        mem += Wf @ ((S >> t) & 1).astype(np.float64)
        f = mem >= theta
        mem -= f * theta
        k += f
    return k


def sato_paper(W, S, T, theta=None):
    """paper-faithful cycles of one layer -> dict of components and the lenient / strict totals."""
    M, K = W.shape
    N = S.shape[1]
    nnz = row_nnz(S, T)
    lg = int(math.log2(T)) + 1
    G = max(1, NPE // T)
    int_L = max(-(-M * int(nnz.sum()) // NPE), int(nnz.max()))
    # loop nest (Fig. 2b; l.855-862 "each PE is responsible for ... multiple time steps"): a neuron's T rows on its PEs.
    # T <= 128: 128 // T neurons per wave, a wave lasts its slowest row; T > 128: one neuron, its rows spread over all
    # 128 PEs (balanced by the dispatcher) -> max(ceil(sum / 128), max row). Checked against Fig. 8 (128 -> 1024 PEs:
    # x5.1 here vs x6.4 in the paper).
    if T <= NPE:
        int_S = int(sum(-(-M // G) * int(nnz[:, p].max()) for p in range(N)))
    else:
        int_S = int(sum(M * max(-(-int(nnz[:, p].sum()) // NPE), int(nnz[:, p].max())) for p in range(N)))
    r = dict(int_L=int_L, int_S=int_S, bast_log=M * N * lg, bast_T=M * N * T)
    if theta is not None:
        k = if_out_spikes(W, S, T, theta)
        r["bast_respike"] = int(((k + 1) * lg).sum())
        r["out_spikes"] = int(k.sum())
        r["out_active"] = int((k > 0).sum())
    r["paper_lenient"] = max(int_L, r["bast_log"])
    r["paper_strict"] = int_S + r["bast_T"]
    r["official"] = official_chunked(nnz, M, K, T)
    return r


def run(net="VGG16", levels=("dense", "sp90", "sp95", "sp98")):
    cache = json.load(open(os.path.join(REPO, "results", "prune_chain_cache.json")))
    out = {}
    for lvl in levels:
        d = np.load(os.path.join(SD, f"{net}_{lvl}.npz"))
        meta = json.load(open(os.path.join(SD, f"{net}_{lvl}.json")))
        T = meta["T"]
        thr = {c: th for _, c, th in meta["thresholds"]}            # consumer layer -> threshold of its input IF
        L = meta["layers"]
        rows = []
        for li, e in enumerate(L):
            if e["analog"]:
                continue
            W, S = d[f"W{li}"].astype(np.int16), d[f"S{li}"]
            nxt = L[li + 1]["name"] if li + 1 < len(L) else None
            theta = thr[nxt] * e["pool"] / thr[e["name"]] if nxt in thr else None   # integer-unit threshold
            r = sato_paper(W, S, T, theta)
            r["cached"] = cache[str((net, lvl, li))]["cycles"]["sato"]
            r["name"] = e["name"]
            rows.append(r)
        out[lvl] = rows
    return out


if __name__ == "__main__":
    res = run()
    json.dump(res, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "sato_paper_VGG16.json"), "w"),
              indent=1)
    cols = ["cached", "official", "int_L", "int_S", "bast_log", "bast_T", "bast_respike", "paper_lenient",
            "paper_strict"]
    for lvl, rows in res.items():
        print(f"\n== VGG16 {lvl}")
        print(f"{'layer':14s}" + "".join(f"{c:>13s}" for c in cols) + f"{'L/cache':>9s}{'S/cache':>9s}")
        for r in rows:
            print(f"{r['name']:14s}" + "".join(f"{r.get(c, 0) or 0:13d}" for c in cols)
                  + f"{r['paper_lenient'] / r['cached']:9.3f}{r['paper_strict'] / r['cached']:9.3f}")
        tot = {c: sum(r.get(c, 0) or 0 for r in rows) for c in cols}
        print(f"{'TOTAL':14s}" + "".join(f"{tot[c]:13d}" for c in cols)
              + f"{tot['paper_lenient'] / tot['cached']:9.3f}{tot['paper_strict'] / tot['cached']:9.3f}")
        a = sum(r.get("out_active", 0) for r in rows)
        print(f"   output spikes {sum(r.get('out_spikes', 0) for r in rows)}, neurons that fire {a}")
