#include "reg52.h"
#include "Delay.h"//显示输出“x”

sbit SCK=P3^6;	//移位寄存器
sbit RCK=P3^5;		//存储寄存器
sbit SER=P3^4;   //串行数据输入

void write_byte(unsigned char byte)//74HC595模块输出
{
	unsigned char i;
	for(i=0;i<8;i++)
	{  SER=byte&(0x80>>i);
		SCK=1;SCK=0;
	}
    RCK=1;RCK=0;
}
void Martrixled_ShowColumn(unsigned char Column,Data)//输出1列中的一帧
{    write_byte(Data);//输出列
	 P0=~(0x80>>Column);//列选
	 Delay(1);P0=0xff;
}
void led_Init()
{
	SCK=0;
	RCK=0;
}