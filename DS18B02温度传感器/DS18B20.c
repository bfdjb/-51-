#include <REGX52.H>
#include "OneWire.h"

//DS18B20指令
#define DS18B20_SKIP_ROM			0xCC   //跳过ROM
#define DS18B20_CONVERT_T			0x44   //温度转换（将温度值转换为数字信号）
#define DS18B20_READ_SCRATCHPAD 	0xBE   //读取温度

void DS18B20_ConvertT(void)
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVERT_T);
}

float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;
	int Temp;
	float T;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=OneWire_ReceiveByte();//低位温度数据
	TMSB=OneWire_ReceiveByte();//高位温度数据
	Temp=(TMSB<<8)|TLSB;
	T=Temp/16.0;
	return T;
}
