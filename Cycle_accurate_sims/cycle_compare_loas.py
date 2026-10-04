"""
Closed-Form Cycle Comparison: LoAS (fast+laggy, QCFS sparsity)
                          vs  Ours/LEDSA (laggy+laggy, PASC sparsity)
======================================================================

Closed-form expressions per 128-element vector chunk:
  - LoAS  (fast + laggy): cycles = N_matches + 21
  - Ours  (laggy + laggy): cycles = N_matches + 14

Where N_matches = number of non-silent neurons (fire at least once across T
timesteps), driven directly by the measured Combined Sparsity (%) figures:

    SNN        Prec.   T     QCFS (%)   PASC (%)
    ResNet18   INT8    4     79.12      80.68
    ResNet18   INT8    8     75.05      77.87
    ResNet18   INT8    16    72.73      75.84
    ResNet18   INT4    4     86.07      85.90
    ResNet18   INT4    8     83.37      83.86
    ResNet18   INT4    16    81.87      82.41
    ResNet18   Mixed   8     78.79      80.60
    VGG16      INT8    4     78.40      78.37
    VGG16      INT8    8     74.38      74.87
    VGG16      INT8    16    72.08      72.53
    VGG16      INT4    4     84.84      85.01
    VGG16      INT4    8     82.15      82.66
    VGG16      INT4    16    80.66      80.95
    VGG16      Mixed   8     77.78      78.20
    AlexNet    INT8    4     79.59      81.23
    AlexNet    INT8    8     76.05      79.60
    AlexNet    INT8    16    73.98      77.63
    AlexNet    INT4    4     85.57      86.60
    AlexNet    INT4    8     83.16      85.42
    AlexNet    INT4    16    81.77      83.94
    AlexNet    Mixed   8     79.37      82.20

LoAS uses QCFS sparsity, Ours (LEDSA) uses PASC sparsity.
non_silent_prob = 1 - combined_sparsity

16 TPPEs in parallel, chunk size = 128.
"""

import math
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

# ============================================================
# CONSTANTS
# ============================================================
CHUNK_SIZE    = 128
NUM_TPPES     = 16
CLOCK_MHZ     = 800          # LoAS uses 800 MHz (from paper)
CLOCK_PERIOD  = 1.0 / CLOCK_MHZ   # μs per cycle

# LoAS closed-form overhead constants
LOAS_OVERHEAD  = 21   # fast+laggy overhead per chunk (QCFS sparsity)
OURS_OVERHEAD  = 14   # laggy+laggy overhead per chunk (PASC sparsity)

# ============================================================
# SPARSITY TABLE (Combined Sparsity %, from measured results)
# ============================================================
# key: (network, precision, T) -> (QCFS %, PASC %)
SPARSITY_TABLE = {
    ("ResNet18", "INT8", 4):  (79.12, 80.68),
    ("ResNet18", "INT8", 8):  (75.05, 77.87),
    ("ResNet18", "INT8", 16): (72.73, 75.84),
    ("ResNet18", "INT4", 4):  (86.07, 85.90),
    ("ResNet18", "INT4", 8):  (83.37, 83.86),
    ("ResNet18", "INT4", 16): (81.87, 82.41),
    ("ResNet18", "Mixed", 8): (78.79, 80.60),

    ("VGG16", "INT8", 4):  (78.40, 78.37),
    ("VGG16", "INT8", 8):  (74.38, 74.87),
    ("VGG16", "INT8", 16): (72.08, 72.53),
    ("VGG16", "INT4", 4):  (84.84, 85.01),
    ("VGG16", "INT4", 8):  (82.15, 82.66),
    ("VGG16", "INT4", 16): (80.66, 80.95),
    ("VGG16", "Mixed", 8): (77.78, 78.20),

    ("AlexNet", "INT8", 4):  (79.59, 81.23),
    ("AlexNet", "INT8", 8):  (76.05, 79.60),
    ("AlexNet", "INT8", 16): (73.98, 77.63),
    ("AlexNet", "INT4", 4):  (85.57, 86.60),
    ("AlexNet", "INT4", 8):  (83.16, 85.42),
    ("AlexNet", "INT4", 16): (81.77, 83.94),
    ("AlexNet", "Mixed", 8): (79.37, 82.20),
}

