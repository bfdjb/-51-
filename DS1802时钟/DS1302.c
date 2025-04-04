#include "reg52.h"
sbit  DS1302_SCLK=P3^6;//�ṩʱ�ӣ������ض�ȡ�����½����������
sbit  DS1302_IO=P3^4;//˫��������
sbit  DS1302_CE=P3^5;//�����ؿ�ʼ���䣬�½��ؽ���
unsigned char DS1302_Time[]={25,4,4,23,8,55,5};//������ʱ��������

//�Ĵ�����ַ
#define DS1302_SECOND		0x80  //д���ַ
#define DS1302_MINUTE		0x82
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86  //��
#define DS1302_MONTH		0x88
#define DS1302_DAY			0x8A  //����
#define DS1302_YEAR			0x8C 
#define DS1302_WP			0x8E  //д����

void DS_1302_Init()//��ʼ��
{
  DS1302_CE=0;
	DS1302_SCLK=0;
}

void DS_1302_Write(unsigned char Command ,Data)//д����
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

unsigned char DS_1302_Read(unsigned char Command)//������
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
void DS1302_SetTime(void)//Ĭ�����õ�ʱ��
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
void DS1302_ReadTime(void)//��ʱ��
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
