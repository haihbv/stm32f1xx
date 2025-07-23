#ifndef BUTTON_H
#define BUTTON_H


#include <stdio.h>
#include <stdint.h>
#include "stm32f10x.h"

/*
 *
 */

void Delay_ms(uint32_t ms);
void Led_Init(void);
void Button_Init(void);
void Button_Update(void);  
void LED_PIN_13(void); // nhan giu
void LED_PIN_14(void); // double click
void LED_PIN_15(void); // led sang khi nhan giu, led tat khi double click
void LED_MIXED(void); // 3 led 13, 14, 15 sang dan tu trai sang phai xong phai sang trai


uint8_t Button_IsPressed(void);
uint8_t Button2_IsPressed(void);
uint8_t Button_IsLongPressed(void);     
uint8_t Button_IsDoubleClicked(void);  

#endif /* BUTTON_H */
