`timescale 1ns/1ns
`include "mux16to1.v"
 module mux16to1_tb();
 reg [15:0]in;
 reg [3:0] sel;
 wire out;
 mux16to1 m16to1(in, sel,out);
 initial
 begin
 $dumpfile("mux16to1_tb.vcd");
 $dumpvars(0,mux16to1_tb);
 in=16'b1010101010101010;
 sel=4'b0000;
 #10;
  sel=4'b0001;
 #10;
  sel=4'b0010;
 #10;
  sel=4'b0011;
 #10;
  sel=4'b0100;
 #10;
  sel=4'b0101;
 #10;
  sel=4'b0110;
 #10;
  sel=4'b0111;
 #10;
  sel=4'b1000;
 #10;
  sel=4'b1001;
 #10;
  sel=4'b1010;
 #10;
  sel=4'b1011;
 #10;
  sel=4'b1100;
 #10;
  sel=4'b1101;
 #10;
 sel=4'b1110;
 #10;
 sel=4'b1111;
 #10;
 end
 endmodule 
