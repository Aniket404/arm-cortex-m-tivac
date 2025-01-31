#include "TM4C123.h"                    // Device header

int main() {
    SYSCTL->RCGCGPIO |= (1 << 5);  // Enable clock to GPIO port F
    
    GPIOF->LOCK = 0x4C4F434;      // Unlock GPIO Port F
    GPIOF->CR = 0x01;             // Allow changes to PF0 (SW2)
    GPIOF->LOCK = 0;              // Lock GPIO Port F
    
    GPIOF->DEN |= (1 << 0) | (1 << 4);  // Enable digital function for PF0 (SW1) and PF4 (SW2)
    GPIOF->DIR &= ~((1 << 0) | (1 << 4)); // Set PF0 and PF4 as inputs
    
    GPIOF->PUR |= (1 << 0) | (1 << 4); // Enable pull-up resistors for PF0 and PF4
    
    GPIOF->DEN |= (1 << 2) | (1 << 3);  // Enable digital for PF2 and PF3 (LEDs)
    GPIOF->DIR |= (1 << 2) | (1 << 3);  // Set PF2 and PF3 as outputs
    
    GPIOF->IS &= ~((1 << 0) | (1 << 4));   // Edge-sensitive
    GPIOF->IBE &= ~((1 << 0) | (1 << 4));  // Disable both edges
    GPIOF->IEV &= ~((1 << 0) | (1 << 4));  // Trigger on falling edge
    GPIOF->IM |= (1 << 0) | (1 << 4);     // Enable interrupts for PF0 and PF4
    GPIOF->ICR |= (1 << 0) | (1 << 4);    // Clear interrupt flags for PF0 and PF4
    
    NVIC->ISER[0] |= (1 << 30);           // Enable IRQ 30 for GPIOF
    NVIC->IPR[30] = 0x60;                 // Set priority for GPIOF interrupt
    
    while (1) {
        // Main loop, waiting for interrupts
    }
}

void GPIOF_Handler() {
    if ((GPIOF->MIS & 0x10) == 0x10) {  // PF4 (SW2)
        GPIOF->DATA |= (1 << 3);       // Turn on Green LED (PF3)
        GPIOF->DATA &= ~(1 << 2);      // Turn off Blue LED (PF2)
        GPIOF->ICR |= (1 << 4);        // Clear PF4 interrupt
    } 
    else if ((GPIOF->MIS & 0x01) == 0x01) {  // PF0 (SW1)
        GPIOF->DATA |= (1 << 2);       // Turn on Blue LED (PF2)
        GPIOF->DATA &= ~(1 << 3);      // Turn off Green LED (PF3)
        GPIOF->ICR |= (1 << 0);        // Clear PF0 interrupt
    }
}
