"""
prune_chain.py -- every accelerator on the lab's unstructured-pruning models (~/snn-pruning-DAC: QCFS L = 8, IF
neuron, CIFAR-10; ResNet-18, ResNet-19, VGG-16 at dense / 90 % / 95 % (/ 98 % once its eval.json exists) global
weight sparsity), T = 8, batch 1, with the activations produced by running ONE real CIFAR-10 test image (test image 0)
through the network layer by layer: each layer's input spikes are the previous layer's output spikes.

Model (per network and level): the repo's own model definition (torch-pruning/qcfs_utils.get_model, unchanged) with
  * synthetic INT8 weights (the checkpoints are not in the repo): every conv / linear layer gets exactly the weight
    density the repo measured for that layer (eval.json, if_T8, layer W), at random positions, magnitudes uniform
    1..127 with random signs (= workload.rand_weights); biases 0, BatchNorm = identity;
  * IF thresholds calibrated in forward order (bisection on each IF neuron's threshold) so that the zero fraction of
    every layer's input equals the repo's measured activation sparsity A of that layer (eval.json if_T8, same
    definition as torch-pruning-unstructured/common.SparsityCounter: zero entries of the layer's input tensor, per
    timestep); a neuron feeding two layers (a block input feeding conv1 and the 1x1 shortcut) is calibrated on the
    first. Run in float64, so the traces are exact: every layer's conv output is checked against
    workload.dense_sums(W, S) of the recorded trains.
Per weight layer the GEMM is W (M x K) times S (K x N spike trains, bit t = timestep t), as realtraces/run_real.py:
  conv: S = im2col of the input spike map (zero padding k//2, stride s);  fc: S = input spikes
  after an average pool (VGG AvgPool2d(2); ResNet global average pool before the classifier): the pooled input is
  exactly 1/P x the sum of P binary pre-pool spikes, so the layer runs as an exact binary-spike layer on the pre-pool
  spikes with K x P inputs, each weight repeated for its P pre-pool positions (the 1/P belongs to the threshold).
  The first conv (input = the image) is left out for every design.
The same traces go to every design (the simulators of the main results and prune_sweep.py / prune_energy.py):
  TIDES ours.run_layer_fast; SpikeX, SpikeFlow baselines.py; LoAS loas_model.py; PTB / SATO / Prosperity the official
  Prosperity-repo models (Prosperity with the main results' operator names conv<i>_kernel<k>_fc / fc<i>).
Energy per inference = core + on-chip SRAM + DRAM, the rules of prune_energy.py (45 nm, 500 MHz, T = 8 core power).

  ~/torch-env/bin/python prune_chain.py spikes [net ...]   -> results/prune_chain/<net>_<level>.npz + .json
  ~/torch-env/bin/python prune_chain.py sim [net ...]      -> results/prune_chain.json (cached per layer)
  ~/torch-env/bin/python prune_chain.py plot               -> results/prune_chain_{latency,energy,edp}.png/.pdf, .md
  PC_BW=128 python3 prune_chain.py sim / plot   -> latency per layer = max(compute, DRAM bits / 128 bits per cycle)
      for every design (the energy follows the latency) -> results/prune_chain_bw128*.  (sim reuses the cache)
"""
import contextlib, io, json, math, os, sys, time, types, zlib
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, "hw"))
R = os.path.join(HERE, "results")
T, L, CLK = int(os.environ.get("PC_T", 8)), 8, 500e6          # T != 8: latency only (no per-T power / memory)
TT = "" if T == 8 else f"_T{T}"
SD = os.path.join(R, f"prune_chain{TT}")
BW = int(os.environ.get("PC_BW", 0))                       # DRAM bits per cycle bounding latency (0: compute only)
TAG = TT + (f"_bw{BW}" if BW else "")
OUT = os.path.join(R, f"prune_chain{TAG}.json")
CACHE = os.path.join(R, f"prune_chain{TT}_cache.json")
REPO = os.path.expanduser("~/snn-pruning-DAC")
DATA = os.path.expanduser("~/LoAS/dataset")
NETS = {"ResNet18": "resnet18", "ResNet19": "resnet19", "VGG16": "vgg16"}
LEVELS = ("dense", "sp90", "sp95", "sp98")
DESIGNS = ("ptb", "spikex", "loas", "sato", "spikeflow", "prosperity", "ours")


