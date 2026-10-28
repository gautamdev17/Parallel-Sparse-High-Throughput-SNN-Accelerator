// tb_sato_tree.v (tsweep_synth) -- unit test of the generalised SATO adder-search tree: non-negative integrations,
// fire_t must equal the first timestep whose prefix sum exceeds Vth (T if none).  iverilog -Ptb.T=<T> tb_sato_tree.v ../rtl/sato/sato_core.v
module tb; parameter T = 8; localparam AW = 16, LT = $clog2(T);
reg clk = 0, rst = 1, go = 0; reg [T*AW-1:0] x; wire [LT:0] f; wire done;
sato_adder_search #(.T(T), .AW(AW)) u(.clk(clk), .rst(rst), .go(go), .x(x), .vth(200), .fire_t(f), .done(done));
always #1 clk = ~clk;
integer n, t, cum, exp, bad = 0, seed = 7;
initial begin
  #4 rst = 0;
  for (n = 0; n < 300; n = n + 1) begin
    cum = 0; exp = T;
    for (t = 0; t < T; t = t + 1) begin x[t*AW +: AW] = $urandom(seed) % 60; cum = cum + x[t*AW +: AW]; if (cum > 200 && exp == T) exp = t; end
    @(negedge clk) go = 1; @(negedge clk) go = 0;
    while (!done) @(negedge clk);
    if (f != exp) bad = bad + 1;
  end
  $display("T=%0d tree mismatches %0d / 300", T, bad); $finish;
end
endmodule
