#include "stm32f10x.h"                  // Device header

void GPIO_Config(void);
void TIM2_Config(void);
void TIM2_IRQHandler(void);
static volatile uint32_t millis = 0;
void delay_ms(uint32_t ms);
int main()
{
	SystemInit();
	GPIO_Config();
	TIM2_Config();
	
	while (1)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_13 | GPIO_Pin_14);
		delay_ms(1000);
		GPIO_SetBits(GPIOC, GPIO_Pin_13 | GPIO_Pin_14);
		delay_ms(1000);
	}
}
void GPIO_Config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
}

void TIM2_Config(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseInitTypeDef tim;
	tim.TIM_Period = 1000 - 1;        
	tim.TIM_Prescaler = 72 - 1;        
	tim.TIM_ClockDivision = TIM_CKD_DIV1;
	tim.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &tim);

	/* Bat chuc nang ngat cho TIM2 */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); // Update interrupt enabled  

	/* Bat ngat tai NVIC cho IRQ line */
	NVIC_InitTypeDef nvic;
	nvic.NVIC_IRQChannel = TIM2_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 0;
	nvic.NVIC_IRQChannelSubPriority = 0;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic);

	TIM_Cmd(TIM2, ENABLE); 
}

/* Ham xu ly ngat */
void TIM2_IRQHandler(void) // call function khi TIM2 phat sinh ngat
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) // Set bit TIMx_SR and TIMx_DIER
	{
		millis++;  
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // CLear bit TIMx_SR
	}
}


void delay_ms(uint32_t ms)
{
	uint32_t prev_time = millis;
	while (millis - prev_time < ms);
}


