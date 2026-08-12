// mentha_pe_ws.sv
// Weight-Stationary (WS) Processing Element for Mentha SNN (Spiking Neural Network Accelerator IP).
//
// SNN Dataflow & Microarchitecture:
//   - A* is stationary in PE: stores (a_idx, a_val) with INT8 signed weights.
//   - B* flows vertically (top -> bottom): (b_idx, b_spikes) where b_spikes is an 8-bit mask (1 bit per timestep t in [0..7]).
//   - C* flows horizontally (west -> east) as a stream of NUM_CBUF slots.
//     Each C* slot carries (c_a_idx, c_b_idx, c_val[0..7], c_valid), holding independent 16-bit signed accumulators
//     for all 8 timesteps.
//
// AC (Accumulation-Only, No Multipliers) Logic per Cycle:
//   - If both a_idx and b_in_idx are non-zero and match (a_idx_q == b_in_idx):
//     1. Match incoming C* stream slots for (c_a_idx == a_idx) && (c_b_idx == b_in_idx) or locate free slot.
//     2. For each timestep t in [0..7]:
//        - If b_in_spikes[t] == 1: Accumulate stationary weight +a_val_q into c_val[t] (no multiplier used!).
//        - If b_in_spikes[t] == 0: No accumulation performed for timestep t.
//   - B* spikes and index are registered and passed to the bottom PE.
//   - Updated multi-timestep C* stream is registered and passed to the right PE.

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
    input  logic [IDX_W-1:0]            a_load_idx,
    input  logic signed [A_VAL_W-1:0]   a_load_val,

    // --- B* flowing vertically (top -> bottom) (8-bit timestep spikes: b_spikes[t] is 1 or 0) ---
    input  logic [IDX_W-1:0]            b_in_idx,
    input  logic [TIMESTEPS-1:0]        b_in_spikes,
    output logic [IDX_W-1:0]            b_out_idx,
    output logic [TIMESTEPS-1:0]        b_out_spikes,

    // --- C* stream flowing horizontally (west -> east) (16-bit signed accumulator x 8 timesteps per slot) ---
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

    // Compute trigger: Addition occurs ONLY when A* index matches B* index
    logic do_compute;
    assign do_compute = (a_idx_q != '0) && (b_in_idx != '0) && (a_idx_q == b_in_idx);

    // Unpack incoming C* stream (NUM_CBUF slots, each having 8 timesteps x 16-bit values)
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

    // Next C* stream state combinational computation across all 8 timesteps
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

        if (do_compute) begin
            if (match_found) begin
                for (int t = 0; t < TIMESTEPS; t++) begin
                    if (b_in_spikes[t]) begin
                        // AC (Accumulation): Add weight +a_val_q if spike is present at timestep t
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

    // Registered outputs
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
            // Systolic B* vertical passage
            b_out_idx    <= b_in_idx;
            b_out_spikes <= b_in_spikes;

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
                c_out_valid_flat[i]                <= c_next_valid[i];
                for (int t = 0; t < TIMESTEPS; t++) begin
                    c_out_val_flat[(i*TIMESTEPS + t)*C_VAL_W +: C_VAL_W] <= c_next_val[i][t];
                end
            end
        end
    end

endmodule