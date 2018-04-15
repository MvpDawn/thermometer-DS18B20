#ifndef __LCD_H_
#define __LCD_H_
#include<reg51.h>

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/**********************************
PIN�ڶ���
**********************************/
#define LCD_DATAPINS P0
sbit LCD_E=P2^2;
sbit LCD_RW=P2^1;
sbit LCD_RS=P2^0;

/**********************************
��������
**********************************/
/*��51��Ƭ��12MHZʱ���µ���ʱ1ms����*/
void Lcd_Delay1ms(uint c);   //��� 0us
/*LCD1602д��8λ�����Ӻ���*/
void LcdWriteCom(uchar com);
/*LCD1602д��8λ�����Ӻ���*/	
void LcdWriteData(uchar dat);
/*������Ϊx,y����ʾ�����ַ�*/
void LcdDisplayChar(uchar X,Y ,uchar dat);
/*����ʼ����Ϊx,y����ʼ��ʾ�ַ���*/
void LcdDisplayStr(uchar X,Y ,uchar *str);
/*LCD1602��ʼ���ӳ���*/		
void LcdInit();						  

#endif
