# All designs at 45 nm (Nangate45), 500 MHz, workload sparse90

OP = one accumulation per '1' spike bit per output channel; VGG16 65.4 M OP/image, ResNet18 117.7 M OP/image (same for every design). GOP/s from batch-16 throughput. Core: our RTL of each design, gate-level power. SRAM: CACTI 7 at 45 nm (area + leakage; read/write energy not counted for any design). Phi has no RTL here and is not in this table.

| Design | Node | Clock | Core area (mm^2) | SRAM | SRAM area (mm^2) | Total area (mm^2) | Core power (mW) | Core + SRAM leak. (mW) | VGG16 GOP/s | VGG16 GOP/J (core) | VGG16 GOP/J (core+SRAM) | ResNet18 GOP/s | ResNet18 GOP/J (core) | ResNet18 GOP/J (core+SRAM) |
|---|---|---|---:|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| PTB | 45 nm | 500 MHz | 0.953 | 54 KB GLB + 2 KB L1 (Table IV) | 0.207 | 1.160 | 381.4 | 457.2 | 8.8 | 23 | 19 | 9.2 | 24 | 20 |
| SpikeX | 45 nm | 500 MHz | 0.468 | 54 KB + 2 KB (Sec. V-A) | 0.207 | 0.675 | 187.8 | 263.5 | 9.8 | 52 | 37 | 9.7 | 52 | 37 |
| SATO | 45 nm | 500 MHz | 0.076 | 54 KB (assumed, not given) | 0.207 | 0.283 | 21.6 | 97.4 | 19.5 | 903 | 200 | 17.3 | 800 | 178 |
| SpikeFlow | 45 nm | 500 MHz | 0.123 | 18.5 KB (Table 1) | 0.065 | 0.187 | 47.2 | 72.3 | 20.5 | 435 | 284 | 20.4 | 433 | 283 |
| LoAS | 45 nm | 500 MHz | 0.370 | 256 KB global cache (Table III) | 0.977 | 1.347 | 59.4 | 359.0 | 12.9 | 217 | 36 | 13.6 | 229 | 38 |
| Prosperity | 45 nm | 500 MHz | 0.369 | 8 + 32 + 96 KB (Table III) | 0.656 | 1.025 | 100.3 | 264.4 | 67.1 | 669 | 254 | 59.1 | 590 | 224 |
| Ours | 45 nm | 500 MHz | 0.950 | 192 + 64 + 4 KB | 0.955 | 1.905 | 296.3 | 654.4 | 114.3 | 386 | 175 | 118.1 | 398 | 180 |

All core power numbers are from the same flow; baselines were measured at 800 MHz activity and rescaled (internal + switching x 500/800, leakage unchanged). Clock 500 MHz is the one our pipelined core meets at 45 nm (synthesis-level timing); the baselines' RTL was not timing-closed and is assumed to run at the same clock.
