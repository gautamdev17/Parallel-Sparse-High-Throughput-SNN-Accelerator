"""
nf_vgg16.py -- NeuroFlex's INT8 PASCAL VGG-16 (CIFAR-10, T = L = 8) run on this Mac: test accuracy, and per-layer
traces for the accelerator simulators (binary input spike trains + INT8 weights of every conv / linear layer).

Uses the NeuroFlex artifact unchanged (~/NeuroFlex_Code_weights: PASCALMODEL, quantize.load_quantized_checkpoint and
test_pascal_quantize's threshold rescaling); the only edit there is PASCALMODEL/layer.py line 107 (device=0 ->
device=x.device) so it runs without CUDA. CIFAR-10 test set from ~/LoAS/dataset (the official python batches).

  python nf_vgg16.py acc [n_images]   -> accuracy on the first n test images (default all 10000)
  python nf_vgg16.py dump [n_images]  -> results/real_vgg16_cifar10.npz (default 16 images)

Trace format (one entry per conv / linear layer, in order):
  W   INT8 weights, (M, K), K ordered (c, kh, kw) like workload.im2col
  X   uint8 spike trains of the layer's input, bit t = timestep t: (B, C, H, W) for conv, (B, C) for linear
      (spike = input != 0; inputs right after an AvgPool are multi-level -- those are recorded as a spike when
      non-zero and their share is reported as 'nonbinary')
  meta  name, kind, ci, co, k, s, h, analog (first layer: the image, not spikes), nonbinary fraction
  P   for a layer right after an AvgPool(2): the binary spike trains BEFORE the pool, (B, C, 2H, 2W). The pooled
      input is then exactly (1/4) x the sum of 4 binary spikes, so the layer equals a binary-spike layer with
      4x the inputs and each weight repeated 4x (the 1/4 folded into the threshold) -- see realtraces/traces.py
"""
import os, sys, json, time
import numpy as np
import torch

NF = os.path.expanduser("~/NeuroFlex_Code_weights")
HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(os.path.dirname(HERE), "results")
CKPT = os.path.join(NF, "checkpoints/vgg16/Quantized_vgg16_8_cifar10.pth")
DATA = os.path.expanduser("~/LoAS/dataset")
T = 8

sys.argv_saved = list(sys.argv)
sys.path.insert(0, NF)
os.chdir(NF)


def build():
    from PASCALMODEL.utils import modelpool
    from quantize import load_quantized_checkpoint
    model = modelpool("vgg16", "cifar10")
    model = load_quantized_checkpoint(model, CKPT, map_location="cpu")
    # = test_pascal_quantize.rescale_thresholds(model, 'vgg16', T, cpu)
    levels = torch.FloatTensor([T] * 50)
    skip = {'layer1.0.weight', 'layer1.0.bias', 'layer1.1.running_mean', 'layer1.1.bias'}
    sd = model.state_dict()
    i = 0
    for k in list(sd.keys()):
        if (k.endswith('bias') or k.endswith('running_mean')) and k not in skip:
            sd[k] = torch.div(sd[k].double(), levels[i])
            i += 1
    model.load_state_dict(sd, strict=False)
    return model.float().eval()


def loader(n, bs):
    from torchvision import datasets, transforms
    trans = transforms.Compose([transforms.ToTensor(),
                                transforms.Normalize((0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010))])
    ds = datasets.CIFAR10(DATA, train=False, transform=trans, download=False)
    ds = torch.utils.data.Subset(ds, range(min(n, len(ds))))
    return torch.utils.data.DataLoader(ds, batch_size=bs, shuffle=False, num_workers=0)


def acc(n):
    torch.set_num_threads(os.cpu_count())
    model = build()
    correct = total = 0
    t0 = time.time()
    with torch.no_grad():
        for x, y in loader(n, 100):
            out = model(x).mean(0)
            correct += int((out.argmax(1) == y).sum())
            total += len(y)
            print(f"{total:5d} images  acc {100 * correct / total:.2f}%  ({time.time() - t0:.0f}s)", flush=True)
    res = dict(images=total, accuracy=100 * correct / total, T=T)
    json.dump(res, open(os.path.join(OUT, "real_vgg16_cifar10_acc.json"), "w"), indent=1)
    print(res)


def dump(n):
    from quantize import QuantConv2d, QuantLinear
    model = build()
    layers, rec, events = [], [], []
    for name, m in model.named_modules():
        if isinstance(m, (QuantConv2d, QuantLinear)):
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
        conv = isinstance(m, QuantConv2d)
        q = m.qweight.to(torch.int8)
        W = q.reshape(q.shape[0], -1).numpy()
        if li == 0:                                   # the image itself (B, C, H, W), not spikes
            X = xin.numpy()
            nonbin = None
        else:
            xt = xin.reshape(T, B, *xin.shape[1:])     # merged (T*B) -> (T, B, ...)
            nz = (xt != 0).numpy()
            vals = xt[xt != 0]
            nonbin = float(((vals - vals.max()).abs() > 1e-6 * vals.max().abs()).float().mean()) if vals.numel() else 0.0
            X = np.zeros(nz.shape[1:], np.uint8)
            for t in range(T):
                X |= (nz[t].astype(np.uint8) << t)
        k = m.qweight.shape[-1] if conv else 1
        s = m.stride[0] if conv else 1
        h = xin.shape[-1] if conv else 1
        ci = xin.shape[1]
        meta.append(dict(name=name, kind="conv" if conv else "fc", ci=int(ci), co=int(W.shape[0]), k=int(k),
                         s=int(s), h=int(h), analog=li == 0, nonbinary=nonbin,
                         weight_density=float((W != 0).mean()),
                         nonsilent=None if li == 0 else float((X != 0).mean()),
                         bit_density=None if li == 0 else float(np.unpackbits(X[..., None], axis=-1).mean())))
        store[f"W{li}"] = W
        store[f"X{li}"] = X
        if name in prepool:
            pt = prepool[name].reshape(T, B, *prepool[name].shape[1:])
            pnz = (pt != 0).numpy()
            assert ((pt[pt != 0] - pt[pt != 0].max()).abs() < 1e-6 * pt.abs().max()).all(), "pre-pool not binary"
            P = np.zeros(pnz.shape[1:], np.uint8)
            for t in range(T):
                P |= (pnz[t].astype(np.uint8) << t)
            store[f"P{li}"] = P
            meta[-1]["pooled"] = True
    np.savez_compressed(os.path.join(OUT, "real_vgg16_cifar10.npz"), **store)
    json.dump(dict(images=B, labels=y.tolist(), pred=out.argmax(1).tolist(), layers=meta),
              open(os.path.join(OUT, "real_vgg16_cifar10_meta.json"), "w"), indent=1)
    for m_ in meta:
        print(m_)


if __name__ == "__main__":
    mode = sys.argv_saved[1]
    n = int(sys.argv_saved[2]) if len(sys.argv_saved) > 2 else (10000 if mode == "acc" else 16)
    {"acc": acc, "dump": dump}[mode](n)
