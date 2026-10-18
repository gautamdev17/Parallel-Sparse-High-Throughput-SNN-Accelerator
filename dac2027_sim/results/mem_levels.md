# Weight and activation traffic per inference at three levels (MB), sparse90, batch 1

Off-chip: DRAM -> on-chip buffers (mem_traffic.py). On-chip: buffers -> PE array (reads). PE: operand bits latched by the PEs, once per receiving PE (broadcast / systolic forwarding counted per PE). Rules per design in mem_levels.py. Normalized = (weights + activations) / PTB at the same level.

| Network | Design | Off-chip wgt | Off-chip act | On-chip wgt | On-chip act | PE wgt | PE act | Off-chip total (norm.) | On-chip total (norm.) | PE total (norm.) |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| VGG16 | PTB | 33.63 | 0.19 | 23.62 | 3.86 | 188.97 | 61.84 | 33.82 (1.00x) | 27.49 (1.00x) | 250.81 (1.00x) |
| VGG16 | SpikeX | 33.77 | 0.26 | 26.68 | 3.34 | 213.45 | 26.68 | 34.03 (1.01x) | 30.02 (1.09x) | 240.13 (0.96x) |
| VGG16 | LoAS | 7.57 | 0.42 | 14.73 | 40.26 | 76.36 | 45.80 | 7.99 (0.24x) | 55.00 (2.00x) | 122.16 (0.49x) |
| VGG16 | SATO | 33.77 | 0.26 | 65.40 | 1.68 | 65.40 | 1.68 | 34.03 (1.01x) | 67.07 (2.44x) | 67.07 (0.27x) |
| VGG16 | SpikeFlow | 33.66 | 0.04 | 25.61 | 3.20 | 409.76 | 51.22 | 33.71 (1.00x) | 28.81 (1.05x) | 460.99 (1.84x) |
| VGG16 | Prosperity | 37.79 | 0.44 | 52.34 | 2.91 | 52.34 | 0.00 | 38.23 (1.13x) | 55.25 (2.01x) | 52.34 (0.21x) |
| VGG16 | Ours | 9.38 | 0.19 | 4.33 | 10.59 | 2.71 | 16.31 | 9.57 (0.28x) | 14.92 (0.54x) | 19.02 (0.08x) |
| ResNet18 | PTB | 11.16 | 0.67 | 41.53 | 6.51 | 332.23 | 104.09 | 11.83 (1.00x) | 48.03 (1.00x) | 436.32 (1.00x) |
| ResNet18 | SpikeX | 11.93 | 1.06 | 47.82 | 5.98 | 382.55 | 47.82 | 12.99 (1.10x) | 53.80 (1.12x) | 430.37 (0.99x) |
| ResNet18 | LoAS | 2.52 | 1.04 | 8.03 | 77.66 | 128.40 | 77.66 | 3.56 (0.30x) | 85.68 (1.78x) | 206.06 (0.47x) |
| ResNet18 | SATO | 11.93 | 1.06 | 117.73 | 4.22 | 117.73 | 4.22 | 12.99 (1.10x) | 121.95 (2.54x) | 121.95 (0.28x) |
| ResNet18 | SpikeFlow | 11.39 | 0.15 | 45.66 | 5.71 | 730.53 | 91.32 | 11.54 (0.97x) | 51.37 (1.07x) | 821.85 (1.88x) |
| ResNet18 | Prosperity | 21.50 | 0.66 | 92.82 | 5.53 | 92.82 | 0.00 | 22.16 (1.87x) | 98.36 (2.05x) | 92.82 (0.21x) |
| ResNet18 | Ours | 3.11 | 0.67 | 3.21 | 16.68 | 2.01 | 24.19 | 3.78 (0.32x) | 19.89 (0.41x) | 26.20 (0.06x) |
