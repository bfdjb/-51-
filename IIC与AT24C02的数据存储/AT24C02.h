#ifndef __AT24C02_H__
#define __AT24C02_H__

//WordAddressΪ���ݵ�ַ��DataΪ����
void AT24C02_WriteByte(unsigned char WordAddress,Data);//д����
unsigned char AT24C02_ReadByte(unsigned char WordAddress);//������
#endif
