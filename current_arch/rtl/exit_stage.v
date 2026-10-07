// exit_stage.v -- what happens to a psum set after it leaves the last used array column.
//
// Datapath (REPORT.md stage 6 and 7):
//   arrivals : up to 4 rows x 4 slots of {m, n, 8 x 16-bit sums} per cycle (from the tap column)
//   FIFO     : depth 64.  Entries are served in order: FIFO contents first, then new arrivals.
//              Up to PORTS (8) entries are served per cycle; the rest stay in / go into the FIFO.
//   lane     : tot[t] = sums[t] + (partial buffer entry if it is dirty)      (24-bit per timestep)
//       NOT the last K-slab : write tot back to the partial buffer (PB) at (m,n), mark dirty.
//       last K-slab         : clear dirty, run the one-cycle neuron (lif) on tot, send
//                             {m, n, spike byte} to the packed result buffer (post-proc).
//   sweep    : after the last slab, outputs that are still dirty (touched earlier, not in the
//              last slab) go through the same lanes, PORTS per cycle, until none is left.
//
// PB: 64 x 128 entries x (8 x 24 bits) = 192 KB, index = (m-1)*128 + (n-1).
//     Behavioural memory here.  Eight lanes access it at once; a real implementation banks it
//     (the 8 entries served in one cycle all have different (m,n): one (m,n) appears at most
//     once per pass).
// The sweep picks the first PORTS dirty entries with a find-first-N over the dirty bitmap.
// That is a behavioural priority network; hardware would use a 2-level bitmap with the same rate.
`include "snn_defs.vh"
module exit_stage #(
    parameter PORTS      = 8,
    parameter FIFO_DEPTH = 64,
    parameter PBDEPTH    = 8192,
    parameter THW        = 24
) (
    input                        clk,
    input                        rst_n,
    // arrivals
    input                        arr_en,        // the array advanced: tap_* are valid this cycle
    input  [`ARR-1:0]            tap_valid,
    input  [`ARR*`SETW-1:0]      tap_sets,
    // control
    input                        serve_en,      // RUN state
    input                        mode_final,    // this pass belongs to the last K-slab
    input                        sweep_en,      // SWEEP state
    input  [THW-1:0]             theta,
    // status
    output [7:0]                 fifo_cnt,
    output reg [7:0]             fifo_cnt_nxt,
    output [13:0]                dirty_cnt,
    output reg [13:0]            dirty_cnt_nxt,
    output reg                   served_final,  // a lane served an entry that goes through the neuron
    output reg                   err_fifo,
    // results for post-proc (registered by the neuron)
    output [PORTS-1:0]           res_valid,
    output [PORTS*8-1:0]         res_m,
    output [PORTS*8-1:0]         res_n,
    output [PORTS*8-1:0]         res_byte
);
    localparam LENW = `LENW;
    localparam TW   = `TS * `PBW;           // one PB entry: 192 bits

    // ---------------------------------------------------------------- state
    reg [LENW-1:0] fifo_mem [0:FIFO_DEPTH-1];
    reg [6:0]      fhead;
    reg [7:0]      fcnt;
    reg [TW-1:0]   pb_mem   [0:PBDEPTH-1];
    reg [PBDEPTH-1:0] pb_dirty;
    reg [13:0]     dcnt_r;
    reg [13:0]     sweep_base;

    assign fifo_cnt  = fcnt;
    assign dirty_cnt = dcnt_r;

    // ---------------------------------------------------------------- sweep: first PORTS dirty entries
    reg [PORTS-1:0]    sw_v;
    reg [PORTS*13-1:0] sw_idx_f;
    reg [13:0]         sw_next;
    integer            sw_n, sd;
    always @* begin
        sw_v = {PORTS{1'b0}};
        sw_idx_f = {PORTS*13{1'b0}};
        sw_n = 0;
        sw_next = sweep_base;
        if (sweep_en) begin
            for (sd = sweep_base; sd < PBDEPTH && sw_n < PORTS; sd = sd + 1)
                if (pb_dirty[sd]) begin
                    sw_idx_f[sw_n*13 +: 13] = sd;
                    sw_v[sw_n] = 1'b1;
                    sw_n = sw_n + 1;
                    sw_next = sd + 1;
                end
        end
    end

    // ---------------------------------------------------------------- lane selection and arithmetic
    reg [LENW-1:0]     arr_e [0:15];
    integer            na;
    reg [LENW-1:0]     le [0:PORTS-1];
    reg [PORTS-1:0]    lv;
    reg [12:0]         lidx [0:PORTS-1];
    reg [PORTS*TW-1:0] ltot;
    reg [PORTS*16-1:0] ltagf;
    reg [PORTS-1:0]    ldirty;
    integer            fc, a0, popped, served, i, s, j, t, delta, over;
    reg                do_if, do_pb;
    reg [LENW-1:0]     lw;
    reg [7:0]          mm, nn, m1, n1;
    reg [12:0]         idx;
    reg [TW-1:0]       pw;
    reg                db;
    reg signed [`PBW-1:0] sv, pbv, tt;
    reg [12:0]         swi;

    always @* begin
        do_if = sweep_en || (serve_en && mode_final);
        do_pb = serve_en && !mode_final;

        // arrivals, compacted: row 0 first, slot order inside a set
        na = 0;
        for (i = 0; i < `ARR; i = i + 1)
            for (s = 0; s < `SLOTS; s = s + 1)
                if (arr_en && tap_valid[i] && tap_sets[i*`SETW + s*`ENTW]) begin
                    arr_e[na] = tap_sets[i*`SETW + s*`ENTW + 1 +: LENW];
                    na = na + 1;
                end

        // which entries are served this cycle
        fc = fcnt;
        for (j = 0; j < PORTS; j = j + 1) begin
            lv[j] = 1'b0;
            le[j] = {LENW{1'b0}};
            if (serve_en) begin
                if (j < fc) begin
                    lv[j] = 1'b1;
                    le[j] = fifo_mem[(fhead + j) & (FIFO_DEPTH - 1)];
                end else if ((j - fc) < na) begin
                    lv[j] = 1'b1;
                    le[j] = arr_e[j - fc];
                end
            end else if (sweep_en && sw_v[j]) begin
                swi = sw_idx_f[j*13 +: 13];
                m1  = {2'b00, swi[12:7]} + 8'd1;
                n1  = {1'b0, swi[6:0]} + 8'd1;
                lv[j] = 1'b1;
                le[j] = {{(LENW-16){1'b0}}, n1, m1};      // sums = 0: the PB value alone is the total
            end
        end

        // FIFO bookkeeping
        popped = (fc < PORTS) ? fc : PORTS;
        a0     = (fc >= PORTS) ? 0 : (PORTS - fc);
        served = (fc + na < PORTS) ? (fc + na) : PORTS;
        if (!serve_en) served = 0;
        over   = fc + na - served;
        fifo_cnt_nxt = over;
        err_fifo     = (over > FIFO_DEPTH);

        // per-lane arithmetic
        delta = 0;
        served_final = 1'b0;
        ltot  = {PORTS*TW{1'b0}};
        ltagf = {PORTS*16{1'b0}};
        ldirty = {PORTS{1'b0}};
        for (j = 0; j < PORTS; j = j + 1) begin
            lidx[j] = 13'd0;
            if (lv[j]) begin
                lw = le[j];
                mm = lw[7:0];
                nn = lw[15:8];
                m1 = mm - 8'd1;
                n1 = nn - 8'd1;
                idx = {m1[5:0], n1[6:0]};
                lidx[j] = idx;
                ltagf[j*16 +: 16] = lw[15:0];
                db = pb_dirty[idx];
                ldirty[j] = db;
                pw = pb_mem[idx];
                for (t = 0; t < `TS; t = t + 1) begin
                    sv  = $signed(lw[16 + t*`SUMW +: `SUMW]);
                    pbv = db ? $signed(pw[t*`PBW +: `PBW]) : {`PBW{1'b0}};
                    tt  = sv + pbv;
                    ltot[(j*`TS + t)*`PBW +: `PBW] = tt;
                end
                if (do_pb) begin
                    if (!db) delta = delta + 1;
                end else if (do_if) begin
                    if (db) delta = delta - 1;
                    served_final = 1'b1;
                end
            end
        end
        dirty_cnt_nxt = dcnt_r + delta;
    end

    // ---------------------------------------------------------------- state update
    integer a, b;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            fhead <= 7'd0; fcnt <= 8'd0; pb_dirty <= {PBDEPTH{1'b0}};
            dcnt_r <= 14'd0; sweep_base <= 14'd0;
        end else begin
            if (serve_en) begin
                for (a = 0; a < na; a = a + 1)
                    if (fc + a >= PORTS)
                        fifo_mem[(fhead + fc + a - a0) & (FIFO_DEPTH - 1)] <= arr_e[a];
                fhead <= (fhead + popped) & (FIFO_DEPTH - 1);
            end
            fcnt <= fifo_cnt_nxt;

            for (b = 0; b < PORTS; b = b + 1)
                if (lv[b]) begin
                    if (do_pb) begin
                        pb_mem[lidx[b]]   <= ltot[b*TW +: TW];
                        pb_dirty[lidx[b]] <= 1'b1;
                    end else if (do_if) begin
                        pb_dirty[lidx[b]] <= 1'b0;
                    end
                end
            dcnt_r <= dirty_cnt_nxt;
            sweep_base <= sweep_en ? sw_next : 14'd0;
        end
    end

    // ---------------------------------------------------------------- neuron lanes (one clock each)
    wire [PORTS*16-1:0] rtag;
    genvar g;
    generate
        for (g = 0; g < PORTS; g = g + 1) begin : lane
            lif #(.T(`TS), .SUMW(`PBW), .THW(THW), .TAGW(16)) u_lif (
                .clk(clk), .rst_n(rst_n),
                .in_valid(lv[g] && do_if),
                .sums(ltot[g*TW +: TW]),
                .theta(theta),
                .tag_in(ltagf[g*16 +: 16]),
                .out_valid(res_valid[g]),
                .spikes(res_byte[g*8 +: 8]),
                .tag_out(rtag[g*16 +: 16])
            );
            assign res_m[g*8 +: 8] = rtag[g*16 +: 8];
            assign res_n[g*8 +: 8] = rtag[g*16 + 8 +: 8];
        end
    endgenerate
endmodule
