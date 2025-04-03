#include "reg52.h"
#include "lcd1602.h"
int a;
sbit boot1=P3^1;
sbit boot2=P3^0;
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

void main()//lcd按键计数器
	//长按可加速，加减按键为1和2
{
    LCD_Init();
  
	LCD_ShowNum(1,1,a,2);
	while(1)
	{//加法
		if(boot1==0){a++;LCD_ShowNum(1,1,a,2);
		Delay100ms();
		if(boot1==0){
		do{
		Delay10ms();if(boot1==0)a++;if(a==100)a=0;LCD_ShowNum(1,1,a,2);
		}while(boot1==0);
		};
		//while(boot==0);
		if(a==100)a=0;
		LCD_ShowNum(1,1,a,2);};
		//减法
		if(boot2==0){a--;LCD_ShowNum(1,1,a,2);
		Delay100ms();
		if(boot2==0){
		do{
		Delay10ms();if(boot2==0)a--;if(a<0)a=99;LCD_ShowNum(1,1,a,2);
		}while(boot2==0);
		};
		//while(boot==0);
		if(a<0)a=99;
		LCD_ShowNum(1,1,a,2);};
	}
}