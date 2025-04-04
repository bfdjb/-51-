/**************************************************************************************
深圳市普中科技有限公司（PRECHIN 普中）
技术支持：www.prechin.net
PRECHIN
 普中

实验名称：外部中断0实验
接线说明：	
实验现象：下载程序后，当按下K3键可控制D1指示灯亮灭
注意事项：将红外接收传感器取下，防止对P3.2口干扰																				  
***************************************************************************************/
#include "reg52.h"//使用外部中断来控制流水灯的开始和停止

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
	IT0=1;//跳变沿触发方式（下降沿）
	EX0=1;//打开INT0的中断允许
	EA=1;//打开总中断
}

void main()
{	
	exti0_init();//外部中断0配置
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