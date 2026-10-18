### Cycles, real spike trains (Prosperity CIFAR-10 traces, first 8 steps), synthetic weights

| Workload | Network | Batch | LoAS | LoAS-overlap | +C1 | +C1+C2 | +C1+C2+C3 | LoAS+ vs LoAS | LoAS+ vs LoAS-overlap |
|---|---|---|---:|---:|---:|---:|---:|---:|---:|
| real-spikes wd=0.1 | VGG16 | 1 | 10,352,867 | 9,094,815 | 5,760,659 | 4,722,273 | 2,807,272 | **3.69x** | **3.24x** |
| real-spikes wd=0.1 | ResNet18 | 1 | 6,031,413 | 5,297,516 | 3,289,093 | 2,737,488 | 1,623,283 | **3.72x** | **3.26x** |
| real-spikes wd=0.02 | VGG16 | 1 | 7,026,352 | 5,991,145 | 3,116,152 | 3,109,460 | 1,442,968 | **4.87x** | **4.15x** |
| real-spikes wd=0.02 | ResNet18 | 1 | 3,895,036 | 3,301,502 | 1,763,996 | 1,760,894 | 829,734 | **4.69x** | **3.98x** |
