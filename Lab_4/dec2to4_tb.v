`timescale 1ns/1ns
`include "dec2to4.v"
module dec2to4_tb();
reg [1:0]W;
reg EN;
wire [3:0]out;
dec2to4 d2to4(W,EN, out);
initial 
begin
$dumpfile("dec2to4_tb.vcd");
$dumpvars(0,dec2to4_tb);
W=0; EN=1;
#20;
W=1;EN=0;
#20;
W=2;EN=0;
#20;
W=3;EN=0;
#20;
$display("Test Complete");
end
endmodule

