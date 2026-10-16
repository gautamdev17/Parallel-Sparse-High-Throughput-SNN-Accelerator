"""
prosperity_official.py -- Prosperity latency from the OFFICIAL Prosperity simulator (github Prosperity-main,
MIT, vendored in third_party/prosperity, unmodified).

Only one thing is replaced: simulator.find_product_sparsity (a per-row Python loop; the authors use a CUDA
kernel for speed) by a vectorized numpy version that returns the SAME preprocessed tile and prefix array.
`verify` checks the equality on random tiles and on tiles of the authors' real spike data.

  python3 prosperity_official.py verify     # equality check of the fast prefix search
  python3 prosperity_official.py reference  # their 4 CNN benchmarks vs reference/time_reference.xlsx (+ PTB)
  python3 prosperity_official.py ours       # our VGG16/ResNet18 workloads -> results/prosperity_official.json

Needs torch + networkx (pip). The authors' spike data: third_party/prosperity_data/*.pkl.
"""
import json, math, os, sys, types, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
SIM = os.path.join(HERE, "third_party", "prosperity")
DATA = os.path.join(HERE, "third_party", "prosperity_data")
sys.path.insert(0, SIM)

import torch  # noqa: E402


_cache = {}


def fast_find_product_sparsity(act):
    """identical result to Prosperity's simulator.find_product_sparsity(act) (rows x k bool tile)."""
    a = act.numpy().astype(bool) if isinstance(act, torch.Tensor) else np.asarray(act, dtype=bool)
    m, k = a.shape
    nnz = a.sum(1)
    if not (nnz >= 2).any():                    # no row is searched: tile unchanged, no prefix
        return act.clone(), torch.full((m,), -1.0)
    key = (a.shape, np.packbits(a).tobytes())
    hit = _cache.get(key)
    if hit is not None:
        return hit[0].clone().to(act.dtype), hit[1].clone()
    out = _fps(a, m, nnz)
    pre, prefix = torch.from_numpy(out[0]).to(act.dtype), torch.from_numpy(out[1])
    if len(_cache) < 200000:
        _cache[key] = (pre, prefix)
    return pre.clone(), prefix.clone()


def _fps(a, m, nnz):
    # subset[i, j]: row j is a subset of row i (and_result == act[j] for all bits)
    sub = ~(a[None, :, :] & ~a[:, None, :]).any(-1)
    eq = (a[None, :, :] == a[:, None, :]).all(-1)
    big = np.arange(m)[None, :] >= np.arange(m)[:, None]
    cand = sub & ~(eq & big)
    size = np.where(cand, nnz[None, :], -1)
    best = size.argmax(1)                       # first maximal index, as torch.max on CPU
    bsize = size[np.arange(m), best]
    ok = (nnz >= 2) & (bsize >= 1)
    pre = a.copy()
    pre[ok] = a[ok] ^ a[best[ok]]
    prefix = np.full(m, -1.0, dtype=np.float32)
    prefix[ok] = best[ok]
    return pre, prefix


# the CUDA extension is only imported (used by the LoAS baseline); give it the same function tile by tile
_eng = types.ModuleType("prosparsity_engine")


def _engine_fps(x, M, K):
    out = x.clone()
    pref = []
    for m0 in range(0, x.shape[0], M):
        for k0 in range(0, x.shape[1], K):
            p, q = fast_find_product_sparsity(x[m0:m0 + M, k0:k0 + K])
            out[m0:m0 + M, k0:k0 + K] = p
            pref.append(q)
    return out, torch.cat(pref)


_eng.find_product_sparsity = _engine_fps
sys.modules["prosparsity_engine"] = _eng

# load the official modules in isolation: their baselines.py must not clash with ours
_saved = sys.modules.pop("baselines", None)
import simulator as S  # noqa: E402  (official code)
import networks as NW  # noqa: E402
from accelerator import Accelerator  # noqa: E402
from baselines import run_simulation_PTB, run_PTB_convfc, run_simulation_sato  # noqa: E402
sys.modules["p_baselines"] = sys.modules.pop("baselines")
sys.path.remove(SIM)
if _saved is not None:
    sys.modules["baselines"] = _saved

_orig = S.find_product_sparsity
S.find_product_sparsity = fast_find_product_sparsity


MEM_W = int(os.environ.get("DRAM_BITS_PER_CYCLE", 1024))     # official default 1024
SUFFIX = "" if MEM_W == 1024 else f"_bw{MEM_W}"
if MEM_W != 1024:
    # PTB model hard-codes the 1024-bit interface; re-load it with the same code and only that constant changed
    import inspect, textwrap
    _pb = sys.modules["p_baselines"]
    _src = textwrap.dedent(inspect.getsource(_pb.run_PTB_convfc)).replace("// 1024", f"// {MEM_W}")
    exec(compile(_src, "<run_PTB_convfc bw>", "exec"), _pb.__dict__)


def prosperity_accel():
    return Accelerator(type="Prosperity", adder_array_size=128, LIF_array_size=32, tile_size_M=256,
                       tile_size_K=16, product_sparsity=True, issue_type=2, dense=False, mem_if_width=MEM_W)


