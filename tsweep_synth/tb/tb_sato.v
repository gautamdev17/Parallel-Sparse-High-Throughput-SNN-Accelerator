// tb_sato.v -- plays build/stim/sato/in.hex (per-cycle PE inputs) and disp.hex (dispatcher rows, one per cycle)
// into sato_core; the adder-search tree is fed with finished integrations every 4 cycles (log2 T + 1).
// Logs PE results (res_sato.txt) and dispatcher choices (disp_sato.txt) for check_rtl.py.
`timescale 1ns/1ps
module tb_sato;
`ifndef TB_T
 `define TB_T 8
`endif
    // tsweep_synth: T = `TB_T; the tree gets a new neuron every log2(T) + 1 cycles
    localparam NPE = 128, IW = 12, AW = 16, WIDTH = 2*NPE + NPE*IW + NPE*8, NMAX = 20000, T = `TB_T, LT = $clog2(T);
    reg clk = 0, rst = 1;
    always #0.625 clk = ~clk;
    reg [WIDTH-1:0] stim [0:NMAX-1];
    reg [22:0] disp [0:NMAX-1];
    reg [WIDTH-1:0] cur = 0;
    reg [22:0] dcur = 0;
    reg a_go = 0; reg [T*AW-1:0] a_x = 0;
    wire [NPE*AW-1:0] res; wire [NPE-1:0] res_v;
    // tree input = T consecutive PE results starting at PE n % NPE, wrapping round the 128 PEs (the plain part
    // select ran past res[] for n % NPE > NPE - T: X leaves in the gate-level run, 7/128 neurons at T = 8, 31/128 at T = 32)
    wire [2*NPE*AW-1:0] res2 = {res, res}; wire [6:0] d_sel; wire d_sel_v; wire [LT:0] fire_t; wire a_done;
`ifdef GATE
    sato_core dut(
`else
    sato_core #(.T(T)) dut(
`endif
       .clk(clk), .rst(rst), .v(cur[WIDTH-1 -: NPE]), .row_end(cur[WIDTH-1-NPE -: NPE]),
        .nz_idx(cur[NPE*8 +: NPE*IW]), .w(cur[NPE*8-1:0]), .res(res), .res_v(res_v),
        .d_clr(1'b0), .d_row_v(dcur[22]), .d_bits(dcur[21:6]), .d_cnt(dcur[5:0]), .d_sel(d_sel), .d_sel_v(d_sel_v),
        .a_go(a_go), .a_x(a_x), .vth(200), .fire_t(fire_t), .a_done(a_done));
    integer n, i, fr, fd, ncyc, nd;
    always @(posedge clk) if (!rst) begin
        for (i = 0; i < NPE; i = i + 1) if (res_v[i]) $fwrite(fr, "%0d %0d\n", i, $signed(res[i*AW +: AW]));
        if (d_sel_v) $fwrite(fd, "%0d\n", d_sel);
    end
    initial begin
        $readmemh(`STIM, stim);
        $readmemh(`DISP, disp);
        ncyc = `NCYC; nd = `ND;
        fr = $fopen("res_sato.txt", "w"); fd = $fopen("disp_sato.txt", "w");
        if ($test$plusargs("vcd")) $dumpfile(`VCDFILE);
        repeat (3) @(negedge clk); rst = 0;
        if ($test$plusargs("vcd")) $dumpvars(0, tb_sato.dut);
        for (n = 0; n < ncyc; n = n + 1) begin
            cur = stim[n];
            dcur = (n < nd) ? disp[n] : 0;
            a_go = (n % (LT + 1) == 0);
            a_x = res2[(n % NPE)*AW +: T*AW];
            @(negedge clk);
        end
        cur = 0; dcur = 0; a_go = 0;
        repeat (6) @(negedge clk);
        $fclose(fr); $fclose(fd);
        $display("SATO_DONE cycles=%0d", ncyc);
        $finish;
    end
endmodule
