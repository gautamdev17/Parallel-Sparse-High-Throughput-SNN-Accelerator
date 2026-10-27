# VGG-16, IF T = 8, snn-pruning-DAC dense/90/95/98 %: baselines audited against their papers (audited_vgg16.py)

Normalized to the paper-faithful PTB. TIDES RTL cycle-exact. Batch 1, 500 MHz, 45 nm. Speed-up: higher is better; energy, EDP: lower is better. 'official sim.' = the models used before the audit.

## Speedup over PTB (paper model), DRAM 64 GB/s (1024 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper loop nest) | SATO (ideal balance) | SATO (paper, strict) | SpikeFlow (paper) | SpikeFlow (fill per pass) | Prosperity (official sim.) | Prosperity (prosperity_own_correct_final) | Prosperity (published-number model) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 0.421 | 0.287 | 0.172 | 1.486 | 2.093 | 1.022 | 0.749 | 0.729 | 3.570 | **1.984** | 3.540 | 0.594 | Prosperity (prosperity_own_correct_final) |
| 90 | 95.27 | 0.429 | 0.286 | 0.482 | 1.401 | 1.944 | 0.986 | 0.758 | 0.737 | 3.461 | **1.966** | 3.431 | 1.611 | Prosperity (prosperity_own_correct_final) |
| 95 | 95.20 | 0.442 | 0.286 | 0.637 | 1.436 | 1.985 | 1.007 | 0.758 | 0.737 | 3.477 | **1.973** | 3.448 | 1.963 | Prosperity (prosperity_own_correct_final) |
| 98 | 94.51 | 0.468 | 0.287 | 0.926 | 1.404 | 1.929 | 0.991 | 0.777 | 0.755 | 3.390 | 1.935 | 3.366 | **2.725** | TIDES |

## Speedup over PTB (paper model), DRAM 16 GB/s (256 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper loop nest) | SATO (ideal balance) | SATO (paper, strict) | SpikeFlow (paper) | SpikeFlow (fill per pass) | Prosperity (official sim.) | Prosperity (prosperity_own_correct_final) | Prosperity (published-number model) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 0.457 | 0.312 | 0.187 | 1.389 | 1.737 | 1.013 | 0.804 | 0.784 | 2.410 | **1.752** | 2.401 | 0.632 | Prosperity (prosperity_own_correct_final) |
| 90 | 95.27 | 0.465 | 0.310 | 0.523 | 1.315 | 1.659 | 0.976 | 0.808 | 0.787 | 2.389 | 1.737 | 2.379 | **1.746** | TIDES |
| 95 | 95.20 | 0.486 | 0.314 | 0.699 | 1.347 | 1.698 | 0.996 | 0.804 | 0.784 | 2.423 | 1.770 | 2.414 | **2.156** | TIDES |
| 98 | 94.51 | 0.519 | 0.314 | 1.027 | 1.328 | 1.667 | 0.987 | 0.812 | 0.792 | 2.409 | 1.763 | 2.401 | **3.021** | TIDES |

## Speedup over PTB (paper model), DRAM 8 GB/s (128 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper loop nest) | SATO (ideal balance) | SATO (paper, strict) | SpikeFlow (paper) | SpikeFlow (fill per pass) | Prosperity (official sim.) | Prosperity (prosperity_own_correct_final) | Prosperity (published-number model) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 0.546 | 0.369 | 0.223 | 1.293 | 1.470 | 1.015 | 0.845 | 0.827 | 1.789 | **1.545** | 1.788 | 0.612 | Prosperity (prosperity_own_correct_final) |
| 90 | 95.27 | 0.554 | 0.365 | 0.623 | 1.251 | 1.431 | 0.984 | 0.852 | 0.833 | 1.788 | 1.535 | 1.786 | **1.969** | TIDES |
| 95 | 95.20 | 0.578 | 0.364 | 0.833 | 1.274 | 1.461 | 1.001 | 0.846 | 0.828 | 1.814 | 1.559 | 1.811 | **2.518** | TIDES |
| 98 | 94.51 | 0.596 | 0.363 | 1.225 | 1.260 | 1.455 | 0.993 | 0.848 | 0.830 | 1.813 | 1.559 | 1.809 | **3.593** | TIDES |

