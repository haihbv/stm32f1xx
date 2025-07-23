#include "stm32f10x.h"

// Prototype
void GPIO_Config(void);
void TIM2_Config_1ms(void);
void delay_start(uint32_t ms);
uint8_t delay_is_done(void);

// Biến quản lý delay
volatile uint32_t tim2_millis = 0;
volatile uint32_t delay_start_time = 0;
volatile uint32_t delay_duration = 0;
volatile uint8_t  is_delaying = 0;

int main()	
{
	GPIO_Config();
	TIM2_Config_1ms();

	delay_start(1000); // bắt đầu delay 1s

	while (1)
	{
		if (delay_is_done())
		{
			GPIOC->ODR ^= GPIO_Pin_13;  // Toggle LED
			delay_start(1000);          // delay tiếp 1s nữa
		}

		// Các xử lý khác vẫn hoạt động được tại đây
	}
}

void GPIO_Config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
}

void TIM2_Config_1ms(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseInitTypeDef tim;
	tim.TIM_ClockDivision = TIM_CKD_DIV1;
	tim.TIM_CounterMode = TIM_CounterMode_Up;
	tim.TIM_Period = 1000 - 1;       // 1000 tick → 1ms
	tim.TIM_Prescaler = 72 - 1;      // 72MHz / 72 = 1MHz → 1 tick = 1us
	tim.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &tim);

	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);  // Bật ngắt overflow
	TIM_Cmd(TIM2, ENABLE);

	// Bật NVIC cho TIM2
	NVIC_InitTypeDef nvic;
	nvic.NVIC_IRQChannel = TIM2_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 0;
	nvic.NVIC_IRQChannelSubPriority = 0;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic);
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
		tim2_millis++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
void delay_start(uint32_t ms)
{
	delay_start_time = tim2_millis;
	delay_duration = ms;
	is_delaying = 1;
}

uint8_t delay_is_done(void)
{
	if (is_delaying && (tim2_millis - delay_start_time >= delay_duration))
	{
		is_delaying = 0;
		return 1; // xong delay
	}
	return 0; // chưa xong
}

