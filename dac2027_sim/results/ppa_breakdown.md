# Our design: area and power breakdown

Core: Yosys + ABC, Nangate45 typical, hierarchy kept; power: OpenSTA with gate-level activity from the closed-loop testbench (1000 streaming cycles of VGG16 L3 + the drain/LIF sweep of a ResNet18 tile, weighted 0.966 / 0.034 by the LIF share of VGG16 cycles), at 800 MHz activity. SRAM: CACTI 7 at 28 nm. 28 nm core = 45 nm x (28/45)^2 area, x 0.486 energy (Stillmaker & Baas 2017).

| Block | Area 45 nm (mm^2) | Area 28 nm (mm^2) | Share | Power 45 nm @800 MHz (mW) | Share | Worst path 45 nm (ns) |
|---|---:|---:|---:|---:|---:|---:|
| PE array (16 PEs) | 0.1994 | 0.0772 | 28.2% | 132.3 | 40.3% | 1.68 |
| edge FIFOs (4 x 80 entries) | 0.3909 | 0.1513 | 55.4% | 157.8 | 48.1% | 22.31 |
| packer (8 slices/cycle) | 0.0466 | 0.0181 | 6.6% | 23.0 | 7.0% | 23.11 |
| LIF units (16) | 0.0403 | 0.0156 | 5.7% | 2.4 | 0.7% | 10.67 |
| arbiter, skew, id sideband, RMW adders | 0.0288 | 0.0112 | 4.1% | 12.6 | 3.9% | 0.35 |
| **Core total** | **0.7060** | **0.2733** | 100% | **328.1** | 100% | **23.11** (43 MHz) |

Activity annotation: 0 / 0 unannotated pins (stream / LIF window).

SRAM buffers (outside the core), CACTI 7, 28 nm:

| Buffer | Area (mm^2) | Read (pJ) | Write (pJ) | Leakage (mW) |
|---|---:|---:|---:|---:|
| output buffer (192 KB, 24 B entries) | 0.3314 | 32.25 | 34.84 | 94.2 |
| staging buffer (64 KB, 16 B) | 0.1009 | 12.83 | 14.56 | 33.2 |
| group buffer (2 x 2 KB, 16 B) | 0.0062 | 1.82 | 4.67 | 2.5 |

Ours at 28 nm on VGG16 (batch 1, sparse90), operations in Phi's definition (65.4 M per image; 6.55 M touch a non-zero weight):

| Clock | Latency (ms) | GOP/s | Power core + SRAM (mW) | GOP/J | Area core + SRAM (mm^2) |
|---|---:|---:|---:|---:|---:|
| target 500 MHz (packer, LIF, edge pipelined): 500 MHz | 0.867 | 75.4 | 453.4 (99.7 + 353.7) | 166 | 0.712 |
| as synthesized (fmax): 48 MHz | 9.008 | 7.3 | 161.0 (9.6 + 151.4) | 45 | 0.712 |
