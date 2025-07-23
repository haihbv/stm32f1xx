#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM


void GPIOC_Init(void);
void TIM2_Init(void);

int main()
{
	SystemInit();
	GPIOC_Init();
	TIM2_Init();
	
	while (1)
	{
		if (TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) == SET)
		{
			TIM_ClearFlag(TIM2, TIM_FLAG_Update);
			
			GPIOC->ODR ^= GPIO_Pin_13 | GPIO_Pin_14;
		}
	}
}

void GPIOC_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &GPIO_InitStruct);
}
void TIM2_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStruct.TIM_Period = 10000 - 1;
	TIM_InitStruct.TIM_Prescaler = 7200 - 1;
	TIM_InitStruct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM2, &TIM_InitStruct);
	
	TIM_Cmd(TIM2, ENABLE);
}
