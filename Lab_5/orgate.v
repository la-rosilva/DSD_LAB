module decoder(i,out);
input[3:0]i;
output reg [15:0] out;
always @(*) begin
case(i)
0:out=1;
1:out=2;
2:out=4;
3:out=8;
4:out=16;
5:out=32;
6:out=64;
7:out=128;
8:out=256;
9:out=512;
10:out=1024;
11:out=2048;
12:out=4096;
13:out=8192;
14:out=16384;
15:out=32768;
default: out=1'b0;
endcase
end
endmodule
module orgate(in,f);
input [3:0] in;
output f;
wire [15:0]out;
decoder gt(in[3:0],out[15:0]);
assign f=out[2]|out[3]|out[4]|out[5]|out[6]|out[7]|out[10]|out[11]|out[12]|out[15];
endmodule



