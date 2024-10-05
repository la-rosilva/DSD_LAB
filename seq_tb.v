`timescale 1ns/1ns
`include "seq.v"
module seq_tb();
reg x,clk,reset;
wire z;
wire [2:0]y;
seq sc(x,clk,reset,z);
initial clk=0;
always #10 clk=~clk;
initial begin
$dumpfile("seq_tb.vcd");
$dumpvars(0,seq_tb);
reset=1;x=0;
#20 reset=0;x=1;
#20 x=0;
#20 x=1;
#20 x=0;
#20 x=1;
#100
$display("Test Complete");
$finish;
end
endmodule
