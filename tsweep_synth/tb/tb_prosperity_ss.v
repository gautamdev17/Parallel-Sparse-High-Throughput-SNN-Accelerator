// tb_prosperity_ss.v -- steady-state power window for prosperity_core (same stimulus as tb_prosperity.v:
// build/stim/prosperity, VGG16 b2c2 sparse90, NT k-tiles).
// Pipeline as the double-buffered RTL intends (and as the official simulator counts: max(compute, preprocess)):
// while the processor issues tile t (reading PST bank t%2), the detector/pruner/sorter preprocess tile t+1
// (TCAM bank (t+1)%2, PST bank (t+1)%2). The sorter output is single-buffered, so the TB snapshots it at
// sort_done into an issue-order buffer (dispatcher queue, outside the core like the other buffers).
// The 256-cycle TCAM pre-load of tile t+2 (overlapped with compute in hardware, one row/cycle in this TB) runs
// between windows with $dumpoff; splice_vcd.py removes those gaps. Windows: t = 0 .. NT-2 (front-end of t+1 and
// issue of t both active). Counts window cycles and processor-occupied cycles (iss_v | pbusy) at posedge.
`timescale 1ns/1ps
module tb_prosperity;
    localparam M = 256, K = 16, N = 128, AW = 16, NT = `NT;
    reg clk = 0, rst = 1;
    always #0.625 clk = ~clk;
    reg [K-1:0] rows [0:NT*M-1];
    reg [N*8-1:0] wts [0:NT*K-1];
    reg [N*AW-1:0] resm [0:M-1];
    reg [7:0] ordb [0:2*M-1];
    reg ld_we = 0, ld_bank = 0, bank = 0, pc_v = 0, q_v = 0, pst_bank = 0, sort_start = 0;
    reg [7:0] ld_addr = 0, q_idx = 0, rd_row = 0; reg [4:0] pc_grp = 0; reg [K-1:0] ld_data = 0;
    reg iss_v = 0, iss_has = 0; reg [K-1:0] iss_pat = 0; reg [7:0] iss_pref = 0;
    wire p_v, p_has, sort_done, rd_has, pbusy, wb_v; wire [7:0] p_idx, p_prefix, rd_prefix; wire [K-1:0] p_pattern, rd_pattern;
    wire [M*8-1:0] order; wire [3:0] wsel; wire [N*AW-1:0] acc_out; wire [31:0] l_spk;
    integer tile, t, f2, fc, cyc = 0, w0, wbrow, vcd;
    integer nwin = 0, nocc = 0, nadd = 0, wocc;
    reg inwin = 0;
    wire [N*AW-1:0] pref_row = (wb_v && iss_pref == wbrow) ? acc_out : resm[iss_pref];
    prosperity_core dut(.clk(clk), .rst(rst), .ld_we(ld_we), .ld_bank(ld_bank), .ld_addr(ld_addr), .ld_data(ld_data),
        .bank(bank), .pc_v(pc_v), .pc_grp(pc_grp), .q_v(q_v), .q_idx(q_idx), .p_v(p_v), .p_idx(p_idx), .p_has(p_has),
        .p_prefix(p_prefix), .p_pattern(p_pattern), .pst_bank(pst_bank), .sort_start(sort_start), .sort_done(sort_done),
        .order_flat(order), .rd_row(rd_row), .rd_has(rd_has), .rd_prefix(rd_prefix), .rd_pattern(rd_pattern),
        .iss_v(iss_v), .iss_pattern(iss_pat), .iss_has_prefix(iss_has), .prefix_row(pref_row),
        .wrow(wts[tile*K + wsel]), .wsel(wsel), .pbusy(pbusy), .wb_v(wb_v), .acc_out(acc_out),
        .l_v(32'b0), .l_first(32'b0), .l_x({32*AW{1'b0}}), .l_spk(l_spk));
    always @(posedge clk) cyc <= cyc + 1;
    always @(posedge clk) if (inwin) begin
        nwin <= nwin + 1;
        if (iss_v || pbusy) nocc <= nocc + 1;                       // processor occupied (simulator's compute cycle)
        if ((iss_v && iss_pat != 0) || pbusy) nadd <= nadd + 1;     // 128-adder array adding a weight row
    end
    always @(posedge clk) if (!rst && wb_v) begin
        resm[wbrow] <= acc_out;
        $fwrite(f2, "%0d %0d", tile, wbrow);
        for (integer j = 0; j < N; j = j + 1) $fwrite(f2, " %0d", $signed(acc_out[j*AW +: AW]));
        $fwrite(f2, "\n");
    end
    function integer popc(input [K-1:0] x); integer b; begin popc = 0; for (b = 0; b < K; b = b + 1) popc = popc + x[b]; end endfunction

    task preload(input integer tl); integer a; begin
        for (a = 0; a < M; a = a + 1) begin
            ld_we = 1; ld_bank = tl % 2; ld_addr = a; ld_data = rows[tl*M + a]; @(negedge clk);
        end
        ld_we = 0;
    end endtask

    // detector popcount + searches, pruner -> PST bank pst_bank, sort, snapshot the issue order
    task frontend(input integer tl); integer a; begin
        bank = tl % 2;
        for (a = 0; a < M / 8; a = a + 1) begin pc_v = 1; pc_grp = a; @(negedge clk); end
        pc_v = 0;
        for (a = 0; a < M; a = a + 1) if (popc(rows[tl*M + a]) > 1) begin q_v = 1; q_idx = a; @(negedge clk); end
        q_v = 0;
        sort_start = 1; @(negedge clk); sort_start = 0;
        while (!sort_done) @(negedge clk);
        for (a = 0; a < M; a = a + 1) ordb[(tl % 2)*M + a] = order[a*8 +: 8];
    end endtask

    // processor: issue tile tl's rows in sorted order (PST read bank = ~pst_bank = tl % 2)
    task issue(input integer tl); integer a, r, pc; begin
        for (a = 0; a < M; a = a + 1) begin
            r = ordb[(tl % 2)*M + a];
            pc = popc(rows[tl*M + r]);
            if (pc > 0) begin
                rd_row = r; #0.01;
                while (pbusy) @(negedge clk);
                if (pc == 1) begin iss_has = 0; iss_pat = rows[tl*M + r]; iss_pref = 0; end
                else begin iss_has = rd_has; iss_pat = rd_pattern; iss_pref = rd_prefix; end
                iss_v = 1;
                @(posedge clk); wbrow <= r;
                @(negedge clk); iss_v = 0;
            end
        end
        while (pbusy) @(negedge clk);
        @(negedge clk);
    end endtask

    initial begin
        $readmemh("stim/prosperity/rows.hex", rows);
        $readmemh("stim/prosperity/wts.hex", wts);
        f2 = $fopen("res_prosperity_ss.txt", "w"); fc = $fopen("cyc_prosperity_ss.txt", "w");
        vcd = $test$plusargs("vcd");
        if (vcd) $dumpfile(`VCDFILE);
        tile = 0; wbrow = 0;
        repeat (3) @(negedge clk); rst = 0;
        // prologue: tile 0 ready to issue, tile 1 pre-loaded
        preload(0); pst_bank = 0; frontend(0); preload(1);
        if (vcd) $dumpvars(0, tb_prosperity.dut);
        for (t = 0; t < NT; t = t + 1) begin
            if (vcd && t > 0 && t < NT - 1) $dumpon;
            tile = t; pst_bank = (t + 1) % 2; w0 = cyc; wocc = nocc;
            inwin = (t < NT - 1);
            fork
                issue(t);
                if (t + 1 < NT) frontend(t + 1);
            join
            inwin = 0;
            $fwrite(fc, "%0d %0d %0d\n", t, cyc - w0, nocc - wocc);
            if (vcd && t < NT - 1) $dumpoff;
            if (t + 2 < NT) preload(t + 2);
        end
        $fclose(f2); $fclose(fc);
        $display("PROSPERITY_SS_DONE tiles=%0d window_cycles=%0d occupied=%0d (%0.1f%%) adding=%0d (%0.1f%%)",
                 NT, nwin, nocc, 100.0 * nocc / nwin, nadd, 100.0 * nadd / nwin);
        $finish;
    end
endmodule
