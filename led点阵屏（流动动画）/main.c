#include "reg52.h"
#include "Delay.h"//œ‘ æ ‰≥ˆ°∞x°±
#include "LED.h"

unsigned char Animation[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x40,
0x20,0x10,0x08,0x04,0x02,
};

void main()
{   unsigned char a , move,count;
	led_Init();
	while(1)
	{   int i;
		for(i=0;i<8;i++)
		{
		Martrixled_ShowColumn(i,Animation[i+move]);
		}
		count++;
		if(count>30){
		move++;count=0;
			if(move>13){move=0;}
		}
	}
}