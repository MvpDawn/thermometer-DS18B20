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
#define LCD1602_DATAPINS P0
sbit LCD1602_E=P2^2;
sbit LCD1602_RW=P2^1;
sbit LCD1602_RS=P2^0;

/**********************************
��������
**********************************/
/*��51��Ƭ��12MHZʱ���µ���ʱ1ms����*/
void Lcd1602_Delay1ms(uint c);   //��� 0us
/*LCD1602д��8λ�����Ӻ���*/
void LcdWriteCom(uchar com);
/*LCD1602д��8λ�����Ӻ���*/	
void LcdWriteData(uchar data)	;
/*LCD1602��ʼ���ӳ���*/		
void LcdInit();						  

#endif
