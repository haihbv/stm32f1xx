#include "rcc.h"

// Cấu hình hệ thống sử dụng HSE làm nguồn xung và thiết lập SYSCLK = 72MHz
void RCC_Clock72MHz_HSE(void)
{
	// Bật HSE (High Speed External oscillator)
	RCC->CR.BITS.HSEON = 1;
	// Chờ HSE sẵn sàng
	while (!RCC->CR.BITS.HSERDY)
		;

	// Thiết lập độ trễ Flash phù hợp với tần số hệ thống (2 chu kỳ cho 72MHz)
	FLASH->ACR.BITS.LATENCY = 2;

	// Chọn nguồn PLL là HSE
	RCC->CFGR.BITS.PLLSRC = 1;
	// Nhân tần số PLL lên 9 lần (8MHz x 9 = 72MHz)
	RCC->CFGR.BITS.PLLMUL = 7;
	// Cấu hình tần số USB (chia 1.5)
	RCC->CFGR.BITS.USBPRE = 0;

	// Bật PLL
	RCC->CR.BITS.PLLON = 1;
	// Chờ PLL sẵn sàng
	while (!RCC->CR.BITS.PLLRDY)
		;

	// Chia tần số AHB = SYSCLK/1
	RCC->CFGR.BITS.HPRE = 0;
	// Chia tần số APB1 = HCLK/2 (tối đa 36MHz)
	RCC->CFGR.BITS.PPRE1 = 4;
	// Chia tần số APB2 = HCLK/1
	RCC->CFGR.BITS.PPRE2 = 0;

	// Chọn PLL làm nguồn xung hệ thống (SYSCLK)
	RCC->CFGR.BITS.SW = 2;
	// Chờ chuyển đổi nguồn xung hệ thống sang PLL
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
