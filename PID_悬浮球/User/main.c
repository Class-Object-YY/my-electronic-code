// TIM��ͨ��-����-�������� Ӧ��
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_GeneralTim.h"  
#include "bsp_SysTick.h"
#include "HC_SR04.h"
#include "pid.h"

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
	
extern 	uint16_t CCR3_Val;
	
int main(void)
{
	float feed,p_i_d;
	int uuu;
	//��ʼ���δ�ʱ��
	SysTick_Init();		
	/* ���ڳ�ʼ�� */
	USART_Config();
	//��ʼ�����������
	HC_SR04_gpio_init();
	/* ��ʱ����ʼ�� */
	GENERAL_TIM_Init();
	//���pwm��ʼ��
	GENERAL_TIM_Init_PP();
	while ( 1 )
	{
	feed=20-HC_SR04_get_data();
	printf("\r\n**%f**\r\n",feed);	
//	p_i_d=pid_calculate(30,0,1.2,feed);	
//		p_i_d=pid_calculate(15,80,0.01,feed);	  13
//		p_i_d=pid_calculate(10.5,110,0.05,feed);
p_i_d=pid_calculate(9,370,0.015,feed);			
  uuu=p_i_d+660;
	CCR3_Val=(uint16_t)uuu;
   if(uuu<=0||uuu>3000)
	 {
	    if(uuu<=0)		 
		printf("\r\n**error-**\r\n");
		else 
			printf("\r\n**error+**\r\n");
	 }
	}
}
/*********************************************END OF FILE**********************/
//	printf("\r\n**%f**\r\n",p_i_d);	

