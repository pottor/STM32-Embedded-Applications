#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "exti.h"//4x4矩阵按键外部中断
#include "oled.h"
#include "random_generate.h"//生成随机数
#include "beep.h" //蜂鸣器驱动



 int main(void)
 {		
	extern int KeyValue;
	extern int randomValue;
	 
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口波特率115200
 	LED_Init();		  		 //初始化与LED连接的硬件接口
	OLED_Init();			   //初始化OLED  
	OLED_Clear();  
	EXTIX_Init();		 	   //外部中断初始�
	Adc_Init();          //adc初始化
	BEEP_Init();         	//初始化蜂鸣器端口


	KeyValue=17;
	led_output();//输出led随机显示
	 
//	OLED_ShowCHinese(0,0,0);//中
//	OLED_ShowCHinese(18,0,1);//景
//	OLED_ShowCHinese(36,0,2);//园
//	OLED_ShowCHinese(54,0,3);//电
//	OLED_ShowCHinese(72,0,4);//子
//	OLED_ShowCHinese(90,0,5);//科
//	OLED_ShowCHinese(108,0,6);//技
	


	while(1)
	{
//	OLED_Clear();
//		OLED_ShowCHinese(0,0,0);//中
//		OLED_ShowCHinese(18,0,1);//景
//		OLED_ShowCHinese(36,0,2);//园
//		OLED_ShowCHinese(54,0,3);//电 
//		OLED_ShowCHinese(72,0,4);//子
//		OLED_ShowCHinese(90,0,5);//科
//		OLED_ShowCHinese(108,0,6);//技
		
    if((KeyValue-1) == randomValue)
		{
				BEEP = 0;
				led_output();		
		}
		
		else
				BEEP = 1;
		
		delay_ms(50);

		
		OLED_ShowNum(0,2,(KeyValue-1),8,8);

	
	}
 }

