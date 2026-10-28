/*
Input flat weight array converted to internal array.
Find lowest '1' bit in AND result using priority encoder.
Calculate prefix sum of bitmask_b up to that position using parallel prefix sum.
Output matched position, offset, and weight.

FIX: The ParallelPrefixSum port 'position' was driven by a ternary expression:
     (lowest_one_position_reg > 0 ? lowest_one_position_reg - 1 : 0)
     DC resolves the ternary as a signed intermediate value, producing a
     width/signedness mismatch with the unsigned [$clog2(WIDTH)-1:0] port → LINK-3.
     Fix: compute the adjusted position into an explicit reg 'adj_position' and
     connect that reg directly to the port.
*/

module fast_prefix #(
    parameter BITMASK_WIDTH = 128,
    parameter WEIGHT_WIDTH = 8
)(
    input wire clk,
    input wire rst,
    input wire [BITMASK_WIDTH-1:0] and_result,
    input wire [BITMASK_WIDTH-1:0] bitmask_b,
    input wire valid_match,
    input wire [BITMASK_WIDTH*WEIGHT_WIDTH-1:0] fibre_b_data_flat,
    output reg [$clog2(BITMASK_WIDTH)-1:0] fast_offset,
    output reg [$clog2(BITMASK_WIDTH)-1:0] matched_position,
    output reg [WEIGHT_WIDTH-1:0] matched_weight,
    output reg fast_valid,
    output reg processing_done,
    output reg fast_all_matches_done
);

    wire [WEIGHT_WIDTH-1:0] fibre_b_data [0:BITMASK_WIDTH-1];

    genvar i;
    generate
        for (i = 0; i < BITMASK_WIDTH; i = i + 1) begin : gen_array
            assign fibre_b_data[i] = fibre_b_data_flat[i*WEIGHT_WIDTH +: WEIGHT_WIDTH];
        end
    endgenerate

    reg [BITMASK_WIDTH-1:0] current_and_result;
    reg [BITMASK_WIDTH-1:0] registered_bitmask_b;

    localparam IDLE           = 2'd0;
    localparam PRIORITY_ENCODE = 2'd1;
    localparam PREFIX_SUM     = 2'd2;
    localparam CLEAR_BIT      = 2'd3;

    reg [1:0] state, next_state;
    reg all_done_flag;

    reg [$clog2(BITMASK_WIDTH)-1:0] lowest_one_position_reg;

    // FIX: explicit unsigned register for the adjusted position fed to the port
    reg [$clog2(BITMASK_WIDTH)-1:0] adj_position;

    function [$clog2(BITMASK_WIDTH)-1:0] find_lowest_one;
        input [BITMASK_WIDTH-1:0] bit_vector;
        integer j;
        begin
            find_lowest_one = {$clog2(BITMASK_WIDTH){1'b1}};
            for (j = 0; j < BITMASK_WIDTH; j = j + 1) begin
                if (bit_vector[j] && (find_lowest_one == {$clog2(BITMASK_WIDTH){1'b1}})) begin
                    find_lowest_one = j[$clog2(BITMASK_WIDTH)-1:0];
                end
            end
        end
    endfunction

    wire [$clog2(BITMASK_WIDTH):0] prefix_sum_result;

    // FIX: connect adj_position (a plain reg) instead of the ternary expression
    ParallelPrefixSum #(
        .WIDTH(BITMASK_WIDTH)
    ) prefix_sum_inst (
        .bit_array(registered_bitmask_b),
        .position(adj_position),
        .prefix_sum(prefix_sum_result)
    );

    reg [$clog2(BITMASK_WIDTH):0] ones_before_position;
    reg [$clog2(BITMASK_WIDTH)-1:0] calculated_offset;
    reg [WEIGHT_WIDTH-1:0] selected_weight;

    always @(*) begin
        if (lowest_one_position_reg == 0) begin
            ones_before_position = 0;
        end
        else begin
            ones_before_position = prefix_sum_result;
        end
        calculated_offset = ones_before_position[$clog2(BITMASK_WIDTH)-1:0];
        selected_weight = fibre_b_data[calculated_offset];
    end

    // FIX: keep adj_position updated combinationally alongside lowest_one_position_reg
    always @(*) begin
        if (lowest_one_position_reg == 0)
            adj_position = {$clog2(BITMASK_WIDTH){1'b0}};
        else
            adj_position = lowest_one_position_reg - 1'b1;
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
        end
        else begin
            state <= next_state;
        end
    end

    always @(*) begin
        next_state = state;
        case (state)
            IDLE: begin
                if (valid_match)
                    next_state = PRIORITY_ENCODE;
            end
            PRIORITY_ENCODE: begin
                if (current_and_result != 0)
                    next_state = PREFIX_SUM;
                else
                    next_state = IDLE;
            end
            PREFIX_SUM: begin
                next_state = CLEAR_BIT;
            end
            CLEAR_BIT: begin
                next_state = PRIORITY_ENCODE;
            end
            default: next_state = IDLE;
        endcase
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            current_and_result    <= 0;
            registered_bitmask_b  <= 0;
            lowest_one_position_reg <= 0;
            fast_offset           <= 0;
            matched_position      <= 0;
            matched_weight        <= 0;
            fast_valid            <= 0;
            processing_done       <= 1;
            fast_all_matches_done <= 0;
            all_done_flag         <= 0;
        end
        else begin
            fast_valid <= 0;

            case (state)
                IDLE: begin
                    processing_done <= 1;
                    if (all_done_flag) begin
                        fast_all_matches_done <= 1;
                        all_done_flag <= 0;
                    end else begin
                        fast_all_matches_done <= 0;
                    end
                    if (valid_match) begin
                        current_and_result   <= and_result;
                        registered_bitmask_b <= bitmask_b;
                        processing_done      <= 0;
                        fast_all_matches_done <= 0;
                    end
                end

                PRIORITY_ENCODE: begin
                    if (current_and_result != 0) begin
                        lowest_one_position_reg <= find_lowest_one(current_and_result);
                    end
                    else begin
                        processing_done <= 1;
                    end
                end

                PREFIX_SUM: begin
                    matched_position <= lowest_one_position_reg;
                    fast_offset      <= calculated_offset;
                    matched_weight   <= selected_weight;
                    fast_valid       <= 1;
                end

                CLEAR_BIT: begin
                    current_and_result <= current_and_result & ~({{(BITMASK_WIDTH-1){1'b0}}, 1'b1} << lowest_one_position_reg);
                    if ((current_and_result & ~({{(BITMASK_WIDTH-1){1'b0}}, 1'b1} << lowest_one_position_reg)) == 0)
                        all_done_flag <= 1;
                end

                default: begin
                end
            endcase
        end
    end

endmodule

//----------------------------------------------------------------
// Parallel Prefix Sum Module
//----------------------------------------------------------------
module ParallelPrefixSum #(
    parameter WIDTH = 128
)(
    input wire [WIDTH-1:0] bit_array,
    input wire [$clog2(WIDTH)-1:0] position,
    output wire [$clog2(WIDTH):0] prefix_sum
);
    wire [$clog2(WIDTH):0] stage0 [WIDTH-1:0];

    localparam LOG2_WIDTH = $clog2(WIDTH);

    wire [$clog2(WIDTH):0] stages [0:LOG2_WIDTH][WIDTH-1:0];

    genvar i, j, k;

    generate
        for (i = 0; i < WIDTH; i = i + 1) begin: stage0_gen
            assign stage0[i] = bit_array[i] ? 1 : 0;
        end
    endgenerate

    generate
        for (i = 0; i < WIDTH; i = i + 1) begin: stage0_copy
            assign stages[0][i] = stage0[i];
        end

        for (j = 1; j <= LOG2_WIDTH; j = j + 1) begin: stages_gen
            for (k = 0; k < WIDTH; k = k + 1) begin: each_element
                if (k >= (1 << (j-1))) begin
                    assign stages[j][k] = stages[j-1][k] + stages[j-1][k - (1 << (j-1))];
                end else begin
                    assign stages[j][k] = stages[j-1][k];
                end
            end
        end
    endgenerate

    assign prefix_sum = stages[LOG2_WIDTH][position];
endmodule
