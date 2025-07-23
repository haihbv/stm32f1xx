#include "rcc.h"

void RCC_SystemClock_HSE_72MHz(void)
{
	/* Enable HSE */
	RCC->CR.BITS.HSEON = 1;
	while (!RCC->CR.BITS.HSERDY)
		;

	/* Configure Flash latency */
	FLASH->ACR.BITS.LATENCY = 2;

	/* Configure PLL: source = HSE, multiplier = x9 (8MHz * 9 = 72MHz) */
	RCC->CFGR.BITS.PLLSRC = 1;
	RCC->CFGR.BITS.PLLMUL = 7;
	RCC->CFGR.BITS.USBPRE = 0;

	RCC->CR.BITS.PLLON = 1;
	while (!RCC->CR.BITS.PLLRDY)
		;

	/* Prescalers */
	RCC->CFGR.BITS.HPRE = 0;  // AHB = SYSCLK
	RCC->CFGR.BITS.PPRE1 = 4; // APB1 = HCLK / 2
	RCC->CFGR.BITS.PPRE2 = 0; // APB2 = HCLK

	/* Switch to PLL as system clock */
	RCC->CFGR.BITS.SW = 2;
	while (RCC->CFGR.BITS.SWS != 2)
		;
}

/**
 * @brief  Enables or disables clock for a given peripheral (GPIO, AFIO, TIMx)
 * @param  periph: Peripheral to control, see @ref RCC_PeriphType
 * @param  enable: 1 to enable, 0 to disable
 * @retval None
 */
void RCC_PeripheralClockCmd(uint32_t periph_mask, uint8_t enable)
{
	if (enable)
	{
		// Enable trên APB2 (GPIO, AFIO, TIM1)
		uint32_t apb2_mask = periph_mask & 0xFFFF; // Lấy 16 bit thấp
		if (apb2_mask)
		{
			RCC->APB2ENR.REG |= apb2_mask;
		}

		// Enable trên APB1 (TIM2, TIM3, TIM4)
		uint32_t apb1_mask = (periph_mask >> 16) & 0xFFFF; // Lấy 16 bit cao, shift về bit thấp
		if (apb1_mask)
		{
			RCC->APB1ENR.REG |= apb1_mask;
		}
	}
	else
	{
		// Disable trên APB2
		uint32_t apb2_mask = periph_mask & 0xFFFF;
		if (apb2_mask)
		{
			RCC->APB2ENR.REG &= ~apb2_mask;
		}

		// Disable trên APB1
		uint32_t apb1_mask = (periph_mask >> 16) & 0xFFFF;
		if (apb1_mask)
		{
			RCC->APB1ENR.REG &= ~apb1_mask;
		}
	}
}
