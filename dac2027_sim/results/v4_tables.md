### v4: 16 PEs in every design, LoAS from loas_model.py, workload sparse90 (T=8, 800 MHz)

| Network | Design | Latency (ms) | Normalized latency | Throughput (img/s) | Normalized throughput |
|---|---|---:|---:|---:|---:|
| VGG16 | LoAS | 3.186 | 1.000 | 315 | 1.00 |
| VGG16 | SpikeX | 13.126 | 4.121 | 76 | 0.24 |
| VGG16 | PTB | 32.386 | 10.166 | 31 | 0.10 |
| VGG16 | SATO | 7.103 | 2.230 | 152 | 0.48 |
| VGG16 | SpikeFlow | 13.133 | 4.122 | 76 | 0.24 |
| VGG16 | Prosperity | 4.288 | 1.346 | 235 | 0.75 |
| VGG16 | Ours | 0.507 | 0.159 | 2,762 | 8.78 |
| ResNet18 | LoAS | 5.420 | 1.000 | 185 | 1.00 |
| ResNet18 | SpikeX | 23.599 | 4.354 | 42 | 0.23 |
| ResNet18 | PTB | 53.322 | 9.837 | 19 | 0.10 |
| ResNet18 | SATO | 12.447 | 2.296 | 81 | 0.44 |
| ResNet18 | SpikeFlow | 23.610 | 4.356 | 42 | 0.23 |
| ResNet18 | Prosperity | 7.616 | 1.405 | 131 | 0.71 |
| ResNet18 | Ours | 0.688 | 0.127 | 1,596 | 8.64 |

Ours and LoAS PEs have 8 adders each (one per timestep); the other designs' PEs have 1.
