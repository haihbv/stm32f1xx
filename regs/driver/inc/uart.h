#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32_util.h"

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



#ifdef __cplusplus
}
#endif

#endif /* UART_H */
