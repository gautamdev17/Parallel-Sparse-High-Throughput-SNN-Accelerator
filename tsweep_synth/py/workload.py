"""
workload.py -- networks and synthetic sparse SNN tensors shared by every simulator in this folder.

Networks (CIFAR-10 shapes, 32x32 input):
  VGG16    : the exact layer list of cycle_compare.py in EnergySpeedupSim.zip (13 conv + 3 FC), so the
             LoAS number reproduces the zip (8,973,849 cycles).
  ResNet18 : the standard CIFAR ResNet18 (conv1 + 4 stages x 2 BasicBlocks + 3 1x1 downsample convs + FC).
             (current_arch/cycle_compare.py calls the 19-conv ResNet19 list "ResNet18"; that list is kept
             as "ResNet19" for reference.)

A layer is (name, C_in, C_out, k, stride, H_in) for conv and (name, C_in, C_out, 1, 1, 1) for FC.
GEMM view (im2col): M = C_out filters, K = C_in*k*k inputs, N = H_out*W_out*batch pixels.

Synthetic tensors (independent random, the same tensors are fed to every design):
  weights : int8, each non-zero with probability wd (non-zero values uniform in [-127,127] without 0)
  spikes  : T-bit spike train per input neuron (c,h,w,b). A neuron is non-silent with probability ns;
            a non-silent neuron fires each timestep with probability q, at least once (if the draw is
            all-zero one random timestep is set).

tsweep_synth copy: spike trains of any T (dtype uint8/16/32/64 by T; at T = 8 the draws and values are identical to
dac2027_sim/workload.py), dense_sums for any T, popcount().
"""
import numpy as np

T = 8


def _conv(name, ci, co, k, s, h):
    return (name, ci, co, k, s, h)


def vgg16_layers():
    L = []
    cfg = [(3, 64, 32), (64, 64, 32), (64, 128, 16), (128, 128, 16), (128, 256, 8), (256, 256, 8), (256, 256, 8),
           (256, 512, 4), (512, 512, 4), (512, 512, 4), (512, 512, 2), (512, 512, 2), (512, 512, 2)]
    names = ["b1c1", "b1c2", "b2c1", "b2c2", "b3c1", "b3c2", "b3c3", "b4c1", "b4c2", "b4c3", "b5c1", "b5c2", "b5c3"]
    for n, (ci, co, h) in zip(names, cfg):
        L.append(_conv(n, ci, co, 3, 1, h))
    L += [("fc1", 512, 4096, 1, 1, 1), ("fc2", 4096, 4096, 1, 1, 1), ("fc3", 4096, 10, 1, 1, 1)]
    return L


def resnet18_layers():
    L = [_conv("conv1", 3, 64, 3, 1, 32)]
    ci, h = 64, 32
    for stage, co in enumerate([64, 128, 256, 512], start=1):
        for blk in range(2):
            s = 2 if (stage > 1 and blk == 0) else 1
            L.append(_conv(f"l{stage}.{blk}.c1", ci, co, 3, s, h))
            ho = h // s
            L.append(_conv(f"l{stage}.{blk}.c2", co, co, 3, 1, ho))
            if s != 1 or ci != co:
                L.append(_conv(f"l{stage}.{blk}.ds", ci, co, 1, s, h))
            ci, h = co, ho
    L.append(("fc", 512, 10, 1, 1, 1))
    return L


def resnet19_layers():
    """the 19-conv list used as 'ResNet18' in current_arch/cycle_compare.py (all stride 1 there)."""
    cfg = [("conv0", 3, 64, 32)] + [(f"b1l{i}c{j}", 64, 64, 32) for i in (1, 2) for j in (1, 2)]
    cfg += [("b2l1c1", 64, 128, 16), ("b2l1c2", 128, 128, 16)] + [(f"b2l{i}c{j}", 128, 128, 16) for i in (2, 3) for j in (1, 2)]
    cfg += [("b3l1c1", 128, 256, 8), ("b3l1c2", 256, 256, 8)] + [(f"b3l{i}c{j}", 256, 256, 8) for i in (2, 3) for j in (1, 2)]
    cfg += [("b4l1c1", 256, 512, 4), ("b4l1c2", 512, 512, 4)]
    return [(n, ci, co, 3, 1, h) for n, ci, co, h in cfg] + [("fc", 512, 10, 1, 1, 1)]


def cifarnet_layers():
    """CifarNet of the PLIF paper (Fang et al., ICCV 2021): {{c256k3}*3-MP2}*2-FC2048-FC100 (then 10-way voting)."""
    L = [_conv(f"c{i}", 3 if i == 1 else 256, 256, 3, 1, 32) for i in (1, 2, 3)]
    L += [_conv(f"c{i}", 256, 256, 3, 1, 16) for i in (4, 5, 6)]
    return L + [("fc1", 256 * 8 * 8, 2048, 1, 1, 1), ("fc2", 2048, 100, 1, 1, 1)]


