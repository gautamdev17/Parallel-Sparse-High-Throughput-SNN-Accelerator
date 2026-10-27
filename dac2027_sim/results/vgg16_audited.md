# VGG-16, IF T = 8, snn-pruning-DAC dense/90/95/98 %: baselines audited against their papers (audited_vgg16.py)

Normalized to the paper-faithful PTB. TIDES RTL cycle-exact. Batch 1, 500 MHz, 45 nm. Speed-up: higher is better; energy, EDP: lower is better. 'official sim.' = the models used before the audit.

## Speedup over PTB (paper model), DRAM 64 GB/s (1024 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper, lenient) | SATO (paper, strict) | SpikeFlow (paper) | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 0.421 | 0.287 | 0.172 | **2.249** | 1.022 | 0.729 | 3.570 | 1.984 | 0.594 | SATO (paper, lenient) |
| 90 | 95.27 | 0.429 | 0.286 | 0.482 | **2.055** | 0.986 | 0.737 | 3.461 | 1.966 | 1.611 | SATO (paper, lenient) |
| 95 | 95.20 | 0.442 | 0.286 | 0.637 | **2.099** | 1.007 | 0.737 | 3.477 | 1.973 | 1.963 | SATO (paper, lenient) |
| 98 | 94.51 | 0.468 | 0.287 | 0.926 | 2.036 | 0.991 | 0.755 | 3.390 | 1.935 | **2.725** | TIDES |

## Speedup over PTB (paper model), DRAM 16 GB/s (256 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper, lenient) | SATO (paper, strict) | SpikeFlow (paper) | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 0.457 | 0.312 | 0.187 | **1.835** | 1.013 | 0.784 | 2.410 | 1.752 | 0.632 | SATO (paper, lenient) |
| 90 | 95.27 | 0.465 | 0.310 | 0.523 | 1.733 | 0.976 | 0.787 | 2.389 | 1.737 | **1.746** | TIDES |
| 95 | 95.20 | 0.486 | 0.314 | 0.699 | 1.773 | 0.996 | 0.784 | 2.423 | 1.770 | **2.156** | TIDES |
| 98 | 94.51 | 0.519 | 0.314 | 1.027 | 1.738 | 0.987 | 0.792 | 2.409 | 1.763 | **3.021** | TIDES |

## Speedup over PTB (paper model), DRAM 8 GB/s (128 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper, lenient) | SATO (paper, strict) | SpikeFlow (paper) | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 0.546 | 0.369 | 0.223 | 1.528 | 1.015 | 0.827 | 1.789 | **1.545** | 0.612 | Prosperity (paper pipeline) |
| 90 | 95.27 | 0.554 | 0.365 | 0.623 | 1.476 | 0.984 | 0.833 | 1.788 | 1.535 | **1.969** | TIDES |
| 95 | 95.20 | 0.578 | 0.364 | 0.833 | 1.507 | 1.001 | 0.828 | 1.814 | 1.559 | **2.518** | TIDES |
| 98 | 94.51 | 0.596 | 0.363 | 1.225 | 1.499 | 0.993 | 0.830 | 1.813 | 1.559 | **3.593** | TIDES |

## Energy (PTB paper model = 1), DRAM 64 GB/s (1024 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper, lenient) | SATO (paper, strict) | SpikeFlow (paper) | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.613 | 1.350 | 2.035 | **0.613** | 0.626 | 0.654 | 0.787 | 0.849 | 2.415 | SATO (paper, lenient) |
| 90 | 95.27 | 1.596 | 1.355 | 0.656 | **0.615** | 0.629 | 0.649 | 0.788 | 0.850 | 0.687 | SATO (paper, lenient) |
| 95 | 95.20 | 1.564 | 1.356 | 0.528 | 0.614 | 0.627 | 0.652 | 0.787 | 0.849 | **0.523** | TIDES |
| 98 | 94.51 | 1.507 | 1.352 | 0.380 | 0.617 | 0.630 | 0.649 | 0.792 | 0.854 | **0.348** | TIDES |

