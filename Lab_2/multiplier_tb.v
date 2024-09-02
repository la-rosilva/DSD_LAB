`timescale 1ns/1ns
`include "multiplier.v"

module multiplier_tb();
reg [2:0] A,B;

wire [5:0] P;
wire w1,w2,w3,w4;
multiplier a(A,B,P);

initial
begin
$dumpfile("multiplier_tb.vcd");
$dumpvars(0,multiplier_tb);

A=3'b010; B=3'b001; 
#20;
A=3'b011; B=3'b101; 
#20;
A=3'b101; B=3'b011; 
#20;
A=3'b011; B=3'b001;
#20;
A=3'b001; B=3'b111; 
#20;


$display("Test Complete");
end
endmodule


