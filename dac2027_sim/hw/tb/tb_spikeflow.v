// tb_spikeflow.v -- plays build/stim/spikeflow/passes.txt into spikeflow_core: per pass, DMA-writes the entries
// into the idle buffer halves (one weight word + one spike word per cycle) while the previous pass runs, then
// announces it; logs every row's finished psums (psums_spikeflow.txt) and the cycle count.
`timescale 1ns/1ps
module tb_spikeflow;
    localparam R = 16, C = 16, PSW = 16;
    reg clk = 0, rst = 1;
    always #0.625 clk = ~clk;
    reg dma_w_we = 0, dma_s_we = 0, nxt_v = 0;
    reg [8:0] dma_w_addr = 0; reg [10:0] dma_s_addr = 0, nxt_n = 0;
    reg [R*8-1:0] dma_w_data = 0; reg [C-1:0] dma_s_data = 0;
    wire nxt_take, busy, act;
    wire [R*C*PSW-1:0] psum; wire [R-1:0] row_done; wire [C-1:0] spk;
    spikeflow_core dut(.clk(clk), .rst(rst), .dma_w_we(dma_w_we), .dma_w_addr(dma_w_addr), .dma_w_data(dma_w_data),
        .dma_s_we(dma_s_we), .dma_s_addr(dma_s_addr), .dma_s_data(dma_s_data), .nxt_v(nxt_v), .nxt_n(nxt_n),
        .nxt_take(nxt_take), .busy(busy), .act(act), .vth(18'sd200), .vset(18'sd0),
        .psum_out(psum), .row_done(row_done), .lif_spk(spk));
    integer fd, fo, n, i, r, c, cyc = 0, t0 = -1, tlast = 0, stalls = 0, npass = 0, code;
    reg [R*8-1:0] wv; reg [C-1:0] sv;
    always @(posedge clk) cyc <= cyc + 1;
    always @(posedge clk) if (!rst) for (r = 0; r < R; r = r + 1) if (row_done[r]) begin
        $fwrite(fo, "%0d", r);
        for (c = 0; c < C; c = c + 1) $fwrite(fo, " %0d", $signed(psum[(r*C + c)*PSW +: PSW]));
        $fwrite(fo, "\n");
        tlast = cyc;
    end
    always @(posedge clk) if (!rst && t0 >= 0 && !busy && !nxt_take) stalls = stalls + 1;
    initial begin
        fd = $fopen("stim/spikeflow/passes.txt", "r");
        fo = $fopen("psums_spikeflow.txt", "w");
        if ($test$plusargs("vcd")) $dumpfile(`VCDFILE);
        repeat (3) @(negedge clk); rst = 0;
        if ($test$plusargs("vcd")) $dumpvars(0, tb_spikeflow.dut);
        while (!$feof(fd)) begin
            code = $fscanf(fd, "%d\n", n);
            if (code != 1) n = 0;
            if (n > 0) begin
                // DMA this pass into the idle halves (overlaps the running pass)
                for (i = 0; i < n; i = i + 1) begin
                    code = $fscanf(fd, "%h %h\n", wv, sv);
                    @(negedge clk);
                    dma_w_we = 1; dma_w_addr = i; dma_w_data = wv; dma_s_we = 1; dma_s_addr = i; dma_s_data = sv;
                end
                @(negedge clk); dma_w_we = 0; dma_s_we = 0;
                // announce it; it starts when the running pass ends
                nxt_v = 1; nxt_n = n;
                @(posedge clk); while (!nxt_take) @(posedge clk);
                if (t0 < 0) t0 = cyc;
                @(negedge clk); nxt_v = 0;
                npass = npass + 1;
            end
        end
        repeat (R + C + 8) @(negedge clk);
        $fclose(fo);
        $display("SPIKEFLOW_DONE passes=%0d cycles=%0d stall_cycles=%0d", npass, tlast - t0, stalls);
        $finish;
    end
endmodule
