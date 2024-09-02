module Lab1_example(x1,x2,x3,x4,f);
   input x1,x2,x3,x4;
   output f;
   assign f=(x2 & ~x3)|(x3 & ~x4);
endmodule
