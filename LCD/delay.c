#include <REG8253.H>
void Delay_ms(unsigned int time) //delay function using timer0 to generate isec of delay.
{ 
	
	unsigned char i,limit;
	limit=(time/25);
	for(i=0;i<limit;i++)
	{
TMOD=0x11;
TL0=0xCB;
TH0=0x7D;	
TR0=1;
while(!TF0);
TF0=0;
TR0=0;	
}
}
void Delay_us(unsigned int time)
{
unsigned char i,limit;
limit=(time/100);	
for(i=0;i<limit;i++)
	{
TMOD=0x12;
TL0=0x7B;
TH0=0x7B;	
TR0=1;
while(!TF0);
TF0=0;
TR0=0;	
	
}
	}
