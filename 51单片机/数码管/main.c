/**************************************************************************************
深圳市普中科技有限公司（PRECHIN 普中）
技术支持：www.prechin.net
PRECHIN
 普中

实验名称：静态数码管实验
接线说明：	
实验现象：下载程序后“数码管模块”最左边数码管显示数字0
注意事项：																				  
***************************************************************************************/
#include "reg52.h"

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;
sbit one = P2^2 ;
sbit two = P2^3 ;
sbit there = P2^4 ;
#define SMG_A_DP_PORT	P0	//使用宏定义数码管段码口

//共阴极数码管显示0~F的段码数据
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
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	P2=0x00;
	//SMG_A_DP_PORT=gsmg_code[0];//将数组第1个数据赋值给数码管段选口
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