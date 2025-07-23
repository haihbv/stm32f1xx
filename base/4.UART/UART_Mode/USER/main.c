#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_usart.h"            // Keil::Device:StdPeriph Drivers:USART
#include <string.h>

void USART1_Config(void);
void usart1_putChar(uint8_t c);
void usart1_putString(uint8_t *s);
uint8_t usart1_getChar(void);
void delay_ms(uint32_t ms);
void usart1_getString(uint8_t *buffer, uint16_t maxLen);
void GPIO_Config(void);
int main()
{
	uint8_t buffer[50];
	
	USART1_Config();
	GPIO_Config();
	while (1)
	{
		usart1_getString(buffer, sizeof(buffer));
		
		if (strcmp((char *)buffer, "Hello World!\n") == 0)
		{
			GPIO_ResetBits(GPIOC, GPIO_Pin_13);
			delay_ms(500);
		}
		else
		{
			GPIO_SetBits(GPIOC, GPIO_Pin_13);
			delay_ms(500);
		}
	}
}


void USART1_Config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	/* Cau hinh PA10 (USART1 RX) */
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	/* Cau hinh PA9 (USART1 TX) */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	/* __USART__ */
	
	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStruct);
	USART_Cmd(USART1, ENABLE);
}

/* Ham gui tung ky tu*/
void usart1_putChar(uint8_t c)
{
	USART_SendData(USART1, c);
	
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void usart1_putString(uint8_t *s)
{
	uint8_t i = 0;
	
	while (s[i] != 0)
	{
		usart1_putChar(s[i++]);
	}
}

uint8_t usart1_getChar(void)
{
	while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
	
	return USART_ReceiveData(USART1);
}

void usart1_getString(uint8_t *buffer, uint16_t maxLen)
{
	uint16_t i = 0;
	uint8_t ch;
	
	do
	{
		ch = usart1_getChar();
		
		if (ch == '\r') continue;
		
		if (ch != '\n' && i < (maxLen - 1))
		{
			buffer[i++] = ch;
		}
	} while (ch != '\n' && i < (maxLen - 1));
	
	buffer[i] = '\0';
}

void GPIO_Config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOC, &GPIO_InitStruct);

  GPIO_SetBits(GPIOC, GPIO_Pin_13); 
}
void delay_ms(uint32_t ms)
{
	volatile uint32_t i, j;
	for (i = 0; i < ms; i++)
	{
		for (j = 0; j < 0x2aff; j++)
		{
			__NOP();
		}
	}
}


