`timescale 1ns/1ns
`include "dec4to16.v"
module dec4to16_tb();
reg [3:0]W;
reg EN;
wire [15:0]out;
dec4to16 d4to16(W,EN,out);
initial
begin
$dumpfile("dec4to16_tb.vcd");
$dumpvars(0,dec4to16_tb);
EN=1'b0;W=4'b0000;
#20;
EN=1'b0;W=4'b1000;
#20;
EN=1'b1;W=4'b0010;
#20;
EN=1'b1;W=4'b0101;
#20;
EN=1'b1;W=4'b0111;
#20;
EN=1'b1;W=4'b1110;
#20;
EN=1'b1;W=4'b1100;
#20;
$display("Test complete");
end
endmodule