def run_model_ops(ops, name="x"):
    S.clear_global_stats()
    sim = S.Simulator(accelerator=prosperity_accel(), network=ops, benchmark_name=name, use_cuda=False)
    import contextlib, io
    with contextlib.redirect_stdout(io.StringIO()):
        st = sim.sim()
    return st.total_cycles


def verify():
    rng = np.random.default_rng(0)
    n = 0
    for dens in (0.05, 0.2, 0.5):
        for _ in range(40):
            t = torch.from_numpy(rng.random((256, 16)) < dens)
            a, b = _orig(t)
            c, d = fast_find_product_sparsity(t)
            assert torch.equal(a.bool(), c.bool()) and torch.equal(b, d), dens
            n += 1
    import pickle
    sp = pickle.load(open(os.path.join(DATA, "vgg16_cifar100.pkl"), "rb"))
    ops = NW.create_network("vgg16", os.path.join(DATA, "vgg16_cifar100.pkl"))
    conv = [o for o in ops if isinstance(o, NW.Conv2D)][3]
    fc = NW.conv2d_2_fc(conv)
    x = fc.activation_tensor.sparse_map.reshape(fc.time_steps, fc.sequence_length, fc.input_dim).permute(1, 0, 2)
    x = x.reshape(-1, fc.input_dim)
    for m0 in range(0, min(x.shape[0], 256 * 6), 256):
        for k0 in range(0, min(x.shape[1], 16 * 6), 16):
            t = x[m0:m0 + 256, k0:k0 + 16]
            a, b = _orig(t)
            c, d = fast_find_product_sparsity(t)
            assert torch.equal(a.bool(), c.bool()) and torch.equal(b, d)
            n += 1
    print(f"[ok] fast prefix search == official find_product_sparsity on {n} tiles (random + real VGG16 spikes)")


REF = {  # reference/time_reference.xlsx (seconds at 500 MHz)
    "vgg16_cifar10": dict(Prosperity=2.1503906e-2, PTB=0.145917404, SATO=8.5968e-2),
    "vgg16_cifar100": dict(Prosperity=3.3576808e-2, PTB=0.316902108, SATO=0.38986304),
    "resnet18_cifar10": dict(Prosperity=1.176426e-2, PTB=8.0507168e-2, SATO=3.666688e-2),
    "resnet18_cifar100": dict(Prosperity=1.1631254e-2, PTB=9.6489344e-2, SATO=3.5221376e-2),
}


def sato_reference():
    import contextlib, io
    out = {}
    for name, ref in REF.items():
        with contextlib.redirect_stdout(io.StringIO()):
            c = run_simulation_sato(NW.create_network(name.split("_")[0], os.path.join(DATA, name + ".pkl"))).total_cycles
        out[name] = dict(sato_s=c / 500e6, sato_ref_s=ref["SATO"])
        print(f"{name:18s} SATO {c/500e6*1e3:9.3f} ms (paper ref {ref['SATO']*1e3:9.3f})", flush=True)
    json.dump(out, open(os.path.join(HERE, "results", "sato_reference_check.json"), "w"), indent=1)


def sato_ours():
    from multiprocessing import Pool
    tasks = [(net, b, w) for w in ("sparse90", "zipstats") for net in ("VGG16", "ResNet18") for b in (1, 16)]
    with Pool(min(8, len(tasks))) as p:
        res = p.map(_sato_one, tasks)
    out = {f"{net}|{b}|{w}": c for (net, b, w), c in zip(tasks, res)}
    json.dump(out, open(os.path.join(HERE, "results", "sato_official.json"), "w"), indent=1)
    for k, v in out.items():
        print(k, f"{v:,} cycles")


def _sato_one(t):
    import contextlib, io
    net, b, w = t
    wd, ns, q = WORKLOADS[w]
    with contextlib.redirect_stdout(io.StringIO()):
        return int(run_simulation_sato(our_ops(net, b, wd, ns, q)).total_cycles)


def reference():
    import contextlib, io
    out = {}
    for name, ref in REF.items():
        path = os.path.join(DATA, name + ".pkl")
        cyc = run_model_ops(NW.create_network(name.split("_")[0], path), name)
        with contextlib.redirect_stdout(io.StringIO()):
            ptb = run_simulation_PTB(NW.create_network(name.split("_")[0], path)).total_cycles
        t, tp = cyc / 500e6, ptb / 500e6
        out[name] = dict(prosperity_s=t, prosperity_ref_s=ref["Prosperity"], ptb_s=tp, ptb_ref_s=ref["PTB"])
        print(f"{name:18s} Prosperity {t*1e3:8.3f} ms (paper ref {ref['Prosperity']*1e3:8.3f})   "
              f"PTB {tp*1e3:8.3f} ms (paper ref {ref['PTB']*1e3:8.3f})", flush=True)
    json.dump(out, open(os.path.join(HERE, "results", "prosperity_reference_check.json"), "w"), indent=1)


