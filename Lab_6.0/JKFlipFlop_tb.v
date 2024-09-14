`timescale 1ns/1ns
`include "JKFlipFlop.v"
module JKFlipFlop_tb();
reg [1:0]jk;
reg clk,reset;
wire q;
JKFlipFlop jkff(jk,clk,reset,q);
intial
begin
$dumpfile("JKFlipFlop_tb.vcd");
$dumpvars(0,JKFlipFlop_tb);
end
initial
begin
clk=0;
forever #20 clk=~clk;
end
initial
begin
jk=2'b00; reset=0;#20;
jk=2'b01; reset=0;#20;
jk=2'b10; reset=0;#20;
jk=2'b11; reset=0;#20;
jk=2'b00; reset=0;#20;
jk=2'b11; reset=0;#20;
jk=2'b01; reset=0;#20;
jk=2'b10; reset=0;#20;
jk=2'b11; reset=0;#20;
jk=2'b01; reset=0;#20;
#120 $finish;
$display("Test Complete");
end
endmodule



