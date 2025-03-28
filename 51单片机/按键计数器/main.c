#include "reg52.h"
sbit switch1=P3^1;
typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;
sbit one = P2^2 ;
sbit two = P2^3 ;
sbit there = P2^4 ;
#define SMG_A_DP_PORT	P0	//使用宏定义数码管段码口

//共阴极数码管显示0~F的段码数据
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;


	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	int a; int shi,ge;shi=0;
	while(1)
	{
		if(switch1==0)
		{while(switch1==0){//检测按键是否松开
		one=1;two=0;there=0;P0=gsmg_code[shi];Delay1ms();//同下
			one=0;two=0;there=0;P0=gsmg_code[ge];Delay1ms();//使按键按下时常亮
		};
			a++;
		};
		if(a==100) a=0;
		//if(a>=10)
   
		shi=a/10;
		ge=a%10;
			one=1;two=0;there=0;P0=gsmg_code[shi];Delay1ms();
			one=0;two=0;there=0;P0=gsmg_code[ge];Delay1ms();
		
	}
}