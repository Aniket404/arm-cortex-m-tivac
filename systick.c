#include "TM4C123.h"

volatile uint32_t ms;  // Mark ms as volatile to ensure proper update in ISR

void _delay_ms(uint16_t delay) {
    ms = 0;
    while (ms < delay);  // Wait until the delay time is reached
}

int main() {
    SYSCTL->RCGCGPIO |= (1 << 5);  // Enable clock for GPIOF
    while ((SYSCTL->PRGPIO & (1 << 5)) == 0);  // Wait for GPIOF to be ready

    GPIOF->DEN |= (1 << 3);  // Enable PF3 (Green LED) as digital pin
    GPIOF->DIR |= (1 << 3);  // Set PF3 as output

    // Configure SysTick
    SysTick->LOAD = 16000 - 1;  // 1ms delay (16MHz clock)
    SysTick->VAL = 0;  // Clear current value register
    SysTick->CTRL = 0x07;  // Enable SysTick with system clock and interrupt

    while (1) {
        GPIOF->DATA ^= (1 << 3);  // Toggle Green LED
        _delay_ms(1000);  // 1-second delay
    }
}

// SysTick Interrupt Handler
void SysTick_Handler() {
    ms++;  // Increment millisecond counter
}
