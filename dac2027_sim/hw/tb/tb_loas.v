// tb_loas.v -- drives ONE LoAS TPPE (rtl/loas, T=8, 8-bit weights) through NCHUNK 128-element chunks.
// Workload = the zip's LoAS model: bitmask_a (spikes, non-silent) density 0.261, bitmask_b (weights) dense.
// Checks every result against a behavioural reference (mod 2^12, the RTL's accumulator width), counts
// cycles per chunk, and dumps a VCD of the window used for power (works for RTL and gate-level netlist).
`timescale 1ns/1ps
module tb_loas;
    localparam W = 128, T = 8, WW = 8, NCHUNK = `NCHUNK;
    reg clk = 0, rst = 1;
    always #0.625 clk = ~clk;                       // 800 MHz

    reg start_new_batch = 0, valid_match = 0;
    reg [W-1:0] bitmask_a = 0, bitmask_b = 0;
    reg [W*WW-1:0] fibre_b = 0;
    reg [T-1:0] fibre_a_data = 0;
    reg fibre_a_valid = 0;
    wire [7:0] fibre_a_addr;
    wire fibre_a_read_en, ready_for_input, tppe_done, result_valid;
    wire [T-1:0] spike_out;
    wire [11:0] r0, r1, r2, r3, r4, r5, r6, r7;

    tppe dut(.clk(clk), .rst(rst), .start_new_batch(start_new_batch), .ready_for_input(ready_for_input),
             .tppe_done(tppe_done), .valid_match(valid_match), .bitmask_b(bitmask_b),
             .fibre_b_data_flat(fibre_b), .bitmask_a(bitmask_a), .fibre_a_data(fibre_a_data),
             .fibre_a_valid(fibre_a_valid), .fibre_a_addr(fibre_a_addr), .fibre_a_read_en(fibre_a_read_en),
             .lif_threshold(12'd300), .spike_out(spike_out),
             .result_0(r0), .result_1(r1), .result_2(r2), .result_3(r3),
             .result_4(r4), .result_5(r5), .result_6(r6), .result_7(r7), .result_valid(result_valid));

    reg [T-1:0] fibre_a_mem [0:W-1];   // compressed spike trains of the non-silent inputs
    reg [11:0] exp_v [0:T-1];
    reg [11:0] got [0:T-1];
    integer i, t, n, k, nb, na, nm, c0, total_cycles, total_nm, errors, seen;
    integer cyc = 0;
    always @(posedge clk) cyc <= cyc + 1;

    // fibre-A memory: one-cycle read latency
    always @(posedge clk) begin
        fibre_a_valid <= fibre_a_read_en;
        if (fibre_a_read_en) fibre_a_data <= fibre_a_mem[fibre_a_addr - 1];   // laggy offsets are 1-based
    end
    always @(posedge clk) if (result_valid) begin
        got[0] <= r0; got[1] <= r1; got[2] <= r2; got[3] <= r3; got[4] <= r4; got[5] <= r5; got[6] <= r6; got[7] <= r7;
        seen <= 1;
    end

    initial begin
        if ($test$plusargs("vcd")) begin
            $dumpfile(`VCDFILE);
        end
        errors = 0; total_cycles = 0; total_nm = 0;
        i = `SEED; i = $urandom(i);
        repeat (4) @(posedge clk);
        rst = 0;
        for (n = 0; n < NCHUNK; n = n + 1) begin
            if (n == 2 && $test$plusargs("vcd")) $dumpvars(0, tb_loas.dut);   // skip warm-up chunks
            // ---- build the chunk
            bitmask_b = {W{1'b1}};
            nb = 0; na = 0; nm = 0;
            for (t = 0; t < T; t = t + 1) exp_v[t] = 0;
            for (k = 0; k < W; k = k + 1) begin
                fibre_b[k*WW +: WW] = 1 + ($urandom % 63);
                bitmask_a[k] = (($urandom % 1000) < 261);
            end
            for (k = 0; k < W; k = k + 1) begin
                if (bitmask_a[k]) begin
                    fibre_a_mem[na] = 0;
                    while (fibre_a_mem[na] == 0)
                        for (t = 0; t < T; t = t + 1) fibre_a_mem[na][t] = (($urandom % 100) < 30);
                    for (t = 0; t < T; t = t + 1)
                        if (fibre_a_mem[na][t]) exp_v[t] = exp_v[t] + fibre_b[nb*WW +: WW];
                    na = na + 1;
                    nm = nm + 1;
                end
                if (bitmask_b[k]) nb = nb + 1;
            end
            // ---- run it
            @(negedge clk); start_new_batch = 1; @(negedge clk); start_new_batch = 0;
            c0 = cyc; seen = 0;
            valid_match = 1; @(negedge clk); valid_match = 0;
            k = 0; while (!tppe_done && k < 20000) begin @(negedge clk); k = k + 1; end
            if (k >= 20000) begin $display("TIMEOUT chunk %0d", n); $finish; end
            total_cycles = total_cycles + (cyc - c0);
            total_nm = total_nm + nm;
            if (nm > 0) begin
                for (t = 0; t < T; t = t + 1)
                    if (got[t] !== exp_v[t]) begin
                        errors = errors + 1;
                        if (errors < 5) $display("MISMATCH chunk %0d t%0d got %0d exp_v %0d", n, t, got[t], exp_v[t]);
                    end
            end
        end
        $display("LOAS_RESULT chunks=%0d matches=%0d cycles=%0d cycles_per_chunk=%0.1f cycles_per_match=%0.2f errors=%0d",
                 NCHUNK, total_nm, total_cycles, total_cycles * 1.0 / NCHUNK,
                 total_cycles * 1.0 / total_nm, errors);
        $finish;
    end
endmodule
