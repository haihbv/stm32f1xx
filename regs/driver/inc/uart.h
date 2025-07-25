#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32_util.h"
#include "gpio.h"
#include "exti.h"

typedef struct
{
    __IO uint32_t SR;
    __IO uint32_t DR;
    __IO uint32_t BRR;
    __IO uint32_t CR1;
    __IO uint32_t CR2;
    __IO uint32_t CR3;
    __IO uint32_t GTPR;
} USART_TypeDef;

// USART baud rate definitions

#define USART_BRR_9600      9600U
#define USART_BRR_19200     19200U
#define USART_BRR_57600     57600U
#define USART_BRR_115200    115200U

uint16_t USART_GetBaudRate(uint32_t baudrate);
void USART1_Init(void);
void USART1_SendChar(char c);
void USART1_SendString(const char *str);
void USART1_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* UART_H */
