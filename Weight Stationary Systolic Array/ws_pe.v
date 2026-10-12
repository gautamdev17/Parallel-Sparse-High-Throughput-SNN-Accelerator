// =============================================================================
// ws_pe : weight-stationary processing element
//   - holds one weight (loaded once via load_w, then stationary)
//   - passes activation east, passes psum south (each registered, 1 cycle)
// =============================================================================
module ws_pe #(parameter DW = 8, AW = 24) (
    input  wire                     clk, rst_n,
    input  wire                     load_w,        // latch w_in into the weight register
    input  wire signed [DW-1:0]     w_in,
    input  wire signed [DW-1:0]     a_in,          // from the left
    input  wire signed [AW-1:0]     psum_in,       // from above
    output reg  signed [DW-1:0]     a_out,         // to the right
    output reg  signed [AW-1:0]     psum_out       // to below
);
    reg signed [DW-1:0] w;                         // <-- the STATIONARY weight

    always @(posedge clk) begin
        if (!rst_n) begin
            w <= 0; a_out <= 0; psum_out <= 0;
        end else begin
            if (load_w) w <= w_in;                 // only changes when loading
            a_out    <= a_in;                      // pass activation east (1 cycle)
            psum_out <= psum_in + w * a_in;        // MAC, pass sum south (1 cycle)
        end
    end
endmodule