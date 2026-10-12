// 4x4 x 4x4 matrix multiply on the weight-stationary systolic array.
//   iverilog -g2012 -o sa.vvp tb_ws_systolic_array.v ws_systolic_array.v ws_pe.v
//   vvp sa.vvp
//   gtkwave ws.vcd
//
//   C = A x B      B = weights (loaded once, stationary)    A = streamed in rows
`timescale 1ns/1ps
module tb_ws_systolic_array;
    localparam N = 4, DW = 8, AW = 24;

    reg clk = 0, rst_n = 0, load_w = 0;
    reg  [N*N*DW-1:0] w_flat = 0;      // w_flat[(k*N+j)*DW +: DW] = B[k][j]
    reg  [N*DW-1:0]   a_top = 0;      // a_top[k*DW +: DW]       -> top of array column k
    wire [N*AW-1:0]   y_right;        // y_right[n*AW +: AW]     <- right edge of array row n

    ws_systolic_array #(.N(N), .DW(DW), .AW(AW)) dut (
        .clk(clk), .rst_n(rst_n), .load_w(load_w),
        .w_flat(w_flat), .a_top(a_top), .y_right(y_right));

    always #5 clk = ~clk;

    reg signed [DW-1:0] A [0:N*N-1];   // A[i*N+k]
    reg signed [DW-1:0] B [0:N*N-1];   // B[k*N+j]
    integer Cref [0:N*N-1];
    integer Chw  [0:N*N-1];
    integer seed = 32'hC0FFEE;
    integer i, j, k, m, c, t, errs, tests;

    // one full 4x4 multiply: load B, stream skewed A, collect C
    task run_matmul;
    begin
        // reference
        for (i = 0; i < N; i = i + 1) for (j = 0; j < N; j = j + 1) begin
            Cref[i*N+j] = 0;
            for (k = 0; k < N; k = k + 1) Cref[i*N+j] = Cref[i*N+j] + A[i*N+k]*B[k*N+j];
        end

        // 1) load weights once
        for (k = 0; k < N; k = k + 1) for (j = 0; j < N; j = j + 1)
            w_flat[(k*N+j)*DW +: DW] = B[k*N+j];
        a_top = 0;
        load_w = 1; @(posedge clk); #1; load_w = 0;

        // 2) stream A: column k of the array gets A[c-k][k]  (column k delayed k cycles)
        //    and 3) collect: row n delivers output row m = c-(N-1)-n
        for (c = 0; c <= 3*N - 3; c = c + 1) begin
            for (k = 0; k < N; k = k + 1) begin
                m = c - k;
                a_top[k*DW +: DW] = (m >= 0 && m < N) ? A[m*N+k] : 0;
            end
            @(posedge clk); #1;
            for (j = 0; j < N; j = j + 1) begin
                m = c - (N-1) - j;
                if (m >= 0 && m < N) Chw[m*N+j] = $signed(y_right[j*AW +: AW]);
            end
        end
        a_top = 0;
        repeat (N) @(posedge clk);           // flush, so back-to-back runs are clean

        for (i = 0; i < N*N; i = i + 1) if (Chw[i] !== Cref[i]) errs = errs + 1;
        tests = tests + 1;
    end
    endtask

    initial begin
        $dumpfile("ws.vcd"); $dumpvars(0, tb_ws_systolic_array);
        errs = 0; tests = 0;
        repeat (2) @(posedge clk); #1; rst_n = 1;

        // ---- readable example ----
        for (i = 0; i < N*N; i = i + 1) begin A[i] = i + 1; B[i] = (i % 2) ? -(i % 5) : (i % 3); end
        run_matmul;
        $display("A =                      B =");
        for (i = 0; i < N; i = i + 1) begin
            $write("  "); for (k = 0; k < N; k = k + 1) $write("%4d", A[i*N+k]);
            $write("      "); for (j = 0; j < N; j = j + 1) $write("%4d", B[i*N+j]); $write("\n");
        end
        $display("C (hardware)             C (reference)");
        for (i = 0; i < N; i = i + 1) begin
            $write("  "); for (j = 0; j < N; j = j + 1) $write("%6d", Chw[i*N+j]);
            $write("    "); for (j = 0; j < N; j = j + 1) $write("%6d", Cref[i*N+j]); $write("\n");
        end

        // ---- corner cases ----
        for (i = 0; i < N*N; i = i + 1) begin A[i] = -128; B[i] = -128; end run_matmul;
        for (i = 0; i < N*N; i = i + 1) begin A[i] =  127; B[i] = -128; end run_matmul;
        for (i = 0; i < N; i = i + 1) for (j = 0; j < N; j = j + 1) begin
            A[i*N+j] = (i == j) ? 1 : 0; B[i*N+j] = i*10 + j - 7; end        run_matmul;

        // ---- 300 random signed INT8 matrix pairs ----
        for (t = 0; t < 300; t = t + 1) begin
            for (i = 0; i < N*N; i = i + 1) begin A[i] = $random(seed); B[i] = $random(seed); end
            run_matmul;
        end

        $display("-------------------------------------------");
        $display("%0d matrix multiplies, %0d mismatches -> %s", tests, errs, errs == 0 ? "PASS" : "FAIL");
        $finish;
    end
endmodule