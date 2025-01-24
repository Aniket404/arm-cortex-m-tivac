
int main()
{
    // Enable the clock for Port F
    unsigned int *RCGCGPIO;
    RCGCGPIO = (unsigned int *)0x400FE608U;
    *RCGCGPIO = 0x20U;  // Enable clock for PORT F

    // Digital enable for PF1, PF2, and PF3
    unsigned int *GPIOFDEN;
    GPIOFDEN = (unsigned int *)0x4002551CU;
    *GPIOFDEN = 0x0EU;  // Enable digital function for PF1, PF2, PF3

    // Set PF1, PF2, and PF3 as output
    unsigned int *GPIOFDIR;
    GPIOFDIR = (unsigned int *)0x40025400U;
    *GPIOFDIR = 0x0EU;  // Set PF1, PF2, PF3 as outputs

    // Data register for toggling LED states
    unsigned int *GPIOFDATA;
    GPIOFDATA = (unsigned int *)0x400253FCU;
    
    while (1)
    {
        *GPIOFDATA = 0x04U;  // Turn ON the blue LED (PF1) 0x02u for red 0x08u green
        for (volatile int i = 0; i < 1000000; i++);  // Delay
        *GPIOFDATA = 0x00U;  // Turn OFF all LEDs
        for (volatile int i = 0; i < 1000000; i++);  // Delay
     
    }
}

        
     
    
