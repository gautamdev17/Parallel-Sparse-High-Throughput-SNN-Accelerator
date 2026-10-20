"""
plot_tip_visual.py -- packing visualization in the style of Mentha's Fig. 9: a 256 x 256 spike matrix (inputs x output
positions, 90% silent trains, T = 8: workload.rand_spikes with ns = 0.10, q = 0.3, the synthetic sparse90 setting) and
the packed matrices produced by the real packer (ours.pack_spikes, Q = 4 open groups), stacked as cards.

Packing is per tile of R = 4 inputs (the array rows) and output block of 128 positions (Cfg.Nt), as in the hardware:
in every tile the groups are pushed to the left, one column per group, block after block, so the right edge is
ragged; the red dashed line marks the widest tile (= packed rows the array streams for that tile).
Cards (back to front): TIP at threshold (positions per group) 8, 4, 3, 2, as in Mentha.

  python3 plot_tip_visual.py   -> results/tip_visual.png/.pdf, results/ptb_visual.png/.pdf (PTB, time window = T),
                                 results/packing_ptb_vs_tides.png/.pdf (both on one input)
"""
import os
import numpy as np
import figstyle as FS
import workload as wl
from ours import tile_masks, pack_spikes

plt = FS.plt
HERE = os.path.dirname(os.path.abspath(__file__))
R_ = os.path.join(HERE, "results")
M = K = 256
T, R, Q, NT = 8, 4, 4, 128          # timesteps, tile inputs (array rows), open groups, output block (Cfg.Nt)
RED = "#E8590C"                     # accent: widest-tile line and numbers
DOT = "#1D4ED8"                     # spikes
from matplotlib.colors import ListedColormap
CMAP = ListedColormap(["white", DOT])


def packed_image(S, G):
    """TIP per tile of R inputs and output block of NT positions, exactly as ours.run_layer_fast drives the packer.
    -> (image (K, M) bool: the groups of a tile pushed left, block after block; packed rows per tile)"""
    img = np.zeros((K, M), bool)
    ng = []
    for kt in range(K // R):
        St = S[kt * R:(kt + 1) * R]
        col = 0
        for n0 in range(0, M, NT):
            Sb = St[:, n0:n0 + NT]
            for g in pack_spikes(tile_masks(Sb, T), G, Q):
                img[kt * R:(kt + 1) * R, col] = np.bitwise_or.reduce(Sb[:, g], axis=1) != 0
                col += 1
        ng.append(col)
    return img, ng


def original(fig, S):
    """the unpacked 256 x 256 spike matrix (left panel)."""
    W, H = fig.get_size_inches()
    ax = fig.add_axes([0.06, (1 - 1.62 / H) / 2 + 0.02, 1.62 / W, 1.62 / H])
    ax.imshow(S != 0, cmap=CMAP, interpolation="nearest", extent=[0, M, K, 0], vmin=0, vmax=1)
    ax.set_xticks([]); ax.set_yticks([])
    for sp in ax.spines.values():
        sp.set_linewidth(1.0)
    ax.text(M / 2, K / 2, "90% silent trains\n$T$ = 8", ha="center", va="center", fontsize=8, fontweight="bold",
            bbox=dict(facecolor="white", edgecolor="none", pad=2.5))
    ax.text(-6, K, "0", ha="right", va="bottom", fontsize=7, fontweight="bold")
    ax.text(-6, 0, f"{K - 1}", ha="right", va="top", fontsize=7, fontweight="bold")
    ax.text(M, K + 4, f"{M - 1}", ha="right", va="top", fontsize=7, fontweight="bold")


def ptb_figure(S, windows=(1, 2, 4, 8)):
    """PTB's StSAP on the same matrix (baselines.ptb_slots, the model behind our PTB numbers), one card per time
    window. StSAP tags each input's train with one bit per window and pairs at most two non-bursting inputs of an
    output position whose tags do not overlap; an input active in every window (bursting) is never paired. PTB packs
    along the input dimension, so each column is compacted upward; the dashed line marks the widest position. With
    one window of T timesteps every active input is bursting, so no pair forms."""
    from baselines import ptb_slots
    res = {}
    for tws in windows:
        slots = ptb_slots(S, tws, T)
        assert np.all(2 * slots >= (S != 0).sum(0))                  # at most two inputs per slot
        img = np.zeros((K, M), bool)
        for m in range(M):
            img[:slots[m], m] = True
        res[tws] = (img, slots)
    assert np.array_equal(res[T][1], (S != 0).sum(0)) if T in res else True   # full window: no pairs
    fig = plt.figure(figsize=(FS.TEXT, 2.35))
    W, H = fig.get_size_inches()
    original(fig, S)
    if len(windows) == 1:                                              # one large card (FTP: full window)
        cw, ch, dx, dy = 2.9 / W, 1.62 / H, 0, 0
        x0, y0 = 0.40, (1 - 1.62 / H) / 2 + 0.02
    else:                                                              # stacked cards, back = most compressed
        cw, ch, dx, dy = 1.95 / W, 1.18 / H, 0.42 / W, -0.30 / H
        x0, y0 = 0.40, 0.90 - ch
    for i, tws in enumerate(windows):
        img, slots = res[tws]
        a = fig.add_axes([x0 + i * dx, y0 + i * dy, cw, ch])
        a.set_facecolor("white")
        a.imshow(img, cmap=CMAP, interpolation="nearest", extent=[0, M, K, 0], vmin=0, vmax=1, aspect="auto")
        a.set_xlim(0, M); a.set_ylim(K, 0)
        a.set_xticks([]); a.set_yticks([])
        for sp in a.spines.values():
            sp.set_linewidth(1.0)
        h = int(slots.max())
        a.axhline(h, color=RED, lw=1.3, ls=(0, (3, 2)))
        a.text(-4, h, str(h), color=RED, ha="right", va="center", fontsize=7.5, fontweight="bold", clip_on=False)
        if len(windows) == 1:
            a.text(M - 6, K - 10, f"PTB, time window = {tws}", ha="right", va="bottom", fontsize=7.5,
                   fontweight="bold", color="#333333")
        else:
            a.text(M, -5, f"Time window = {tws}", ha="right", va="bottom", fontsize=7.5, fontweight="bold",
                   color="#333333", clip_on=False, bbox=dict(facecolor="white", edgecolor="none", pad=1.0))
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R_, f"ptb_visual.{ext}"), dpi=300)
    for tws in windows:
        sl = res[tws][1]
        print(f"PTB window {tws}: mean slots/position {sl.mean():.1f}  widest {sl.max()}  "
              f"pairs/position {((S != 0).sum(0) - sl).mean():.1f}")


