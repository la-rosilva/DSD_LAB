`timescale 1ns/1ns
`include "SRFlipFlop.v"
module SRFlipFlop_tb();
reg clk,reset;
reg [1:0]sr;
wire q;
SRFlipFlop(sr,clk,reset,q);

initial
begin
clk=0;
forever #20 clk=~clk;
end
initial
begin
sr=2'b00;reset=1;#20;
sr=2'b01;reset=1;#20;
sr=2'b11;reset=1;#20;
sr=2'b10;reset=1;#20;
sr=2'b00;reset=0;#20;
sr=2'b11;reset=0;#20;
sr=2'b11;reset=1;#20;
sr=2'b01;reset=1;#20;
sr=2'b11;reset=1;#20;
sr=2'b10;reset=1;#20;
#120 $finish;
$display("Test Complete");
end
endmodule