## Energy (PTB paper model = 1), DRAM 64 GB/s (1024 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper loop nest) | SATO (ideal balance) | SATO (paper, strict) | SpikeFlow (paper) | SpikeFlow (fill per pass) | Prosperity (official sim.) | Prosperity (prosperity_own_correct_final) | Prosperity (published-number model) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.613 | 1.350 | 2.035 | **0.619** | 0.613 | 0.626 | 0.652 | 0.654 | 0.787 | 0.849 | 0.787 | 2.415 | SATO (paper loop nest) |
| 90 | 95.27 | 1.596 | 1.355 | 0.656 | **0.621** | 0.616 | 0.629 | 0.647 | 0.649 | 0.788 | 0.850 | 0.789 | 0.687 | SATO (paper loop nest) |
| 95 | 95.20 | 1.564 | 1.356 | 0.528 | 0.619 | 0.614 | 0.627 | 0.650 | 0.652 | 0.787 | 0.849 | 0.788 | **0.523** | TIDES |
| 98 | 94.51 | 1.507 | 1.352 | 0.380 | 0.623 | 0.618 | 0.630 | 0.647 | 0.649 | 0.792 | 0.854 | 0.792 | **0.348** | TIDES |

## Energy (PTB paper model = 1), DRAM 16 GB/s (256 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper loop nest) | SATO (ideal balance) | SATO (paper, strict) | SpikeFlow (paper) | SpikeFlow (fill per pass) | Prosperity (official sim.) | Prosperity (prosperity_own_correct_final) | Prosperity (published-number model) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.553 | 1.300 | 1.960 | **0.598** | 0.594 | 0.606 | 0.629 | 0.631 | 0.804 | 0.849 | 0.804 | 2.338 | SATO (paper loop nest) |
| 90 | 95.27 | 1.538 | 1.306 | 0.632 | **0.601** | 0.597 | 0.609 | 0.624 | 0.626 | 0.804 | 0.850 | 0.804 | 0.662 | SATO (paper loop nest) |
| 95 | 95.20 | 1.499 | 1.299 | 0.506 | 0.596 | 0.592 | 0.603 | 0.625 | 0.627 | 0.799 | 0.844 | 0.799 | **0.501** | TIDES |
| 98 | 94.51 | 1.437 | 1.299 | 0.362 | 0.597 | 0.593 | 0.604 | 0.621 | 0.623 | 0.799 | 0.845 | 0.800 | **0.332** | TIDES |

## Energy (PTB paper model = 1), DRAM 8 GB/s (128 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper loop nest) | SATO (ideal balance) | SATO (paper, strict) | SpikeFlow (paper) | SpikeFlow (fill per pass) | Prosperity (official sim.) | Prosperity (prosperity_own_correct_final) | Prosperity (published-number model) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.424 | 1.199 | 1.797 | **0.554** | 0.551 | 0.560 | 0.586 | 0.587 | 0.805 | 0.833 | 0.805 | 2.266 | SATO (paper loop nest) |
| 90 | 95.27 | 1.411 | 1.207 | 0.580 | **0.557** | 0.554 | 0.563 | 0.582 | 0.583 | 0.805 | 0.834 | 0.805 | 0.618 | SATO (paper loop nest) |
| 95 | 95.20 | 1.375 | 1.209 | 0.464 | 0.552 | 0.549 | 0.558 | 0.582 | 0.584 | 0.799 | 0.828 | 0.800 | **0.463** | TIDES |
| 98 | 94.51 | 1.349 | 1.212 | 0.332 | 0.552 | 0.549 | 0.558 | 0.579 | 0.580 | 0.799 | 0.828 | 0.799 | **0.305** | TIDES |

