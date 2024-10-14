`timescale 1ns/1ns
`include "q1.v"
module q1_tb;
reg clk;
reg [1:0]s;
reg [3:0]I;
wire [3:0]Q;
q1 sreg(I,A,s,clk);
always #10 clk=~clk;
initial
begin
$dumpfile("q1_tb.vcd");
$dumpvars(0,q1_tb);
clk=0;
#100
$finish
end
initial 
begin
I=2'b00,A=4'b1010;
I=2'b01,A=4'b1010;
I=2'b10,A=4'b0000;
I=2'b11,A=4'b0000;
$display("Test Complete");
end
endmodule




