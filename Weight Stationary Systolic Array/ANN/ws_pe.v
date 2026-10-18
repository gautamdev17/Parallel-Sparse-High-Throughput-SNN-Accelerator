// =============================================================================
// ws_pe : weight-stationary processing element
//   - holds one weight (loaded once via load_w, then stationary)
//   - activation  : in from ABOVE,  out to BELOW   (registered, 1 cycle)
//   - partial sum : in from LEFT,   out to RIGHT   (registered, 1 cycle, += w*a)
// =============================================================================
module ws_pe #(parameter DW = 8, AW = 24) (
    input  wire                     clk, rst_n,
    input  wire                     load_w,        // latch w_in into the weight register
    input  wire signed [DW-1:0]     w_in,
    input  wire signed [DW-1:0]     a_in,          // activation from above
    input  wire signed [AW-1:0]     psum_in,       // partial sum from the left
    output reg  signed [DW-1:0]     a_out,         // activation to below
    output reg  signed [AW-1:0]     psum_out       // partial sum to the right
);
    reg signed [DW-1:0] w;                         // <-- the STATIONARY weight

    always @(posedge clk) begin
        if (!rst_n) begin
            w <= 0; a_out <= 0; psum_out <= 0;
        end else begin
            if (load_w) w <= w_in;                 // only changes when loading
            a_out    <= a_in;                      // pass activation south (1 cycle)
            psum_out <= psum_in + w * a_in;        // MAC, pass sum east   (1 cycle)
        end
    end
endmodule