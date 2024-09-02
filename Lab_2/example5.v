module example5(A,B,C,D,F);
  input A,B,C,D;
  output F;
  assign g=(A & ~B)|(~A & B);
  assign F=(g & C)|(~g & D);
endmodule 


