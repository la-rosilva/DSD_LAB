#include<lpc17xx.h>
#include<stdlib.h>

void lcd_init(void);
void write(int,int);
void delay_lcd(unsigned int);
void lcd_comdata(int,int);
void lcd_putc(unsigned char);
void clear_ports(void);
unsigned int  r;

int main(void){
	SystemInit();
	SystemCoreClockUpdate();
	lcd_init();
	
	LPC_GPIO0->FIODIR &= ~(1<<21);
	
	while(1){
		if(!(LPC_GPIO0->FIOPIN & (1<<21))){
			int random_number =(rand()%6)+1;
			
			lcd_comdata(0x80,0);
			lcd_putc(random_number+'0');
			
			delay_lcd(100000);
			while(!(LPC_GPIO0->FIOPIN & (1<<21)));
		}
	}
}
void lcd_init() {
    LPC_PINCON->PINSEL1 &= 0xFC003FFF; // Configure P0.23 to P0.28 as GPIO
    LPC_GPIO0->FIODIR |= 0x0F << 23 | 1 << 27 | 1 << 28; // Set directions as output
    clear_ports();
    delay_lcd(3200);

    lcd_comdata(0x33, 0); delay_lcd(30000);
    lcd_comdata(0x32, 0); delay_lcd(30000);
    lcd_comdata(0x28, 0); delay_lcd(30000);
    lcd_comdata(0x0C, 0); delay_lcd(800);
    lcd_comdata(0x06, 0); delay_lcd(800);
    lcd_comdata(0x01, 0); delay_lcd(10000);
}

// Send command/data to LCD
void lcd_comdata(int temp1, int type) {
    int temp2 = temp1 & 0xF0;
    temp2 = temp2 << 19;
    write(temp2, type);
    temp2 = temp1 & 0x0F;
    temp2 = temp2 << 23;
    write(temp2, type);
    delay_lcd(1000);
}

// Write to LCD
void write(int temp2, int type) {
    clear_ports();
    LPC_GPIO0->FIOPIN = temp2;
    if (type == 0) LPC_GPIO0->FIOCLR = 1 << 27;
    else LPC_GPIO0->FIOSET = 1 << 27;
    LPC_GPIO0->FIOSET = 1 << 28;
    delay_lcd(25);
    LPC_GPIO0->FIOCLR = 1 << 28;
}

// LCD Delay
void delay_lcd(unsigned int r1) {
    for (r = 0; r < r1; r++);
}

// Clear LCD Ports
void clear_ports(void) {
    LPC_GPIO0->FIOCLR = 0x0F << 23;
    LPC_GPIO0->FIOCLR = 1 << 27;
    LPC_GPIO0->FIOCLR = 1 << 28;
}

// Display Single Character on LCD
void lcd_putc(unsigned char c) {
    lcd_comdata(c, 1);
}
