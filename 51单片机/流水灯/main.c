#include "reg52.h"

sbit LED1=P2^0;	//��P2.0�ܽŶ���ΪLED1
void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	LED1=0;	//LED1�˿�����Ϊ�͵�ƽ
	while(1)
	{int a;
		Delay10ms();
		for(a=0;a<8;a++)
		{ P2=~(0x01<<a);
			Delay10ms();
			Delay10ms();Delay10ms();Delay10ms();Delay10ms();
		}
	}		
}