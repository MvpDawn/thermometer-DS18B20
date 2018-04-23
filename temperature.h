#ifndef __TEMPERATURE_H_
#define __TEMPERATURE_H_

#include<reg51.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

sbit DSPORT=P1^0;

void Delay1ms(uint y); 			  // 延时yms
uchar DS18B20Init();			  // DS18B20初始化
void DS18B20WriteByte(uchar com); // 向DS18B20写入一个字节
uchar DS18B20ReadByte();		  // 从DS18B20读取一个字节
void  DS18B20TransfTemp();		  // 让18b20开始转换温度
void  DS18B20ReadTempCom();		  // 发送读取温度命令
int DS18B20ReadTemp();			  // 读取温度值（数字量）
uchar* DS18B20toString();			  // 读取温度值并转化为字符串（模拟量，保留两位小数）

#endif