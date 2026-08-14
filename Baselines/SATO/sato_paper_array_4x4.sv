// sato_paper_array_4x4.sv
// 4x4 PE Array for DAC 2022 Paper: "SATO: Spiking Neural Network Acceleration"
// Ref: Fangxin Liu et al. (SJTU) - DAC 2022
//
// Array Concept:
// - PEs process potential increments (\Delta V_mem) for T=8 time steps in parallel.
// - Outputs from PEs are routed directly to the Binary Search-Adder Tree.

module sato_paper_array_4x4 #(
    parameter int WEIGHT_W  = 8,
    parameter int ACC_W     = 16,
    parameter int TIMESTEPS = 8,
    parameter int PES       = 8       // PEs processing parallel time steps
) (
    input  logic                     clk,
    input  logic                     rst_n,

    // --- Control Signals ---
    input  logic                     clear_acc,

    // --- Dispatched Sparse Inputs for 8 Time Steps ---
    input  logic [PES-1:0]           spike_valid_vec,
    input  logic signed [WEIGHT_W-1:0] weight_vec [PES],

    // --- Potential Increments for 8 Time Steps to Adder Tree ---
    output logic signed [ACC_W-1:0]  v_inc_array [PES]
);

    genvar p;
    generate
        for (p = 0; p < PES; p++) begin : g_pe
            sato_paper_pe #(
                .WEIGHT_W (WEIGHT_W),
                .ACC_W    (ACC_W)
            ) u_pe (
                .clk         (clk),
                .rst_n       (rst_n),
                .clear_acc   (clear_acc),
                .spike_valid (spike_valid_vec[p]),
                .weight_in   (weight_vec[p]),
                .v_inc_out   (v_inc_array[p])
            );
        end
    endgenerate

endmodule
