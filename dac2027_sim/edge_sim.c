/* edge_sim.c -- one output tile of our design, cycle by cycle: group injection (with edge-FIFO backpressure), the
 * double-buffered packer, and the edge unit entry by entry (used by ours.py through ctypes; same rules as the RTL
 * ours_core.v edge FIFOs + arbiter and the controller in hw/tb/tb_ours_closed.v):
 *   - injection: one group per cycle at row 0. The first group of a pass may enter when its K-tile is packed and
 *     the previous pass allows it (s_next); the groups of a pass enter in order. Backpressure: a group enters at
 *     cycle x only if, for every column c, (FIFO occupancy at the end of x-1) + (entries of the groups injected in
 *     [x-R-c, x-1], still in the array above the FIFO) + (this group's entries for column c) <= D. Otherwise the
 *     feeder holds (a stall cycle) and retries next cycle. No pop is assumed, so a FIFO can never overflow.
 *   - pass timing: after the last group of a pass entered at cycle x, the next pass may start at
 *     max(x + 1, s + L) with shadow weights (s = first injection of the pass), else x + 1 + (R-1) + (C-1) + L.
 *   - packer: K-tiles in scan order, pkc cycles each; K-tile i starts when the packer is free and K-tile i-2 has
 *     released its group buffer (all its groups injected; an empty K-tile releases when packed).
 *   - a group injected at cycle s leaves column c at s + R + c; its entries are written into that column's FIFO at
 *     the end of that cycle and can update the output buffer from the next cycle;
 *   - every cycle each column offers its first min(count, E) entries; priority is column 0 first, then FIFO order;
 *     an entry whose (filter, pixel) address equals an earlier offered entry's address may not update the buffer
 *     this cycle (both would read the old value); it and the entries behind it in its FIFO wait.
 * Input: nkt K-tiles: P[i] groups (0: packed to nothing), np[i] passes. Units = (K-tile, pass, group) in injection
 *   order; n[u*C + c] entries of unit u for column c; addr[] their addresses in (unit, column, slot) order.
 *   pk[3] in/out: packer end, release of the K-tile two back, release of the last K-tile (carried across tiles).
 *   D <= 0: unbounded FIFO (no backpressure).
 * Output: out[0] cycle after the last output-buffer update (t0 if none), out[1] cycle after the last bundle left the
 *   array, out[2] earliest start of a further pass, out[3] last pack-done cycle (t0 if none), out[4] largest FIFO
 *   occupancy (end of a cycle), out[5] (entry, cycle) pairs held back by a same-address conflict, out[6] cycles the
 *   feeder held a ready group because of backpressure.
 */
#include <limits.h>
#include <stdlib.h>

static long *g_pk, g_pkc, g_pklast;

static void release(long r) { g_pk[1] = g_pk[2]; g_pk[2] = r; }

static long pack_one(void)
{
    long start = g_pk[0] > g_pk[1] ? g_pk[0] : g_pk[1];
    g_pk[0] = start + g_pkc;
    g_pklast = g_pk[0];
    return g_pk[0];
}

