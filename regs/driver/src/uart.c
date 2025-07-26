#include "uart.h"

#define USART_CR1_UE                (1U << 13) // USART Enable
#define USART_CR1_TE                (1U << 3)  // Transmitter Enable
#define USART_CR1_RE                (1U << 2)  // Receiver Enable
#define USART_CR1_RXNEIE            (1U << 5)  // RXNE Interrupt Enable

#define USART_CR1_ENABLE_MASK       (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE)
#define USART_CR1_IRQ_MASK          (USART_CR1_RXNEIE)

#define USART_SR_TXE                (1U << 7)  // Transmit Data Register Empty
#define USART_SR_RXNE               (1U << 5)  // Read Data Register Not Empty

#define USART_CLK_FRE_72Mhz       (72000000U) // Clock frequency for USART at 72MHz
#define USART_CLK_FRE_36Mhz       (36000000U) // Clock frequency for USART at 36MHz
#define USART_CLK_FRE_16Mhz       (16000000U) // Clock frequency for USART at 16MHz
#define USART_CLK_FRE_8Mhz        (8000000U)  // Clock frequency for USART at 8MHz

uint16_t USART_GetBaudRate(uint32_t pclk, uint32_t baudrate)
{
    uint32_t usartdiv = ((pclk) / (16U * (uint32_t)baudrate)) * 100U;
    uint16_t mantissa = (uint16_t)(usartdiv / 100U);
    uint16_t fraction = (uint16_t)((((usartdiv - (mantissa * 100U)) * 16U) + 50U) / 100U);
    return (uint16_t)((mantissa << 4) | (fraction & 0x0F));
}

void USART1_Init(void)
{
    RCC_APB2ClockCmd(RCC_APB2_GPIOA | RCC_APB2_USART1, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.Mode = GPIO_MODE_AF_PP;
    gpio.Pin = GPIO_PIN_9;
    gpio.Speed = GPIO_SPEED_50MHZ;
    GPIO_Init(GPIOA, &gpio);

    gpio.Pin = GPIO_PIN_10;
    gpio.Mode = GPIO_MODE_INPUT;
    GPIO_Init(GPIOA, &gpio);

    // USART1->BRR = 0x1D4C;
    USART1->BRR = USART_GetBaudRate(USART_CLK_FRE_72Mhz ,USART_BRR_9600);
    USART1->CR1 = 0; // Reset CR1
    SET_BIT(USART1->CR1, USART_CR1_ENABLE_MASK);    // Enable USART
    SET_BIT(USART1->CR1, USART_CR1_IRQ_MASK);       // Enable RXNE Interrupt
    NVIC_EnableIRQ(USART1_IRQn);
    // NVIC->ISER[1] |= (1 << (37 - 32));
}
void USART1_SendChar(char c)
{
    while (!(READ_BIT(USART1->SR, USART_SR_TXE)))
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
    if (READ_BIT(USART1->SR, USART_SR_RXNE))
    {
        // doing something
        char reverseChar = (char)(USART1->DR & 0xFF);
        USART1_SendChar(reverseChar);
    }
}
