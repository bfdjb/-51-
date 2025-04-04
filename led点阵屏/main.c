#include "reg52.h"
#include "Delay.h"//��ʾ�����x��

sbit SCK=P3^6;	//��λ�Ĵ���
sbit RCK=P3^5;		//�洢�Ĵ���
sbit SER=P3^4;   //������������

void write_byte(unsigned char byte)//74HC595ģ�����
{
	unsigned char i;
	for(i=0;i<8;i++)
	{  SER=byte&(0x80>>i);
		SCK=1;SCK=0;
	}
    RCK=1;RCK=0;
}
void Martrixled_ShowColumn(unsigned char Column,Data)//���1���е�һ֡
{    write_byte(Data);//�����
	 P0=~(0x80>>Column);//��ѡ
	 Delay(1);P0=0xff;

}
void main()
{
	SCK=0;RCK=0;
	while(1)
	{   Martrixled_ShowColumn(0,0x81);
		Martrixled_ShowColumn(1,0x42);
		Martrixled_ShowColumn(2,0x24);
		Martrixled_ShowColumn(3,0x18);
		Martrixled_ShowColumn(4,0x18);
		Martrixled_ShowColumn(5,0x24);
		Martrixled_ShowColumn(6,0x42);
		Martrixled_ShowColumn(7,0x81);
	}
}