// pe.v -- one processing element of the weight-stationary dual-sparse array.
//
// State: one stationary weight (w_val) with its row index (w_idx; 0 = zero weight).
// Every cycle (when en = 1) it sees
//   * an activation element from above: {a_valid, a_idx, a_mask}
//       a_valid = a packed column is passing here (the "token"); a_idx = 0 means the
//       element is an all-zero mask,
//   * a psum SET from the left: up to SLOTS entries {valid, ridx, cidx, sums[T]}.
// Rules (REPORT.md stage 5):
//   * w_idx == 0 or a_idx == 0       -> skip and pass: the set goes on unchanged.
//   * otherwise search the set for the key (w_idx, a_idx):
//       hit  -> add into that slot,
//       miss -> take the lowest free slot.
//     Adding means: for every timestep t with a_mask[t] == 1, sums[t] += w_val.
//     All T gated adders work in the same cycle.
// The activation moves down one register, the set moves right one register.
//
// err_slot : the set needed a 5th slot (cannot happen; checked by the testbench)
// err_align: activation token and psum-set token disagree (cannot happen)
`include "snn_defs.vh"
module pe (
    input                       clk,
    input                       rst_n,
    input                       en,         // advance (array not frozen)
    input                       clr,        // clear the pipeline registers (weights stay)
    // weight load
    input                       ld_clr,     // zero the stationary weight
    input                       ld_en,      // write the stationary weight
    input  [`IDXW-1:0]          ld_idx,
    input  [`VALW-1:0]          ld_val,
    // activation from above
    input                       a_valid,
    input  [`IDXW-1:0]          a_idx,
    input  [`TS-1:0]            a_mask,
    // psum set from the left
    input                       s_valid,
    input  [`SETW-1:0]          s_in,
    // registered outputs
    output reg                  ao_valid,
    output reg [`IDXW-1:0]      ao_idx,
    output reg [`TS-1:0]        ao_mask,
    output reg                  so_valid,
    output reg [`SETW-1:0]      s_out,
    output                      err_slot,
    output                      err_align
);
    reg [`IDXW-1:0] w_idx;
    reg [`VALW-1:0] w_val;

    reg [`SETW-1:0] nxt;
    reg             hit, freef, bad;
    integer         s, t, hs, fs, sel;
    reg signed [`SUMW-1:0] old, ws;

    always @* begin
        nxt   = s_in;
        hit   = 1'b0;
        freef = 1'b0;
        bad   = 1'b0;
        hs    = 0;
        fs    = 0;
        sel   = 0;
        if (a_valid && w_idx != 0 && a_idx != 0) begin
            for (s = 0; s < `SLOTS; s = s + 1)
                if (s_in[s*`ENTW] &&
                    s_in[s*`ENTW + 1 +: `IDXW]         == w_idx &&
                    s_in[s*`ENTW + 1 + `IDXW +: `IDXW] == a_idx) begin
                    hit = 1'b1;
                    hs  = s;
                end
            for (s = `SLOTS - 1; s >= 0; s = s - 1)
                if (!s_in[s*`ENTW]) begin
                    freef = 1'b1;
                    fs    = s;
                end
            if (hit || freef) begin
                sel = hit ? hs : fs;
                nxt[sel*`ENTW]                         = 1'b1;
                nxt[sel*`ENTW + 1 +: `IDXW]            = w_idx;
                nxt[sel*`ENTW + 1 + `IDXW +: `IDXW]    = a_idx;
                ws = $signed(w_val);
                for (t = 0; t < `TS; t = t + 1)
                    if (a_mask[t]) begin
                        old = s_in[sel*`ENTW + 1 + 2*`IDXW + t*`SUMW +: `SUMW];
                        nxt[sel*`ENTW + 1 + 2*`IDXW + t*`SUMW +: `SUMW] = old + ws;
                    end
            end else begin
                bad = 1'b1;
            end
        end
    end

    assign err_slot  = bad;
    assign err_align = (a_valid != s_valid);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            w_idx    <= 0;
            w_val    <= 0;
            ao_valid <= 1'b0;
            ao_idx   <= 0;
            ao_mask  <= 0;
            so_valid <= 1'b0;
            s_out    <= 0;
        end else begin
            if (ld_clr) begin
                w_idx <= 0;
                w_val <= 0;
            end
            if (ld_en) begin
                w_idx <= ld_idx;
                w_val <= ld_val;
            end
            if (clr) begin
                ao_valid <= 1'b0;
                so_valid <= 1'b0;
                s_out    <= 0;
            end else if (en) begin
                ao_valid <= a_valid;
                ao_idx   <= a_idx;
                ao_mask  <= a_mask;
                so_valid <= a_valid;
                s_out    <= a_valid ? nxt : {`SETW{1'b0}};
            end
        end
    end
endmodule
