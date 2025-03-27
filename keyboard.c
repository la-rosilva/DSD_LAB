#include <LPC17xx.h>
#include "lcd-disp.c" // Include the LCD functions

void scan(void);
unsigned char row, flag, key;
unsigned long int temp, temp3;

// Keypad scan and mapping
unsigned char SCAN_CODE[16] = { 0x11, 0x21, 0x41, 0x81,
                                0x12, 0x22, 0x42, 0x82,
                                0x14, 0x24, 0x44, 0x84,
                                0x18, 0x28, 0x48, 0x88 };

unsigned char ASCII_CODE[16] = { '0', '1', '2', '3',
                                 '4', '5', '6', '7',
                                 '8', '9', '+', '-',
                                 'C', '=', ' ', ' ' };

void delay(unsigned int r) {
    for (unsigned int i = 0; i < r; i++);
}

void scan(void) {
    temp3 = LPC_GPIO1->FIOPIN;   // Read keypad column inputs
    temp3 &= 0x07800000;         // Mask unused bits (P1.23 to P1.26)

    if (temp3 != 0x00000000) {   // If key is pressed
        flag = 1;                // Set flag
        temp3 >>= 19;            // Shift high nibble
        temp >>= 10;             // Shift low nibble
        key = temp3 | temp;      // Combine row and column data
    }
}

int main(void) {
    char input[5] = {0};  // Store expression "A op B ="
    int index = 0;
    int A = 0, B = 0, result = 0;
    char op = 0;

    // GPIO Configuration for Keypad
    LPC_GPIO2->FIODIR |= 0x00003C00;   // Set P2.10 - P2.13 as outputs (Rows)
    LPC_GPIO1->FIODIR &= 0xF87FFFFF;   // Set P1.23 - P1.26 as inputs (Columns)

    lcd_init();  // Initialize LCD
    lcd_comdata(0x80, 0);
    lcd_puts("Enter Expr: ");  // Display message

    while (1) {
        flag = 0;

        // Scan each row
        for (row = 1; row < 5; row++) {
            LPC_GPIO2->FIOCLR = 0x00003C00;  // Clear row bits
            LPC_GPIO2->FIOSET = (1 << (9 + row));  // Enable one row at a time

            scan();  // Check for key press

            if (flag == 1) break;  // If key found, exit loop
        }

        if (flag == 1) {
            // Identify the key pressed
            for (int i = 0; i < 16; i++) {
                if (key == SCAN_CODE[i]) {
                    key = ASCII_CODE[i];  // Get ASCII equivalent
                    break;
                }
            }

            // Display on LCD
            lcd_comdata(0xC0 + index, 0); // Move cursor
            lcd_putc(key);

            // Store the input
            input[index++] = key;

            // Stop input at '='
            if (key == '=' || index == 5) {
                break;
            }

            delay(100000);
        }
    }

    // Parse Expression
    A = input[0] - '0';  // Convert char to integer
    op = input[1];       // Operator
    B = input[2] - '0';  // Convert char to integer

    // Perform operation
    if (op == '+') {
        result = A + B;
    } else if (op == '-') {
        result = A - B;
    }

    // Display Result
    lcd_comdata(0xC0 + index, 0);
    lcd_putc('=');
    index++;

    lcd_comdata(0xC0 + index, 0);
    lcd_putc(result + '0');  // Convert to char

    while (1); // Infinite loop to hold the result
}