# VGG-16, CIFAR-10, IF T = 8, snn-pruning-DAC models, batch 1 (plot_vgg16_chain.py)

Same chained traces for every design (prune_chain.py; per-layer W exact, A within 0.07 pts, C within 0.3 pts on the heavy layers of eval.json). TIDES cycles RTL-exact (rtl_t4.py, RT_T=8). Energy = core + SRAM + DRAM (45 nm, 500 MHz). Speed-up: higher is better; energy and EDP normalized to PTB: lower is better. Prosperity is given twice: its official simulator, and the per-tile pipeline of its paper (Sec. VI: ProSparsity phase m + 4 cycles, computation >= m + 4 cycles per tile of m rows; prosperity_paper.py), with the same memory traffic and power.

## Speedup over PTB, DRAM 64 GB/s (1024 b/cycle, official)

| Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.000 | 0.682 | 0.846 | 1.321 | 1.779 | 8.478 | **4.713** | 1.412 | Prosperity (paper pipeline) |
| 90 | 95.27 | 1.000 | 0.667 | 1.449 | 1.339 | 1.769 | 8.074 | **4.586** | 3.759 | Prosperity (paper pipeline) |
| 95 | 95.20 | 1.000 | 0.646 | 1.590 | 1.494 | 1.713 | 7.864 | **4.462** | 4.440 | Prosperity (paper pipeline) |
| 98 | 94.51 | 1.000 | 0.612 | 1.939 | 1.479 | 1.660 | 7.245 | 4.136 | **5.824** | TIDES |

## Energy (PTB = 1), DRAM 64 GB/s (1024 b/cycle, official)

| Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.000 | 0.837 | 0.647 | **0.402** | 0.404 | 0.488 | 0.527 | 1.491 | SATO |
| 90 | 95.27 | 1.000 | 0.849 | **0.203** | 0.406 | 0.405 | 0.494 | 0.532 | 0.429 | LoAS |
| 95 | 95.20 | 1.000 | 0.867 | **0.169** | 0.409 | 0.415 | 0.503 | 0.543 | 0.334 | LoAS |
| 98 | 94.51 | 1.000 | 0.898 | **0.141** | 0.426 | 0.429 | 0.525 | 0.567 | 0.231 | LoAS |

## EDP (PTB = 1), DRAM 64 GB/s (1024 b/cycle, official)

| Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.000 | 1.228 | 0.765 | 0.304 | 0.227 | 0.058 | **0.112** | 1.056 | Prosperity (paper pipeline) |
| 90 | 95.27 | 1.000 | 1.274 | 0.140 | 0.303 | 0.229 | 0.061 | 0.116 | **0.114** | TIDES |
| 95 | 95.20 | 1.000 | 1.342 | 0.106 | 0.274 | 0.242 | 0.064 | 0.122 | **0.075** | TIDES |
| 98 | 94.51 | 1.000 | 1.466 | 0.073 | 0.288 | 0.259 | 0.073 | 0.137 | **0.040** | TIDES |

## Speedup over PTB, DRAM 16 GB/s (256 b/cycle)

| Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.000 | 0.682 | 0.845 | 1.321 | 1.758 | 5.268 | **3.832** | 1.382 | Prosperity (paper pipeline) |
| 90 | 95.27 | 1.000 | 0.667 | 1.449 | 1.339 | 1.737 | 5.137 | 3.736 | **3.755** | TIDES |
| 95 | 95.20 | 1.000 | 0.646 | 1.590 | 1.494 | 1.657 | 4.991 | 3.645 | **4.440** | TIDES |
| 98 | 94.51 | 1.000 | 0.605 | 1.939 | 1.479 | 1.566 | 4.643 | 3.398 | **5.824** | TIDES |

## Energy (PTB = 1), DRAM 16 GB/s (256 b/cycle)

| Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.000 | 0.837 | 0.647 | **0.402** | 0.405 | 0.518 | 0.547 | 1.499 | SATO |
| 90 | 95.27 | 1.000 | 0.849 | **0.203** | 0.406 | 0.406 | 0.523 | 0.553 | 0.430 | LoAS |
| 95 | 95.20 | 1.000 | 0.867 | **0.169** | 0.409 | 0.417 | 0.533 | 0.563 | 0.334 | LoAS |
| 98 | 94.51 | 1.000 | 0.904 | **0.141** | 0.426 | 0.432 | 0.556 | 0.588 | 0.231 | LoAS |

## EDP (PTB = 1), DRAM 16 GB/s (256 b/cycle)

| Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.000 | 1.228 | 0.766 | 0.304 | 0.230 | 0.098 | **0.143** | 1.085 | Prosperity (paper pipeline) |
| 90 | 95.27 | 1.000 | 1.274 | 0.140 | 0.303 | 0.234 | 0.102 | 0.148 | **0.114** | TIDES |
| 95 | 95.20 | 1.000 | 1.342 | 0.106 | 0.274 | 0.252 | 0.107 | 0.154 | **0.075** | TIDES |
| 98 | 94.51 | 1.000 | 1.493 | 0.073 | 0.288 | 0.276 | 0.120 | 0.173 | **0.040** | TIDES |

## Speedup over PTB, DRAM 8 GB/s (128 b/cycle)

| Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.000 | 0.676 | 0.803 | 1.321 | 1.547 | 3.276 | **2.829** | 1.121 | Prosperity (paper pipeline) |
| 90 | 95.27 | 1.000 | 0.658 | 1.438 | 1.339 | 1.536 | 3.226 | 2.768 | **3.552** | TIDES |
| 95 | 95.20 | 1.000 | 0.630 | 1.581 | 1.494 | 1.463 | 3.136 | 2.697 | **4.354** | TIDES |
| 98 | 94.51 | 1.000 | 0.609 | 1.990 | 1.478 | 1.422 | 3.040 | 2.614 | **6.025** | TIDES |

## Energy (PTB = 1), DRAM 8 GB/s (128 b/cycle)

| Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.000 | 0.842 | 0.654 | **0.402** | 0.411 | 0.565 | 0.585 | 1.585 | SATO |
| 90 | 95.27 | 1.000 | 0.856 | **0.203** | 0.406 | 0.412 | 0.570 | 0.591 | 0.437 | LoAS |
| 95 | 95.20 | 1.000 | 0.879 | **0.169** | 0.409 | 0.423 | 0.581 | 0.602 | 0.336 | LoAS |
| 98 | 94.51 | 1.000 | 0.898 | **0.138** | 0.417 | 0.429 | 0.592 | 0.614 | 0.226 | LoAS |

## EDP (PTB = 1), DRAM 8 GB/s (128 b/cycle)

| Level | Acc % | PTB | SpikeX | LoAS | SATO | SpikeFlow | Prosperity (official sim.) | Prosperity (paper pipeline) | TIDES | Best |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| dense | 95.20 | 1.000 | 1.246 | 0.814 | 0.304 | 0.266 | 0.173 | **0.207** | 1.414 | Prosperity (paper pipeline) |
| 90 | 95.27 | 1.000 | 1.301 | 0.141 | 0.303 | 0.268 | 0.177 | 0.214 | **0.123** | TIDES |
| 95 | 95.20 | 1.000 | 1.397 | 0.107 | 0.274 | 0.289 | 0.185 | 0.223 | **0.077** | TIDES |
| 98 | 94.51 | 1.000 | 1.476 | 0.070 | 0.282 | 0.302 | 0.195 | 0.235 | **0.037** | TIDES |

