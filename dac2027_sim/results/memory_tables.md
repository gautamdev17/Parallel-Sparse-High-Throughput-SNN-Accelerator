### Workload sparse90, DRAM 64 GB/s, 64 KB operand buffer, 800 MHz

| Network | Design | DRAM traffic b=1 (MB) | Compute-only latency (ms) | With memory latency (ms) | Memory-bound? | Throughput b=16 with memory (img/s) |
|---|---|---:|---:|---:|---|---:|
| VGG16 | loas_zip | 7.67 | 11.217 | 11.225 | no | 89 |
| VGG16 | spikex | 34.10 | 4.170 | 4.200 | no | 240 |
| VGG16 | ptb (official sim, own DRAM model) | – | – | 4.627 | – | 215 |
| VGG16 | sato | 34.10 | 3.060 | 3.060 | no | 478 |
| VGG16 | spikeflow | 33.73 | 2.002 | 2.181 | no | 502 |
| VGG16 | prosperity (official sim, own DRAM model) | – | – | 0.833 | – | 1,642 |
| VGG16 | ours | 8.20 | 0.507 | 0.516 | no | 2,755 |
| ResNet18 | loas_zip | 2.80 | 18.846 | 18.856 | no | 53 |
| ResNet18 | spikex | 12.45 | 7.472 | 7.489 | no | 132 |
| ResNet18 | ptb (official sim, own DRAM model) | – | – | 7.941 | – | 125 |
| ResNet18 | sato | 12.45 | 4.444 | 4.444 | no | 235 |
| ResNet18 | spikeflow | 11.45 | 3.568 | 3.580 | no | 278 |
| ResNet18 | prosperity (official sim, own DRAM model) | – | – | 1.282 | – | 804 |
| ResNet18 | ours | 3.84 | 0.688 | 0.703 | no | 1,593 |

### Workload sparse90, DRAM 30 GB/s, 64 KB operand buffer, 800 MHz

| Network | Design | DRAM traffic b=1 (MB) | Compute-only latency (ms) | With memory latency (ms) | Memory-bound? | Throughput b=16 with memory (img/s) |
|---|---|---:|---:|---:|---|---:|
| VGG16 | loas_zip | 7.67 | 11.217 | 11.233 | no | 89 |
| VGG16 | spikex | 34.10 | 4.170 | 4.584 | no | 240 |
| VGG16 | ptb (official sim, own DRAM model) | – | – | 4.627 | – | 215 |
| VGG16 | sato | 34.10 | 3.060 | 3.060 | no | 478 |
| VGG16 | spikeflow | 33.73 | 2.002 | 2.651 | no | 501 |
| VGG16 | prosperity (official sim, own DRAM model) | – | – | 0.833 | – | 1,642 |
| VGG16 | ours | 8.20 | 0.507 | 0.566 | no | 2,747 |
| ResNet18 | loas_zip | 2.80 | 18.846 | 18.866 | no | 53 |
| ResNet18 | spikex | 12.45 | 7.472 | 7.508 | no | 132 |
| ResNet18 | ptb (official sim, own DRAM model) | – | – | 7.941 | – | 125 |
| ResNet18 | sato | 12.45 | 4.444 | 4.444 | no | 235 |
| ResNet18 | spikeflow | 11.45 | 3.568 | 3.593 | no | 278 |
| ResNet18 | prosperity (official sim, own DRAM model) | – | – | 1.282 | – | 804 |
| ResNet18 | ours | 3.84 | 0.688 | 0.719 | no | 1,590 |
