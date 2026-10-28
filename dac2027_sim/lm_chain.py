"""
lm_chain.py -- every accelerator on NeuroFlex's transformer / language models (BERT, ViT-B, GPT-2 XL, OPT-6.7B), swept
over WEIGHT sparsity, with the activations produced by running one input sample through the spiking network layer
by layer (each layer's input spikes are the previous layer's output spikes), not set by hand. No downloads: the
weights are synthetic.

Model (per sweep point): one dense INT8 model per network (magnitudes uniform 1..127, random signs, seeded per
(network, block, GEMM)), magnitude-pruned to the weight sparsity of the point (nested masks: the same model, pruned
further). Spiking transformer block, T = 8 timesteps. Every spiking neuron SN is BatchNorm (each channel standardised over
tokens and timesteps; inference form, statistics of the sample) followed by the neuron of Spikformer / Spike-driven
Transformer: SpikingJelly LIFNode, tau = 2 (a leak of 1/2, as the paper's LIF), threshold 1, hard reset. Block structure
of the Spike-driven Transformer (Yao et al., NeurIPS 2023): membrane shortcut (the residual stream u stays a current,
spikes are generated from it) and spike-driven self-attention SDSA = Q (x) SN(sum over tokens of K (x) V):
    x  = SN(u)                                     block input spikes (N tokens)
    q | k | v = SN(W_qkv x)
    z  = q (x) SN(sum_n k (x) v)                   per channel and timestep; z is a spike map
    u  = u + W_proj z
    x1 = SN(u)
    h  = SN(W_fc1 x1)
    u  = u + W_fc2 h
Input sample: a random embedding
(N x d, standard normal; ViT: 196 patches + CLS), spiked by the same SN.

Simulated: the four weight GEMMs (qkv, proj, fc1, fc2) with their actual input spikes of every block for BERT and
ViT-B (12 blocks), and of 4 evenly spaced blocks (first ... last) for GPT-2 XL and OPT-6.7B, scaled to all blocks
(LMC_BLOCKS=0: every block); on every design
(the same simulators as lm_sweep.py / the main results). The attention products, the embedding and the head are not
simulated (no stationary weight / outside the blocks).

  <python with torch, pandas, networkx> lm_chain.py spikes [model ...]   -> results/lm_chain/<model>_<ws>.npz
  <python ...> lm_chain.py sim [model ...]                                -> results/lm_chain.json (cached per GEMM)
  LMC_REAL=1 <python ...> lm_chain.py all BERT   -> BERT on a real sentence (SENTENCE, BERT's own WordPiece vocabulary
      and embedding, third_party/bert-base-uncased from huggingface.co/bert-base-uncased) -> results/lm_chain_real*
"""
import json, os, sys, time, zlib
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
R = os.path.join(HERE, "results")
REAL = os.environ.get("LMC_REAL") == "1"                  # BERT: a real sentence through BERT's real embedding
TAGR = ("_real_long" if os.environ.get("LMC_TEXT") else "_real") if REAL else ""
BN_FROZEN = os.environ.get("LMC_BN") == "frozen"          # BN statistics of the dense model, reused when pruned
TAGR += "_bnfrozen" if BN_FROZEN else ""
_BN = dict(mode="sample", stats=[], i=0)                   # sample: statistics of the current pass; record / use
SD = os.path.join(R, f"lm_chain{TAGR}")
OUT = os.path.join(R, f"lm_chain{TAGR}.json")
CACHE = os.path.join(R, f"lm_chain{TAGR}_cache.json")
BERT_DIR = os.path.join(HERE, "third_party", "bert-base-uncased")    # vocab.txt + model.safetensors (huggingface)
SENTENCE = os.environ.get("LMC_TEXT") or ("Sparse spiking neural networks can run language models on small edge "
                                          "devices while keeping the energy of every inference low.")


def bert_tokens(text):
    """BERT uncased WordPiece: lower-case, split on whitespace and punctuation, greedy longest-match sub-words,
    [CLS] ... [SEP]. -> token ids."""
    import unicodedata
    vocab = {w.rstrip("\n"): i for i, w in enumerate(open(os.path.join(BERT_DIR, "vocab.txt"), encoding="utf-8"))}
    text = "".join(c for c in unicodedata.normalize("NFD", text.lower()) if unicodedata.category(c) != "Mn")
    words, cur = [], ""
    for c in text:
        if c.isspace() or unicodedata.category(c).startswith("P"):
            if cur:
                words.append(cur)
            cur = ""
            if not c.isspace():
                words.append(c)
        else:
            cur += c
    if cur:
        words.append(cur)
    ids = [vocab["[CLS]"]]
    for w in words:
        start, pieces = 0, []
        while start < len(w):
            end = len(w)
            while end > start and (("##" if start else "") + w[start:end]) not in vocab:
                end -= 1
            if end == start:
                pieces = [vocab["[UNK]"]]
                break
            pieces.append(vocab[("##" if start else "") + w[start:end]])
            start = end
        ids += pieces
    return ids + [vocab["[SEP]"]]


