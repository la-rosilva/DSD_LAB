`timescale 1ns/1ns
`include "bintogray.v"
module bintogray_tb();
parameter N=4;
reg [N-1:0] bin;
wire [N-1:0] gray;
bintogray btg(bin,gray);

initial
begin
$dumpfile("bintogray_tb.vcd");
$dumpvars(0,bintogray_tb);
bin=4'b0010;
#10;
bin=4'b1010;
#10;
bin=4'b0001;
#10;
bin=4'b0011;
#10;
bin=4'b0001;
#10;
bin=4'b1001;
#10;
$display("Test complete");
end
endmodule
