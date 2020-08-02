/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   串口中断接收测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart.h"
#include "ADS1256.h"
#include "bsp_SysTick.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
	int Adc;
	float Volts,Volts2;
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();
	SysTick_Init();
	Init_ADS1256_GPIO(); //初始化ADS1256 GPIO管脚
  Delay_ms(50);
  ADS1256_Init(ADS1256_GAIN_1);
  while(1)
	{	
		Adc = ADS1256ReadData(ADS1256_MUXP_AIN0| ADS1256_MUXN_AINCOM);// 相当于 ( ADS1256_MUXP_AIN0 | ADS1256_MUXN_AINCOM);		
    Volts = ads_v(Adc,ADS1256_GAIN_1);
		Volts2=Adc*0.000000596;
		printf(" %.4fV  ",Volts);			
		printf("\r\n"); 
		printf(" *%.4fV*  ",Volts2);			
		printf("\r\n"); 
	}	
}


/*********************************************END OF FILE**********************/
