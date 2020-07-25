#include "HC_SR04.h"
#include "stm32f10x.h"
#include "bsp_SysTick.h"
#include "bsp_GeneralTim.h"
#include "bsp_usart.h"

void  HC_SR04_gpio_init()
{
	//����gpio�Ľṹ��
	GPIO_InitTypeDef GPIO_InitStructure;
	// �򿪳�����GPIO��ʱ��
	RCC_APB2PeriphClockCmd(HC_SR04_GPIO_CLK, ENABLE);
	// ����Ϊ���츴��ģʽ
	GPIO_InitStructure.GPIO_Pin = HC_SR04_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HC_SR04_GPIO_PORT, &GPIO_InitStructure);
  //�ر�io��
  GPIO_ResetBits(HC_SR04_GPIO_PORT, HC_SR04_GPIO_PIN);

}


void  HC_SR04_begining(void)
{
  GPIO_SetBits(HC_SR04_GPIO_PORT, HC_SR04_GPIO_PIN);
   Delay_us(2);
  GPIO_ResetBits(HC_SR04_GPIO_PORT, HC_SR04_GPIO_PIN);
}

float  HC_SR04_get_data(void)
{
   uint32_t time;
	 float s;
	 uint32_t TIM_PscCLK = 72000000 / (GENERAL_TIM_PSC+1);
   HC_SR04_begining();
	while(TIM_ICUserValueStructure.Capture_FinishFlag != 1)
	{}
		if(TIM_ICUserValueStructure.Capture_FinishFlag == 1)
		{
			// ����ߵ�ƽʱ��ļ�������ֵ
			time = TIM_ICUserValueStructure.Capture_Period * (GENERAL_TIM_PERIOD+1) + 
			       (TIM_ICUserValueStructure.Capture_CcrValue+1);
			
			s=(float)time/TIM_PscCLK*170*100;
			// ��ӡ�ߵ�ƽ����ʱ��
			printf ( "%f\r\n",s);
			TIM_ICUserValueStructure.Capture_FinishFlag = 0;	
      Delay_ms(1);	     		
		}		
		return s;
}


