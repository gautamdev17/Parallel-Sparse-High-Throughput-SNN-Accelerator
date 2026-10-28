# Pruning sweep: speed-up over PTB (normalized latency at batch 1, normalized throughput at batch 16)

| Network | Level | Weight density % | Firing rate % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity | TIDES | TIDES vs best baseline |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| **latency** | | | | | | | | | | | |
| CifarNet | dense | 100 | 5.09 | 1.00 | 0.66 | 0.90 | 4.19 | 1.57 | 11.42 | 1.98 | 0.17x vs Prosperity |
| CifarNet | 2e-7 | 72.52 | 4.73 | 1.00 | 0.67 | 1.03 | 4.24 | 1.59 | 11.59 | 2.21 | 0.19x vs Prosperity |
| CifarNet | 5e-7 | 45.92 | 3.61 | 1.00 | 0.75 | 1.32 | 4.35 | 1.70 | 12.29 | 3.32 | 0.27x vs Prosperity |
| CifarNet | 1e-6 | 19.15 | 2.66 | 1.00 | 0.82 | 1.80 | 4.24 | 1.80 | 12.85 | 7.15 | 0.56x vs Prosperity |
| CifarNet | 1.5e-6 | 8.84 | 2.14 | 1.00 | 0.87 | 2.06 | 4.07 | 1.88 | 13.13 | 13.06 | 0.99x vs Prosperity |
| CifarNet | 2e-6 | 5.24 | 1.74 | 1.00 | 0.91 | 1.97 | 3.80 | 1.94 | 13.30 | 18.18 | 1.37x vs Prosperity |
| ResNet19-tdBN | dense | 100 | 6.83 | 1.00 | 0.56 | 0.81 | 4.06 | 1.40 | 10.39 | 1.97 | 0.19x vs Prosperity |
| ResNet19-tdBN | 5e-7 | 7.29 | 5.52 | 1.00 | 0.62 | 2.96 | 4.29 | 1.49 | 11.21 | 12.92 | 1.15x vs Prosperity |
| ResNet19-tdBN | 1e-6 | 3.41 | 3.91 | 1.00 | 0.71 | 3.10 | 4.39 | 1.63 | 12.44 | 22.56 | 1.81x vs Prosperity |
| ResNet19-tdBN | 2e-6 | 1.52 | 2.28 | 1.00 | 0.85 | 2.88 | 4.01 | 1.84 | 14.23 | 30.57 | 2.15x vs Prosperity |
| ResNet19-tdBN | 2.5e-6 | 1.15 | 1.9 | 1.00 | 0.89 | 2.87 | 3.75 | 1.90 | 14.71 | 29.08 | 1.98x vs Prosperity |
| ResNet19-tdBN | 3e-6 | 0.91 | 1.61 | 1.00 | 0.92 | 2.92 | 3.51 | 1.96 | 15.15 | 27.52 | 1.82x vs Prosperity |
| ResNet18 | dense | 100 | 10.39 | 1.00 | 0.48 | 0.73 | 2.77 | 1.31 | 6.89 | 1.78 | 0.26x vs Prosperity |
| ResNet18 | 5e-7 | 32.69 | 9.99 | 1.00 | 0.49 | 1.47 | 2.80 | 1.32 | 7.00 | 3.45 | 0.49x vs Prosperity |
| ResNet18 | 1e-6 | 15.14 | 8.65 | 1.00 | 0.52 | 2.26 | 2.96 | 1.37 | 7.44 | 6.51 | 0.88x vs Prosperity |
| ResNet18 | 2e-6 | 6.4 | 6.58 | 1.00 | 0.60 | 3.05 | 3.17 | 1.49 | 8.28 | 13.50 | 1.63x vs Prosperity |
| ResNet18 | 3e-6 | 3.88 | 5.15 | 1.00 | 0.67 | 3.23 | 3.25 | 1.60 | 9.01 | 19.65 | 2.18x vs Prosperity |
| ResNet18 | 4e-6 | 2.67 | 3.98 | 1.00 | 0.74 | 3.16 | 3.21 | 1.71 | 9.73 | 24.91 | 2.56x vs Prosperity |
| VGGSNN-DVS | dense | 100 | 5.38 | 1.00 | 0.63 | 0.86 | 4.30 | 1.52 | 11.36 | 1.99 | 0.17x vs Prosperity |
| VGGSNN-DVS | 2e-6 | 11.44 | 4.69 | 1.00 | 0.66 | 2.44 | 4.37 | 1.57 | 11.87 | 9.71 | 0.82x vs Prosperity |
| VGGSNN-DVS | 5e-6 | 5.91 | 3.28 | 1.00 | 0.76 | 2.56 | 4.30 | 1.71 | 13.11 | 16.62 | 1.27x vs Prosperity |
| VGGSNN-DVS | 7e-6 | 4.49 | 2.8 | 1.00 | 0.80 | 2.49 | 4.19 | 1.77 | 13.64 | 20.20 | 1.48x vs Prosperity |
| VGGSNN-DVS | 1e-5 | 3.2 | 2.34 | 1.00 | 0.84 | 2.39 | 3.99 | 1.83 | 14.14 | 24.99 | 1.77x vs Prosperity |
| VGGSNN-DVS | 1.5e-5 | 1.96 | 1.76 | 1.00 | 0.91 | 2.24 | 3.61 | 1.94 | 15.04 | 26.18 | 1.74x vs Prosperity |
| ResNet18-ImageNet | dense | 100 | 15.37 | 1.00 | 0.44 | 0.72 | 2.52 | 1.37 | 6.36 | 1.56 | 0.25x vs Prosperity |
| ResNet18-ImageNet | 7e-8 | 41.67 | 13.38 | 1.00 | 0.44 | 1.26 | 2.55 | 1.31 | 6.46 | 2.81 | 0.43x vs Prosperity |
| ResNet18-ImageNet | 1.5e-7 | 29.86 | 11.29 | 1.00 | 0.47 | 1.59 | 2.69 | 1.33 | 6.86 | 3.64 | 0.53x vs Prosperity |
| ResNet18-ImageNet | 2e-7 | 25.75 | 11.09 | 1.00 | 0.47 | 1.74 | 2.71 | 1.34 | 6.92 | 4.05 | 0.58x vs Prosperity |
| ResNet18-ImageNet | 3e-7 | 20.75 | 9.5 | 1.00 | 0.51 | 2.00 | 2.86 | 1.38 | 7.37 | 5.03 | 0.68x vs Prosperity |
| Spikformer-8-384 | dense | 100 | 14.61 | 1.00 | 0.44 | 0.72 | 2.16 | 1.36 | 7.89 | 1.61 | 0.20x vs Prosperity |
| Spikformer-8-384 | 1e-6 | 52.24 | 11.15 | 1.00 | 0.46 | 1.10 | 2.21 | 1.33 | 8.38 | 2.49 | 0.30x vs Prosperity |
| Spikformer-8-384 | 2e-6 | 39.27 | 13.51 | 1.00 | 0.44 | 1.32 | 2.15 | 1.33 | 7.92 | 2.90 | 0.37x vs Prosperity |
| Spikformer-8-384 | 3e-6 | 33.07 | 11.38 | 1.00 | 0.46 | 1.48 | 2.20 | 1.32 | 8.31 | 3.32 | 0.40x vs Prosperity |
