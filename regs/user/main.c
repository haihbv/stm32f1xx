#include "main.h"

int main()
{
	SysTick_Init(72000);
	
	RCC_APB2ClockCmd(RCC_APB2_GPIOC, ENABLE);
	
	GPIO_InitTypeDef gpio;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pin = GPIO_PIN_15;
	gpio.Speed = GPIO_SPEED_2MHZ;
	GPIO_Init(GPIOC, &gpio);
	
	while (1)
	{
		GPIO_WritePin(GPIOC, GPIO_PIN_15, BIT_RESET);
		delay_ms(1000);
		GPIO_WritePin(GPIOC, GPIO_PIN_15, BIT_SET);
		delay_ms(1000);
	}
}
