"""
loas_plus.py -- LoAS+ : three micro-architecture changes to LoAS, evaluated on the same cycle model as
loas_model.py (16 TPPEs, 128-position chunks, 16 B/cycle weight bus, same mapping choice per layer).

LoAS per TPPE and chunk (loas_model.py):  load + join + (laggy + m + 1 if m > 0)      m = matches
  load = 1 (bitmasks) + ceil(nnz(fiber-B chunk) / BUS), join = 1, laggy = 8; a round of 16 TPPEs lasts its
  slowest TPPE (lock step on the broadcast fiber); +1 P-LIF cycle per output.

C1  prefix-free inner join.  Weights are static, so the offset of every non-zero inside its fiber is known
    offline; spike fibers are written by LoAS's own output compressor, which already runs a prefix sum. Both
    fibers therefore store a 7-bit base offset per 16-bit bitmask segment (8 x 7 = 56 bits per 128-chunk);
    a match's offset is base[seg] + popcount16(segment below the match). The fast prefix-sum (52 % of TPPE
    power, 67 % of TPPE area in LoAS Tbl. IV), the laggy prefix-sum, the pseudo-accumulator speculation,
    FIFO-mp/FIFO-B and the correction accumulators are all removed: the fiber-A value of a match is known one
    cycle after the match (cache latency), so the T gated accumulators add directly.
      compute = m + DRAIN      (if m > 0; DRAIN = 3, the pipeline of hw/rtl/loas_plus/tppe_plus.v)
C2  multi-match join.  Every 32-bit quarter of the AND result has its own priority encoder + popcount, so a
    TPPE retires one match per quarter per cycle (T lanes of 5-input gated adders; the offline packer stores each
    quarter's weights in its own 32 slots of the 128-B weight buffer, so each lane's weight mux is 32:1). Four
    fiber-A reads per TPPE per cycle (the global cache must serve 4 ports per TPPE).
      compute = max over quarters of m_q + DRAIN         (exactly the RTL: hw/tb/tb_loas_plus.v)
C3  decoupled, skipping chunk pipeline.
    a) chunk skip: a 1-bit "chunk non-empty" summary per fiber chunk. Weight chunks that are empty are never
       broadcast (mapping A); spike chunks that are empty are never broadcast (mapping B). If no TPPE matches,
       only the bitmask is broadcast (lazy value fetch).
    b) double buffering: the next chunk's bitmask/weights load while the TPPEs compute the current chunk.
    c) elastic TPPEs: each TPPE keeps a Q = 4 deep queue of broadcast chunks and runs at its own pace instead
       of in lock step; the broadcaster stalls only when some TPPE's queue is full.
  Recurrence (per block of 16 TPPEs, items i in stream order, TPPE j):
      b_i  = max(b_{i-1}, max_j f_{i-Q, j}) + bcast_i                 broadcast of item i complete
      f_ij = max(f_{i-1, j}, b_i) + c_ij           (lock step: max(max_j f_{i-1, j}, b_i) + c_ij)
  With Q = 1, lock step, bcast = load and c = 1 + compute it is exactly loas_model.py (checked by `check`).

  python3 loas_plus.py check     # engine == loas_model.py on random layers
  python3 loas_plus.py           # synthetic workloads (same tensors/seeds as loas_model.py) -> results/loas_plus.*
  ~/torch-env/bin/python loas_plus.py prep   # real spike trains (Prosperity traces, first 8 steps) -> results/real_trains.npz
  python3 loas_plus.py real      # real-spike workload (synthetic weights) -> results/loas_plus_real.*
"""
import json, os, sys, zlib
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import workload as wl
from loas_model import loas_layer_cycles_own, TPPES, CHUNK, LAGGY, BUS

NQ, DRAIN, QDEPTH = 4, 3, 4

VARIANTS = {   # name: (compute rule, double-buffered load, chunk skip, elastic queue depth or None = lock step)
    "LoAS":          ("orig", False, False, None),
    "LoAS-overlap":  ("orig", True, False, None),   # generous baseline: Sec. IV-C overlaps the next fiber-B fetch
    "+C1":           ("c1", False, False, None),
    "+C1+C2":        ("c2", False, False, None),
    "+C1+C2+C3":     ("c2", True, True, QDEPTH),    # LoAS+
}


