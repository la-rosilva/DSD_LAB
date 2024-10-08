module tff(Q, T, clear, clk);
    input T, clear, clk;
    output reg Q;
    
    always @(posedge clk or negedge clear) begin
        if (!clear) 
            Q <= 0;
        else if (T) 
            Q <= ~Q;
        else 
            Q <= Q;
    end
endmodule

// Synchronous Counter Module
module synchronous_counter(clear, clk, Q);
    input clear, clk;
    output [2:0] Q;
    
    tff FF0(Q[0], 1'b1, clear, clk);
    tff FF1(Q[1], Q[0], clear, clk);
    tff FF2(Q[2], Q[1] && Q[0], clear, clk);
endmodule
