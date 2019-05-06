#include<lpc21xx.h>
typedef  char uint_8;
#define DIRECTION 0x01FE0000
static void led_event(void);
void delay()
{
	short int i,j;
	for(i=0;i<500;i++)
	{
		for(j=0;j<1000;j++);
	}
}
int main()
{
		IODIR1 =DIRECTION;
		led_event();

		return 0;
}
static void led_event(void)
{
	uint_8 i;
	for(i=17;i<=24;i++)
	{
		IOSET1 =(1<<i);
		delay();
		IOCLR1 =(1<<i);
		delay();	
		if(i==24)
		{
			for(i=24;i>=17;i--)
			{
				IOSET1 =(1<<i);
				delay();
				IOCLR1 =(1<<i);
				delay();
			}
		}
	}
}