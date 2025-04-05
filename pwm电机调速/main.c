#include "reg52.h"
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"//用不了lcd，引脚冲突

sbit Motor=P1^0;

unsigned char Counter,Compare,KeyNum,Speed;


void main()
{
	Timer0_Init();
	
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Speed++;
			Speed%=4;
			if(Speed==0){Compare=0;}	
			//if(Speed==1){Compare=40;}//启动不了需要手动
			if(Speed==1){Compare=50;}
			if(Speed==2){Compare=75;}
			if(Speed==3){Compare=100;}
		}
		Nixie(1,Speed);
	}
	}

void Timer0_Routine() interrupt 1
{

	TL0 = 0xA4;		//???????
	TH0 = 0xFF;		//???????
    Counter++;Counter%=100;
    if(Counter<Compare)
	{ Motor=1;
	}
	else
{   Motor=0;
}
}