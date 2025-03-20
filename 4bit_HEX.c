#include <LPC17xx.h>

unsigned char tohex[16] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F,0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
int arr[4] = {0, 0, 0, 0}; 


unsigned int i=0x0;

void initTimer()
{
 
    LPC_TIM0->CTCR = 0x0;   
    LPC_TIM0->TCR  = 0x02; 
    LPC_TIM0->PR   = 2;     
    LPC_TIM0->MR0  = 999999; 
    LPC_TIM0->MCR  = 2;     
    LPC_TIM0->EMR  = 0x20;  
    LPC_TIM0->TCR  = 0x01;  
}


void delay()
{
    initTimer();
    while (!(LPC_TIM0->EMR & 1)); 
}


void updateDisplay()
{
    for (i = 0; i < 4; i++)  
    {
        LPC_GPIO1->FIOPIN = i << 23;      
        LPC_GPIO0->FIOPIN = tohex[arr[i]] << 4; 
        delay(); 
    }
}


int main()
{
   
    LPC_PINCON->PINSEL0 = LPC_PINCON->PINSEL0 & 0xFF0000FF; 
    LPC_GPIO0->FIODIR |= 0XFF0;   

  
    LPC_PINCON->PINSEL3 = LPC_PINCON->PINSEL3 & 0xF00FFFFF; 
    LPC_GPIO1->FIODIR |= 0xF << 23; 


   
    LPC_GPIO2->FIODIR = LPC_GPIO0->FIODIR &=0xFFDFFFFF;

    while (1)
    {

        int switchState = LPC_GPIO0->FIOPIN & (1<<21);

      
        if (switchState) 
        {
            arr[0] = arr[0] + 1;
            if (arr[0] > 0xF)
            {
                arr[0] = 0;
                arr[1] = arr[1] + 1;
                if (arr[1] > 0xF)
                {
                    arr[1] = 0;
                    arr[2] = arr[2] + 1;
                    if (arr[2] > 0xF)
                    {
                        arr[2] = 0;
                        arr[3] = arr[3] + 1;
                        if (arr[3] > 0xF)
                        {
                            arr[3] = 0;
                        }
                    }
                }
            }
        }
        else 
        {
            if (arr[0] == 0)
            {
                arr[0] = 0xF;
                if (arr[1] == 0)
                {
                    arr[1] = 0xF;
                    if (arr[2] == 0)
                    {
                        arr[2] = 0XF;
                        if (arr[3] == 0)
                        {
                            arr[3] = 0xF;
                        }
                        else
                        {
                            arr[3] = arr[3] - 1;
                        }
                    }
                    else
                    {
                        arr[2] = arr[2] - 1;
                    }
                }
                else
                {
                    arr[1] = arr[1] - 1;
                }
            }
            else
            {
                arr[0] = arr[0] - 1;
            }
        }

       
        updateDisplay();
    }
}
