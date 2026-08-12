// tb_mentha_ws.sv
// Unit Testbench for Weight-Stationary Mentha SNN PE Array with Horizontal Streaming Multi-Timestep C*.
// Configured with INT8 signed weights (A*), 8-bit timestep spikes (B*), and INT16 accumulators x 8 timesteps (C*).

`timescale 1ns/1ps

module tb_mentha_ws;

    localparam int IDX_W     = 8;
    localparam int A_VAL_W   = 8;     // INT8 signed weight
    localparam int TIMESTEPS = 8;     // 8 timesteps per spike vector
    localparam int C_VAL_W   = 16;    // INT16 signed accumulator per timestep
    localparam int NUM_CBUF  = 4;
    localparam int ROWS      = 4;
    localparam int COLS      = 4;

    logic clk = 0;
    logic rst_n;

    logic                    a_load_en;
    logic [$clog2(ROWS)-1:0] a_load_row;
    logic [$clog2(COLS)-1:0] a_load_col;
    logic [IDX_W-1:0]        a_load_idx;
    logic signed [A_VAL_W-1:0] a_load_val;

    logic [COLS*IDX_W-1:0]     b_edge_idx_flat;
    logic [COLS*TIMESTEPS-1:0] b_edge_spikes_flat;
    logic [COLS*IDX_W-1:0]     b_out_idx_flat;
    logic [COLS*TIMESTEPS-1:0] b_out_spikes_flat;

    logic [ROWS*NUM_CBUF*IDX_W-1:0]               c_edge_a_idx_flat;
    logic [ROWS*NUM_CBUF*IDX_W-1:0]               c_edge_b_idx_flat;
    logic signed [ROWS*NUM_CBUF*TIMESTEPS*C_VAL_W-1:0] c_edge_val_flat;
    logic [ROWS*NUM_CBUF-1:0]                     c_edge_valid_flat;

    logic [ROWS*NUM_CBUF*IDX_W-1:0]               c_out_a_idx_flat;
    logic [ROWS*NUM_CBUF*IDX_W-1:0]               c_out_b_idx_flat;
    logic signed [ROWS*NUM_CBUF*TIMESTEPS*C_VAL_W-1:0] c_out_val_flat;
    logic [ROWS*NUM_CBUF-1:0]                     c_out_valid_flat;

    logic [ROWS*COLS-1:0]                         overflow_flat;

    int errors = 0;

    mentha_array_ws_4x4 #(
        .IDX_W     (IDX_W),
        .A_VAL_W   (A_VAL_W),
        .TIMESTEPS (TIMESTEPS),
        .C_VAL_W   (C_VAL_W),
        .NUM_CBUF  (NUM_CBUF),
        .ROWS      (ROWS),
        .COLS      (COLS)
    ) dut (.*);

    always #5 clk = ~clk;

    task automatic set_b(int col, int idx, logic [TIMESTEPS-1:0] spikes);
        b_edge_idx_flat[col*IDX_W +: IDX_W]             = idx;
        b_edge_spikes_flat[col*TIMESTEPS +: TIMESTEPS] = spikes;
    endtask

    task automatic clear_b_all;
        b_edge_idx_flat    = '0;
        b_edge_spikes_flat = '0;
    endtask

    task automatic clear_c_west_all;
        c_edge_a_idx_flat = '0;
        c_edge_b_idx_flat = '0;
        c_edge_val_flat   = '0;
        c_edge_valid_flat = '0;
    endtask

    task automatic load_a(int row, int col, int idx, int val);
        @(negedge clk);
        a_load_en  = 1;
        a_load_row = row;
        a_load_col = col;
        a_load_idx = idx;
        a_load_val = val;
        @(negedge clk);
        a_load_en  = 0;
    endtask

    function automatic logic signed [C_VAL_W-1:0] get_east_c_val_timestep(int row, int slot, int timestep);
        int slot_idx = row*NUM_CBUF + slot;
        return c_out_val_flat[(slot_idx*TIMESTEPS + timestep)*C_VAL_W +: C_VAL_W];
    endfunction

    function automatic logic [IDX_W-1:0] get_east_c_a_idx(int row, int slot);
        return c_out_a_idx_flat[(row*NUM_CBUF + slot)*IDX_W +: IDX_W];
    endfunction

    function automatic logic [IDX_W-1:0] get_east_c_b_idx(int row, int slot);
        return c_out_b_idx_flat[(row*NUM_CBUF + slot)*IDX_W +: IDX_W];
    endfunction

    function automatic int find_east_c(int row, int a_tag, int b_tag);
        for (int k = 0; k < NUM_CBUF; k++) begin
            if (c_out_valid_flat[row*NUM_CBUF + k] &&
                get_east_c_a_idx(row, k) == a_tag &&
                get_east_c_b_idx(row, k) == b_tag)
                return k;
        end
        return -1;
    endfunction

    task automatic check_east_c_timestep(string name, int row, int a_tag, int b_tag, int timestep, int exp_val);
        automatic int slot = find_east_c(row, a_tag, b_tag);
        if (slot == -1) begin
            $display("FAIL %s : (a_idx=%0d, b_idx=%0d) not found at East Edge row %0d", name, a_tag, b_tag, row);
            errors++;
        end else if (get_east_c_val_timestep(row, slot, timestep) !== exp_val) begin
            $display("FAIL %s t=%0d : got=%0d exp=%0d for (a_idx=%0d, b_idx=%0d)", name, timestep, get_east_c_val_timestep(row, slot, timestep), exp_val, a_tag, b_tag);
            errors++;
        end else begin
            $display("PASS %s t=%0d : (a_idx=%0d, b_idx=%0d) val=%0d at East Edge", name, timestep, a_tag, b_tag, exp_val);
        end
    endtask

    initial begin
        rst_n = 0;
        a_load_en = 0;
        clear_b_all();
        clear_c_west_all();
        @(negedge clk);
        rst_n = 1;

        $display("=== Starting Mentha SNN WS Multi-Timestep C* Test Suite ===");

        // Preload stationary A* (INT8 signed weights):
        // PE(0,0): A*(a_idx=10, val=5)
        // PE(0,1): A*(a_idx=20, val=-8)
        load_a(0, 0, 10, 5);
        load_a(0, 1, 20, -8);

        // --- Test 1: SNN Spike Accumulation Across 8 Timesteps ---
        // Cycle 1: B*(b_idx=10, spikes=8'b0010_0001) at Col 0 (spikes at t=0 and t=5)
        // -> PE(0,0) weight=5: t=0 -> 5, t=5 -> 5, all other t -> 0
        @(negedge clk);
        set_b(0, 10, 8'b0010_0001);
        clear_c_west_all();

        // Cycle 2: B*(b_idx=20, spikes=8'b1000_0010) at Col 1 (spikes at t=1 and t=7)
        // -> PE(0,1) weight=-8: t=1 -> -8, t=7 -> -8, all other t -> 0
        @(negedge clk);
        clear_b_all();
        set_b(1, 20, 8'b1000_0010);

        // Cycle 3: Clear B*
        @(negedge clk);
        clear_b_all();

        // Wait for C* wave to reach East Edge of Row 0
        @(negedge clk);
        @(negedge clk);
        #1;

        // Verify East Edge output of Row 0 for PE(0,0) slot across timesteps
        check_east_c_timestep("T1: PE(0,0) t=0 Spike Accumulation", 0, 10, 10, 0, 5);
        check_east_c_timestep("T1: PE(0,0) t=1 No Spike",             0, 10, 10, 1, 0);
        check_east_c_timestep("T1: PE(0,0) t=5 Spike Accumulation", 0, 10, 10, 5, 5);

        // Verify East Edge output of Row 0 for PE(0,1) slot across timesteps
        check_east_c_timestep("T1: PE(0,1) t=1 Spike Accumulation", 0, 20, 20, 1, -8);
        check_east_c_timestep("T1: PE(0,1) t=7 Spike Accumulation", 0, 20, 20, 7, -8);

        // --- Test 2: Multi-Pass In-Flight Accumulation Across Timesteps ---
        // Feed new spikes 8'b0000_0011 into Col 0 (spikes at t=0 and t=1)
        // Feed existing C* slot (10, 10, t=0:5, t=5:5) into West Edge of Row 0
        @(negedge clk);
        set_b(0, 10, 8'b0000_0011);
        c_edge_a_idx_flat[0 +: IDX_W] = 10;
        c_edge_b_idx_flat[0 +: IDX_W] = 10;
        // Set West C* slot values: t=0 -> 5, t=5 -> 5
        c_edge_val_flat[0*C_VAL_W +: C_VAL_W] = 5;
        c_edge_val_flat[5*C_VAL_W +: C_VAL_W] = 5;
        c_edge_valid_flat[0]                  = 1'b1;

        @(negedge clk);
        clear_b_all();
        clear_c_west_all();

        @(negedge clk);
        @(negedge clk);
        @(negedge clk);
        #1;

        // Verify that:
        // t=0: 5 + 5 = 10
        // t=1: 0 + 5 = 5
        // t=5: 5 + 0 = 5
        check_east_c_timestep("T2: Multi-pass t=0 Accumulation (5+5)", 0, 10, 10, 0, 10);
        check_east_c_timestep("T2: Multi-pass t=1 Accumulation (0+5)", 0, 10, 10, 1, 5);
        check_east_c_timestep("T2: Multi-pass t=5 Accumulation (5+0)", 0, 10, 10, 5, 5);

        $display("--------------------------------------------------");
        if (errors == 0)
            $display("ALL SNN TESTS PASSED 100%% ACCURATELY!");
        else
            $display("%0d SNN TEST(S) FAILED", errors);
        $display("--------------------------------------------------");

        $finish;
    end

endmodule