## EDP (PTB paper model = 1), DRAM 64 GB/s (1024 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper loop nest) | SATO (ideal balance) | SATO (paper, strict) | SpikeFlow (paper) | SpikeFlow (fill per pass) | Prosperity (official sim.) | Prosperity (prosperity_own_correct_final) | Prosperity (published-number model) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 3.830 | 4.702 | 11.831 | **0.416** | 0.293 | 0.613 | 0.870 | 0.898 | 0.220 | 0.428 | 0.222 | 4.063 | SATO (paper loop nest) |
| 90 | 95.27 | 3.723 | 4.741 | 1.362 | 0.443 | 0.317 | 0.638 | 0.853 | 0.880 | 0.228 | 0.432 | 0.230 | **0.426** | TIDES |
| 95 | 95.20 | 3.538 | 4.747 | 0.829 | 0.431 | 0.310 | 0.623 | 0.858 | 0.885 | 0.226 | 0.430 | 0.229 | **0.267** | TIDES |
| 98 | 94.51 | 3.220 | 4.719 | 0.410 | 0.444 | 0.320 | 0.636 | 0.833 | 0.860 | 0.234 | 0.441 | 0.235 | **0.128** | TIDES |

## EDP (PTB paper model = 1), DRAM 16 GB/s (256 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper loop nest) | SATO (ideal balance) | SATO (paper, strict) | SpikeFlow (paper) | SpikeFlow (fill per pass) | Prosperity (official sim.) | Prosperity (prosperity_own_correct_final) | Prosperity (published-number model) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 3.395 | 4.169 | 10.488 | **0.431** | 0.342 | 0.598 | 0.782 | 0.805 | 0.334 | 0.485 | 0.335 | 3.700 | SATO (paper loop nest) |
| 90 | 95.27 | 3.307 | 4.212 | 1.210 | 0.457 | 0.360 | 0.623 | 0.773 | 0.795 | 0.337 | 0.489 | 0.338 | **0.379** | TIDES |
| 95 | 95.20 | 3.086 | 4.141 | 0.723 | 0.443 | 0.349 | 0.606 | 0.777 | 0.799 | 0.330 | 0.477 | 0.331 | **0.233** | TIDES |
| 98 | 94.51 | 2.770 | 4.136 | 0.353 | 0.450 | 0.355 | 0.612 | 0.765 | 0.787 | 0.332 | 0.479 | 0.333 | **0.110** | TIDES |

## EDP (PTB paper model = 1), DRAM 8 GB/s (128 b/cycle)

| Level | Acc % | PTB (official sim.) | SpikeX | LoAS | SATO (paper loop nest) | SATO (ideal balance) | SATO (paper, strict) | SpikeFlow (paper) | SpikeFlow (fill per pass) | Prosperity (official sim.) | Prosperity (prosperity_own_correct_final) | Prosperity (published-number model) | TIDES | Best (paper models) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 2.606 | 3.248 | 8.051 | **0.428** | 0.375 | 0.552 | 0.693 | 0.710 | 0.450 | 0.539 | 0.450 | 3.701 | SATO (paper loop nest) |
| 90 | 95.27 | 2.545 | 3.311 | 0.931 | 0.445 | 0.387 | 0.572 | 0.683 | 0.700 | 0.450 | 0.544 | 0.451 | **0.314** | TIDES |
| 95 | 95.20 | 2.378 | 3.321 | 0.557 | 0.433 | 0.376 | 0.558 | 0.688 | 0.705 | 0.441 | 0.531 | 0.442 | **0.184** | TIDES |
| 98 | 94.51 | 2.262 | 3.338 | 0.271 | 0.438 | 0.377 | 0.562 | 0.682 | 0.699 | 0.441 | 0.531 | 0.442 | **0.085** | TIDES |

