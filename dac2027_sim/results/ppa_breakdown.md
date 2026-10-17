# Our design: area and power breakdown

Core: Yosys + ABC, Nangate45 typical, hierarchy kept; power: OpenSTA with gate-level activity from the closed-loop testbench (1000 streaming cycles of VGG16 L3 + the drain/LIF sweep of a ResNet18 tile, weighted 0.960 / 0.040 by the LIF share of VGG16 cycles), at 500 MHz. SRAM: CACTI 7 at 28 nm. 28 nm core = 45 nm x (28/45)^2 area, x 0.486 energy (Stillmaker & Baas 2017).

| Block | Area 45 nm (mm^2) | Area 28 nm (mm^2) | Share | Power 45 nm @500 MHz (mW) | Share | Worst path 45 nm (ns) |
|---|---:|---:|---:|---:|---:|---:|
| PE array (16 PEs) | 0.2190 | 0.0848 | 23.0% | 89.7 | 30.3% | 0.86 |
| edge FIFOs (4 x 80 entries) | 0.4804 | 0.1860 | 50.6% | 118.7 | 40.1% | 1.96 |
| packer (8 slices/cycle) | 0.1056 | 0.0409 | 11.1% | 39.4 | 13.3% | 1.30 |
| LIF units (16) | 0.0975 | 0.0378 | 10.3% | 26.2 | 8.8% | 1.88 |
| arbiter, skew, id sideband, RMW adders | 0.0476 | 0.0184 | 5.0% | 22.3 | 7.5% | 1.59 |
| **Core total** | **0.9501** | **0.3678** | 100% | **296.3** | 100% | **1.96** (510 MHz) |

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
| 500 MHz (timing met at 45 nm): 500 MHz | 0.730 | 89.6 | 539.9 (144.0 + 395.9) | 166 | 0.806 |
| fmax (510 MHz at 45 nm, scaled): 568 MHz | 0.643 | 101.7 | 595.2 (163.4 + 431.8) | 171 | 0.806 |
