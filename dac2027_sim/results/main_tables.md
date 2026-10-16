### Workload `sparse90`: weight density 0.1, non-silent 0.1, fire prob 0.3 (T=8, INT8, 800 MHz)

| Network | Design | Cycles (b=1) | Latency (ms) | Ours speed-up (latency) | Throughput (img/s, b=16) | Ours gain (throughput) | img/s per adder |
|---|---|---:|---:|---:|---:|---:|---:|
| VGG16 | LoAS | 8,973,849 | 11.217 | 22.15x | 89 | 30.98x | 0.70 |
| VGG16 | SpikeX (8x8) | 3,335,686 | 4.170 | 8.23x | 240 | 11.52x | 3.75 |
| VGG16 | PTB (16x8) | 853,729 | 1.067 | 2.11x | 937 | 2.95x | 7.32 |
| VGG16 | Prosperity (official sim) | 666,778 | 0.833 | 1.65x | 1,642 | 1.68x | 12.83 |
| VGG16 | Ours (4x4, T=8) | 405,230 | 0.507 | 1.00x | 2,762 | 1.00x | 21.58 |
| ResNet18 | LoAS | 15,076,980 | 18.846 | 27.38x | 53 | 30.08x | 0.41 |
| ResNet18 | SpikeX (8x8) | 5,977,620 | 7.472 | 10.85x | 132 | 12.05x | 2.07 |
| ResNet18 | PTB (16x8) | 1,532,172 | 1.915 | 2.78x | 517 | 3.09x | 4.04 |
| ResNet18 | Prosperity (official sim) | 1,025,513 | 1.282 | 1.86x | 804 | 1.99x | 6.28 |
| ResNet18 | Ours (4x4, T=8) | 550,695 | 0.688 | 1.00x | 1,596 | 1.00x | 12.47 |

### Workload `zipstats`: weight density 1.0, non-silent 0.261, fire prob 0.3 (T=8, INT8, 800 MHz)

| Network | Design | Cycles (b=1) | Latency (ms) | Ours speed-up (latency) | Throughput (img/s, b=16) | Ours gain (throughput) | img/s per adder |
|---|---|---:|---:|---:|---:|---:|---:|
| VGG16 | LoAS | 8,973,849 | 11.217 | 1.94x | 89 | 2.46x | 0.70 |
| VGG16 | SpikeX (8x8) | 8,658,454 | 10.823 | 1.87x | 92 | 2.38x | 1.44 |
| VGG16 | PTB (16x8) | 2,205,824 | 2.757 | 0.48x | 361 | 0.61x | 2.82 |
| VGG16 | Prosperity (official sim) | 1,117,161 | 1.396 | 0.24x | 807 | 0.27x | 6.30 |
| VGG16 | Ours (4x4, T=8) | 4,623,242 | 5.779 | 1.00x | 219 | 1.00x | 1.71 |
| ResNet18 | LoAS | 15,076,980 | 18.846 | 2.22x | 53 | 2.37x | 0.41 |
| ResNet18 | SpikeX (8x8) | 15,711,996 | 19.640 | 2.31x | 51 | 2.47x | 0.80 |
| ResNet18 | PTB (16x8) | 4,003,844 | 5.005 | 0.59x | 200 | 0.63x | 1.56 |
| ResNet18 | Prosperity (official sim) | 2,034,105 | 2.543 | 0.30x | 401 | 0.31x | 3.13 |
| ResNet18 | Ours (4x4, T=8) | 6,794,337 | 8.493 | 1.00x | 126 | 1.00x | 0.98 |
