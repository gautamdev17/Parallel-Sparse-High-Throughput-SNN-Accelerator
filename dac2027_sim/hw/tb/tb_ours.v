// tb_ours.v -- plays build/stim/ours/{inj,wl,pk}.hex into ours_core (one output tile of VGG16 b2c2),
// models the output-buffer SRAM (async read, write at the clock edge, 16 RMW ports), runs the LIF sweep over
// the dirty entries after the edge FIFOs drain, and writes obuf_ours.txt / groups_ours.txt for check_rtl.py.
// Works on the RTL and on the gate-level netlist (+vcd dumps the VCD used for power).
`timescale 1ns/1ps
module tb_ours;
    localparam R = 4, C = 4, T = 8, G = 4, PSW = 24, E = 4, NLIF = 16, PP = 8;
    localparam INJW = 222, WLW = 192, PKW = 321, NMAX = 20000, AW = 13;
    reg clk = 0, rst = 1;
    always #0.625 clk = ~clk;

    reg [INJW-1:0] inj_m [0:NMAX-1];
    reg [WLW-1:0]  wl_m  [0:NMAX-1];
    reg [PKW-1:0]  pk_m  [0:NMAX-1];
    reg [INJW-1:0] inj = 0;
    reg [WLW-1:0]  wl = 0;
    reg [PKW-1:0]  pk = 0;

    wire [C*E-1:0] obuf_we;
    wire [C*E*AW-1:0] obuf_addr;
    wire [C*E*T*PSW-1:0] obuf_rdata, obuf_wdata;
    wire [C-1:0] ovf;
    reg  [NLIF-1:0] lif_v = 0;
    reg  [NLIF*T*PSW-1:0] lif_x = 0;
    wire [NLIF*T-1:0] lif_spk;
    wire [PP+3:0] gv;
    wire [(PP+4)*R*T-1:0] gm;
    wire [(PP+4)*2*R*T-1:0] glab;
    wire [(PP+4)*G*7-1:0] gid;
    wire [(PP+4)*3-1:0] gc;

    ours_core dut(.clk(clk), .rst(rst),
        .inj_v(inj[INJW-1]), .inj_par(inj[INJW-2]), .inj_bits(inj[INJW-3 -: R*T]),
        .inj_lab(inj[INJW-3-R*T -: 2*R*T]), .inj_pid(inj[INJW-3-3*R*T -: G*7]), .inj_fid(inj[C*4*6-1:0]),
        .wl_en(wl[WLW-1 -: 16]), .wl_w(wl[WLW-17 -: 128]), .wl_f(wl[47 -: 32]), .wl_par(wl[15:0]),
        .obuf_we(obuf_we), .obuf_addr(obuf_addr), .obuf_rdata(obuf_rdata), .obuf_wdata(obuf_wdata),
        .fifo_overflow(ovf), .lif_v(lif_v), .lif_x(lif_x), .theta(24'sd200), .lif_spk(lif_spk),
        .sl_v(pk[PKW-2 -: PP]), .sl_m(pk[PKW-2-PP -: PP*R*T]), .sl_id(pk[PP*7-1:0]), .pk_flush(pk[PKW-1]),
        .pk_gv(gv), .pk_gm(gm), .pk_gl(glab), .pk_gid(gid), .pk_gc(gc));

    // ---- output buffer SRAM model
    reg [T*PSW-1:0] obuf [0:(1<<AW)-1];
    reg dirty [0:(1<<AW)-1];
    genvar q;
    generate for (q = 0; q < C*E; q = q + 1) begin : rd
        assign obuf_rdata[q*T*PSW +: T*PSW] = obuf[obuf_addr[q*AW +: AW]];
    end endgenerate
    integer ii, jj, i, j, n, conflicts = 0, rmw = 0, last_rmw = 0, cyc = 0, fg, fo, ncyc, k, nd, sweep;
    always @(posedge clk) begin
        cyc <= cyc + 1;
        if (cyc % 1000 == 0) $display("cyc %0d", cyc);
        if (cyc > `NCYC + 3000) begin $display("WATCHDOG obuf_we=%h", obuf_we); $finish; end
        for (i = 0; i < C*E; i = i + 1) if (obuf_we[i]) begin
            for (j = 0; j < i; j = j + 1)
                if (obuf_we[j] && obuf_addr[j*AW +: AW] == obuf_addr[i*AW +: AW]) conflicts = conflicts + 1;
            obuf[obuf_addr[i*AW +: AW]] <= obuf_wdata[i*T*PSW +: T*PSW];
            dirty[obuf_addr[i*AW +: AW]] <= 1'b1;
            rmw = rmw + 1;
            last_rmw = cyc;
        end
    end
    // ---- packer output log
    always @(posedge clk) if (!rst) for (i = 0; i < PP + 4; i = i + 1) if (gv[i]) begin
        for (j = 0; j < gc[i*3 +: 3]; j = j + 1) $fwrite(fg, "%0d ", gid[(i*G + j)*7 +: 7]);
        $fwrite(fg, "\n");
    end

    initial begin
        for (i = 0; i < (1<<AW); i = i + 1) begin obuf[i] = 0; dirty[i] = 0; end
        $readmemh("stim/ours/inj.hex", inj_m);
        $readmemh("stim/ours/wl.hex", wl_m);
        $readmemh("stim/ours/pk.hex", pk_m);
        ncyc = `NCYC;
        fg = $fopen("groups_ours.txt", "w");
        if ($test$plusargs("vcd")) $dumpfile(`VCDFILE);
        repeat (3) @(negedge clk);
        rst = 0;
        for (n = 0; n < ncyc; n = n + 1) begin
