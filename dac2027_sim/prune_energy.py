"""
prune_energy.py -- full-system energy per inference (core + on-chip SRAM + DRAM, 45 nm, 500 MHz, batch 1) of every
design on the six networks of the pruning sweep (prune_sweep.py), with the memory models of the main results applied
layer by layer to the sweep's tensors:

  core   gate-level core power of each design (hw/same_node_table.core) x latency
  SRAM   each design's on-chip buffers (hw/same_node_table.SRAM, CACTI 7 45 nm LSTP/LOP): leakage x latency + read /
         write energy of the bits each buffer moves. The access counts are those of mem_levels.py / same_node_table.
         sram_access_bits: ours = staging (weights + the packer's raw spike reads; DRAM fills), group buffer (group
         reads per pass; packer writes), output buffer (read-modify-writes + LIF reads, 24-bit x T entries); SpikeX,
         SpikeFlow, LoAS (mem_levels.py rules), SATO (every (t, pixel) row read once + M weights per spike), PTB (StSAP
         slots and pairs of the official model) = one global buffer: reads + DRAM fills; Prosperity = its official
         simulator's own g_act / g_wgt / g_psum counters.
  DRAM   12.45 pJ/bit x off-chip traffic: mem_traffic.py rules (tiled two-loop-order rule with each design's
         format and buffer; LoAS fibres; PTB's official model rule); Prosperity = its simulator's DRAM counters.

Prosperity is re-run here per layer with the operator names of the main results (prosperity_official.our_ops:
"conv<i>_kernel<k>_fc" / "fc<i>"): the official simulator reads the kernel size (on-chip im2col: activation DRAM
traffic / k^2) and the LIF-overlap rule from the name. Its corrected batch-1 cycles replace those of prune_sweep.py
(which named the operators after our layers) in results/prune_sweep.json. The other designs' cycles are unchanged.

  <python with torch, pandas, networkx> prune_energy.py validate   -> VGG16 sparse90 vs results/system_breakdown_b1.json
  <python ...> prune_energy.py [network ...]                       -> results/prune_energy.json
"""
import contextlib, io, json, math, os, sys, time, zlib
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, "hw"))
R = os.path.join(HERE, "results")
OUT = os.path.join(R, "prune_energy.json")
CACHE = os.path.join(R, "prune_energy_cache.json")
T, CLK, KB = 8, 500e6, 1024
DRAM_PJ_BIT = 12.45
CHUNK = 40_000_000
DESIGNS = ("ptb", "spikex", "loas", "sato", "spikeflow", "prosperity", "ours")
SN_KEY = {"loas": "loas_zip"}


# ------------------------------------------------------------------------------------------------ tensors
def sweep_tensors(net, lv, li):
    """the prune_sweep.py draws of one layer at batch 1: W, the im2col spikes S and the input feature map X."""
    import workload as wl, prune_sweep as PS
    lab, dens, fr = PS.LEVELS[net][lv]
    layer = wl.NETWORKS[net]()[li]
    rng = np.random.default_rng(zlib.crc32(f"prune|{net}|{lab}|{li}|1|{dens}|{fr}|T{T}".encode()))
    M, K, N = wl.gemm_shape(layer, 1)
    W = wl.rand_weights(rng, M, K, dens / 100)
    X = wl.rand_spikes_rate(rng, (1, layer[1], layer[5], layer[5]), fr / 100, T)
    return layer, W, X


def main_tensors(net, li, wd=0.10, ns=0.10, q=0.3):
    """the main results' sparse90 draws (memory_model.layer_inputs = workload.layer_tensors), batch 1."""
    import memory_model as MM
    return MM.layer_inputs(net, li, 1, wd, ns, q)


def im2col(layer, X):
    import workload as wl
    name, ci, co, k, s, h = layer
    return wl.im2col(X, k, s) if k > 1 or s > 1 or h > 1 else X.reshape(1, ci).T.copy()


