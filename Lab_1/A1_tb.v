`timescale 1ns/1ns
`include "A1.v"

module A1_tb();
reg A,B,C,D;
wire F;

A1 ex(A,B,C,D,F);
initial 
begin

  $dumpfile("A1.vcd");
  $dumpvars(0,A1_tb);
  
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
    
