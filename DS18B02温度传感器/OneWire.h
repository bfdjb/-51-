#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

unsigned char OneWire_Init(void);//��ʼ��
void OneWire_SendBit(unsigned char Bit);//����һλ����
unsigned char OneWire_ReceiveBit(void);//����һλ����
void OneWire_SendByte(unsigned char Byte);//��������
unsigned char OneWire_ReceiveByte(void);//��������

#endif
