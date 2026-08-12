// mentha_array_ws_4x4.sv
// 4x4 Weight-Stationary Mentha SNN Systolic Array.
// Configured with INT8 signed weights (A*), 8-bit timestep spikes (B*), and multi-timestep INT16 signed accumulators (C*).

module mentha_array_ws_4x4 #(
    parameter int IDX_W     = 8,     // 8-bit index
    parameter int A_VAL_W   = 8,     // 8-bit signed INT8 stationary weight A*
    parameter int TIMESTEPS = 8,     // 8 timesteps per spike activation vector B*
    parameter int C_VAL_W   = 16,    // 16-bit signed INT16 stream accumulator C* per timestep
    parameter int NUM_CBUF  = 4,     // 4 in-flight slots per row
    parameter int ROWS      = 4,
    parameter int COLS      = 4
) (
    input  logic clk,
    input  logic rst_n,

    // --- A* stationary load interface (INT8 signed) ---
    input  logic                    a_load_en,
    input  logic [$clog2(ROWS)-1:0] a_load_row,
    input  logic [$clog2(COLS)-1:0] a_load_col,
    input  logic [IDX_W-1:0]        a_load_idx,
    input  logic signed [A_VAL_W-1:0] a_load_val,

    // --- B* vertical edge inputs (top -> bottom) (8-bit timestep spikes) ---
    input  logic [COLS*IDX_W-1:0]     b_edge_idx_flat,
    input  logic [COLS*TIMESTEPS-1:0] b_edge_spikes_flat,

    // --- B* vertical edge outputs (exiting bottom) ---
    output logic [COLS*IDX_W-1:0]     b_out_idx_flat,
    output logic [COLS*TIMESTEPS-1:0] b_out_spikes_flat,

    // --- C* horizontal edge inputs (entering from West) (INT16 accumulators x 8 timesteps) ---
    input  logic [ROWS*NUM_CBUF*IDX_W-1:0]               c_edge_a_idx_flat,
    input  logic [ROWS*NUM_CBUF*IDX_W-1:0]               c_edge_b_idx_flat,
    input  logic signed [ROWS*NUM_CBUF*TIMESTEPS*C_VAL_W-1:0] c_edge_val_flat,
    input  logic [ROWS*NUM_CBUF-1:0]                     c_edge_valid_flat,

    // --- C* horizontal edge outputs (exiting to East) ---
    output logic [ROWS*NUM_CBUF*IDX_W-1:0]               c_out_a_idx_flat,
    output logic [ROWS*NUM_CBUF*IDX_W-1:0]               c_out_b_idx_flat,
    output logic signed [ROWS*NUM_CBUF*TIMESTEPS*C_VAL_W-1:0] c_out_val_flat,
    output logic [ROWS*NUM_CBUF-1:0]                     c_out_valid_flat,

    output logic [ROWS*COLS-1:0]                         overflow_flat
);

    // Vertical B* inter-PE wires: b_wire_idx[ (r)*(COLS) + c ]
    logic [IDX_W-1:0]     b_wire_idx    [(ROWS+1)*COLS];
    logic [TIMESTEPS-1:0] b_wire_spikes [(ROWS+1)*COLS];

    // Horizontal C* inter-PE wires: c_wire_a_idx[ (r)*(COLS+1) + c ]
    logic [NUM_CBUF*IDX_W-1:0]               c_wire_a_idx [ROWS*(COLS+1)];
    logic [NUM_CBUF*IDX_W-1:0]               c_wire_b_idx [ROWS*(COLS+1)];
    logic signed [NUM_CBUF*TIMESTEPS*C_VAL_W-1:0] c_wire_val   [ROWS*(COLS+1)];
    logic [NUM_CBUF-1:0]                     c_wire_valid [ROWS*(COLS+1)];

    genvar r, c;
    generate
        // Top edge B* connection
        for (c = 0; c < COLS; c++) begin : g_top_b
            assign b_wire_idx[0*COLS + c]    = b_edge_idx_flat[c*IDX_W +: IDX_W];
            assign b_wire_spikes[0*COLS + c] = b_edge_spikes_flat[c*TIMESTEPS +: TIMESTEPS];
        end

        // West edge C* connection
        for (r = 0; r < ROWS; r++) begin : g_west_c
            assign c_wire_a_idx[r*(COLS+1) + 0] = c_edge_a_idx_flat[r*NUM_CBUF*IDX_W +: NUM_CBUF*IDX_W];
            assign c_wire_b_idx[r*(COLS+1) + 0] = c_edge_b_idx_flat[r*NUM_CBUF*IDX_W +: NUM_CBUF*IDX_W];
            assign c_wire_val[r*(COLS+1) + 0]   = c_edge_val_flat[r*NUM_CBUF*TIMESTEPS*C_VAL_W +: NUM_CBUF*TIMESTEPS*C_VAL_W];
            assign c_wire_valid[r*(COLS+1) + 0] = c_edge_valid_flat[r*NUM_CBUF +: NUM_CBUF];
        end

        // 2D Array of PEs
        for (r = 0; r < ROWS; r++) begin : g_row
            for (c = 0; c < COLS; c++) begin : g_col
                mentha_pe_ws #(
                    .IDX_W     (IDX_W),
                    .A_VAL_W   (A_VAL_W),
                    .TIMESTEPS (TIMESTEPS),
                    .C_VAL_W   (C_VAL_W),
                    .NUM_CBUF  (NUM_CBUF)
                ) u_pe (
                    .clk              (clk),
                    .rst_n            (rst_n),
                    .a_load_en        (a_load_en && (a_load_row == r) && (a_load_col == c)),
                    .a_load_idx       (a_load_idx),
                    .a_load_val       (a_load_val),
                    .b_in_idx         (b_wire_idx[r*COLS + c]),
                    .b_in_spikes      (b_wire_spikes[r*COLS + c]),
                    .b_out_idx        (b_wire_idx[(r+1)*COLS + c]),
                    .b_out_spikes     (b_wire_spikes[(r+1)*COLS + c]),
                    .c_in_a_idx_flat  (c_wire_a_idx[r*(COLS+1) + c]),
                    .c_in_b_idx_flat  (c_wire_b_idx[r*(COLS+1) + c]),
                    .c_in_val_flat    (c_wire_val[r*(COLS+1) + c]),
                    .c_in_valid_flat  (c_wire_valid[r*(COLS+1) + c]),
                    .c_out_a_idx_flat (c_wire_a_idx[r*(COLS+1) + c + 1]),
                    .c_out_b_idx_flat (c_wire_b_idx[r*(COLS+1) + c + 1]),
                    .c_out_val_flat   (c_wire_val[r*(COLS+1) + c + 1]),
                    .c_out_valid_flat (c_wire_valid[r*(COLS+1) + c + 1]),
                    .overflow         (overflow_flat[r*COLS + c])
                );
            end
        end

        // Bottom edge B* output connection
        for (c = 0; c < COLS; c++) begin : g_bottom_b
            assign b_out_idx_flat[c*IDX_W +: IDX_W]       = b_wire_idx[ROWS*COLS + c];
            assign b_out_spikes_flat[c*TIMESTEPS +: TIMESTEPS] = b_wire_spikes[ROWS*COLS + c];
        end

        // East edge C* output connection
        for (r = 0; r < ROWS; r++) begin : g_east_c
            assign c_out_a_idx_flat[r*NUM_CBUF*IDX_W +: NUM_CBUF*IDX_W] = c_wire_a_idx[r*(COLS+1) + COLS];
            assign c_out_b_idx_flat[r*NUM_CBUF*IDX_W +: NUM_CBUF*IDX_W] = c_wire_b_idx[r*(COLS+1) + COLS];
            assign c_out_val_flat[r*NUM_CBUF*TIMESTEPS*C_VAL_W +: NUM_CBUF*TIMESTEPS*C_VAL_W]   = c_wire_val[r*(COLS+1) + COLS];
            assign c_out_valid_flat[r*NUM_CBUF +: NUM_CBUF]             = c_wire_valid[r*(COLS+1) + COLS];
        end
    endgenerate

endmodule