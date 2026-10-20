"""
run_real.py -- every accelerator on the REAL traces of NeuroFlex's INT8 PASCAL VGG-16 (CIFAR-10, T = 8), dumped by
nf_vgg16.py (results/real_vgg16_cifar10.npz): batch 1 (test image 0) and batch 16 (test images 0..15).

Per layer the GEMM is W (M x K, INT8) times S (K x N spike trains, bit t = timestep t):
  * conv: S = im2col of the input spike map (rows ordered (c, kh, kw)), N = B x H x W
  * fc:   S = input spikes (C x B)
  * a layer right after an AvgPool(2): the pooled input is exactly 1/4 x the sum of 4 binary pre-pool spikes, so the
    layer is run as an exact binary-spike layer on the pre-pool spikes with K x 4 inputs, each weight repeated for its
    4 pre-pool positions (rows (c, kh, kw, u, v); the 1/4 belongs to the neuron threshold)
  * the first conv (input = the image, not spikes) is left out for every design, as for all spiking accelerators.

Designs (the same models as the main results):
  TIDES (ours) ours.run_layer_fast (cycle model, RTL-verified)
  PTB          official Prosperity-repo model (run_PTB_convfc + run_PTB_lif), one image at a time
  SATO         official Prosperity-repo model (run_sato_conv_fc + run_sato_lif), per layer
  Prosperity   official Prosperity simulator (product sparsity)
  SpikeX, SpikeFlow  baselines.py;  LoAS  loas_model.py

  <venv python with torch> run_real.py   -> results/real_vgg16_cycles.json
  RR_TAG=qcfs_vgg16_cifar10_T16 RR_T=16 run_real.py   -> any other trace set (results/<tag>.npz + <tag>_meta.json,
      from nf_vgg16.py / qcfs_vgg16.py) at its T -> results/<tag>_cycles.json. Every design runs all T timesteps as
      it does at T = 8: TIDES with T adders per PE (Cfg(T=T)), PTB/SpikeX with time windows up to T, SpikeFlow with
      pcd // T pixels per column group, the official simulators with time_steps = T.
  RR_SYN=ResNet19,0.0732,0.1351,0.3 RR_T=4 RR_TAG=<tag> run_real.py   -> synthetic layers instead of traces:
      workload.layer_tensors (network, weight density, non-silent density, per-timestep fire probability, T), the
      generator of the main results, seeded per (network, layer, batch, workload, T); every layer is included.
"""
import contextlib, functools, io, json, os, sys, time, zlib
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, ROOT)
R = os.path.join(ROOT, "results")
T = int(os.environ.get("RR_T", "8"))
TAG = os.environ.get("RR_TAG", "real_vgg16_cifar10")
NPZ = os.path.join(R, f"{TAG}.npz")
META = os.path.join(R, f"{TAG}_meta.json")
OUTF = os.path.join(R, "real_vgg16_cycles.json" if TAG == "real_vgg16_cifar10" else f"{TAG}_cycles.json")
TWS = tuple(1 << i for i in range(T.bit_length()))          # time-window sizes 1, 2, 4, ..., T


def im2col(X, k):
    import workload as wl
    return wl.im2col(X, k, 1)


def pooled_conv(P, W, k=3):
    """P: (B, C, 2H, 2W) pre-pool trains; W: (M, C*k*k) -> W' (M, C*k*k*4), S' (C*k*k*4, B*H*W)."""
    B, C, H2, W2 = P.shape
    H, Wd = H2 // 2, W2 // 2
    p = k // 2
    Pp = np.pad(P, ((0, 0), (0, 0), (2 * p, 2 * p), (2 * p, 2 * p)))
    cols = np.empty((C, k, k, 2, 2, B, H, Wd), P.dtype)
    for kh in range(k):
        for kw in range(k):
            for u in range(2):
                for v in range(2):
                    sl = Pp[:, :, 2 * kh + u: 2 * kh + u + 2 * H: 2, 2 * kw + v: 2 * kw + v + 2 * Wd: 2]
                    cols[:, kh, kw, u, v] = sl.transpose(1, 0, 2, 3)
    M = W.shape[0]
    Wx = np.repeat(np.repeat(W.reshape(M, C, k, k, 1, 1), 2, 4), 2, 5).reshape(M, -1)
    return Wx, cols.reshape(C * k * k * 4, B * H * Wd)


def pooled_fc(P, W):
    """P: (B, C, 2, 2) pre-pool trains, W: (M, C) -> W' (M, 4C), S' (4C, B)."""
    B, C = P.shape[:2]
    M = W.shape[0]
    Wx = np.repeat(W.reshape(M, C, 1), 4, 2).reshape(M, -1)
    return Wx, P.reshape(B, C * 4).T.copy()


SYN = os.environ.get("RR_SYN")


