#include "reg52.h"//ͨ������ͨ���õ��Կ���led�Ƶ����𲢷�������
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

void UART_Routine() interrupt 4  //�����ж�
{
  if(RI==1){
  P2=~SBUF;
  UART_sendbyte(SBUF);
  RI=0;
  }
	
}