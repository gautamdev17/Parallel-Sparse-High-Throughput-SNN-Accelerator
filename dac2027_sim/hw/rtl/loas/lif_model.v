`timescale 1ns/1ps

module lif_model #(
    parameter T = 8,
    parameter Q = 12
)(
    input  wire               clk,
    input  wire               rst,

    input  wire               start,
    input  wire               result_val,

    // Flattened per-timestep inputs (8 timesteps)
    input  wire [Q-1:0]       input_0,
    input  wire [Q-1:0]       input_1,
    input  wire [Q-1:0]       input_2,
    input  wire [Q-1:0]       input_3,
    input  wire [Q-1:0]       input_4,
    input  wire [Q-1:0]       input_5,
    input  wire [Q-1:0]       input_6,
    input  wire [Q-1:0]       input_7,

    input  wire [Q-1:0]       threshold,

    output reg  [T-1:0]       spike_out,
    output reg                lif_done
);

    // FSM
    localparam IDLE = 2'd0;
    localparam CALC = 2'd1;
    localparam DONE = 2'd2;

    reg [1:0] state, next_state;

    // Internal latched inputs (array)
    reg [Q-1:0] in_vec [0:T-1];

    reg [Q-1:0] mem_potential;
    reg [Q-1:0] next_potential;

    reg [$clog2(T):0] timestep;

    // next-state combinational
    always @(*) begin
        next_state = state;
        case (state)
            IDLE: if (result_val) next_state = CALC;
            CALC: if (timestep == T) next_state = DONE;
            DONE: if (result_val) next_state = CALC;
        endcase
    end

    // sequential
    integer i;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state          <= IDLE;
            timestep       <= 0;
            mem_potential  <= 0;
            spike_out      <= 0;
            lif_done       <= 0;
            for (i = 0; i < T; i = i + 1) in_vec[i] <= 0;
        end else begin
            state    <= next_state;
            lif_done <= 1'b0;

            case (state)
                IDLE: begin
                    timestep <= 0;
                    if (result_val) begin
                        // latch flattened inputs into array
                        in_vec[0]  <= input_0;
                        in_vec[1]  <= input_1;
                        in_vec[2]  <= input_2;
                        in_vec[3]  <= input_3;
                        in_vec[4]  <= input_4;
                        in_vec[5]  <= input_5;
                        in_vec[6]  <= input_6;
                        in_vec[7]  <= input_7;

                        mem_potential <= 0;
                        spike_out     <= {T{1'b0}};
                        $display("[LIF] START at time %0t threshold=%0d", $time, threshold);
                    end
                end

                CALC: begin
                    if (timestep < T) begin
                        if (timestep == 0) next_potential = mem_potential + in_vec[0];
                        else if (spike_out[timestep-1]) next_potential = in_vec[timestep];
                        else next_potential = mem_potential + in_vec[timestep];

                        spike_out[timestep] <= (next_potential > threshold);
                        mem_potential       <= next_potential;

                        $display("[LIF] t=%0d time=%0t next_pot=%0d spike=%0d",
                                 timestep, $time, next_potential,
                                 (next_potential > threshold));

                        timestep <= timestep + 1;
                    end
                end

                DONE: begin
                    lif_done <= 1'b1;
                end
            endcase
        end
    end

endmodule
