#include<lpc21xx.h>
void delay(int count)
{
 	int i,j;
	for(i=0;i<count;i++)
	for(j=0;j<1000;j++);
}

int main()
{
	short int i;
 	IODIR1 = 1 << 17;
	while(1)
	{
		
	IOSET1 = 1<<17;
	delay(5000);
	IOCLR1 = 1 << 17;
	delay(5000);
	}
}