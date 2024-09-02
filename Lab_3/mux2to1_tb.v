`timescale 1ns/1ns
`include "mux2to1.v"
 module mux2to1_tb();
 reg x1,x2,s;
 wire f;
 mux2to1 ex2(x1,x2,s,f);
 initial
 begin
 $dumpfile("mux2to1_tb.vcd");
 $dumpvars(0,mux2to1_tb);
 s=1'b0; x1=1'b0; x2=1'b0;
 #20;
 s=1'b0; x1=1'b0; x2=1'b1;
 #20;
 s=1'b0; x1=1'b1; x2=1'b0;
 #20;
 s=1'b0; x1=1'b1; x2=1'b1;
 #20;
 s=1'b1; x1=1'b0; x2=1'b0;
 #20;
 s=1'b1; x1=1'b0; x2=1'b1;
 #20;
 s=1'b1; x1=1'b1; x2=1'b0;
 #20;
 s=1'b1; x1=1'b1; x2=1'b1;
 #20;
 $display("Test Complete");
 end
 endmodule

 
 

