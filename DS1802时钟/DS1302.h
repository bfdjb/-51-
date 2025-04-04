#ifndef __DS1302_H__
#define __DS1302_H__

DS_1302_Init();
void DS_1302_Write(unsigned char command ,Data);
unsigned char DS_1302_Read(unsigned char command);
extern unsigned char DS1302_Time[];
void DS1302_SetTime(void);
void DS1302_ReadTime(void);
#endif