def eval_path(net, lvl):
    m = NETS[net]
    if lvl == "dense":
        return os.path.join(REPO, "unstructured_ckpts", "dense", f"eval_cifar10_{m}.json")
    return os.path.join(REPO, "unstructured_ckpts", f"cifar10_{m}_{lvl}", "eval.json")


def levels(net):
    return [lv for lv in LEVELS if os.path.exists(eval_path(net, lv))]


# ------------------------------------------------------------------------------------------------ spikes (torch)
def repo_model(net):
    import torch
    sys.modules.setdefault("cv2", types.SimpleNamespace(mean=None))   # Models/layer.py imports cv2.mean, unused
    try:
        import matplotlib.pyplot                                         # Models/ResNet.py imports xlim, unused
    except ImportError:
        sys.modules["matplotlib"] = types.SimpleNamespace()
        sys.modules["matplotlib.pyplot"] = types.SimpleNamespace(xlim=None)
    sys.path.insert(0, os.path.join(REPO, "torch-pruning"))
    from qcfs_utils import get_model
    model = get_model(NETS[net], "cifar10")
    model.set_L(L)
    with contextlib.redirect_stdout(io.StringIO()):                    # ResNet.set_T prints every threshold
        model.set_T(T)
    return model.double().eval()


def image():
    import torch
    from torchvision import datasets, transforms
    sys.path.insert(0, os.path.join(REPO, "torch-pruning"))
    from qcfs_utils import NORM
    ds = datasets.CIFAR10(DATA, train=False, download=False,
                          transform=transforms.Compose([transforms.ToTensor(), transforms.Normalize(*NORM["cifar10"])]))
    x, y = ds[0]
    return x[None].double(), int(y)


def packed(nz):
    """(T, ...) bool -> (...) uint8 trains, bit t = timestep t."""
    X = np.zeros(nz.shape[1:], np.uint8)
    for t in range(T):
        X |= nz[t].astype(np.uint8) << t
    return X


class Stop(Exception):
    pass