# ============================================================
# NETWORK ARCHITECTURES
# ============================================================
# Each layer: (name, C_in, C_out, KH, KW, OH, OW)

def get_alexnet_layers():
    """AlexNet CIFAR-adapted (as used in LoAS paper): 7 conv + 1 FC"""
    return [
        ("conv1",    3,   64,   3,  3,  32,  32),
        ("conv2",   64,   192,  3,  3,  16,  16),
        ("conv3",  192,   384,  3,  3,   8,   8),
        ("conv4",  384,   256,  3,  3,   8,   8),
        ("conv5",  256,   256,  3,  3,   4,   4),
        ("fc1",    256,  1024,  1,  1,   1,   1),
        ("fc2",   1024,   512,  1,  1,   1,   1),
        ("fc3",    512,    10,  1,  1,   1,   1),
    ]

def get_vgg16_layers():
    """VGG16 CIFAR-adapted (as used in LoAS paper): 14 conv + 3 FC"""
    return [
        ("b1c1",   3,  64, 3, 3, 32, 32),
        ("b1c2",  64,  64, 3, 3, 32, 32),
        ("b2c1",  64, 128, 3, 3, 16, 16),
        ("b2c2", 128, 128, 3, 3, 16, 16),
        ("b3c1", 128, 256, 3, 3,  8,  8),
        ("b3c2", 256, 256, 3, 3,  8,  8),
        ("b3c3", 256, 256, 3, 3,  8,  8),
        ("b4c1", 256, 512, 3, 3,  4,  4),
        ("b4c2", 512, 512, 3, 3,  4,  4),
        ("b4c3", 512, 512, 3, 3,  4,  4),
        ("b5c1", 512, 512, 3, 3,  2,  2),
        ("b5c2", 512, 512, 3, 3,  2,  2),
        ("b5c3", 512, 512, 3, 3,  2,  2),
        ("fc1",  512, 4096, 1, 1, 1, 1),
        ("fc2", 4096, 4096, 1, 1, 1, 1),
        ("fc3", 4096,   10, 1, 1, 1, 1),
    ]

def get_resnet18_layers():
    """ResNet18 CIFAR-adapted (structurally same 19-layer topology used
    for ResNet19 elsewhere in this repo): 19 conv + 1 FC"""
    return [
        ("conv0",   3,  64, 3, 3, 32, 32),
        ("b1l1c1",  64,  64, 3, 3, 32, 32),
        ("b1l1c2",  64,  64, 3, 3, 32, 32),
        ("b1l2c1",  64,  64, 3, 3, 32, 32),
        ("b1l2c2",  64,  64, 3, 3, 32, 32),
        ("b2l1c1",  64, 128, 3, 3, 16, 16),
        ("b2l1c2", 128, 128, 3, 3, 16, 16),
        ("b2l2c1", 128, 128, 3, 3, 16, 16),
        ("b2l2c2", 128, 128, 3, 3, 16, 16),
        ("b2l3c1", 128, 128, 3, 3, 16, 16),
        ("b2l3c2", 128, 128, 3, 3, 16, 16),
        ("b3l1c1", 128, 256, 3, 3,  8,  8),
        ("b3l1c2", 256, 256, 3, 3,  8,  8),
        ("b3l2c1", 256, 256, 3, 3,  8,  8),
        ("b3l2c2", 256, 256, 3, 3,  8,  8),
        ("b3l3c1", 256, 256, 3, 3,  8,  8),
        ("b3l3c2", 256, 256, 3, 3,  8,  8),
        ("b4l1c1", 256, 512, 3, 3,  4,  4),
        ("b4l1c2", 512, 512, 3, 3,  4,  4),
        ("fc",     512,  10, 1, 1,  1,  1),
    ]

