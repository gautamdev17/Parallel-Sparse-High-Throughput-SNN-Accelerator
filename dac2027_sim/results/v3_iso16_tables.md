### v3: all designs with 16 PEs, workload `sparse90` (T=8, 800 MHz)

| Network | Design | Latency b=1 (ms) | Speed-up vs LoAS | Throughput b=16 (img/s) | Throughput vs LoAS |
|---|---|---:|---:|---:|---:|
| VGG16 | LoAS (16 TPPE) | 11.217 | 1.00x | 89 | 1.00x |
| VGG16 | SpikeX (4x4) | 13.126 | 0.85x | 76 | 0.85x |
| VGG16 | PTB (2x8) | 32.386 | 0.35x | 31 | 0.34x |
| VGG16 | SATO (16 PE) | 7.103 | 1.58x | 152 | 1.71x |
| VGG16 | SpikeFlow (4x4) | 13.133 | 0.85x | 76 | 0.85x |
| VGG16 | Prosperity (16 PE) | 4.288 | 2.62x | 235 | 2.63x |
| VGG16 | Ours (4x4) | 0.542 | 20.70x | 2,762 | 30.98x |
| ResNet18 | LoAS (16 TPPE) | 18.846 | 1.00x | 53 | 1.00x |
| ResNet18 | SpikeX (4x4) | 23.599 | 0.80x | 42 | 0.79x |
| ResNet18 | PTB (2x8) | 53.322 | 0.35x | 19 | 0.35x |
| ResNet18 | SATO (16 PE) | 12.447 | 1.51x | 81 | 1.52x |
| ResNet18 | SpikeFlow (4x4) | 23.610 | 0.80x | 42 | 0.79x |
| ResNet18 | Prosperity (16 PE) | 7.616 | 2.47x | 131 | 2.47x |
| ResNet18 | Ours (4x4) | 0.688 | 27.38x | 1,596 | 30.08x |

### v3: all designs with 16 PEs, workload `zipstats` (T=8, 800 MHz)

| Network | Design | Latency b=1 (ms) | Speed-up vs LoAS | Throughput b=16 (img/s) | Throughput vs LoAS |
|---|---|---:|---:|---:|---:|
| VGG16 | LoAS (16 TPPE) | 11.217 | 1.00x | 89 | 1.00x |
| VGG16 | SpikeX (4x4) | 34.214 | 0.33x | 29 | 0.33x |
| VGG16 | PTB (2x8) | 69.754 | 0.16x | 14 | 0.16x |
| VGG16 | SATO (16 PE) | 16.267 | 0.69x | 67 | 0.76x |
| VGG16 | SpikeFlow (4x4) | 34.217 | 0.33x | 29 | 0.33x |
| VGG16 | Prosperity (16 PE) | 8.877 | 1.26x | 115 | 1.29x |
| VGG16 | Ours (4x4) | 5.790 | 1.94x | 219 | 2.46x |
| ResNet18 | LoAS (16 TPPE) | 18.846 | 1.00x | 53 | 1.00x |
| ResNet18 | SpikeX (4x4) | 61.855 | 0.30x | 16 | 0.30x |
| ResNet18 | PTB (2x8) | 110.105 | 0.17x | 9 | 0.17x |
| ResNet18 | SATO (16 PE) | 27.636 | 0.68x | 37 | 0.69x |
| ResNet18 | SpikeFlow (4x4) | 61.856 | 0.30x | 16 | 0.30x |
| ResNet18 | Prosperity (16 PE) | 15.446 | 1.22x | 65 | 1.22x |
| ResNet18 | Ours (4x4) | 8.493 | 2.22x | 126 | 2.37x |

PE = 8 adders for Ours and LoAS, 1 adder for the others: at 16 PEs Ours and LoAS have 128 adders, the others 16. The equal-adder (128) comparison is v1 (main_tables.md).
