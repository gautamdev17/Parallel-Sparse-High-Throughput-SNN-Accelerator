| Network | Design | Area (mm²) | Power (mW) | Latency b=1 (ms) | Energy b=1 (mJ) | EDP (mJ·ms) | Energy/img b=16 (mJ) |
|---|---|---:|---:|---:|---:|---:|---:|
| VGG16 | LoAS (16 TPPE) | 0.370 | 90.2 | 11.236 | 1.0140 | 11.39397 | 1.0124 |
| VGG16 | SpikeX (8x8) | 0.468 | 278.2 | 4.174 | 1.1612 | 4.84671 | 1.1607 |
| VGG16 | PTB (16x8) | 0.953 | 535.9 | 4.627 | 2.4796 | 11.47264 | 2.4886 |
| VGG16 | SATO (128 PE) | 0.076 | 33.7 | 3.065 | 0.1033 | 0.31649 | 0.0706 |
| VGG16 | Ours (4x4) | 0.731 | 382.8 | 0.511 | 0.1957 | 0.10004 | 0.1387 |
| ResNet18 | LoAS (16 TPPE) | 0.370 | 90.2 | 18.869 | 1.7029 | 32.13235 | 1.7009 |
| ResNet18 | SpikeX (8x8) | 0.468 | 278.2 | 7.477 | 2.0804 | 15.55566 | 2.1002 |
| ResNet18 | PTB (16x8) | 0.953 | 535.9 | 7.941 | 4.2558 | 33.79608 | 4.2922 |
| ResNet18 | SATO (128 PE) | 0.076 | 33.7 | 4.449 | 0.1499 | 0.66707 | 0.1432 |
| ResNet18 | Ours (4x4) | 0.731 | 382.8 | 0.695 | 0.2658 | 0.18462 | 0.2400 |

| Design | Paper reports | Paper area | Paper power | Ours (Nangate45, our clock 800 MHz) | Ours at the paper's clock |
|---|---|---:|---:|---:|---:|
| LoAS (16 TPPE) | TPPE x 16 (zip synthesis) | 0.5255 mm² | 79.4 mW @zip,560MHz | 0.3700 mm² / 90.2 mW | 63.2 mW |
| SATO (128 PE) | Core = PE array + adder-search tree (Sec. 4.1) | 0.0203 mm² | 47.7 mW @28nm,200MHz -> 45nm: 0.0524 mm² / 114.6 mW | 0.0755 mm² / 33.7 mW | 8.4 mW |

Missing (power not measured yet): spikeflow, prosperity