def our_ops(net, batch, wd, ns, q, T=8):
    """our layers + tensors (same seeds as run_all.py) as official FC + LIF operators."""
    import workload as wl
    ops = []
    for li, layer in enumerate(wl.NETWORKS[net]()):
        M, K, N = wl.gemm_shape(layer, batch)
        seed = zlib.crc32(f"{net}|{li}|{batch}|{wd}|{ns}|{q}".encode())
        _, Sm = wl.layer_tensors(layer, batch, wd, ns, q, seed)        # (K, N) T-bit trains
        bits = ((Sm[None, :, :] >> np.arange(T)[:, None, None]) & 1).astype(bool)   # T, K, N
        act = torch.from_numpy(bits.transpose(0, 2, 1).copy())       # T, L, K
        k = layer[3]
        nm = f"conv{li}_kernel{k}_fc" if k > 1 else f"fc{li}"
        op = NW.FC(nm, K, M, N, 1, T)
        op.activation_tensor.sparse_map = act.reshape(1, T, N, K).float()
        ops.append(op)
        ops.append(NW.LIFNeuron(f"lif_{li}", M * N, 1, T))
    return ops


def ours():
    from multiprocessing import Pool
    tasks = [(net, b, w) for w in ("sparse90", "zipstats") for net in ("VGG16", "ResNet18") for b in (1, 16)]
    with Pool(min(8, len(tasks))) as p:
        res = p.map(_one, tasks)
    out = {f"{net}|{b}|{w}": c for (net, b, w), c in zip(tasks, res)}
    json.dump(out, open(os.path.join(HERE, "results", f"prosperity_official{SUFFIX}.json"), "w"), indent=1)
    for k, v in out.items():
        print(k, f"{v:,} cycles")


WORKLOADS = {"sparse90": (0.10, 0.10, 0.3), "zipstats": (1.00, 0.261, 0.3)}   # = run_all.WORKLOADS


def _one(t):
    net, b, w = t
    wd, ns, q = WORKLOADS[w]
    return int(run_model_ops(our_ops(net, b, wd, ns, q), f"{net}_{b}_{w}"))


sys.path.insert(1, HERE)

def ptb_ops_image(net, batch, b, wd, ns, q, T=8):
    """one image (b) of our batch as official Conv2D / FC + LIF operators (conv inputs = feature maps, so the
    Prosperity repo's own img2col and time-window packing run on them). Same seeds/tensors as run_all.py."""
    import workload as wl
    ops = []
    for li, layer in enumerate(wl.NETWORKS[net]()):
        name, ci, co, k, s, h = layer
        M, K, N = wl.gemm_shape(layer, batch)
        seed = zlib.crc32(f"{net}|{li}|{batch}|{wd}|{ns}|{q}".encode())
        rng = np.random.default_rng(seed)
        wl.rand_weights(rng, M, K, wd)                       # same draw order as workload.layer_tensors
        X = wl.rand_spikes(rng, (batch, ci, h, h), ns, q)[b]  # (C, H, H) T-bit trains of image b
        bits = ((X[None] >> np.arange(T)[:, None, None, None]) & 1).astype(np.float32)   # T, C, H, H
        if k > 1 or s > 1 or h > 1:
            op = NW.Conv2D(f"conv2d_{li}", h, ci, co, k, k // 2, s, 1, T)
            op.activation_tensor.sparse_map = torch.from_numpy(bits)
            nn_out = op.output_H * op.output_H * co
        else:
            op = NW.FC(f"fc_{li}", ci, co, 1, 1, T)
            op.activation_tensor.sparse_map = torch.from_numpy(bits.reshape(1, T, 1, ci))
            nn_out = co
        ops.append(op)
        ops.append(NW.LIFNeuron(f"lif_{li}", nn_out, 1, T))
    return ops


def ptb_ours():
    """PTB = the Prosperity repo's run_simulation_PTB, unmodified. Batch 16 = the 16 images run one after
    another (PTB has no cross-image batching; its cold start is per output pixel of each image)."""
    from multiprocessing import Pool
    tasks = []
    for w in ("sparse90", "zipstats"):
        for net in ("VGG16", "ResNet18"):
            tasks.append((net, 1, 0, w))
            tasks += [(net, 16, b, w) for b in range(16)]
    with Pool(8) as p:
        res = p.map(_ptb_one, tasks)
    out = {}
    for (net, batch, b, w), c in zip(tasks, res):
        out[f"{net}|{batch}|{w}"] = out.get(f"{net}|{batch}|{w}", 0) + c
    json.dump(out, open(os.path.join(HERE, "results", f"ptb_official{SUFFIX}.json"), "w"), indent=1)
    for k, v in out.items():
        print(k, f"{v:,} cycles")


def _ptb_one(t):
    import contextlib, io
    net, batch, b, w = t
    wd, ns, q = WORKLOADS[w]
    with contextlib.redirect_stdout(io.StringIO()):
        return int(run_simulation_PTB(ptb_ops_image(net, batch, b, wd, ns, q)).total_cycles)


if __name__ == "__main__":
    {"verify": verify, "reference": reference, "ours": ours, "sato_reference": sato_reference,
     "sato_ours": sato_ours, "ptb_ours": ptb_ours}[sys.argv[1]]()
