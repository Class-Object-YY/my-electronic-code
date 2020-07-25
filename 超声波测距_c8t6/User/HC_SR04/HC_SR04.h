#ifndef __HC_SR04_H
#define	__HC_SR04_H



// ³¬Éù²¨´¥·¢Òý½Å
#define  HC_SR04_GPIO_CLK        (RCC_APB2Periph_GPIOA)
#define  HC_SR04_GPIO_PORT       GPIOA   
#define  HC_SR04_GPIO_PIN        GPIO_Pin_1

void  HC_SR04_gpio_init(void);
void  HC_SR04_begining(void);
float  HC_SR04_get_data(void);

	
#endif  /*__HC_SR04_H*/






