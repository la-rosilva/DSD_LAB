#include <LPC17xx.h>

unsigned char row, var, flag, key, disp[3];
int num1,num2,operation = -1, equalsTyped = 0, result =0;
unsigned long int i, var1, temp, temp1, temp2, temp3;
unsigned char SCAN_CODE[16] = {0x11, 0x21, 0x41, 0x81,
                               0x12, 0x22, 0x42, 0x82,
                               0x14, 0x24, 0x44, 0x84,
                               0x18, 0x28, 0x48, 0x88};
unsigned char ASCII_CODE[16] = {'0', '1', '2', '3',
                                '4', '5', '6', '7',
                                '=', '9', '+', '-',
                                '8', 'D', 'E', 'F'};

void delay_lcd(unsigned int r1) {
    unsigned int r;
    for(r=0;r<r1;r++);
    return;
}

void clear_ports(void) {
    /* Clearing the lines at power on */
    LPC_GPIO0->FIOCLR = 0x0F<<23; //Clearing data lines
    LPC_GPIO0->FIOCLR = 1<<27; //Clearing RS line
    LPC_GPIO0->FIOCLR = 1<<28; //Clearing Enable line
    
    return;
}

void write(int temp2, int type) { 
    clear_ports();
    LPC_GPIO0->FIOPIN = temp2; // Assign the value to the data lines 
    if(type==0)
    LPC_GPIO0->FIOCLR = 1<<27; // clear bit RS for Command
    else
    LPC_GPIO0->FIOSET = 1<<27; // set bit RS for Data
    LPC_GPIO0->FIOSET = 1<<28; // EN=1
    delay_lcd(25);
    LPC_GPIO0->FIOCLR = 1<<28; // EN =0
    return;
}

void lcd_comdata(int temp1, int type) {
    int temp2 = temp1 & 0xf0; //move data (26-8+1) times : 26 - HN place, 4 - Bits
    temp2 = temp2 << 19; //data lines from 23 to 26
    write(temp2, type);
    temp2 = temp1 & 0x0f; //26-4+1
    temp2 = temp2 << 23; 
    write(temp2, type);
    delay_lcd(1000);
    return;
}

void lcd_puts(unsigned char *buf1) {
    unsigned int i=0;
    unsigned int temp3;
    while(buf1[i]!='\0') {
        temp3 = buf1[i];
        lcd_comdata(temp3, 1);
        i++;
        if(i==16) {
            lcd_comdata(0xc0, 0);
        }
    }
    return;
}

void lcd_init() {
    /*Ports initialized as GPIO */
    LPC_PINCON->PINSEL1 &= 0xFC003FFF; //P0.23 to P0.28
    /*Setting the directions as output */
    LPC_GPIO0->FIODIR |= 0x0F<<23 | 1<<27 | 1<<28;
 
    clear_ports();
    delay_lcd(3200);
    lcd_comdata(0x33, 0); 
    delay_lcd(30000); 
    lcd_comdata(0x32, 0);
    delay_lcd(30000);
    lcd_comdata(0x28, 0); //function set
    delay_lcd(30000);
    lcd_comdata(0x0c, 0);//display on cursor off
    delay_lcd(800);
    lcd_comdata(0x06, 0); //entry mode set increment cursor right
    delay_lcd(800);
    lcd_comdata(0x01, 0); //display clear
    delay_lcd(10000);
    return;
}

void scan(void)
{
    temp3 = LPC_GPIO1->FIOPIN;
    temp3 &= 0x07800000; //check if any key pressed in the enabled row .. checks bits 26 to 23
    if(temp3 != 0)
    {
        flag = 1;
        temp3 >>= 19;//Shifted to come at HN of byte (4 to 7 bits)
        temp >>= 10; //shifted to come at LN of byte (indicates row 0 to 3 bits)
        key = temp3|temp; //get SCAN_CODE (0 to 7 bits)
    }
}//end scan

