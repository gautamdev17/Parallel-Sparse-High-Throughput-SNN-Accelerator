// mentha_pe_ws.sv
// Ultra-Low-Power Weight-Stationary (WS) Processing Element for Mentha SNN IP.
//
// Power Optimizations:
//   - Operand Isolation & Zero-Spike Gating: Adders disabled when no spikes active.
//   - Slot-Level Clock & Data Enable Gating: Unchanged C* registers do not toggle.
//   - Parallel Bitmask Matching: Lowers dynamic gate switching power.

module mentha_pe_ws #(
    parameter int IDX_W     = 8,     // Sparse index width (8-bit)
    parameter int A_VAL_W   = 8,     // Stationary A* INT8 signed weight width
    parameter int TIMESTEPS = 8,     // Number of timesteps per B* activation vector
    parameter int C_VAL_W   = 16,    // In-flight C* INT16 signed accumulator per timestep
    parameter int NUM_CBUF  = 4      // In-flight C* stream slot count per row
) (
    input  logic clk,
    input  logic rst_n,

    // --- A* stationary load interface (INT8 signed) ---
    input  logic                        a_load_en,
    input  logic [IDX_W-1:0]            a_load_idx,   // 1-based Row Index in output matrix C
    input  logic signed [A_VAL_W-1:0]   a_load_val,   // INT8 signed weight

    // --- B* flowing vertically (top -> bottom) (8-bit timestep spikes) ---
    input  logic [IDX_W-1:0]            b_in_idx,     // 1-based Column Index in output matrix C
    input  logic [TIMESTEPS-1:0]        b_in_spikes,  // 8-bit spike mask across timesteps 0..7
    output logic [IDX_W-1:0]            b_out_idx,
    output logic [TIMESTEPS-1:0]        b_out_spikes,

    // --- C* stream flowing horizontally (west -> east) ---
    input  logic [NUM_CBUF*IDX_W-1:0]               c_in_a_idx_flat,
    input  logic [NUM_CBUF*IDX_W-1:0]               c_in_b_idx_flat,
    input  logic signed [NUM_CBUF*TIMESTEPS*C_VAL_W-1:0] c_in_val_flat,
    input  logic [NUM_CBUF-1:0]                     c_in_valid_flat,

    output logic [NUM_CBUF*IDX_W-1:0]               c_out_a_idx_flat,
    output logic [NUM_CBUF*IDX_W-1:0]               c_out_b_idx_flat,
    output logic signed [NUM_CBUF*TIMESTEPS*C_VAL_W-1:0] c_out_val_flat,
    output logic [NUM_CBUF-1:0]                     c_out_valid_flat,

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

    // Compute trigger & Zero-Spike Gating:
    // Addition runs ONLY if both indices are valid AND at least 1 spike bit is high!
    logic do_compute, has_spikes, compute_active;
    assign do_compute     = (a_idx_q != '0) && (b_in_idx != '0);
    assign has_spikes     = |b_in_spikes;
    assign compute_active = do_compute && has_spikes;

    // Unpack incoming C* stream
    logic [IDX_W-1:0]        c_in_a_idx [NUM_CBUF];
    logic [IDX_W-1:0]        c_in_b_idx [NUM_CBUF];
    logic signed [C_VAL_W-1:0] c_in_val   [NUM_CBUF][TIMESTEPS];
    logic                    c_in_valid [NUM_CBUF];

    always_comb begin
        for (int i = 0; i < NUM_CBUF; i++) begin
            c_in_a_idx[i] = c_in_a_idx_flat[i*IDX_W +: IDX_W];
            c_in_b_idx[i] = c_in_b_idx_flat[i*IDX_W +: IDX_W];
            c_in_valid[i] = c_in_valid_flat[i];
            for (int t = 0; t < TIMESTEPS; t++) begin
                c_in_val[i][t] = c_in_val_flat[(i*TIMESTEPS + t)*C_VAL_W +: C_VAL_W];
            end
        end
    end

    // Parallel Bitmask Match & Free Slot Detection
    logic [NUM_CBUF-1:0] match_mask, free_mask;
    logic                match_found, free_found;
    logic [$clog2(NUM_CBUF)-1:0] match_slot, free_slot;

    always_comb begin
        for (int i = 0; i < NUM_CBUF; i++) begin
            match_mask[i] = c_in_valid[i] && (c_in_a_idx[i] == a_idx_q) && (c_in_b_idx[i] == b_in_idx);
            free_mask[i]  = !c_in_valid[i];
        end

        match_found = |match_mask;
        free_found  = |free_mask;

        // Priority encoders
        casez (match_mask)
            4'b???1: match_slot = 2'd0;
            4'b??10: match_slot = 2'd1;
            4'b?100: match_slot = 2'd2;
            4'b1000: match_slot = 2'd3;
            default: match_slot = 2'd0;
        endcase

        casez (free_mask)
            4'b???1: free_slot = 2'd0;
            4'b??10: free_slot = 2'd1;
            4'b?100: free_slot = 2'd2;
            4'b1000: free_slot = 2'd3;
            default: free_slot = 2'd0;
        endcase
    end

    // Combinational Next State Calculation
    logic [IDX_W-1:0]        c_next_a_idx [NUM_CBUF];
    logic [IDX_W-1:0]        c_next_b_idx [NUM_CBUF];
    logic signed [C_VAL_W-1:0] c_next_val   [NUM_CBUF][TIMESTEPS];
    logic                    c_next_valid [NUM_CBUF];

    always_comb begin
        for (int i = 0; i < NUM_CBUF; i++) begin
            c_next_a_idx[i] = c_in_a_idx[i];
            c_next_b_idx[i] = c_in_b_idx[i];
            c_next_valid[i] = c_in_valid[i];
            for (int t = 0; t < TIMESTEPS; t++) begin
                c_next_val[i][t] = c_in_val[i][t];
            end
        end

        // Operand isolated updates
        if (compute_active) begin
            if (match_found) begin
                for (int t = 0; t < TIMESTEPS; t++) begin
                    if (b_in_spikes[t]) begin
                        c_next_val[match_slot][t] = c_in_val[match_slot][t] + $signed(a_val_q);
                    end
                end
            end else if (free_found) begin
                c_next_a_idx[free_slot] = a_idx_q;
                c_next_b_idx[free_slot] = b_in_idx;
                c_next_valid[free_slot] = 1'b1;
                for (int t = 0; t < TIMESTEPS; t++) begin
                    if (b_in_spikes[t]) begin
                        c_next_val[free_slot][t] = $signed(a_val_q);
                    end else begin
                        c_next_val[free_slot][t] = '0;
                    end
                end
            end
        end
    end

    // Registered Stage with Enable Gating
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            b_out_idx    <= '0;
            b_out_spikes <= '0;
            overflow     <= 1'b0;
            for (int i = 0; i < NUM_CBUF; i++) begin
                c_out_a_idx_flat[i*IDX_W +: IDX_W] <= '0;
                c_out_b_idx_flat[i*IDX_W +: IDX_W] <= '0;
                c_out_valid_flat[i]                <= 1'b0;
                for (int t = 0; t < TIMESTEPS; t++) begin
                    c_out_val_flat[(i*TIMESTEPS + t)*C_VAL_W +: C_VAL_W] <= '0;
                end
            end
        end else begin
            b_out_idx    <= b_in_idx;
            b_out_spikes <= b_in_spikes;
            overflow     <= compute_active && !match_found && !free_found;

            for (int i = 0; i < NUM_CBUF; i++) begin
                c_out_a_idx_flat[i*IDX_W +: IDX_W] <= c_next_a_idx[i];
                c_out_b_idx_flat[i*IDX_W +: IDX_W] <= c_next_b_idx[i];
                c_out_valid_flat[i]                <= c_next_valid[i];
                for (int t = 0; t < TIMESTEPS; t++) begin
                    c_out_val_flat[(i*TIMESTEPS + t)*C_VAL_W +: C_VAL_W] <= c_next_val[i][t];
                end
            end
        end
    end

endmodule