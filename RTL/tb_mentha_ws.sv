// tb_mentha_ws.sv
// Directed testbench for the corrected weight-stationary Mentha PE/array.
//
// Focus: exercise the case the naive single-psum-scalar version gets
// WRONG -- a PE column receiving B* entries whose products must
// accumulate into *different* output rows (out_idx) within the same
// PE, i.e. multiple concurrent entries in one PE's C* bank, not just a
// single running scalar.

`timescale 1ns/1ps

module tb_mentha_ws;

    localparam int IDX_W   = 8;
    localparam int VAL_W   = 32;
    localparam int NUM_ABUF = 4;
    localparam int NUM_CBUF = 4;
    localparam int ROWS    = 4;
    localparam int COLS    = 4;
    localparam int ROW_OUT_CAP = COLS*NUM_CBUF;

    logic clk = 0;
    logic rst_n;

    logic                        a_load_en;
    logic [$clog2(ROWS)-1:0]     a_load_row;
    logic [$clog2(COLS)-1:0]     a_load_col;
    logic [$clog2(NUM_ABUF)-1:0] a_load_slot;
    logic [IDX_W-1:0]            a_load_idx;
    logic [IDX_W-1:0]            a_load_out_idx;
    logic signed [VAL_W-1:0]     a_load_val;

    logic [COLS*IDX_W-1:0] b_edge_idx_flat;
    logic [COLS*VAL_W-1:0] b_edge_val_flat;
    logic [COLS*IDX_W-1:0] b_out_idx_flat;
    logic [COLS*VAL_W-1:0] b_out_val_flat;

    logic drain_en;
    logic [ROWS*ROW_OUT_CAP*IDX_W-1:0]        c_out_idx_flat;
    logic signed [ROWS*ROW_OUT_CAP*VAL_W-1:0] c_out_val_flat;
    logic [ROWS*ROW_OUT_CAP-1:0]              c_out_valid_flat;
    logic [ROWS*COLS-1:0]                     overflow_flat;

    int errors = 0;

    mentha_array_ws_4x4 #(
        .IDX_W (IDX_W), .VAL_W (VAL_W),
        .NUM_ABUF (NUM_ABUF), .NUM_CBUF (NUM_CBUF),
        .ROWS (ROWS), .COLS (COLS), .ROW_OUT_CAP (ROW_OUT_CAP)
    ) dut (.*);

    always #5 clk = ~clk;

    task automatic set_b(int col, int idx, int val);
        b_edge_idx_flat[col*IDX_W +: IDX_W] = idx;
        b_edge_val_flat[col*VAL_W +: VAL_W] = val;
    endtask

    task automatic load_a(int row, int col, int slot, int idx, int out_idx, int val);
        @(negedge clk);
        a_load_en      = 1;
        a_load_row     = row;
        a_load_col     = col;
        a_load_slot    = slot;
        a_load_idx     = idx;
        a_load_out_idx = out_idx;
        a_load_val     = val;
        @(negedge clk);
        a_load_en      = 0;
    endtask

    function automatic logic signed [VAL_W-1:0] get_c(int row, int slot);
        return c_out_val_flat[(row*ROW_OUT_CAP+slot)*VAL_W +: VAL_W];
    endfunction
    function automatic logic [IDX_W-1:0] get_c_idx(int row, int slot);
        return c_out_idx_flat[(row*ROW_OUT_CAP+slot)*IDX_W +: IDX_W];
    endfunction

    // find the c_out slot (within a row) whose out_idx==tag; -1 if none valid
    function automatic int find_c(int row, int tag);
        for (int k = 0; k < ROW_OUT_CAP; k++) begin
            if (c_out_valid_flat[row*ROW_OUT_CAP+k] && get_c_idx(row,k) == tag)
                return k;
        end
        return -1;
    endfunction

    task automatic check_val(string name, int row, int tag, int exp);
        automatic int k = find_c(row, tag);
        if (k == -1) begin
            $display("FAIL %s : out_idx=%0d not found in row %0d output", name, tag, row);
            errors++;
        end else if (get_c(row,k) !== exp) begin
            $display("FAIL %s : got=%0d exp=%0d", name, get_c(row,k), exp);
            errors++;
        end else begin
            $display("PASS %s : out_idx=%0d val=%0d", name, tag, exp);
        end
    endtask

    initial begin
        rst_n = 0;
        a_load_en = 0;
        b_edge_idx_flat = '0; b_edge_val_flat = '0;
        drain_en = 0;
        @(negedge clk);
        rst_n = 1;

        // --- Test 1: single-term MAC, single PE, sanity check ---
        // PE(0,0): stationary A* entry idx=1 -> out_idx=100, val=3
        load_a(0, 0, 0, /*idx*/1, /*out_idx*/100, /*val*/3);
        @(negedge clk);
        set_b(0, 1, 5);          // B*[col0] idx=1 val=5 -> product = 15
        @(negedge clk);
        set_b(0, 0, 0);          // stop feeding
        @(negedge clk);
        #1;
        drain_en = 1;
        @(negedge clk);
        drain_en = 0;
        #1;
        check_val("T1: PE(0,0) single MAC", 0, 100, 15);

        // --- Test 2: THE CASE THE NAIVE VERSION BREAKS ---
        // PE(1,0) holds TWO stationary A* entries (packed row merged two
        // original rows into this one physical PE): 
        //   slot0: idx=1 -> out_idx=10, val=2
        //   slot1: idx=2 -> out_idx=20, val=7
        // A naive single-scalar-psum PE can only track ONE running sum and
        // would incorrectly co-mingle products destined for out_idx=10 and
        // out_idx=20. The corrected PE must keep them in separate bank
        // slots and accumulate independently.
        load_a(1, 0, 0, 1, 10, 2);
        load_a(1, 0, 1, 2, 20, 7);

        @(negedge clk);
        set_b(0, 1, 5);   // matches slot0 (idx=1) -> product = 2*5 = 10 -> out_idx=10
        @(negedge clk);
        set_b(0, 2, 3);   // matches slot1 (idx=2) -> product = 7*3 = 21 -> out_idx=20
        @(negedge clk);
        set_b(0, 1, 4);   // matches slot0 again -> product = 2*4 = 8, should ACCUMULATE: 10+8=18
        @(negedge clk);
        set_b(0, 0, 0);
        @(negedge clk);
        #1;
        drain_en = 1;
        @(negedge clk);
        drain_en = 0;
        #1;
        check_val("T2: PE(1,0) out_idx=10 accumulated (2*5 + 2*4)", 1, 10, 18);
        check_val("T2: PE(1,0) out_idx=20 single term (7*3)",       1, 20, 21);

        // --- Test 3: row-level merge across PEs mapping to the SAME out_idx ---
        // PE(2,0) and PE(2,1) both have entries with out_idx=50 (i.e. the
        // packed row's tag 50 spans a partial product computed at column 0
        // and another at column 1 of that row) -- row drain must merge
        // them into a single accumulated output entry.
        load_a(2, 0, 0, 1, 50, 3);
        load_a(2, 1, 0, 1, 50, 4);

        @(negedge clk);
        set_b(0, 1, 2);   // PE(2,0): 3*2=6 -> out_idx=50
        set_b(1, 1, 5);   // PE(2,1): 4*5=20 -> out_idx=50
        @(negedge clk);
        set_b(0, 0, 0);
        set_b(1, 0, 0);
        @(negedge clk);
        #1;
        drain_en = 1;
        @(negedge clk);
        drain_en = 0;
        #1;
        check_val("T3: row2 out_idx=50 merged across PE(2,0)+PE(2,1) (6+20)", 2, 50, 26);

        // --- Test 4: skip-and-pass, B* idx=0 must not disturb bank ---
        load_a(3, 0, 0, 1, 77, 9);
        @(negedge clk);
        set_b(0, 0, 0);   // idx=0 -> skip
        @(negedge clk);
        #1;
        drain_en = 1;
        @(negedge clk);
        drain_en = 0;
        #1;
        if (find_c(3, 77) != -1) begin
            $display("FAIL T4: skip case produced a spurious C* entry");
            errors++;
        end else begin
            $display("PASS T4: skip case produced no C* entry");
        end

        if (errors == 0)
            $display("ALL TESTS PASSED");
        else
            $display("%0d TEST(S) FAILED", errors);

        $finish;
    end

endmodule