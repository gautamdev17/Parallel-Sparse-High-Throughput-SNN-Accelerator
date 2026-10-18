# Dataflow ablation: WS vs IS vs OS (4x4 PEs, T = 8 adders, sparse90, batch 1, analytical)

| Network | Dataflow | Packing used | Ideal cycles | Cycles with overheads | vs WS | Adder utilization | Weight reads (MB) | Spike reads, raw + packed (MB) | Partial sums / outputs (MB) | On-chip total (MB) |
|---|---|---|---:|---:|---:|---:|---:|---:|---:|---:|
| VGG16 | WS (ours) | weights + spikes | 339,839 | 364,930 | 1.00x | 14.0% | 4.33 | 10.59 | 126.60 | 141.52 |
| VGG16 | IS | weights + spikes | 638,006 | 685,111 | 1.88x | 7.5% | 5.10 | 7.27 | 126.60 | 138.98 |
| VGG16 | OS | weights + spikes | 1,135,334 | 1,151,984 | 3.16x | 4.4% | 5.47 | 25.51 | 0.28 | 31.27 |
| ResNet18 | WS (ours) | weights + spikes | 503,958 | 543,056 | 1.00x | 16.9% | 3.21 | 16.68 | 226.27 | 246.17 |
| ResNet18 | IS | weights + spikes | 634,135 | 683,332 | 1.26x | 13.5% | 5.07 | 11.77 | 226.27 | 243.11 |
| ResNet18 | OS | weights + spikes | 1,878,125 | 1,902,135 | 3.50x | 4.8% | 4.34 | 43.18 | 0.61 | 48.14 |