def combined_figure(S):
    """PTB (time window = T, the FTP setting) next to TIDES (TIP at thresholds 8, 4, 3, 2) on the same input matrix.
    PTB packs along the inputs of each position (columns compacted upward, at most two inputs per slot; with one
    window every active input is bursting, so no pair forms); TIP packs positions within each tile of 4 inputs x 128
    positions (groups pushed left). Dashed lines mark the widest position (PTB) and the widest tile (TIDES)."""
    from baselines import ptb_slots
    slots = ptb_slots(S, T, T)
    pimg = np.zeros((K, M), bool)
    for m in range(M):
        pimg[:slots[m], m] = True
    tip = {G: packed_image(S, G) for G in (8, 4, 3, 2)}
    fig = plt.figure(figsize=(FS.TEXT, 2.45))
    W, H = fig.get_size_inches()
    sq = 1.45
    ax = fig.add_axes([0.05, (1 - sq / H) / 2 - 0.02, sq / W, sq / H])
    ax.imshow(S != 0, cmap=CMAP, interpolation="nearest", extent=[0, M, K, 0], vmin=0, vmax=1)
    ax.set_xticks([]); ax.set_yticks([])
    for sp in ax.spines.values():
        sp.set_linewidth(1.0)
    ax.text(M / 2, K / 2, "90% silent trains\n$T$ = 8", ha="center", va="center", fontsize=7.5, fontweight="bold",
            bbox=dict(facecolor="white", edgecolor="none", pad=2.0))
    ax.text(-6, K, "0", ha="right", va="bottom", fontsize=7, fontweight="bold")
    ax.text(-6, 0, f"{K - 1}", ha="right", va="top", fontsize=7, fontweight="bold")
    ax.text(M, K + 4, f"{M - 1}", ha="right", va="top", fontsize=7, fontweight="bold")
    ax.set_title("Input", fontsize=8, fontweight="bold", pad=4)

    def card(rect, img, title, dash, vertical):
        a = fig.add_axes(rect)
        a.set_facecolor("white")
        a.imshow(img, cmap=CMAP, interpolation="nearest", extent=[0, M, K, 0], vmin=0, vmax=1, aspect="auto")
        a.set_xlim(0, M); a.set_ylim(K, 0)
        a.set_xticks([]); a.set_yticks([])
        for sp in a.spines.values():
            sp.set_linewidth(1.0)
        if vertical:
            a.axhline(dash, color=RED, lw=1.3, ls=(0, (3, 2)))
            a.text(-4, dash, str(dash), color=RED, ha="right", va="center", fontsize=7.5, fontweight="bold",
                   clip_on=False)
        else:
            a.axvline(dash, color=RED, lw=1.3, ls=(0, (3, 2)))
            a.text(dash, -4, str(dash), color=RED, ha="center", va="bottom", fontsize=7.5, fontweight="bold",
                   clip_on=False)
        a.text(M - 6, K - 10 if vertical else 10, title, ha="right", va="bottom" if vertical else "top",
               fontsize=7, fontweight="bold", color="#333333")
        return a

    # PTB: one card, same height as the input
    px = 0.05 + sq / W + 0.06
    pw = 1.65 / W
    a = card([px, (1 - sq / H) / 2 - 0.02, pw, sq / H], pimg, "time window = 8", int(slots.max()), True)
    a.set_title("PTB (StSAP)", fontsize=8, fontweight="bold", pad=4)
    # TIDES: stacked cards, back = most compressed
    cw, ch, dx, dy = 1.55 / W, 0.98 / H, 0.30 / W, -0.27 / H
    x0 = px + pw + 0.07
    y0 = (1 - sq / H) / 2 - 0.02 + sq / H - ch
    for i, G in enumerate((8, 4, 3, 2)):
        img, ng = tip[G]
        card([x0 + i * dx, y0 + i * dy, cw, ch], img, f"$G_{{\\max}}$ = {G}", int(max(ng)), False)
    fig.text(x0 + (cw + 3 * dx) / 2, y0 + ch + 0.085, "TIDES (TIP)", ha="center", va="bottom", fontsize=8,
             fontweight="bold")
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R_, f"packing_ptb_vs_tides.{ext}"), dpi=300)
    print(f"combined: PTB widest {slots.max()} slots/position; TIDES widest rows/tile "
          + ", ".join(f"thr {G}: {max(tip[G][1])}" for G in (8, 4, 3, 2)))


