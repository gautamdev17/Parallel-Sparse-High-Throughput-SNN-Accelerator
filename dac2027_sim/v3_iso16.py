"""
v3_iso16.py -- version 3: every design with 16 PEs. Batch-1 latency and batch-16 throughput, VGG16 / ResNet18,
workload sparse90 (and zipstats), T=8, 800 MHz. Real numbers and normalized to LoAS = 1x.

  .../venv/bin/python v3_iso16.py        -> results/v3_iso16.json, results/v3_iso16_tables.md, results/v3_*.png

Per design at 16 PEs (only the PE count is changed, every other rule as in v1):
  Ours        4 x 4 PEs (unchanged; each PE has T=8 adders)                       -> results/main.json 'ours'
  LoAS        16 TPPEs (unchanged; each TPPE has T accumulators), zip closed form -> results/main.json 'loas_zip'
  PTB         2 x 8 PEs: the Prosperity repo's run_PTB_convfc with the 16 output-channel rows set to 2
              (repeat count ceil(M/2), cold start 2 x 2 cycles per pixel); 8 columns, TWS=4, StSAP, DRAM, LIF as is
  SATO        16 PEs: the Prosperity repo's run_sato_conv_fc with 128 PEs set to 16
  Prosperity  official simulator with a 16-adder array (tile n = 16); tiles m=256, k=16 unchanged
  SpikeX      4 x 4 PEs (4 output-channel rows, 4 NTWU columns), best of mode x TWS, long-T model of paper_checks
  SpikeFlow   4 x 4 PEs (4 output-channel rows, PCD = 4): T=8 > PCD, so the time domain is split into two chunks
              of 4 timesteps ('Partial Silence Cell', Sec. 4.1/4.2); an input is skipped per (pixel, chunk) if silent
NOTE: a PE is not the same unit in every design. Ours and LoAS have T=8 adders per PE, the others one adder per PE,
so at 16 PEs Ours and LoAS have 128 adders and the other five 16. The equal-adder comparison is v1.
"""
import inspect, json, math, os, sys, textwrap, zlib
from multiprocessing import Pool
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import prosperity_official as PO          # official Prosperity simulator (+ PTB/SATO models), isolated import
import workload as wl
import paper_checks as PC

R = os.path.join(HERE, "results")
F_HZ = 800e6
NPE = 16
WORKLOADS = {"sparse90": (0.10, 0.10, 0.3), "zipstats": (1.00, 0.261, 0.3)}

# ---- official PTB / SATO with only the PE count changed (same code, constants edited)
_pb = sys.modules["p_baselines"]
_src = textwrap.dedent(inspect.getsource(_pb.run_PTB_convfc))
assert "ceil_a_by_b(output_dim, 16)" in _src and "num_cold_start * 16 * 2" in _src
_src = _src.replace("ceil_a_by_b(output_dim, 16)", "ceil_a_by_b(output_dim, 2)").replace(
    "num_cold_start * 16 * 2", "num_cold_start * 2 * 2").replace("def run_PTB_convfc", "def run_PTB_convfc_16pe")
exec(compile(_src, "<run_PTB_convfc_16pe>", "exec"), _pb.__dict__)
_s2 = textwrap.dedent(inspect.getsource(_pb.run_sato_conv_fc))
assert "torch.zeros(128" in _s2
_s2 = _s2.replace("torch.zeros(128", "torch.zeros(16").replace("def run_sato_conv_fc", "def run_sato_conv_fc_16pe")
exec(compile(_s2, "<run_sato_conv_fc_16pe>", "exec"), _pb.__dict__)


def ptb16(ops):
    tot = 0
    for op in ops:
        if isinstance(op, (PO.NW.Conv2D, PO.NW.FC)):
            tot += _pb.run_PTB_convfc_16pe(op).total_cycles
        elif isinstance(op, PO.NW.LIFNeuron):
            tot += _pb.run_PTB_lif(op).total_cycles
    return tot


def sato16(ops):
    tot = 0
    for op in ops:
        if isinstance(op, (PO.NW.Conv2D, PO.NW.FC)):
            tot += _pb.run_sato_conv_fc_16pe(op).total_cycles
        elif isinstance(op, PO.NW.LIFNeuron):
            tot += _pb.run_sato_lif(op).total_cycles
    return tot


def prosperity16(ops, name):
    import contextlib, io
    acc = PO.Accelerator(type="Prosperity", adder_array_size=NPE, LIF_array_size=32, tile_size_M=256,
                         tile_size_K=16, product_sparsity=True, issue_type=2, dense=False)
    PO.S.clear_global_stats()
    sim = PO.S.Simulator(accelerator=acc, network=ops, benchmark_name=name, use_cuda=False)
    with contextlib.redirect_stdout(io.StringIO()):
        return sim.sim().total_cycles


