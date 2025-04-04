#include "reg52.h"//通过串口通信用电脑控制led灯的亮灭并返回数据
#include "delay.h"
#include "UART.h"
typedef unsigned int u16;	
typedef unsigned char u8;

void main()
{	
	Uart_Init();
   
	while(1)
	{			
				
	}		
}

void UART_Routine() interrupt 4  //串口中断
{
  if(RI==1){
  P2=~SBUF;
  UART_sendbyte(SBUF);
  RI=0;
  }
	
}