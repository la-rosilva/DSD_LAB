module seq_1010(clk, reset, in, out);
input clk, reset,in;
output reg out;
output reg[1:0]cs,ns;
parameter s0=2'b00;
parameter s1=2'b01; 
parameter s2=2'b10;
parameter s3=2'b11;
always @(posedge clk or posedge reset)begin
if(reset)
	cs<=s0;
else
	cs<=ns;
end

always @(*)begin
case(cs)
s0: 
begin
	ns=in?s1:s0;
	out=1'b0;
end


s1:
begin 
	ns=in?s2:s1;
	out=1'b0;
end

s2:
begin
	ns=in?s0:s3;
	out=1'b0;
end
s3:
begin
	ns=in?s2:s1;
	out=in?1'b0:1'b1;
end

default: 
begin 
	ns=s0;
	out=1'b0;
end

endcase
end
endmodule



