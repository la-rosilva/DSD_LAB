`timescale 1ns/1ns
`include "Lab1_example.v"

module Lab1_example_tb();
reg x1,x2,x3,x4;
wire f;

Lab1_example ex(x1,x2,x3,x4,f);
initial 
begin

  $dumpfile("Lab1_example.vcd");
  $dumpvars(0,Lab1_example_tb);
  
    x1=1'b0; x2=1'b0; x3=1'b0;x4=1'b0;
    #20;
    
    x1=1'b0; x2=1'b0; x3=1'b0;x4=1'b1;
    #20;
    
    x1=1'b0; x2=1'b0; x3=1'b1;x4=1'b0;
    #20;
    
    x1=1'b0; x2=1'b0; x3=1'b1;x4=1'b1;
    #20;
    
    x1=1'b0; x2=1'b1; x3=1'b0;x4=1'b0;
    #20;
    
    x1=1'b0; x2=1'b1; x3=1'b0;x4=1'b1;
    #20;
    
    x1=1'b0; x2=1'b1; x3=1'b1;x4=1'b0;
    #20;
    
    x1=1'b0; x2=1'b1; x3=1'b1;x4=1'b1;
    #20;
    
    x1=1'b1; x2=1'b0; x3=1'b0;x4=1'b0;
    #20;
    
    x1=1'b1; x2=1'b0; x3=1'b0;x4=1'b1;
    #20;
    
    x1=1'b1; x2=1'b0; x3=1'b1;x4=1'b0;
    #20;
    
    x1=1'b1; x2=1'b0; x3=1'b1;x4=1'b1;
    #20;
    
   
    
     x1=1'b1; x2=1'b1; x3=1'b0;x4=1'b0;
    #20;
    
     x1=1'b1; x2=1'b1; x3=1'b0;x4=1'b1;
    #20;
    
     x1=1'b1; x2=1'b1; x3=1'b1;x4=1'b0;
    #20;
    
     x1=1'b1; x2=1'b1; x3=1'b1;x4=1'b1;
    #20;
    
    $display("Test complete");
  
end

endmodule
    
