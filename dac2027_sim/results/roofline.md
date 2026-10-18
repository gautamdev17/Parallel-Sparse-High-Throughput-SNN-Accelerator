# Roofline (sparse90, batch 16, 500 MHz, DRAM 64 GB/s)

Work = effectual accumulations (non-zero weight x spike bit): VGG16 6.55 M, ResNet18 11.77 M per image. Compute roof = adders x 500 MHz; memory roof = 64 GB/s x OI. Ridge point = compute roof / 64 GB/s.

| Network | Design | DRAM (MB/img) | OI (op/B) | Attained (GOP/s) | Compute roof (GOP/s) | Memory roof at OI (GOP/s) | Bound | % of roof |
|---|---|---:|---:|---:|---:|---:|---|---:|
| VGG16 | PTB | 33.86 | 0.193 | 0.88 | 64 | 12.38 | memory | 7% |
| VGG16 | SpikeX | 7.45 | 0.879 | 0.98 | 32 | 56.24 | compute | 3% |
| VGG16 | LoAS | 1.39 | 4.703 | 1.29 | 64 | 300.97 | compute | 2% |
| VGG16 | SATO | 7.45 | 0.879 | 1.95 | 64 | 56.24 | memory | 3% |
| VGG16 | SpikeFlow | 5.12 | 1.279 | 2.05 | 128 | 81.87 | memory | 3% |
| VGG16 | Prosperity | 11.66 | 0.562 | 6.72 | 64 | 35.94 | memory | 19% |
| VGG16 | Ours | 1.81 | 3.618 | 11.44 | 64 | 231.56 | compute | 18% |
| ResNet18 | PTB | 11.91 | 0.988 | 0.92 | 64 | 63.25 | memory | 1% |
| ResNet18 | SpikeX | 6.72 | 1.752 | 0.97 | 32 | 112.11 | compute | 3% |
| ResNet18 | LoAS | 2.13 | 5.532 | 1.36 | 64 | 354.07 | compute | 2% |
| ResNet18 | SATO | 6.72 | 1.752 | 1.73 | 64 | 112.11 | compute | 3% |
| ResNet18 | SpikeFlow | 4.80 | 2.452 | 2.04 | 128 | 156.95 | compute | 2% |
| ResNet18 | Prosperity | 18.58 | 0.634 | 5.91 | 64 | 40.55 | memory | 15% |
| ResNet18 | Ours | 2.39 | 4.933 | 11.80 | 64 | 315.69 | compute | 18% |