def spikes(net, lvl):
    import torch
    torch.set_num_threads(int(os.environ.get("PC_THREADS", 2)))
    import torch.nn as nn
    import workload as wl
    ev = json.load(open(eval_path(net, lvl)))[f"if_T{T}"]
    target = {e["layer"]: e for e in ev["layers"]}
    model = repo_model(net)
    from Models.layer import IF
    wlayers = [(n, m) for n, m in model.named_modules() if isinstance(m, (nn.Conv2d, nn.Linear))]
    assert [n for n, _ in wlayers] == [e["layer"] for e in ev["layers"]], "layer names differ from eval.json"
    with torch.no_grad():
        for m in model.modules():
            if isinstance(m, nn.BatchNorm2d):
                m.running_mean.zero_(); m.running_var.fill_(1.0); m.weight.fill_(1.0); m.bias.zero_(); m.eps = 1e-30
        Wint = {}
        for n, m in wlayers:
            rng = np.random.default_rng(zlib.crc32(f"chain|{net}|{lvl}|{n}".encode()))
            M, K = m.weight.shape[0], m.weight[0].numel()
            nnz = int(round((1 - target[n]["W"] / 100) * M * K))
            W = np.zeros(M * K, np.int16)
            pos = rng.choice(M * K, nnz, replace=False)
            W[pos] = rng.integers(1, 128, nnz) * np.where(rng.random(nnz) < 0.5, -1, 1)
            Wint[n] = W.reshape(M, K)
            m.weight.copy_(torch.from_numpy(W.reshape(m.weight.shape).astype(np.float64)))
            if m.bias is not None:
                m.bias.zero_()
    ifs = {m: n for n, m in model.named_modules() if isinstance(m, IF)}
    pools = [m for m in model.modules() if isinstance(m, (nn.AvgPool2d, nn.AdaptiveAvgPool2d))]
    st = dict(ptr={}, stop=None, rec=None)

    def if_hook(m, i, o):
        st["ptr"][o.data_ptr()] = ("if", m)
        st.setdefault("imax", {})[m] = float(i[0].abs().max())

    def pool_hook(m, i, o):
        st["ptr"][o.data_ptr()] = ("pool", m, i[0])

    def w_pre(m, i, name=None):
        x = i[0]
        if st["rec"] is not None:
            st["rec"][name] = dict(x=x.detach().clone(), src=st["ptr"].get(x.data_ptr()))
        if st["stop"] == name:
            st["zero"] = float((x == 0).double().mean())
            st["src"] = st["ptr"].get(x.data_ptr())
            raise Stop

    def w_post(m, i, o, name=None):
        if st["rec"] is not None:
            st["rec"][name]["y"] = o.detach().clone()

    hooks = [m.register_forward_hook(if_hook) for m in ifs] + [m.register_forward_hook(pool_hook) for m in pools]
    for n, m in wlayers:
        hooks.append(m.register_forward_pre_hook(lambda m, i, name=n: w_pre(m, i, name)))
        hooks.append(m.register_forward_hook(lambda m, i, o, name=n: w_post(m, i, o, name)))
    x, label = image()

    def probe(name):
        """-> zero fraction of `name`'s input and the producing IF neuron (through a pool, if any)."""
        st["ptr"], st["stop"] = {}, name
        try:
            with torch.no_grad():
                model(x.clone())          # add_dimention unsqueezes its input in place
        except Stop:
            pass
        st["stop"] = None
        src = st["src"]
        if src and src[0] == "pool":
            src = st["ptr"].get(src[2].data_ptr())
        assert src and src[0] == "if", f"{name}: input not produced by an IF neuron"
        return st["zero"], src[1]

    done, cal = set(), []
    t0 = time.time()
    for n, _ in wlayers[1:]:                                    # forward order; the first conv sees the image
        _, neuron = probe(n)
        if neuron in done:
            continue
        a = target[n]["A"] / 100
        top = math.log10(max(st["imax"][neuron], 1e-300) * 2 * T)  # above this the neuron never fires
        lo, hi = top - 10, top + 0.5                             # log10 threshold
        for _ in range(48):
            mid = (lo + hi) / 2
            neuron.thresh.data.fill_(10 ** mid)
            z, _ = probe(n)
            lo, hi = (lo, mid) if z > a else (mid, hi)
            if hi - lo < 1e-5:
                break
        neuron.thresh.data.fill_(10 ** ((lo + hi) / 2))
        done.add(neuron)
        cal.append((ifs[neuron], n, float(neuron.thresh)))
    # final pass: record every layer's input / output
    st["rec"], st["ptr"] = {}, {}
    with torch.no_grad():
        logits = model(x.clone()).mean(0)
    rec = st["rec"]
    for h in hooks:
        h.remove()
    store, meta = {}, []
    for li, (n, m) in enumerate(wlayers):
        r = rec[n]
        xin, src = r["x"], r["src"]
        zero = float((xin == 0).double().mean())
        # collective sparsity C as torch-pruning-unstructured/common.SparsityCounter: MACs skipped because the weight
        # or the input is zero (zero padding counts as zero input), on the layer's actual (pooled) input
        with torch.no_grad():
            xi, wi = (xin != 0).double(), (m.weight != 0).double()
            if isinstance(m, nn.Conv2d):
                nzm = torch.nn.functional.conv2d(xi, wi, None, m.stride, m.padding, m.dilation, m.groups)
                macs = nzm.numel() * m.in_channels // m.groups * m.kernel_size[0] * m.kernel_size[1]
            else:
                nzm = torch.nn.functional.linear(xi, wi)
                macs = nzm.numel() * m.in_features
            coll = 1 - float(nzm.sum()) / macs
        if li == 0:
            meta.append(dict(name=n, analog=True))
            continue
        conv = isinstance(m, nn.Conv2d)
        W = Wint[n]
        M = W.shape[0]
        pooled = src is not None and src[0] == "pool"
        thr = float((st["ptr"][src[2].data_ptr()] if pooled else src)[1].thresh)
        if pooled:
            pre = src[2]                                         # (T, C, Hp, Wp) binary x thr
            assert torch.all((pre == 0) | ((pre - thr).abs() <= 1e-9 * thr)), f"{n}: pre-pool not binary"
            Pb = packed((pre != 0).numpy())                      # (C, Hp, Wp)
            C, Hp, Wp = Pb.shape
            if conv:
                k = m.kernel_size[0]
                assert m.stride[0] == 1 and Hp == 2 * xin.shape[-1]
                import realtraces.run_real as RRm                  # pooled_conv: exact pre-pool expansion
                Wx, S = RRm.pooled_conv(Pb[None], W, k)
                P = 4
            else:                                                # global / 2x2 average pool -> linear
                k, P = 1, Hp * Wp
                Wx = np.repeat(W.reshape(M, C, 1), P, 2).reshape(M, -1)
                S = Pb.reshape(C * P, 1)
            raw_n, raw_nz = Pb.size, int((Pb != 0).sum())
        else:
            assert torch.all((xin == 0) | ((xin - thr).abs() <= 1e-9 * thr)), f"{n}: input not binary"
            Xb = packed((xin != 0).numpy())                      # (C, H, W) or (C,)
            P = 1
            if conv:
                k, s = m.kernel_size[0], m.stride[0]
                assert m.padding[0] == k // 2
                S = wl.im2col(Xb[None], k, s)
            else:
                k = 1
                S = Xb.reshape(-1, 1)
            Wx = W
            raw_n, raw_nz = Xb.size, int((Xb != 0).sum())
        # exactness: the layer's output = thr / P x W' S' at every timestep
        y = r["y"].numpy().reshape(T, M, -1)
        ref = wl.dense_sums(Wx, S, T).transpose(2, 0, 1) * thr / P
        err = float(np.abs(y - ref).max() / max(1e-30, np.abs(ref).max()))
        assert err < 1e-9, f"{n}: trace mismatch {err}"
        store[f"W{li}"], store[f"S{li}"] = Wx.astype(np.int16), S
        meta.append(dict(name=n, analog=False, kind="conv" if conv else "fc", k=int(k), pool=int(P),
                         M=int(M), K=int(S.shape[0]), N=int(S.shape[1]), raw_n=int(raw_n), raw_nz=raw_nz,
                         ci=int(xin.shape[1]), h=int(xin.shape[-1]) if conv else 1,
                         s=int(m.stride[0]) if conv else 1,
                         W_target=target[n]["W"], W_got=100 * float((W == 0).mean()),
                         A_target=target[n]["A"], A_got=100 * zero, C_target=target[n]["C"], C_got=100 * coll,
                         bit_density=float(wl.popcount8(S).mean() / T), max_rel_err=err))
    os.makedirs(SD, exist_ok=True)
    np.savez_compressed(os.path.join(SD, f"{net}_{lvl}.npz"), **store)
    json.dump(dict(net=net, level=lvl, T=T, image=0, label=label, pred=int(logits.argmax()), acc=ev["acc"],
                   total=ev["total"], thresholds=cal, layers=meta),
              open(os.path.join(SD, f"{net}_{lvl}.json"), "w"), indent=1)
    worst = max(abs(e["A_got"] - e["A_target"]) for e in meta if not e["analog"])
    print(f"{net} {lvl}: {len(meta) - 1} layers, A within {worst:.2f} pts of eval.json, "
          f"{time.time() - t0:.0f}s", flush=True)


