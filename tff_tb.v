

`timescale 1ns/1ns
`include "tff.v"


module tff_tb;
    reg clear, clk;
    wire [2:0] Q;

    
    synchronous_counter uut(clear, clk, Q);

    always #10 clk = ~clk;

    initial begin
        clear = 0; 
        clk = 1;  
        #12 clear = 1; 
        #150 $finish; 
    end

    initial begin
        $dumpfile("tff.vcd");
        $dumpvars(0, tff_tb);
        $monitor($time, " clear=%b, Q=%3b", clear, Q);
    end
endmodule

