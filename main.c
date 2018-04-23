#include<reg51.h>
#include"lcd.h"
#include"temperature.h"
#include"UART.h"

main()
{
	int i=0;
	uchar *str="hello world";
	uchar *now_temp="Not ready";
	LcdInit();
	UARTInit();
	now_temp=DS18B20toString();
	LcdDisplayChar(0,0,'A');
//	LcdDisplayChar(0,1,now_temp[0]);
//	LcdDisplayChar(1,1,now_temp[1]);
//	LcdDisplayChar(2,1,now_temp[2]);
//	LcdDisplayChar(3,1,now_temp[3]);
//	LcdDisplayChar(4,1,now_temp[4]);
//	LcdDisplayChar(5,1,now_temp[5]);

	while(1)
	{
		now_temp=DS18B20toString();
		LcdDisplayStr(0,1,now_temp);
	}

/*	LcdDisplayChar(0,1,now_temp[0]);
	LcdDisplayChar(1,1,now_temp[1]);
	LcdDisplayChar(2,1,now_temp[2]);
	LcdDisplayChar(3,1,now_temp[3]);
	LcdDisplayChar(4,1,now_temp[4]);
	LcdDisplayChar(5,1,now_temp[5]);*/
	
}