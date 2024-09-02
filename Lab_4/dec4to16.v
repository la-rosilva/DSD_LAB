module dec2to4(W, EN, out);
	input [1:0]W;
	input EN;
	output reg [3:0]out;
	always @(W or EN)
		begin
		if(EN==1 && W==0)
		out=1;
		else if(EN==1 && W==1)
		out=2;
		else if (EN==1 && W==2)
		out=4;
		else if(EN==1 && W==3)
		out=8;

		else
	out=0;
	end
endmodule

module dec4to16(W,EN,out);
 input [3:0]W;
 input EN;
 output [15:0]out;
 wire[3:0]en;
   dec2to4 d1(W[3:2],EN,en[3:0]);
   dec2to4 d2(W[1:0],en[0],out[3:0]);
   dec2to4 d3(W[1:0],en[1],out[7:4]);
   dec2to4 d4(W[1:0],en[2],out[11:8]);
   dec2to4 d5(W[1:0],en[3],out[15:12]);
endmodule


   
   
