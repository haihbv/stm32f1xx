#include "main.h"

int main()
{
	SysTick_Init(72000);
	
	RCC_APB2ClockCmd(RCC_APB2_GPIOA | RCC_APB2_GPIOB, ENABLE);
	
	GPIO_InitTypeDef gpio;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pin = GPIO_PIN_0;
	gpio.Speed = GPIO_SPEED_50MHZ;
	GPIO_Init(GPIOA, &gpio);
	
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pin = GPIO_PIN_1;
	gpio.Speed = GPIO_SPEED_50MHZ;
	GPIO_Init(GPIOB, &gpio);
	
	
	while (1)
	{
		GPIO_WritePin(GPIOA, GPIO_PIN_0, BIT_RESET); GPIO_WritePin(GPIOB, GPIO_PIN_1, BIT_RESET);
		delay_ms(1000);
		GPIO_WritePin(GPIOA, GPIO_PIN_0, BIT_SET); GPIO_WritePin(GPIOB, GPIO_PIN_1, BIT_SET);
		delay_ms(1000);
	}
}
