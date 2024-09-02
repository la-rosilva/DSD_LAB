module ex2b(A,B,C,D,F);
   input A,B,C,D;
   output F;
   assign F=(A|~B|C|~D) & (~A|D) & (~C|D);
endmodule
