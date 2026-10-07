// packer.v -- Mentha's offline packing (graph colouring), done in hardware by pre-proc.
//
// One packer packs ONE operand of ONE K-slab:
//   * vertices  = the rows of the weight slab (A) or the columns of the activation slab (B),
//   * a vertex is described by a 4-bit mask: bit k = element at K-position k is nonzero,
//   * two vertices CONFLICT if their masks share a bit,
//   * all-zero vertices are dropped,
//   * groups are built greedily exactly like snn_sim.mentha_group():
//        sort vertices by (conflict degree DESC, index ASC);
//        take the first unplaced vertex as the head of a group, then walk the rest of the
//        sorted list and add every vertex that does not conflict with the group so far,
//        until the group holds CAP vertices.
//   * a group becomes one PACKED row/column: for each K-position k the element of the (at most
//     one) member that is nonzero there, stored as {index, value}.  index = vertex number + 1.
//     index 0 = empty position.
//
// How the sort is done without a sorter: the degree of a vertex depends only on its 4-bit mask
// (there are only 15 non-zero masks).  Histogram the masks, get one degree per mask value,
// then a stable counting sort on the degree puts the vertices into the order above.
//
// Memory interface: the vertex's 4 bytes of this slab are read with a 1-cycle-latency read
// (rd_v is the vertex number, rd_data the 4 bytes, byte k at [8k +: 8]).
// Output: pk[g*64 +: 64] = packed row/column g, element k at [16k +: 16] = {index[15:8], value[7:0]}.
// Packing takes many cycles here, but REPORT.md assumes it is done offline / ahead of the array,
// so the top level counts these cycles separately (cyc_pre).
module packer #(
    parameter NV  = 128,           // maximum number of vertices
    parameter CAP = 4              // Mentha threshold: members per group
) (
    input                  clk,
    input                  rst_n,
    input                  start,
    input  [7:0]           nv,     // vertices in this tile (1..NV)
    input  [2:0]           keff,   // slab width 1..4 (positions >= keff are ignored)
    output [7:0]           rd_v,
    input  [31:0]          rd_data,
    output reg             busy,
    output reg             done,   // one-cycle pulse
    output reg [7:0]       n_groups,
    output reg [NV*64-1:0] pk
);
    localparam S_IDLE = 4'd0, S_INIT = 4'd1, S_REQ = 4'd2, S_CAP = 4'd3, S_DEG = 4'd4,
               S_BK1  = 4'd5, S_PFX  = 4'd6, S_BK2 = 4'd7, S_HEAD = 4'd8, S_SCAN = 4'd9,
               S_EMIT = 4'd10, S_FIN = 4'd11;

    reg [3:0]  st;
    reg [7:0]  ctr;
    assign rd_v = ctr;

    reg [31:0] elem   [0:NV-1];     // the vertex's bytes (positions >= keff forced to 0)
    reg [3:0]  vmask  [0:NV-1];
    reg [7:0]  hist   [0:15];       // vertices per mask value
    reg [7:0]  dm     [0:15];       // degree per mask value
    reg [7:0]  dcnt   [0:NV-1];     // vertices per degree
    reg [7:0]  dstart [0:NV-1];     // counting-sort write pointer per degree
    reg [7:0]  order  [0:NV-1];     // vertices sorted by (degree desc, index asc)
    reg        alive  [0:NV-1];
    reg [7:0]  nzcnt, hp, q, ng;
    reg [2:0]  gcnt;
    reg [3:0]  gunion;
    reg [7:0]  gmem [0:3];

    integer    i, m2, u, sum, acc, g, k;
    reg [3:0]  m;
    reg [7:0]  v, d, mm, b, b0, b1, b2, b3;
    reg [63:0] row;
    reg [31:0] ev;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            st <= S_IDLE; busy <= 1'b0; done <= 1'b0; n_groups <= 8'd0;
            ctr <= 8'd0; nzcnt <= 8'd0; hp <= 8'd0; q <= 8'd0; ng <= 8'd0;
            gcnt <= 3'd0; gunion <= 4'd0;
        end else begin
            done <= 1'b0;
            case (st)
            S_IDLE: if (start) begin busy <= 1'b1; st <= S_INIT; end

            S_INIT: begin
                for (i = 0; i < 16; i = i + 1) hist[i] <= 8'd0;
                for (i = 0; i < NV; i = i + 1) dcnt[i] <= 8'd0;
                nzcnt <= 8'd0; ng <= 8'd0; hp <= 8'd0; ctr <= 8'd0;
                st <= S_REQ;
            end

            S_REQ: st <= S_CAP;                        // address is on rd_v, data arrives next cycle

            S_CAP: begin
                b0 = (keff > 0) ? rd_data[7:0]   : 8'd0;
                b1 = (keff > 1) ? rd_data[15:8]  : 8'd0;
                b2 = (keff > 2) ? rd_data[23:16] : 8'd0;
                b3 = (keff > 3) ? rd_data[31:24] : 8'd0;
                m  = {(b3 != 0), (b2 != 0), (b1 != 0), (b0 != 0)};
                elem[ctr]  <= {b3, b2, b1, b0};
                vmask[ctr] <= m;
                if (m != 0) hist[m] <= hist[m] + 8'd1;
                if (ctr == nv - 1) begin ctr <= 8'd0; st <= S_DEG; end
                else begin ctr <= ctr + 8'd1; st <= S_REQ; end
            end

            S_DEG: begin                               // degree of a mask class = vertices sharing a bit, minus itself
                for (m2 = 1; m2 < 16; m2 = m2 + 1) begin
                    sum = 0;
                    for (u = 1; u < 16; u = u + 1)
                        if ((u & m2) != 0) sum = sum + hist[u];
                    dm[m2] <= sum - 1;
                end
                st <= S_BK1;
            end

            S_BK1: begin                               // histogram of degrees
                m = vmask[ctr];
                if (m != 0) begin
                    d = dm[m];
                    dcnt[d] <= dcnt[d] + 8'd1;
                    nzcnt   <= nzcnt + 8'd1;
                end
                if (ctr == nv - 1) begin ctr <= 8'd0; st <= S_PFX; end
                else ctr <= ctr + 8'd1;
            end

            S_PFX: begin                               // start position of each degree, highest degree first
                acc = 0;
                for (i = NV - 1; i >= 0; i = i - 1) begin
                    dstart[i] <= acc;
                    acc = acc + dcnt[i];
                end
                st <= S_BK2;
            end

            S_BK2: begin                               // stable placement (vertex index ascending)
                m = vmask[ctr];
                if (m != 0) begin
                    d = dm[m];
                    order[dstart[d]] <= ctr;
                    dstart[d]        <= dstart[d] + 8'd1;
                    alive[ctr]       <= 1'b1;
                end else
                    alive[ctr]       <= 1'b0;
                if (ctr == nv - 1) begin ctr <= 8'd0; hp <= 8'd0; st <= S_HEAD; end
                else ctr <= ctr + 8'd1;
            end

            S_HEAD: begin                              // next unplaced vertex in sorted order starts a group
                if (hp >= nzcnt) st <= S_FIN;
                else begin
                    v = order[hp];
                    if (!alive[v]) hp <= hp + 8'd1;
                    else begin
                        gcnt     <= 3'd1;
                        gmem[0]  <= v;
                        gunion   <= vmask[v];
                        alive[v] <= 1'b0;
                        q        <= hp + 8'd1;
                        hp       <= hp + 8'd1;
                        st       <= (CAP == 1) ? S_EMIT : S_SCAN;
                    end
                end
            end

            S_SCAN: begin                              // add every non-conflicting vertex until the group is full
                if (q >= nzcnt || gcnt >= CAP) st <= S_EMIT;
                else begin
                    v = order[q];
                    if (alive[v] && ((vmask[v] & gunion) == 4'd0)) begin
                        gmem[gcnt] <= v;
                        gcnt       <= gcnt + 3'd1;
                        gunion     <= gunion | vmask[v];
                        alive[v]   <= 1'b0;
                    end
                    q <= q + 8'd1;
                end
            end

            S_EMIT: begin                              // build the packed row/column
                row = 64'd0;
                for (g = 0; g < 4; g = g + 1)
                    if (g < gcnt) begin
                        mm = gmem[g];
                        ev = elem[mm];
                        for (k = 0; k < 4; k = k + 1) begin
                            b = ev[8*k +: 8];
                            if (b != 8'd0) row[16*k +: 16] = {(mm + 8'd1), b};
                        end
                    end
                pk[ng*64 +: 64] <= row;
                ng <= ng + 8'd1;
                st <= S_HEAD;
            end

            S_FIN: begin
                n_groups <= ng;
                done     <= 1'b1;
                busy     <= 1'b0;
                st       <= S_IDLE;
            end

            default: st <= S_IDLE;
            endcase
        end
    end
endmodule
