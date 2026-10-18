// 4x4 SNN layer on the weight-stationary systolic array: spike-train x INT8 weights -> LIF.
//   iverilog -g2012 -o snn.vvp tb_snn_systolic_array.v snn_systolic_array.v snn_pe.v lif_model.v
//   vvp snn.vvp
//   gtkwave snn.vcd
//
//   S[m][k] : T-bit input spike train (bit t = spike at timestep t)    -> streamed in
//   W[k][n] : INT8 weight                                               -> stationary
//   P[m][n][t] = sum_k S[m][k][t] * W[k][n]     O[m][n] = LIF(P[m][n][*], threshold)
`timescale 1ns/1ps
module tb_snn_systolic_array;
    localparam N = 4, DW = 8, T = 8;
    localparam Q = DW + $clog2(N) + $clog2(T), PWM = DW + $clog2(N);   // 13, 10

    reg clk = 0, rst_n = 0, load_w = 0, in_valid = 0;
    reg  [N*N*DW-1:0]     w_flat = 0;     // w_flat[(k*N+n)*DW +: DW] = W[k][n]
    reg  [N*T-1:0]        s_top  = 0;     // s_top[k*T +: T]          -> top of column k
    reg  [Q-2:0]          threshold = 0;     // unsigned, 0..4095
    wire [N*T-1:0]        spike_out;      // spike_out[n*T +: T]      <- row n, after LIF
    wire [N-1:0]          out_valid;

    snn_systolic_array #(.N(N), .DW(DW), .T(T)) dut (
        .clk(clk), .rst_n(rst_n), .load_w(load_w), .w_flat(w_flat),
        .s_top(s_top), .in_valid(in_valid), .threshold(threshold),
        .spike_out(spike_out), .out_valid(out_valid));

    always #5 clk = ~clk;

    reg        [T-1:0]  S [0:N*N-1];          // S[m*N+k]
    reg signed [DW-1:0] W [0:N*N-1];          // W[k*N+n]
    integer    Pref [0:N*N*T-1];              // Pref[(m*N+n)*T+t]
    integer    Phw  [0:N*N*T-1];
    reg [T-1:0] Oref [0:N*N-1], Ohw [0:N*N-1];
    integer seed = 32'h5EED;
    integer thr_i;
    integer i, j, k, m, c, t, run, mem, nvalid, errs_p, errs_s, errs_v, tests, nspk_in, nspk_out;

    task run_layer;
    begin
        // ---- reference: per-timestep psums, then soft-reset LIF ----
        thr_i = threshold;                 // as signed integer (threshold port is unsigned)
        for (m = 0; m < N; m = m + 1) for (j = 0; j < N; j = j + 1) begin
            mem = 0;
            for (t = 0; t < T; t = t + 1) begin
                Pref[(m*N+j)*T+t] = 0;
                for (k = 0; k < N; k = k + 1)
                    if (S[m*N+k][t]) Pref[(m*N+j)*T+t] = Pref[(m*N+j)*T+t] + W[k*N+j];
                if (t > 0 && Oref[m*N+j][t-1]) mem = mem - thr_i;
                mem = mem + Pref[(m*N+j)*T+t];
                Oref[m*N+j][t] = (mem > thr_i);
            end
        end
        for (i = 0; i < N*N; i = i + 1)
            for (t = 0; t < T; t = t + 1) begin
                nspk_in  = nspk_in  + S[i][t];
                nspk_out = nspk_out + Oref[i][t];
            end

        // 1) load weights once
        for (k = 0; k < N; k = k + 1) for (j = 0; j < N; j = j + 1)
            w_flat[(k*N+j)*DW +: DW] = W[k*N+j];
        s_top = 0;
        load_w = 1; @(posedge clk); #1; load_w = 0;

        // 2) stream spike trains: column k gets S[c-k][k]  (column k delayed k cycles)
        // 3) collect:  raw psums of row m leave row j in cycle m+j+N   (checked inside dut)
        //              LIF spikes of row m leave row j one cycle later (with out_valid)
        nvalid = 0;
        for (c = 0; c <= 3*N - 2; c = c + 1) begin
            for (k = 0; k < N; k = k + 1) begin
                m = c - k;
                s_top[k*T +: T] = (m >= 0 && m < N) ? S[m*N+k] : 0;
            end
            in_valid = (c < N);
            @(posedge clk); #1;
            for (j = 0; j < N; j = j + 1) begin
                m = c + 1 - N - j;
                if (m >= 0 && m < N)
                    for (t = 0; t < T; t = t + 1)
                        Phw[(m*N+j)*T+t] = $signed(dut.p_w[j][N][t*PWM +: PWM]);
                m = c - N - j;
                if (m >= 0 && m < N) begin
                    Ohw[m*N+j] = spike_out[j*T +: T];
                    if (out_valid[j] !== 1'b1) errs_v = errs_v + 1;
                end
                nvalid = nvalid + out_valid[j];
            end
        end
        s_top = 0; in_valid = 0;
        repeat (N + 1) begin @(posedge clk); #1; nvalid = nvalid + $countones(out_valid); end
        if (nvalid != N*N) errs_v = errs_v + 1;          // exactly one done pulse per output

        for (i = 0; i < N*N*T; i = i + 1) if (Phw[i] !== Pref[i]) errs_p = errs_p + 1;
        for (i = 0; i < N*N;   i = i + 1) if (Ohw[i] !== Oref[i]) errs_s = errs_s + 1;
        tests = tests + 1;
    end
    endtask

    initial begin
        $dumpfile("snn.vcd"); $dumpvars(0, tb_snn_systolic_array);
        errs_p = 0; errs_s = 0; errs_v = 0; tests = 0; nspk_in = 0; nspk_out = 0;
        repeat (2) @(posedge clk); #1; rst_n = 1;

        // ---- readable example ----
        threshold = 20;
        for (i = 0; i < N*N; i = i + 1) begin
            S[i] = 8'b1010_1010 >> (i % 3) | (i % 5 == 0 ? 8'h11 : 8'h00);
            W[i] = (i % 2) ? -(i * 3 % 17) : (i * 7 % 23);
        end
        run_layer;
        $display("threshold = %0d", threshold);
        $display("S (spike trains, t7..t0)                 W");
        for (i = 0; i < N; i = i + 1) begin
            $write("  "); for (k = 0; k < N; k = k + 1) $write(" %b", S[i*N+k]);
            $write("     "); for (j = 0; j < N; j = j + 1) $write("%5d", W[i*N+j]); $write("\n");
        end
        $display("psums P[0][0][t=0..7] (hw): %0d %0d %0d %0d %0d %0d %0d %0d",
                 Phw[0],Phw[1],Phw[2],Phw[3],Phw[4],Phw[5],Phw[6],Phw[7]);
        $display("LIF out O (hardware)                     O (reference)");
        for (i = 0; i < N; i = i + 1) begin
            $write("  "); for (j = 0; j < N; j = j + 1) $write(" %b", Ohw[i*N+j]);
            $write("     "); for (j = 0; j < N; j = j + 1) $write(" %b", Oref[i*N+j]); $write("\n");
        end

        // ---- corner cases ----
        threshold = 100;
        for (i = 0; i < N*N; i = i + 1) begin S[i] = 8'h00; W[i] =  127; end run_layer; // no input spikes
        for (i = 0; i < N*N; i = i + 1) begin S[i] = 8'hFF; W[i] =  127; end run_layer; // max positive
        for (i = 0; i < N*N; i = i + 1) begin S[i] = 8'hFF; W[i] = -128; end run_layer; // max negative
        threshold = 0;     // widest membrane swings: +4064 and -4096 (13-bit limits)
        for (i = 0; i < N*N; i = i + 1) begin S[i] = 8'hFF; W[i] =  127; end run_layer;
        for (i = 0; i < N*N; i = i + 1) begin S[i] = 8'hFF; W[i] = -128; end run_layer;
        for (i = 0; i < N*N; i = i + 1) begin S[i] = 8'h01 << (i % 8); W[i] = 1; end run_layer; // one-hot timesteps
        // threshold boundary: membrane reaches exactly 4064 at t=7
        for (i = 0; i < N*N; i = i + 1) begin S[i] = 8'hFF; W[i] =  127; end
        threshold = 4063; run_layer;   // fires once at t=7
        threshold = 4064; run_layer;   // never fires
        threshold = 4095; run_layer;   // max threshold

        // ---- 300 random layers: random weights, spike densities and thresholds ----
        for (run = 0; run < 300; run = run + 1) begin
            threshold = (run % 4 == 3) ? ($random(seed) & 4095) : ($random(seed) & 255);
            for (i = 0; i < N*N; i = i + 1) begin
                W[i] = $random(seed);
                case (run % 3)
                    0: S[i] = $random(seed);                       // ~50% spikes
                    1: S[i] = $random(seed) & $random(seed);       // ~25%
                    2: S[i] = $random(seed) | $random(seed);       // ~75%
                endcase
            end
            run_layer;
        end

        $display("-------------------------------------------");
        $display("%0d layers, %0d input spikes, %0d output spikes", tests, nspk_in, nspk_out);
        $display("%0d psum mismatches, %0d spike mismatches, %0d valid errors -> %s",
                 errs_p, errs_s, errs_v, (errs_p == 0 && errs_s == 0 && errs_v == 0) ? "PASS" : "FAIL");
        $finish;
    end
endmodule