#include "reg52.h"
#include "delay.h"
sbit led=P2^1;
void Delay10us(unsigned char a)		//@11.0592MHz
{
	unsigned char i,c;

	for(c=0;c<a;c++){
	i = 25;
	while (--i);}
}

void main()
{
	unsigned char Time,i;
	while(1)
	{
		for(Time=0;Time<100;Time++)
		{for(i=0;i<20;i++){
			led=0;Delay10us(Time);
            led=1;Delay10us(100-Time);	}}
        for(Time=0;Time<100;Time++)
		{for(i=0;i<20;i++){
			led=0;Delay10us(100-Time);
            led=1;Delay10us(Time);	}			
}
}}
