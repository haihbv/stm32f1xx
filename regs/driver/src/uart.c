#include "uart.h"

uint16_t USART_GetBaudRate(uint32_t baudrate)
{
    uint32_t usartdiv = (((uint32_t)72000000U) / (16U * (uint32_t)baudrate)) * 100U;
    uint16_t mantissa = (uint16_t)(usartdiv / 100U);
    uint16_t fraction = (uint16_t)((((usartdiv - (mantissa * 100U)) * 16U) + 50U) / 100U);
    return (uint16_t)((mantissa << 4) | (fraction & 0x0F));
}

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

    // USART1->BRR = 0x1D4C;
    USART1->BRR = USART_GetBaudRate(USART_BRR_115200);
    SET_BIT(USART1->CR1, 1 << 13); // UE
    SET_BIT(USART1->CR1, 1 << 3);  // TE
    SET_BIT(USART1->CR1, 1 << 2);  // RE
    SET_BIT(USART1->CR1, 1 << 5);  // RXNEIE
    NVIC_EnableIRQ(USART1_IRQn);
    // NVIC->ISER[1] |= (1 << (37 - 32));
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
