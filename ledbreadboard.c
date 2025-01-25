#include "TM4C123.h"

void delay(long d)
{
	while(d--);
}

void Printdata(unsigned char data)
{
	//zeroth bit =a=PA7
	if((data&0x01)==0x01) ( GPIO->DATA =GPIO->DATA | (1<<7);
	else                  ( GPIO->DATA =GPIO->DATA & (~(1<<7));
  //first bit =b=PA6
	if((data&0x02)==0x02) ( GPIO->DATA =GPIO->DATA | (1<<6);
	else                  ( GPIO->DATA =GPIO->DATA & (~(1<<6));
  //second bit =c=PA5
	if((data&0x04)==0x04) ( GPIO->DATA =GPIO->DATA | (1<<5);
	else                  ( GPIO->DATA =GPIO->DATA & (~(1<<5));
  //third bit =d=PB4
	if((data&0x08)==0x08) ( GPIO->DATA =GPIO->DATA | (1<<4);
	else                  ( GPIO->DATA =GPIO->DATA & (~(1<<4));	
  //fourth bit =e=PE5
	if((data&0x10)==0x10) ( GPIO->DATA =GPIO->DATA | (1<<5);
	else                  ( GPIO->DATA =GPIO->DATA & (~(1<<5));	
  //fifth bit =f=PE4
	if((data&0x20)==0x20) ( GPIO->DATA =GPIO->DATA | (1<<4);
	else                  ( GPIO->DATA =GPIO->DATA & (~(1<<4));
  //sixth bit =g=PB1
	if((data&0x40)==0x40) ( GPIO->DATA =GPIO->DATA | (1<<1);
	else                  ( GPIO->DATA =GPIO->DATA & (~(1<<1));
  //seventh bit =h=PB0
	if((data&0x80)==0x80) ( GPIO->DATA =GPIO->DATA | (1<<0);
	else                  ( GPIO->DATA =GPIO->DATA & (~(1<<0));			
	
/*
a-PA7
b-PA6
c-pa5
D-PA4
E-PE5
F-PE4
G-PB1
H-PB0 */

int main()
{
	SYSCTL->RCGCGPIO =SYSCTL->RCGCGPIO | (1<<0)| (1<<1) |(1<<4);
	//DIGITALIZE THESE 8 PINS
	GPIOA->DEN =GPIO->DEN |(1<<5) | (1<<6) |(1<<7);
	GPIOB->DEN =GPIOB->DEN |(1<<0)|(1<<1)| (1<<4);
	GPIOE->DEN =GPIOE->DEN|(1<<4) |(1<<5);
	//CONFIGURE THESE 8 PINS AS OP PINS
	GPIOA->DIR =GPIO->DIR |(1<<5) | (1<<6) |(1<<7);
	GPIOB->DIR =GPIOB->DIR |(1<<0)|(1<<1)| (1<<4);
	GPIOE->DIR =GPIOE->DIR|(1<<4) |(1<<5);
	
	while(1)
	{
		//0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x6f
		Printdata(0x3F); //zero
		delay(1000000);
		Printdata(0x06); //one
		delay(1000000);
		Printdata(0x5B); //TWO
		delay(1000000);
		Printdata(0x4F); //THREE
		delay(1000000);
	
}	