def _chunk_stats(W, S, chunk):
    """per chunk: matches m (M, N), max matches in one quarter (M, N), weight non-zeros (M,), non-silent (N,)."""
    wnz, snz = (W != 0).astype(np.float32), (S != 0).astype(np.float32)
    q = chunk // NQ
    for c0 in range(0, W.shape[1], chunk):
        mq = [np.rint(wnz[:, a:a + q] @ snz[a:a + q, :]).astype(np.int64)
              for a in range(c0, min(c0 + chunk, W.shape[1]), q)]
        yield sum(mq), np.max(mq, axis=0), wnz[:, c0:c0 + chunk].sum(1).astype(np.int64), \
            snz[c0:c0 + chunk, :].sum(0).astype(np.int64)


def _compute(rule, m, mqmax):
    if rule == "orig":
        return np.where(m > 0, LAGGY + m + 1, 0)
    if rule == "c1":
        return np.where(m > 0, m + DRAIN, 0)
    return np.where(m > 0, mqmax + DRAIN, 0)


def _stream(bc, c, keep, Q, lockstep):
    """bc: (I, B) broadcast cycles, c: (I, B, P) TPPE cycles, keep: (I, B) item not skipped. -> total cycles."""
    I, B, P = c.shape
    if Q == 1 and lockstep:                           # fully serial: closed form
        return int(((bc + c.max(2)) * keep).sum())
    f = np.zeros((B, P), np.int64)
    b = np.zeros(B, np.int64)
    ring = np.zeros((Q, B), np.int64)                 # max_j f of the last Q kept items of each block
    cnt = np.zeros(B, np.int64)
    ar = np.arange(B)
    for i in range(I):
        k = keep[i]
        if not k.any():
            continue
        slot = cnt % Q
        nb = np.maximum(b, ring[slot, ar]) + bc[i]      # load starts when bus and buffer slot are free
        start = np.maximum(f.max(1), nb)[:, None] if lockstep else np.maximum(f, nb[:, None])
        f = np.where(k[:, None], start + c[i], f)
        b = np.where(k, nb, b)
        ring[slot, ar] = np.where(k, f.max(1), ring[slot, ar])
        cnt += k
    return int(f.max(1).sum())


