#include "stm32f10x.h"

/* Prototype */
void SysTick_Handler(void);
void SysTick_Init(void);
void delay_us(uint32_t ms);
void delay_ms(uint32_t ms);

void ADC1_Init(void);
uint16_t Read_ADC(void);
void TIM2_PWM_Init(void);

static volatile uint32_t systick_us = 0;
int main()
{
	TIM2_PWM_Init();
	SysTick_Init();
	ADC1_Init();

	while (1)
	{
		uint16_t adc_val = Read_ADC();
		if (adc_val < 10) 
		{
			TIM_SetCompare2(TIM2, 0); // Dưới ngưỡng này tắt hẳn LED
		}
		else
		{
			TIM_SetCompare2(TIM2, adc_val);
		}
		delay_ms(10);
	}
}

void TIM2_PWM_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 4095;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 17 - 1;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC2Init(TIM2, &TIM_OCInitStruct);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM2, ENABLE);

	TIM_Cmd(TIM2, ENABLE);
}

void ADC1_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	ADC_InitTypeDef ADC_InitStruct;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStruct);

	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);

	ADC_Cmd(ADC1, ENABLE);

	ADC_ResetCalibration(ADC1);
	while (ADC_GetCalibrationStatus(ADC1))
		;
	ADC_StartCalibration(ADC1);
	while (ADC_GetCalibrationStatus(ADC1))
		;
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

uint16_t Read_ADC(void)
{
	return ADC_GetConversionValue(ADC1);
}

void SysTick_Init(void)
{
	SysTick_Config(SystemCoreClock / 1000000);
}

void delay_us(uint32_t us)
{
	systick_us = us;
	while (systick_us)
		;
}

void delay_ms(uint32_t ms)
{
	while (ms--)
	{
		delay_us(1000);
	}
}	

void SysTick_Handler(void)
{
	if (systick_us > 0)
	{
		systick_us--;
	}
}
