#ifndef _GPIO_H
#define _GPIO_H

#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"

#define LEDON GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
#define LEDOFF GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
#define PC13 GPIOx_Init(GPIOC, GPIO_Pin_13, GPIO_Mode_Out_PP, GPIO_Speed_50MHz);
void delay(unsigned int time);
void config_led(void);
void blink(void);

void GPIOx_Init(GPIO_TypeDef* GPIOx, uint16_t PINx, GPIOMode_TypeDef MODEx, GPIOSpeed_TypeDef SPEEDx);
#endif
