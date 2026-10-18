`timescale 1ns/1ps
// tppe_plus.v -- LoAS+ TPPE (loas_plus.py C1 + C2): prefix-free, 4-match inner join, direct T-lane accumulation.
//
// C1  No prefix-sum circuits. Both fibres carry a 7-bit base offset per 16-bit bitmask segment (weights: offline;
//     spikes: written by the output compressor). A match at position p has offset
//         base[p/16] + popcount(mask[p/16 segment] below p)
//     so the fast prefix-sum, the laggy prefix-sum, the pseudo-accumulator, FIFO-mp/FIFO-B and the correction
//     path of LoAS are gone: each lane adds its weight directly when the matched spike train arrives.
// C2  The AND result is split into 4 quarters of 32 bits, each with its own priority encoder, so up to 4 matches
//     retire per cycle (one per quarter). 4 fibre-A read ports (1-cycle latency, as in tb_loas), and per timestep
//     a 4-input gated adder into the accumulator. Weights are static, so the offline packer stores quarter q's
//     non-zeros in slots q*32.. of the 128-entry weight buffer: each lane's weight mux is 32:1, and the weight
//     base is a 5-bit offset inside the quarter (base_bq).
// Pipeline: S0 priority encode | S1 offsets | S2 weight mux + fibre-A read issued | S3 accumulate. LIF = lif_model.
module tppe_plus #(
    parameter W   = 128,
    parameter T   = 8,
    parameter WW  = 8,
    parameter ACC = 12,
    parameter NQ  = 4                    // quarters = matches per cycle
)(
    input  wire clk,
    input  wire rst,
    input  wire start_new_batch,         // latch the chunk (bitmasks + segment bases) and clear the accumulators
    output wire tppe_done,

    input  wire [W-1:0]        bitmask_a,
    input  wire [W-1:0]        bitmask_b,
    input  wire [8*7-1:0]      base_a,   // per 16-bit segment: # non-zeros before it (7 bits each)
    input  wire [8*5-1:0]      base_bq,  // per 16-bit segment: # non-zero weights before it inside its quarter
    input  wire [W*WW-1:0]     fibre_b_data_flat,

    output reg  [NQ*7-1:0]     fibre_a_addr,
    output reg  [NQ-1:0]       fibre_a_read_en,
    input  wire [NQ*T-1:0]     fibre_a_data,     // valid the cycle after read_en

    input  wire [ACC-1:0]      lif_threshold,
    output wire [T-1:0]        spike_out,
    output wire [ACC*T-1:0]    result_flat,
    output reg                 result_valid
);
    localparam QW = W / NQ;              // 32

    reg  [W-1:0] rem, bm_a, bm_b;
    reg  [8*7-1:0] ba;
    reg  [8*5-1:0] bb;
    reg  busy;

    // ---------------- S0: one priority encoder per quarter
    reg  [4:0]  pe_pos [0:NQ-1];
    reg  [NQ-1:0] pe_v;
    reg  [W-1:0] clr;
    integer q0, i0;
    always @* begin
        clr = 0;
        for (q0 = 0; q0 < NQ; q0 = q0 + 1) begin
            pe_v[q0] = 0; pe_pos[q0] = 0;
            for (i0 = QW - 1; i0 >= 0; i0 = i0 - 1)
                if (rem[q0*QW + i0]) begin pe_v[q0] = 1; pe_pos[q0] = i0[4:0]; end
            if (pe_v[q0]) clr[q0*QW + pe_pos[q0]] = 1'b1;
        end
    end

    integer q1, q2, q3, q4, t4;
    reg [6:0]    s1_pos [0:NQ-1];
    reg [NQ-1:0] s1_v;
    reg [NQ-1:0] s2_v, s3_v;
    // done when nothing is left to find and the pipeline is empty
    wire drained = busy & ~|rem & ~|s1_v & ~|s2_v & ~|s3_v & ~start_new_batch;
    always @(posedge clk) begin
        if (rst) begin
            busy <= 0; rem <= 0; s1_v <= 0;
        end else if (start_new_batch) begin
            rem  <= bitmask_a & bitmask_b;
            bm_a <= bitmask_a; bm_b <= bitmask_b; ba <= base_a; bb <= base_bq;
            busy <= 1; s1_v <= 0;
        end else begin
            rem  <= rem & ~clr;
            s1_v <= pe_v;
            for (q1 = 0; q1 < NQ; q1 = q1 + 1) s1_pos[q1] <= q1 * QW + pe_pos[q1];
            if (drained) busy <= 0;
        end
    end

    // ---------------- S1: segment offsets (base + popcount16), weight mux, fibre-A read
    function [4:0] below(input [6:0] p, input [W-1:0] m);       // popcount16 of the segment below p
        reg [15:0] s; integer k;
        begin
            s = m[p[6:4]*16 +: 16] & ((16'h1 << p[3:0]) - 16'h1);
            below = 0;
            for (k = 0; k < 16; k = k + 1) below = below + s[k];
        end
    endfunction
    function [6:0] a_off(input [6:0] p, input [W-1:0] m, input [8*7-1:0] base);
        a_off = base[p[6:4]*7 +: 7] + below(p, m);
    endfunction
    function [4:0] b_loc(input [6:0] p, input [W-1:0] m, input [8*5-1:0] base);   // slot inside the quarter
        b_loc = base[p[6:4]*5 +: 5] + below(p, m);
    endfunction

    reg [WW-1:0] s2_w [0:NQ-1];
    always @(posedge clk) begin
        if (rst | start_new_batch) begin
            s2_v <= 0; fibre_a_read_en <= 0;
        end else begin
            s2_v <= s1_v;
            fibre_a_read_en <= s1_v;
            for (q2 = 0; q2 < NQ; q2 = q2 + 1) begin
                s2_w[q2] <= fibre_b_data_flat[(q2*QW + b_loc(s1_pos[q2], bm_b, bb))*WW +: WW];   // 32:1 per lane
                fibre_a_addr[q2*7 +: 7] <= a_off(s1_pos[q2], bm_a, ba);
            end
        end
    end

    // ---------------- S3: fibre-A data arrives (1-cycle memory latency); T lanes, 4-input gated add
    reg [WW-1:0] s3_w [0:NQ-1];
    always @(posedge clk) begin
        if (rst | start_new_batch) s3_v <= 0;
        else begin
            s3_v <= s2_v;
            for (q3 = 0; q3 < NQ; q3 = q3 + 1) s3_w[q3] <= s2_w[q3];
        end
    end
    reg [ACC-1:0] acc [0:T-1];
    reg [ACC-1:0] sum;
    always @(posedge clk) begin
        if (rst | start_new_batch) begin
            for (t4 = 0; t4 < T; t4 = t4 + 1) acc[t4] <= 0;
        end else if (|s3_v) begin
            for (t4 = 0; t4 < T; t4 = t4 + 1) begin
                sum = acc[t4];
                for (q4 = 0; q4 < NQ; q4 = q4 + 1)
                    if (s3_v[q4] & fibre_a_data[q4*T + t4]) sum = sum + s3_w[q4];
                acc[t4] <= sum;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) result_valid <= 0;
        else result_valid <= drained;
    end
    genvar g;
    generate for (g = 0; g < T; g = g + 1) begin : res
        assign result_flat[g*ACC +: ACC] = acc[g];
    end endgenerate

    lif_model #(.T(T), .Q(ACC)) lif_inst (
        .clk(clk), .rst(rst | start_new_batch), .start(result_valid), .result_val(result_valid),
        .input_0(acc[0]), .input_1(acc[1]), .input_2(acc[2]), .input_3(acc[3]),
        .input_4(acc[4]), .input_5(acc[5]), .input_6(acc[6]), .input_7(acc[7]),
        .threshold(lif_threshold), .spike_out(spike_out), .lif_done(tppe_done));
endmodule
