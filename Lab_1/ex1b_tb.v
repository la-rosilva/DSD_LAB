`timescale 1ns/1ns
`include "ex1b.v"

module ex1b_tb();
reg A,B,C,D;
wire F;

ex1b ex(A,B,C,D,F);
initial 
begin

  $dumpfile("ex1b.vcd");
  $dumpvars(0,ex1b_tb);
  
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
    
