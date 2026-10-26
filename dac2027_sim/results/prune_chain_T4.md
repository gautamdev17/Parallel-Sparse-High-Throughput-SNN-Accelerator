# Weight-sparsity sweep, chained CIFAR-10 test image 0, IF T = 4, batch 1 (prune_chain.py)

Normalized to PTB (PTB = 1, lower is better). Energy = core + SRAM + DRAM (45 nm, 500 MHz).

## Norm. latency (PTB = 1)

| Network | Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity | TIDES | TIDES vs best baseline |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---|
| ResNet18 | dense | 87.81 | 1.000 | 1.600 | 1.758 | 1.068 | 0.579 | 0.162 | 1.092 | 0.15x vs Prosperity |
| ResNet18 | sp90 | 89.23 | 1.000 | 1.653 | 0.973 | 0.983 | 0.580 | 0.161 | 0.407 | 0.39x vs Prosperity |
| ResNet18 | sp95 | 88.02 | 1.000 | 1.658 | 0.799 | 0.980 | 0.580 | 0.163 | 0.302 | 0.54x vs Prosperity |
| ResNet19 | dense | 93.26 | 1.000 | 1.647 | 2.079 | 0.552 | 0.641 | 0.103 | 1.154 | 0.09x vs Prosperity |
| ResNet19 | sp90 | 94.45 | 1.000 | 1.678 | 0.775 | 0.562 | 0.643 | 0.108 | 0.262 | 0.41x vs Prosperity |
| ResNet19 | sp95 | 92.66 | 1.000 | 1.714 | 0.621 | 0.556 | 0.646 | 0.109 | 0.174 | 0.63x vs Prosperity |
| VGG16 | dense | 93.63 | 1.000 | 1.311 | 1.598 | 1.285 | 0.513 | 0.118 | 1.022 | 0.12x vs Prosperity |
| VGG16 | sp90 | 93.81 | 1.000 | 1.380 | 1.006 | 1.150 | 0.521 | 0.124 | 0.379 | 0.33x vs Prosperity |
| VGG16 | sp95 | 93.57 | 1.000 | 1.429 | 0.955 | 1.313 | 0.547 | 0.131 | 0.329 | 0.40x vs Prosperity |

