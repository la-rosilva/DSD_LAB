module dff1(d,clk,q);
input d,clk;
output reg q = 0;
always @(posedge clk)
q<=d;
endmodule

module mux4_1(w,s,f);
input[0:3]w;
input[1:0]s;
output reg f;
always@(w or s)
begin
if(s==0)
f=w[0];
else if(s==1)
f=w[1];
else if(s==2)
f=w[2];
else
f=w[3];
end
endmodule;

module sreg(I,A,S,clk);
input clk;
input [1:0]S;
output[3:0]A;
input [3:0]I;
wire [3:0]D;

mux4_1 m1({A[2],I[3],A[3],A[3]},S,D[3]);
mux4_1 m2({A[1],I[2],A[2],A[2]},S,D[2]);
mux4_1 m2({A[0],I[1],A[1],A[1]},S,D[1]);
mux4_1 m2({S[1],I[0],A[0],A[0]},S,D[0]);

dff D1(D[3],clk,A[3],1'b0);
dff D2(D[2],clk,A[2],1'b0);
dff D3(D[1],clk,A[1],1'b0);
dff D4(D[0],clk,A[0],1'b0);

endmodule


