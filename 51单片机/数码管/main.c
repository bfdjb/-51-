/**************************************************************************************
���������пƼ����޹�˾��PRECHIN ���У�
����֧�֣�www.prechin.net
PRECHIN
 ����

ʵ�����ƣ���̬�����ʵ��
����˵����	
ʵ���������س���������ģ�顱������������ʾ����0
ע�����																				  
***************************************************************************************/
#include "reg52.h"

typedef unsigned int u16;	//��ϵͳĬ���������ͽ����ض���
typedef unsigned char u8;
sbit one = P2^2 ;
sbit two = P2^3 ;
sbit there = P2^4 ;
#define SMG_A_DP_PORT	P0	//ʹ�ú궨������ܶ����

//�������������ʾ0~F�Ķ�������
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

/*******************************************************************************
* �� �� ��       : main
* ��������		 : ������
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void main()
{	P2=0x00;
	//SMG_A_DP_PORT=gsmg_code[0];//�������1�����ݸ�ֵ������ܶ�ѡ��
	while(1)
	{int a,b,c;
		P2=0x00;SMG_A_DP_PORT=gsmg_code[0];Delay100ms();
		for(a=1,b=1,c=1;a<17;a++,b++,c++)
		{
			//SMG_A_DP_PORT=gsmg_code[a];
			one=~one;
      if((b)%2==0){two=~two;};
			if((c)%4==0){there=~there;};
			SMG_A_DP_PORT=gsmg_code[a];
			Delay100ms();
			//SMG_A_DP_PORT=gsmg_code[a];Delay100ms();
		}
	   	
	}		
}