# ------------------------------------------------------------------------------------------------ simulation
def layer_sim(t):
    net, lvl, li = t
    import baselines as ob                    # ours, imported before the official repo's module of that name
    from ours import Cfg, run_layer_fast
    from loas_model import loas_layer_cycles_own
    import workload as wl
    import mem_levels as ML
    import memory_model as MM
    import prosperity_official as P
    import prune_sweep as PS
    import prune_energy as PE
    from mem_traffic import split_tiled
    pb = sys.modules["p_baselines"]
    PS.T = PE.T = T                                            # their fc_op / chunks / prosperity_layer use T
    d = np.load(os.path.join(SD, f"{net}_{lvl}.npz"))
    meta = json.load(open(os.path.join(SD, f"{net}_{lvl}.json")))["layers"][li]
    W, S = d[f"W{li}"].astype(np.int16), d[f"S{li}"]
    M, K = W.shape
    N = S.shape[1]
    t0 = time.time()
    cyc = dict(ours=int(run_layer_fast(W, S, Cfg(T=T))["cycles"]),
               spikex=int(ob.spikex_layer_cycles(S, M, T=T, tws_list=tuple(1 << i for i in range(T.bit_length())))[0]),
               spikeflow=int(ob.spikeflow_layer_cycles(S, M, T=T)),
               loas=int(loas_layer_cycles_own(W, S)))
    lif = lambda n: P.NW.LIFNeuron(f"lif_{li}", M * n, 1, T)
    cyc["sato"] = 0
    with contextlib.redirect_stdout(io.StringIO()):
        for a, b in PS.chunks(N, K, 32):
            cyc["sato"] += int(pb.run_sato_conv_fc(PS.fc_op(P, f"fc{li}", S[:, a:b], M)).compute_cycles
                               + pb.run_sato_lif(lif(b - a)).compute_cycles)
    # PTB: cycles and its StSAP slots / pairs (prune_energy.ptb_slots), one pass
    rec, orig = [], pb.StSAP

    def st_wrap(act):
        n = orig(act)
        rec.append((n, int((act != 0).any(-1).sum())))
        return n

    pb.StSAP, cyc["ptb"] = st_wrap, 0
    try:
        with contextlib.redirect_stdout(io.StringIO()):
            al = max(1, 32 // T)                                 # PTB folds (T/4 windows x positions) into 8 rows
            for a, b in PS.chunks(N, K, al):
                Sc = S[:, a:b]
                if Sc.shape[1] > 1 and Sc.shape[1] % al:         # pad with silent positions
                    Sc = np.pad(Sc, ((0, 0), (0, -Sc.shape[1] % al)))
                cyc["ptb"] += int(pb.run_simulation_PTB([PS.fc_op(P, f"fc{li}", Sc, M), lif(b - a)]).total_cycles)
    finally:
        pb.StSAP = orig
    pw = pa = 0
    for n, nz in rec:
        pr = nz - n
        pw += (n + pr) * M * 8
        pa += math.ceil(M / 16) * (n * 8 * 4 + pr * 8)
    k = meta["k"]
    pcyc, rd, wr = PE.prosperity_layer(li, (meta["name"], meta["ci"], M, k, meta["s"], meta["h"]), S, M)
    cyc["prosperity"] = int(pcyc)
    if T != 8:
        return t, dict(name=meta["name"], M=M, K=K, N=N, cycles=cyc, counts=None, secs=round(time.time() - t0, 1))
    # memory counts (prune_energy.layer_counts with the trace's own sizes; raw input = the (pre-pool) spike map)
    KB = 1024
    I_raw = meta["raw_n"] * T / 8
    O = M * N * T / 8
    Wd = M * K
    I_sf = meta["raw_nz"] * T / 8 + meta["raw_n"] / 8
    nch = math.ceil(K / 128)
    fA = nch * (16 + 128 * meta["raw_nz"] / meta["raw_n"] * (T / 8))
    fB = nch * (16 + 128 * float((W != 0).mean()))
    dram_B = {"ours": split_tiled(I_raw, MM.ours_weight_bytes(W), O, 64 * KB),
              "spikex": split_tiled(I_raw, Wd, O, 54 * KB),
              "spikeflow": split_tiled(I_sf, Wd, O, int(18.5 * KB)),
              "sato": split_tiled(I_raw, Wd, O, 54 * KB),
              "loas": split_tiled(N * fA, M * fB, N * M * T / 8, 256 * KB),
              "ptb": (I_raw, Wd, O / 8)}
    cnt = {dd: dict(dram=8 * sum(v)) for dd, v in dram_B.items()}
    fills = {dd: cnt[dd]["dram"] for dd in cnt}
    oc_w, oc_a, _, _, rmw, lifr, gw, rawr, _ = ML.ours_layer(W, S)
    cnt["ours"]["bufs"] = {"staging": (oc_w + rawr, fills["ours"]), "group": (oc_a - rawr, gw),
                           "obuf": ((rmw + lifr) * T * 24, rmw * T * 24)}
    for dd, f in (("spikex", ML.spikex_layer), ("spikeflow", ML.spikeflow_layer), ("loas", ML.loas_layer)):
        w, a = f(W, S)[:2]
        cnt[dd]["bufs"] = {"glb": (w + a, fills[dd])}
    cnt["sato"]["bufs"] = {"glb": (T * N * K + int(wl.popcount8(S).sum()) * M * 8, fills["sato"])}
    cnt["ptb"]["bufs"] = {"glb": (pw + pa, fills["ptb"])}
    cnt["prosperity"] = dict(dram=rd.get("dram", 0.0) + wr.get("dram", 0.0), cycles=int(pcyc),
                             bufs={b: (rd.get(b, 0.0), wr.get(b, 0.0)) for b in ("g_act", "g_wgt", "g_psum")})
    return t, dict(name=meta["name"], M=M, K=K, N=N, cycles=cyc, counts=cnt, secs=round(time.time() - t0, 1))


def sim(nets):
    import prune_energy as PE
    todo = []
    for n in nets:
        for lv in levels(n):
            meta = json.load(open(os.path.join(SD, f"{n}_{lv}.json")))["layers"]
            todo += [(n, lv, li) for li, m in enumerate(meta) if not m["analog"]]
    size = {}
    for t in todo:
        m = json.load(open(os.path.join(SD, f"{t[0]}_{t[1]}.json")))["layers"][t[2]]
        size[t] = m["K"] * m["N"] * m["M"]
    todo.sort(key=lambda t: -size[t])
    cache = json.load(open(CACHE)) if os.path.exists(CACHE) else {}
    res = {t: cache[repr(t)] for t in todo if repr(t) in cache}
    todo = [t for t in todo if t not in res]
    print(f"{len(res)} cached, {len(todo)} to run", flush=True)
    t0 = time.time()
    with Pool(int(os.environ.get("PC_WORKERS", 8))) as pool:
        for i, (t, r) in enumerate(pool.imap_unordered(layer_sim, todo)):
            res[t] = r
            cache[repr(t)] = r
            json.dump(cache, open(CACHE, "w"))
            print(f"[{i + 1}/{len(todo)} {time.time() - t0:.0f}s] {t[0]} {t[1]} {r['name']} M{r['M']} K{r['K']} "
                  f"N{r['N']} | " + " ".join(f"{k} {r['cycles'][k]:,}" for k in DESIGNS) + f" | {r['secs']}s",
                  flush=True)
    out = json.load(open(OUT)) if os.path.exists(OUT) else {}
    for n in nets:
        out[n] = dict(levels=[])
        for lv in levels(n):
            info = json.load(open(os.path.join(SD, f"{n}_{lv}.json")))
            keys = [t for t in res if t[0] == n and t[1] == lv]
            # latency per layer = max(compute, DRAM traffic / bandwidth) when PC_BW is set, for every design
            cyc = {k: sum(max(res[t]["cycles"][k], res[t]["counts"][k]["dram"] / BW) if BW else res[t]["cycles"][k]
                          for t in keys) for k in DESIGNS}
            e = dict(level=lv, acc=info["acc"], W=info["total"]["W"], A=info["total"]["A"], cycles_b1=cyc,
                     layers=len(keys))
            if T == 8:
                acc = {}
                for t in keys:
                    PE.add(acc, res[t]["counts"])
                e.update(energy_J=PE.energy(acc, cyc), dram_MB={d: acc[d]["dram"] / 8e6 for d in DESIGNS})
            # Prosperity with its paper's per-tile pipeline (prosperity_own_correct_final.py), next to the official simulator
            pp = os.path.join(R, f"prosperity_own_correct_final_{n}_T{T}.json")
            if os.path.exists(pp) and lv in (pj := json.load(open(pp))):
                pl = pj[lv]
                pc = sum(max(pl[str(t[2])]["paper_total"], res[t]["counts"]["prosperity"]["dram"] / BW)
                         if BW and res[t]["counts"] else pl[str(t[2])]["paper_total"] for t in keys)
                e["cycles_b1_prosperity_paper"] = pc
                if T == 8:
                    e["energy_J_prosperity_paper"] = PE.energy(acc, dict(cyc, prosperity=pc))["prosperity"]
            out[n]["levels"].append(e)
    json.dump(out, open(OUT, "w"), indent=1)
    for n in nets:
        print(n)
        for e in out[n]["levels"]:
            c = e["cycles_b1"]
            print(f"  {e['level']:5s} acc {e['acc']:.2f}  lat/PTB " + " ".join(f"{d} {c[d] / c['ptb']:.3f}"
                                                                             for d in DESIGNS))
            if "energy_J" in e:
                E = {d: sum(e["energy_J"][d].values()) for d in DESIGNS}
                print(f"        E/PTB   " + " ".join(f"{d} {E[d] / E['ptb']:.3f}" for d in DESIGNS))


# ------------------------------------------------------------------------------------------------ plot
def plot():
    import figstyle as FS
    from plot_prune_sweep import ORDER, NAME, MARK, GREY
    plt = FS.plt
    d = json.load(open(OUT))
    nets = [n for n in NETS if n in d]
    energy = all("energy_J" in e for n in nets for e in d[n]["levels"])
    for e in (e for n in nets for e in d[n]["levels"]):
        e["lat"] = {k: e["cycles_b1"][k] / CLK for k in ORDER}
        if energy:
            e["E"] = {k: sum(e["energy_J"][k].values()) for k in ORDER}
            e["edp"] = {k: e["E"][k] * e["lat"][k] for k in ORDER}
    lab = {"dense": "dense", "sp90": "90", "sp95": "95", "sp98": "98"}
    metrics = (("lat", "Norm. latency (PTB = 1)", "latency"), ("E", "Norm. energy (PTB = 1)", "energy"),
               ("edp", "Norm. EDP (PTB = 1)", "edp"))
    metrics = metrics if energy else metrics[:1]
    for key, ylabel, stem in metrics:
        fig, axes = plt.subplots(1, len(nets), figsize=(FS.TEXT, 2.2))
        for ax, n in zip(axes, nets):
            lv = d[n]["levels"]
            xs = list(range(len(lv)))
            for k in ORDER:
                ys = [e[key][k] / e[key]["ptb"] for e in lv]
                ours = k == "ours"
                ax.plot(xs, ys, marker=MARK[k], ms=6 if ours else 3.5, lw=1.7 if ours else 0.8, color=GREY[k],
                        mfc=GREY[k] if ours else "white", mec=GREY[k], label=NAME[k], zorder=5 if ours else 3)
            ax.set_yscale("log")
            ax.set_xticks(xs, [f"{lab[e['level']]}\n{e['acc']:.2f}" for e in lv], fontsize=6)
            ax.set_title(f"{n} (CIFAR-10)", fontsize=7, fontweight="bold")
            ax.set_xlabel("Weight sparsity %\nIF T = {T} accuracy %", fontsize=6.5)
            ax.grid(True, which="major", ls=":", lw=0.5, color="#999999")
        axes[0].set_ylabel(ylabel, fontsize=7)
        h, l = axes[0].get_legend_handles_labels()
        fig.legend(h, l, loc="upper center", ncol=len(ORDER), frameon=False, fontsize=7, bbox_to_anchor=(0.5, 1.06))
        fig.tight_layout(rect=(0, 0, 1, 0.92), w_pad=0.6)
        for ext in ("png", "pdf"):
            fig.savefig(os.path.join(R, f"prune_chain{TAG}_{stem}.{ext}"), dpi=300, bbox_inches="tight")
        plt.close(fig)
    lines = [f"# Weight-sparsity sweep, chained CIFAR-10 test image 0, IF T = {T}, batch 1 (prune_chain.py)", "",
             "Normalized to PTB (PTB = 1, lower is better). Energy = core + SRAM + DRAM (45 nm, 500 MHz)."
             + (f" Latency per layer = max(compute cycles, DRAM bits / {BW} bits per cycle) for every design "
                f"({BW * 500e6 / 8e9:g} GB/s at 500 MHz); core and SRAM leakage energy follow that latency."
                if BW else ""), ""]
    for key, ylabel, stem in metrics:
        lines += [f"## {ylabel}", "", "| Network | Level | Acc % | " + " | ".join(NAME[k] for k in ORDER)
                  + " | TIDES vs best baseline |", "|---|---|---:|" + "---:|" * len(ORDER) + "---|"]
        for n in nets:
            for e in d[n]["levels"]:
                v = {k: e[key][k] / e[key]["ptb"] for k in ORDER}
                best = min((k for k in ORDER if k != "ours"), key=lambda k: v[k])
                lines.append(f"| {n} | {e['level']} | {e['acc']:.2f} | " + " | ".join(f"{v[k]:.3f}" for k in ORDER)
                             + f" | {v[best] / v['ours']:.2f}x vs {NAME[best]} |")
        lines.append("")
    lines += [] if not energy else ["## Energy breakdown core / SRAM / DRAM (uJ)", "",
              "| Network | Level | " + " | ".join(NAME[k] for k in ORDER) + " |", "|---|---|" + "---|" * len(ORDER)]
    for n in (nets if energy else []):
        for e in d[n]["levels"]:
            p = e["energy_J"]
            lines.append(f"| {n} | {e['level']} | " + " | ".join(
                "/".join(f"{p[k][x] * 1e6:,.1f}" for x in ("core", "sram", "dram")) for k in ORDER) + " |")
    open(os.path.join(R, f"prune_chain{TAG}.md"), "w").write("\n".join(lines) + "\n")


if __name__ == "__main__":
    mode, nets = sys.argv[1], sys.argv[2:] or list(NETS)
    if mode == "spikes":
        for n in nets:
            for lv in levels(n):
                spikes(n, lv)
    elif mode == "sim":
        sim(nets)
    elif mode == "plot":
        plot()
