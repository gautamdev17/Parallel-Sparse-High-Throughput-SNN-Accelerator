/* edge_sim.c -- edge unit of our design, entry by entry (used by ours.py through ctypes; same rules as the RTL
 * ours_core.v edge FIFOs + arbiter):
 *   - a running-sum entry that leaves column c at cycle a is written into that column's FIFO at the end of cycle a
 *     and can update the output buffer from cycle a+1;
 *   - every cycle each column offers its first min(count, E) entries; priority is column 0 first, then FIFO order;
 *     an entry whose (filter, pixel) address equals an earlier offered entry's address may not update the buffer
 *     this cycle (both would read the old value); it and the entries behind it in its FIFO wait.
 * Input: n entries sorted by (arrival cycle, column, slot order): t[i], col[i], addr[i].
 * Output: cycle after the last update (t0 if no entries); *qmax = largest FIFO occupancy (end of a cycle);
 *         *nconf = number of (entry, cycle) pairs held back by a same-address conflict.
 */
#include <stdlib.h>
#include <string.h>

long edge_sim(long n, const long *t, const int *col, const long *addr, int C, int E, long t0,
              long *qmax, long *nconf)
{
    long *head = calloc(C, sizeof(long)), *tail = calloc(C, sizeof(long)), *cnt = calloc(C, sizeof(long));
    long **q = malloc(C * sizeof(long *));
    long *ncol = calloc(C, sizeof(long));
    for (long i = 0; i < n; i++) ncol[col[i]]++;
    for (int c = 0; c < C; c++) q[c] = malloc((ncol[c] + 1) * sizeof(long));
    long *off_a = malloc(C * E * sizeof(long));
    int *off_v = malloc(C * E * sizeof(int));
    long i = 0, x = (n ? t[0] : t0), last = t0 - 1, mx = 0, conf = 0, queued = 0;
    while (i < n || queued > 0) {
        if (queued == 0 && i < n && t[i] > x) x = t[i];          /* idle: jump to the next arrival */
        /* serve: entries written before this cycle */
        int k = 0;
        for (int c = 0; c < C; c++) {
            long av = cnt[c] < E ? cnt[c] : E;
            for (int e = 0; e < E; e++, k++) {
                off_v[k] = e < av;
                off_a[k] = off_v[k] ? addr[q[c][head[c] + e]] : -1;
            }
        }
        for (int c = 0; c < C; c++) {
            int pop = 0;
            for (int e = 0; e < E; e++) {
                int kk = c * E + e;
                if (!off_v[kk]) break;
                int same = 0;
                for (int j = 0; j < kk; j++)
                    if (off_v[j] && off_a[j] == off_a[kk]) { same = 1; break; }
                if (same) { conf++; break; }
                pop++;
            }
            if (pop) last = x;
            head[c] += pop; cnt[c] -= pop; queued -= pop;
        }
        /* arrivals of this cycle are written at its end */
        while (i < n && t[i] == x) {
            int c = col[i];
            q[c][tail[c]++] = i; cnt[c]++; queued++;
            i++;
        }
        for (int c = 0; c < C; c++) if (cnt[c] > mx) mx = cnt[c];
        x++;
    }
    for (int c = 0; c < C; c++) free(q[c]);
    free(q); free(head); free(tail); free(cnt); free(ncol); free(off_a); free(off_v);
    *qmax = mx; *nconf = conf;
    return last + 1 > t0 ? last + 1 : t0;
}
