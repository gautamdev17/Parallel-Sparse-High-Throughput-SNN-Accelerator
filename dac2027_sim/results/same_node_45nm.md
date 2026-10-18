# All designs at 45 nm (Nangate45), 500 MHz, workload sparse90

OP = one accumulation per '1' spike bit per output channel; VGG16 65.4 M OP/image, ResNet18 117.7 M OP/image (same for every design). GOP/s and energy per image from batch-16 throughput. Core: our RTL of each design, gate-level power. SRAM: CACTI 7 at 45 nm, LSTP cells + LOP periphery, 300 K: area, leakage and read/write energy from each design's access counts (mem_levels.py). DRAM: 12.45 pJ/bit (Prosperity repo, DRAMsim3) x DRAM traffic per image. Phi has no RTL here and is not in this table.

| Design | Core area (mm^2) | SRAM | SRAM area (mm^2) | Total area (mm^2) | Core power (mW) | SRAM leak. (mW) | VGG16 GOP/s | VGG16 energy core / SRAM / DRAM (uJ/img) | VGG16 GOP/J core | VGG16 GOP/J core+SRAM | VGG16 GOP/J system | ResNet18 GOP/s | ResNet18 energy core / SRAM / DRAM (uJ/img) | ResNet18 GOP/J core | ResNet18 GOP/J core+SRAM | ResNet18 GOP/J system |
|---|---:|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| PTB | 0.953 | 54 KB GLB + 2 KB L1 (Table IV) | 0.279 | 1.232 | 381.4 | 0.47 | 8.8 | 2834 / 76 / 3372 | 23 | 22 | 10 | 9.2 | 4888 / 73 / 1186 | 24 | 24 | 19 |
| SpikeX | 0.468 | 54 KB + 2 KB (Sec. V-A) | 0.279 | 0.747 | 187.8 | 0.47 | 9.8 | 1253 / 45 / 742 | 52 | 50 | 32 | 9.7 | 2268 / 72 / 669 | 52 | 50 | 39 |
| SATO | 0.076 | 54 KB (assumed, not given) | 0.279 | 0.355 | 21.6 | 0.47 | 19.5 | 72 / 83 / 742 | 903 | 421 | 73 | 17.3 | 147 / 143 / 669 | 800 | 406 | 123 |
| SpikeFlow | 0.123 | 18.5 KB (Table 1) | 0.084 | 0.207 | 47.2 | 0.13 | 20.5 | 150 / 19 / 510 | 435 | 385 | 96 | 20.4 | 272 / 28 / 478 | 433 | 393 | 151 |
| LoAS | 0.370 | 256 KB global cache (Table III) | 1.108 | 1.478 | 57.7 | 1.02 | 12.9 | 294 / 132 / 139 | 223 | 153 | 116 | 13.6 | 500 / 224 / 212 | 235 | 162 | 126 |
| Prosperity | 0.369 | 8 + 32 + 96 KB (Table III) | 0.666 | 1.035 | 239.8 | 0.70 | 67.1 | 234 / 540 / 1161 | 280 | 85 | 34 | 59.1 | 477 / 907 / 1850 | 247 | 85 | 36 |
| Ours | 0.950 | 192 + 64 + 4 KB | 1.178 | 2.128 | 296.3 | 1.13 | 114.3 | 170 / 272 / 180 | 386 | 148 | 105 | 118.1 | 295 / 491 / 238 | 398 | 150 | 115 |

Core power numbers are all from the same flow; baselines were measured at 800 MHz activity and rescaled (internal + switching x 500/800, leakage unchanged). Clock 500 MHz is the one our pipelined core meets at 45 nm (synthesis-level timing); the baselines' RTL was not timing-closed and is assumed to run at the same clock (LoAS's TPPE does not: 3.14 ns). Previous version with ITRS-HP SRAM at 360 K and no access energy: same_node_45nm_hpsram_old.md.
