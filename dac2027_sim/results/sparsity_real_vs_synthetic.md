# Real pruned QCFS VGG-16 vs synthetic sparse90

Real: SNN-QCFS-Pruning VGG-16 (DepGraph group_sl, L = 8), INT8 weights (test_quantize.py pipeline), spikes of 16 CIFAR-10 test images. Synthetic: weight density 0.10 (scattered), 10% non-silent neurons, q = 0.3, T = 8. 'work-weighted' = weighted by each layer's dense M x K x N (where the cycles are).

| | Weight density | Non-silent neurons | Spike-bit density | Firing rate of an active neuron |
|---|---|---|---|---|
| Synthetic sparse90 | 0.100 | 0.100 | 0.0307 | 0.31 |
| Real T = 8, work-weighted | 0.370 | 0.151 | 0.0524 | 0.35 |
| Real T = 8, plain mean | 0.274 | 0.121 | 0.0420 | 0.35 |
| Real T = 16, work-weighted | 0.370 | 0.167 | 0.0525 | 0.31 |
| Real T = 16, plain mean | 0.274 | 0.140 | 0.0423 | 0.30 |

Per layer (T = 16):

| Layer | Share of work | Weight density | Non-silent | Spike-bit density |
|---|---|---|---|---|
| layer1.4 | 11.4% | 0.323 | 0.248 | 0.1201 |
| layer2.0 | 5.7% | 0.578 | 0.303 | 0.1143 |
| layer2.4 | 11.4% | 0.643 | 0.260 | 0.0799 |
| layer3.0 | 5.7% | 0.771 | 0.220 | 0.0512 |
| layer3.4 | 11.4% | 0.681 | 0.218 | 0.0562 |
| layer3.8 | 11.4% | 0.671 | 0.178 | 0.0413 |
| layer4.0 | 5.7% | 0.328 | 0.145 | 0.0299 |
| layer4.4 | 11.4% | 0.061 | 0.093 | 0.0227 |
| layer4.8 | 11.4% | 0.014 | 0.052 | 0.0205 |
| layer5.0 | 2.9% | 0.006 | 0.031 | 0.0113 |
| layer5.4 | 2.9% | 0.006 | 0.082 | 0.0259 |
| layer5.8 | 2.9% | 0.011 | 0.153 | 0.0342 |
| classifier.1 | 0.6% | 0.003 | 0.096 | 0.0212 |
| classifier.4 | 5.1% | 0.000 | 0.013 | 0.0037 |
| classifier.7 | 0.0% | 0.010 | 0.007 | 0.0021 |
