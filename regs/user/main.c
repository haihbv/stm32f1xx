#include "rcc.h"
#include "gpio.h"
#include "systick.h"

void GPIO_Config(void);

int main()
{
	SysTick_Init(72000);
	GPIO_Config();

	while (1)
	{
		GPIO_WritePin(GPIOC, GPIO_PIN_13, BIT_RESET);
		delay_ms(1000);
		GPIO_WritePin(GPIOC, GPIO_PIN_13, BIT_SET);
		delay_ms(1000);
	}
}

void GPIO_Config(void)
{
	RCC_APB2ClockCmd(RCC_APB2_GPIOC, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_50MHZ;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
}
