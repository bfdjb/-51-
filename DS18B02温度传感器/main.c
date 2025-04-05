#include "reg52.h"
#include " lcd1602.h"
#include " delay.h"
#include "Onewire.h"
#include "DS18B20.h"//œ‘ æ…„ œ∂»Œ¬∂»
unsigned char Ack;
float T;
void main()
{
	LCD_Init();
	while(1)
	{
		DS18B20_ConvertT();
       T=DS18B20_ReadT();
		if(T<0){
		LCD_ShowString(2,1,"-");LCD_ShowString(2,4,".");	
		}
		else{
		LCD_ShowString(2,1,"+");
        LCD_ShowString(2,4,".");				
		}
      	LCD_ShowNum(2,2,T,2);
        LCD_ShowNum(2,5,(unsigned long)(T*100)%100,2);		
	}
}