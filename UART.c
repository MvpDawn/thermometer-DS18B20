#include <UART.h>

void UARTInit(void)
{
    TMOD = 0x20;
    SCON = 0x50;
    TH1 = 0xFD;
    TL1 = TH1;
    PCON = 0x00;
    EA = 1;
    ES = 1;
    TR1 = 1;
}

void SendByte(unsigned char c)
{
    SBUF = c;
    while(!TI);
    TI = 0;
}

void UARTReceive(void) interrupt 4 //Ω” ’÷–∂œ
{
    if(RI)
    {
        RI = 0;
        SendByte(SBUF);
    }
    else
        TI = 0;
}

