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

void RCC_APB1ClockCmd(uint32_t periph_mask, FunctionalState state)
{
	if (state == ENABLE)
	{
		RCC->APB1ENR.REG |= periph_mask; 
	}
	else
	{
		RCC->APB1ENR.REG &= ~periph_mask;
	}
}
void RCC_APB2ClockCmd(uint32_t periph_mask, FunctionalState state)
{
	if (state == ENABLE)
	{
		RCC->APB2ENR.REG |= periph_mask; 
	}
	else
	{
		RCC->APB2ENR.REG &= ~periph_mask;
	}
}
