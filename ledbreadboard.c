#include <stdint.h>                  // For uint32_t type
#include "TM4C123GH6PM.h"            // Device header for Tiva C
#include "TM4C123.h"                    // Device header


void delay(long d){
	while(d--);
}
int main()
{
    SYSCTL->RCGCGPIO = 0x00000001; //enable clock of gpio 
	  GPIOA-> DEN      = 0x00000004;   //PA2 WILL BE DIGITALISED
	  GPIOA-> DIR      = 0x00000004;   //PA2 WILL BE OUTPUT
	
	  while(1)
		{
			GPIOA->DATA= GPIOA->DATA | (1<<2); //PA2 ON
			delay(10000000);
			GPIOA->DATA= GPIOA->DATA & (~(1<<2));
			delay(10000000);
		}
}

