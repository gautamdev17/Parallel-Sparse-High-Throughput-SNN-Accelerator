// iverilog -g2012 -o tm.vvp tb_ws_tiled_matmul.v ws_tiled_matmul.v ws_systolic_array.v ws_pe.v
// vvp tm.vvp        gtkwave ws_tiled.vcd
//
// Memory model + descriptor only. ALL tiling is done by the RTL.
`timescale 1ns/1ps
module tb_ws_tiled_matmul;
    localparam ARR = 4, DW = 8, ACCW = 32, MT = 16, ADDRW = 20, DIMW = 16;
    localparam MEMSZ = 8192;

    reg clk = 0, rst_n = 0, start = 0;
    reg  [DIMW-1:0]  dim_m = 0, dim_k = 0, dim_n = 0;
    reg  [ADDRW-1:0] a_base = 0, b_base = 0, c_base = 0;
    wire done, busy;
    wire [ARR*ADDRW-1:0] a_raddr, b_raddr, c_waddr;
    reg  [ARR*DW-1:0]    a_rdata = 0, b_rdata = 0;
    wire [ARR-1:0]       c_we;
    wire [ARR*ACCW-1:0]  c_wdata;

    ws_tiled_matmul #(.ARR(ARR), .DW(DW), .ACCW(ACCW), .MT(MT), .ADDRW(ADDRW), .DIMW(DIMW)) dut (
        .clk(clk), .rst_n(rst_n), .start(start),
        .dim_m(dim_m), .dim_k(dim_k), .dim_n(dim_n),
        .a_base(a_base), .b_base(b_base), .c_base(c_base),
        .done(done), .busy(busy),
        .a_raddr(a_raddr), .a_rdata(a_rdata),
        .b_raddr(b_raddr), .b_rdata(b_rdata),
        .c_we(c_we), .c_waddr(c_waddr), .c_wdata(c_wdata));

    always #5 clk = ~clk;

    // ---------------- memories (synchronous read, 1-cycle latency) ----------------
    reg signed [DW-1:0]   A_mem [0:MEMSZ-1];
    reg signed [DW-1:0]   B_mem [0:MEMSZ-1];
    reg signed [ACCW-1:0] C_mem [0:MEMSZ-1];
    integer p;
    always @(posedge clk)
        for (p = 0; p < ARR; p = p + 1) begin
            a_rdata[p*DW +: DW] <= A_mem[a_raddr[p*ADDRW +: ADDRW]];
            b_rdata[p*DW +: DW] <= B_mem[b_raddr[p*ADDRW +: ADDRW]];
            if (c_we[p]) C_mem[c_waddr[p*ADDRW +: ADDRW]] <= c_wdata[p*ACCW +: ACCW];
        end

    // ---------------- test bench ----------------
    localparam SENT = 32'h7FFF_1234;           // sentinel to detect stray writes
    integer seed = 32'hBEEF01;
    integer errs = 0, tests = 0, fails = 0;
    integer i, j, k, cyc, bad, stray;
    integer ref_v;
    integer tot_cycles;

    // mode: 0 = random, 1 = all -128 (worst-case magnitude)
    task run_case;
        input integer M, K, N, mode, ab, bb, cb;
        integer m_, k_, n_;
    begin
        // fill operands (non-zero bases to prove addressing)
        for (m_ = 0; m_ < M; m_ = m_ + 1) for (k_ = 0; k_ < K; k_ = k_ + 1)
            A_mem[ab + m_*K + k_] = (mode == 1) ? -128 : $random(seed);
        for (k_ = 0; k_ < K; k_ = k_ + 1) for (n_ = 0; n_ < N; n_ = n_ + 1)
            B_mem[bb + k_*N + n_] = (mode == 1) ? -128 : $random(seed);
        for (i = cb - 4; i < cb + M*N + 8; i = i + 1) C_mem[i] = SENT;

        dim_m = M; dim_k = K; dim_n = N; a_base = ab; b_base = bb; c_base = cb;
        @(negedge clk); start = 1;
        @(negedge clk); start = 0;
        cyc = 2;
        while (!done && cyc < 3000000) begin @(negedge clk); cyc = cyc + 1; end
        if (!done) begin $display("TIMEOUT  M=%0d K=%0d N=%0d", M, K, N); fails = fails + 1; end

        // check every element
        bad = 0;
        for (m_ = 0; m_ < M; m_ = m_ + 1) for (n_ = 0; n_ < N; n_ = n_ + 1) begin
            ref_v = 0;
            for (k_ = 0; k_ < K; k_ = k_ + 1)
                ref_v = ref_v + A_mem[ab + m_*K + k_] * B_mem[bb + k_*N + n_];
            if (C_mem[cb + m_*N + n_] !== ref_v) begin
                bad = bad + 1;
                if (bad <= 3) $display("  mismatch C[%0d][%0d]: hw=%0d ref=%0d", m_, n_, C_mem[cb + m_*N + n_], ref_v);
            end
        end
        // nothing outside the MxN region may be written
        stray = 0;
        for (i = cb - 4; i < cb; i = i + 1)              if (C_mem[i] !== SENT) stray = stray + 1;
        for (i = cb + M*N; i < cb + M*N + 8; i = i + 1)  if (C_mem[i] !== SENT) stray = stray + 1;

        tests = tests + 1; errs = errs + bad + stray;
        tot_cycles = cyc;
        $display("M=%3d K=%3d N=%3d | %7d cycles | MAC util %4.1f%% | %s",
                 M, K, N, cyc, 100.0*M*K*N/(cyc*ARR*ARR),
                 (bad == 0 && stray == 0 && done) ? "ok" : "FAIL");
    end
    endtask

    integer t, M, K, N;
    initial begin
        $dumpfile("ws_tiled.vcd"); $dumpvars(0, tb_ws_tiled_matmul);
        repeat (3) @(negedge clk); rst_n = 1;

        $display("---- hand-picked shapes (aligned, ragged, M > MT) ----");
        run_case( 4,  4,  4, 0,  0,   0,  0);   // exactly one tile
        run_case( 1,  1,  1, 0,  3,   5,  7);
        run_case( 1,  5,  3, 0,  0,   0,  0);
        run_case( 3,  7,  2, 0, 11,   9, 13);
        run_case( 5,  4,  4, 0,  0,   0,  0);
        run_case( 4,  8,  4, 0,  0,   0,  0);   // two K-tiles
        run_case( 4,  4,  8, 0,  0,   0,  0);   // two N-tiles
        run_case( 6, 10,  7, 0,  2,   4,  6);
        run_case(16, 16, 16, 0,  0,   0,  0);
        run_case(17,  9, 13, 0,  1,   2,  3);
        run_case(33, 20, 10, 0,  0,   0,  0);   // 3 M-blocks (MT=16)
        run_case( 2, 40,  9, 0,  0,   0,  0);
        run_case(31, 31, 31, 0,  0,   0,  0);
        run_case( 8, 12,  8, 1,  0,   0,  0);   // worst-case magnitudes (-128 * -128)

        $display("---- 60 random shapes, M,K,N in [1,40], random bases ----");
        for (t = 0; t < 60; t = t + 1) begin
            M = 1 + ({$random(seed)} % 40);
            K = 1 + ({$random(seed)} % 40);
            N = 1 + ({$random(seed)} % 40);
            run_case(M, K, N, 0, {$random(seed)} % 100, {$random(seed)} % 100, 8 + {$random(seed)} % 100);
        end

        $display("--------------------------------------------------------------");
        $display("%0d matmuls, %0d element/stray errors, %0d timeouts -> %s",
                 tests, errs, fails, (errs == 0 && fails == 0) ? "PASS" : "FAIL");
        $finish;
    end
endmodule