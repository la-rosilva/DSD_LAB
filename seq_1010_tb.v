`timescale 1ns/1ns
`include "seq_1010.v"

module seq_1010_tb();
reg clk,reset,in;
wire out;
wire [1:0]ns;
seq_1010 ss(clk,reset,in,out);
initial clk=0;
always #10 clk=~clk;
initial begin
$dumpfile("seq_1010_tb.vcd");
$dumpvars(0,seq_1010_tb);
reset=1;in=0;
#20 reset=0; in=1;
#20 in=1;
#20 in=0;
#20 in=1;
#20 in=0;
#20 in=1;
#20 in=1;
#20 in=0;
#20 in=1;
#20 in=0;
#20 in=1;
#20 in=0;
#100;
$display("Test Complete");
#160;
$finish;
end
endmodule

