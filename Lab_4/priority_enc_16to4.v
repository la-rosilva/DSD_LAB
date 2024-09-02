module priority_enc_16to4(in,en,out);
input [15:0]in;
input en;
output reg[3:0]out;
integer i=0;
always @(in,en) begin
if(en==1)begin
for(i=0; i<15;i=i+1)
begin
if((in[i]==1)&&(d[15:i+1]==0))begin
  out=i;
  else
  out=0;
  end
 end
 end
 else
 begin
 out=4'b0000;
 end
 end
 endmodule
