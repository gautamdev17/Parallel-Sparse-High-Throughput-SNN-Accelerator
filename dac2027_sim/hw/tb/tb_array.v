// tb_array.v -- plays build/stim/{ptb,spikex}/in.hex into ptb_core / spikex_core, one row per cycle.
// RTL run (+check): writes every row's psums when its integrate-and-fire unit fires 'go' -> psums.txt,
// compared against the dense reference by check_rtl.py. Gate-level run (+vcd): dumps the VCD for power.
`timescale 1ns/1ps
module tb_array;
`ifdef PTB
    localparam ROWS = 16, COLS = 8, WIDTH = 2 + 2*ROWS*8 + 16;
`else
    localparam ROWS = 8, COLS = 8, WIDTH = 2 + ROWS*8 + 8;
`endif
    localparam NMAX = 20000;
    reg clk = 0, rst = 1;
    always #0.625 clk = ~clk;
    reg [WIDTH-1:0] stim [0:NMAX-1];
    reg [WIDTH-1:0] cur = 0;
    integer n, i, fd, ncyc;
    wire [ROWS*COLS-1:0] spk;
    wire [ROWS*COLS*16-1:0] psum;
`ifdef PTB
    ptb_core dut(.clk(clk), .rst(rst), .in_v(cur[WIDTH-1]), .in_first(cur[WIDTH-2]),
                 .wa(cur[WIDTH-3 -: ROWS*8]), .wb(cur[WIDTH-3-ROWS*8 -: ROWS*8]),
                 .sa(cur[15:8]), .sb(cur[7:0]), .theta(16'sd200), .spk(spk), .psum_out(psum));
`else
    spikex_core dut(.clk(clk), .rst(rst), .in_v(cur[WIDTH-1]), .in_first(cur[WIDTH-2]),
                    .w(cur[WIDTH-3 -: ROWS*8]), .s(cur[7:0]), .theta(16'sd200), .spk(spk), .psum_out(psum));
`endif
`ifdef CHECK
    // a row's 'go' = the first flag leaving its last column (same condition as inside the core)
    genvar r;
    generate for (r = 0; r < ROWS; r = r + 1) begin : mon
        always @(posedge clk) if (!rst && dut.row[r].lif.go) begin
            $fwrite(fd, "%0d", r);
            for (i = 0; i < COLS; i = i + 1) $fwrite(fd, " %0d", $signed(psum[(r*COLS + i)*16 +: 16]));
            $fwrite(fd, "\n");
        end
    end endgenerate
`endif
    initial begin
        for (n = 0; n < NMAX; n = n + 1) stim[n] = 0;
        $readmemh(`STIM, stim);
        ncyc = `NCYC;
`ifdef CHECK
        fd = $fopen("psums.txt", "w");
`endif
        if ($test$plusargs("vcd")) $dumpfile(`VCDFILE);
        repeat (3) @(negedge clk);
        rst = 0;
        if ($test$plusargs("vcd")) $dumpvars(0, tb_array.dut);
        for (n = 0; n < ncyc; n = n + 1) begin
            cur = stim[n];
            @(negedge clk);
        end
        cur = 0;
        repeat (ROWS + COLS + 4) @(negedge clk);
`ifdef CHECK
        $fclose(fd);
`endif
        $display("ARRAY_DONE cycles=%0d", ncyc);
        $finish;
    end
endmodule
