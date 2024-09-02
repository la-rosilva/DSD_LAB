module comperator(a,b,e,g,l);
  input [2:0]a,b;
  output reg e,l,g;
  always @(a,b)begin
  if(a>b)begin
  
  e=0;g=1;l=0;
  end
  else if(a==b)begin
  e=1;l=0;g=0;
  end
  else begin
  e=0; l=1;g=0;
  end
  end
  endmodule