def resnet19_tdbn_layers():
    """ResNet-19 of tdBN (Zheng et al., AAAI 2021), CIFAR: c128, 3x Basic(128), 3x Basic(256, s2), 2x Basic(512, s2),
    FC256, FC10."""
    L = [_conv("conv1", 3, 128, 3, 1, 32)]
    ci, h = 128, 32
    for stage, (co, nb) in enumerate([(128, 3), (256, 3), (512, 2)], start=1):
        for blk in range(nb):
            s = 2 if (stage > 1 and blk == 0) else 1
            L.append(_conv(f"l{stage}.{blk}.c1", ci, co, 3, s, h))
            ho = h // s
            L.append(_conv(f"l{stage}.{blk}.c2", co, co, 3, 1, ho))
            if s != 1 or ci != co:
                L.append(_conv(f"l{stage}.{blk}.ds", ci, co, 1, s, h))
            ci, h = co, ho
    return L + [("fc1", 512, 256, 1, 1, 1), ("fc2", 256, 10, 1, 1, 1)]


def vggsnn_dvs_layers():
    """VGGSNN of TET (Deng et al., ICLR 2022) on DVS-CIFAR10 (2 x 48 x 48):
    64C3-128C3-AP2-256C3-256C3-AP2-512C3-512C3-AP2-512C3-512C3-AP2-FC10."""
    cfg = [(2, 64, 48), (64, 128, 48), (128, 256, 24), (256, 256, 24), (256, 512, 12), (512, 512, 12),
           (512, 512, 6), (512, 512, 6)]
    return [_conv(f"c{i + 1}", ci, co, 3, 1, h) for i, (ci, co, h) in enumerate(cfg)] + [("fc", 512 * 3 * 3, 10, 1, 1, 1)]


def resnet18_imagenet_layers():
    """the standard ImageNet ResNet-18 (224 x 224): c64k7s2, MP3s2, 4 stages x 2 BasicBlocks, FC1000."""
    L = [_conv("conv1", 3, 64, 7, 2, 224)]
    ci, h = 64, 56
    for stage, co in enumerate([64, 128, 256, 512], start=1):
        for blk in range(2):
            s = 2 if (stage > 1 and blk == 0) else 1
            L.append(_conv(f"l{stage}.{blk}.c1", ci, co, 3, s, h))
            ho = h // s
            L.append(_conv(f"l{stage}.{blk}.c2", co, co, 3, 1, ho))
            if s != 1 or ci != co:
                L.append(_conv(f"l{stage}.{blk}.ds", ci, co, 1, s, h))
            ci, h = co, ho
    return L + [("fc", 512, 1000, 1, 1, 1)]


def spikformer_8_384_layers():
    """Spikformer-8-384 on ImageNet (Zhou et al., ICLR 2023): SPS = 4 x (conv3x3 + max-pool 2) 3 -> 48 -> 96 -> 192 ->
    384 (224 -> 14) + RPE conv; 8 blocks of SSA (q, k, v, proj: 384 x 384) and MLP (384 -> 1536 -> 384) over the
    14 x 14 = 196 tokens, written as 1x1 convs on the 14 x 14 map; head FC1000. The spike-spike products of SSA
    (Q K^T, (Q K^T) V) have no stationary weight and are not part of the GEMM workload."""
    L = [_conv("sps0", 3, 48, 3, 1, 224), _conv("sps1", 48, 96, 3, 1, 112), _conv("sps2", 96, 192, 3, 1, 56),
         _conv("sps3", 192, 384, 3, 1, 28), _conv("rpe", 384, 384, 3, 1, 14)]
    for b in range(8):
        L += [_conv(f"b{b}.{n}", ci, co, 1, 1, 14) for n, ci, co in
              (("q", 384, 384), ("k", 384, 384), ("v", 384, 384), ("proj", 384, 384), ("fc1", 384, 1536),
               ("fc2", 1536, 384))]
    return L + [("head", 384, 1000, 1, 1, 1)]


NETWORKS = {"VGG16": vgg16_layers, "ResNet18": resnet18_layers, "ResNet19": resnet19_layers,
            "CifarNet": cifarnet_layers, "ResNet19-tdBN": resnet19_tdbn_layers, "VGGSNN-DVS": vggsnn_dvs_layers,
            "ResNet18-ImageNet": resnet18_imagenet_layers, "Spikformer-8-384": spikformer_8_384_layers}


def gemm_shape(layer, batch=1):
    name, ci, co, k, s, h = layer
    ho = h // s
    return co, ci * k * k, ho * ho * batch


def out_hw(layer):
    return layer[5] // layer[4]


def rand_weights(rng, M, K, wd):
    mag = rng.integers(1, 128, size=(M, K))
    sign = np.where(rng.random((M, K)) < 0.5, -1, 1)
    return (mag * sign * (rng.random((M, K)) < wd)).astype(np.int16)


