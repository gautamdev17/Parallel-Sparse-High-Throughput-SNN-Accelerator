# Our baseline models vs the papers' own published numbers

Scaling: 45 nm -> 28 nm area x 0.387, power x 0.486 (Stillmaker & Baas 2017); 32 nm log-interpolated (area x 0.506,
power x 0.595). Dynamic power scaled to the paper's clock, leakage unchanged. Our numbers: hw/build/*_power.rpt
(gate-level, Nangate45, our RTL of each design), hw/same_node_table.py.

## Speed (official simulators, the papers' own benchmarks)

| Benchmark | Prosperity paper ref | Our run | PTB paper ref | Our run |
|---|---:|---:|---:|---:|
| VGG16 CIFAR10 | 21.504 ms | 21.504 ms | 145.917 ms | 145.917 ms |
| VGG16 CIFAR100 | 33.577 ms | 33.608 ms | 316.902 ms | 316.902 ms |
| ResNet18 CIFAR10 | 11.764 ms | 11.825 ms | 80.507 ms | 80.507 ms |
| ResNet18 CIFAR100 | 11.631 ms | 11.720 ms | 96.489 ms | 96.489 ms |

Prosperity's claim over PTB on VGG16 (Table IV, 390.10 / 41.37 GOP/s = 9.43x) is reproduced: 316.9 / 33.6 ms =
9.43x. SATO's official model also matches its reference (results/sato_reference_check.json).

## Area and power (our RTL, scaled to the paper's node and clock)

| Design (what the paper reports) | Node / clock | Paper area (mm²) | Ours (mm²) | Ours / paper | Paper power (mW) | Ours (mW) | Ours / paper |
|---|---|---:|---:|---:|---:|---:|---:|
| Prosperity core, excl. buffers and DRAM (Fig. 10) | 28 nm / 500 MHz | 0.225 | 0.143 | 0.64 | 367.1 | 116.6 | 0.32 |
| SATO core: PEs + adder-search tree (Table 2) | 28 nm / 200 MHz | 0.0203 | 0.0292 | 1.44 | 47.7 | 4.6 | 0.10 |
| LoAS 16 TPPEs (Table IV) | 32 nm / 800 MHz | 0.96 | 0.19 | 0.19 | 45.1 | 52.1 | 1.16 |
| SpikeFlow whole accelerator (Table 3) | 45 nm / 100 MHz | 1.195 | 0.207 | 0.17 | 127.2 | 11.3 | 0.09 |

PTB and SpikeX report no synthesis (CACTI-only), so there is nothing to compare.

## Reading

- Speed models of Prosperity, PTB and SATO match their papers within 0.8%.
- Our RTL of the baselines comes out at or below the papers' own power: Prosperity 3x lower, SATO and SpikeFlow about
  10x lower, LoAS within 16%. Different flows (commercial 28 nm DC vs Yosys/Nangate45), workloads (Spikformer,
  real CIFAR spikes) and what each paper keeps inside its RTL (SpikeFlow's buffers are in its RTL: 1.19 mm²) explain
  part of it.
- Direction: the baselines' power in our comparison is lower than the papers claim, so our energy and EDP advantages
  are conservative; with the papers' own core power they would be larger.
