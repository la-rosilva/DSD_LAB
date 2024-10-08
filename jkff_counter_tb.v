`timescale 1ns/1ns
`include"jkff_counter.v"
module jkff_counter_tb;
reg clear,clk;
wire [2:0]Q;
synchronous_counter G0(clear,clk,Q);
always #10 clk=~clk;
initial
begin
clear=0;
clk=1;
#150 $finish;
end
initial
begin
$dumpfile("jkff_counter_tb.vcd");
$dumpvars(0,jkff_counter_tb);
$monitor($time,"clear=%b, Q=%3b",clear,Q);
#12 clear=1;
end
endmodule

