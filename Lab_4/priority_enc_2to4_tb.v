`timescale 1ns/1ns
`include "priority_enc_4to2.v"
module priority_enc_4to2_tb();
reg [3:0]in;
reg EN;
wire [1:0]out;
priority_enc_4to2 p_enc4to2(W,EN,out);
initial
begin
$dumpfile("priority_enc_4to2_tb.vcd");
$dumpvars(0,priority_enc_4to2_tb);
EN=1'b0;W=4'b0001;
#20;
EN=1'b0;W=4'b1001;
#20;
EN=1'b1;W=4'b1101;
#20;
EN=1'b1;W=4'b0101;
#20;
EN=1'b1;W=4'b1111;
#20;
EN=1'b1;W=4'b0011;
#20;
EN=1'b1;W=4'b1010;
#20;
EN=1'b1;W=4'b1110;
#20;
$display("Test complete");
end
endmodule