void tile_sim(int nkt, const int *P, const int *np, long pkc, const int *n, const long *addr,
              int R, int C, int E, int D, int L, int shadow, long t0, long *pk, long *out)
{
    long nunits = 0;
    for (int i = 0; i < nkt; i++) nunits += (long)P[i] * np[i];
    long *uoff = malloc((nunits * C + 1) * sizeof(long));
    long *ncol = calloc(C, sizeof(long));
    uoff[0] = 0;
    for (long k = 0; k < nunits * C; k++) { uoff[k + 1] = uoff[k] + n[k]; ncol[k % C] += n[k]; }
    long **q = malloc(C * sizeof(long *));
    for (int c = 0; c < C; c++) q[c] = malloc((ncol[c] + 1) * sizeof(long));
    long *head = calloc(C, sizeof(long)), *tail = calloc(C, sizeof(long)), *cnt = calloc(C, sizeof(long));
    long *off_a = malloc(C * E * sizeof(long));
    int *off_v = malloc(C * E * sizeof(int));
    int W = R + C;                                   /* ring of the last W injections (unit, cycle) */
    long *ring_t = malloc(W * sizeof(long)), *ring_u = malloc(W * sizeof(long));
    for (int k = 0; k < W; k++) ring_t[k] = LONG_MIN;   /* no injection */

    g_pk = pk; g_pkc = pkc; g_pklast = t0;
    int i = 0, j = 0, g = 0;
    long u = 0, pkr = 0, s_cur = 0, s_next = t0 + L, arr_end = t0, last_inj = -(1L << 40);
    long x = t0, last = t0 - 1, mx = 0, conf = 0, queued = 0, stalls = 0;
    /* pack up to the first K-tile with groups */
    while (i < nkt) { long e = pack_one(); if (P[i]) { pkr = e; break; } release(e); i++; }

    for (;;) {
        int inflight = x <= last_inj + R + C - 1;
        if (i >= nkt && queued == 0 && !inflight) break;
        if (queued == 0 && !inflight && i < nkt && g == 0) {          /* idle: jump to the next pass start */
            long nx = s_next > pkr ? s_next : pkr;
            if (nx > x) x = nx;
        }
        /* injection decision for cycle x (FIFO counts = end of x-1) */
        long inj = -1;
        if (i < nkt && (g > 0 || (x >= s_next && x >= pkr))) {
            int ok = 1;
            if (D > 0)
                for (int c = 0; c < C && ok; c++) {
                    long tot = cnt[c] + n[u * C + c];
                    for (int d = 1; d <= R + c; d++) {
                        long y = x - d, k = ((y % W) + W) % W;
                        if (ring_t[k] == y) tot += n[ring_u[k] * C + c];
                    }
                    if (tot > D) ok = 0;
                }
            if (ok) inj = u; else stalls++;
        }
        /* serve: entries written before this cycle */
        int k = 0;
        for (int c = 0; c < C; c++) {
            long av = cnt[c] < E ? cnt[c] : E;
            for (int e = 0; e < E; e++, k++) {
                off_v[k] = e < av;
                off_a[k] = off_v[k] ? q[c][head[c] + e] : -1;
            }
        }
        for (int c = 0; c < C; c++) {
            int pop = 0;
            for (int e = 0; e < E; e++) {
                int kk = c * E + e;
                if (!off_v[kk]) break;
                int same = 0;
                for (int jj = 0; jj < kk; jj++)
                    if (off_v[jj] && off_a[jj] == off_a[kk]) { same = 1; break; }
                if (same) { conf++; break; }
                pop++;
            }
            if (pop) last = x;
            head[c] += pop; cnt[c] -= pop; queued -= pop;
        }
        /* bundles leaving the array this cycle are written at its end, in slot order */
        for (int c = 0; c < C; c++) {
            long y = x - R - c, kr = ((y % W) + W) % W;
            if (ring_t[kr] != y) continue;
            long uc = ring_u[kr] * C + c;
            for (long a = uoff[uc]; a < uoff[uc + 1]; a++) q[c][tail[c]++] = addr[a];
            cnt[c] += n[uc]; queued += n[uc];
        }
        for (int c = 0; c < C; c++) if (cnt[c] > mx) mx = cnt[c];
        ring_t[x % W] = inj >= 0 ? x : LONG_MIN;
        ring_u[x % W] = inj;
        if (inj >= 0) {
            if (g == 0) s_cur = x;
            last_inj = x;
            if (x + R + C > arr_end) arr_end = x + R + C;
            u++; g++;
            if (g == P[i]) {
                long a = x + 1, b = s_cur + L;
                s_next = shadow ? (a > b ? a : b) : x + 1 + (R - 1) + (C - 1) + L;
                g = 0; j++;
                if (j == np[i]) {
                    release(x + 1);
                    j = 0; i++;
                    while (i < nkt) { long e = pack_one(); if (P[i]) { pkr = e; break; } release(e); i++; }
                }
            }
        }
        x++;
    }
    for (int c = 0; c < C; c++) free(q[c]);
    free(q); free(head); free(tail); free(cnt); free(ncol); free(off_a); free(off_v); free(uoff);
    free(ring_t); free(ring_u);
    out[0] = last + 1 > t0 ? last + 1 : t0;
    out[1] = arr_end; out[2] = s_next; out[3] = g_pklast; out[4] = mx; out[5] = conf; out[6] = stalls;
}
