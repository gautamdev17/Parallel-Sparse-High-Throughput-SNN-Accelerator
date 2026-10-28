"""
prune_sweep.py -- every accelerator on the six networks of the SNN unstructured-pruning table (CifarNet, ResNet-19,
ResNet-18 on CIFAR-10; VGGSNN on DVS-CIFAR10; ResNet-18 and Spikformer-8-384 on ImageNet) at every pruning level of
the table: weight density = the table's Density (sparsity = 1 - density), spikes = the table's Firing Rate.

Tensors (synthetic, workload.layer_tensors_rate): INT8 weights, each non-zero with probability = density; spike
trains with every (neuron, timestep) firing independently with probability = firing rate; T = 8 (our design point);
seeded per (network, level, layer, batch). All layers are included (as in the main results).

Designs (the same simulators as the main results and realtraces/run_real.py), per layer:
  TIDES      ours.run_layer_fast (cycle model, RTL-verified)
  SpikeX, SpikeFlow  baselines.py;   LoAS  loas_model.py
  PTB        official Prosperity-repo model, FC operator on the im2col spikes + LIF, one image at a time
  SATO       official Prosperity-repo model, FC operator + LIF
  Prosperity official Prosperity simulator, FC operator + LIF
  The official models get the spike map as a T x N x K tensor; a layer whose map exceeds CHUNK elements is run in
  column chunks (Prosperity / SATO: multiples of 32 output positions = whole 256-row tiles; PTB: within one image)
  and the cycles are summed. PTB's model folds the positions into 8 rows, so a chunk whose position count is not a
  multiple of 4 is padded with silent positions (PTB only; e.g. the 7 x 7 maps of ImageNet ResNet-18).
Latency = batch-1 cycles; throughput = batch-16 cycles / 16.

  <python with torch, pandas, networkx> prune_sweep.py [network ...]   -> results/prune_sweep.json
  PS_BATCHES=1 ...   only batch 1 (latency); PS_WORKERS=8 ...   worker processes (default 6)
"""
import contextlib, io, json, os, sys, time, zlib
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
R = os.path.join(HERE, "results")
OUT = os.path.join(R, "prune_sweep.json")
CACHE = os.path.join(R, "prune_sweep_cache.json")
T = 8
TWS = (1, 2, 4, 8)
BATCHES = tuple(int(b) for b in os.environ.get("PS_BATCHES", "1,16").split(","))
CHUNK = 40_000_000
DESIGNS = ("ptb", "spikex", "loas", "sato", "spikeflow", "prosperity", "ours")

# (label, weight density %, firing rate %) from the table; the first row of each network is the dense model
LEVELS = {
    "CifarNet": [("dense", 100, 5.09), ("2e-7", 72.52, 4.73), ("5e-7", 45.92, 3.61), ("1e-6", 19.15, 2.66),
                 ("1.5e-6", 8.84, 2.14), ("2e-6", 5.24, 1.74)],
    "ResNet19-tdBN": [("dense", 100, 6.83), ("5e-7", 7.29, 5.52), ("1e-6", 3.41, 3.91), ("2e-6", 1.52, 2.28),
                      ("2.5e-6", 1.15, 1.90), ("3e-6", 0.91, 1.61)],
    "ResNet18": [("dense", 100, 10.39), ("5e-7", 32.69, 9.99), ("1e-6", 15.14, 8.65), ("2e-6", 6.40, 6.58),
                 ("3e-6", 3.88, 5.15), ("4e-6", 2.67, 3.98)],
    "VGGSNN-DVS": [("dense", 100, 5.38), ("2e-6", 11.44, 4.69), ("5e-6", 5.91, 3.28), ("7e-6", 4.49, 2.80),
                   ("1e-5", 3.20, 2.34), ("1.5e-5", 1.96, 1.76)],
    "ResNet18-ImageNet": [("dense", 100, 15.37), ("7e-8", 41.67, 13.38), ("1.5e-7", 29.86, 11.29),
                          ("2e-7", 25.75, 11.09), ("3e-7", 20.75, 9.50)],
    "Spikformer-8-384": [("dense", 100, 14.61), ("1e-6", 52.24, 11.15), ("2e-6", 39.27, 13.51),
                         ("3e-6", 33.07, 11.38)],
}
DATASET = {"CifarNet": "CIFAR-10", "ResNet19-tdBN": "CIFAR-10", "ResNet18": "CIFAR-10", "VGGSNN-DVS": "DVS-CIFAR10",
           "ResNet18-ImageNet": "ImageNet", "Spikformer-8-384": "ImageNet"}


def tensors(net, lvl, li, batch):
    import workload as wl
    lab, dens, fr = LEVELS[net][lvl]
    layer = wl.NETWORKS[net]()[li]
    seed = zlib.crc32(f"prune|{net}|{lab}|{li}|{batch}|{dens}|{fr}|T{T}".encode())
    return wl.layer_tensors_rate(layer, batch, dens / 100, fr / 100, seed, T=T)


def fc_op(P, name, S, M):
    """official FC operator with the trains S (K x N) as its T x N x K spike map (as in realtraces/run_real.py)."""
    import torch
    K, N = S.shape
    bits = ((S[None] >> np.arange(T)[:, None, None]) & 1).astype(bool)
    op = P.NW.FC(name, K, M, N, 1, T)
    op.activation_tensor.sparse_map = torch.from_numpy(bits.transpose(0, 2, 1).copy()).reshape(1, T, N, K).float()
    return op


