module mux8to1(s,in0,in1,in2,in3,in4,in5,in6,in7,out);
 input [2:0]s;
 input in0,in1,in2,in3,in4,in5,in6,in7;
 output reg out;
 always @ (*) begin
 case(s)
 0: out=in0;
 1: out=in1;
 2: out=in2;
 3: out=in3;
 4: out=in4;
 5: out=in5;
 6: out=in6;
 7: out=in7;
 default: out=in0;
 endcase
 end
 endmodule
 module graytobin(g,b);
 input [3:0]g;
 output [3:0]b;
 mux8to1 m1(g[3:0],0,0,0,0,1,1,1,1,b[3]);
 mux8to1 m2(g[3:0],0,0,1,1,1,1,0,0,b[2]);
 mux8to1 m3(g[3:0],0,1,1,0,1,0,0,1,b[1]);
 mux8to1 m4(g[3:0],g[0],~g[0],~g[0],g[0],~g[0],g[0],g[0],~g[0],b[0]);
 endmodule
 
 
 
         
 
