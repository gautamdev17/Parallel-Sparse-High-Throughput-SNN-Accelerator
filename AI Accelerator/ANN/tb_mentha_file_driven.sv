// tb_mentha_file_driven.sv
// File-Driven SystemVerilog Testbench for Mentha Weight-Stationary AI Accelerator IP.
// Driven by Python Golden Model stimulus files (sim_data/stim_*.hex).
// Configured with INT8 signed weights (A*), INT8 signed activations (B*), and INT32 signed accumulators (C*).

`timescale 1ns/1ps

module tb_mentha_file_driven;

    localparam int IDX_W    = 8;
    localparam int A_VAL_W  = 8;     // INT8 signed weight
    localparam int B_VAL_W  = 8;     // INT8 signed activation
    localparam int C_VAL_W  = 32;    // INT32 signed accumulator
    localparam int NUM_CBUF = 4;
    localparam int ROWS     = 4;
    localparam int COLS     = 4;

    logic clk = 0;
    logic rst_n;

    // --- A* stationary load interface ---
    logic                    a_load_en;
    logic [$clog2(ROWS)-1:0] a_load_row;
    logic [$clog2(COLS)-1:0] a_load_col;
    logic [IDX_W-1:0]        a_load_idx;
    logic signed [A_VAL_W-1:0] a_load_val;

    // --- B* vertical edge inputs (top -> bottom) ---
    logic [COLS*IDX_W-1:0]   b_edge_idx_flat;
    logic signed [COLS*B_VAL_W-1:0] b_edge_val_flat;
    logic [COLS*IDX_W-1:0]   b_out_idx_flat;
    logic signed [COLS*B_VAL_W-1:0] b_out_val_flat;

    // --- C* horizontal edge inputs (entering from West) ---
    logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_edge_a_idx_flat;
    logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_edge_b_idx_flat;
    logic signed [ROWS*NUM_CBUF*C_VAL_W-1:0] c_edge_val_flat;
    logic [ROWS*NUM_CBUF-1:0]             c_edge_valid_flat;

    // --- C* horizontal edge outputs (exiting to East) ---
    logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_out_a_idx_flat;
    logic [ROWS*NUM_CBUF*IDX_W-1:0]       c_out_b_idx_flat;
    logic signed [ROWS*NUM_CBUF*C_VAL_W-1:0] c_out_val_flat;
    logic [ROWS*NUM_CBUF-1:0]             c_out_valid_flat;

    logic [ROWS*COLS-1:0]                 overflow_flat;

    mentha_array_ws_4x4 #(
        .IDX_W (IDX_W),
        .A_VAL_W (A_VAL_W),
        .B_VAL_W (B_VAL_W),
        .C_VAL_W (C_VAL_W),
        .NUM_CBUF (NUM_CBUF),
        .ROWS (ROWS),
        .COLS (COLS)
    ) dut (.*);

    always #5 clk = ~clk;

    int file_a, file_b, file_c_west, file_c_actual;
    int status;
    int r_in, c_in;
    logic [IDX_W-1:0] a_idx_in;
    logic signed [A_VAL_W-1:0] a_val_in;

    // Temporary scalar L-values for $fscanf
    logic [IDX_W-1:0]        b_tmp_idx [4];
    logic signed [B_VAL_W-1:0] b_tmp_val [4];

    logic [IDX_W-1:0]        tmp_a_idx;
    logic [IDX_W-1:0]        tmp_b_idx;
    logic signed [C_VAL_W-1:0] tmp_val;
    logic                    tmp_valid;

    // Output extraction variables
    logic [IDX_W-1:0]        out_a;
    logic [IDX_W-1:0]        out_b;
    logic signed [C_VAL_W-1:0] out_val;
    logic                    out_valid;

    initial begin
        rst_n = 0;
        a_load_en = 0;
        b_edge_idx_flat = '0;
        b_edge_val_flat = '0;
        c_edge_a_idx_flat = '0;
        c_edge_b_idx_flat = '0;
        c_edge_val_flat   = '0;
        c_edge_valid_flat = '0;

        #20;
        rst_n = 1;
        #10;

        // 1. Preload stationary A* from sim_data/stim_a.hex
        file_a = $fopen("sim_data/stim_a.hex", "r");
        if (file_a == 0) begin
            $display("ERROR: Could not open sim_data/stim_a.hex!");
            $finish;
        end

        while (!$feof(file_a)) begin
            status = $fscanf(file_a, "%d %d %h %h\n", r_in, c_in, a_idx_in, a_val_in);
            if (status == 4) begin
                @(negedge clk);
                a_load_en  = 1;
                a_load_row = r_in;
                a_load_col = c_in;
                a_load_idx = a_idx_in;
                a_load_val = a_val_in;
                @(negedge clk);
                a_load_en  = 0;
            end
        end
        $fclose(file_a);

        // 2. Open B* and West C* stimulus files & actual output file
        file_b = $fopen("sim_data/stim_b.hex", "r");
        file_c_west = $fopen("sim_data/stim_c_west.hex", "r");
        file_c_actual = $fopen("sim_data/actual_c_east.hex", "w");

        if (file_b == 0 || file_c_west == 0 || file_c_actual == 0) begin
            $display("ERROR: Could not open streaming stimulus or output files!");
            $finish;
        end

        // 3. Cycle-by-cycle streaming loop
        while (!$feof(file_b) && !$feof(file_c_west)) begin
            int stat_b, stat_cw, total_cw_items;

            @(negedge clk);

            // Read 4 columns of B* (8 hex numbers)
            stat_b = $fscanf(file_b, "%h %h %h %h %h %h %h %h\n",
                b_tmp_idx[0], b_tmp_val[0],
                b_tmp_idx[1], b_tmp_val[1],
                b_tmp_idx[2], b_tmp_val[2],
                b_tmp_idx[3], b_tmp_val[3]
            );

            if (stat_b == 8) begin
                for (int c = 0; c < 4; c++) begin
                    b_edge_idx_flat[c*IDX_W +: IDX_W]     = b_tmp_idx[c];
                    b_edge_val_flat[c*B_VAL_W +: B_VAL_W] = b_tmp_val[c];
                end
            end

            // Read 16 slots of West C* (4 items per slot = 64 numbers total)
            total_cw_items = 0;
            for (int slot = 0; slot < 16; slot++) begin
                stat_cw = $fscanf(file_c_west, "%h %h %h %h",
                    tmp_a_idx, tmp_b_idx, tmp_val, tmp_valid
                );
                if (stat_cw == 4) begin
                    c_edge_a_idx_flat[slot*IDX_W +: IDX_W]     = tmp_a_idx;
                    c_edge_b_idx_flat[slot*IDX_W +: IDX_W]     = tmp_b_idx;
                    c_edge_val_flat[slot*C_VAL_W +: C_VAL_W]   = tmp_val;
                    c_edge_valid_flat[slot]                    = tmp_valid;
                    total_cw_items += 4;
                end
            end

            if (stat_b == 8 && total_cw_items == 64) begin
                @(posedge clk);
                #1;

                // Write actual East Edge output to file in space-separated hex
                for (int r = 0; r < ROWS; r++) begin
                    for (int s = 0; s < NUM_CBUF; s++) begin
                        out_a     = c_out_a_idx_flat[(r*NUM_CBUF + s)*IDX_W +: IDX_W];
                        out_b     = c_out_b_idx_flat[(r*NUM_CBUF + s)*IDX_W +: IDX_W];
                        out_val   = c_out_val_flat[(r*NUM_CBUF + s)*C_VAL_W +: C_VAL_W];
                        out_valid = c_out_valid_flat[r*NUM_CBUF + s];

                        $fwrite(file_c_actual, "%02h %02h %08h %0d ", out_a, out_b, out_val, out_valid);
                    end
                end
                $fdisplay(file_c_actual, "");
            end
        end

        $fclose(file_b);
        $fclose(file_c_west);
        $fclose(file_c_actual);

        $display("RTL File-Driven Co-Simulation Completed!");
        $finish;
    end

endmodule