`timescale 1ns/1ns
`include "adder.v"

module adder_tb();
reg [3:0] A,B;
reg Cin;
wire [3:0] sum;
wire Cout;
adder a(A,B,Cin,sum,Cout);

initial
begin
$dumpfile("adder_tb.vcd");
$dumpvars(0,adder_tb);

A=4'b0000; B=4'b0001; Cin=1'b0;
#20;
A=4'b0011; B=4'b0011; Cin=1'b0;
#20;
A=4'b1111; B=4'b1001; Cin=1'b0;
#20;
A=4'b0011; B=4'b0001; Cin=1'b1;
#20;
A=4'b0001; B=4'b0001; Cin=1'b0;
#20;
A=4'b1001; B=4'b0011; Cin=1'b1;
#20;

$display("Test Complete");
end
endmodule


