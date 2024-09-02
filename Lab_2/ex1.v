module ex1(A,B,C,D,F);
  input A,B,C,D;
  output F;
  assign g=(A & B);
  assign h=(C|D);
  assign F=(g & h)|(~g & ~h);
endmodule 

