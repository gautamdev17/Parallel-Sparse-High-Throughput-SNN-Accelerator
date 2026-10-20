"""
qcfs_vgg16.py -- the lab's pruned QCFS VGG-16 (SNN-QCFS-Pruning, DepGraph group_sl, L = 8, CIFAR-10) run as an SNN on
this Mac with INT8 weights: test accuracy, and per-layer traces (binary input spike trains + INT8 weights).

Everything comes from ~/SNN-QCFS-Pruning, unchanged: the pruned checkpoint pruned/final_cifar10_vgg16_group_sl.pth
({model, masks}), and test_quantize.py's own pipeline -- apply_masks, fold_all_batchnorms, swap_to_quant,
calibrate_all, export_integer_weights -- in the same order as its __main__ (which saves the same INT8 weights to
pruned/quantized_cifar10_vgg16_group_sl_int8.pth but only evaluates at T = 0). The model is then switched to SNN mode
(set_T) and forward hooks record the input of every conv / linear layer. CIFAR-10 test set from ~/LoAS/dataset.

  python qcfs_vgg16.py acc  [n_images] [T]   -> accuracy on the first n test images (default all 10000, T = 16)
  python qcfs_vgg16.py dump [n_images] [T]   -> results/qcfs_vgg16_cifar10_T{T}.npz + _meta.json (default 16 images)

Trace format (same as nf_vgg16.py; one entry per conv / linear layer, in order):
  W   INT8 weights (M, K), K ordered (c, kh, kw); scale[li] = the layer's dequantization scale (w = W x scale)
  X   spike trains of the layer's input, bit t = timestep t (uint16 for T = 16): (B, C, H, W) conv, (B, C) linear.
      The repo's IF neuron outputs spike x theta, so spike = (input != 0); the first layer's input is the image.
  P   for a layer right after an AvgPool(2): the binary spike trains BEFORE the pool, (B, C, 2H, 2W)
  meta  name, kind, ci, co, k, s, h, analog, nonbinary, weight_density, nonsilent, bit_density, theta of the IF
        neuron that produced the input
"""
import os, sys, json, time
import numpy as np
import torch

REPO = os.path.expanduser("~/SNN-QCFS-Pruning")
HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(os.path.dirname(HERE), "results")
CKPT = os.path.join(REPO, "pruned", "final_cifar10_vgg16_group_sl.pth")
DATA = os.path.expanduser("~/LoAS/dataset")
L = 8

sys.path.insert(0, REPO)


def build():
    """test_quantize.py's __main__ pipeline, step for step (masks, BN fold, INT8 weights)."""
    import test_quantize as TQ
    ck = torch.load(CKPT, map_location="cpu", weights_only=False)
    model, masks = ck["model"], ck["masks"]
    model.set_L(L)
    model.set_T(0)
    TQ.apply_masks(model, masks)
    model.eval()
    TQ.fold_all_batchnorms(model)
    TQ.swap_to_quant(model, n_bits=8)
    TQ.calibrate_all(model)
    TQ.apply_masks(model, masks)
    return model.eval(), TQ


def loader(n, bs):
    from torchvision import datasets, transforms
    trans = transforms.Compose([transforms.ToTensor(),       # = Preprocess/getdataloader.py GetCifar10 test transform
                                transforms.Normalize((0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010))])
    ds = datasets.CIFAR10(DATA, train=False, transform=trans, download=False)
    ds = torch.utils.data.Subset(ds, range(min(n, len(ds))))
    return torch.utils.data.DataLoader(ds, batch_size=bs, shuffle=False, num_workers=0)


def acc(n, T):
    torch.set_num_threads(os.cpu_count())
    model, _ = build()
    model.set_T(T)
    correct = total = 0
    t0 = time.time()
    with torch.no_grad():
        for x, y in loader(n, 100):
            out = model(x).mean(0)
            correct += int((out.argmax(1) == y).sum())
            total += len(y)
            if total % 1000 == 0 or total == n:
                print(f"{total:5d} images  acc {100 * correct / total:.2f}%  ({time.time() - t0:.0f}s)", flush=True)
    res = dict(images=total, accuracy=100 * correct / total, T=T, L=L, weights="INT8 (test_quantize.py pipeline)")
    json.dump(res, open(os.path.join(OUT, f"qcfs_vgg16_cifar10_T{T}_acc.json"), "w"), indent=1)
    print(res)


