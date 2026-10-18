### Cycles, real spike trains (Prosperity CIFAR-10 traces, first 8 steps), synthetic weights

| Workload | Network | Batch | LoAS | LoAS-overlap | +C1 | +C1+C2 | +C1+C2+C3 | LoAS+ vs LoAS | LoAS+ vs LoAS-overlap |
|---|---|---|---:|---:|---:|---:|---:|---:|---:|
| real-spikes wd=0.1 | VGG16 | 1 | 10,352,867 | 9,094,815 | 6,908,711 | 5,423,701 | 3,442,891 | **3.01x** | **2.64x** |
| real-spikes wd=0.1 | ResNet18 | 1 | 6,031,413 | 5,297,516 | 3,974,673 | 3,097,426 | 1,947,703 | **3.10x** | **2.72x** |
| real-spikes wd=0.02 | VGG16 | 1 | 7,026,352 | 5,991,145 | 4,093,702 | 3,841,796 | 2,029,197 | **3.46x** | **2.95x** |
| real-spikes wd=0.02 | ResNet18 | 1 | 3,895,036 | 3,301,502 | 2,296,756 | 2,161,298 | 1,133,533 | **3.44x** | **2.91x** |