int main(void)
{
    LPC_GPIO2->FIODIR |= 0x3C00; // made output P2.10 to P2.13 (rows)
    LPC_GPIO1->FIODIR &= 0xF87FFFFF; // made input P1.23 to P1.26(cols)
    LPC_GPIO0->FIODIR |= 0x0F << 23 | 1 << 27 | 1 << 28;
    clear_ports();
    delay_lcd(3200);
    lcd_init();
    lcd_comdata(0x80,0); // point to first line of LCD
    delay_lcd(800);
    while (1) {
        while (1) {
            for (row = 1; row < 5; row++) {
                if (row == 1)
                    var1 = 1 << 10;
                else if (row == 2)
                    var1 = 1 << 11;
                else if (row == 3)
                    var1 = 1 << 12;
                else if (row == 4)
                    var1 = 1 << 13;
                temp = var1;
                LPC_GPIO2->FIOCLR = 0x3C00; // first clear the port and send appropriate value for
                LPC_GPIO2->FIOSET = var1; //enabling the row
                flag = 0;
                scan(); // scan if any key pressed in the enabled row
                if (flag == 1) {
                    break;
                }
            } // end for
            if (flag == 1)
                break;
        }                        // 2nd while(1)
        for (i = 0; i < 16; i++) // get the ascii code for display
        {
            if (key == SCAN_CODE[i])
            {
                key = ASCII_CODE[i];
                if (key == '=')
                    equalsTyped = 1;
                else if (key == '+')
                    operation = 1;
                else if (key == '-')
                    operation = 2;
                if (operation == -1)
                    num1 = key - 48;
                else if (operation != -1 && equalsTyped == 0)
                    num2 = key - 48;
                break;
            } 
        }     

        lcd_comdata(0x01, 0); //display clear
        delay_lcd(800);
        disp[0] = key;
        disp[1] = '\0';
        disp[2] = '\0';
        lcd_puts(&disp[0]);
        delay_lcd(1000);
        if (equalsTyped == 1) {
            if (operation == 1)
                result = num1 + num2;
            else 
                result = num1 - num2;
            if (result > 9) {
                disp[1] = result%10 + 48;
                result /= 10;
                disp[0] = result + 48;
            } 
            else if (result < 0) {
                disp[0] = '-';
                disp[1] = (-result) + 48;
            }
            else {
                disp[0] = result + 48;
            }
            lcd_comdata(0x01, 0); //display clear
            delay_lcd(800);
            lcd_puts(&disp[0]);
        }
    } // end while 1
} // end main


























//Visalakshi's code
#include<lpc17xx.h>
#include "lcd_disp.c"
void scan(void);
unsigned char key, op, eq;
unsigned char expression[10];
unsigned int pos = 0;
int a, b;
unsigned long int row, var, flag, i, var1, temp, temp1, temp2, temp3;
unsigned int num1, num2, res;
unsigned char scan_code[16] = {0X11, 0X21, 0X41, 0X81, 0X12, 0X22, 0X42, 0X82, 0X14, 0X24, 0X44, 0X84, 0X18, 0X28, 0X48, 0X88};
unsigned char ascii_code[16] = {'1', '2', '3', '+', '4', '5', '6', '-', '7', '8', '9', '=', '*', '0', '#', 'C'};
int main(void)
{
	LPC_GPIO2 -> FIODIR |= 0x00003C00;
	LPC_GPIO1 -> FIODIR &= 0xF87FFFFF;
	LPC_GPIO0 -> FIODIR |= 0XF << 23 | 1 <<27 | 1 << 28;
	clear_ports();
	delay_lcd(3200);
	lcd_init();
	lcd_comdata(0x80, 0);
	delay_lcd(800);
	while(1){
		while(1){
			for(row = 1; row < 5; row++){
				if(row == 1)
					var1 = 0x00000400;
				else if(row == 2)
					var1 = 0x00000800;
				else if(row == 3)
					var1 = 0x00001000;
				else if(row == 4)
					var1 = 0x00002000;
				temp = var1;
				LPC_GPIO2 -> FIOCLR = 0x00003C00;
				LPC_GPIO2 -> FIOSET = var1;
				flag = 0;
				scan();
				if(flag == 1)
					break;
			}
			if(flag == 1)
				break;
		}
		for(i = 0; i<16; i++){
			if(key == scan_code[i]){
				if(ascii_code[i] == 'C'){
					lcd_comdata(0x01, 0);
					delay_lcd(100000);
					pos = 0;
					break;
				}
				expression[pos++] = ascii_code[i];
				lcd_puts(expression[pos-1]);
				delay_lcd(100000);
				if(pos == 4){
					if(expression[1] == '+'){
						expression[4] = ((expression[0] - '0') + (expression[2] - '0')) + '0';
						if(expression[4] - '0' > 9){
							a = (expression[4] - '0')%10;
							b = (expression[4] - '0')/10;
							lcd_puts(b + '0');
							delay_lcd(100000);
							lcd_puts(a + '0');
							delay_lcd(100000);
						}
						else{
							lcd_puts(expression[4]);
							delay_lcd(100000);
						}
					}
					else if(expression[1] == '-'){
						expression[4] = ((expression[0] - '0') - (expression[2] - '0')) + '0';
						lcd_puts(expression[4]);
						delay_lcd(100000);
					}
				}
				break;
			}
		}
	}
}
void scan(void)
{
	temp3 = LPC_GPIO1 -> FIOPIN;
	temp3 &= 0x07800000;
	if(temp3 != 0x00000000){
		flag = 1;
		temp3 >>= 19;
		temp >>= 10;
		key = temp3 | temp;
	}
}
