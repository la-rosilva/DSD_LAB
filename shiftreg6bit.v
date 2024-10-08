module dff1(d,clk,q);
input d,clk;
output reg q = 0;
always @(posedge clk)
q<=d;
endmodule


module shiftreg6bit(g,clk,a);
input g,clk;
output [5:0]a;

  dff1 s1(g,clk,a[5]);
  dff1 s2(a[5],clk,a[4]);
  dff1 s3(a[4],clk,a[3]);
  dff1 s4(a[3],clk,a[2]);
  dff1 s5(a[2],clk,a[1]);
  dff1 s6(a[1],clk,a[0]);
  endmodule
  


  


  
  
 




