// ptb_paper_array_4x4.sv
// 4x4 Systolic Array for MICRO 2021 Paper: "Parallel Time Batching (PTB)"
// Ref: Jeong-Jun Lee, Wenrui Zhang, Peng Li (UCSB) - MICRO 2021
//
// Dataflow Topology:
// - Weights (weight_in) flow horizontally (West -> East).
// - Input Spikes (spike_in) flow vertically (North -> South).
// - Each PE represents 1 post-synaptic neuron computing over a Time Window (TW=8).

module ptb_paper_array_4x4 #(
    parameter int WEIGHT_W = 8,
    parameter int VMEM_W   = 16,
    parameter int TW       = 8,
    parameter int ROWS     = 4,
    parameter int COLS     = 4
) (
    input  logic                     clk,
    input  logic                     rst_n,

    // --- Global Controls ---
    input  logic                     clear_vmem,
    input  logic signed [VMEM_W-1:0] v_th,
    input  logic signed [VMEM_W-1:0] v_leak,

    // --- West Edge Weight Inputs (4 rows x WEIGHT_W) ---
    input  logic signed [ROWS*WEIGHT_W-1:0] weight_west_flat,

    // --- North Edge Spike Inputs (4 cols x TW bits) ---
    input  logic [COLS*TW-1:0]              spike_north_flat,

    // --- Output Spikes Fired by 4x4 PEs ---
    output logic [ROWS*COLS*TW-1:0]         spike_out_array_flat
);

    // Interconnect Wires
    logic signed [WEIGHT_W-1:0] w_wire [ROWS][COLS+1];
    logic [TW-1:0]             s_wire [ROWS+1][COLS];

    genvar r, c;
    generate
        // Connect West Edge Weight Inputs
        for (r = 0; r < ROWS; r++) begin : g_west_w
            assign w_wire[r][0] = weight_west_flat[r*WEIGHT_W +: WEIGHT_W];
        end

        // Connect North Edge Spike Inputs
        for (c = 0; c < COLS; c++) begin : g_north_s
            assign s_wire[0][c] = spike_north_flat[c*TW +: TW];
        end

        // Instantiate 2D PE Array (4x4)
        for (r = 0; r < ROWS; r++) begin : g_row
            for (c = 0; c < COLS; c++) begin : g_col
                ptb_paper_pe #(
                    .WEIGHT_W (WEIGHT_W),
                    .VMEM_W   (VMEM_W),
                    .TW       (TW)
                ) u_pe (
                    .clk            (clk),
                    .rst_n          (rst_n),
                    .clear_vmem     (clear_vmem),
                    .v_th           (v_th),
                    .v_leak         (v_leak),
                    .weight_in      (w_wire[r][c]),
                    .spike_in       (s_wire[r][c]),
                    .weight_out     (w_wire[r][c+1]),
                    .spike_out_pass (s_wire[r+1][c]),
                    .spike_out_fire (spike_out_array_flat[(r*COLS + c)*TW +: TW])
                );
            end
        end
    endgenerate

endmodule
