#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H


#include "stm32f10x.h"


/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM5

#define            GENERAL_TIM                   TIM3
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM_PERIOD            0XFFFF
#define            GENERAL_TIM_PSC              (72-1)

// TIM ���벶��ͨ��GPIO��غ궨��
#define            GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH1_PORT          GPIOA
#define            GENERAL_TIM_CH1_PIN           GPIO_Pin_6
#define            GENERAL_TIM_CHANNEL_x         TIM_Channel_1

// �ж���غ궨��
#define            GENERAL_TIM_IT_CCx            TIM_IT_CC1
#define            GENERAL_TIM_IRQ               TIM3_IRQn
#define            GENERAL_TIM_INT_FUN           TIM3_IRQHandler

// ��ȡ����Ĵ���ֵ�����궨��
#define            GENERAL_TIM_GetCapturex_FUN                 TIM_GetCapture1
// �����źż��Ժ����궨��
#define            GENERAL_TIM_OCxPolarityConfig_FUN           TIM_OC1PolarityConfig

// ��������ʼ����
#define            GENERAL_TIM_STRAT_ICPolarity                TIM_ICPolarity_Rising
// �����Ľ�������
#define            GENERAL_TIM_END_ICPolarity                  TIM_ICPolarity_Falling
/************************************************************************************************************************************************/


/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM3

#define            GENERAL_TIM_PP                   TIM2
#define            GENERAL_TIM_APBxClock_FUN_PP      RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK_PP                RCC_APB1Periph_TIM2
#define            GENERAL_TIM_Period_PP             2999
#define            GENERAL_TIM_Prescaler_PP          71

// TIM3 ����Ƚ�ͨ��3
#define            GENERAL_TIM_CH4_GPIO_CLK_PP       RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH4_PORT_PP           GPIOA
#define            GENERAL_TIM_CH4_PIN_PP            GPIO_Pin_3


// �ж���غ궨��
#define            GENERAL_TIM_IRQ_PP                TIM2_IRQn
#define            GENERAL_TIM_INT_FUN_PP            TIM2_IRQHandler



/**************************��������********************************/






// ��ʱ�����벶���û��Զ�������ṹ������
typedef struct
{   
	uint8_t   Capture_FinishFlag;   // ���������־λ
	uint8_t   Capture_StartFlag;    // ����ʼ��־λ
	uint16_t  Capture_CcrValue;     // ����Ĵ�����ֵ
	uint16_t  Capture_Period;       // �Զ���װ�ؼĴ������±�־ 
}TIM_ICUserValueTypeDef;

extern TIM_ICUserValueTypeDef TIM_ICUserValueStructure;

/**************************��������********************************/
void GENERAL_TIM_Init(void);
void GENERAL_TIM_Init_PP (void);
void PWM_Width_change(uint32_t m);

#endif	/* __BSP_GENERALTIME_H */


