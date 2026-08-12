// mentha_array_ws_4x4.sv
// 4x4 Weight-Stationary Mentha Systolic Array.
// Robust 1D inter-PE wiring for 100% compatibility across SystemVerilog tools (Icarus Verilog, Verilator, Questa).

module mentha_array_ws_4x4 #(
    parameter int IDX_W    = 8,
    parameter int VAL_W    = 32,
    parameter int NUM_CBUF = 4,
    parameter int ROWS     = 4,
    parameter int COLS     = 4
) (
    input  logic clk,
    input  logic rst_n,

    // --- A* stationary load interface ---
    input  logic                    a_load_en,
    input  logic [$clog2(ROWS)-1:0] a_load_row,
    input  logic [$clog2(COLS)-1:0] a_load_col,
    input  logic [IDX_W-1:0]        a_load_idx,
    input  logic signed [VAL_W-1:0] a_load_val,

    // --- B* vertical edge inputs (top -> bottom) ---
    input  logic [COLS*IDX_W-1:0]   b_edge_idx_flat,
    input  logic [COLS*VAL_W-1:0]   b_edge_val_flat,

    // --- B* vertical edge outputs (exiting bottom) ---
    output logic [COLS*IDX_W-1:0]   b_out_idx_flat,
    output logic [COLS*VAL_W-1:0]   b_out_val_flat,

    // --- C* horizontal edge inputs (entering from West) ---
    input  logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_edge_a_idx_flat,
    input  logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_edge_b_idx_flat,
    input  logic signed [ROWS*NUM_CBUF*VAL_W-1:0] c_edge_val_flat,
    input  logic [ROWS*NUM_CBUF-1:0]             c_edge_valid_flat,

    // --- C* horizontal edge outputs (exiting to East) ---
    output logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_out_a_idx_flat,
    output logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_out_b_idx_flat,
    output logic signed [ROWS*NUM_CBUF*VAL_W-1:0] c_out_val_flat,
    output logic [ROWS*NUM_CBUF-1:0]             c_out_valid_flat,

    output logic [ROWS*COLS-1:0]                 overflow_flat
);

    // Vertical B* inter-PE wires: b_wire_idx[ (r)*(COLS) + c ]
    logic [IDX_W-1:0]        b_wire_idx [(ROWS+1)*COLS];
    logic signed [VAL_W-1:0] b_wire_val [(ROWS+1)*COLS];

    // Horizontal C* inter-PE wires: c_wire_a_idx[ (r)*(COLS+1) + c ]
    logic [NUM_CBUF*IDX_W-1:0]       c_wire_a_idx [ROWS*(COLS+1)];
    logic [NUM_CBUF*IDX_W-1:0]       c_wire_b_idx [ROWS*(COLS+1)];
    logic signed [NUM_CBUF*VAL_W-1:0] c_wire_val   [ROWS*(COLS+1)];
    logic [NUM_CBUF-1:0]             c_wire_valid [ROWS*(COLS+1)];

    genvar r, c;
    generate
        // Top edge B* connection
        for (c = 0; c < COLS; c++) begin : g_top_b
            assign b_wire_idx[0*COLS + c] = b_edge_idx_flat[c*IDX_W +: IDX_W];
            assign b_wire_val[0*COLS + c] = b_edge_val_flat[c*VAL_W +: VAL_W];
        end

        // West edge C* connection
        for (r = 0; r < ROWS; r++) begin : g_west_c
            assign c_wire_a_idx[r*(COLS+1) + 0] = c_edge_a_idx_flat[r*NUM_CBUF*IDX_W +: NUM_CBUF*IDX_W];
            assign c_wire_b_idx[r*(COLS+1) + 0] = c_edge_b_idx_flat[r*NUM_CBUF*IDX_W +: NUM_CBUF*IDX_W];
            assign c_wire_val[r*(COLS+1) + 0]   = c_edge_val_flat[r*NUM_CBUF*VAL_W +: NUM_CBUF*VAL_W];
            assign c_wire_valid[r*(COLS+1) + 0] = c_edge_valid_flat[r*NUM_CBUF +: NUM_CBUF];
        end

        // 2D Array of PEs
        for (r = 0; r < ROWS; r++) begin : g_row
            for (c = 0; c < COLS; c++) begin : g_col
                mentha_pe_ws #(
                    .IDX_W    (IDX_W),
                    .VAL_W    (VAL_W),
                    .NUM_CBUF (NUM_CBUF)
                ) u_pe (
                    .clk              (clk),
                    .rst_n            (rst_n),
                    .a_load_en        (a_load_en && (a_load_row == r) && (a_load_col == c)),
                    .a_load_idx       (a_load_idx),
                    .a_load_val       (a_load_val),
                    .b_in_idx         (b_wire_idx[r*COLS + c]),
                    .b_in_val         (b_wire_val[r*COLS + c]),
                    .b_out_idx        (b_wire_idx[(r+1)*COLS + c]),
                    .b_out_val        (b_wire_val[(r+1)*COLS + c]),
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
            assign b_out_idx_flat[c*IDX_W +: IDX_W] = b_wire_idx[ROWS*COLS + c];
            assign b_out_val_flat[c*VAL_W +: VAL_W] = b_wire_val[ROWS*COLS + c];
        end

        // East edge C* output connection
        for (r = 0; r < ROWS; r++) begin : g_east_c
            assign c_out_a_idx_flat[r*NUM_CBUF*IDX_W +: NUM_CBUF*IDX_W] = c_wire_a_idx[r*(COLS+1) + COLS];
            assign c_out_b_idx_flat[r*NUM_CBUF*IDX_W +: NUM_CBUF*IDX_W] = c_wire_b_idx[r*(COLS+1) + COLS];
            assign c_out_val_flat[r*NUM_CBUF*VAL_W +: NUM_CBUF*VAL_W]   = c_wire_val[r*(COLS+1) + COLS];
            assign c_out_valid_flat[r*NUM_CBUF +: NUM_CBUF]             = c_wire_valid[r*(COLS+1) + COLS];
        end
    endgenerate

endmodule