@functools.lru_cache(maxsize=2)
def layers(batch):
    """-> list of (name, W, S, pixels per image) for the spiking layers of `batch` images."""
    if SYN:
        import workload as wl
        net, wd, ns, q = SYN.split(",")
        wd, ns, q = float(wd), float(ns), float(q)
        out = []
        for li, layer in enumerate(wl.NETWORKS[net]()):
            seed = zlib.crc32(f"{net}|{li}|{batch}|{wd}|{ns}|{q}|T{T}".encode())
            W, S = wl.layer_tensors(layer, batch, wd, ns, q, seed, T=T)
            out.append((layer[0], W, S, S.shape[1] // batch))
        return out
    d = np.load(NPZ)
    meta = json.load(open(META))["layers"]
    out = []
    for li, m in enumerate(meta):
        if m["analog"]:
            continue
        W = d[f"W{li}"]
        if f"P{li}" in d.files:
            P = d[f"P{li}"][:batch]
            Wx, S = pooled_conv(P, W) if m["kind"] == "conv" else pooled_fc(P, W)
        elif m["kind"] == "conv":
            Wx, S = W, im2col(d[f"X{li}"][:batch], m["k"])
        else:
            Wx, S = W, d[f"X{li}"][:batch].T.copy()
        out.append((m["name"], Wx, S, S.shape[1] // batch))
    return out


def fc_op(name, S, M, li):
    """official FC operator with the trains S (K x N) as its T x N x K spike map."""
    import torch
    import prosperity_official as P
    K, N = S.shape
    bits = ((S[None] >> np.arange(T)[:, None, None]) & 1).astype(bool)
    act = torch.from_numpy(bits.transpose(0, 2, 1).copy())
    op = P.NW.FC(name, K, M, N, 1, T)
    op.activation_tensor.sparse_map = act.reshape(1, T, N, K).float()
    return op


def ours_task(t):
    import importlib.util
    from ours import Cfg, run_layer_fast
    from loas_model import loas_layer_cycles_own
    # our baselines.py, by path: a worker that ran official() has the Prosperity repo's own 'baselines' on sys.path
    spec = importlib.util.spec_from_file_location("our_baselines", os.path.join(ROOT, "baselines.py"))
    ob = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(ob)
    spikex_layer_cycles, spikeflow_layer_cycles = ob.spikex_layer_cycles, ob.spikeflow_layer_cycles
    batch, li = t
    name, W, S, _ = layers(batch)[li]
    M = W.shape[0]
    return batch, li, dict(name=name, M=M, K=S.shape[0], N=S.shape[1], ours=run_layer_fast(W, S, Cfg(T=T))["cycles"],
                           spikex=spikex_layer_cycles(S, M, T=T, tws_list=TWS)[0],
                           spikeflow=spikeflow_layer_cycles(S, M, T=T),
                           loas=int(loas_layer_cycles_own(W, S)),
                           weight_density=float((W != 0).mean()), nonsilent=float((S != 0).mean()))


def official(batch):
    import prosperity_official as P
    pb = sys.modules["p_baselines"]
    L = layers(batch)
    res = {}
    with contextlib.redirect_stdout(io.StringIO()):
        # Prosperity: whole network on the official simulator
        ops = []
        for li, (name, W, S, _) in enumerate(L):
            ops += [fc_op(f"fc{li}", S, W.shape[0], li), P.NW.LIFNeuron(f"lif_{li}", W.shape[0] * S.shape[1], 1, T)]
        res["prosperity"] = int(P.run_model_ops(ops, f"real_{batch}"))
        # SATO: per layer, as in the main results
        res["sato"] = 0
        for li, (name, W, S, _) in enumerate(L):
            op = fc_op(f"fc{li}", S, W.shape[0], li)
            res["sato"] += pb.run_sato_conv_fc(op).compute_cycles
            res["sato"] += pb.run_sato_lif(P.NW.LIFNeuron(f"lif_{li}", W.shape[0] * S.shape[1], 1, T)).compute_cycles
        # PTB: one image at a time (no cross-image batching), as the official model
        res["ptb"] = 0
        for b in range(batch):
            ops = []
            for li, (name, W, S, npix) in enumerate(L):
                Sb = S[:, b * npix:(b + 1) * npix]
                ops += [fc_op(f"fc{li}", Sb, W.shape[0], li), P.NW.LIFNeuron(f"lif_{li}", W.shape[0] * npix, 1, T)]
            res["ptb"] += int(pb.run_simulation_PTB(ops).total_cycles)
    return batch, res


def main():
    nl = len(layers(1))
    t0 = time.time()
    out = {b: dict(layers=[None] * nl) for b in (1, 16)}
    with Pool(min(8, os.cpu_count())) as pool:
        offi = pool.map_async(official, (1, 16))
        for batch, li, r in pool.imap_unordered(ours_task, [(b, li) for b in (1, 16) for li in range(nl)]):
            out[batch]["layers"][li] = r
            print(f"b{batch} {r['name']:14s} M{r['M']:5d} K{r['K']:6d} N{r['N']:6d} TIDES {r['ours']:>9,} "
                  f"LoAS {r['loas']:>10,} SpikeX {r['spikex']:>10,} SpikeFlow {r['spikeflow']:>9,} "
                  f"({time.time() - t0:.0f}s)", flush=True)
        for batch, r in offi.get():
            out[batch].update(r)
            print(f"b{batch} official: {r}", flush=True)
    for b in (1, 16):
        for d in ("ours", "spikex", "spikeflow", "loas"):
            out[b][d] = sum(x[d] for x in out[b]["layers"])
    json.dump({str(k): v for k, v in out.items()}, open(OUTF, "w"), indent=1)
    for b in (1, 16):
        print(b, {d: out[b][d] for d in ("ptb", "spikex", "loas", "sato", "spikeflow", "prosperity", "ours")})


if __name__ == "__main__":
    main()