# ------------------------------------------------------------------------------------------------ official models
def prosperity_layer(li, layer, S, M):
    """Prosperity per layer with the main results' operator names, in column chunks: cycles + its buffer and DRAM
    counters (bits)."""
    import prosperity_official as P
    k = layer[3]
    name = f"conv{li}_kernel{k}_fc" if k > 1 else f"fc{li}"
    K, N = S.shape
    step = max(32, (CHUNK // (T * K)) // 32 * 32)
    cyc, rd, wr = 0, {}, {}
    for a in range(0, N, step):
        Sc = S[:, a:a + step]
        n = Sc.shape[1]
        bits = ((Sc[None] >> np.arange(T)[:, None, None]) & 1).astype(bool)
        import torch
        op = P.NW.FC(name, K, M, n, 1, T)
        op.activation_tensor.sparse_map = torch.from_numpy(bits.transpose(0, 2, 1).copy()).reshape(1, T, n, K).float()
        P.S.clear_global_stats()
        sim = P.S.Simulator(accelerator=P.prosperity_accel(), network=[op, P.NW.LIFNeuron(f"lif_{li}", M * n, 1, T)],
                            benchmark_name=f"pe_{li}", use_cuda=False)
        with contextlib.redirect_stdout(io.StringIO()):
            st = sim.sim()
        cyc += int(st.total_cycles)
        for d_, src in ((rd, st.reads), (wr, st.writes)):
            for key, v in src.items():
                d_[key] = d_.get(key, 0.0) + float(v)
    return cyc, rd, wr


def ptb_slots(S, M, name):
    """PTB's official model on the layer (one image, as prune_sweep.py), recording StSAP slots / pairs
    (mem_levels.py ptb rule): -> (weight bits, spike bits) read from its buffer."""
    import prosperity_official as P
    import prune_sweep as PS
    pb = sys.modules["p_baselines"]
    rec = []
    orig = pb.StSAP

    def st_wrap(act):
        n = orig(act)
        a = act != 0
        rec.append((n, int(a.any(-1).sum())))
        return n

    pb.StSAP = st_wrap
    try:
        K, N = S.shape
        with contextlib.redirect_stdout(io.StringIO()):
            for a, b in PS.chunks(N, K, 4):
                Sc = S[:, a:b]
                if Sc.shape[1] > 1 and Sc.shape[1] % 4:
                    Sc = np.pad(Sc, ((0, 0), (0, -Sc.shape[1] % 4)))
                pb.run_simulation_PTB([PS.fc_op(P, name, Sc, M), P.NW.LIFNeuron("lif", M * (b - a), 1, T)])
    finally:
        pb.StSAP = orig
    wbits = abits = 0
    for n, nz in rec:
        pr = nz - n
        wbits += (n + pr) * M * 8
        abits += math.ceil(M / 16) * (n * 8 * 4 + pr * 8)
    return wbits, abits


# ------------------------------------------------------------------------------------------------ one layer
def layer_counts(li, layer, W, X):
    """-> {design: dict(dram=bits, bufs={buffer: (read bits, write bits)}, cycles=None|int)} for one layer."""
    import workload as wl
    import mem_levels as ML
    import memory_model as MM
    from mem_traffic import split_tiled
    S = im2col(layer, X)
    name, ci, co, k, s, h = layer
    M, K = W.shape
    N = S.shape[1]
    I_raw = ci * h * h * T / 8
    O = co * (h // s) ** 2 * T / 8
    Wd = M * K
    I_sf = int((X != 0).sum()) * T / 8 + ci * h * h / 8
    Mpos = (h // s) ** 2
    nch = math.ceil(K / 128)
    fA = nch * (16 + 128 * float((X != 0).mean()) * (T / 8))
    fB = nch * (16 + 128 * float((W != 0).mean()))
    dram_B = {"ours": split_tiled(I_raw, MM.ours_weight_bytes(W), O, 64 * KB),
              "spikex": split_tiled(I_raw, Wd, O, 54 * KB),
              "spikeflow": split_tiled(I_sf, Wd, O, int(18.5 * KB)),
              "sato": split_tiled(I_raw, Wd, O, 54 * KB),
              "loas": split_tiled(Mpos * fA, co * fB, Mpos * co * T / 8, 256 * KB),
              "ptb": (I_raw, Wd, O / 8)}
    out = {d: dict(dram=8 * sum(v)) for d, v in dram_B.items()}
    fills = {d: out[d]["dram"] for d in out}
    oc_w, oc_a, _, _, rmw, lifr, gw, rawr, _ = ML.ours_layer(W, S)
    out["ours"]["bufs"] = {"staging": (oc_w + rawr, fills["ours"]), "group": (oc_a - rawr, gw),
                           "obuf": ((rmw + lifr) * T * 24, rmw * T * 24)}
    for d, f in (("spikex", ML.spikex_layer), ("spikeflow", ML.spikeflow_layer), ("loas", ML.loas_layer)):
        w, a = f(W, S)[:2]
        out[d]["bufs"] = {"glb": (w + a, fills[d])}
    spikes = int(wl.popcount8(S).sum())
    out["sato"]["bufs"] = {"glb": (T * N * K + spikes * M * 8, fills["sato"])}
    w, a = ptb_slots(S, M, f"fc{li}")
    out["ptb"]["bufs"] = {"glb": (w + a, fills["ptb"])}
    cyc, rd, wr = prosperity_layer(li, layer, S, M)
    out["prosperity"] = dict(dram=rd.get("dram", 0.0) + wr.get("dram", 0.0), cycles=cyc,
                             bufs={b: (rd.get(b, 0.0), wr.get(b, 0.0)) for b in ("g_act", "g_wgt", "g_psum")})
    return out


def energy(counts, cycles):
    """counts: {design: summed layer counts}; cycles: {design: batch-1 cycles} -> {design: {core, sram, dram} J}."""
    import same_node_table as SN
    e = {}
    for d in DESIGNS:
        t = cycles[d] / CLK
        sd = SN_KEY.get(d, d)
        core = SN.core(sd)[1] * t
        sram = 0.0
        for bname, blk, size in SN.SRAM[sd][1]:
            c = SN.CACTI[f"{blk}|{size}"]
            rb, wb = counts[d]["bufs"][bname]
            sram += c["leak_mW"] * 1e-3 * t + (rb * c["read_nJ"] + wb * c["write_nJ"]) / (blk * 8) * 1e-9
        e[d] = dict(core=core, sram=sram, dram=counts[d]["dram"] * DRAM_PJ_BIT * 1e-12)
    return e


def add(acc, c):
    for d, v in c.items():
        a = acc.setdefault(d, dict(dram=0.0, bufs={}, cycles=0))
        a["dram"] += v["dram"]
        a["cycles"] += v.get("cycles") or 0
        for b, (r, w) in v["bufs"].items():
            r0, w0 = a["bufs"].get(b, (0.0, 0.0))
            a["bufs"][b] = (r0 + r, w0 + w)


# ------------------------------------------------------------------------------------------------ runs
def _main_layer(t):
    net, li = t
    layer, W, X = main_tensors(net, li)
    return t, layer_counts(li, layer, W, X)


def validate():
    """VGG16 sparse90, batch 1: these layer-wise rules vs the main results (results/system_breakdown_b1.json)."""
    import workload as wl
    net = "VGG16"
    ref = json.load(open(os.path.join(R, "system_breakdown_b1.json")))
    s = json.load(open(os.path.join(R, "main_summary.json")))["sparse90"]
    own = json.load(open(os.path.join(R, "loas_own.json")))
    cyc = {d: (own[f"sparse90|{net}|1"] if d == "loas" else s[f"{net}|{SN_KEY.get(d, d)}"]["cycles_b1"])
           for d in DESIGNS}
    acc = {}
    with Pool(8) as p:
        for _, c in p.imap_unordered(_main_layer, [(net, li) for li in range(len(wl.NETWORKS[net]()))]):
            add(acc, c)
    e = energy(acc, cyc)
    print(f"{net} sparse90 b1: per design, (core, SRAM, DRAM) uJ here | main results")
    for d in DESIGNS:
        r = ref[f"{net}|{SN_KEY.get(d, d)}"]["energy_J"]
        print(f"  {d:10s} " + " ".join(f"{e[d][k] * 1e6:9.1f}" for k in ("core", "sram", "dram")) + "  | "
              + " ".join(f"{r[k] * 1e6:9.1f}" for k in ("core", "sram", "dram")))
    print(f"  Prosperity cycles: layer-wise {acc['prosperity']['cycles']:,} vs whole-network {cyc['prosperity']:,}")


def _sweep_layer(t):
    net, lv, li = t
    layer, W, X = sweep_tensors(net, lv, li)
    return t, layer_counts(li, layer, W, X)


def main():
    import workload as wl, prune_sweep as PS
    nets = sys.argv[1:] or list(PS.LEVELS)
    todo = [(n, lv, li) for n in nets for lv in range(len(PS.LEVELS[n])) for li in range(len(wl.NETWORKS[n]()))]
    size = lambda t: np.prod(wl.gemm_shape(wl.NETWORKS[t[0]]()[t[2]], 1)[1:])
    todo.sort(key=lambda t: -size(t))
    cache = json.load(open(CACHE)) if os.path.exists(CACHE) else {}
    res = {t: cache[repr(t)] for t in todo if repr(t) in cache}
    todo = [t for t in todo if t not in res]
    print(f"{len(res)} cached, {len(todo)} to run", flush=True)
    t0 = time.time()
    with Pool(int(os.environ.get("PS_WORKERS", 8))) as pool:
        for i, (t, c) in enumerate(pool.imap_unordered(_sweep_layer, todo)):
            res[t] = c
            cache[repr(t)] = c
            if i % 10 == 0 or i == len(todo) - 1:
                json.dump(cache, open(CACHE, "w"))
            print(f"[{i + 1}/{len(todo)} {time.time() - t0:.0f}s] {t}", flush=True)
    json.dump(cache, open(CACHE, "w"))
    sweep = json.load(open(PS.OUT))
    out = json.load(open(OUT)) if os.path.exists(OUT) else {}
    for n in nets:
        nl = len(wl.NETWORKS[n]())
        out[n] = dict(levels=[])
        for lv, (lab, dens, fr) in enumerate(PS.LEVELS[n]):
            acc = {}
            for li in range(nl):
                add(acc, res[(n, lv, li)])
            e1 = sweep[n]["levels"][lv]
            e1.setdefault("cycles_b1_prune_sweep", dict(e1["cycles_b1"]))
            e1["cycles_b1"]["prosperity"] = acc["prosperity"]["cycles"]          # corrected operator names
            cyc = e1["cycles_b1"]
            out[n]["levels"].append(dict(label=lab, density=dens, firing_rate=fr, cycles_b1=cyc,
                                         energy_J=energy(acc, cyc),
                                         dram_MB={d: acc[d]["dram"] / 8e6 for d in DESIGNS}))
    json.dump(sweep, open(PS.OUT, "w"), indent=1)
    json.dump(out, open(OUT, "w"), indent=1)
    for n in nets:
        print(n)
        for e in out[n]["levels"]:
            E = {d: sum(e["energy_J"][d].values()) for d in DESIGNS}
            print(f"  {e['label']:7s} total uJ: " + " ".join(f"{d} {E[d] * 1e6:9.1f}" for d in DESIGNS))


if __name__ == "__main__":
    validate() if sys.argv[1:] == ["validate"] else main()
