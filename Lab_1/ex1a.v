module ex1a(A,B,C,D,F);
   input A,B,C,D;
   output F;
   assign F=(~A & ~B)|(~C & ~D)|(~C & ~B);
endmodule
