module DFlipFlop1 (D,clk,Reset,Q);
	input D,clk,Reset;
	output Q;
	reg Q=0;
	always @(posedge clk)
	if(Reset)
	Q<=0;
	else
	Q<=D;
endmodule
