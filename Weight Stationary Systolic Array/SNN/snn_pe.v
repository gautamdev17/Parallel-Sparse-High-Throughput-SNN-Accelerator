`timescale 1ns/1ps
// =============================================================================
// snn_pe : weight-stationary SNN processing element, minimum-width version
//   - one INT8 stationary weight
//   - spikes   : T-bit train, in from ABOVE, out to BELOW (1 cycle)
//   - psums    : T parallel conditional accumulators, in LEFT, out RIGHT (1 cycle)
//                psum_out[t] <= psum_in[t] + (s_in[t] ? w : 0)      (no multiplier)
//
//   Register widths are only what column c can ever need:
//     POW = DW + clog2(c+1)  bits per accumulator (sum of c+1 INT8 values)
//
//   FIRST (column 0): psum_in is always 0, so psum_out[t] = s[t] ? w : 0.
//     Instead of T*DW psum flops, only the T spike bits are registered (that
//     register is also the spike pass-down register) and the AND with w is
//     done after it. Same values, same timing, T*DW - T fewer flops.
//
//   PASS_S = 0 (bottom row): spike pass-down register is not built.
//
//   Bus layout (wires only, no hardware): each timestep has a PWM-bit slot,
//     psum[t*PWM +: PWM]; only the low PIW/POW bits are real, rest is sign-ext.
//
//   Pipeline regs (spikes, psums) have no reset: they flush themselves and the
//   valid pipeline in the array ignores them until real data arrives.
// =============================================================================
module snn_pe #(parameter DW = 8, T = 8,
                PWM = 10,          // slot width on the psum bus (array's widest)
                PIW = 8,           // real width of incoming psums
                POW = 9,           // real width of outgoing psums (accumulator regs)
                FIRST  = 0,        // 1 = column 0
                PASS_S = 1)        // 0 = bottom row, no spike pass-down
(
    input  wire                 clk, rst_n,
    input  wire                 load_w,
    input  wire signed [DW-1:0] w_in,
    input  wire [T-1:0]         s_in,
    input  wire [T*PWM-1:0]     psum_in,
    output wire [T-1:0]         s_out,
    output wire [T*PWM-1:0]     psum_out
);
    reg signed [DW-1:0] w;                                   // the STATIONARY weight
    always @(posedge clk)
        if (!rst_n)      w <= 0;
        else if (load_w) w <= w_in;

    genvar t;
    generate
        if (FIRST) begin : g_first
            reg [T-1:0] s_q;                                 // T flops total
            always @(posedge clk) s_q <= s_in;
            assign s_out = s_q;
            wire signed [PWM-1:0] w_x = w;
            for (t = 0; t < T; t = t + 1) begin : g_t
                assign psum_out[t*PWM +: PWM] = s_q[t] ? w_x : {PWM{1'b0}};
            end
        end else begin : g_acc
            if (PASS_S) begin : g_s
                reg [T-1:0] s_q;
                always @(posedge clk) s_q <= s_in;
                assign s_out = s_q;
            end else begin : g_ns
                assign s_out = {T{1'b0}};
            end

            wire signed [POW-1:0] w_x = w;
            for (t = 0; t < T; t = t + 1) begin : g_t       // T accumulators, POW bits each
                wire signed [POW-1:0] p_x = $signed(psum_in[t*PWM +: PIW]);
                reg  signed [POW-1:0] acc;
                always @(posedge clk) acc <= s_in[t] ? p_x + w_x : p_x;
                wire signed [PWM-1:0] acc_x = acc;
                assign psum_out[t*PWM +: PWM] = acc_x;
            end
        end
    endgenerate
endmodule