def layer_cycles(W, S, variant, tppes=TPPES, chunk=CHUNK, bus=BUS):
    rule, ovl, skip, q = VARIANTS[variant]
    Q = (q or 2) if ovl else 1
    lockstep = q is None
    stats = list(_chunk_stats(W, S, chunk))
    nch = len(stats)
    M, N = W.shape[0], S.shape[1]
    best = None
    for axis in (1, 0):        # 1: 16 pixels share a weight fiber (A); 0: 16 channels share a spike fiber (B)
        R, C = (M, N) if axis == 1 else (N, M)        # R = streamed outer index, C = spread over TPPEs
        pad = (-C) % tppes
        nb = (C + pad) // tppes
        I = R * nch
        bc = np.zeros((I, nb), np.int64)
        c = np.zeros((I, nb, tppes), np.int64)
        keep = np.zeros((I, nb), bool)
        valid = np.concatenate([np.ones(C, bool), np.zeros(pad, bool)]).reshape(nb, tppes)
        for ci, (m, mqm, wnz, snz) in enumerate(stats):
            mm = m if axis == 1 else m.T                  # (R, C)
            load = 1 + -(-wnz // bus)                     # (M,) bitmask + weights of each channel's chunk
            comp = _compute(rule, mm, mqm if axis == 1 else mqm.T)
            mm_p = np.pad(mm, ((0, 0), (0, pad))).reshape(R, nb, tppes)
            comp_p = np.pad(comp, ((0, 0), (0, pad))).reshape(R, nb, tppes)
            last = 1 if ci == nch - 1 else 0              # P-LIF cycle on each output's last chunk
            if axis == 1:                                 # weight chunk of channel r broadcast to the block
                lr = load[:, None].repeat(nb, 1)
                if skip:  # skip empty weight chunks; bitmask only if nobody matches (lazy value fetch)
                    lr = np.where(mm_p.max(2) > 0, lr, np.where(wnz[:, None] > 0, 1, 0))
                    kp = (wnz[:, None] > 0).repeat(nb, 1) | (last == 1)
                else:
                    kp = np.ones((R, nb), bool)
                tp = 1 + comp_p
                bcast = lr
            else:                                         # spike chunk of pixel r broadcast; own weight chunks
                own = np.pad(load, (0, pad)).reshape(nb, tppes)[None]
                if skip:
                    own = np.where(np.pad(wnz, (0, pad)).reshape(nb, tppes)[None] > 0, own, 0)
                    kp = ((snz[:, None] > 0) | (last == 1)).repeat(nb, 1)
                else:
                    kp = np.ones((R, nb), bool)
                tp = np.maximum(own, 1 + comp_p) if ovl else own + 1 + comp_p
                bcast = np.zeros((R, nb), np.int64)
            tp = (tp + last) * valid[None]
            idx = np.arange(R) * nch + ci                 # stream order: outer index, then chunk
            bc[idx], c[idx], keep[idx] = bcast, tp, kp
        tot = _stream(bc, c, keep, Q, lockstep)
        best = tot if best is None else min(best, tot)
    return best


# ----------------------------------------------------------------------------------------------- workloads
WORK = {"sparse90": (0.10, 0.10, 0.3), "zipstats": (1.00, 0.261, 0.3)}


def check(n=12):
    rng = np.random.default_rng(1)
    for i in range(n):
        M, K, N = rng.integers(1, 70), rng.integers(1, 600), rng.integers(1, 70)
        W = wl.rand_weights(rng, M, K, rng.uniform(0.02, 1))
        S = wl.rand_spikes(rng, (K, N), rng.uniform(0.05, 1), 0.3)
        a, b = loas_layer_cycles_own(W, S), layer_cycles(W, S, "LoAS")
        assert a == b, (i, M, K, N, a, b)
        cyc = [layer_cycles(W, S, v) for v in VARIANTS]
        assert cyc[1] <= cyc[0] and cyc[2] <= cyc[0] and cyc[3] <= cyc[2], cyc
    print(f"[ok] engine == loas_model.py on {n} random layers; variants monotone")


def _table(rows, title):
    names = list(VARIANTS)
    out = [f"### {title}", "", "| Workload | Network | Batch | " + " | ".join(names) + " | LoAS+ vs LoAS | LoAS+ vs LoAS-overlap |",
           "|---|---|---|" + "---:|" * (len(names) + 2)]
    for key, cyc in rows.items():
        w, net, b = key.split("|")
        out.append(f"| {w} | {net} | {b} | " + " | ".join(f"{cyc[v]:,}" for v in names)
                   + f" | **{cyc['LoAS'] / cyc['+C1+C2+C3']:.2f}x** | **{cyc['LoAS-overlap'] / cyc['+C1+C2+C3']:.2f}x** |")
    return out


def synthetic():
    rows, per_layer = {}, {}
    for w, (wd, ns, q) in WORK.items():
        for net in ("VGG16", "ResNet18"):
            for b in (1, 16):
                tot = {v: 0 for v in VARIANTS}
                for li, layer in enumerate(wl.NETWORKS[net]()):
                    seed = zlib.crc32(f"{net}|{li}|{b}|{wd}|{ns}|{q}".encode())
                    W, S = wl.layer_tensors(layer, b, wd, ns, q, seed)
                    cyc = {v: layer_cycles(W, S, v) for v in VARIANTS}
                    per_layer[f"{w}|{net}|{b}|{layer[0]}"] = cyc
                    for v in VARIANTS:
                        tot[v] += cyc[v]
                rows[f"{w}|{net}|{b}"] = tot
                print(f"{w:9s} {net:8s} b{b:<2d} " + "  ".join(f"{v} {tot[v]:,}" for v in VARIANTS)
                      + f"   LoAS+ {tot['LoAS'] / tot['+C1+C2+C3']:.2f}x", flush=True)
    json.dump({"totals": rows, "layers": per_layer}, open(os.path.join(HERE, "results", "loas_plus.json"), "w"), indent=1)
    md = _table(rows, "Cycles (800 MHz), synthetic tensors of loas_model.py, T = 8")
    open(os.path.join(HERE, "results", "loas_plus.md"), "w").write("\n".join(md) + "\n")
    print("\n".join(md))


# ------------------------------------------------------------------------------------------ real spikes
REAL = os.path.join(HERE, "results", "real_trains.npz")


def prep():
    """needs torch: Prosperity's traces (T = 32, batch 1) -> first 8 steps as uint8 trains per layer input."""
    import pickle, importlib.util
    spec = importlib.util.spec_from_file_location("pcfg", os.path.join(HERE, "third_party", "prosperity", "configs.py"))
    pcfg = importlib.util.module_from_spec(spec); spec.loader.exec_module(pcfg)
    out = {}
    for net, cfg in (("VGG16", pcfg.vgg16_config()), ("ResNet18", pcfg.resnet18_config())):
        d = pickle.load(open(os.path.join(HERE, "third_party", "prosperity_data", f"{net.lower()}_cifar10.pkl"), "rb"))
        for key, v in cfg.items():
            if not (key.startswith("conv2d") or key.startswith("fc")) or key not in d:
                continue
            x = d[key][:8].numpy().astype(np.uint8)
            tr = np.zeros(x.shape[1:], np.uint8)
            for t in range(8):
                tr |= x[t] << t
            out[f"{net}|{key}|trains"] = tr
            out[f"{net}|{key}|shape"] = np.array(v[:6] if key.startswith("conv2d") else [v[0], v[1]])
    np.savez_compressed(REAL, **out)
    print("wrote", REAL, len(out) // 2, "layers")


def real_layers(net):
    z = np.load(REAL)
    keys = sorted({k.split("|")[1] for k in z.files if k.startswith(net + "|")},
                  key=lambda s: (not s.startswith("conv"), int(s.split("_")[1])))
    for key in keys:
        tr, sh = z[f"{net}|{key}|trains"], z[f"{net}|{key}|shape"]
        if key.startswith("conv2d"):
            H, ci, co, k, p, s = (int(a) for a in sh)
            assert tr.shape == (ci, H, H), (key, tr.shape, sh)
            S = wl.im2col(tr[None], k, s) if k > 1 else tr.reshape(ci, -1)
            yield key, co, S
        else:
            yield key, int(sh[1]), tr.reshape(-1, 1)


def real(wds=(0.10, 0.02)):
    rows = {}
    for wd in wds:
        for net in ("VGG16", "ResNet18"):
            tot = {v: 0 for v in VARIANTS}
            for key, co, S in real_layers(net):
                rng = np.random.default_rng(zlib.crc32(f"real|{net}|{key}|{wd}".encode()))
                W = wl.rand_weights(rng, co, S.shape[0], wd)
                for v in VARIANTS:
                    tot[v] += layer_cycles(W, S, v)
            rows[f"real-spikes wd={wd}|{net}|1"] = tot
            print(f"wd={wd} {net:8s} " + "  ".join(f"{v} {tot[v]:,}" for v in VARIANTS)
                  + f"   LoAS+ {tot['LoAS'] / tot['+C1+C2+C3']:.2f}x", flush=True)
    json.dump(rows, open(os.path.join(HERE, "results", "loas_plus_real.json"), "w"), indent=1)
    md = _table(rows, "Cycles, real spike trains (Prosperity CIFAR-10 traces, first 8 steps), synthetic weights")
    open(os.path.join(HERE, "results", "loas_plus_real.md"), "w").write("\n".join(md) + "\n")
    print("\n".join(md))


if __name__ == "__main__":
    cmd = sys.argv[1] if len(sys.argv) > 1 else "synthetic"
    {"check": check, "synthetic": synthetic, "prep": prep, "real": real}[cmd]()
