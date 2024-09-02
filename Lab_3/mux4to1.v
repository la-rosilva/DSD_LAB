module mux4to1(w,s,f);
 input [3:0]w;
 input [1:0]s;
 output reg f;

 always @(w,s)begin
 if(s==2'b00)
 begin 
 f=w[0];
 end
 else if(s==2'b01)
 begin 
 f=w[1];
 end
 else if(s==2'b10)
 begin 
 f=w[2];
 end
 else
 begin
 f=w[3];
 end
 end
 endmodule
  

