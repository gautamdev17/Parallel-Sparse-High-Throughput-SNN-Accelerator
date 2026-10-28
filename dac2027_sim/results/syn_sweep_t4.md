# Synthetic ResNet-19 (CIFAR-10 shapes), T = 4, batch 1: latency speed-up over PTB (syn_sweep_t4.py)

| Sweep | Weight sparsity % | Silent neurons % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity | TIDES | TIDES vs best baseline |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| wgt | 0 | 86.49 | 1.00 | 0.73 | 0.64 | 2.27 | 1.77 | 8.15 | 1.57 | 0.19x vs Prosperity |
| wgt | 50 | 86.49 | 1.00 | 0.73 | 0.81 | 2.27 | 1.77 | 8.21 | 2.61 | 0.32x vs Prosperity |
| wgt | 70 | 86.49 | 1.00 | 0.73 | 0.99 | 2.29 | 1.77 | 8.19 | 4.03 | 0.49x vs Prosperity |
| wgt | 80 | 86.49 | 1.00 | 0.74 | 1.13 | 2.28 | 1.78 | 8.22 | 5.61 | 0.68x vs Prosperity |
| wgt | 90 | 86.49 | 1.00 | 0.73 | 1.35 | 2.29 | 1.78 | 8.22 | 9.29 | 1.13x vs Prosperity |
| wgt | 92.68 | 86.49 | 1.00 | 0.73 | 1.43 | 2.27 | 1.77 | 8.19 | 11.30 | 1.38x vs Prosperity |
| wgt | 95 | 86.49 | 1.00 | 0.74 | 1.50 | 2.27 | 1.78 | 8.20 | 14.26 | 1.74x vs Prosperity |
| wgt | 98 | 86.49 | 1.00 | 0.73 | 1.76 | 2.27 | 1.77 | 8.16 | 19.87 | 2.44x vs Prosperity |
| wgt | 99 | 86.49 | 1.00 | 0.73 | 2.28 | 2.28 | 1.77 | 8.18 | 21.97 | 2.68x vs Prosperity |
| act | 92.68 | 70 | 1.00 | 0.45 | 1.74 | 2.18 | 1.38 | 6.72 | 8.44 | 1.26x vs Prosperity |
| act | 92.68 | 80 | 1.00 | 0.60 | 1.63 | 2.35 | 1.59 | 7.59 | 10.17 | 1.34x vs Prosperity |
| act | 92.68 | 90 | 1.00 | 0.83 | 1.24 | 2.11 | 1.92 | 8.57 | 11.86 | 1.38x vs Prosperity |
| act | 92.68 | 95 | 1.00 | 1.06 | 0.85 | 1.56 | 2.27 | 9.21 | 10.52 | 1.14x vs Prosperity |
| act | 92.68 | 97 | 1.00 | 1.26 | 0.66 | 1.19 | 2.62 | 9.51 | 7.73 | 0.81x vs Prosperity |
