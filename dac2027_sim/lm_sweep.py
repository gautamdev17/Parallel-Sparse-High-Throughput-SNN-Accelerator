"""
lm_sweep.py -- every accelerator on the transformer / language models of NeuroFlex (BERT, ViT-B, GPT-2 XL,
OPT-6.7B), swept over activation sparsity as NeuroFlex's Fig. 10 (25, 40, 60, 75, 90 %), synthetic tensors.

Per transformer block, the four weight GEMMs W (M x K, INT8) x S (K x N spike trains, N = tokens of one sequence):
  qkv  M = 3d, K = d      proj  M = d, K = d      fc1  M = h, K = d      fc2  M = d, K = h
The attention products Q K^T and A V multiply two spike matrices (no stationary weight) and are left out, as are
the embedding and the classifier / LM head. Blocks of a model are identical in shape and the tensors are i.i.d., so
each GEMM is simulated once per sparsity point and its cycles are multiplied by the number of blocks.

  model     d      h      blocks  tokens
  BERT      768    3072   12      128     (BERT-base, GLUE-length sequence)
  ViT-B     768    3072   12      197     (ViT-B/16, 224 x 224 image: 196 patches + CLS)
  GPT-2 XL  1600   6400   48      128
  OPT-6.7B  4096   16384  32      128

PTB only: the official model folds the sequence into 8 rows, so ViT-B's 197 tokens are padded with 3 silent tokens.

Tensors: workload.rand_weights / rand_spikes (the generator of the main results): weight sparsity 90 % (density
0.10), activation sparsity s = fraction of silent spike trains (non-silent 1 - s), per-timestep fire probability 0.3,
T = 8; seeded per (model, GEMM, sparsity).

Designs (the same models as the main results and realtraces/run_real.py):
  TIDES      ours.run_layer_fast (cycle model, RTL-verified)
  PTB, SATO  official Prosperity-repo models (FC operator + LIF)
  Prosperity official Prosperity simulator (FC operator + LIF)
  SpikeX, SpikeFlow  baselines.py;   LoAS  loas_model.py

  <python with torch, pandas, networkx> lm_sweep.py [model ...]   -> results/lm_sweep.json (merged per model)
  LM_SWEEP=wgt <python> lm_sweep.py   -> results/lm_sweep_wgt.json: weight sparsity 25 .. 90 % at activation
                                         sparsity 90 % (points keyed by weight sparsity)
"""
import contextlib, io, json, os, sys, time, zlib
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
R = os.path.join(HERE, "results")
SWEEP = os.environ.get("LM_SWEEP", "act")                 # act: activation sparsity; wgt: weight sparsity
SFX = "" if SWEEP == "act" else "_wgt"
OUT = os.path.join(R, f"lm_sweep{SFX}.json")
CACHE = os.path.join(R, f"lm_sweep{SFX}_cache.json")        # one entry per finished GEMM (resume after a crash)
T, WD, Q = 8, 0.10, 0.3
TWS = (1, 2, 4, 8)
ACT_SPARSITY = (0.25, 0.40, 0.60, 0.75, 0.90)
WGT_SPARSITY = (0.25, 0.40, 0.60, 0.75, 0.90)               # LM_SWEEP=wgt, at activation sparsity ACT_FIXED
ACT_FIXED = 0.90
MODELS = {"BERT": (768, 3072, 12, 128), "ViT-B": (768, 3072, 12, 197), "GPT-2 XL": (1600, 6400, 48, 128),
          "OPT-6.7B": (4096, 16384, 32, 128)}
DESIGNS = ("ptb", "spikex", "loas", "sato", "spikeflow", "prosperity", "ours")


def gemms(d, h):
    return [("qkv", 3 * d, d), ("proj", d, d), ("fc1", h, d), ("fc2", d, h)]


def tensors(model, gname, M, K, N, sp, wd=WD):
    import workload as wl
    rng = np.random.default_rng(zlib.crc32(f"lm|{model}|{gname}|{wd}|{sp}|{Q}|T{T}".encode()))
    W = wl.rand_weights(rng, M, K, wd)
    S = wl.rand_spikes(rng, (K, N), 1.0 - sp, Q, T)
    return W, S


def fc_op(P, name, S, M):
    """official FC operator with the trains S (K x N) as its T x N x K spike map (as in run_real.py)."""
    import torch
    K, N = S.shape
    bits = ((S[None] >> np.arange(T)[:, None, None]) & 1).astype(bool)
    act = torch.from_numpy(bits.transpose(0, 2, 1).copy())
    op = P.NW.FC(name, K, M, N, 1, T)
    op.activation_tensor.sparse_map = act.reshape(1, T, N, K).float()
    return op


