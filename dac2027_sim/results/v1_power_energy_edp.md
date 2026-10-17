### v1 power, energy, EDP (sparse90, batch 1, 800 MHz; power from our RTL of each design, Nangate45)

| Network | Design | Power (mW) | Latency b=1 (ms) | Energy (mJ) | EDP (mJ*ms) |
|---|---|---:|---:|---:|---:|
| VGG16 | LoAS | 90.2 | 3.186 | 0.2875 | 0.91584 |
| VGG16 | SpikeX | 295.7 | 4.170 | 1.2329 | 5.14058 |
| VGG16 | PTB | 600.5 | 4.627 | 2.7785 | 12.85580 |
| VGG16 | SATO | 33.7 | 3.060 | 0.1031 | 0.31564 |
| VGG16 | SpikeFlow | 10925.0 | 2.002 | 21.8672 | 43.76880 |
| VGG16 | Prosperity | 156.2 | 0.833 | 0.1302 | 0.10852 |
| VGG16 | Ours | 382.8 | 0.542 | 0.2074 | 0.11242 |
| ResNet18 | LoAS | 90.2 | 5.420 | 0.4892 | 2.65149 |
| ResNet18 | SpikeX | 295.7 | 7.472 | 2.2093 | 16.50816 |
| ResNet18 | PTB | 600.5 | 7.941 | 4.7689 | 37.87058 |
| ResNet18 | SATO | 33.7 | 4.444 | 0.1498 | 0.66550 |
| ResNet18 | SpikeFlow | 10925.0 | 3.568 | 38.9789 | 139.07125 |
| ResNet18 | Prosperity | 156.2 | 1.282 | 0.2003 | 0.25671 |
| ResNet18 | Ours | 382.8 | 0.688 | 0.2635 | 0.18140 |

Normalized to PTB = 1x in v1_power_energy_edp.png. SpikeFlow is not plotted: its power report is not physical (10.75 W combinational internal vs 16 mW switching) and must be re-measured.
