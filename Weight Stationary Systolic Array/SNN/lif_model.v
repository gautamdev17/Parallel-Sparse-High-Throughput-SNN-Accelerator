`timescale 1ns / 1ps

`ifndef __LIF_MODEL_8_V__
`define __LIF_MODEL_8_V__

/*
 * Module Name: lif_model
 * Version:     1.0
 *
 * Description:
 * Leaky Integrate-and-Fire (LIF) neuron block. Consumes a vector of signed
 * inputs across T timesteps and computes the membrane potential and spike
 * generation in parallel.
 *
 * The membrane potential is accumulated across timesteps. Whenever a spike is
 * generated, the threshold is subtracted from the membrane potential and the
 * remaining residual carries into the next timestep. (Soft Reset)
 *
 * Parameters:
 * T : Number of timesteps / output spikes (default: 8)
 * Q : Bit width of each input, accumulated potential, and threshold (default: 16)
 *
 * Notes:
 * - result_val is the launch condition.
 * - Computation is purely combinational; outputs are registered on the clock edge.
 * - inputs[i] corresponds to timestep i.
 */

module lif_model #(
    parameter int T = 8,
    parameter int Q = 16
)(
    input  wire                 clk,
    input  wire                 rst,
    input  wire                 result_val,

    input  wire signed [Q-1:0]  inputs [0:T-1],
    input  wire signed [Q-1:0]  threshold,

    output reg  [T-1:0]         spike_out,
    output reg                  lif_done
);

reg signed [Q-1:0] wire_membrane [0:T-1];
reg        [T-1:0] wire_spike_seq;

integer i;

always @(*) begin
    for (i = 0; i < T; i = i + 1) begin
        wire_membrane[i]   = '0;
        wire_spike_seq[i]  = 1'b0;
    end

    if (result_val) begin
        wire_membrane[0]  = inputs[0];
        wire_spike_seq[0] = (wire_membrane[0] > threshold);

        for (i = 1; i < T; i = i + 1) begin
            if (wire_spike_seq[i-1])
                wire_membrane[i] = wire_membrane[i-1] - threshold + inputs[i];
            else
                wire_membrane[i] = wire_membrane[i-1] + inputs[i];

            wire_spike_seq[i] = (wire_membrane[i] > threshold);
        end
    end
end

always @(posedge clk or posedge rst) begin
    if (rst) begin
        spike_out <= '0;
        lif_done  <= 1'b0;
    end
    else begin
        lif_done <= 1'b0;

        if (result_val) begin
            spike_out <= wire_spike_seq;
            lif_done  <= 1'b1;
        end
    end
end

endmodule

`endif // __LIF_MODEL_8_V__