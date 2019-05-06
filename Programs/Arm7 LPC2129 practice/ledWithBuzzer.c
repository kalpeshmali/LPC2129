#include<lpc21xx.h>

typedef short int uint_8;
#define BUZZER_DIRECTION 0x00000800;
#define LED_DIRECTION 0x01FE0000;

void led_event(void);
void buzzer_event(void);

void delay()
{
	uint_8 i,j;
	for(i=0;i<500;i++)
	{
		for(j=0;j<1000;j++);
	}
}

int main()
{
	
	IODIR0 = BUZZER_DIRECTION ;
	IODIR1 = LED_DIRECTION;
	led_event();
	
	return 0;
}
void led_event(void)
{
	uint_8 i;
	for(i=17;i<=24;i++)
	{
	//	buzzer_event();
		IOSET1=1<<i;
		delay();
		IOCLR1=1<<i;
		delay();
		if(i==24)
		{
			buzzer_event();
			for(i=24;i>=17;i--)
			{
				IOSET1=1<<i;
				delay();
				IOCLR1=1<<i;
				delay();
			}
			buzzer_event();
		}
		
	}
	
}
void buzzer_event(void)
{
	IOSET0=1<<11;
	delay();
	IOCLR0=1<<11;
	delay();
}