def bert_embedding(text):
    """BERT's real input embedding of `text`: word + position + token-type (0), then the embedding LayerNorm.
    -> (768, N) float32 and the token ids. Reads model.safetensors directly (header JSON + raw float32)."""
    import struct
    ids = bert_tokens(text)
    f = open(os.path.join(BERT_DIR, "model.safetensors"), "rb")
    n = struct.unpack("<Q", f.read(8))[0]
    hdr, base = json.loads(f.read(n)), 8 + n

    def tensor(name):
        e = hdr[name]
        a, b = e["data_offsets"]
        f.seek(base + a)
        return np.frombuffer(f.read(b - a), np.float32).reshape(e["shape"])

    E = (tensor("bert.embeddings.word_embeddings.weight")[ids] + tensor("bert.embeddings.position_embeddings.weight")
         [:len(ids)] + tensor("bert.embeddings.token_type_embeddings.weight")[0])
    mu, var = E.mean(-1, keepdims=True), E.var(-1, keepdims=True)
    E = (E - mu) / np.sqrt(var + 1e-12) * tensor("bert.embeddings.LayerNorm.gamma") + tensor("bert.embeddings.LayerNorm.beta")
    return E.T.astype(np.float32), ids
T, TAU, VTH = 8, 2.0, 1.0
WGT_SPARSITY = tuple(float(x) for x in os.environ.get("LMC_WS", "0.25,0.40,0.60,0.75,0.90").split(","))
MODELS = {"BERT": (768, 3072, 12, 128, 12), "ViT-B": (768, 3072, 12, 197, 12),
          "GPT-2 XL": (1600, 6400, 48, 128, 25), "OPT-6.7B": (4096, 16384, 32, 128, 32)}   # d, h, blocks, N, heads
DESIGNS = ("ptb", "spikex", "loas", "sato", "spikeflow", "prosperity", "ours")


def gemms(d, h):
    return [("qkv", 3 * d, d), ("proj", d, d), ("fc1", h, d), ("fc2", d, h)]


def pruned_weights(model, blk, g, M, K, ws):
    """the dense INT8 weights of (model, block, GEMM), magnitude-pruned to sparsity ws (ties broken at random)."""
    rng = np.random.default_rng(zlib.crc32(f"lmchain|{model}|{blk}|{g}".encode()))
    mag = rng.integers(1, 128, size=(M, K), dtype=np.int16)
    key = mag + rng.random((M, K), dtype=np.float32)             # magnitude + tie-break
    sign = np.where(rng.random((M, K), dtype=np.float32) < 0.5, -1, 1).astype(np.int16)
    keep = int(round((1.0 - ws) * M * K))
    if keep < M * K:
        cut = np.partition(key.ravel(), M * K - keep)[M * K - keep]
        mag = np.where(key >= cut, mag, 0).astype(np.int16)
    return mag * sign


def bn(cur):
    """BatchNorm before every spiking neuron: standardise each channel (axis 0) over tokens and timesteps. With
    LMC_BN=frozen, the statistics are those of the DENSE model on the sample (recorded once, in call order) and are
    reused for every pruned model, as inference BN keeps its running statistics; pruning then lowers the currents
    and fewer neurons fire."""
    c = cur.reshape(cur.shape[0], -1)
    if _BN["mode"] == "use":
        mu, sd = _BN["stats"][_BN["i"]]
        _BN["i"] += 1
    else:
        mu, sd = c.mean(1), c.std(1) + 1e-6
        if _BN["mode"] == "record":
            _BN["stats"].append((mu, sd))
    return ((c - mu[:, None]) / sd[:, None]).reshape(cur.shape).astype(np.float32)


def lif(cur):
    """BN then the spiking neuron of Spikformer / Spike-driven Transformer (SpikingJelly LIFNode, tau = 2,
    v_threshold = 1, hard reset to 0): H = V + (X - V) / tau, spike if H >= 1. cur (..., T) -> uint8 trains."""
    X = bn(cur)
    V = np.zeros(X.shape[:-1], np.float32)
    out = np.zeros(X.shape[:-1], np.uint8)
    for t in range(T):
        H = V + (X[..., t] - V) / TAU
        f = H >= VTH
        out |= (f.astype(np.uint8) << t)
        V = np.where(f, 0.0, H)
    return out


