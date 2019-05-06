#include<lpc21xx.h>
typedef short int uint_8;
#define DIRECTION 1<<11 ;
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
	IODIR0 = DIRECTION;
	IOSET0 = DIRECTION;
	
	
	return 0;
}