def _train_dtype(T):
    """tsweep_synth: smallest unsigned type holding a T-bit train (uint8 at T <= 8, as before)."""
    return np.uint8 if T <= 8 else np.uint16 if T <= 16 else np.uint32 if T <= 32 else np.uint64


def _pack_trains(bits, T):
    """bits (..., T) bool -> T-bit trains (bit t = timestep t); identical to np.packbits(little)[..., 0] at T <= 8."""
    dt = _train_dtype(T)
    v = np.zeros(bits.shape[:-1], dtype=np.uint64)
    for t in range(T):
        v |= bits[..., t].astype(np.uint64) << np.uint64(t)
    return v.astype(dt)


def rand_spikes(rng, shape, ns, q, T=T):
    """T-bit spike trains (bit t = timestep t) for neurons of `shape` (tsweep_synth: any T <= 64, same RNG draws)."""
    dt = _train_dtype(T)
    bits = (rng.random(shape + (T,)) < q)
    v = _pack_trains(bits, T)
    active = rng.random(shape) < ns
    empty = active & (v == 0)
    v = np.where(empty, (np.uint64(1) << rng.integers(0, T, size=shape).astype(np.uint64)).astype(dt), v)
    return np.where(active, v, 0).astype(dt)


def rand_spikes_rate(rng, shape, p, T=T):
    """uint8 spike trains with every (neuron, timestep) firing independently with probability p (firing rate)."""
    bits = rng.random(shape + (T,), dtype=np.float32) < p
    return np.packbits(bits, axis=-1, bitorder="little")[..., 0].astype(np.uint8)


def layer_tensors_rate(layer, batch, wd, p, seed, T=T):
    """layer_tensors with i.i.d. spikes at firing rate p per timestep (instead of the non-silent / fire-probability
    model): W (M,K) with weight density wd and the im2col spike matrix S (K,N)."""
    rng = np.random.default_rng(seed)
    name, ci, co, k, s, h = layer
    M, K, N = gemm_shape(layer, batch)
    W = rand_weights(rng, M, K, wd)
    X = rand_spikes_rate(rng, (batch, ci, h, h), p, T)
    S = im2col(X, k, s) if k > 1 or s > 1 or h > 1 else X.reshape(batch, ci).T.copy()
    assert S.shape == (K, N)
    return W, S


def im2col(X, k, s):
    """X: (B, C, H, W) uint8 spike trains -> S: (C*k*k, B*Ho*Wo), zero padding k//2, row k=(c,kh,kw)."""
    B, C, H, W = X.shape
    p = k // 2
    Xp = np.pad(X, ((0, 0), (0, 0), (p, p), (p, p)))
    Ho, Wo = H // s, W // s
    cols = np.empty((C, k, k, B, Ho, Wo), dtype=X.dtype)
    for i in range(k):
        for j in range(k):
            cols[:, i, j] = Xp[:, :, i:i + s * Ho:s, j:j + s * Wo:s].transpose(1, 0, 2, 3)
    return cols.reshape(C * k * k, B * Ho * Wo)


def layer_tensors(layer, batch, wd, ns, q, seed, T=T):
    """the weights W (M,K) and im2col spike matrix S (K,N) of one layer, deterministic in `seed`."""
    rng = np.random.default_rng(seed)
    name, ci, co, k, s, h = layer
    M, K, N = gemm_shape(layer, batch)
    W = rand_weights(rng, M, K, wd)
    X = rand_spikes(rng, (batch, ci, h, h), ns, q, T)
    S = im2col(X, k, s) if k > 1 or s > 1 or h > 1 else X.reshape(batch, ci).T.copy()
    assert S.shape == (K, N)
    return W, S


def popcount8(x):
    return np.unpackbits(np.asarray(x, dtype=np.uint8)[..., None], axis=-1).sum(-1)


def popcount(x):
    """tsweep_synth: popcount of trains of any width."""
    x = np.asarray(x).astype(np.uint64)
    return sum(((x >> np.uint64(b)) & np.uint64(1)).astype(np.int64) for b in range(64))


def dense_sums(W, S, T=T):
    """reference: sums[m, n, t] = sum_k W[m,k] * bit_t(S[k,n])  (exact in float64 for these sizes)."""
    S = np.asarray(S).astype(np.uint64)
    Wf = W.astype(np.float64)
    out = np.empty((W.shape[0], S.shape[1], T), dtype=np.int64)
    for t in range(T):
        out[..., t] = np.rint(Wf @ ((S >> np.uint64(t)) & np.uint64(1)).astype(np.float64)).astype(np.int64)
    return out


def lif(sums, theta, leak=0.5):
    """the doc's neuron (Sec. 8): V = leak*V + x[t]; fire if V >= theta, then V -= theta. -> uint8 trains."""
    V = np.zeros(sums.shape[:-1])
    out = np.zeros(sums.shape[:-1], dtype=np.uint8)
    for t in range(sums.shape[-1]):
        V = leak * V + sums[..., t]
        f = V >= theta
        out |= (f.astype(np.uint8) << t)
        V = np.where(f, V - theta, V)
    return out
