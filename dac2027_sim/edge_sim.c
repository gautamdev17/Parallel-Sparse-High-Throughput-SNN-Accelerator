/* edge_sim.c -- one output tile of our design, cycle by cycle: group injection (with edge-FIFO backpressure), the
 * double-buffered packer, and the edge unit entry by entry (used by ours.py through ctypes; same rules as the RTL
 * ours_core.v edge FIFOs + arbiter and the controller in hw/tb/tb_ours_closed.v):
 *   - injection: one group per cycle at row 0. The first group of a pass may enter when its K-tile is packed and
 *     the previous pass allows it (s_next); the groups of a pass enter in order. Backpressure: a group enters at
 *     cycle x only if, for every column c, (FIFO occupancy at the end of x-1) + (entries of the groups injected in
 *     [x-R-c, x-1], still in the array above the FIFO) + (this group's entries for column c) <= D. Otherwise the
 *     feeder holds (a stall cycle) and retries next cycle. No pop is assumed, so a FIFO can never overflow.
 *   - a K-tile's first pass may not start in the cycle in which an empty K-tile just before it was found empty (the
 *     PEs' shadow weights, loaded for that empty K-tile's pass, are rewritten in that cycle); usable from max(own
 *     pack-done, last skipped empty K-tile's pack-done + 1).
 *   - pass timing: after the last group of a pass entered at cycle x, the next pass may start at
 *     max(x + 1, s + L) with shadow weights (s = first injection of the pass), else x + 1 + (R-1) + (C-1) + L.
 *   - packer: `lanes` independent lanes, each packing one K-tile at a time in pkc cycles; K-tiles start in scan order
 *     on the lane that is free first, once K-tile i-NS (NS = group-buffer slots) has released its slot (all its
 *     groups injected; an empty K-tile releases when packed).
 *   - a group injected at cycle s leaves column c at s + R + c; its entries are written into that column's FIFO at
 *     the end of that cycle and can update the output buffer from the next cycle;
 *   - every cycle each column offers its first min(count, E) entries; priority is column 0 first, then FIFO order;
 *     an entry whose (filter, pixel) address equals an earlier offered entry's address, or an address issued in
 *     the previous cycle (its write is still in flight: synchronous SRAM read, write one cycle later), may not issue
 *     this cycle; it and the entries behind it in its FIFO wait. An issued entry is written one cycle later.
 * Input: nkt K-tiles: P[i] groups (0: packed to nothing), np[i] passes. Units = (K-tile, pass, group) in injection
 *   order; n[u*C + c] entries of unit u for column c; addr[] their addresses in (unit, column, slot) order.
 *   pk in/out: [lanes, NS, last start, lane free times (lanes), releases of the last NS K-tiles (oldest first)].
 *   D <= 0: unbounded FIFO (no backpressure).
 * Output: out[0] first cycle the output buffer can be read after the last update (last issue + 2; t0 if none), out[1] cycle after the last bundle left the
 *   array, out[2] earliest start of a further pass, out[3] last pack-done cycle (t0 if none), out[4] largest FIFO
 *   occupancy (end of a cycle), out[5] (entry, cycle) pairs held back by a same-address conflict, out[6] cycles the
 *   feeder held a ready group because of backpressure.
 */
#include <limits.h>
#include <stdlib.h>

static long *g_pk, g_pkc, g_pklast;
#define PK_L (g_pk[0])
#define PK_NS (g_pk[1])
#define PK_LANE(i) (g_pk[3 + (i)])
#define PK_REL(i) (g_pk[3 + PK_L + (i)])

static void release(long r)
{
    for (long i = 0; i + 1 < PK_NS; i++) PK_REL(i) = PK_REL(i + 1);
    PK_REL(PK_NS - 1) = r;
}

static long pack_one(void)
{
    long l = 0;
    for (long i = 1; i < PK_L; i++) if (PK_LANE(i) < PK_LANE(l)) l = i;
    long start = g_pk[2];
    if (PK_LANE(l) > start) start = PK_LANE(l);
    if (PK_REL(0) > start) start = PK_REL(0);
    g_pk[2] = start;
    PK_LANE(l) = start + g_pkc;
    g_pklast = PK_LANE(l);
    return PK_LANE(l);
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
    long *prev_a = malloc(C * E * sizeof(long)), *cur_a = malloc(C * E * sizeof(long));
    int nprev = 0, ncur = 0;
    long xprev = t0 - 2;                             /* cycle of the issues held in prev_a */
    /* pack up to the first K-tile with groups */
    { long sk = -1; while (i < nkt) { long e = pack_one(); if (P[i]) { pkr = e > sk + 1 ? e : sk + 1; break; } release(e); if (e > sk) sk = e; i++; } }

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
        /* serve: entries written before this cycle; addresses issued in the previous cycle are blocked */
        if (xprev != x - 1) nprev = 0;
        ncur = 0;
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
                for (int jj = 0; jj < nprev && !same; jj++)
                    if (prev_a[jj] == off_a[kk]) same = 1;
                if (same) { conf++; break; }
                cur_a[ncur++] = off_a[kk];
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
        { long *tp = prev_a; prev_a = cur_a; cur_a = tp; nprev = ncur; xprev = x; }
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
                    { long sk = -1; while (i < nkt) { long e = pack_one(); if (P[i]) { pkr = e > sk + 1 ? e : sk + 1; break; } release(e); if (e > sk) sk = e; i++; } }
                }
            }
        }
        x++;
    }
    for (int c = 0; c < C; c++) free(q[c]);
    free(q); free(head); free(tail); free(cnt); free(ncol); free(off_a); free(off_v); free(uoff);
    free(ring_t); free(ring_u); free(prev_a); free(cur_a);
    out[0] = last >= t0 ? last + 2 : t0;
    out[1] = arr_end; out[2] = s_next; out[3] = g_pklast; out[4] = mx; out[5] = conf; out[6] = stalls;
}
