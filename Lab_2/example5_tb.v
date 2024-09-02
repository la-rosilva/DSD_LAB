`timescale 1ns/1ns
`include "example5.v"

module example5_tb();
reg A,B,C,D;
wire F;

example5 ex(A,B,C,D,F);
initial
begin

  $dumpfile("example5_tb.vcd");
  $dumpvars(0,example5_tb);
  
   A=1'b0; B=1'b0; C=1'b0;D=1'b0;
    #20;
    
    A=1'b0; B=1'b0; C=1'b0;D=1'b1;
    #20;
    
    A=1'b0; B=1'b0; C=1'b1;D=1'b0;
    #20;
    
    A=1'b0; B=1'b0; C=1'b1;D=1'b1;
    #20;
    
    A=1'b0; B=1'b1; C=1'b0;D=1'b0;
    #20;
    
    A=1'b0; B=1'b1; C=1'b0;D=1'b1;
    #20;
    
  A=1'b0; B=1'b1; C=1'b1;D=1'b0;
    #20;
    
    A=1'b0; B=1'b1; C=1'b1;D=1'b1;
    #20;
    
   A=1'b1; B=1'b0; C=1'b0;D=1'b0;
    #20;
    
   A=1'b1;B=1'b0; C=1'b0;D=1'b1;
    #20;
    
   A=1'b1; B=1'b0; C=1'b1;D=1'b0;
    #20;
    
   A=1'b1; B=1'b0; C=1'b1;D=1'b1;
    #20;
    
   
    
     A=1'b1; B=1'b1; C=1'b0;D=1'b0;
    #20;
    
     A=1'b1; B=1'b1; C=1'b0;D=1'b1;
    #20;
    
     A=1'b1; B=1'b1; C=1'b1;D=1'b0;
    #20;
    
     A=1'b1; B=1'b1; C=1'b1;D=1'b1;
    #20;
    
    $display("Test complete");
  
end

endmodule
    
