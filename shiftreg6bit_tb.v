`timescale 1ns/1ns
`include "shiftreg6bit.v"
module shiftreg6bit_tb();
 reg q,clk;
 
 
 wire [5:0]A;
 shiftreg6bit d(q,clk,A);
  initial begin
  $dumpfile ("shiftreg6bit_tb.vcd");
  $dumpvars(0,shiftreg6bit_tb);
  clk=0;
  forever #10 clk=~clk;
  end
  initial begin
  q=1;#20;
  q=0;#20;
  q=1;#20;
  q=0;#20;
  q=0;#20;
  q=1;#20;
  #100 $finish;
  $display("Test complete");
  end
  endmodule
