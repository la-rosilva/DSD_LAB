module A1(A,B,C,D,F);
   input A,B,C,D;
   output F;
   assign F=(A & ~C)|(B & C)|(~B & ~C);
   
endmodule







