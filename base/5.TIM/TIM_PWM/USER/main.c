#include "stm32f10x_rcc.h"	// Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_gpio.h" // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_tim.h"	// Keil::Device:StdPeriph Drivers:TIM


#define SERVO_MIN 500
#define SERVO_MAX 2500

/**
 *========================= PWM OUTPUT ===============================
 * Servo (SG90)
 * Do sang Led
 * Toc do dong co DC
 *====================================================================
 **/
 
 /**
 *========================= PWM INPUT ================================
 * Doc tin hieu tu cam bien - VD: cam bien sieu am HC-SR04 phat xung
 * Doc tin hieu RC - tay dieu khien may bay, robot, ...
 * Do toc do, tan so tin hieu - dua tren xung dau vao
 *====================================================================
 **/
 

/*========================= PROTOTYPE =========================*/
void GPIO_Config(void);
void TIM2_PWM_Config(void);
void TIM3_PWM_Delay(void);
void Servo_SetAngle(uint8_t angle);

void TIM3_IRQHandler(void);
void delay_ms(uint32_t time);

/*====================== GLOBAL VARIABLE ======================*/
static volatile uint32_t millis = 0;

int main()
{
	SystemInit();
	GPIO_Config();
	TIM2_PWM_Config();
	TIM3_PWM_Delay();
	while (1)
	{
		Servo_SetAngle(0);
		delay_ms(1000);
		Servo_SetAngle(90);
		delay_ms(1000);
		Servo_SetAngle(180);
		delay_ms(1000);
	}
}

void GPIO_Config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	gpio.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; // PA0: TIM2_CH1, PA1: TIM2_CH2
	GPIO_Init(GPIOA, &gpio);
}

void TIM2_PWM_Config(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseInitTypeDef tim;
	tim.TIM_Prescaler = 72 - 1;
	tim.TIM_Period = 20000 - 1;
	tim.TIM_RepetitionCounter = 0;
	tim.TIM_ClockDivision = TIM_CKD_DIV1;
	tim.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &tim);

	TIM_OCInitTypeDef pwm;
	pwm.TIM_OCMode = TIM_OCMode_PWM1;
	pwm.TIM_OutputState = TIM_OutputState_Enable;
	pwm.TIM_Pulse = 1500;
	pwm.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM2, &pwm);
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

	TIM_OC2Init(TIM2, &pwm);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM2, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
}

void Servo_SetAngle(uint8_t angle)
{
	if (angle > 180)
		angle = 180;
	uint16_t pulse1 = SERVO_MIN + ((SERVO_MAX - SERVO_MIN) * angle) / 180;
	uint16_t pulse2 = SERVO_MIN + ((SERVO_MAX - SERVO_MIN) * (180 - angle)) / 180;
	TIM2->CCR1 = pulse1;
	TIM2->CCR2 = pulse2;
}

void TIM3_PWM_Delay(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	/* Config frequency timer for delay 1 ms */
	TIM_TimeBaseInitTypeDef tim3;
	
	tim3.TIM_Prescaler = 72 - 1;
	tim3.TIM_Period = 999;
	tim3.TIM_RepetitionCounter = 0;
	tim3.TIM_ClockDivision = TIM_CKD_DIV1;
	tim3.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &tim3);
	
	TIM_Cmd(TIM3, ENABLE);
	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	/* Config NVIC */
	NVIC_InitTypeDef nvic;
	nvic.NVIC_IRQChannel = TIM3_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 0;
	nvic.NVIC_IRQChannelSubPriority = 0;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic);
}


void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
	{
		millis++;
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}

void delay_ms(uint32_t time)
{
	uint32_t start = millis;
	while (millis - start < time);
}
