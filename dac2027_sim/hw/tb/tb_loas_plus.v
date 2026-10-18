// tb_loas_plus.v -- drives ONE LoAS+ TPPE (rtl/loas_plus, T=8, 8-bit weights) through NCHUNK 128-element chunks.
// Same workload and structure as tb_loas.v (bitmask_a density 0.261, bitmask_b dense, weights 1..63, spike trains
// with bit probability 0.3 and at least one spike), so the two power numbers are comparable. The segment bases
// (# non-zeros before each 16-bit segment) are computed here, as the offline weight packer / output compressor would;
// the weight non-zeros are laid out quarter-aligned (quarter q's non-zeros from slot q*32), as the packer would.
// Checks every result against a behavioural reference (mod 2^12), counts cycles per chunk, dumps the VCD window.
`timescale 1ns/1ps
module tb_loas_plus;
    localparam W = 128, T = 8, WW = 8, NQ = 4, NCHUNK = `NCHUNK;
    reg clk = 0, rst = 1;
    always #0.625 clk = ~clk;                       // 800 MHz

    reg start_new_batch = 0;
    reg [W-1:0] bitmask_a = 0, bitmask_b = 0;
    reg [8*7-1:0] base_a = 0;
    reg [8*5-1:0] base_bq = 0;
    reg [W*WW-1:0] fibre_b = 0;      // quarter-aligned weight buffer
    reg [WW-1:0] wdense [0:W-1];
    reg [NQ*T-1:0] fibre_a_data = 0;
    wire [NQ*7-1:0] fibre_a_addr;
    wire [NQ-1:0] fibre_a_read_en;
    wire tppe_done, result_valid;
    wire [T-1:0] spike_out;
    wire [12*T-1:0] res;

    tppe_plus dut(.clk(clk), .rst(rst), .start_new_batch(start_new_batch), .tppe_done(tppe_done),
                  .bitmask_a(bitmask_a), .bitmask_b(bitmask_b), .base_a(base_a), .base_bq(base_bq),
                  .fibre_b_data_flat(fibre_b), .fibre_a_addr(fibre_a_addr), .fibre_a_read_en(fibre_a_read_en),
                  .fibre_a_data(fibre_a_data), .lif_threshold(12'd300), .spike_out(spike_out),
                  .result_flat(res), .result_valid(result_valid));

    reg [T-1:0] fibre_a_mem [0:W-1];
    reg [11:0] exp_v [0:T-1];
    reg [11:0] got [0:T-1];
    integer i, t, n, k, q, nb, na, nm, c0, total_cycles, total_nm, errors;
    integer cyc = 0;
    always @(posedge clk) cyc <= cyc + 1;

    // fibre-A memory: 4 read ports, one-cycle read latency
    always @(posedge clk)
        for (q = 0; q < NQ; q = q + 1)
            if (fibre_a_read_en[q]) fibre_a_data[q*T +: T] <= fibre_a_mem[fibre_a_addr[q*7 +: 7]];
    always @(posedge clk) if (result_valid)
        for (t = 0; t < T; t = t + 1) got[t] <= res[t*12 +: 12];

    initial begin
        if ($test$plusargs("vcd")) $dumpfile(`VCDFILE);
        errors = 0; total_cycles = 0; total_nm = 0;
        i = `SEED; i = $urandom(i);
        repeat (4) @(posedge clk);
        rst = 0;
        for (n = 0; n < NCHUNK; n = n + 1) begin
            if (n == 2 && $test$plusargs("vcd")) $dumpvars(0, tb_loas_plus.dut);   // skip warm-up chunks
`ifdef WDENS
            for (k = 0; k < W; k = k + 1) bitmask_b[k] = (($urandom % 1000) < `WDENS);   // sparse weights (test)
`else
            bitmask_b = {W{1'b1}};
`endif
            nb = 0; na = 0; nm = 0;
            for (t = 0; t < T; t = t + 1) exp_v[t] = 0;
            for (k = 0; k < W; k = k + 1) begin
                wdense[k] = 1 + ($urandom % 63);
                bitmask_a[k] = (($urandom % 1000) < 261);
            end
            for (k = 0; k < W; k = k + 1) begin
                if (k % 32 == 0) nb = 0;                                  // weights: count inside the quarter
                if (k % 16 == 0) begin base_a[(k/16)*7 +: 7] = na; base_bq[(k/16)*5 +: 5] = nb; end
                if (bitmask_b[k]) fibre_b[((k/32)*32 + nb)*WW +: WW] = wdense[k];
                if (bitmask_a[k]) begin
                    fibre_a_mem[na] = 0;
                    while (fibre_a_mem[na] == 0)
                        for (t = 0; t < T; t = t + 1) fibre_a_mem[na][t] = (($urandom % 100) < 30);
                    for (t = 0; t < T; t = t + 1)
                        if (fibre_a_mem[na][t] && bitmask_b[k]) exp_v[t] = exp_v[t] + wdense[k];
                    na = na + 1;
                    if (bitmask_b[k]) nm = nm + 1;
                end
                if (bitmask_b[k]) nb = nb + 1;
            end
            @(negedge clk); start_new_batch = 1; @(negedge clk); start_new_batch = 0;
            c0 = cyc;
            k = 0; while (!tppe_done && k < 20000) begin @(negedge clk); k = k + 1; end
            if (k >= 20000) begin $display("TIMEOUT chunk %0d", n); $finish; end
            total_cycles = total_cycles + (cyc - c0);
            total_nm = total_nm + nm;
            for (t = 0; t < T; t = t + 1)
                if (got[t] !== exp_v[t]) begin
                    errors = errors + 1;
                    if (errors < 5) $display("MISMATCH chunk %0d t%0d got %0d exp_v %0d", n, t, got[t], exp_v[t]);
                end
        end
        $display("LOASPLUS_RESULT chunks=%0d matches=%0d cycles=%0d cycles_per_chunk=%0.1f cycles_per_match=%0.2f errors=%0d",
                 NCHUNK, total_nm, total_cycles, total_cycles * 1.0 / NCHUNK,
                 total_cycles * 1.0 / total_nm, errors);
        $finish;
    end
endmodule