def bits(S):
    """uint8 trains (K, N) -> float32 (T, K, N) 0/1."""
    return ((S[None] >> np.arange(T, dtype=np.uint8)[:, None, None]) & 1).astype(np.float32)


def gemm_cur(W, S):
    """W (M, K) int, S (K, N) trains -> currents (M, N, T)."""
    B = bits(S)                                                   # (T, K, N)
    K, N = S.shape
    C = W.astype(np.float32) @ B.transpose(1, 0, 2).reshape(K, T * N)   # (M, T*N)
    return C.reshape(W.shape[0], T, N).transpose(0, 2, 1)


def ssa(q, k, v, heads):
    """spike self-attention currents: per head and timestep (q_t k_t^T) v_t; q, k, v (d, N) trains -> (d, N, T)."""
    d, N = q.shape
    dh = d // heads
    Q, Kb, Vb = bits(q), bits(k), bits(v)                        # (T, d, N)
    out = np.empty((d, N, T), np.float32)
    for hd in range(heads):
        sl = slice(hd * dh, (hd + 1) * dh)
        for t in range(T):
            A = Q[t, sl].T @ Kb[t, sl]                            # (N, N)
            out[sl, :, t] = (A @ Vb[t, sl].T).T                   # (dh, N)
    return out


def sdsa(q, k, v):
    """spike-driven self-attention: z[c, n, t] = q[c, n, t] AND SN_t(sum_n k[c, n, t] v[c, n, t]) (spike map)."""
    kv = (bits(k) * bits(v)).sum(axis=2)                          # (T, d): sum over tokens
    g = lif(kv.T[:, None, :])[:, 0]                               # (d,) trains: one spike vector per channel
    return q & g[:, None]


def spikes(model, ws):
    """run the sample through the pruned network; -> {f'{blk}:{g}': input trains (K, N)} and per-layer densities."""
    d, h, L, N, heads = MODELS[model]
    rng = np.random.default_rng(zlib.crc32(f"lmchain|{model}|sample".encode()))
    if REAL and model == "BERT":
        emb, _ = bert_embedding(SENTENCE)                         # (768, N), N = tokens of the real sentence
        N = emb.shape[1]
    else:
        emb = rng.standard_normal((d, N)).astype(np.float32)
    u = np.repeat(emb[..., None], T, axis=-1)                     # residual stream (membrane shortcut), (d, N, T)
    ins, dens = {}, {}
    for blk in range(L):
        W = {g: pruned_weights(model, blk, g, M, K, ws) for g, M, K in gemms(d, h)}
        x = lif(u)
        ins[f"{blk}:qkv"] = x
        qkv = lif(gemm_cur(W["qkv"], x))
        q, k, v = qkv[:d], qkv[d:2 * d], qkv[2 * d:]
        z = sdsa(q, k, v)
        ins[f"{blk}:proj"] = z
        u = u + gemm_cur(W["proj"], z)
        x1 = lif(u)
        ins[f"{blk}:fc1"] = x1
        hh = lif(gemm_cur(W["fc1"], x1))
        ins[f"{blk}:fc2"] = hh
        u = u + gemm_cur(W["fc2"], hh)
        for g in ("qkv", "proj", "fc1", "fc2"):
            S = ins[f"{blk}:{g}"]
            dens[f"{blk}:{g}"] = dict(nonsilent=float((S != 0).mean()), bit=float(bits(S).mean()))
    return ins, dens


def run_spikes(models):
    os.makedirs(SD, exist_ok=True)
    for m in models:
        for ws in WGT_SPARSITY:
            f = os.path.join(SD, f"{m.replace(' ', '_')}_{ws:.2f}.npz")
            if os.path.exists(f):
                continue
            t0 = time.time()
            if BN_FROZEN:
                _BN.update(mode="record", stats=[], i=0)
                spikes(m, 0.0)                                         # dense model: its BN statistics
                _BN.update(mode="use", i=0)
            ins, dens = spikes(m, ws)
            _BN.update(mode="sample")
            np.savez_compressed(f, **{k.replace(":", "_"): v for k, v in ins.items()})
            json.dump(dens, open(f.replace(".npz", "_dens.json"), "w"), indent=1)
            ns = [v["nonsilent"] for v in dens.values()]
            print(f"{m:9s} ws={ws:.2f} spikes in {time.time() - t0:.0f}s | input non-silent mean {np.mean(ns):.3f} "
                  f"(min {min(ns):.3f}, max {max(ns):.3f})", flush=True)


