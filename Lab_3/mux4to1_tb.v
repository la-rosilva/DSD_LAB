`timescale 1ns/1ns
`include "mux4to1.v"
 module mux4to1_tb();
 reg [3:0]w;
 reg [1:0]s;
 wire f;
 mux4to1 m4to1(w,s,f);
 initial
 begin
 $dumpfile("mux4to1_tb.vcd");
 $dumpvars(0,mux4to1_tb);
 s=2'b00; w[0]=1'b0; w[1]=1'b0; w[2]=1'b0; w[3]=1'b0;
 #20;
  s=2'b01;w[0]=1'b0; w[1]=1'b0; w[2]=1'b1; w[3]=1'b0;
 #20;
  s=2'b10;w[0]=1'b0; w[1]=1'b0; w[2]=1'b1; w[3]=1'b1;
 #20;
  s=2'b11; w[0]=1'b0; w[1]=1'b1; w[2]=1'b0; w[3]=1'b0;
 #20;
  s=2'b00; w[0]=1'b0; w[1]=1'b1; w[2]=1'b0; w[3]=1'b1;
 #20;
  s=2'b01; w[0]=1'b0; w[1]=1'b1; w[2]=1'b1; w[3]=1'b0;
 #20;
  s=2'b10; w[0]=1'b0; w[1]=1'b1; w[2]=1'b1; w[3]=1'b1;
 #20;
  s=2'b11; w[0]=1'b1; w[1]=1'b0; w[2]=1'b0; w[3]=1'b0;
 #20;
 
 $display("Test Complete");
 end
 endmodule
