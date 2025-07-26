#include "main.h"

void UART1_Config(void);
void UART2_Config(void);
void UART3_Config(void);
int main()
{
	RCC_Clock72MHz_HSE();
	SysTick_Init();
	UART1_Config();
	UART2_Config();
	UART3_Config();

	while (1)
	{
		USART_SendString(USART1, "Hello, USART1!\r\n");
		delay_ms(500);
		USART_SendString(USART2, "Hello, USART2!\r\n");
		delay_ms(500);
		USART_SendString(USART3, "Hello, USART3!\r\n");
		delay_ms(500);
	}
}

void UART1_Config(void)
{
	USART_HandleTypeDef uart;
	uart.USARTx = USART1;
	uart.BaudRate = USART_BRR_115200;
	uart.WordLength = USART_CR1_M;
	uart.StopBits = USART_CR2_STOP_1;
	uart.IRQ_Enable = ENABLE;
	USART_Init(&uart);
}

void UART2_Config(void)
{
	USART_HandleTypeDef uart;
	uart.USARTx = USART2;
	uart.BaudRate = USART_BRR_115200;
	uart.WordLength = USART_CR1_M;
	uart.StopBits = USART_CR2_STOP_1;
	uart.IRQ_Enable = ENABLE;
	USART_Init(&uart);
}

void UART3_Config(void)
{
	USART_HandleTypeDef uart;
	uart.USARTx = USART3;
	uart.BaudRate = USART_BRR_115200;
	uart.WordLength = USART_CR1_M;
	uart.StopBits = USART_CR2_STOP_1;
	uart.IRQ_Enable = ENABLE;
	USART_Init(&uart);
}
