`timescale 1ns / 1ps

// FIX 1: Replaced all SystemVerilog-only operators:
//   'count_ones_in_range++'  ->  'count_ones_in_range = count_ones_in_range + 1'
//   'count_ones_in_range += X' -> 'count_ones_in_range = count_ones_in_range + X'
// FIX 2: ELAB-366 multi-driver on fifo_internal_read_en_d.
//   The signal was assigned in TWO separate always blocks: its own dedicated
//   delay register block AND the main FSM reset block. DC treats this as a
//   multi-driver conflict. Removed the redundant assignment from the FSM reset;
//   the dedicated always block already handles both reset and normal operation.

module laggy_prefix #(
    parameter BITMASK_WIDTH = 128,
    parameter NUM_ADDERS = 16,
    parameter WEIGHT_WIDTH = 8,
    parameter FIFO_DEPTH = 8,
    parameter CHUNK_SIZE = BITMASK_WIDTH / NUM_ADDERS
)(
    input  wire clk,
    input  wire rst,
    input  wire [BITMASK_WIDTH-1:0] and_result,
    input  wire [BITMASK_WIDTH-1:0] bitmask_a,
    input  wire [$clog2(BITMASK_WIDTH)-1:0] matched_position,
    input  wire [WEIGHT_WIDTH-1:0] matched_weight,
    input  wire valid_match,

    input  wire fifo_mp_read_en,
    input  wire fifo_weight_read_en,

    output reg  [$clog2(BITMASK_WIDTH)-1:0] slow_offset,
    output reg  [$clog2(BITMASK_WIDTH)-1:0] current_position,
    output reg  [WEIGHT_WIDTH-1:0] current_weight,
    output reg  slow_valid,
    output reg  ready_for_new_calc,

    output wire fifo_mp_empty,
    output wire fifo_mp_full,
    output wire fifo_weight_empty,
    output wire fifo_weight_full,

    output reg  laggy_done
);

    wire fifo_write_en = valid_match && !fifo_mp_full && !fifo_weight_full;

    reg fifo_internal_read_en;
    reg fifo_internal_read_en_d;

    wire [$clog2(BITMASK_WIDTH)-1:0] fifo_mp_out;
    wire [WEIGHT_WIDTH-1:0]          fifo_weight_out;

    reg [2:0] slow_counter;
    reg [$clog2(BITMASK_WIDTH)-1:0] adder_results [NUM_ADDERS-1:0];
    reg processing;

    fifo #(
        .WIDTH($clog2(BITMASK_WIDTH)),
        .DEPTH(FIFO_DEPTH)
    ) matched_pos_fifo (
        .clk(clk),
        .rst(rst),
        .write_en(fifo_write_en),
        .read_en(fifo_mp_read_en || fifo_internal_read_en),
        .data_in(matched_position),
        .data_out(fifo_mp_out),
        .full(fifo_mp_full),
        .empty(fifo_mp_empty)
    );

    fifo #(
        .WIDTH(WEIGHT_WIDTH),
        .DEPTH(FIFO_DEPTH)
    ) weight_fifo (
        .clk(clk),
        .rst(rst),
        .write_en(fifo_write_en),
        .read_en(fifo_weight_read_en || fifo_internal_read_en),
        .data_in(matched_weight),
        .data_out(fifo_weight_out),
        .full(fifo_weight_full),
        .empty(fifo_weight_empty)
    );

    // FIX: All ++ and += replaced with explicit = ... + ...
    function automatic [$clog2(BITMASK_WIDTH)-1:0] count_ones_in_range;
        input [BITMASK_WIDTH-1:0] vector;
        input integer start_pos;
        input integer end_pos;
        integer i;
        begin
            // dac2027_sim edit for Yosys (needs constant loop bounds); same result as the original
            // `for (i = start_pos; i <= end_pos && i < BITMASK_WIDTH; i++)`
            count_ones_in_range = 0;
            for (i = 0; i < BITMASK_WIDTH; i = i + 1) begin
                if (vector[i] && i >= start_pos && i <= end_pos)
                    count_ones_in_range = count_ones_in_range + 1;
            end
        end
    endfunction

    integer i, j;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            ready_for_new_calc <= 1'b1;
        end else begin
            if (!processing && !fifo_mp_empty && !fifo_weight_empty && ready_for_new_calc) begin
                ready_for_new_calc <= 1'b0;
            end else if (processing && slow_counter == 7) begin
                ready_for_new_calc <= 1'b1;
            end
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            fifo_internal_read_en_d <= 1'b0;
        end else begin
            fifo_internal_read_en_d <= fifo_internal_read_en;
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            slow_counter <= 0;
            slow_offset <= 0;
            slow_valid <= 0;
            processing <= 0;
            fifo_internal_read_en <= 0;
            // fifo_internal_read_en_d is driven solely by its own always block above
            current_position <= 0;
            current_weight <= 0;
            for (i = 0; i < NUM_ADDERS; i = i + 1) adder_results[i] <= 0;
            laggy_done <= 0;
        end
        else begin
            fifo_internal_read_en <= 1'b0;
            slow_valid <= 1'b0;

            if (!processing && !fifo_mp_empty && !fifo_weight_empty && ready_for_new_calc) begin
                fifo_internal_read_en <= 1'b1;
            end
            else if (fifo_internal_read_en_d) begin
                current_position <= fifo_mp_out;
                current_weight <= fifo_weight_out;

                slow_counter <= 0;
                processing <= 1'b1;

                for (i = 0; i < NUM_ADDERS; i = i + 1) begin
                    j = i * CHUNK_SIZE;
                    if (j > fifo_mp_out) begin
                        adder_results[i] <= 0;
                    end
                    else if (j + CHUNK_SIZE - 1 <= fifo_mp_out) begin
                        adder_results[i] <= count_ones_in_range(bitmask_a, j, j + CHUNK_SIZE - 1);
                    end
                    else begin
                        adder_results[i] <= count_ones_in_range(bitmask_a, j, fifo_mp_out);
                    end
                end
            end
            else if (processing) begin
                slow_counter <= slow_counter + 1;

                case (slow_counter)
                    0: begin
                        for (i = 0; i < NUM_ADDERS/2; i = i + 1)
                            adder_results[i] <= adder_results[2*i] + adder_results[2*i+1];
                    end
                    1: begin
                        for (i = 0; i < NUM_ADDERS/4; i = i + 1)
                            adder_results[i] <= adder_results[2*i] + adder_results[2*i+1];
                    end
                    2: begin
                        for (i = 0; i < NUM_ADDERS/8; i = i + 1)
                            adder_results[i] <= adder_results[2*i] + adder_results[2*i+1];
                    end
                    3: begin
                        adder_results[0] <= adder_results[0] + adder_results[1];
                    end
                    7: begin
                        slow_offset <= adder_results[0];
                        slow_valid <= 1'b1;
                        processing <= 1'b0;
                    end
                    default: begin
                        // wait cycles
                    end
                endcase
            end

            if (!processing && fifo_mp_empty && fifo_weight_empty &&
                !fifo_write_en && !fifo_internal_read_en && !fifo_internal_read_en_d) begin
                laggy_done <= 1'b1;
            end else begin
                laggy_done <= 1'b0;
            end
        end
    end

endmodule


// ------------------------------------------------------
// Simple synchronous FIFO (parameterisable)
// ------------------------------------------------------
module fifo #(
    parameter WIDTH = 8,
    parameter DEPTH = 8
)(
    input  wire clk,
    input  wire rst,
    input  wire write_en,
    input  wire read_en,
    input  wire [WIDTH-1:0] data_in,
    output reg  [WIDTH-1:0] data_out,
    output reg  full,
    output reg  empty
);
    reg [WIDTH-1:0] memory [0:DEPTH-1];
    reg [$clog2(DEPTH):0] write_ptr;
    reg [$clog2(DEPTH):0] read_ptr;

    always @(*) begin
        empty = (write_ptr == read_ptr);
        full  = (write_ptr[$clog2(DEPTH)] != read_ptr[$clog2(DEPTH)] &&
                 write_ptr[$clog2(DEPTH)-1:0] == read_ptr[$clog2(DEPTH)-1:0]);
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            write_ptr <= 0;
        end else if (write_en && !full) begin
            memory[write_ptr[$clog2(DEPTH)-1:0]] <= data_in;
            write_ptr <= write_ptr + 1;
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            read_ptr <= 0;
            data_out <= 0;
        end else if (read_en && !empty) begin
            data_out <= memory[read_ptr[$clog2(DEPTH)-1:0]];
            read_ptr <= read_ptr + 1;
        end
    end

endmodule
