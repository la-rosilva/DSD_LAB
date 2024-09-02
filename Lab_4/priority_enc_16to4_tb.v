`timescale 1ns/1ns
`include "priority_enc_16to4.v"
module priority_enc_16to4_tb();
reg [15:0]in;
reg EN;
wire [3:0]out;
priority_enc_16to4 p_enc16to4(in,EN,out);
initial
begin
$dumpfile("priority_enc_16to4_tb.vcd");
$dumpvars(0,priority_enc_16to4_tb);
EN=1'b0;in=4'b0001;
#20;
EN=1'b1;in=16'b0000100011000010;
#20;
EN=1'b1;in=16'b1001001001001001;
#20;
EN=1'b1;in=16'b0000001001110101;
#20;
EN=1'b1;in=16'b0000000000100111;
#20;
EN=1'b1;in=16'b0100000011000000;
#20;

$display("Test complete");
end
endmodule

