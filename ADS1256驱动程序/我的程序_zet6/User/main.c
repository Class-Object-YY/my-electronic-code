/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   �����жϽ��ղ���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-�Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart.h"
#include "ADS1256.h"
#include "bsp_SysTick.h"

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
	int Adc;
	float Volts,Volts2;
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
	SysTick_Init();
	Init_ADS1256_GPIO(); //��ʼ��ADS1256 GPIO�ܽ�
  Delay_ms(50);
  ADS1256_Init(ADS1256_GAIN_1);
  while(1)
	{	
		Adc = ADS1256ReadData(ADS1256_MUXP_AIN0| ADS1256_MUXN_AINCOM);// �൱�� ( ADS1256_MUXP_AIN0 | ADS1256_MUXN_AINCOM);		
    Volts = ads_v(Adc,ADS1256_GAIN_1);
		Volts2=Adc*0.000000596;
		printf(" %.4fV  ",Volts);			
		printf("\r\n"); 
		printf(" *%.4fV*  ",Volts2);			
		printf("\r\n"); 
	}	
}


/*********************************************END OF FILE**********************/