NETWORKS = {
    "ResNet18": get_resnet18_layers(),
    "VGG16":    get_vgg16_layers(),
    "AlexNet":  get_alexnet_layers(),
}

# ============================================================
# CLOSED-FORM CYCLE MODEL
# ============================================================

def compute_layer_cycles(C_in, C_out, KH, KW, OH, OW,
                         non_silent_prob, overhead, num_tppes,
                         chunk_size=128):
    """
    Cycles for one layer using the closed-form expression.

    For each output neuron (OH*OW*C_out total):
      - Vector length K = KH * KW * C_in
      - Number of chunks = ceil(K / chunk_size)
      - Expected matches per chunk = chunk_len * non_silent_prob
      - Cycles per chunk = E[matches] + overhead
      - Cycles per neuron = sum over chunks, + 1 (P-LIF step)

    With NUM_TPPES parallel units, total neuron-cycles is divided across
    waves of NUM_TPPES neurons at a time.
    """
    K = KH * KW * C_in
    num_chunks = math.ceil(K / chunk_size)
    num_output_neurons = OH * OW * C_out

    cycles_per_neuron = 0
    for chunk_idx in range(num_chunks):
        start = chunk_idx * chunk_size
        end   = min(start + chunk_size, K)
        chunk_len = end - start
        expected_matches = chunk_len * non_silent_prob
        cycles_per_neuron += expected_matches + overhead

    cycles_per_neuron += 1  # LIF step (P-LIF, parallel across T)

    num_waves = math.ceil(num_output_neurons / num_tppes)
    total_cycles = num_waves * cycles_per_neuron

    return total_cycles, num_output_neurons, cycles_per_neuron


def compute_network_cycles(layers, non_silent_prob, overhead,
                           num_tppes=NUM_TPPES, chunk_size=CHUNK_SIZE):
    total = 0
    layer_data = []
    for name, C_in, C_out, KH, KW, OH, OW in layers:
        cyc, n_neurons, cpn = compute_layer_cycles(
            C_in, C_out, KH, KW, OH, OW,
            non_silent_prob, overhead, num_tppes, chunk_size
        )
        total += cyc
        layer_data.append((name, cyc, n_neurons, cpn))
    return total, layer_data


def print_header(title):
    print(f"\n{'='*90}")
    print(f"  {title}")
    print(f"{'='*90}")


