### Workload `sparse90`: weight density 0.1, non-silent 0.1, fire prob 0.3 (T=8, INT8, 800 MHz)

| Network | Design | Cycles (b=1) | Latency (ms) | Ours speed-up (latency) | Throughput (img/s, b=16) | Ours gain (throughput) | img/s per adder |
|---|---|---:|---:|---:|---:|---:|---:|
| VGG16 | LoAS | 8,973,849 | 11.217 | 24.59x | 89 | 31.37x | 0.70 |
| VGG16 | SpikeX (8x8) | 3,335,686 | 4.170 | 9.14x | 240 | 11.67x | 3.75 |
| VGG16 | PTB (16x8, Prosperity-repo model) | 3,701,483 | 4.627 | 10.14x | 215 | 12.99x | 1.68 |
| VGG16 | SATO (128 PE) | 2,448,376 | 3.060 | 6.71x | 478 | 5.85x | 3.73 |
| VGG16 | SpikeFlow (16x16) | 1,601,259 | 2.002 | 4.39x | 502 | 5.57x | 1.96 |
| VGG16 | Prosperity (official sim) | 666,778 | 0.833 | 1.83x | 1,642 | 1.70x | 12.83 |
| VGG16 | Ours (4x4, T=8) | 364,930 | 0.456 | 1.00x | 2,797 | 1.00x | 21.85 |
| ResNet18 | LoAS | 15,076,980 | 18.846 | 27.76x | 53 | 30.24x | 0.41 |
| ResNet18 | SpikeX (8x8) | 5,977,620 | 7.472 | 11.01x | 132 | 12.11x | 2.07 |
| ResNet18 | PTB (16x8, Prosperity-repo model) | 6,352,976 | 7.941 | 11.70x | 125 | 12.85x | 0.98 |
| ResNet18 | SATO (128 PE) | 3,555,140 | 4.444 | 6.55x | 235 | 6.82x | 1.84 |
| ResNet18 | SpikeFlow (16x16) | 2,854,289 | 3.568 | 5.26x | 278 | 5.77x | 1.09 |
| ResNet18 | Prosperity (official sim) | 1,025,513 | 1.282 | 1.89x | 804 | 2.00x | 6.28 |
| ResNet18 | Ours (4x4, T=8) | 543,056 | 0.679 | 1.00x | 1,605 | 1.00x | 12.54 |

### Workload `zipstats`: weight density 1.0, non-silent 0.261, fire prob 0.3 (T=8, INT8, 800 MHz)

| Network | Design | Cycles (b=1) | Latency (ms) | Ours speed-up (latency) | Throughput (img/s, b=16) | Ours gain (throughput) | img/s per adder |
|---|---|---:|---:|---:|---:|---:|---:|
| VGG16 | LoAS | 8,973,849 | 11.217 | 1.95x | 89 | 2.46x | 0.70 |
| VGG16 | SpikeX (8x8) | 8,658,454 | 10.823 | 1.88x | 92 | 2.38x | 1.44 |
| VGG16 | PTB (16x8, Prosperity-repo model) | 7,439,307 | 9.299 | 1.62x | 107 | 2.05x | 0.84 |
| VGG16 | SATO (128 PE) | 4,541,498 | 5.677 | 0.99x | 318 | 0.69x | 2.48 |
| VGG16 | SpikeFlow (16x16) | 3,869,059 | 4.836 | 0.84x | 208 | 1.05x | 0.81 |
| VGG16 | Prosperity (official sim) | 1,117,161 | 1.396 | 0.24x | 807 | 0.27x | 6.30 |
| VGG16 | Ours (4x4, T=8) | 4,602,491 | 5.753 | 1.00x | 219 | 1.00x | 1.71 |
| ResNet18 | LoAS | 15,076,980 | 18.846 | 2.22x | 53 | 2.37x | 0.41 |
| ResNet18 | SpikeX (8x8) | 15,711,996 | 19.640 | 2.31x | 51 | 2.47x | 0.80 |
| ResNet18 | PTB (16x8, Prosperity-repo model) | 12,031,392 | 15.039 | 1.77x | 66 | 1.90x | 0.52 |
| ResNet18 | SATO (128 PE) | 5,254,034 | 6.568 | 0.77x | 163 | 0.77x | 1.27 |
| ResNet18 | SpikeFlow (16x16) | 6,912,849 | 8.641 | 1.02x | 116 | 1.09x | 0.45 |
| ResNet18 | Prosperity (official sim) | 2,034,105 | 2.543 | 0.30x | 401 | 0.31x | 3.13 |
| ResNet18 | Ours (4x4, T=8) | 6,796,249 | 8.495 | 1.00x | 126 | 1.00x | 0.98 |
