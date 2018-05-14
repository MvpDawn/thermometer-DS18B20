/*****************************************************************
	
						  数据帧格式
	┌────────┬─────┬───────────────────┬────────────┬────────────┐
	│ index  │  0  │         1         │  ········	│     X		 │ 
	├────────┼─────┼───────────────────┼────────────┼────────────┤
	│数据    │0x7F │0（数据）/1（指令）│数据/指令	│    0x7F    │			    
	└────────┴─────┴───────────────────┴────────────┴────────────┘	
			  
******************************************************************/


#ifndef __BLUETOOTH_H_
#define __BLUETOOTH_H_
#include<reg51.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

sbit warming=P1^1;
sbit cooling=P1^2;
void BluInit(void);
void BluSendByte(unsigned char c);
void BluSendStr(uchar *s);
#endif
