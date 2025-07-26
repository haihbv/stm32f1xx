#include "main.h"

int main()
{
	RCC_Clock72MHz_HSE();
	SysTick_Init();
	USART1_Init();

	while (1)
	{
		USART1_SendString("Hello from USART1\r\n");
		delay_ms(1000);
	}
}


