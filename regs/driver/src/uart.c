#include "uart.h"

void USART1_Init(void)
{
    GPIO_InitTypeDef gpio;
    gpio.Mode = GPIO_MODE_AF_PP;
    gpio.Pin = GPIO_PIN_9;
    gpio.Speed = GPIO_SPEED_50MHZ;
    GPIO_Init(GPIOA, &gpio);

    gpio.Pin = GPIO_PIN_10;
    gpio.Mode = GPIO_MODE_INPUT;
    GPIO_Init(GPIOA, &gpio);

    USART1->BRR = 0x1D4C;
    SET_BIT(USART1->CR1, 1 << 13); // UE
    SET_BIT(USART1->CR1, 1 << 3);  // TE
    SET_BIT(USART1->CR1, 1 << 2);  // RE
    SET_BIT(USART1->CR1, 1 << 5);  // RXNEIE
		NVIC_EnableIRQ(USART1_IRQn);
    //NVIC->ISER[1] |= (1 << (37 - 32));
}
void USART1_SendChar(char c)
{
    while (!(READ_BIT(USART1->SR, 1 << 7)))
        ; // Wait until TXE is set

    USART1->DR = c;
}
void USART1_SendString(const char *str)
{
    while (*str)
    {
        USART1_SendChar(*str++);
    }
}
void USART1_IRQHandler(void)
{
    if (READ_BIT(USART1->SR, 1 << 5))
    {
        // doing something
        char reverseChar = (char)(USART1->DR & 0xFF);
        USART1_SendChar(reverseChar);
    }
}