def main():
    rng = np.random.default_rng(7)
    S = wl.rand_spikes(rng, (K, M), 0.10, 0.3, T)                 # S[k, m]: 90% silent trains
    cards = [(f"$G_{{\\max}}$ = {G}", G) for G in (8, 4, 3, 2)]
    res = {lab: packed_image(S, G) for lab, G in cards}

    fig = plt.figure(figsize=(FS.TEXT, 2.35))
    W, H = fig.get_size_inches()
    original(fig, S)
    # ---- stacked cards (back to front)
    cw, ch, dx, dy = 1.95 / W, 1.18 / H, 0.42 / W, -0.30 / H
    x0, y0 = 0.40, 0.94 - ch
    for i, (lab, G) in enumerate(cards):
        img, ng = res[lab]
        a = fig.add_axes([x0 + i * dx, y0 + i * dy, cw, ch])
        a.set_facecolor("white")
        a.imshow(img, cmap=CMAP, interpolation="nearest", extent=[0, M, K, 0], vmin=0, vmax=1, aspect="auto")
        a.set_xlim(0, M); a.set_ylim(K, 0)
        a.set_xticks([]); a.set_yticks([])
        for sp in a.spines.values():
            sp.set_linewidth(1.0)
        w = max(ng)
        a.axvline(w, color=RED, lw=1.3, ls=(0, (3, 2)))
        a.text(w, -4, str(w), color=RED, ha="center", va="bottom", fontsize=7.5, fontweight="bold", clip_on=False)
        a.text(M - 6, 10, lab, ha="right", va="top", fontsize=7.5, fontweight="bold", color="#333333")
    os.makedirs(R_, exist_ok=True)
    for ext in ("png", "pdf"):
        fig.savefig(os.path.join(R_, f"tip_visual.{ext}"), dpi=300)
    for lab, G in cards:
        print(f"{lab:16s} mean rows/tile {np.mean(res[lab][1]):6.1f}  widest {max(res[lab][1])}")
    ptb_figure(S, (T,))                  # FTP comparison: one window of all T timesteps
    combined_figure(S)


if __name__ == "__main__":
    main()
