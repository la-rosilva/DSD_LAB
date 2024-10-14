module dff1(d,clk,q);
input d,clk;
output reg q;
always @(posedge clk)
begin
q<=d;
end
endmodule

module mux4to1(w,s,out);
input [3:0]w;
input [1:0]s;
output reg out;
always @(w,s)
begin
if(s==0)
 out=w[0];
else if(s==1)
out=w[1];
else if(s==2)
out=w[2];
else
out=w[3];
end
endmodule

module shiftreg(I,A,S,clk);
input [3:0]I;
input [1:0]S;
input clk;
output [3:0]A;
wire [3:0]D;

mux4to1 m1({A[3],~A[3],I[3],A[2]},S,D[3]);
mux4to1 m2({A[2],~A[2],I[2],A[1]},S,D[2]);
mux4to1 m3({A[1],~A[1],I[1],A[0]},S,D[1]);
mux4to1 m4({A[0],~A[0],I[0],0},S,D[0]);

dff1 d1(D[3],clk,A[3]);
dff1 d2(D[2],clk,A[2]);
dff1 d3(D[1],clk,A[1]);
dff1 d4(D[0],clk,A[0]);
endmodule







