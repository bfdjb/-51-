#include "reg52.h"
#include "lcd1602.h"
#include "DS1302.h"
#include "delay.h"//由DS1302实现的电子时钟
unsigned char Second,miniute,hour;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :   DAY:");
	DS_1302_Init();
	
	DS1302_SetTime();
	while(1)
	{
		
		DS1302_ReadTime();//????
		LCD_ShowNum(1,1,DS1302_Time[0],2);
		LCD_ShowNum(1,4,DS1302_Time[1],2);
		LCD_ShowNum(1,7,DS1302_Time[2],2);
		LCD_ShowNum(2,1,DS1302_Time[3],2);
		LCD_ShowNum(2,4,DS1302_Time[4],2);
		LCD_ShowNum(2,7,DS1302_Time[5],2);
	    LCD_ShowNum(2,14,DS1302_Time[6],1);
	}
}