if __name__ == "__main__":

    np.random.seed(42)

    print_header(f"CYCLE / LATENCY COMPARISON — LoAS (QCFS) vs Ours/LEDSA (PASC), "
                 f"{NUM_TPPES} TPPEs, chunk={CHUNK_SIZE} @ {CLOCK_MHZ}MHz")

    header = (f"  {'Network':<10} {'Prec':<6} {'T':>3}  "
              f"{'QCFS%':>7} {'PASC%':>7}  {'LoAS cyc':>14} {'Ours cyc':>14}  "
              f"{'LoAS ms':>9} {'Ours ms':>9}  {'Speedup':>8}")
    print(header)
    print(f"  {'-'*len(header)}")

    results = []  # list of dicts, one per (network, config)

    for (net_name, prec, T), (qcfs_pct, pasc_pct) in SPARSITY_TABLE.items():
        layers = NETWORKS[net_name]

        qcfs_non_silent = 1.0 - qcfs_pct / 100.0   # LoAS density
        pasc_non_silent = 1.0 - pasc_pct / 100.0   # Ours/LEDSA density

        loas_total, _ = compute_network_cycles(layers, qcfs_non_silent, LOAS_OVERHEAD)
        ours_total, _ = compute_network_cycles(layers, pasc_non_silent, OURS_OVERHEAD)

        loas_ms = loas_total / (CLOCK_MHZ * 1e3)
        ours_ms = ours_total / (CLOCK_MHZ * 1e3)
        speedup = loas_total / ours_total

        print(f"  {net_name:<10} {prec:<6} {T:>3}  "
              f"{qcfs_pct:>7.2f} {pasc_pct:>7.2f}  "
              f"{loas_total:>14,.0f} {ours_total:>14,.0f}  "
              f"{loas_ms:>9.4f} {ours_ms:>9.4f}  {speedup:>7.3f}×")

        results.append(dict(
            network=net_name, prec=prec, T=T,
            qcfs_pct=qcfs_pct, pasc_pct=pasc_pct,
            loas_cycles=loas_total, ours_cycles=ours_total,
            loas_ms=loas_ms, ours_ms=ours_ms, speedup=speedup,
        ))

    # ----------------------------------------------------------
    # Summary: average speedup per network
    # ----------------------------------------------------------
    print_header("AVERAGE SPEEDUP PER NETWORK (across all configs)")
    for net_name in NETWORKS:
        sps = [r["speedup"] for r in results if r["network"] == net_name]
        print(f"  {net_name:<10} avg speedup = {np.mean(sps):.3f}×  "
              f"(min {min(sps):.3f}×, max {max(sps):.3f}×)")

    # ============================================================
    # FINAL FIGURE: latency comparison (LoAS/QCFS vs Ours/PASC)
    # ============================================================
    plt.rcParams.update({
        "font.size": 10,
        "axes.titlesize": 12,
        "axes.titleweight": "bold",
        "figure.facecolor": "white",
    })

    net_order = ["ResNet18", "VGG16", "AlexNet"]
    fig, axes = plt.subplots(1, 3, figsize=(16, 5.5), sharey=False)

    color_loas = "#4C72B0"  # LoAS / QCFS
    color_ours = "#55A868"  # Ours / LEDSA / PASC

    for ax, net_name in zip(axes, net_order):
        rows = [r for r in results if r["network"] == net_name]
        # sort: INT8 T4,8,16 ; INT4 T4,8,16 ; Mixed T8  (table order)
        order_key = {("INT8", 4): 0, ("INT8", 8): 1, ("INT8", 16): 2,
                     ("INT4", 4): 3, ("INT4", 8): 4, ("INT4", 16): 5,
                     ("Mixed", 8): 6}
        rows.sort(key=lambda r: order_key[(r["prec"], r["T"])])

        labels = [f"{r['prec']}\nT={r['T']}" for r in rows]
        loas_ms = [r["loas_ms"] for r in rows]
        ours_ms = [r["ours_ms"] for r in rows]

        x = np.arange(len(rows))
        width = 0.36

        ax.bar(x - width/2, loas_ms, width, label="LoAS (QCFS)",
               color=color_loas, edgecolor="black", linewidth=0.6)
        ax.bar(x + width/2, ours_ms, width, label="Ours/LEDSA (PASC)",
               color=color_ours, edgecolor="black", linewidth=0.6)

        for r, xi in zip(rows, x):
            ax.annotate(f"{r['speedup']:.2f}×",
                        xy=(xi, max(r["loas_ms"], r["ours_ms"])),
                        xytext=(0, 4), textcoords="offset points",
                        ha="center", fontsize=8, fontweight="bold", color="#333333")

        ax.set_xticks(x)
        ax.set_xticklabels(labels, fontsize=8.5)
        ax.set_title(net_name)
        ax.set_xlabel("Precision / Timesteps")
        if net_name == net_order[0]:
            ax.set_ylabel("Latency (ms @ 800 MHz)")
        ax.grid(axis="y", linestyle="--", alpha=0.4)
        ax.set_axisbelow(True)

    handles, labels_ = axes[0].get_legend_handles_labels()
    fig.legend(handles, labels_, loc="upper center", ncol=2,
               bbox_to_anchor=(0.5, 1.03), frameon=False, fontsize=11)
    fig.suptitle("Per-Layer Closed-Form Latency: LoAS (QCFS sparsity) vs "
                 "Ours/LEDSA (PASC sparsity)", fontsize=13, fontweight="bold", y=1.10)

    fig.tight_layout()
    out_path = "cycle_accurate_final.png"
    fig.savefig(out_path, dpi=200, bbox_inches="tight")
    print(f"\nSaved figure to: {out_path}")
