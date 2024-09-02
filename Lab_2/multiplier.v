module multiplier(A,B,P);
  input [2:0] A,B;
  output [5:0] P;
  wire w1,w2,w3,w4;
  
  assign P[0]=A[0] & B[0];
  assign P[1]=(A[1] & B[0])^(A[0] & B[1]);
  assign w1=(A[1] & B[0])&(A[0] & B[1]);
  
  assign P[2]=(w1 ^ (A[2] & B[0]) ^ (A[1] & B[1])^ (A[0] & B[2]));
  assign w2=(w1 & (A[2] & B[0]) & (A[1] & B[1])& (A[0] & B[2]));
  
  assign P[3]=(w2^ (A[2] & B[1]) ^ (A[1] & B[2]));
  assign w3=(w2 & (A[2] & B[1]) & (A[1] & B[2]));
  
  assign P[4]=(w3 ^(A[2] & B[2]));
  assign w4= (w3 & (A[2] & B[2]));
  
  assign P[5]=w4;
  
  endmodule 
  
