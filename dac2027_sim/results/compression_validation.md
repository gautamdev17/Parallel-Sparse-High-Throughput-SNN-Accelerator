# Stored-bit compression: formats and validation

`storage_compression.py` -> `compression.json`, `compression.png`. Compression ratio = (dense 8-bit weights + dense T-bit spikes) / (packed weight bits + packed spike bits); higher is better. Same matrices for every design: weights 128 x 128 (int8), spikes 128 inputs x 128 pixels, T=8. At sparsity x, exactly x of the weights are zero and exactly x of the neurons are silent; a non-silent neuron has >= 1 spike (each timestep p = 0.3).

| Sparsity | Ours | LoAS | PTB | Phi | SpikeFlow | SpikeX | Prosperity |
|---|---:|---:|---:|---:|---:|---:|---:|
| 50% | 0.71 | 1.58 | 0.94 | 0.20 | 1.23 | 0.89 | 1.00 |
| 70% | 1.19 | 2.30 | 1.13 | 0.21 | 1.40 | 0.89 | 1.00 |
| 80% | 1.69 | 2.99 | 1.25 | 0.21 | 1.51 | 0.89 | 1.00 |
| 90% | 3.00 | 4.26 | 1.40 | 0.21 | 1.63 | 0.89 | 1.00 |
| 95% | 5.41 | 5.41 | 1.49 | 0.22 | 1.70 | 0.89 | 1.00 |
| 98% | 10.88 | 6.46 | 1.55 | 0.22 | 1.75 | 0.89 | 1.00 |

Formats (paper sources; where a width is not given, the choice that reproduces the paper's own measured numbers, else the smallest lossless one):

| Design | Weights | Spikes | Source |
|---|---|---|---|
| Ours | per packed column 4 x (8-bit weight + 2-bit filter label) + 4 x 6-bit filter id | per group 32 spike bits + 32 x 2-bit pixel labels + 4 x 7-bit pixel id + 3-bit count | our RTL (`ours_core.v`, `tb_ours_closed.v`) |
| LoAS | 128-position bitmask fibre + 8-bit non-zeros + 10-bit pointer | 1 bit/neuron + T bits per non-silent neuron + pointer | LoAS Sec IV-A, V (pointer width not given) |
| PTB | dense 8-bit | StSAP stream: TB-tags + T bits per slot + owner bit per TW for pairs + 11-bit neuron address; best TWS | PTB Sec 4.4, Table 4; "no data compression is applied to binary input data" (Sec 6.1.1); slot layout not given |
| Phi | dense 8-bit + 128 x 8-bit pattern-weight products per 16 inputs (9x dense) | pattern-index bitmask + 7-bit index per patterned segment + 6-bit units (1 partial-sum unit per corrected row + 1 per +-1 correction) | Phi Sec 3, 4.2.2, Fig 12; widths fitted to Fig 12 |
| Prosperity | dense 8-bit | dense bits (product sparsity saves computation, not storage) | Prosperity Sec II-A, VII-A |
| SpikeX | dense 8-bit | dense bits + 1-bit activity tag per neuron per TW (TWS=4) | SpikeX Sec III-D |
| SpikeFlow | dense | 1-bit silence label per neuron + T bits per non-silent neuron | SpikeFlow Sec 4.2 |
| SATO | not specified in the paper | not specified | not plotted |

Validation against the papers' own numbers:

| Check | Paper | This model |
|---|---|---|
| Prosperity product sparsity, VGG16 CIFAR100 real spikes (official simulator) | bit 34.21% -> 2.79% (Table I/II) | bit 34.21% -> 2.79% (exact) |
| Prosperity, VGG16 CIFAR10 / ResNet18 CIFAR100 | not reported | 8.96% -> 2.48% / 8.63% -> 2.63% |
| Phi Table 4 random 5% (bit/L1/L2+/L2-, over bit) | 5.0/2.4/2.6/0.0, 2.0x | 5.0/2.7/2.4/0.1, 2.0x |
| Phi Table 4 random 10% | 10.0/6.6/3.4/0.0, 2.9x | 10.0/6.8/3.6/0.3, 2.6x |
| Phi Table 4 random 20% | 19.9/13.9/6.4/0.4, 2.9x | 20.0/15.4/6.2/1.6, 2.6x |
| Phi Table 4 random 50% | 50.0/49.8/7.9/7.7, 3.2x | 50.0/49.4/8.0/7.3, 3.3x |
| Phi on real VGG16 / ResNet18 CIFAR10 spikes (over bit) | 5.8x / 3.7x on the authors' own models (8.7% / 7.4% bit density) | 3.8x / 3.9x on Prosperity's models (9.0% / 9.8%) |
| Phi activation traffic vs dense (Fig 12a) | ~0.47-0.52, geomean ~0.49 | 0.475 (VGG16), 0.466 (ResNet18) |
| Phi weight + PWP traffic without prefetcher (Fig 12b) | ~9x dense weights | 9x (8-bit PWPs) |
| PTB, LoAS, SpikeX, SpikeFlow | report no compression ratio that can be reproduced from their text | format only |

Phi's patterns are calibrated on the evaluated matrix (k-means, Hamming, 128 patterns per 16 inputs), which is what its random-matrix numbers imply (calibrating on an independent draw gives lower gains); this favours Phi. The Phi random check uses a 1024-row matrix (size not given in the paper).