def task(t):
    model, sp, gname, M, K, N = t[:6]
    wd = t[6] if len(t) > 6 else WD                          # weight density (LM_SWEEP=wgt)
    import baselines as ob                      # ours, imported before the official repo's module of that name
    from ours import Cfg, run_layer_fast
    from loas_model import loas_layer_cycles_own
    import prosperity_official as P
    pb = sys.modules["p_baselines"]
    W, S = tensors(model, gname, M, K, N, sp, wd)
    t0 = time.time()
    r = dict(ours=int(run_layer_fast(W, S, Cfg(T=T))["cycles"]),
             spikex=int(ob.spikex_layer_cycles(S, M, T=T, tws_list=TWS)[0]),
             spikeflow=int(ob.spikeflow_layer_cycles(S, M, T=T)),
             loas=int(loas_layer_cycles_own(W, S)))
    with contextlib.redirect_stdout(io.StringIO()):
        lif = lambda: P.NW.LIFNeuron(f"lif_{gname}", M * N, 1, T)
        r["prosperity"] = int(P.run_model_ops([fc_op(P, gname, S, M), lif()], f"{model}_{gname}_{sp}_{wd}"))
        r["sato"] = int(pb.run_sato_conv_fc(fc_op(P, gname, S, M)).compute_cycles
                        + pb.run_sato_lif(lif()).compute_cycles)
        # the official PTB model folds the sequence into 8 rows (reshape [8, -1, K]): pad with silent tokens
        Sp = np.pad(S, ((0, 0), (0, -N % 8))) if N % 8 else S
        r["ptb"] = int(pb.run_simulation_PTB([fc_op(P, gname, Sp, M), lif()]).total_cycles)
    r.update(weight_density=float((W != 0).mean()), nonsilent=float((S != 0).mean()), secs=round(time.time() - t0, 1))
    return t, r


def main():
    models = sys.argv[1:] or list(MODELS)
    out = json.load(open(OUT)) if os.path.exists(OUT) else {}
    # a sweep point -> (activation sparsity, weight density); the activation sweep keeps its 6-field task keys
    pts = ([(sp, None) for sp in ACT_SPARSITY] if SWEEP == "act"
           else [(ACT_FIXED, round(1.0 - ws, 2)) for ws in WGT_SPARSITY])
    key = lambda m, sp, wd, g, M, K, N: (m, sp, g, M, K, N) if wd is None else (m, sp, g, M, K, N, wd)
    todo = []
    for m in models:
        d, h, L, N = MODELS[m]
        for sp, wd in pts:
            for g, M, K in gemms(d, h):
                todo.append(key(m, sp, wd, g, M, K, N))
    todo.sort(key=lambda t: -t[3] * t[4])        # largest GEMMs first
    cache = json.load(open(CACHE)) if os.path.exists(CACHE) else {}
    res = {t: cache[repr(t)] for t in todo if repr(t) in cache}
    todo = [t for t in todo if t not in res]
    t0 = time.time()
    with Pool(min(8, os.cpu_count())) as pool:
        for t, r in pool.imap_unordered(task, todo):
            res[t] = r
            cache[repr(t)] = r
            json.dump(cache, open(CACHE, "w"))
            print(f"{t[0]:9s} s={t[1]:.2f} wd={t[6] if len(t) > 6 else WD:.2f} {t[2]:5s} M{t[3]:6d} K{t[4]:6d} N{t[5]:4d} | "
                  + " ".join(f"{k} {r[k]:,}" for k in DESIGNS) + f" | {r['secs']}s ({time.time() - t0:.0f}s)",
                  flush=True)
    for m in models:
        d, h, L, N = MODELS[m]
        out[m] = dict(d=d, h=h, blocks=L, tokens=N, sweep=SWEEP, q=Q, T=T, points={},
                      **({"weight_density": WD} if SWEEP == "act" else {"act_sparsity": ACT_FIXED}))
        for sp, wd in pts:
            per = {g: res[key(m, sp, wd, g, M, K, N)] for g, M, K in gemms(d, h)}
            tot = {k: L * sum(per[g][k] for g in per) for k in DESIGNS}
            x = sp if SWEEP == "act" else 1.0 - wd                  # the swept sparsity
            out[m]["points"][f"{x:.2f}"] = dict(cycles=tot, gemms=per)
    json.dump(out, open(OUT, "w"), indent=1)
    for m in models:
        print(m, {sp: {k: round(v["cycles"]["ptb"] / v["cycles"][k], 2) for k in DESIGNS}
                  for sp, v in out[m]["points"].items()})


if __name__ == "__main__":
    main()
