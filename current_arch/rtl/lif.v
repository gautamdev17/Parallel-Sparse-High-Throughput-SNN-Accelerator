// lif.v -- the one-cycle neuron (file is called "lif" as requested; the behaviour is IF with
// soft reset, i.e. LIF with no leak, exactly as in REPORT.md section 3 / snn_sim.if_scalar):
//
//     v = 0
//     for t in 0..T-1:   v += sums[t];   if (v > theta) { spike[t] = 1; v -= theta; }
//
// All T steps are unrolled combinationally.  The result is registered once, so the neuron
// costs exactly one clock cycle between "sums presented" and "spikes visible".
// theta is non-negative, so a zero sum never fires.
//
// A tag (the output coordinates) rides along with the data through the output register.
module lif #(
    parameter T    = 8,
    parameter SUMW = 24,       // width of one timestep sum at the input
    parameter THW  = 24,       // threshold width (unsigned, >= 0)
    parameter TAGW = 16
) (
    input                  clk,
    input                  rst_n,
    input                  in_valid,
    input  [T*SUMW-1:0]    sums,        // sums[t] at [t*SUMW +: SUMW], signed
    input  [THW-1:0]       theta,
    input  [TAGW-1:0]      tag_in,
    output reg             out_valid,
    output reg [T-1:0]     spikes,      // bit t = spike at timestep t
    output reg [TAGW-1:0]  tag_out
);
    localparam VW = SUMW + 4;           // membrane: sum of 8 sums needs 3 more bits, +1 for the subtract

    reg signed [VW-1:0]  v;
    reg signed [THW:0]   th;
    reg [T-1:0]          sp;
    integer t;

    always @* begin
        v  = 0;
        sp = 0;
        th = {1'b0, theta};
        for (t = 0; t < T; t = t + 1) begin
            v = v + $signed(sums[t*SUMW +: SUMW]);
            if (v > th) begin
                sp[t] = 1'b1;
                v     = v - th;
            end
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            out_valid <= 1'b0;
            spikes    <= {T{1'b0}};
            tag_out   <= {TAGW{1'b0}};
        end else begin
            out_valid <= in_valid;
            spikes    <= in_valid ? sp : {T{1'b0}};
            tag_out   <= tag_in;
        end
    end
endmodule
