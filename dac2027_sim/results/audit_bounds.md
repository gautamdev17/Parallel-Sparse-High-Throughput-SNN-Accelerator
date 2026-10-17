| Network | Batch | Model cycles | compute bound | feeder bound | packer bound | edge bound | LIF bound | model / max bound | binding |
|---|---|---:|---:|---:|---:|---:|---:|---:|---|
| VGG16 | 1 | 405,230 | 51,145 | 339,839 | 162,302 | 164,846 | 14,644 | 1.19 | feeder |
| VGG16 | 16 | 4,634,555 | 819,740 | 4,328,991 | 2,596,844 | 2,638,105 | 233,430 | 1.07 | feeder |
| ResNet18 | 1 | 550,695 | 91,939 | 503,958 | 271,248 | 294,623 | 33,842 | 1.09 | feeder |
| ResNet18 | 16 | 8,019,857 | 1,472,560 | 7,420,989 | 4,339,964 | 4,727,427 | 538,740 | 1.08 | feeder |