def task(t):
    model, ws, blk, g, M, K = t
    import baselines as ob
    from ours import Cfg, run_layer_fast
    from loas_model import loas_layer_cycles_own
    import prosperity_official as P
    from lm_sweep import fc_op
    import contextlib, io
    pb = sys.modules["p_baselines"]
    W = pruned_weights(model, blk, g, M, K, ws)
    S = np.load(os.path.join(SD, f"{model.replace(' ', '_')}_{ws:.2f}.npz"))[f"{blk}_{g}"]
    N = S.shape[1]
    t0 = time.time()
    r = dict(ours=int(run_layer_fast(W, S, __import__("ours").Cfg(T=T))["cycles"]),
             spikex=int(ob.spikex_layer_cycles(S, M, T=T, tws_list=(1, 2, 4, 8))[0]),
             spikeflow=int(ob.spikeflow_layer_cycles(S, M, T=T)),
             loas=int(loas_layer_cycles_own(W, S)))
    with contextlib.redirect_stdout(io.StringIO()):
        lif_op = lambda: P.NW.LIFNeuron(f"lif_{g}", M * N, 1, T)
        r["prosperity"] = int(P.run_model_ops([fc_op(P, g, S, M), lif_op()], f"{model}_{blk}_{g}_{ws}"))
        r["sato"] = int(pb.run_sato_conv_fc(fc_op(P, g, S, M)).compute_cycles + pb.run_sato_lif(lif_op()).compute_cycles)
        Sp = np.pad(S, ((0, 0), (0, -N % 8))) if N % 8 else S        # official PTB folds the sequence into 8 rows
        r["ptb"] = int(pb.run_simulation_PTB([fc_op(P, g, Sp, M), lif_op()]).total_cycles)
    r.update(weight_density=float((W != 0).mean()), nonsilent=float((S != 0).mean()), secs=round(time.time() - t0, 1))
    return t, r


def sim_blocks(L):
    """blocks whose GEMMs are simulated: all for <= 12 blocks, else NB evenly spaced (first ... last); the spikes of
    every block still come from the full layer-by-layer forward pass."""
    nb = int(os.environ.get("LMC_BLOCKS", "4"))
    return list(range(L)) if L <= 12 or nb <= 0 else sorted(set(np.linspace(0, L - 1, nb).round().astype(int).tolist()))


def run_sim(models):
    todo = []
    for m in models:
        d, h, L, N, _ = MODELS[m]
        for ws in WGT_SPARSITY:
            for blk in sim_blocks(L):
                for g, M, K in gemms(d, h):
                    todo.append((m, ws, blk, g, M, K))
    cache = json.load(open(CACHE)) if os.path.exists(CACHE) else {}
    res = {t: cache[repr(t)] for t in todo if repr(t) in cache}
    todo = [t for t in todo if t not in res]
    todo.sort(key=lambda t: (list(MODELS).index(t[0]), -t[4] * t[5]))      # small models first, big GEMMs first
    t0 = time.time()
    with Pool(min(8, os.cpu_count())) as pool:
        for i, (t, r) in enumerate(pool.imap_unordered(task, todo)):
            res[t] = r
            cache[repr(t)] = r
            json.dump(cache, open(CACHE, "w"))
            print(f"[{i + 1}/{len(todo)}] {t[0]:9s} ws={t[1]:.2f} b{t[2]:2d} {t[3]:4s} ns={r['nonsilent']:.3f} | "
                  + " ".join(f"{k} {r[k]:,}" for k in DESIGNS) + f" | {r['secs']}s ({time.time() - t0:.0f}s)", flush=True)
    out = json.load(open(OUT)) if os.path.exists(OUT) else {}
    for m in models:
        d, h, L, N, heads = MODELS[m]
        sb = sim_blocks(L)
        if REAL and m == "BERT":
            N = len(bert_tokens(SENTENCE))
        out[m] = dict(d=d, h=h, blocks=L, tokens=N, heads=heads, T=T, simulated_blocks=sb, points={},
                      **({"input": SENTENCE} if REAL and m == "BERT" else {}))
        for ws in WGT_SPARSITY:
            per = {f"{b}:{g}": res[(m, ws, b, g, M, K)] for b in sb for g, M, K in gemms(d, h)}
            tot = {k: sum(v[k] for v in per.values()) * L / len(sb) for k in DESIGNS}   # scaled to all blocks
            ns = float(np.mean([v["nonsilent"] for v in per.values()]))
            out[m]["points"][f"{ws:.2f}"] = dict(cycles=tot, mean_nonsilent=ns, gemms=per)
    json.dump(out, open(OUT, "w"), indent=1)


if __name__ == "__main__":
    mode, models = sys.argv[1], (sys.argv[2:] or list(MODELS))
    if mode in ("spikes", "all"):
        run_spikes(models)
    if mode in ("sim", "all"):
        run_sim(models)
