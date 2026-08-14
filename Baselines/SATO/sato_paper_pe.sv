// sato_paper_pe.sv
// Processing Element (PE) for DAC 2022 Paper: "SATO: Spiking Neural Network Acceleration"
// Ref: Fangxin Liu, Wenbo Zhao, Zhezhi He, Li Jiang et al. (SJTU) - DAC 2022
//
// Key Concepts:
// - Temporal-Parallel Dataflow: Decouples chronological dependence of spiking neurons.
// - Simplified PE: Removes comparator, membrane potential registers, and reset logic from PE core.
// - Each PE computes membrane potential increments (\Delta V_mem) for a given time step in parallel.
// - Partial sum results are sent to an external Binary Search-Adder Tree.

module sato_paper_pe #(
    parameter int WEIGHT_W = 8,      // 8-bit INT8 signed weight precision
    parameter int ACC_W    = 16      // 16-bit partial sum increment precision (\Delta V_mem)
) (
    input  logic                     clk,
    input  logic                     rst_n,

    // --- Control Signals ---
    input  logic                     clear_acc,     // Clears accumulator for new workload batch

    // --- Sparse Dispatch Inputs (from Bucket-Sort Dispatcher) ---
    input  logic                     spike_valid,   // Active non-zero spike indicator
    input  logic signed [WEIGHT_W-1:0] weight_in,    // Incoming weight corresponding to active spike

    // --- Accumulated Output to Binary Search-Adder Tree ---
    output logic signed [ACC_W-1:0]  v_inc_out      // Calculated potential increment for assigned time step
);

    // Non-Zero Element Register & Partial Sum Accumulator
    logic signed [ACC_W-1:0] acc_q;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            acc_q <= '0;
        end else if (clear_acc) begin
            acc_q <= '0;
        end else if (spike_valid) begin
            // Accumulate weight into time step potential increment: \Delta V_mem = \Delta V_mem + Weight
            acc_q <= acc_q + $signed(weight_in);
        end
    end

    // Direct output to external Binary Search-Adder Tree
    assign v_inc_out = acc_q;

endmodule
