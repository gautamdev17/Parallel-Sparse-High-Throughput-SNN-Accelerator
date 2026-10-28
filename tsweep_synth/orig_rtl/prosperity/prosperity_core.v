// prosperity_core.v -- Prosperity PPU (prosperity.pdf, HPCA'25, Fig. 5, Tbl. III), equivalent to the official
// simulator (third_party/prosperity simulator.py run_fc + find_product_sparsity):
//   tile m = 256 spike rows x k = 16 columns, n = 128 output channels.
//   Detector  : double-buffered TCAM 256 x 16 (pre-load overlaps); 8 popcount units -> NO of every row
//               (m / 8 cycles); then one TCAM search per row with NO > 1 (subset index SI, rows with NO < 2 are
//               not searched, as in the simulator): preprocess = m/8 + #searched rows cycles.
//   Pruner    : proper-subset filter (drop exact matches with index >= query), argmax of NO (first index on
//               ties, like torch.max), XOR -> ProSparsity pattern.
//   Dispatcher: double-buffered product-sparsity table (prefix, pattern), iterative bitonic sorter
//               (128 compare-exchange units, one stage per cycle, 36 stages) on {NO, index} = stable order.
//   Processor : 128 8-bit-add PEs; per issued row: start from the prefix row's tile result (from the output
//               buffer), add one weight row (128 weights) per set pattern bit (bit-scan-forward decoder);
//               cycles = popcount(pattern), 1 for an exact match, 0 for an all-zero row (simulator rule).
//   Spiking neuron array: 32 LIF cells.
// Spike / weight / output buffers are SRAM outside the core (same exclusion as for every design).
`timescale 1ns/1ps

module pr_detector #(parameter M = 256, K = 16) (
    input  wire clk, rst,
    input  wire          ld_we, ld_bank,
    input  wire [7:0]    ld_addr,
    input  wire [K-1:0]  ld_data,
    input  wire          bank,          // bank searched
    input  wire          pc_v,          // popcount phase: 8 rows per cycle
    input  wire [4:0]    pc_grp,
    input  wire          q_v,           // search phase
    input  wire [7:0]    q_idx,
    output reg  [M-1:0]  si,            // subset index vector of the query (registered)
    output reg  [7:0]    si_idx,
    output reg           si_v,
    output wire [M*5-1:0] no_flat,
    output wire [K-1:0]  q_bits,
    output wire [K*M-1:0] tcam_flat
);
    reg [K-1:0] tcam [0:1][0:M-1];
    reg [4:0] no [0:M-1];
    integer i, j;
    always @(posedge clk) if (ld_we) tcam[ld_bank][ld_addr] <= ld_data;
    genvar g;
    generate for (g = 0; g < M; g = g + 1) begin : nf
        assign no_flat[g*5 +: 5] = no[g];
        assign tcam_flat[g*K +: K] = tcam[bank][g];
    end endgenerate
    assign q_bits = tcam[bank][q_idx];
    reg [4:0] pc;
    always @(posedge clk or posedge rst) begin
        if (rst) begin si <= 0; si_v <= 0; si_idx <= 0; for (i = 0; i < M; i = i + 1) no[i] <= 0; end
        else begin
            if (pc_v)
                for (i = 0; i < 8; i = i + 1) begin
                    pc = 0;
                    for (j = 0; j < K; j = j + 1) pc = pc + tcam[bank][pc_grp*8 + i][j];
                    no[pc_grp*8 + i] <= pc;
                end
            si_v <= q_v;
            si_idx <= q_idx;
            if (q_v)
                for (i = 0; i < M; i = i + 1)               // ternary search: query 1s masked to X
                    si[i] <= ((tcam[bank][i] & ~tcam[bank][q_idx]) == 0);
        end
    end
endmodule

module pr_pruner #(parameter M = 256, K = 16) (
    input  wire clk, rst,
    input  wire          si_v,
    input  wire [M-1:0]  si,
    input  wire [7:0]    q_idx,
    input  wire [M*5-1:0] no_flat,
    input  wire [K*M-1:0] tcam_flat,
    output reg           p_v,
    output reg  [7:0]    p_idx,
    output reg           p_has,         // a prefix was found
    output reg  [7:0]    p_prefix,
    output reg  [K-1:0]  p_pattern
);
    reg [4:0] bestv; reg [7:0] besti; reg found;
    reg [4:0] nq;
    reg [K-1:0] qb;
    integer i;
    always @(*) begin
        nq = no_flat[q_idx*5 +: 5];
        qb = tcam_flat[q_idx*K +: K];
        found = 0; bestv = 0; besti = 0;
        for (i = 0; i < M; i = i + 1)
            if (si[i] && !((no_flat[i*5 +: 5] == nq) && (i >= q_idx)) && (no_flat[i*5 +: 5] > bestv)) begin
                bestv = no_flat[i*5 +: 5]; besti = i; found = 1;      // strict '>' keeps the first index
            end
    end
    always @(posedge clk or posedge rst) begin
        if (rst) begin p_v <= 0; p_idx <= 0; p_has <= 0; p_prefix <= 0; p_pattern <= 0; end
        else begin
            p_v <= si_v; p_idx <= q_idx;
            p_has <= found;
            p_prefix <= besti;
            p_pattern <= found ? (qb ^ tcam_flat[besti*K +: K]) : qb;
        end
    end
endmodule

// stable issue order: iterative bitonic sort of {NO, index}, one of the 36 stages per cycle
module pr_sorter #(parameter M = 256) (
    input  wire clk, rst,
    input  wire          start,
    input  wire [M*5-1:0] no_flat,
    output reg           done,
    output wire [M*8-1:0] order_flat
);
    reg [12:0] key [0:M-1];
    reg [3:0] kk, jj;        // k = 2^kk (1..8), j = 2^jj
    reg busy;
    integer i;
    genvar g;
    generate for (g = 0; g < M; g = g + 1) begin : of
        assign order_flat[g*8 +: 8] = key[g][7:0];
    end endgenerate
    reg [12:0] nk [0:M-1];
    always @(*) begin
        for (i = 0; i < M; i = i + 1) nk[i] = key[i];
        for (i = 0; i < M; i = i + 1)
            if ((i & (1 << jj)) == 0) begin
                if ((((i >> kk) & 1) == 0) ? (key[i] > key[i | (1 << jj)]) : (key[i] < key[i | (1 << jj)])) begin
                    nk[i] = key[i | (1 << jj)]; nk[i | (1 << jj)] = key[i];
                end
            end
    end
    always @(posedge clk or posedge rst) begin
        if (rst) begin busy <= 0; done <= 0; kk <= 1; jj <= 0; for (i = 0; i < M; i = i + 1) key[i] <= 0; end
        else begin
            done <= 0;
            if (start) begin
                busy <= 1; kk <= 1; jj <= 0;
                for (i = 0; i < M; i = i + 1) key[i] <= {no_flat[i*5 +: 5], i[7:0]};
            end else if (busy) begin
                for (i = 0; i < M; i = i + 1) key[i] <= nk[i];
                if (jj == 0) begin
                    if (kk == 8) begin busy <= 0; done <= 1; end
                    else begin kk <= kk + 1; jj <= kk; end
                end else jj <= jj - 1;
            end
        end
    end
endmodule

module pr_processor #(parameter N = 128, K = 16, AW = 16) (
    input  wire clk, rst,
    input  wire              iss_v,          // issue a row (only when !busy)
    input  wire [K-1:0]      iss_pattern,
    input  wire              iss_has_prefix,
    input  wire [N*AW-1:0]   prefix_row,     // tile result of the prefix row (output buffer read)
    input  wire [N*8-1:0]    wrow,           // weight row selected by wsel (weight buffer read, same cycle)
    output reg  [3:0]        wsel,
    output wire              busy,
    output reg               wb_v,           // write back the finished row (output buffer write)
    output reg  [N*AW-1:0]   acc_out
);
    // one weight row per cycle; the first addition happens in the issue cycle, so a row takes
    // popcount(pattern) cycles (1 for an exact match), the simulator's rule
    reg [N*AW-1:0] acc, base, sum;
    reg [K-1:0] pat, src, rem;
    reg active;
    assign busy = active;
    integer i;
    reg any;
    always @(*) begin
        src = iss_v ? iss_pattern : pat;
        wsel = 0; any = 0;
        for (i = K - 1; i >= 0; i = i - 1) if (src[i]) begin wsel = i; any = 1; end
        rem = src & ~(16'b1 << wsel);
        base = iss_v ? (iss_has_prefix ? prefix_row : {N*AW{1'b0}}) : acc;
        for (i = 0; i < N; i = i + 1)
            sum[i*AW +: AW] = base[i*AW +: AW] + {{(AW-8){wrow[i*8+7]}}, wrow[i*8 +: 8]};
    end
    always @(posedge clk or posedge rst) begin
        if (rst) begin acc <= 0; pat <= 0; active <= 0; wb_v <= 0; acc_out <= 0; end
        else begin
            wb_v <= 0;
            if (iss_v && iss_pattern == 0) begin         // exact match: copy the prefix result
                wb_v <= 1; acc_out <= prefix_row; active <= 0;
            end else if ((iss_v || active) && any) begin
                if (rem == 0) begin wb_v <= 1; acc_out <= sum; active <= 0; end
                else begin acc <= sum; pat <= rem; active <= 1; end
            end
        end
    end
endmodule

module pr_lif #(parameter NL = 32, AW = 16) (
    input  wire clk, rst,
    input  wire [NL-1:0]     v, first,
    input  wire [NL*AW-1:0]  x,
    input  wire signed [AW+1:0] vth,
    output reg  [NL-1:0]     spk
);
    reg signed [AW+1:0] vm [0:NL-1];
    reg signed [AW+1:0] nv;
    integer i;
    always @(posedge clk or posedge rst) begin
        if (rst) begin spk <= 0; for (i = 0; i < NL; i = i + 1) vm[i] <= 0; end
        else for (i = 0; i < NL; i = i + 1) if (v[i]) begin
            nv = (first[i] ? 0 : vm[i]) + $signed(x[i*AW +: AW]);
            spk[i] <= (nv >= vth);
            vm[i] <= (nv >= vth) ? 0 : nv;
        end
    end
endmodule

module prosperity_core #(parameter M = 256, K = 16, N = 128, AW = 16, NL = 32) (
    input  wire clk, rst,
    // detector
    input  wire ld_we, ld_bank, input wire [7:0] ld_addr, input wire [K-1:0] ld_data,
    input  wire bank, pc_v, input wire [4:0] pc_grp, input wire q_v, input wire [7:0] q_idx,
    output wire p_v, output wire [7:0] p_idx, output wire p_has, output wire [7:0] p_prefix, output wire [K-1:0] p_pattern,
    // dispatcher: product sparsity table (double-buffered) + sorter
    input  wire pst_bank, sort_start, output wire sort_done, output wire [M*8-1:0] order_flat,
    input  wire [7:0] rd_row, output wire rd_has, output wire [7:0] rd_prefix, output wire [K-1:0] rd_pattern,
    // processor
    input  wire iss_v, input wire [K-1:0] iss_pattern, input wire iss_has_prefix,
    input  wire [N*AW-1:0] prefix_row, input wire [N*8-1:0] wrow, output wire [3:0] wsel,
    output wire pbusy, output wire wb_v, output wire [N*AW-1:0] acc_out,
    // LIF
    input  wire [NL-1:0] l_v, l_first, input wire [NL*AW-1:0] l_x, output wire [NL-1:0] l_spk
);
    wire [M-1:0] si; wire [7:0] si_idx; wire si_v; wire [M*5-1:0] no_flat; wire [K-1:0] qb; wire [K*M-1:0] tf;
    pr_detector #(.M(M), .K(K)) det (.clk(clk), .rst(rst), .ld_we(ld_we), .ld_bank(ld_bank), .ld_addr(ld_addr),
        .ld_data(ld_data), .bank(bank), .pc_v(pc_v), .pc_grp(pc_grp), .q_v(q_v), .q_idx(q_idx), .si(si),
        .si_idx(si_idx), .si_v(si_v), .no_flat(no_flat), .q_bits(qb), .tcam_flat(tf));
    pr_pruner #(.M(M), .K(K)) pru (.clk(clk), .rst(rst), .si_v(si_v), .si(si), .q_idx(si_idx), .no_flat(no_flat),
        .tcam_flat(tf), .p_v(p_v), .p_idx(p_idx), .p_has(p_has), .p_prefix(p_prefix), .p_pattern(p_pattern));
    // product sparsity table: 2 x 256 x (valid + prefix 8 + pattern 16) = 2 x 6400 bits (~1.5 KB)
    reg [K+8:0] pst [0:1][0:M-1];
    always @(posedge clk) if (p_v) pst[pst_bank][p_idx] <= {p_has, p_prefix, p_pattern};
    assign {rd_has, rd_prefix, rd_pattern} = pst[~pst_bank][rd_row];
    pr_sorter #(.M(M)) srt (.clk(clk), .rst(rst), .start(sort_start), .no_flat(no_flat), .done(sort_done),
        .order_flat(order_flat));
    pr_processor #(.N(N), .K(K), .AW(AW)) proc (.clk(clk), .rst(rst), .iss_v(iss_v), .iss_pattern(iss_pattern),
        .iss_has_prefix(iss_has_prefix), .prefix_row(prefix_row), .wrow(wrow), .wsel(wsel), .busy(pbusy),
        .wb_v(wb_v), .acc_out(acc_out));
    pr_lif #(.NL(NL), .AW(AW)) lif (.clk(clk), .rst(rst), .v(l_v), .first(l_first), .x(l_x), .vth(18'sd200), .spk(l_spk));
endmodule
