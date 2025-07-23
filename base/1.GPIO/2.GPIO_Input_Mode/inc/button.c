#include "button.h"

static uint8_t last_state = 1;
static uint32_t press_start = 0;
// static uint32_t last_release = 0;
static uint8_t click_count = 0;

static uint8_t flag_long_press = 0;
static uint8_t flag_double_click = 0;


void Delay_ms(uint32_t ms)
{
	volatile uint32_t i, j;
	for (i = 0; i < ms; i++)
	{
		for (j = 0; j < 0x2aff; j++)
		{
			__NOP();
		}
	}
}

void Led_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpio);
}

void Button_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Mode = GPIO_Mode_IPU;
    gpio.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; 
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &gpio);
}


uint8_t Button_IsPressed(void)
{
    return (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0);
}

uint8_t Button2_IsPressed(void)
{
    return (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
}
void Button_Update(void)
{
	uint8_t current = Button_IsPressed();
	
	if (current != last_state)
	{
		if (!current) // vua nhan
		{
			press_start = 0;
			for (volatile uint32_t i = 0; i < 1000; i++)
			{
				if (!Button_IsPressed())
				{
					break;
				}
				Delay_ms(1);
				press_start++;
			}
			
			if (press_start >= 250)
			{
				flag_long_press = 1;
				click_count = 0;
				while (Button_IsPressed());
			}
			else
			{
				while (Button_IsPressed());
				Delay_ms(25);
				
				if (Button_IsPressed())
				{
					while (Button_IsPressed());
					flag_double_click = 1;
				}
					
			}
		}
		
		last_state = current;
	}
}

uint8_t Button_IsLongPressed(void)
{
	if (flag_long_press)
	{
		flag_long_press = 0;
		return 1;
	}
	return 0;
}

uint8_t Button_IsDoubleClicked(void)
{
	if (flag_double_click)
	{
		flag_double_click = 0;
		return 1;
	}
	return 0;
}

void LED_PIN_13(void)
{
    if (Button_IsLongPressed())
        GPIOC->ODR ^= GPIO_Pin_13; // Toggle LED13
}

void LED_PIN_14(void)
{
    if (Button_IsDoubleClicked())
        GPIOC->ODR ^= GPIO_Pin_14; // Toggle LED14
}

void LED_PIN_15(void)
{
    if (Button_IsLongPressed())
        GPIOC->ODR ^= GPIO_Pin_15; // Toggle khi nh?n gi?

    if (Button_IsDoubleClicked())
        GPIOC->ODR ^= GPIO_Pin_15; // Toggle khi double click
        
}

void LED_MIXED(void)
{
    uint16_t leds[] = {GPIO_Pin_13, GPIO_Pin_14, GPIO_Pin_15};

    for (int i = 0; i < 3; i++)
    {
        GPIO_SetBits(GPIOC, leds[i]);
        Delay_ms(200);
    }
    for (int i = 2; i >= 0; i--)
    {
        GPIO_ResetBits(GPIOC, leds[i]);
        Delay_ms(200);
    }
}
