// tb_snn.v -- testbench: runs a whole layer (C = A x B, tiled 64 x 128) through snn_top.
//
// The testbench plays HBM / tile SRAM:
//   +A=<file>  weights, one hex byte per line, row-major M x K          (int8, two's complement)
//   +B=<file>  activations, one hex byte per line, row-major K x N      (8-bit spike masks)
//   +O=<file>  output spike bytes, row-major M x N
//   +M= +K= +N= +THETA=
// Tiles are issued in the order m0 outer, n0 inner (same as snn_sim.run_layer).
// It prints one line per tile:
//   TILE m0 n0 mb nb cyc_array cyc_pre passes stalls pp_cycles
`timescale 1ns/1ps
module tb_snn;
    reg clk = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;

    integer M, K, N, THETA;
    reg [8*256:1] afile, bfile, ofile;
    reg [7:0] Af [0:262143];
    reg [7:0] Bf [0:262143];
    reg [7:0] Of [0:262143];

    integer m0, n0, mb_t, nb_t;
    reg        start;
    reg [7:0]  mb, nb;
    reg [15:0] kdim;
    reg [23:0] theta;

    wire [7:0]  w_rd_row, a_rd_col;
    wire [11:0] w_rd_slab, a_rd_slab;
    reg  [31:0] w_rd_data, a_rd_data;
    wire [15:0]  hbm_wr_valid;
    wire [127:0] hbm_wr_row, hbm_wr_col, hbm_wr_data;
    wire busy, tile_done, pp_done, err;
    wire [31:0] cyc_array, cyc_pre, n_pass, n_stall, pp_cycles;

    snn_top dut (
        .clk(clk), .rst_n(rst_n), .start(start), .mb(mb), .nb(nb), .kdim(kdim), .theta(theta),
        .w_rd_row(w_rd_row), .w_rd_slab(w_rd_slab), .w_rd_data(w_rd_data),
        .a_rd_col(a_rd_col), .a_rd_slab(a_rd_slab), .a_rd_data(a_rd_data),
        .hbm_wr_valid(hbm_wr_valid), .hbm_wr_row(hbm_wr_row), .hbm_wr_col(hbm_wr_col), .hbm_wr_data(hbm_wr_data),
        .busy(busy), .tile_done(tile_done), .pp_done(pp_done),
        .cyc_array(cyc_array), .cyc_pre(cyc_pre), .n_pass(n_pass), .n_stall(n_stall),
        .pp_cycles(pp_cycles), .err(err));

    // ---- tile memories: synchronous read, 1-cycle latency
    integer kk;
    reg [31:0] dw, da;
    always @(posedge clk) begin
        dw = 32'd0;
        da = 32'd0;
        for (kk = 0; kk < 4; kk = kk + 1) begin
            if ((w_rd_slab * 4 + kk) < K && w_rd_row < mb_t)
                dw[8*kk +: 8] = Af[(m0 + w_rd_row) * K + w_rd_slab * 4 + kk];
            if ((a_rd_slab * 4 + kk) < K && a_rd_col < nb_t)
                da[8*kk +: 8] = Bf[(a_rd_slab * 4 + kk) * N + n0 + a_rd_col];
        end
        w_rd_data <= dw;
        a_rd_data <= da;
    end

    // ---- HBM write model (output region starts at zero)
    integer l;
    always @(posedge clk)
        for (l = 0; l < 16; l = l + 1)
            if (hbm_wr_valid[l])
                Of[(m0 + hbm_wr_row[l*8 +: 8]) * N + n0 + hbm_wr_col[l*8 +: 8]] = hbm_wr_data[l*8 +: 8];

    // ---- error monitor
    integer nerr = 0;
    always @(posedge clk) if (rst_n && err) begin
        nerr = nerr + 1;
        if (nerr < 5) $display("ERROR flag at %0t: slot=%b align=%b fifo=%b fifo_cnt=%0d st=%0d ea=%b cmask=%b keff=%0d slab=%0d", $time,
                               dut.err_slot, dut.err_align, dut.err_fifo, dut.fifo_cnt, dut.st, dut.u_arr.ea, dut.u_arr.cmask, dut.keff, dut.slab);
    end

    integer i, guard;
    integer tot_array, tot_pre, tot_pp, last_pp;
    initial begin
        if (!$value$plusargs("M=%d", M)) M = 8;
        if (!$value$plusargs("K=%d", K)) K = 8;
        if (!$value$plusargs("N=%d", N)) N = 8;
        if (!$value$plusargs("THETA=%d", THETA)) THETA = 0;
        if (!$value$plusargs("A=%s", afile)) afile = "A.hex";
        if (!$value$plusargs("B=%s", bfile)) bfile = "B.hex";
        if (!$value$plusargs("O=%s", ofile)) ofile = "O.hex";
        for (i = 0; i < 262144; i = i + 1) begin Af[i] = 0; Bf[i] = 0; Of[i] = 0; end
        $readmemh(afile, Af);
        $readmemh(bfile, Bf);
        start = 0; mb = 0; nb = 0; kdim = K; theta = THETA; mb_t = 0; nb_t = 0; m0 = 0; n0 = 0;
        tot_array = 0; tot_pre = 0; tot_pp = 0; last_pp = 0;
        repeat (4) @(posedge clk);
        rst_n = 1;
        repeat (2) @(posedge clk);

        for (m0 = 0; m0 < M; m0 = m0 + 64)
            for (n0 = 0; n0 < N; n0 = n0 + 128) begin
                mb_t = (M - m0 < 64) ? (M - m0) : 64;
                nb_t = (N - n0 < 128) ? (N - n0) : 128;
                mb = mb_t; nb = nb_t;
                @(posedge clk); #1 start = 1;
                @(posedge clk); #1 start = 0;
                guard = 0;
                while (!pp_done && guard < 3000000) begin @(posedge clk); guard = guard + 1; end
                if (guard >= 3000000) begin $display("TIMEOUT"); $finish; end
                @(posedge clk);
                $display("TILE %0d %0d %0d %0d %0d %0d %0d %0d %0d", m0, n0, mb_t, nb_t,
                         cyc_array, cyc_pre, n_pass, n_stall, pp_cycles);
                tot_array = tot_array + cyc_array;
                tot_pre   = tot_pre + cyc_pre;
                last_pp   = pp_cycles;
                repeat (2) @(posedge clk);
            end
        $display("LAYER cyc_array %0d cyc_pre %0d last_pp %0d errors %0d", tot_array, tot_pre, last_pp, nerr);
        $writememh(ofile, Of, 0, M * N - 1);
        $display("DONE");
        $finish;
    end
endmodule
