// mentha_pe_ws.sv
// Weight-Stationary (WS) Processing Element for Mentha (packed SpGEMM/SpMM).
//
// Dataflow (Paper Fig. 5a / Section 5.2):
//   - A* is stationary in PE: stores (a_idx, a_val) with INT8 signed weights.
//   - B* flows vertically (top -> bottom): (b_idx, b_val) with INT8 signed activations.
//   - C* flows horizontally (west -> east) as a stream of NUM_CBUF slots,
//     where each slot carries (c_a_idx, c_b_idx, c_val, c_valid) with INT32 signed accumulators.
//
// Compute Logic per Cycle:
//   - If both a_idx and b_in_idx are non-zero and match (a_idx_q == b_in_idx):
//     1. Compute 16-bit signed product = a_val (8-bit signed) * b_in_val (8-bit signed).
//     2. Match incoming C* stream slots for (c_a_idx == a_idx) && (c_b_idx == b_in_idx).
//     3. If match found: accumulate product into 32-bit signed C* stream slot.
//     4. Else if free slot found: allocate free C* slot with (a_idx, b_in_idx, product).
//     5. Else: trigger overflow.
//   - B* is registered and passed to the bottom PE.
//   - Updated C* stream is registered and passed to the right PE.

module mentha_pe_ws #(
    parameter int IDX_W    = 8,     // Sparse index width (8-bit)
    parameter int A_VAL_W  = 8,     // Stationary A* INT8 signed weight width
    parameter int B_VAL_W  = 8,     // Streaming B* INT8 signed activation width
    parameter int C_VAL_W  = 32,    // In-flight C* INT32 signed accumulator width
    parameter int NUM_CBUF = 4      // In-flight C* stream slot count per row
) (
    input  logic clk,
    input  logic rst_n,

    // --- A* stationary load interface (INT8 signed) ---
    input  logic                        a_load_en,
    input  logic [IDX_W-1:0]            a_load_idx,
    input  logic signed [A_VAL_W-1:0]   a_load_val,

    // --- B* flowing vertically (top -> bottom) (INT8 signed) ---
    input  logic [IDX_W-1:0]            b_in_idx,
    input  logic signed [B_VAL_W-1:0]   b_in_val,
    output logic [IDX_W-1:0]            b_out_idx,
    output logic signed [B_VAL_W-1:0]   b_out_val,

    // --- C* stream flowing horizontally (west -> east) (INT32 signed accumulators) ---
    input  logic [NUM_CBUF*IDX_W-1:0]       c_in_a_idx_flat,
    input  logic [NUM_CBUF*IDX_W-1:0]       c_in_b_idx_flat,
    input  logic signed [NUM_CBUF*C_VAL_W-1:0] c_in_val_flat,
    input  logic [NUM_CBUF-1:0]             c_in_valid_flat,

    output logic [NUM_CBUF*IDX_W-1:0]       c_out_a_idx_flat,
    output logic [NUM_CBUF*IDX_W-1:0]       c_out_b_idx_flat,
    output logic signed [NUM_CBUF*C_VAL_W-1:0] c_out_val_flat,
    output logic [NUM_CBUF-1:0]             c_out_valid_flat,

    output logic                            overflow
);

    // ---------------- Stationary A* Register (INT8) ----------------
    logic [IDX_W-1:0]        a_idx_q;
    logic signed [A_VAL_W-1:0] a_val_q;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            a_idx_q <= '0;
            a_val_q <= '0;
        end else if (a_load_en) begin
            a_idx_q <= a_load_idx;
            a_val_q <= a_load_val;
        end
    end

    // Compute trigger: multiply-accumulate occurs ONLY when A* index matches B* index
    logic do_compute;
    assign do_compute = (a_idx_q != '0) && (b_in_idx != '0) && (a_idx_q == b_in_idx);

    // 8-bit signed x 8-bit signed = 16-bit signed product
    logic signed [(A_VAL_W+B_VAL_W)-1:0] product;
    assign product = $signed(a_val_q) * $signed(b_in_val);

    // Unpack incoming C* stream
    logic [IDX_W-1:0]        c_in_a_idx [NUM_CBUF];
    logic [IDX_W-1:0]        c_in_b_idx [NUM_CBUF];
    logic signed [C_VAL_W-1:0] c_in_val   [NUM_CBUF];
    logic                    c_in_valid [NUM_CBUF];

    always_comb begin
        for (int i = 0; i < NUM_CBUF; i++) begin
            c_in_a_idx[i] = c_in_a_idx_flat[i*IDX_W +: IDX_W];
            c_in_b_idx[i] = c_in_b_idx_flat[i*IDX_W +: IDX_W];
            c_in_val[i]   = c_in_val_flat[i*C_VAL_W +: C_VAL_W];
            c_in_valid[i] = c_in_valid_flat[i];
        end
    end

    // Match & Free slot detection
    logic                        match_found;
    logic [$clog2(NUM_CBUF)-1:0] match_slot;
    logic                        free_found;
    logic [$clog2(NUM_CBUF)-1:0] free_slot;

    always_comb begin
        match_found = 1'b0; match_slot = '0;
        free_found  = 1'b0; free_slot  = '0;
        for (int i = 0; i < NUM_CBUF; i++) begin
            if (c_in_valid[i] && (c_in_a_idx[i] == a_idx_q) && (c_in_b_idx[i] == b_in_idx)) begin
                match_found = 1'b1;
                match_slot  = i;
            end
            if (!free_found && !c_in_valid[i]) begin
                free_found = 1'b1;
                free_slot  = i;
            end
        end
    end

    // Next C* stream state combinational computation
    logic [IDX_W-1:0]        c_next_a_idx [NUM_CBUF];
    logic [IDX_W-1:0]        c_next_b_idx [NUM_CBUF];
    logic signed [C_VAL_W-1:0] c_next_val   [NUM_CBUF];
    logic                    c_next_valid [NUM_CBUF];

    always_comb begin
        for (int i = 0; i < NUM_CBUF; i++) begin
            c_next_a_idx[i] = c_in_a_idx[i];
            c_next_b_idx[i] = c_in_b_idx[i];
            c_next_val[i]   = c_in_val[i];
            c_next_valid[i] = c_in_valid[i];
        end

        if (do_compute) begin
            if (match_found) begin
                c_next_val[match_slot] = c_in_val[match_slot] + $signed(product);
            end else if (free_found) begin
                c_next_a_idx[free_slot] = a_idx_q;
                c_next_b_idx[free_slot] = b_in_idx;
                c_next_val[free_slot]   = $signed(product);
                c_next_valid[free_slot] = 1'b1;
            end
        end
    end

    // Registered outputs
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            b_out_idx <= '0;
            b_out_val <= '0;
            overflow  <= 1'b0;
            for (int i = 0; i < NUM_CBUF; i++) begin
                c_out_a_idx_flat[i*IDX_W +: IDX_W] <= '0;
                c_out_b_idx_flat[i*IDX_W +: IDX_W] <= '0;
                c_out_val_flat[i*C_VAL_W +: C_VAL_W]   <= '0;
                c_out_valid_flat[i]                <= 1'b0;
            end
        end else begin
            // Systolic B* vertical passage
            b_out_idx <= b_in_idx;
            b_out_val <= b_in_val;

            // Overflow detection
            if (do_compute && !match_found && !free_found) begin
                overflow <= 1'b1;
            end else begin
                overflow <= 1'b0;
            end

            // Systolic C* horizontal passage & update
            for (int i = 0; i < NUM_CBUF; i++) begin
                c_out_a_idx_flat[i*IDX_W +: IDX_W] <= c_next_a_idx[i];
                c_out_b_idx_flat[i*IDX_W +: IDX_W] <= c_next_b_idx[i];
                c_out_val_flat[i*C_VAL_W +: C_VAL_W]   <= c_next_val[i];
                c_out_valid_flat[i]                <= c_next_valid[i];
            end
        end
    end

endmodule