# ---- our-model baselines at 4 x 4
def spikeflow_chunked(S, M, T=8, rows=4, pcd=4):
    """SpikeFlow with T > PCD: ceil(T/PCD) time chunks per pixel, inputs skipped when silent in that chunk."""
    K, N = S.shape
    cyc = 0
    for c0 in range(0, T, pcd):
        mask = ((1 << min(pcd, T - c0)) - 1) << c0
        cyc += int(((S & mask) != 0).sum())
    return math.ceil(M / rows) * cyc + rows + pcd - 2


def spikex16(S, M, T=8):
    X = ((S[:, :, None] >> np.arange(T)[None, None, :]) & 1).astype(bool)      # K, N, T
    return PC.spikex_long(X, M, rows=4, cols=4, tws_list=[1, 2, 4, 8])[0]


def layer_task(t):
    net, li, b, w = t
    wd, ns, q = WORKLOADS[w]
    layer = wl.NETWORKS[net]()[li]
    M, K, N = wl.gemm_shape(layer, b)
    seed = zlib.crc32(f"{net}|{li}|{b}|{wd}|{ns}|{q}".encode())
    _, S = wl.layer_tensors(layer, b, wd, ns, q, seed)
    return t, dict(spikex=spikex16(S, M), spikeflow=spikeflow_chunked(S, M))


def net_task(t):
    import contextlib, io
    kind, net, b, img, w = t
    wd, ns, q = WORKLOADS[w]
    with contextlib.redirect_stdout(io.StringIO()):
        if kind == "ptb":
            return t, ptb16(PO.ptb_ops_image(net, b, img, wd, ns, q))
        if kind == "sato":
            return t, sato16(PO.our_ops(net, b, wd, ns, q))
        return t, prosperity16(PO.our_ops(net, b, wd, ns, q), f"{net}_{b}_{w}")


def main():
    main_c = json.load(open(os.path.join(R, "main.json")))
    path = os.path.join(R, "v3_iso16.json")
    cache = json.load(open(path)) if os.path.exists(path) else {}
    nets = ("VGG16", "ResNet18")
    lt = [(n, li, b, w) for w in WORKLOADS for n in nets for li in range(len(wl.NETWORKS[n]())) for b in (1, 16)
          if f"L|{n}|{li}|{b}|{w}" not in cache]
    nt = []
    for w in WORKLOADS:
        for n in nets:
            for b in (1, 16):
                for kind in ("sato", "prosperity"):
                    if f"N|{kind}|{n}|{b}|{w}" not in cache:
                        nt.append((kind, n, b, 0, w))
                nt += [("ptb", n, b, img, w) for img in range(b) if f"P|{n}|{b}|{img}|{w}" not in cache]
    print(f"{len(lt)} layer tasks, {len(nt)} network tasks", flush=True)
    with Pool(os.cpu_count()) as p:
        for t, r in p.imap_unordered(layer_task, lt):
            cache["L|" + "|".join(map(str, t))] = r
        json.dump(cache, open(path, "w"))
        for t, c in p.imap_unordered(net_task, nt):
            kind, n, b, img, w = t
            cache[f"P|{n}|{b}|{img}|{w}" if kind == "ptb" else f"N|{kind}|{n}|{b}|{w}"] = int(c)
            json.dump(cache, open(path, "w"))
            print(" done", t, f"{c:,}", flush=True)
    # ---- totals
    tot = {}
    for w in WORKLOADS:
        for n in nets:
            nl = len(wl.NETWORKS[n]())
            for b in (1, 16):
                tot[f"{w}|{n}|{b}|ours"] = sum(main_c[f"{n}|{li}|{b}|{w}"]["ours"] for li in range(nl))
                tot[f"{w}|{n}|{b}|loas_zip"] = sum(main_c[f"{n}|{li}|{b}|{w}"]["loas_zip"] for li in range(nl))
                for d in ("spikex", "spikeflow"):
                    tot[f"{w}|{n}|{b}|{d}"] = sum(cache[f"L|{n}|{li}|{b}|{w}"][d] for li in range(nl))
                for d in ("sato", "prosperity"):
                    tot[f"{w}|{n}|{b}|{d}"] = cache[f"N|{d}|{n}|{b}|{w}"]
                tot[f"{w}|{n}|{b}|ptb"] = sum(cache[f"P|{n}|{b}|{img}|{w}"] for img in range(b))
    json.dump(tot, open(os.path.join(R, "v3_iso16_totals.json"), "w"), indent=1)
    report(tot)


ORDER = ["loas_zip", "spikex", "ptb", "sato", "spikeflow", "prosperity", "ours"]
LAB = {"loas_zip": "LoAS (16 TPPE)", "spikex": "SpikeX (4x4)", "ptb": "PTB (2x8)", "sato": "SATO (16 PE)",
       "spikeflow": "SpikeFlow (4x4)", "prosperity": "Prosperity (16 PE)", "ours": "Ours (4x4)"}


