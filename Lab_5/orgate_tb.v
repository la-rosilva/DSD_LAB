`timescale 1ns/1ns
`include"orgate.v"
module orgate_tb;
reg[3:0] in;
wire f;
orgate og(in,f);
initial
begin
$dumpfile("orgate_tb.vcd");
$dumpvars(0,orgate_tb);
in=0;
#20;
in=1;
#20;
in=2;
#20;
in=3;
#20;
in=4;
#20;
in=5;
#20;
in=6;
#20;
in=7;
#20;
in=8;
#20;
in=9;
#20;
in=10;
#20;
in=11;
#20;
in=12;
#20;
in=13;
#20;
in=14;
#20;
in=15;
#20;
$display("Test complete");
end
endmodule


