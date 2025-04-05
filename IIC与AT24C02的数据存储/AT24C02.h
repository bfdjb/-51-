#ifndef __AT24C02_H__
#define __AT24C02_H__

//WordAddress为数据地址，Data为数据
void AT24C02_WriteByte(unsigned char WordAddress,Data);//写数据
unsigned char AT24C02_ReadByte(unsigned char WordAddress);//读数据
#endif
