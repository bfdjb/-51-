/**************************************************************************************
���������пƼ����޹�˾��PRECHIN ���У�
����֧�֣�www.prechin.net
PRECHIN
 ����

ʵ�����ƣ��ⲿ�ж�0ʵ��
����˵����	
ʵ���������س���󣬵�����K3���ɿ���D1ָʾ������
ע�������������մ�����ȡ�£���ֹ��P3.2�ڸ���																				  
***************************************************************************************/
#include "reg52.h"//ʹ���ⲿ�ж���������ˮ�ƵĿ�ʼ��ֹͣ

typedef unsigned int u16;	
typedef unsigned char u8;
#define LED P2 
u16 led=0x01;
u16 count=0;
bit run_flag = 1;
sbit KEY3=P3^2;
sbit KEY1=P3^1;
void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

void Timer0Init(void)		
{
	
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0x66;		
	TH0 = 0xFC;		
	TF0 = 0;		
	TR0 = 1;
    ET0=1;
	EA=1;
}

void exti0_init(void)
{
	IT0=1;//�����ش�����ʽ���½��أ�
	EX0=1;//��INT0���ж�����
	EA=1;//�����ж�
}

void main()
{	
	exti0_init();//�ⲿ�ж�0����
    Timer0Init();
	while(1)
	{			
							
	}		
}

void Timer0_ISR(void) interrupt 1
{
    TL0 = 0x66;		
	TH0 = 0xFC;
	count++;
	if((count>=500)&&run_flag){
	count=0;led<<=1;if(led > 0x80)  
        {
            led= 0x01;  
        }
        LED=~led;
	}
	if((count>=500)&&~run_flag){
	count=0;led>>=1;if(led < 0x01)  
        {
            led= 0x80;  
        }
        LED=~led;
	}
}
void exti0() interrupt 0 
{   
	delay_10us(1000);
	if(KEY3==0){
	run_flag=~run_flag;
	}
				
}