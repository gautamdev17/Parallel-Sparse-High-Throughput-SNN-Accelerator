// tb_mentha_ws.sv
// Testbench for Weight-Stationary Mentha PE Array with Horizontal Streaming C*.

`timescale 1ns/1ps

module tb_mentha_ws;

    localparam int IDX_W    = 8;
    localparam int VAL_W    = 32;
    localparam int NUM_CBUF = 4;
    localparam int ROWS     = 4;
    localparam int COLS     = 4;

    logic clk = 0;
    logic rst_n;

    logic                    a_load_en;
    logic [$clog2(ROWS)-1:0] a_load_row;
    logic [$clog2(COLS)-1:0] a_load_col;
    logic [IDX_W-1:0]        a_load_idx;
    logic signed [VAL_W-1:0] a_load_val;

    logic [COLS*IDX_W-1:0] b_edge_idx_flat;
    logic [COLS*VAL_W-1:0] b_edge_val_flat;
    logic [COLS*IDX_W-1:0] b_out_idx_flat;
    logic [COLS*VAL_W-1:0] b_out_val_flat;

    logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_edge_a_idx_flat;
    logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_edge_b_idx_flat;
    logic signed [ROWS*NUM_CBUF*VAL_W-1:0] c_edge_val_flat;
    logic [ROWS*NUM_CBUF-1:0]             c_edge_valid_flat;

    logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_out_a_idx_flat;
    logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_out_b_idx_flat;
    logic signed [ROWS*NUM_CBUF*VAL_W-1:0] c_out_val_flat;
    logic [ROWS*NUM_CBUF-1:0]             c_out_valid_flat;

    logic [ROWS*COLS-1:0]                 overflow_flat;

    int errors = 0;

    mentha_array_ws_4x4 #(
        .IDX_W (IDX_W), .VAL_W (VAL_W),
        .NUM_CBUF (NUM_CBUF), .ROWS (ROWS), .COLS (COLS)
    ) dut (.*);

    always #5 clk = ~clk;

    task automatic set_b(int col, int idx, int val);
        b_edge_idx_flat[col*IDX_W +: IDX_W] = idx;
        b_edge_val_flat[col*VAL_W +: VAL_W] = val;
    endtask

    task automatic clear_b_all;
        b_edge_idx_flat = '0;
        b_edge_val_flat = '0;
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

    function automatic logic signed [VAL_W-1:0] get_east_c_val(int row, int slot);
        return c_out_val_flat[(row*NUM_CBUF + slot)*VAL_W +: VAL_W];
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

    task automatic check_east_c(string name, int row, int a_tag, int b_tag, int exp_val);
        automatic int slot = find_east_c(row, a_tag, b_tag);
        if (slot == -1) begin
            $display("FAIL %s : (a_idx=%0d, b_idx=%0d) not found at East Edge row %0d", name, a_tag, b_tag, row);
            errors++;
        end else if (get_east_c_val(row, slot) !== exp_val) begin
            $display("FAIL %s : got=%0d exp=%0d for (a_idx=%0d, b_idx=%0d)", name, get_east_c_val(row, slot), exp_val, a_tag, b_tag);
            errors++;
        end else begin
            $display("PASS %s : (a_idx=%0d, b_idx=%0d) val=%0d at East Edge", name, a_tag, b_tag, exp_val);
        end
    endtask

    initial begin
        rst_n = 0;
        a_load_en = 0;
        clear_b_all();
        clear_c_west_all();
        @(negedge clk);
        rst_n = 1;

        $display("=== Starting Mentha WS Streaming C* Test Suite ===");

        // Preload stationary A*:
        // PE(0,0): A*(a_idx=10, val=3)
        // PE(0,1): A*(a_idx=20, val=4)
        load_a(0, 0, 10, 3);
        load_a(0, 1, 20, 4);

        // --- Test 1: Systolic Skewed B* Inputs ---
        // Cycle 1: B*(b_idx=10, val=5) at Col 0 -> PE(0,0) product = 3*5 = 15
        @(negedge clk);
        set_b(0, 10, 5);
        clear_c_west_all();

        // Cycle 2: B*(b_idx=20, val=6) at Col 1 as C* wave reaches PE(0,1)
        @(negedge clk);
        clear_b_all();
        set_b(1, 20, 6);

        // Cycle 3: Clear B*
        @(negedge clk);
        clear_b_all();

        // Wait for C* wave to reach East Edge of Row 0
        @(negedge clk);
        @(negedge clk);
        #1;

        // Verify East Edge output of Row 0
        check_east_c("T1: PE(0,0) Product", 0, 10, 10, 15);
        check_east_c("T1: PE(0,1) Product", 0, 20, 20, 24);

        // --- Test 2: In-Flight Stream Accumulation ---
        // Feed matching B* into Col 0: B*(b_idx=10, val=2) -> product 3*2 = 6
        // Feed existing C* slot (10, 10, 15) into West Edge of Row 0
        @(negedge clk);
        set_b(0, 10, 2);
        c_edge_a_idx_flat[0 +: IDX_W] = 10;
        c_edge_b_idx_flat[0 +: IDX_W] = 10;
        c_edge_val_flat[0 +: VAL_W]   = 15;
        c_edge_valid_flat[0]          = 1'b1;

        @(negedge clk);
        clear_b_all();
        clear_c_west_all();

        @(negedge clk);
        @(negedge clk);
        @(negedge clk);
        #1;

        // Verify that 15 + 6 = 21 was accumulated in-flight inside C* stream!
        check_east_c("T2: In-Flight Accumulation (15 + 6)", 0, 10, 10, 21);

        $display("--------------------------------------------------");
        if (errors == 0)
            $display("ALL TESTS PASSED 100%% ACCURATELY!");
        else
            $display("%0d TEST(S) FAILED", errors);
        $display("--------------------------------------------------");

        $finish;
    end

endmodule