`ifdef WSTART
            if (n == `WSTART && $test$plusargs("vcd")) $dumpvars(0, tb_ours.dut);
`else
            if (n == 0 && $test$plusargs("vcd")) $dumpvars(0, tb_ours.dut);
`endif
            inj = inj_m[n]; wl = wl_m[n]; pk = pk_m[n];
            @(negedge clk);
        end
`ifdef WSTART
        $dumpoff; $display("WINDOW_DONE %0d cycles", ncyc - `WSTART); $finish;
`endif
        inj = 0; wl = 0; pk = 0;
        $display("PHASE stimulus done at cyc %0d rmw=%0d", cyc, rmw);
        // drain: array (R + C) and the edge FIFOs (until no RMW for 8 cycles)
        k = 0;
        while (k < 8) begin @(negedge clk); k = (obuf_we == 0) ? k + 1 : 0; end
        $display("PHASE drained at cyc %0d last_rmw=%0d", cyc, last_rmw);
        // LIF sweep over the dirty entries, 16 per cycle
        nd = 0; sweep = 0; ii = 0;
        while (ii < (1<<AW)) begin
            lif_v = 0;
            for (jj = 0; jj < NLIF && ii < (1<<AW); ii = ii + 1)
                if (dirty[ii]) begin lif_v[jj] = 1'b1; lif_x[jj*T*PSW +: T*PSW] = obuf[ii]; jj = jj + 1; nd = nd + 1; end
            if (lif_v != 0) begin sweep = sweep + 1; @(negedge clk); end
        end
        lif_v = 0;
        @(negedge clk);
        $fclose(fg);
        fo = $fopen("obuf_ours.txt", "w");
        for (ii = 0; ii < (1<<AW); ii = ii + 1) if (dirty[ii]) begin
            $fwrite(fo, "%0d %0d", ii >> 7, ii & 127);
            for (jj = 0; jj < T; jj = jj + 1) $fwrite(fo, " %0d", $signed(obuf[ii][jj*PSW +: PSW]));
            $fwrite(fo, "\n");
        end
        $fclose(fo);
        $display("OURS_DONE stim=%0d last_rmw=%0d rmw=%0d conflicts=%0d overflow=%b dirty=%0d sweep=%0d total=%0d",
                 ncyc, last_rmw, rmw, conflicts, ovf, nd, sweep, cyc);
        $finish;
    end
endmodule
