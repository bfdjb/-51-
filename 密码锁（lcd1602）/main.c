#include <REGX52.H>
#include "Delay.h"		//包含Delay头文件
#include "LCD1602.h"	//包含LCD1602头文件
#include "MatrixKey.h"	//包含矩阵键盘头文件
#include "string.h"

unsigned char KeyNum,num;
unsigned char cod[7];
unsigned char password[7]="123123";
int count=0;
void xuan(unsigned char KeyNum,unsigned char* num)
{
	if(KeyNum==1) *num='1';
	if(KeyNum==2) *num='2';
	if(KeyNum==3) *num='3';
	if(KeyNum==4) *num='4';
	if(KeyNum==5) *num='5';
	if(KeyNum==6) *num='6';
	if(KeyNum==7) *num='7';
	if(KeyNum==8) *num='8';
	if(KeyNum==9) *num='9';
	if(KeyNum==10) *num='0';
}
void main()
{   
	LCD_Init();							//LCD初始化
	LCD_ShowString(1,1,"password:");	//LCD显示字符串
	
	while(1)
	{
		KeyNum=MatrixKey();			//获取矩阵键盘键码
		if(KeyNum)						//如果有按键按下
		{   if(KeyNum<=10){
			xuan(KeyNum,&num);
		cod[count]=num;
		
			count++;if(count==7){count=0;
				strcpy(cod, "      ");LCD_ShowString(1,11,"err");}
		
			LCD_ShowString(2,1,cod);
				
		}LCD_ShowString(2,1,cod);
			if(KeyNum==11)
				{if (strcmp(cod, password) == 0) {
					LCD_ShowString(1,11,"yes");  count=0;strcpy(cod, "      ");
				   LCD_ShowString(2,1,cod);}
                   else{LCD_ShowString(1,11,"err");  count=0;strcpy(cod, "      ");
				   LCD_ShowString(2,1,cod);}
				 
				}
			//LCD_ShowNum(2,1,KeyNum,4);	//LCD显示键码
		}
	}
}
