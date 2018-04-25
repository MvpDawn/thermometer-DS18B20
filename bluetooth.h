#ifndef __UART_H_
#define __UART_H_
#include<reg51.h>

void UARTInit(void);
void SendByte(unsigned char c);
