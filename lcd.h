#ifndef __LCD_H_
#define __LCD_H_
#include<reg51.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/**********************************
PIN口定义
**********************************/
#define LCD_DATAPINS P0
sbit LCD_E=P2^2;
sbit LCD_RW=P2^1;
sbit LCD_RS=P2^0;

/**********************************
函数声明
**********************************/
/*在51单片机12MHZ时钟下的延时1ms函数*/
void Lcd_Delay1ms(uint c);   //误差 0us
/*LCD1602写入8位命令子函数*/
void LcdWriteCom(uchar com);
/*LCD1602写入8位数据子函数*/	
void LcdWriteData(uchar dat);
/*在坐标为x,y处显示单个字符*/
void LcdDisplayChar(uchar X,Y ,uchar dat);
/*在起始坐标为x,y处开始显示字符串*/
void LcdDisplayStr(uchar X,Y ,uchar *str);
/*LCD1602初始化子程序*/		
void LcdInit();						  

#endif
