`timescale 1ns/1ns
`include "DFlipFlop1.v"

module DFlipFlop1_tb();
reg D,clk,reset;
wire Q;

DFlipFlop1 f1(D,clk,reset,Q);
initial
begin 
$dumpfile("DFlipFlop1_tb.vcd");
$dumpvars(0,DFlipFlop1_tb);

clk=0;
forever #20 clk=~clk;
end
initial begin
D=1; reset=0;
#20;
D=1;reset=0;
#20;
D=1;reset=0;
#20;
D=0;reset=1;
#20;
#120;
$finish
$display("Test Complete");
end
endmodule
