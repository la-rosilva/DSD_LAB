`timescale 1ns/1ns
`include"majority_func.v"
module majority_func_tb();
reg [2:0]in;
wire y;
majority_func mfunc(in,y);
initial
begin
$dumpfile("majority_func_tb.vcd");
$dumpvars(0,majority_func_tb);
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
$display("Test complete");
end
endmodule

