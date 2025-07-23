#ifndef __SYSTICK_H
#define __SYSTICK_H

#include <stdint.h>
#include "gpio.h"
void SysTick_Handler(void);
void SysTick_Init(uint32_t ticks_ms);
uint32_t millis(void);
void delay_ms(uint32_t ms);

#endif
