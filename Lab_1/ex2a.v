module ex2a(A,B,C,D,F);
   input A,B,C,D;
   output F;
   assign F=(C|B) & (C|D) & (~A|~B|~C|~D);
endmodule
