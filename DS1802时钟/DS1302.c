#include "reg52.h"
sbit  DS1302_SCLK=P3^6;//提供时钟，上升沿读取数据下降沿输出数据
sbit  DS1302_IO=P3^4;//双向数据线
sbit  DS1302_CE=P3^5;//上升沿开始传输，下降沿结束
unsigned char DS1302_Time[]={25,4,4,23,8,55,5};//年月日时分秒星期

//寄存器地址
#define DS1302_SECOND		0x80  //写入地址
#define DS1302_MINUTE		0x82
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86  //日
#define DS1302_MONTH		0x88
#define DS1302_DAY			0x8A  //星期
#define DS1302_YEAR			0x8C 
#define DS1302_WP			0x8E  //写保护

void DS_1302_Init()//初始化
{
  DS1302_CE=0;
	DS1302_SCLK=0;
}

void DS_1302_Write(unsigned char Command ,Data)//写数据
{ 
	unsigned char i;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}

unsigned char DS_1302_Read(unsigned char Command)//读数据
{
    
	unsigned char i,Data=0x00;
	Command|=0x01;	
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=0;
		DS1302_SCLK=1;
	}
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data|=(0x01<<i);}
	}
	DS1302_CE=0;
	DS1302_IO=0;	
	return Data;
}
void DS1302_SetTime(void)//默认设置的时间
{
	DS_1302_Write(DS1302_WP,0x00);
	DS_1302_Write(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);//????BCD????
	DS_1302_Write(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS_1302_Write(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS_1302_Write(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS_1302_Write(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS_1302_Write(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS_1302_Write(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS_1302_Write(DS1302_WP,0x80);
}
void DS1302_ReadTime(void)//读时间
{
	unsigned char Temp;
	Temp=DS_1302_Read(DS1302_YEAR);
	DS1302_Time[0]=Temp/16*10+Temp%16;//BCD????????
	Temp=DS_1302_Read(DS1302_MONTH);
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS_1302_Read(DS1302_DATE);
	DS1302_Time[2]=Temp/16*10+Temp%16;
	Temp=DS_1302_Read(DS1302_HOUR);
	DS1302_Time[3]=Temp/16*10+Temp%16;
	Temp=DS_1302_Read(DS1302_MINUTE);
	DS1302_Time[4]=Temp/16*10+Temp%16;
	Temp=DS_1302_Read(DS1302_SECOND);
	DS1302_Time[5]=Temp/16*10+Temp%16;
	Temp=DS_1302_Read(DS1302_DAY);
	DS1302_Time[6]=Temp/16*10+Temp%16;
}
