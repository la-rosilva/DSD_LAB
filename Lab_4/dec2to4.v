module dec2to4(W, EN, out);
	input [1:0]W;
	input EN;
	output reg [3:0]out;
	always @(W or EN)
		begin
		if(EN==0 && W==0)
		out=1;
		else if(EN==0 && W==1)
		out=2;
		else if (EN==0 && W==2)
		out=4;
		else if(EN==0 && W==3)
		out=8;

		else
	out=0;
	end
endmodule
		


