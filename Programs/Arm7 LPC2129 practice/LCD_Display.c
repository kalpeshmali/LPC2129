#include<lpc21xx.h>
void delay()
{
	int i,j;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++);
	}
}
#define EN 1<<13
#define RS 1<< 10
#define RW 1<< 12
#define DATA 0xff<<15
#define port (EN|RS|RW|DATA)
void command(int c)
{
	IOPIN0=c<<15;
	IOCLR0=RS;
	IOCLR0=RW;
	IOSET0=EN;
	delay();
	IOCLR0=EN;
	delay();
}
void data(char c)
{
	IOPIN0=c<<15;
	IOSET0=RS;
	IOCLR0=RW;
	IOSET0=EN;
	delay();
	IOCLR0=EN;
}
int main()
{
	IODIR0=port;
	command(0x38);
	command(0x0e);
	command(0x01);
	command(0x0f);
	command(0x80);
	data('A');
	data('A');
	data('B');
	data('A');
	data('A');
	data('A');
	data('A');
	
	
	while(1);
	
}