def report(tot):
    lines = []
    for w in WORKLOADS:
        lines += [f"### v3: all designs with 16 PEs, workload `{w}` (T=8, 800 MHz)", "",
                  "| Network | Design | Latency b=1 (ms) | Speed-up vs LoAS | Throughput b=16 (img/s) | Throughput vs LoAS |",
                  "|---|---|---:|---:|---:|---:|"]
        for n in ("VGG16", "ResNet18"):
            l0 = tot[f"{w}|{n}|1|loas_zip"] / F_HZ
            t0 = 16 * F_HZ / tot[f"{w}|{n}|16|loas_zip"]
            for d in ORDER:
                lat = tot[f"{w}|{n}|1|{d}"] / F_HZ
                thr = 16 * F_HZ / tot[f"{w}|{n}|16|{d}"]
                lines.append(f"| {n} | {LAB[d]} | {lat*1e3:.3f} | {l0/lat:.2f}x | {thr:,.0f} | {thr/t0:.2f}x |")
        lines.append("")
    lines.append("PE = 8 adders for Ours and LoAS, 1 adder for the others: at 16 PEs Ours and LoAS have 128 adders, "
                 "the others 16. The equal-adder (128) comparison is v1 (main_tables.md).")
    open(os.path.join(R, "v3_iso16_tables.md"), "w").write("\n".join(lines) + "\n")
    print("\n".join(lines))
    plots(tot)


def plots(tot):
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    COL = {"loas_zip": "#2a78d6", "spikex": "#eb6834", "ptb": "#1baf7a", "ours": "#eda100", "prosperity": "#e87ba4",
           "sato": "#008300", "spikeflow": "#6250d6"}
    INK, INK2, GRID = "#0b0b0b", "#52514e", "#e4e3df"
    plt.rcParams.update({"font.family": "serif", "font.size": 9, "axes.edgecolor": INK2, "axes.labelcolor": INK,
                         "xtick.color": INK2, "ytick.color": INK2, "axes.spines.top": False, "axes.spines.right": False})
    nets = ["VGG16", "ResNet18"]
    w = "sparse90"
    for norm in (False, True):
        fig, axes = plt.subplots(1, 2, figsize=(7.2, 3.5))
        for ax, metric in zip(axes, ("lat", "thr")):
            bw = 0.11
            for i, d in enumerate(ORDER):
                x = np.arange(2) + (i - 3) * (bw + 0.012)
                v = []
                for n in nets:
                    lat = tot[f"{w}|{n}|1|{d}"] / F_HZ * 1e3
                    thr = 16 * F_HZ / tot[f"{w}|{n}|16|{d}"]
                    if norm:
                        l0 = tot[f"{w}|{n}|1|loas_zip"] / F_HZ * 1e3
                        t0 = 16 * F_HZ / tot[f"{w}|{n}|16|loas_zip"]
                        v.append(l0 / lat if metric == "lat" else thr / t0)
                    else:
                        v.append(lat if metric == "lat" else thr)
                ax.bar(x, v, bw, color=COL[d], label=LAB[d], zorder=3)
                for xi, vi in zip(x, v):
                    s = f"{vi:.1f}x" if norm else (f"{vi:.2f}" if metric == "lat" else f"{vi:,.0f}")
                    ax.text(xi, vi, s, ha="center", va="bottom", fontsize=5.5, color=INK, rotation=90)
            if norm:
                ax.axhline(1, color=INK2, lw=0.8, ls="--", zorder=2)
            ax.set_xticks(range(2), nets)
            ax.set_ylabel({("lat", False): "Latency, batch 1 (ms)", ("thr", False): "Throughput, batch 16 (img/s)",
                           ("lat", True): "Speed-up over LoAS, batch 1 (x)",
                           ("thr", True): "Throughput over LoAS, batch 16 (x)"}[(metric, norm)])
            ax.yaxis.grid(True, color=GRID, lw=0.6, zorder=0)
            ax.set_ylim(0, ax.get_ylim()[1] * 1.15)
        h, l = axes[0].get_legend_handles_labels()
        fig.legend(h, l, fontsize=6.5, frameon=False, loc="lower center", ncol=4)
        fig.suptitle("v3: 16 PEs in every design" + (", normalized to LoAS = 1x" if norm else "") +
                     ". Weights & activations 90% sparse, T=8, 800 MHz", fontsize=8, color=INK2)
        fig.tight_layout(rect=(0, 0.11, 1, 1))
        fig.savefig(os.path.join(R, "v3_latency_throughput" + ("_normalized" if norm else "") + ".png"), dpi=300)


if __name__ == "__main__":
    main()
