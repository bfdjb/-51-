#include "reg52.h"
#include "I2C.h"

#define AT24C02_ADDRESS		0xA0


void AT24C02_WriteByte(unsigned char WordAddress,Data)
{   
	
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);//在I2C总线上发送外设地址
	I2C_ReceiveAck();
    I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_SendByte(Data);//开始写入数据
	I2C_ReceiveAck();
	I2C_Stop();
}
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);//在I2C总线上发送外设地址
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);//发送外设中的存储地址
	I2C_ReceiveAck();
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS|0x01);//开始读
	I2C_ReceiveAck();
	Data=I2C_ReceiveByte();//读取数据
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}
