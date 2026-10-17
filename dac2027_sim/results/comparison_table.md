# Comparison with published SNN accelerators

Baseline numbers are as reported in each paper (GOP/s, GOP/J only where the paper reports them; Phi Table 2 for PTB / SATO / Stellar so one column has one source). 'OP' = one accumulation per '1' spike bit per output channel (Phi's definition; Prosperity and SATO do not define it).

| Design | Venue | Node | Clock | Area (mm^2) | Power (mW) | GOP/s | GOP/J | Workload of the GOP numbers | Notes |
|---|---|---|---|---:|---:|---:|---:|---|---|
| PTB | HPCA'22 | 32 nm (CACTI only) | - | - | - | 18.12* | 10.65* | VGG16/CIFAR100 (from Phi Table 2) | no synthesis reported |
| SpikeX | TCAD | 32 nm (CACTI only) | - | - | - | - | - | - | only normalized results |
| SATO | DAC'22 | 28 nm | 200 MHz | 1.13 (core 0.0203) | 127.8 (core 47.73) | 36.01* (own: 3970.1) | 53.22* | VGG16/CIFAR100 (Phi Table 2) | own GOP/s undefined OP |
| SpikeFlow | JSA'25 | 45 nm (Nangate) | 100 MHz | 1.195 | 127.2 | - | - | - | only normalized results |
| LoAS | MICRO'24 | 32 nm | 800 MHz | 2.08 (incl. 256 KB SRAM) | 188.9 | - | - | - | only normalized results |
| Prosperity | HPCA'25 | 28 nm | 500 MHz | 0.529 (incl. buffers) | 915 (incl. DRAM) | 390.10 | 299.80 | VGG16/CIFAR100 (own Table IV) | OP not defined |
| Phi | ISCA'25 | 28 nm | 500 MHz | 0.662 (incl. 240 KB buffers) | 346.6 (on-chip) | 242.80 | 285.81 | VGG16/CIFAR100 (own Table 2) | GOP/J likely incl. DRAM |
| **Ours** (target clock) | - | 28 nm (scaled from 45 nm) | 500 MHz | 0.712 (incl. 260 KB SRAM) | 453.4 (core + SRAM) | 75.4 | 166 | VGG16, sparse90 synthetic | needs pipelined packer/LIF/edge |
| Ours (as synthesized) | - | 28 nm (scaled) | 48 MHz | 0.712 | 161.0 | 7.3 | 45 | VGG16, sparse90 synthetic | current RTL timing |

\* PTB, SATO numbers as re-simulated by Phi (Table 2, 500 MHz, 28 nm); Prosperity's Table IV gives different values for the same baselines (PTB 41.37 / 34.15, SATO 33.63 / 49.70), so sources are not mixed within a column.
Workloads differ: the baselines' VGG16/CIFAR100 spikes are ~10% (Phi) to 34% (Prosperity) dense with dense weights; our sparse90 workload has 90%-sparse weights and ~4% spike bits, so GOP/s (which counts every output channel per spike) is not a like-for-like speed comparison -- the latency/throughput figures are.
