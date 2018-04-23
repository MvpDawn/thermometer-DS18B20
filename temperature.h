#ifndef __TEMPERATURE_H_
#define __TEMPERATURE_H_

#include<reg51.h>

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

sbit DSPORT=P1^0;

void Delay1ms(uint y); 			  // ��ʱyms
uchar DS18B20Init();			  // DS18B20��ʼ��
void DS18B20WriteByte(uchar com); // ��DS18B20д��һ���ֽ�
uchar DS18B20ReadByte();		  // ��DS18B20��ȡһ���ֽ�
void  DS18B20TransfTemp();		  // ��18b20��ʼת���¶�
void  DS18B20ReadTempCom();		  // ���Ͷ�ȡ�¶�����
int DS18B20ReadTemp();			  // ��ȡ�¶�ֵ����������
uchar* DS18B20toString();			  // ��ȡ�¶�ֵ��ת��Ϊ�ַ�����ģ������������λС����

#endif