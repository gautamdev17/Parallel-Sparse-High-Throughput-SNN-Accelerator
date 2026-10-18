# DRAM traffic per inference (MB), workload sparse90

Weights / input activations / output spikes; batch 16 is per image. See mem_traffic.py for each design's rule (Prosperity: official simulator; PTB: official model; others: the same tiled rule with each design's format and buffer).

| Network | Design | b1 weights | b1 activations | b1 outputs | b1 total | b16 weights | b16 activations | b16 outputs | b16 total |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|
| VGG16 | PTB | 33.63 | 0.194 | 0.036 | 33.86 | 33.63 | 0.194 | 0.036 | 33.86 |
| VGG16 | SpikeX | 33.77 | 0.260 | 0.285 | 34.32 | 6.71 | 0.460 | 0.285 | 7.45 |
| VGG16 | LoAS | 7.57 | 0.421 | 0.285 | 8.27 | 0.67 | 0.435 | 0.285 | 1.39 |
| VGG16 | SATO | 33.77 | 0.260 | 0.285 | 34.32 | 6.71 | 0.460 | 0.285 | 7.45 |
| VGG16 | SpikeFlow | 33.66 | 0.044 | 0.285 | 33.99 | 4.72 | 0.114 | 0.285 | 5.12 |
| VGG16 | Prosperity | 37.79 | 0.441 | 0.285 | 38.52 | 10.91 | 0.458 | 0.285 | 11.66 |
| VGG16 | Ours | 9.38 | 0.194 | 0.285 | 9.86 | 1.23 | 0.292 | 0.285 | 1.81 |
| ResNet18 | PTB | 11.16 | 0.667 | 0.077 | 11.91 | 11.16 | 0.667 | 0.077 | 11.91 |
| ResNet18 | SpikeX | 11.93 | 1.060 | 0.614 | 13.61 | 4.13 | 1.978 | 0.614 | 6.72 |
| ResNet18 | LoAS | 2.52 | 1.040 | 0.614 | 4.17 | 0.37 | 1.140 | 0.614 | 2.13 |
| ResNet18 | SATO | 11.93 | 1.060 | 0.614 | 13.61 | 4.13 | 1.978 | 0.614 | 6.72 |
| ResNet18 | SpikeFlow | 11.39 | 0.150 | 0.614 | 12.15 | 3.57 | 0.611 | 0.614 | 4.80 |
| ResNet18 | Prosperity | 21.50 | 0.659 | 0.614 | 22.78 | 17.30 | 0.659 | 0.614 | 18.58 |
| ResNet18 | Ours | 3.11 | 0.667 | 0.614 | 4.39 | 0.94 | 0.831 | 0.614 | 2.39 |
