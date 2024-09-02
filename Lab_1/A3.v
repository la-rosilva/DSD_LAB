module A3(A,B,C,D,F);
   input A,B,C,D;
   output F;
   assign F=(B & C & D)|(A & C & D)|(C & A & B)+ (D & A & B);
   
   
   
   

   
endmodule

