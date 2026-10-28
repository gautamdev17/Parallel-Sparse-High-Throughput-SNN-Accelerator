// tb_prosperity.v -- drives prosperity_core over build/stim/prosperity tiles: pre-load the TCAM bank, popcount
// phase (m/8 cycles), one search per row with >= 2 spikes, bitonic sort, then issue rows in sorted order
// (all-zero rows skipped; rows with 1 spike are not searched: no prefix, pattern = row). The TB plays the
// spike / weight / output buffers (output-buffer forwarding for a prefix written back the cycle before).
// Logs pst_prosperity.txt (pruner results), res_prosperity.txt (row results), per-tile cycles.
`timescale 1ns/1ps
module tb_prosperity;
    localparam M = 256, K = 16, N = 128, AW = 16, NT = `NT;
    reg clk = 0, rst = 1;
    always #0.625 clk = ~clk;
    reg [K-1:0] rows [0:NT*M-1];
    reg [N*8-1:0] wts [0:NT*K-1];
    reg [N*AW-1:0] resm [0:M-1];
    reg ld_we = 0, ld_bank = 0, bank = 0, pc_v = 0, q_v = 0, pst_bank = 0, sort_start = 0;
    reg [7:0] ld_addr = 0, q_idx = 0, rd_row = 0; reg [4:0] pc_grp = 0; reg [K-1:0] ld_data = 0;
    reg iss_v = 0, iss_has = 0; reg [K-1:0] iss_pat = 0; reg [7:0] iss_pref = 0;
    wire p_v, p_has, sort_done, rd_has, pbusy, wb_v; wire [7:0] p_idx, p_prefix, rd_prefix; wire [K-1:0] p_pattern, rd_pattern;
    wire [M*8-1:0] order; wire [3:0] wsel; wire [N*AW-1:0] acc_out; wire [31:0] l_spk;
    integer tile, i, j, r, pc, f1, f2, fc, cyc = 0, c0, cl, pre0, pre1, lastrow, wbrow;
    wire [N*AW-1:0] pref_row = (wb_v && iss_pref == wbrow) ? acc_out : resm[iss_pref];
    prosperity_core dut(.clk(clk), .rst(rst), .ld_we(ld_we), .ld_bank(ld_bank), .ld_addr(ld_addr), .ld_data(ld_data),
        .bank(bank), .pc_v(pc_v), .pc_grp(pc_grp), .q_v(q_v), .q_idx(q_idx), .p_v(p_v), .p_idx(p_idx), .p_has(p_has),
        .p_prefix(p_prefix), .p_pattern(p_pattern), .pst_bank(pst_bank), .sort_start(sort_start), .sort_done(sort_done),
        .order_flat(order), .rd_row(rd_row), .rd_has(rd_has), .rd_prefix(rd_prefix), .rd_pattern(rd_pattern),
        .iss_v(iss_v), .iss_pattern(iss_pat), .iss_has_prefix(iss_has), .prefix_row(pref_row),
        .wrow(wts[tile*K + wsel]), .wsel(wsel), .pbusy(pbusy), .wb_v(wb_v), .acc_out(acc_out),
        .l_v(32'b0), .l_first(32'b0), .l_x({32*AW{1'b0}}), .l_spk(l_spk));
    always @(posedge clk) cyc <= cyc + 1;
    always @(posedge clk) if (!rst && p_v) $fwrite(f1, "%0d %0d %0d %0d %0d\n", tile, p_idx, p_has, p_prefix, p_pattern);
    always @(posedge clk) if (!rst && wb_v) begin
        resm[wbrow] <= acc_out;
        $fwrite(f2, "%0d %0d", tile, wbrow);
        for (j = 0; j < N; j = j + 1) $fwrite(f2, " %0d", $signed(acc_out[j*AW +: AW]));
        $fwrite(f2, "\n");
        cl = cyc;
    end
    function integer popc(input [K-1:0] x); integer b; begin popc = 0; for (b = 0; b < K; b = b + 1) popc = popc + x[b]; end endfunction
    initial begin
        $readmemh("stim/prosperity/rows.hex", rows);
        $readmemh("stim/prosperity/wts.hex", wts);
        f1 = $fopen("pst_prosperity.txt", "w"); f2 = $fopen("res_prosperity.txt", "w"); fc = $fopen("cyc_prosperity.txt", "w");
        if ($test$plusargs("vcd")) $dumpfile(`VCDFILE);
        tile = 0; wbrow = 0;
        repeat (3) @(negedge clk); rst = 0;
        if ($test$plusargs("vcd")) $dumpvars(0, tb_prosperity.dut);
        for (tile = 0; tile < NT; tile = tile + 1) begin
            // pre-load (double-buffered TCAM: overlaps the previous tile in hardware; not counted)
            for (i = 0; i < M; i = i + 1) begin
                ld_we = 1; ld_bank = tile % 2; ld_addr = i; ld_data = rows[tile*M + i]; @(negedge clk);
            end
            ld_we = 0; bank = tile % 2; pst_bank = tile % 2;
            pre0 = cyc;
            for (i = 0; i < M / 8; i = i + 1) begin pc_v = 1; pc_grp = i; @(negedge clk); end
            pc_v = 0;
            for (i = 0; i < M; i = i + 1) if (popc(rows[tile*M + i]) > 1) begin q_v = 1; q_idx = i; @(negedge clk); end
            q_v = 0;
            pre1 = cyc;
            sort_start = 1; @(negedge clk); sort_start = 0;
            while (!sort_done) @(negedge clk);
            repeat (3) @(negedge clk);
            pst_bank = ~(tile % 2);                      // read the table just written
            // processor: issue rows in sorted order
            c0 = -1; cl = 0;
            for (i = 0; i < M; i = i + 1) begin
                r = order[i*8 +: 8];
                pc = popc(rows[tile*M + r]);
                if (pc > 0) begin
                    rd_row = r; #0.01;
                    while (pbusy) @(negedge clk);
                    if (pc == 1) begin iss_has = 0; iss_pat = rows[tile*M + r]; iss_pref = 0; end
                    else begin iss_has = rd_has; iss_pat = rd_pattern; iss_pref = rd_prefix; end
                    iss_v = 1; if (c0 < 0) c0 = cyc;
                    @(posedge clk); wbrow <= r;
                    @(negedge clk); iss_v = 0;
                end
            end
            while (pbusy) @(negedge clk);
            repeat (2) @(negedge clk);
            $fwrite(fc, "%0d %0d %0d\n", tile, cl - c0 + 1, pre1 - pre0);
        end
        $fclose(f1); $fclose(f2); $fclose(fc);
        $display("PROSPERITY_DONE tiles=%0d", NT);
        $finish;
    end
endmodule
