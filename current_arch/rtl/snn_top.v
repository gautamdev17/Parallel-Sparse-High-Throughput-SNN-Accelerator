// snn_top.v -- one output tile of  C = A x B  on the 4x4 dual-sparse weight-stationary array.
//
//   A = weights (mb x kdim, int8)   B = activations (kdim x nb, 8-bit spike masks)
//   C = mb x nb, 8 spike bits per element.     mb <= 64, nb <= 128 (a tile; tiles live in HBM).
//
// Pipeline: pre-proc (pack both operands of a K-slab)  ->  systolic array  ->  exit stage
//           (FIFO, partial buffer, one-cycle neuron)   ->  post-proc (unpack, write to HBM).
//
// Control flow per tile (this is the FSM below; names match REPORT.md):
//   for every K-slab s (4 wide):
//       PRE   : pre-proc packs the weight rows and the activation columns of the slab
//       for every chunk of up to 4 packed weight rows (a "pass"):
//           LOAD : write the chunk into the PE rows, one PE row per cycle
//           RUN  : stream all P packed columns, collect the exiting psum sets
//                  (the pass ends when all P columns have gone through and the FIFO is empty)
//   SWEEP : still-dirty partial-buffer entries go through the neuron
//   TAIL  : one cycle for the registered neuron output
//   FIN   : tile_done -> post-proc unpacks the result buffer into HBM writes.
//
// cyc_array counts LOAD + RUN + SWEEP + TAIL cycles = the cycles the compute datapath works.
// cyc_pre counts the cycles pre-proc needs; REPORT.md assumes packing is free (done ahead in
// SRAM, e.g. while the previous slab runs), so it is reported separately and not added.
`include "snn_defs.vh"
module snn_top #(
    parameter PORTS      = 8,
    parameter FIFO_DEPTH = 64,
    parameter THW        = 24
) (
    input             clk,
    input             rst_n,
    input             start,
    input  [7:0]      mb,
    input  [7:0]      nb,
    input  [15:0]     kdim,
    input  [THW-1:0]  theta,
    // weight tile memory (1-cycle read latency): 4 bytes of one row for one slab
    output [7:0]      w_rd_row,
    output [11:0]     w_rd_slab,
    input  [31:0]     w_rd_data,
    // activation tile memory: 4 bytes of one column for one slab
    output [7:0]      a_rd_col,
    output [11:0]     a_rd_slab,
    input  [31:0]     a_rd_data,
    // HBM write port (tile-local coordinates), 16 lanes
    output [15:0]     hbm_wr_valid,
    output [127:0]    hbm_wr_row,
    output [127:0]    hbm_wr_col,
    output [127:0]    hbm_wr_data,
    // status
    output            busy,
    output reg        tile_done,        // compute finished, results are in the result buffer
    output            pp_done,          // dense tile has been written to HBM
    output reg [31:0] cyc_array,
    output reg [31:0] cyc_pre,
    output reg [31:0] n_pass,
    output reg [31:0] n_stall,
    output [31:0]     pp_cycles,
    output            err
);
    localparam IDLE = 3'd0, PRE0 = 3'd1, PRE1 = 3'd2, LOAD = 3'd3, RUN = 3'd4,
               SWEEP = 3'd5, TAIL = 3'd6, FIN = 3'd7;
    reg [2:0]  st;

    // tile parameters
    reg [7:0]  mb_r, nb_r;
    reg [15:0] kdim_r;
    reg [THW-1:0] theta_r;
    reg [11:0] slab;
    reg [7:0]  rtot, ptot, c0;
    reg [2:0]  ldj;
    reg [9:0]  cc;
    reg        any_res;

    // ------------------------------------------------------------ derived values
    wire [15:0] s16    = (kdim_r + 16'd3) >> 2;
    wire [11:0] S      = s16[11:0];
    wire        last_slab = (slab == S - 12'd1);
    wire [2:0]  keff   = (last_slab && kdim_r[1:0] != 2'b00) ? {1'b0, kdim_r[1:0]} : 3'd4;
    wire [7:0]  rrem   = rtot - c0;
    wire [2:0]  R      = (rrem >= 8'd4) ? 3'd4 : rrem[2:0];
    wire [9:0]  need   = {2'b00, ptot} + {7'd0, R} + {7'd0, keff} - 10'd1;   // P + R + K - 1

    wire [7:0]  fifo_cnt;
    wire [7:0]  fifo_cnt_nxt;
    wire [13:0] dirty_cnt, dirty_cnt_nxt;
    wire        served_final, err_fifo;

    wire run     = (st == RUN);
    wire frozen  = (({1'b0, fifo_cnt} + {R, 2'b00}) > FIFO_DEPTH);   // fifo + R*slots > depth
    wire adv     = run && !frozen && (cc < need);
    wire [9:0]  cc_nxt = adv ? (cc + 10'd1) : cc;
    wire run_done = run && (cc_nxt >= need) && (fifo_cnt_nxt == 8'd0);

    // ------------------------------------------------------------ pre-proc
    wire        pre_done, pre_busy;
    wire [7:0]  w_groups, a_groups;
    wire [64*64-1:0]  w_pk;
    wire [128*64-1:0] a_pk;

    preproc u_pre (
        .clk(clk), .rst_n(rst_n), .start(st == PRE0),
        .mb(mb_r), .nb(nb_r), .slab(slab), .keff(keff),
        .w_rd_row(w_rd_row), .w_rd_slab(w_rd_slab), .w_rd_data(w_rd_data),
        .a_rd_col(a_rd_col), .a_rd_slab(a_rd_slab), .a_rd_data(a_rd_data),
        .busy(pre_busy), .done(pre_done),
        .w_groups(w_groups), .a_groups(a_groups), .w_pk(w_pk), .a_pk(a_pk));

    // ------------------------------------------------------------ weight load
    wire [63:0] wrow = w_pk[(c0 + ldj) * 64 +: 64];
    reg  [`ARR*`IDXW-1:0] ld_idx;
    reg  [`ARR*`VALW-1:0] ld_val;
    integer lk;
    always @* begin
        for (lk = 0; lk < `ARR; lk = lk + 1) begin
            ld_idx[lk*`IDXW +: `IDXW] = wrow[16*lk + 8 +: 8];
            ld_val[lk*`VALW +: `VALW] = wrow[16*lk +: 8];
        end
    end
    wire ld_first = (st == LOAD) && (ldj == 3'd0);

    // ------------------------------------------------------------ activation feeder (skewed)
    reg [`ARR-1:0]       f_valid;
    reg [`ARR*`IDXW-1:0] f_idx;
    reg [`ARR*`TS-1:0]   f_mask;
    integer fk, fn, cci;
    reg [15:0] w16;
    always @* begin
        cci = cc;
        for (fk = 0; fk < `ARR; fk = fk + 1) begin
            fn = cci - fk;
            f_valid[fk] = 1'b0;
            f_idx[fk*`IDXW +: `IDXW] = 8'd0;
            f_mask[fk*`TS +: `TS]    = 8'd0;
            w16 = 16'd0;
            if (run && fk < keff && fn >= 0 && fn < ptot) begin
                w16 = a_pk[fn*64 + fk*16 +: 16];
                f_valid[fk] = 1'b1;
                f_idx[fk*`IDXW +: `IDXW] = w16[15:8];
                f_mask[fk*`TS +: `TS]    = w16[7:0];
            end
        end
    end

    // ------------------------------------------------------------ array
    wire [`ARR-1:0]       tap_valid;
    wire [`ARR*`SETW-1:0] tap_sets;
    wire                  err_slot, err_align;

    systolic_array u_arr (
        .clk(clk), .rst_n(rst_n), .en(adv), .clr(ld_first),
        .ld_clr(ld_first), .ld_en(st == LOAD), .ld_row(ldj[1:0]),
        .ld_idx(ld_idx), .ld_val(ld_val),
        .in_valid(f_valid), .in_idx(f_idx), .in_mask(f_mask),
        .keff(keff),
        .tap_valid(tap_valid), .tap_sets(tap_sets),
        .err_slot(err_slot), .err_align(err_align));

    // ------------------------------------------------------------ exit stage + post-proc
    wire [PORTS-1:0]   res_valid;
    wire [PORTS*8-1:0] res_m, res_n, res_byte;

    exit_stage #(.PORTS(PORTS), .FIFO_DEPTH(FIFO_DEPTH), .THW(THW)) u_exit (
        .clk(clk), .rst_n(rst_n),
        .arr_en(adv), .tap_valid(tap_valid), .tap_sets(tap_sets),
        .serve_en(run), .mode_final(last_slab), .sweep_en(st == SWEEP),
        .theta(theta_r),
        .fifo_cnt(fifo_cnt), .fifo_cnt_nxt(fifo_cnt_nxt),
        .dirty_cnt(dirty_cnt), .dirty_cnt_nxt(dirty_cnt_nxt),
        .served_final(served_final), .err_fifo(err_fifo),
        .res_valid(res_valid), .res_m(res_m), .res_n(res_n), .res_byte(res_byte));

    wire pp_busy;
    wire [13:0] nres;
    postproc #(.PORTS(PORTS), .LANES(16)) u_post (
        .clk(clk), .rst_n(rst_n), .tile_start(st == IDLE && start),
        .res_valid(res_valid), .res_m(res_m), .res_n(res_n), .res_byte(res_byte),
        .tile_done(tile_done),
        .hbm_wr_valid(hbm_wr_valid), .hbm_wr_row(hbm_wr_row),
        .hbm_wr_col(hbm_wr_col), .hbm_wr_data(hbm_wr_data),
        .busy(pp_busy), .pp_done(pp_done), .pp_cycles(pp_cycles), .nres(nres));

    assign busy = (st != IDLE) || pp_busy;
    // alignment / slot checks only mean something while the array advances (a pass with R < 4 ends
    // before its tokens have left the unused rows; the next LOAD clears them)
    assign err  = ((err_slot | err_align) & adv) | err_fifo;

    // ------------------------------------------------------------ FSM
    // "what comes after this pass / slab" decision, shared by the RUN-exit and the empty-slab path
    wire more_chunks = ((c0 + 8'd4) < rtot);
    wire more_slabs  = ((slab + 12'd1) < S);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            st <= IDLE; tile_done <= 1'b0; any_res <= 1'b0;
            cyc_array <= 0; cyc_pre <= 0; n_pass <= 0; n_stall <= 0;
            mb_r <= 0; nb_r <= 0; kdim_r <= 0; theta_r <= 0;
            slab <= 0; rtot <= 0; ptot <= 0; c0 <= 0; ldj <= 0; cc <= 0;
        end else begin
            tile_done <= 1'b0;
            case (st)
            IDLE: if (start) begin
                mb_r <= mb; nb_r <= nb; kdim_r <= kdim; theta_r <= theta;
                slab <= 12'd0; any_res <= 1'b0;
                cyc_array <= 0; cyc_pre <= 0; n_pass <= 0; n_stall <= 0;
                st <= PRE0;
            end

            PRE0: begin cyc_pre <= cyc_pre + 1; st <= PRE1; end

            PRE1: begin
                cyc_pre <= cyc_pre + 1;
                if (pre_done) begin
                    rtot <= w_groups; ptot <= a_groups;
                    if (w_groups == 0 || a_groups == 0) begin     // empty slab: nothing to do
                        if (more_slabs) begin slab <= slab + 12'd1; st <= PRE0; end
                        else if (dirty_cnt != 0) st <= SWEEP;
                        else if (any_res) st <= TAIL;
                        else st <= FIN;
                    end else begin
                        c0 <= 8'd0; ldj <= 3'd0; st <= LOAD;
                    end
                end
            end

            LOAD: begin
                cyc_array <= cyc_array + 1;
                ldj <= ldj + 3'd1;
                if (ldj + 3'd1 == R) begin
                    st <= RUN; cc <= 10'd0; n_pass <= n_pass + 1;
                end
            end

            RUN: begin
                cyc_array <= cyc_array + 1;
                if (frozen) n_stall <= n_stall + 1;
                cc <= cc_nxt;
                if (served_final) any_res <= 1'b1;
                if (run_done) begin
                    if (more_chunks) begin c0 <= c0 + 8'd4; ldj <= 3'd0; st <= LOAD; end
                    else if (more_slabs) begin slab <= slab + 12'd1; st <= PRE0; end
                    else if (dirty_cnt_nxt != 0) st <= SWEEP;
                    else if (any_res || served_final) st <= TAIL;
                    else st <= FIN;
                end
            end

            SWEEP: begin
                cyc_array <= cyc_array + 1;
                any_res <= 1'b1;
                if (dirty_cnt_nxt == 0) st <= TAIL;
            end

            TAIL: begin cyc_array <= cyc_array + 1; st <= FIN; end

            FIN: begin tile_done <= 1'b1; st <= IDLE; end

            default: st <= IDLE;
            endcase
        end
    end
endmodule
