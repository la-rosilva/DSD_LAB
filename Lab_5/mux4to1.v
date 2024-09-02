module mux4to1 (s,c,d,f);
 input [1:0]s;
 input c,d;
 output reg f;
 always @(*)begin
 case(s)
 0: f=~c|~d;
 1: f=~d;
 2: f=~c&d;
 3:f=~d;
 default f=1'b0;
 endcase 
 end
 endmodule