def bits(nz, T):
    """(T, ...) bool -> (...) packed trains, bit t = timestep t."""
    X = np.zeros(nz.shape[1:], np.uint16 if T > 8 else np.uint8)
    for t in range(T):
        X |= (nz[t].astype(X.dtype) << t)
    return X


def dump(n, T):
    model, TQ = build()
    payload = TQ.export_integer_weights(model)
    model.set_T(T)
    thetas = [float(m.thresh) for m in model.modules() if type(m).__name__ == "IF"]
    layers, rec, events = [], [], []
    for name, m in model.named_modules():
        if isinstance(m, (TQ.QuantConv2d, TQ.QuantLinear)):
            layers.append((name, m))
            def hook(mod, inp, out, name=name):
                rec.append((name, inp[0].detach()))
                events.append(("lin", name))
            m.register_forward_hook(hook)
        elif isinstance(m, torch.nn.AvgPool2d):
            def phook(mod, inp, out, name=name):
                events.append(("pool", name, inp[0].detach()))
            m.register_forward_hook(phook)
    x, y = next(iter(loader(n, n)))
    with torch.no_grad():
        out = model(x).mean(0)
    B = x.shape[0]
    prepool = {}
    for i, e in enumerate(events):                    # the pool event right before a linear layer
        if e[0] == "lin" and i > 0 and events[i - 1][0] == "pool":
            prepool[e[1]] = events[i - 1][2]
    store, meta = {}, []
    for li, ((name, m), (rn, xin)) in enumerate(zip(layers, rec)):
        assert name == rn
        conv = isinstance(m, TQ.QuantConv2d)
        q = payload[name]["w_int"]
        W = q.reshape(q.shape[0], -1).numpy()
        if li == 0:                                   # the image itself (B, C, H, W), not spikes
            X, nonbin = xin.numpy(), None
        else:
            xt = xin.reshape(T, B, *xin.shape[1:])     # merged (T*B) -> (T, B, ...)
            nz = (xt != 0).numpy()
            vals = xt[xt != 0]
            nonbin = float(((vals - vals.max()).abs() > 1e-6 * vals.max().abs()).float().mean()) if vals.numel() else 0.0
            X = bits(nz, T)
        k = m.weight.shape[-1] if conv else 1
        meta.append(dict(name=name, kind="conv" if conv else "fc", ci=int(xin.shape[1]), co=int(W.shape[0]), k=int(k),
                         s=int(m.stride[0]) if conv else 1, h=int(xin.shape[-1]) if conv else 1, analog=li == 0,
                         nonbinary=nonbin, theta_in=None if li == 0 else thetas[li - 1],
                         weight_density=float((W != 0).mean()),
                         nonsilent=None if li == 0 else float((X != 0).mean()),
                         bit_density=None if li == 0 else float(np.mean([(X >> t) & 1 for t in range(T)]))))
        store[f"W{li}"] = W
        store[f"scale{li}"] = np.float32(payload[name]["scale"])
        store[f"X{li}"] = X
        if name in prepool:
            pt = prepool[name].reshape(T, B, *prepool[name].shape[1:])
            nzv = pt[pt != 0]
            assert ((nzv - nzv.max()).abs() < 1e-6 * pt.abs().max()).all(), "pre-pool not binary"
            store[f"P{li}"] = bits((pt != 0).numpy(), T)
            meta[-1]["pooled"] = True
    tag = f"qcfs_vgg16_cifar10_T{T}"
    np.savez_compressed(os.path.join(OUT, tag + ".npz"), **store)
    json.dump(dict(images=B, T=T, L=L, labels=y.tolist(), pred=out.argmax(1).tolist(), layers=meta),
              open(os.path.join(OUT, tag + "_meta.json"), "w"), indent=1)
    for m_ in meta:
        print({k: (round(v, 4) if isinstance(v, float) else v) for k, v in m_.items()})


if __name__ == "__main__":
    mode = sys.argv[1]
    n = int(sys.argv[2]) if len(sys.argv) > 2 else (10000 if mode == "acc" else 16)
    T = int(sys.argv[3]) if len(sys.argv) > 3 else 16
    {"acc": acc, "dump": dump}[mode](n, T)
