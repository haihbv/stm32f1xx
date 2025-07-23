#include "gpio.h"
               

void delay(unsigned int time)	
{
	volatile unsigned int i, j;
	for (i = 0; i < time; i++) {
		for (j = 0; j < 0x2aff; j++);
	}
}
void config_led(void)	
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void blink(void)
{
	LEDON
	//GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
	//GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	delay(500);
	LEDOFF
	//GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
	//GPIO_SetBits(GPIOC, GPIO_Pin_13);
	delay(500);
}


void GPIOx_Init(GPIO_TypeDef* GPIOx, uint16_t PINx, GPIOMode_TypeDef MODEx, GPIOSpeed_TypeDef SPEEDx)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	if (GPIOx == GPIOA)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	}
	if (GPIOx == GPIOB)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	}
	if (GPIOx == GPIOC)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	}
	
	GPIO_InitStruct.GPIO_Mode = MODEx;
	GPIO_InitStruct.GPIO_Pin = PINx;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx, &GPIO_InitStruct);
}
