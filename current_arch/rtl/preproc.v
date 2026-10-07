// preproc.v -- pre-processing unit: packs BOTH operands of one K-slab (Mentha offline algorithm).
//
//   weights     : rows of the (mb x 4) weight slab         -> packed weight rows   (w_pk)
//   activations : columns of the (4 x nb) activation slab  -> packed act columns   (a_pk)
//
// The raw tiles live in memory (HBM/SRAM, modelled by the testbench); the two packers read them
// one vertex at a time through w_rd_* / a_rd_* (1-cycle read latency).  The two packers run in
// parallel.  `done` pulses when both are finished; w_groups / a_groups are R_total and P.
module preproc (
    input             clk,
    input             rst_n,
    input             start,
    input  [7:0]      mb,            // weight rows in the tile   (<= 64)
    input  [7:0]      nb,            // activation columns        (<= 128)
    input  [11:0]     slab,          // slab number
    input  [2:0]      keff,          // slab width
    // weight tile memory
    output [7:0]      w_rd_row,
    output [11:0]     w_rd_slab,
    input  [31:0]     w_rd_data,
    // activation tile memory
    output [7:0]      a_rd_col,
    output [11:0]     a_rd_slab,
    input  [31:0]     a_rd_data,
    output            busy,
    output reg        done,
    output [7:0]      w_groups,
    output [7:0]      a_groups,
    output [64*64-1:0]  w_pk,
    output [128*64-1:0] a_pk
);
    wire w_done, a_done, w_busy, a_busy;
    reg  wd, ad, busy_r;

    assign w_rd_slab = slab;
    assign a_rd_slab = slab;

    packer #(.NV(64),  .CAP(4)) u_wp (
        .clk(clk), .rst_n(rst_n), .start(start), .nv(mb), .keff(keff),
        .rd_v(w_rd_row), .rd_data(w_rd_data),
        .busy(w_busy), .done(w_done), .n_groups(w_groups), .pk(w_pk));

    packer #(.NV(128), .CAP(4)) u_ap (
        .clk(clk), .rst_n(rst_n), .start(start), .nv(nb), .keff(keff),
        .rd_v(a_rd_col), .rd_data(a_rd_data),
        .busy(a_busy), .done(a_done), .n_groups(a_groups), .pk(a_pk));

    assign busy = busy_r;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wd <= 1'b0; ad <= 1'b0; busy_r <= 1'b0; done <= 1'b0;
        end else begin
            done <= 1'b0;
            if (start) begin
                wd <= 1'b0; ad <= 1'b0; busy_r <= 1'b1;
            end else if (busy_r) begin
                if (w_done) wd <= 1'b1;
                if (a_done) ad <= 1'b1;
                if ((wd || w_done) && (ad || a_done)) begin
                    done <= 1'b1; busy_r <= 1'b0; wd <= 1'b0; ad <= 1'b0;
                end
            end
        end
    end
endmodule
