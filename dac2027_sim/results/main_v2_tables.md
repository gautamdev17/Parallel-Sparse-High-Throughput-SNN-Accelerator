### v2 (DRAM included, 1024 bits/cycle = 102.4 GB/s), workload `sparse90`

| Network | Design | Latency b=1 (ms) | v1 latency (compute only) | Throughput b=16 (img/s) | v1 throughput | DRAM traffic b=1 (MB) | Ours speed-up |
|---|---|---:|---:|---:|---:|---:|---:|
| VGG16 | LoAS | 11.236 | 11.217 | 89 | 89 | 38.85 | 21.98x |
| VGG16 | SpikeX (8x8) | 4.174 | 4.170 | 240 | 240 | 34.32 | 8.16x |
| VGG16 | PTB (16x8, Prosperity-repo model) | 4.627 | 4.627 | 215 | 215 | (in official sim) | 9.05x |
| VGG16 | SATO (128 PE) | 3.065 | 3.060 | 478 | 478 | 34.32 | 5.99x |
| VGG16 | SpikeFlow (16x16) | 2.050 | 2.002 | 502 | 502 | 33.99 | 4.01x |
| VGG16 | Prosperity (official sim) | 0.833 | 0.833 | 1,642 | 1,642 | (in official sim) | 1.63x |
| VGG16 | Ours (4x4, T=8) | 0.511 | 0.507 | 2,759 | 2,762 | 9.86 | 1.00x |
| ResNet18 | LoAS | 18.869 | 18.846 | 53 | 53 | 15.00 | 27.17x |
| ResNet18 | SpikeX (8x8) | 7.477 | 7.472 | 132 | 132 | 13.61 | 10.77x |
| ResNet18 | PTB (16x8, Prosperity-repo model) | 7.941 | 7.941 | 125 | 125 | (in official sim) | 11.43x |
| ResNet18 | SATO (128 PE) | 4.449 | 4.444 | 235 | 235 | 13.61 | 6.41x |
| ResNet18 | SpikeFlow (16x16) | 3.570 | 3.568 | 278 | 278 | 12.15 | 5.14x |
| ResNet18 | Prosperity (official sim) | 1.282 | 1.282 | 804 | 804 | (in official sim) | 1.85x |
| ResNet18 | Ours (4x4, T=8) | 0.695 | 0.688 | 1,595 | 1,596 | 4.39 | 1.00x |

### v2 (DRAM included, 1024 bits/cycle = 102.4 GB/s), workload `zipstats`

| Network | Design | Latency b=1 (ms) | v1 latency (compute only) | Throughput b=16 (img/s) | v1 throughput | DRAM traffic b=1 (MB) | Ours speed-up |
|---|---|---:|---:|---:|---:|---:|---:|
| VGG16 | LoAS | 11.236 | 11.217 | 89 | 89 | 38.85 | 1.94x |
| VGG16 | SpikeX (8x8) | 10.827 | 10.823 | 92 | 92 | 34.32 | 1.87x |
| VGG16 | PTB (16x8, Prosperity-repo model) | 9.299 | 9.299 | 107 | 107 | (in official sim) | 1.61x |
| VGG16 | SATO (128 PE) | 5.681 | 5.677 | 318 | 318 | 34.32 | 0.98x |
| VGG16 | SpikeFlow (16x16) | 4.838 | 4.836 | 208 | 208 | 34.21 | 0.84x |
| VGG16 | Prosperity (official sim) | 1.396 | 1.396 | 807 | 807 | (in official sim) | 0.24x |
| VGG16 | Ours (4x4, T=8) | 5.784 | 5.779 | 219 | 219 | 67.80 | 1.00x |
| ResNet18 | LoAS | 18.869 | 18.846 | 53 | 53 | 15.00 | 2.22x |
| ResNet18 | SpikeX (8x8) | 19.645 | 19.640 | 51 | 51 | 13.61 | 2.31x |
| ResNet18 | PTB (16x8, Prosperity-repo model) | 15.039 | 15.039 | 66 | 66 | (in official sim) | 1.77x |
| ResNet18 | SATO (128 PE) | 6.573 | 6.568 | 163 | 163 | 13.61 | 0.77x |
| ResNet18 | SpikeFlow (16x16) | 8.643 | 8.641 | 116 | 116 | 13.25 | 1.02x |
| ResNet18 | Prosperity (official sim) | 2.543 | 2.543 | 401 | 401 | (in official sim) | 0.30x |
| ResNet18 | Ours (4x4, T=8) | 8.499 | 8.493 | 126 | 126 | 24.05 | 1.00x |
