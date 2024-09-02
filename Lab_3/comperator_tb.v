`timescale 1ns/1ns
`include "comperator.v"
module comperator_tb();
reg [2:0] a,b;
wire e,g,l;
comperator comp(a,b,e,g,l);
initial
begin
$dumpfile("comperator_tb.vcd");
$dumpvars(0,comperator_tb);
a=3'b101;b=3'b000;
#20;
a=3'b000;b=3'b000;
#20;
a=3'b110;b=3'b111;
#20;
a=3'b111;b=3'b001;
#20;
a=3'b100;b=3'b010;
#20;
a=3'b011;b=3'b100;
#20;
$display("Test Complete");
end
endmodule 

