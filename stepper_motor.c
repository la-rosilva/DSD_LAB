#include<lpc17xx.h>
void clockwise(void);
void anticlockwise(void);
unsigned int long var1;
unsigned int i=0,j=0,k=0;
int main(void){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO0->FIODIR|=0xF0;
	LPC_GPIO0->FIODIR&=~(1<<21);
	while(1){
		int switchstate=LPC_GPIO0->FIOPIN&(1<<21);
		if(switchstate){
			for(i=0;i<50;i++){
				anticlockwise();
			}
		}else{
			for(j=0; j<50;j++){
				clockwise();
			}
		}
	}
}
void clockwise(void){
	var1=0x10;
	for(i=0; i<=3;i++){
		LPC_GPIO0->FIOPIN=var1;
		var1=var1<<1;
		for(k=0; k<3000;k++);
	}
}


void anticlockwise(void){
	var1=0x80;
	for(j=0; j<=3;j++){
		LPC_GPIO0->FIOPIN=var1;
		var1=var1>>1;
		for(k=0; k<3000;k++);
	}
}









