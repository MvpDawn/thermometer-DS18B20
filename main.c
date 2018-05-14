#include<reg51.h>
#include"lcd.h"
#include<string.h>
#include"temperature.h"
#include"bluetooth.h"

extern uchar flag;//是否有数据更新
extern uchar BluRecData[];//蓝牙接收到的数据帧
uchar now_time[]={"loading..."};
uchar *now_temp="Not ready";  //字符模式当前温度
uchar mode=0;  //mode 为0自动模式，mode为1手动模式
float num_temp;	   //数值模式当前温度
int TempDecThreshold = 45;//报警温度
void DataResolve();	  //对蓝牙接受到的数据进行解析
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
		if(flag==1)//如果有数据更新
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
		flag=0;//每趟循环结束，设置为无数据更新状态
		Lcd_Delay1ms(100);
	}
}

void DataResolve()
{
	uchar i;
//	static uchar tmp_time[17];
	i=1;
 	if(BluRecData[0]=='0') //数据
	{	
		while(BluRecData[i] != '\0')
		{
		   now_time[i-1] = BluRecData[i];
		   i++;
		}
		LcdDisplayStr(0,0,now_time);		
	}
	else				 //指令
	{
		  switch(BluRecData[1])
		  {
			case '0': warming = 1;			   //开启加热
					  break;
			case '1': warming = 0;			   //关闭加热
					  break;
			case '2': cooling = 1;			   //开启散热
					  break;
			case '3': cooling = 0;  			   //关闭散热

			case '4':			   //设置报警温度
					  break;
			default:  break;		 				 
		  }
	}

}
