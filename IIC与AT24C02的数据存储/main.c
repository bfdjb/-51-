#include "reg52.h"
#include "LCD1602.h"
#include "delay.h"
#include " at24c02.h"//改变Data1和Data2，可以掉电保持
	unsigned char Data1,Data2;
void main()
{

	
	LCD_Init();
	AT24C02_WriteByte(1,12);
	Delay(10);
	AT24C02_WriteByte(2,13);
	Delay(10);
	Data1=AT24C02_ReadByte(1);
		Data2=AT24C02_ReadByte(2);
	LCD_ShowNum(1,1,Data1,3);
	LCD_ShowNum(2,1,Data2,3);
	while(1)
	{
		
	}
}