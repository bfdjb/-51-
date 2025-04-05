#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

unsigned char OneWire_Init(void);//初始化
void OneWire_SendBit(unsigned char Bit);//发送一位数据
unsigned char OneWire_ReceiveBit(void);//接收一位数据
void OneWire_SendByte(unsigned char Byte);//发送数据
unsigned char OneWire_ReceiveByte(void);//接收数据

#endif
