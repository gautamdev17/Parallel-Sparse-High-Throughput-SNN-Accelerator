// ptb_paper_pe.sv
// Processing Element (PE) for MICRO 2021 Paper: "Parallel Time Batching (PTB)"
// Ref: Jeong-Jun Lee, Wenrui Zhang, Peng Li (UCSB) - MICRO 2021
//
// Key Concepts:
// - Neuron-Stationary Dataflow: PE stores membrane potentials v_mem for a single neuron over TW time points.
// - Time Window (TW): Parallel processing across TW time points (default TW=8).
// - Input Spikes (spike_in) and Weights (weight_in) flow horizontally and vertically across systolic array.
// - Includes local LIF membrane integration, leaky subtraction, threshold comparator (CMP), and spike reset.

module ptb_paper_pe #(
    parameter int WEIGHT_W = 8,      // INT8 signed weight precision
    parameter int VMEM_W   = 16,     // 16-bit membrane potential precision
    parameter int TW       = 8       // Time Window size (number of time steps processed in parallel)
) (
    input  logic                     clk,
    input  logic                     rst_n,

    // --- Control Signals ---
    input  logic                     clear_vmem,     // Clear membrane potentials for a new TW batch
    input  logic signed [VMEM_W-1:0] v_th,           // Spiking threshold (V_th)
    input  logic signed [VMEM_W-1:0] v_leak,         // Leaky decay parameter (V_leak)

    // --- Systolic Dataflow Inputs ---
    input  logic signed [WEIGHT_W-1:0] weight_in,     // Multi-bit weight W_ji (passed horizontally)
    input  logic [TW-1:0]             spike_in,      // Binary spike vector across TW (passed vertically)

    // --- Systolic Dataflow Pass-Through Outputs ---
    output logic signed [WEIGHT_W-1:0] weight_out,    // Pass weight to right PE neighbor
    output logic [TW-1:0]             spike_out_pass, // Pass spike vector to bottom PE neighbor

    // --- SNN Spike Output ---
    output logic [TW-1:0]             spike_out_fire  // Emitted output spikes across TW
);

    // Local Scratchpad Registers: Stores Membrane Potential (V_mem) for each time point in TW
    logic signed [VMEM_W-1:0] v_mem_q [TW];

    // Systolic Register Propagation (1 cycle latency per hop)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            weight_out     <= '0;
            spike_out_pass <= '0;
        end else begin
            weight_out     <= weight_in;
            spike_out_pass <= spike_in;
        end
    end

    // Step 1, 2 & 3: Synaptic Accumulation, Leaky Potential Update, and Spike Generation across TW
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int t = 0; t < TW; t++) begin
                v_mem_q[t]         <= '0;
                spike_out_fire[t]  <= 1'b0;
            end
        end else if (clear_vmem) begin
            for (int t = 0; t < TW; t++) begin
                v_mem_q[t]         <= '0;
                spike_out_fire[t]  <= 1'b0;
            end
        end else begin
            for (int t = 0; t < TW; t++) begin
                logic signed [VMEM_W-1:0] v_inc;
                logic signed [VMEM_W-1:0] v_next;

                // Step 1: Synaptic Weight Accumulation (Conditional on binary input spike)
                v_inc = spike_in[t] ? $signed(weight_in) : '0;

                // Step 2: Membrane Potential Update (V_mem = V_mem + Weight - V_leak)
                v_next = v_mem_q[t] + v_inc - v_leak;

                // Step 3: Threshold Comparator (CMP) & Spike Generation / Reset
                if (v_next >= v_th) begin
                    spike_out_fire[t] <= 1'b1;  // Emit spike
                    v_mem_q[t]        <= '0;   // Hard reset membrane potential
                end else begin
                    spike_out_fire[t] <= 1'b0;  // Silent
                    v_mem_q[t]        <= v_next;
                end
            end
        end
    end

endmodule
