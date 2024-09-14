`timescale 1ns/1ns
`include "TFlipFlop.v"
module TFlipFlop_tb();
reg t,clk,reset;
wire q;
TFlipFlop Tff(t,clk,reset,q);
initial begin
$dumpfile("TFlipFlop_tb.vcd");
$dumpvars(0,TFlipFlop_tb);
end
initial begin
clk=0;
forever #20 clk=~clk;
end
initial
begin
t=1;reset=1;
#20;
t=0; reset=1;
#20;
t=1; reset=1;
#20;
t=1;reset=0;
#20;
t=1;reset=1;
#20;
t=0;reset=0;
#20;
t=1; reset=1;
#20;
#120 $finish;
$display("Test Complete");
end
endmodule
