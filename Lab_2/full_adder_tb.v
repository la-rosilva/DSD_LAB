`timescale 1ns/1ns
`include "full_adder.v"

module full_adder_tb();
reg A,B,Cin;
wire sum,carry;

full_adder ex(A,B,Cin, sum, carry);
initial 
begin

  $dumpfile("full_adder.vcd");
  $dumpvars(0,full_adder_tb);
  
    A=1'b0; B=1'b0; Cin=1'b0;
    #20;
    
    A=1'b0; B=1'b0; Cin=1'b1;
    #20;
    
    A=1'b0; B=1'b1; Cin=1'b0;
    #20;
    
     A=1'b0; B=1'b1; Cin=1'b1;
    #20;
    
    A=1'b1; B=1'b0; Cin=1'b0;
    #20;
    
    A=1'b1; B=1'b0; Cin=1'b1;
    #20;
    
    A=1'b1; B=1'b1; Cin=1'b0;
    #20;
    
    A=1'b1; B=1'b1; Cin=1'b1;
    #20;
   
    
   
   
   
    $display("Test complete");
  
end

endmodule
  
