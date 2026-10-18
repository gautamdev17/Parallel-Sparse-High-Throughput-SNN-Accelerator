# LoAS vs LoAS+: power, energy, EDP (Nangate45, 800 MHz, gate-level activity; 256 KB cache leakage incl.)

| Design | TPPE area (mm²) | TPPE power (mW) | 16 TPPEs (mW) | + cache leakage (mW) |
|---|---:|---:|---:|---:|
| LoAS | 0.0231 | 5.64 | 90.2 | 389.8 |
| LoAS+ | 0.0117 | 6.90 | 110.5 | 410.1 |

| Workload | Network | LoAS latency (ms) | LoAS+ latency (ms) | LoAS energy (mJ) | LoAS+ energy (mJ) | Energy gain | Core-only energy gain | LoAS EDP (mJ·ms) | LoAS+ EDP (mJ·ms) | EDP gain |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| sparse90 | VGG16 | 3.186 | 0.925 | 1.2418 | 0.3792 | **3.27x** | 2.81x | 3.9560 | 0.35076 | **11.3x** |
| sparse90 | ResNet18 | 5.420 | 1.593 | 2.1130 | 0.6532 | **3.23x** | 2.78x | 11.4533 | 1.04047 | **11.0x** |
| zipstats | VGG16 | 9.374 | 2.746 | 3.6541 | 1.1261 | **3.24x** | 2.79x | 34.2518 | 3.09269 | **11.1x** |
| zipstats | ResNet18 | 16.496 | 4.876 | 6.4304 | 1.9993 | **3.22x** | 2.76x | 106.0744 | 9.74785 | **10.9x** |
| real-spikes wd=0.1 | VGG16 | 12.941 | 4.304 | 5.0448 | 1.7647 | **2.86x** | 2.46x | 65.2849 | 7.59461 | **8.6x** |
| real-spikes wd=0.1 | ResNet18 | 7.539 | 2.435 | 2.9390 | 0.9983 | **2.94x** | 2.53x | 22.1579 | 2.43055 | **9.1x** |
| real-spikes wd=0.02 | VGG16 | 8.783 | 2.536 | 3.4238 | 1.0401 | **3.29x** | 2.83x | 30.0712 | 2.63820 | **11.4x** |
| real-spikes wd=0.02 | ResNet18 | 4.869 | 1.417 | 1.8980 | 0.5810 | **3.27x** | 2.81x | 9.2409 | 0.82324 | **11.2x** |

Energy = (16 TPPEs + cache leakage) x batch-1 latency. LoAS power is measured on hw/rtl/loas, which runs at ~6.3 cycles/match and fails its own reference check (tb_loas.v: 400/400 mismatches over 50 chunks), so its measured activity is low; LoAS+ power is measured at full activity (0.77 cycles/match, bit-exact). Both choices favour LoAS. Neither TPPE closes 800 MHz unplaced (register-to-register: LoAS 3.14 ns, LoAS+ 2.42 ns); both are evaluated at the same 800 MHz, as in the other tables.
