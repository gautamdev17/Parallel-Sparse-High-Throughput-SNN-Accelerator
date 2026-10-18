### v2 (DRAM included, 256 bits/cycle = 25.6 GB/s), workload `sparse90`

| Network | Design | Latency b=1 (ms) | v1 latency (compute only) | Throughput b=16 (img/s) | v1 throughput | DRAM traffic b=1 (MB) | Ours speed-up |
|---|---|---:|---:|---:|---:|---:|---:|
| VGG16 | LoAS | 11.496 | 11.217 | 89 | 89 | 38.85 | 17.71x |
| VGG16 | SpikeX (8x8) | 4.728 | 4.170 | 240 | 240 | 34.32 | 7.28x |
| VGG16 | PTB (16x8, Prosperity-repo model) | 4.905 | 4.627 | 205 | 215 | (in official sim) | 7.56x |
| VGG16 | SATO (128 PE) | 3.184 | 3.060 | 466 | 478 | 34.32 | 4.91x |
| VGG16 | SpikeFlow (16x16) | 2.788 | 2.002 | 502 | 502 | 33.99 | 4.29x |
| VGG16 | Prosperity (official sim) | 1.699 | 0.833 | 1,581 | 1,642 | (in official sim) | 2.62x |
| VGG16 | Ours (4x4, T=8) | 0.649 | 0.507 | 2,752 | 2,762 | 9.86 | 1.00x |
| ResNet18 | LoAS | 18.939 | 18.846 | 53 | 53 | 15.00 | 26.56x |
| ResNet18 | SpikeX (8x8) | 7.493 | 7.472 | 132 | 132 | 13.61 | 10.51x |
| ResNet18 | PTB (16x8, Prosperity-repo model) | 7.941 | 7.941 | 125 | 125 | (in official sim) | 11.14x |
| ResNet18 | SATO (128 PE) | 4.465 | 4.444 | 235 | 235 | 13.61 | 6.26x |
| ResNet18 | SpikeFlow (16x16) | 3.575 | 3.568 | 278 | 278 | 12.15 | 5.01x |
| ResNet18 | Prosperity (official sim) | 1.425 | 1.282 | 804 | 804 | (in official sim) | 2.00x |
| ResNet18 | Ours (4x4, T=8) | 0.713 | 0.688 | 1,591 | 1,596 | 4.39 | 1.00x |

### v2 (DRAM included, 256 bits/cycle = 25.6 GB/s), workload `zipstats`

| Network | Design | Latency b=1 (ms) | v1 latency (compute only) | Throughput b=16 (img/s) | v1 throughput | DRAM traffic b=1 (MB) | Ours speed-up |
|---|---|---:|---:|---:|---:|---:|---:|
| VGG16 | LoAS | 11.496 | 11.217 | 89 | 89 | 38.85 | 1.82x |
| VGG16 | SpikeX (8x8) | 10.840 | 10.823 | 92 | 92 | 34.32 | 1.72x |
| VGG16 | PTB (16x8, Prosperity-repo model) | 9.299 | 9.299 | 107 | 107 | (in official sim) | 1.47x |
| VGG16 | SATO (128 PE) | 5.693 | 5.677 | 318 | 318 | 34.32 | 0.90x |
| VGG16 | SpikeFlow (16x16) | 5.235 | 4.836 | 208 | 208 | 34.21 | 0.83x |
| VGG16 | Prosperity (official sim) | 2.162 | 1.396 | 807 | 807 | (in official sim) | 0.34x |
| VGG16 | Ours (4x4, T=8) | 6.310 | 5.779 | 219 | 219 | 67.80 | 1.00x |
| ResNet18 | LoAS | 18.939 | 18.846 | 53 | 53 | 15.00 | 2.22x |
| ResNet18 | SpikeX (8x8) | 19.661 | 19.640 | 51 | 51 | 13.61 | 2.31x |
| ResNet18 | PTB (16x8, Prosperity-repo model) | 15.039 | 15.039 | 66 | 66 | (in official sim) | 1.77x |
| ResNet18 | SATO (128 PE) | 6.588 | 6.568 | 163 | 163 | 13.61 | 0.77x |
| ResNet18 | SpikeFlow (16x16) | 8.648 | 8.641 | 116 | 116 | 13.25 | 1.02x |
| ResNet18 | Prosperity (official sim) | 2.544 | 2.543 | 401 | 401 | (in official sim) | 0.30x |
| ResNet18 | Ours (4x4, T=8) | 8.518 | 8.493 | 126 | 126 | 24.05 | 1.00x |
