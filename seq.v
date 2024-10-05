
module seq(clk, reset, x, z);
    input clk, reset, x;
    output reg z;
    output reg [2:0] cs, ns;

   
    parameter A = 3'b000;
    parameter B = 3'b001;
    parameter D = 3'b011;
    parameter F = 3'b010;
    parameter G = 3'b110;

   
    always @ (cs or x) begin
        case (cs)
            A: if (x) ns = B; else ns = F;
            B: if (x) ns = A; else ns = D;
            D: if (x) ns = A; else ns = G;
            F: if (x) ns = B; else ns = F; 
            G: if (x) ns = D; else ns = G; 
            default: ns = A;
        endcase
    end

   
    always @(posedge clk or posedge reset) begin
        if (reset)
            cs <= A;
        else
            cs <= ns;
    end


    always @ (cs or x) begin
        z = (cs[1] & ~cs[2] & ~x) || (cs[1] & ~cs[0] & x);
    end
endmodule