## Energy (PTB paper model = 1), DRAM 16 GB/s (256 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper, lenient) | SATO (paper, strict) | SpikeFlow (paper) | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.553 | 1.300 | 1.960 | **0.594** | 0.606 | 0.631 | 0.804 | 0.849 | 2.338 | SATO (paper, lenient) |
| 90 | 95.27 | 1.538 | 1.306 | 0.632 | **0.596** | 0.609 | 0.626 | 0.804 | 0.850 | 0.662 | SATO (paper, lenient) |
| 95 | 95.20 | 1.499 | 1.299 | 0.506 | 0.591 | 0.603 | 0.627 | 0.799 | 0.844 | **0.501** | TIDES |
| 98 | 94.51 | 1.437 | 1.299 | 0.362 | 0.592 | 0.604 | 0.623 | 0.799 | 0.845 | **0.332** | TIDES |

## Energy (PTB paper model = 1), DRAM 8 GB/s (128 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper, lenient) | SATO (paper, strict) | SpikeFlow (paper) | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.424 | 1.199 | 1.797 | **0.550** | 0.560 | 0.587 | 0.805 | 0.833 | 2.266 | SATO (paper, lenient) |
| 90 | 95.27 | 1.411 | 1.207 | 0.580 | **0.553** | 0.563 | 0.583 | 0.805 | 0.834 | 0.618 | SATO (paper, lenient) |
| 95 | 95.20 | 1.375 | 1.209 | 0.464 | 0.548 | 0.558 | 0.584 | 0.799 | 0.828 | **0.463** | TIDES |
| 98 | 94.51 | 1.349 | 1.212 | 0.332 | 0.548 | 0.558 | 0.580 | 0.799 | 0.828 | **0.305** | TIDES |

## EDP (PTB paper model = 1), DRAM 64 GB/s (1024 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper, lenient) | SATO (paper, strict) | SpikeFlow (paper) | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 3.830 | 4.702 | 11.831 | **0.272** | 0.613 | 0.898 | 0.220 | 0.428 | 4.063 | SATO (paper, lenient) |
| 90 | 95.27 | 3.723 | 4.741 | 1.362 | **0.299** | 0.638 | 0.880 | 0.228 | 0.432 | 0.426 | SATO (paper, lenient) |
| 95 | 95.20 | 3.538 | 4.747 | 0.829 | 0.292 | 0.623 | 0.885 | 0.226 | 0.430 | **0.267** | TIDES |
| 98 | 94.51 | 3.220 | 4.719 | 0.410 | 0.303 | 0.636 | 0.860 | 0.234 | 0.441 | **0.128** | TIDES |

## EDP (PTB paper model = 1), DRAM 16 GB/s (256 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper, lenient) | SATO (paper, strict) | SpikeFlow (paper) | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 3.395 | 4.169 | 10.488 | **0.323** | 0.598 | 0.805 | 0.334 | 0.485 | 3.700 | SATO (paper, lenient) |
| 90 | 95.27 | 3.307 | 4.212 | 1.210 | **0.344** | 0.623 | 0.795 | 0.337 | 0.489 | 0.379 | SATO (paper, lenient) |
| 95 | 95.20 | 3.086 | 4.141 | 0.723 | 0.334 | 0.606 | 0.799 | 0.330 | 0.477 | **0.233** | TIDES |
| 98 | 94.51 | 2.770 | 4.136 | 0.353 | 0.341 | 0.612 | 0.787 | 0.332 | 0.479 | **0.110** | TIDES |

## EDP (PTB paper model = 1), DRAM 8 GB/s (128 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper, lenient) | SATO (paper, strict) | SpikeFlow (paper) | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 2.606 | 3.248 | 8.051 | **0.360** | 0.552 | 0.710 | 0.450 | 0.539 | 3.701 | SATO (paper, lenient) |
| 90 | 95.27 | 2.545 | 3.311 | 0.931 | 0.375 | 0.572 | 0.700 | 0.450 | 0.544 | **0.314** | TIDES |
| 95 | 95.20 | 2.378 | 3.321 | 0.557 | 0.364 | 0.558 | 0.705 | 0.441 | 0.531 | **0.184** | TIDES |
| 98 | 94.51 | 2.262 | 3.338 | 0.271 | 0.366 | 0.562 | 0.699 | 0.441 | 0.531 | **0.085** | TIDES |

