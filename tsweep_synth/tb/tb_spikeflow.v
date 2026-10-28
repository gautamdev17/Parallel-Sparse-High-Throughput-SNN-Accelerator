// tb_spikeflow.v (tsweep_synth copy: passes.txt header 'n seg carry', MC segment config, membrane store, LIF
// spike log lif_spikeflow.txt) -- plays build/stim/spikeflow/passes.txt into spikeflow_core: per pass, DMA-writes the entries
// into the idle buffer halves (one weight word + one spike word per cycle) while the previous pass runs, then
// announces it; logs every row's finished psums (psums_spikeflow.txt) and the cycle count.
`timescale 1ns/1ps
module tb_spikeflow;
    localparam R = 16, C = 16, PSW = 16;
    reg clk = 0, rst = 1;
    always #0.625 clk = ~clk;
    reg dma_w_we = 0, dma_s_we = 0, nxt_v = 0, nxt_carry = 0;
    reg [1:0] cfg_seg = 0;
    integer seg, cy, fl;
    // tsweep_synth: membranes stored between time chunks (T > 16), one per SA row: the 'temporary on-chip memory'
    // of Sec. 4.3.2.3, outside the core like the 18.5 KB buffer
    reg signed [PSW+1:0] vmem [0:R-1];
    wire signed [PSW+1:0] vlast; wire [3:0] lrow; wire lgo;
    always @(posedge clk) if (lgo) vmem[lrow] <= vlast;
    reg [8:0] dma_w_addr = 0; reg [10:0] dma_s_addr = 0, nxt_n = 0;
    reg [R*8-1:0] dma_w_data = 0; reg [C-1:0] dma_s_data = 0;
    wire nxt_take, busy, act;
    wire [R*C*PSW-1:0] psum; wire [R-1:0] row_done; wire [C-1:0] spk;
    wire [11:0] sram_raddr;
`ifdef SF_EXT_SRAM
    // the double-buffered SRAM outside the core: DMA writes the idle half, the core reads {act, k}
    reg [R*8-1:0] wmem [0:2047];
    reg [C-1:0]   smem [0:4095];
    always @(posedge clk) begin
        if (dma_w_we) wmem[{~act, 1'b0, dma_w_addr}] <= dma_w_data;
        if (dma_s_we) smem[{~act, dma_s_addr}] <= dma_s_data;
    end
    wire [R*8-1:0] sram_w = wmem[{sram_raddr[11], 1'b0, sram_raddr[8:0]}];
    wire [C-1:0]   sram_s = smem[sram_raddr];
`endif
    spikeflow_core dut(.clk(clk), .rst(rst), .dma_w_we(dma_w_we), .dma_w_addr(dma_w_addr), .dma_w_data(dma_w_data),
        .dma_s_we(dma_s_we), .dma_s_addr(dma_s_addr), .dma_s_data(dma_s_data), .nxt_v(nxt_v), .nxt_n(nxt_n),
        .nxt_take(nxt_take), .nxt_carry(nxt_carry), .cfg_seg(cfg_seg), .lif_vpre(vmem[lrow]), .lif_vlast(vlast),
        .lif_row(lrow), .lif_go(lgo), .busy(busy), .act(act), .vth(18'sd200), .vset(18'sd0),
        .psum_out(psum), .row_done(row_done), .lif_spk(spk)
`ifdef SF_EXT_SRAM
        , .sram_raddr(sram_raddr), .sram_wdata_rd(sram_w), .sram_sdata_rd(sram_s), .obuf_we(), .obuf_waddr()
`endif
        );
    reg lg_d = 0; reg [3:0] lr_d = 0;
    always @(posedge clk) begin lg_d <= lgo; lr_d <= lrow; end
    always @(negedge clk) if (lg_d) $fwrite(fl, "%0d %0d\n", lr_d, spk);
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
        fl = $fopen("lif_spikeflow.txt", "w");
        for (i = 0; i < R; i = i + 1) vmem[i] = 0;
        if ($test$plusargs("vcd")) $dumpfile(`VCDFILE);
        repeat (3) @(negedge clk); rst = 0;
        if ($test$plusargs("vcd")) $dumpvars(0, tb_spikeflow.dut);
        while (!$feof(fd)) begin
            code = $fscanf(fd, "%d %d %d\n", n, seg, cy);       // tsweep_synth: 'entries segment carry'
            if (code != 3) n = 0;
            cfg_seg = (seg == 4) ? 2'd0 : (seg == 8) ? 2'd1 : 2'd2;   // MC configuration (constant per layer)
            if (n > 0) begin
                // DMA this pass into the idle halves (overlaps the running pass)
                for (i = 0; i < n; i = i + 1) begin
                    code = $fscanf(fd, "%h %h\n", wv, sv);
                    @(negedge clk);
                    dma_w_we = 1; dma_w_addr = i; dma_w_data = wv; dma_s_we = 1; dma_s_addr = i; dma_s_data = sv;
                end
                @(negedge clk); dma_w_we = 0; dma_s_we = 0;
                // announce it; it starts when the running pass ends
                nxt_v = 1; nxt_n = n; nxt_carry = cy;
                @(posedge clk); while (!nxt_take) @(posedge clk);
                if (t0 < 0) t0 = cyc;
                @(negedge clk); nxt_v = 0;
                npass = npass + 1;
            end
        end
        repeat (R + C + 8) @(negedge clk);
        $fclose(fo); $fclose(fl);
        $display("SPIKEFLOW_DONE passes=%0d cycles=%0d stall_cycles=%0d", npass, tlast - t0, stalls);
        $finish;
    end
endmodule
