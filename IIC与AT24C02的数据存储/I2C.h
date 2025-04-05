#ifndef __I2C_H__
#define __I2C_H__

void I2C_Start(void);//开始
void I2C_Stop(void);//停止
void I2C_SendByte(unsigned char Byte);//发送数据
unsigned char I2C_ReceiveByte(void);//读取数据
void I2C_SendAck(unsigned char AckBit);//发送应答
unsigned char I2C_ReceiveAck(void);//读取应答


#endif
