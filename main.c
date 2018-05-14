#include<reg51.h>
#include"lcd.h"
#include<string.h>
#include"temperature.h"
#include"bluetooth.h"

extern uchar flag;//�Ƿ������ݸ���
extern uchar BluRecData[];//�������յ�������֡
uchar now_time[]={"loading..."};
uchar *now_temp="Not ready";  //�ַ�ģʽ��ǰ�¶�
uchar mode=0;  //mode Ϊ0�Զ�ģʽ��modeΪ1�ֶ�ģʽ
float num_temp;	   //��ֵģʽ��ǰ�¶�
int TempDecThreshold = 45;//�����¶�
void DataResolve();	  //���������ܵ������ݽ��н���
main()
{
	LcdInit();
	BluInit();
	warming=0;
	cooling=0;
	num_temp=DS18B20NumTemp();
	now_temp=DS18B20toString(num_temp);	   
	LcdDisplayStr(0,0,now_time);

	while(1)
	{
		if(flag==1)//��������ݸ���
		{
			DataResolve();
			
		}
		num_temp=DS18B20NumTemp();
		now_temp=DS18B20toString(num_temp);

		LcdDisplayStr(0,1,"T ");
		LcdDisplayStr(2,1,now_temp);
		LcdDisplayChar(7,1,'C');

		BluSendByte(0x7F);
		BluSendStr(now_temp);
		BluSendByte(0x7F);

		//now_temp = TempFormat(now_temp);
		flag=0;//ÿ��ѭ������������Ϊ�����ݸ���״̬
		Lcd_Delay1ms(100);
	}
}

void DataResolve()
{
	uchar i;
//	static uchar tmp_time[17];
	i=1;
 	if(BluRecData[0]=='0') //����
	{	
		while(BluRecData[i] != '\0')
		{
		   now_time[i-1] = BluRecData[i];
		   i++;
		}
		LcdDisplayStr(0,0,now_time);		
	}
	else				 //ָ��
	{
		  switch(BluRecData[1])
		  {
			case '0': warming = 1;			   //��������
					  break;
			case '1': warming = 0;			   //�رռ���
					  break;
			case '2': cooling = 1;			   //����ɢ��
					  break;
			case '3': cooling = 0;  			   //�ر�ɢ��

			case '4':			   //���ñ����¶�
					  break;
			default:  break;		 				 
		  }
	}

}
