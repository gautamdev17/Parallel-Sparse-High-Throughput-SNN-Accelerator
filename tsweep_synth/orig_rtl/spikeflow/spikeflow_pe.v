// SpikeFlow PE (Spikeflow.pdf Fig. 10, Sec. 4.3.1): output-stationary; the 1-bit input spike enables the
// accumulator (weight added when the spike is 1); weight passes right, spike passes down.
// Widths are not given in the paper: 8-bit weight, 16-bit psum assumed. common_pe: 8-bit input x 8-bit weight MAC.
module spikeflow_pe (input clk, rst, input [7:0] w_in, input s_in, output reg [7:0] w_out, output reg s_out,
                     output reg [15:0] psum);
    always @(posedge clk or posedge rst)
        if (rst) begin w_out <= 0; s_out <= 0; psum <= 0; end
        else begin w_out <= w_in; s_out <= s_in; if (s_in) psum <= psum + {{8{w_in[7]}}, w_in}; end
endmodule
module common_pe (input clk, rst, input [7:0] w_in, input [7:0] a_in, output reg [7:0] w_out, output reg [7:0] a_out,
                  output reg [15:0] psum);
    always @(posedge clk or posedge rst)
        if (rst) begin w_out <= 0; a_out <= 0; psum <= 0; end
        else begin w_out <= w_in; a_out <= a_in; psum <= psum + $signed(w_in) * $signed(a_in); end
endmodule