def chunks(N, K, align):
    step = max(align, (CHUNK // (T * K)) // align * align)
    return [(c, min(N, c + step)) for c in range(0, N, step)]


def official(name, S, M, npix):
    import prosperity_official as P
    pb = sys.modules["p_baselines"]
    K, N = S.shape
    lif = lambda n: P.NW.LIFNeuron(f"lif_{name}", M * n, 1, T)
    r = dict(prosperity=0, sato=0, ptb=0)
    with contextlib.redirect_stdout(io.StringIO()):
        for a, b in chunks(N, K, 32):
            Sc = S[:, a:b]
            r["prosperity"] += int(P.run_model_ops([fc_op(P, name, Sc, M), lif(b - a)], name))
            r["sato"] += int(pb.run_sato_conv_fc(fc_op(P, name, Sc, M)).compute_cycles
                             + pb.run_sato_lif(lif(b - a)).compute_cycles)
        for i in range(0, N, npix):                                # PTB: one image at a time
            for a, b in chunks(npix, K, 4):
                Sc = S[:, i + a:i + b]
                if Sc.shape[1] > 1 and Sc.shape[1] % 4:          # PTB folds positions into 8 rows: pad, silent
                    Sc = np.pad(Sc, ((0, 0), (0, -Sc.shape[1] % 4)))
                r["ptb"] += int(pb.run_simulation_PTB([fc_op(P, name, Sc, M), lif(b - a)]).total_cycles)
    return r


def task(t):
    net, lvl, batch, li = t
    import baselines as ob                      # ours, imported before the official repo's module of that name
    from ours import Cfg, run_layer_fast
    from loas_model import loas_layer_cycles_own
    import workload as wl
    layer = wl.NETWORKS[net]()[li]
    W, S = tensors(net, lvl, li, batch)
    M = W.shape[0]
    t0 = time.time()
    r = dict(name=layer[0], M=M, K=S.shape[0], N=S.shape[1],
             ours=int(run_layer_fast(W, S, Cfg(T=T))["cycles"]),
             spikex=int(ob.spikex_layer_cycles(S, M, T=T, tws_list=TWS)[0]),
             spikeflow=int(ob.spikeflow_layer_cycles(S, M, T=T)),
             loas=int(loas_layer_cycles_own(W, S)))
    r.update(official(layer[0], S, M, S.shape[1] // batch))
    r.update(weight_density=float((W != 0).mean()),
             bit_density=float(wl.popcount8(S).mean() / T), secs=round(time.time() - t0, 1))
    return t, r


def main():
    import workload as wl
    nets = sys.argv[1:] or list(LEVELS)
    todo = [(n, lv, b, li) for n in nets for lv in range(len(LEVELS[n])) for b in BATCHES
            for li in range(len(wl.NETWORKS[n]()))]
    size = lambda t: np.prod(wl.gemm_shape(wl.NETWORKS[t[0]]()[t[3]], t[2])[1:])
    todo.sort(key=lambda t: -size(t))
    cache = json.load(open(CACHE)) if os.path.exists(CACHE) else {}
    res = {t: cache[repr(t)] for t in todo if repr(t) in cache}
    todo = [t for t in todo if t not in res]
    print(f"{len(res)} cached, {len(todo)} to run", flush=True)
    t0 = time.time()
    with Pool(int(os.environ.get("PS_WORKERS", 6))) as pool:
        for i, (t, r) in enumerate(pool.imap_unordered(task, todo)):
            res[t] = r
            cache[repr(t)] = r
            if i % 5 == 0 or i == len(todo) - 1:
                json.dump(cache, open(CACHE, "w"))
            print(f"[{i + 1}/{len(todo)} {time.time() - t0:.0f}s] {t[0]} {LEVELS[t[0]][t[1]][0]} b{t[2]} "
                  f"{r['name']} N{r['N']} | " + " ".join(f"{k} {r[k]:,}" for k in DESIGNS) + f" | {r['secs']}s",
                  flush=True)
    json.dump(cache, open(CACHE, "w"))
    out = json.load(open(OUT)) if os.path.exists(OUT) else {}
    for n in nets:
        nl = len(wl.NETWORKS[n]())
        old = {e["label"]: e for e in out.get(n, {}).get("levels", [])}
        out[n] = dict(dataset=DATASET[n], T=T, levels=[])
        for lv, (lab, dens, fr) in enumerate(LEVELS[n]):
            e = dict(old.get(lab, {}), label=lab, density=dens, firing_rate=fr)
            for b in BATCHES:
                e[f"cycles_b{b}"] = {k: sum(res[(n, lv, b, li)][k] for li in range(nl)) for k in DESIGNS}
            out[n]["levels"].append(e)
    json.dump(out, open(OUT, "w"), indent=1)
    for n in nets:
        print(n)
        for e in out[n]["levels"]:
            print(f"  {e['label']:7s} dens {e['density']:6.2f}% fr {e['firing_rate']:5.2f}%  "
                  + " | ".join(f"b{b}: " + " ".join(f"{k} {e[f'cycles_b{b}']['ptb'] / e[f'cycles_b{b}'][k]:6.2f}"
                                                     for k in DESIGNS)
                               for b in (1, 16) if f"cycles_b{b}" in e))


if __name__ == "__main__":
    main()
