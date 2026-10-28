# VGG-16, CIFAR-10, IF: speed-up over PTB at T = 4 / 8 / 16 / 32, DRAM 64 GB/s, batch 1 (tsweep_speedup.py)

Models as audited_vgg16.py at every T. Latency per layer = max(compute, DRAM bits / 1024 b per cycle).

## T = 4

| Level | Acc % | PTB latency (ms) | SpikeX | LoAS | SATO | SpikeFlow | Prosperity | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 93.63 | 9.287 | 0.44 | 0.18 | 2.26 | 1.11 | **2.75** | 0.56 | Prosperity |
| 90 | 93.81 | 9.443 | 0.43 | 0.46 | 2.15 | 1.13 | **2.78** | 1.56 | Prosperity |
| 95 | 93.57 | 9.675 | 0.45 | 0.62 | 2.18 | 1.17 | **2.83** | 1.95 | Prosperity |
| 98 | 92.43 | 9.592 | 0.45 | 0.87 | 2.17 | 1.18 | **2.81** | 2.71 | Prosperity |

## T = 8

| Level | Acc % | PTB latency (ms) | SpikeX | LoAS | SATO | SpikeFlow | Prosperity | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 11.257 | 0.29 | 0.17 | 1.49 | 0.75 | **1.98** | 0.59 | Prosperity |
| 90 | 95.27 | 11.329 | 0.29 | 0.48 | 1.40 | 0.76 | **1.97** | 1.61 | Prosperity |
| 95 | 95.20 | 11.334 | 0.29 | 0.64 | 1.44 | 0.76 | **1.97** | 1.96 | Prosperity |
| 98 | 94.51 | 11.247 | 0.29 | 0.93 | 1.40 | 0.78 | 1.94 | **2.73** | TIDES |

## T = 16

| Level | Acc % | PTB latency (ms) | SpikeX | LoAS | SATO | SpikeFlow | Prosperity | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.80 | 28.329 | 0.28 | 0.39 | 1.78 | 1.12 | **2.72** | 1.29 | Prosperity |
| 90 | 95.77 | 28.862 | 0.29 | 1.15 | 1.72 | 1.16 | 2.72 | **3.57** | TIDES |
| 95 | 95.80 | 28.839 | 0.29 | 1.50 | 1.77 | 1.14 | 2.73 | **4.31** | TIDES |
| 98 | 95.42 | 28.302 | 0.29 | 2.21 | 1.74 | 1.15 | 2.66 | **5.96** | TIDES |

## T = 32

| Level | Acc % | PTB latency (ms) | SpikeX | LoAS | SATO | SpikeFlow | Prosperity | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.88 | 69.404 | 0.32 | 0.90 | 2.12 | 1.44 | **3.44** | 2.83 | Prosperity |
| 90 | 95.93 | 69.612 | 0.33 | 2.68 | 2.04 | 1.47 | 3.40 | **7.69** | TIDES |
| 95 | 95.89 | 69.619 | 0.32 | 3.50 | 2.08 | 1.44 | 3.44 | **9.22** | TIDES |
| 98 | 95.69 | 68.499 | 0.33 | 5.19 | 2.09 | 1.47 | 3.35 | **12.88** | TIDES |

