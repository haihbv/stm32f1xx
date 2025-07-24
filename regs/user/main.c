#include "main.h"

int main()
{
	RCC_Clock72MHz_HSE();
	SysTick_Init(72000);
	RCC_APB2ClockCmd(RCC_APB2_GPIOA | RCC_APB2_USART1, ENABLE);
	USART1_Init();

	while (1)
	{
		delay_ms(1000);
	}
}


