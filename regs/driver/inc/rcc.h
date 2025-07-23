#ifndef RCC_H
#define RCC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32_util.h"

typedef union
{
	__IO uint32_t REG;
	struct
	{
		__IO uint32_t HSION 	: 1;
		__IO uint32_t HSIRDY 	: 1;
		__IO uint32_t RESERVED0 : 1;
		__IO uint32_t HSITRIM 	: 5;
		__IO uint32_t HSICAL 	: 8;
		__IO uint32_t HSEON 	: 1;
		__IO uint32_t HSERDY 	: 1;
		__IO uint32_t HSEBYP 	: 1;
		__IO uint32_t CSSON 	: 1;
		__IO uint32_t RESERVED1 : 4;
		__IO uint32_t PLLON 	: 1;
		__IO uint32_t PLLRDY 	: 1;
		__IO uint32_t RESERVED2 : 6;
	} BITS;
} RCC_CR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t SW 			: 2;
		uint32_t SWS 			: 2;
		uint32_t HPRE 			: 4;
		uint32_t PPRE1 			: 3;
		uint32_t PPRE2 			: 3;
		uint32_t ADCPRE 		: 2;
		uint32_t PLLSRC 		: 1;
		uint32_t PLLXTPRE 		: 1;
		uint32_t PLLMUL 		: 4;
		uint32_t USBPRE 		: 1;
		uint32_t RESERVED0 		: 1;
		uint32_t MCO 			: 3;
		uint32_t RESERVED1 		: 5;
	} BITS;
} RCC_CFGR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t LSIRDYF 		: 1;
		uint32_t LSERDYF 		: 1;
		uint32_t HSIRDYF 		: 1;
		uint32_t HSERDYF 		: 1;
		uint32_t PLLRDYF 		: 1;
		uint32_t RESERVED0 		: 2;
		uint32_t CSSF 			: 1;
		uint32_t LSIRDYIE 		: 1;
		uint32_t LSERDYIE 		: 1;
		uint32_t HSIRDYIE 		: 1;
		uint32_t HSERDYIE 		: 1;
		uint32_t PLLRDYIE 		: 1;
		uint32_t RESERVED1 		: 3;
		uint32_t LSIRDYC 		: 1;
		uint32_t LSERDYC 		: 1;
		uint32_t HSIRDYC 		: 1;
		uint32_t HSERDYC 		: 1;
		uint32_t PLLRDYC 		: 1;
		uint32_t RESERVED2 		: 2;
		uint32_t CSSC 			: 1;
		uint32_t RESERVED3 		: 8;
	} BITS;
} RCC_CIR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t AFIORST 		: 1;
		uint32_t RESERVED0 		: 1;
		uint32_t IOPARST 		: 1;
		uint32_t IOPBRST 		: 1;
		uint32_t IOPCRST 		: 1;
		uint32_t IOPDRST 		: 1;
		uint32_t IOPERST 		: 1;
		uint32_t IOPFRST 		: 1;
		uint32_t IOPGRST 		: 1;
		uint32_t ADC1RST 		: 1;
		uint32_t ADC2RST 		: 1;
		uint32_t TIM1RST 		: 1;
		uint32_t SPI1RST 		: 1;
		uint32_t TIM8RST 		: 1;
		uint32_t USART1RST 		: 1;
		uint32_t ADC3RST 		: 1;
		uint32_t RESERVED1 		: 3;
		uint32_t TIM9RST 		: 1;
		uint32_t TIM10RST 		: 1;
		uint32_t TIM11RST 		: 1;
		uint32_t RESERVED2 		: 10;
	} BITS;
} RCC_APB2RSTR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t TIM2RST 		: 1;
		uint32_t TIM3RST 		: 1;
		uint32_t TIM4RST 		: 1;
		uint32_t TIM5RST 		: 1;
		uint32_t TIM6RST 		: 1;
		uint32_t TIM7RST 		: 1;
		uint32_t TIM12RST 		: 1;
		uint32_t TIM13RST 		: 1;
		uint32_t TIM14RST 		: 1;
		uint32_t RESERVED0 		: 2;
		uint32_t WWDGRST 		: 1;
		uint32_t RESERVED1 		: 2;
		uint32_t SPI2RST 		: 1;
		uint32_t SPI3RST 		: 1;
		uint32_t RESERVED2 		: 1;
		uint32_t USART2RST 		: 1;
		uint32_t USART3RST 		: 1;
		uint32_t UART4RST 		: 1;
		uint32_t UART5RST 		: 1;
		uint32_t I2C1RST 		: 1;
		uint32_t I2C2RST 		: 1;
		uint32_t USBRST 		: 1;
		uint32_t RESERVED3 		: 1;
		uint32_t CANRST 		: 1;
		uint32_t RESERVED4 		: 1;
		uint32_t BKPRST 		: 1;
		uint32_t PWRRST 		: 1;
		uint32_t DACRST 		: 1;
		uint32_t RESERVED5 		: 2;
	} BITS;
} RCC_APB1RSTR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t DMA1EN 		: 1;
		uint32_t DMA2EN 		: 1;
		uint32_t SRAMEN 		: 1;
		uint32_t RESERVED0 		: 1;
		uint32_t FLITFEN 		: 1;
		uint32_t RESERVED1 		: 1;
		uint32_t CRCEN 			: 1;
		uint32_t RESERVED2 		: 1;
		uint32_t FSMCEN 		: 1;
		uint32_t RESERVED3 		: 1;
		uint32_t SDIOEN 		: 1;
		uint32_t RESERVED4 		: 21;
	} BITS;
} RCC_AHBENR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t AFIOEN 		: 1;
		uint32_t RESERVED0 		: 1;
		uint32_t IOPAEN 		: 1;
		uint32_t IOPBEN 		: 1;
		uint32_t IOPCEN 		: 1;
		uint32_t IOPDEN 		: 1;
		uint32_t IOPEEN 		: 1;
		uint32_t IOPFEN 		: 1;
		uint32_t IOPGEN 		: 1;
		uint32_t ADC1EN 		: 1;
		uint32_t ADC2EN 		: 1;
		uint32_t TIM1EN 		: 1;
		uint32_t SPI1EN 		: 1;
		uint32_t TIM8EN 		: 1;
		uint32_t USART1EN 		: 1;
		uint32_t ADC3EN 		: 1;
		uint32_t RESERVED1 		: 3;
		uint32_t TIM9EN 		: 1;
		uint32_t TIM10EN 		: 1;
		uint32_t TIM11EN 		: 1;
		uint32_t RESERVED2 		: 10;
	} BITS;
} RCC_APB2ENR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t TIM2EN 		: 1;
		uint32_t TIM3EN 		: 1;
		uint32_t TIM4EN 		: 1;
		uint32_t TIM5EN 		: 1;
		uint32_t TIM6EN 		: 1;
		uint32_t TIM7EN 		: 1;
		uint32_t TIM12EN 		: 1;
		uint32_t TIM13EN 		: 1;
		uint32_t TIM14EN 		: 1;
		uint32_t RESERVED0 		: 2;
		uint32_t WWDGEN 		: 1;
		uint32_t RESERVED1 		: 2;
		uint32_t SPI2EN 		: 1;
		uint32_t SPI3EN 		: 1;
		uint32_t RESERVED2 		: 1;
		uint32_t USART2EN 		: 1;
		uint32_t USART3EN 		: 1;
		uint32_t UART4EN 		: 1;
		uint32_t UART5EN 		: 1;
		uint32_t I2C1EN 		: 1;
		uint32_t I2C2EN 		: 1;
		uint32_t USBEN 			: 1;
		uint32_t RESERVED3 		: 1;
		uint32_t CANEN 			: 1;
		uint32_t RESERVED4 		: 1;
		uint32_t BKPEN 			: 1;
		uint32_t PWREN 			: 1;
		uint32_t DACEN 			: 1;
		uint32_t RESERVED5 		: 2;
	} BITS;
} RCC_APB1ENR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t LSEON 			: 1;
		uint32_t LSERDY 		: 1;
		uint32_t LSEBYP 		: 1;
		uint32_t RESERVED0 		: 5;
		uint32_t RTCSEL 		: 2;
		uint32_t RESERVED1 		: 5;
		uint32_t RTCEN 			: 1;
		uint32_t BDRST 			: 1;
		uint32_t RESERVED2 		: 15;
	} BITS;
} RCC_BDCR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t LSION 			: 1;
		uint32_t LSIRDY 		: 1;
		uint32_t RESERVED0 		: 22;
		uint32_t RMVF 			: 1;
		uint32_t RESERVED1 		: 1;
		uint32_t PINRSTF 		: 1;
		uint32_t PORRSTF 		: 1;
		uint32_t SFTRSTF 		: 1;
		uint32_t IWDGRSTF 		: 1;
		uint32_t WWDGRSTF 		: 1;
		uint32_t LPWRRSTF 		: 1;
	} BITS;
} RCC_CSR_t;

typedef union
{
	__IO uint32_t REG;
	struct
	{
		uint32_t LATENCY 		: 3;
		uint32_t HLFCYA 		: 1;
		uint32_t PRFTBE 		: 1;
		uint32_t PRFTBS 		: 1;
		uint32_t RESERVED 		: 26;
	} BITS;
} FLASH_ACR_t;

typedef struct
{
	FLASH_ACR_t ACR;
} FLASH_TypeDef;

typedef struct
{
	RCC_CR_t CR;
	RCC_CFGR_t CFGR;
	RCC_CIR_t CIR;
	RCC_APB2RSTR_t APB2RSTR;
	RCC_APB1RSTR_t APB1RSTR;
	RCC_AHBENR_t AHBENR;
	RCC_APB2ENR_t APB2ENR;
	RCC_APB1ENR_t APB1ENR;
	RCC_BDCR_t BDCR;
	RCC_CSR_t CSR;
} RCC_TypeDef;


#define RCC_APB2_AFIO 		((uint32_t)0x00000001)
#define RCC_APB2_GPIOA 		((uint32_t)0x00000004)
#define RCC_APB2_GPIOB 		((uint32_t)0x00000008)
#define RCC_APB2_GPIOC 		((uint32_t)0x00000010)
#define RCC_APB2_ADC1 		((uint32_t)0x00000200)
#define RCC_APB2_ADC2 		((uint32_t)0x00000400)
#define RCC_APB2_TIM1 		((uint32_t)0x00000800)
#define RCC_APB2_SPI1 		((uint32_t)0x00001000)
#define RCC_APB2_USART1 	((uint32_t)0x00004000)

#define RCC_APB1_TIM2 		((uint32_t)0x00000001)
#define RCC_APB1_TIM3 		((uint32_t)0x00000002)
#define RCC_APB1_TIM4 		((uint32_t)0x00000004)
#define RCC_APB1_WWDG 		((uint32_t)0x00000800)
#define RCC_APB1_SPI2 		((uint32_t)0x00004000)
#define RCC_APB1_SPI3 		((uint32_t)0x00008000)
#define RCC_APB1_USART2 	((uint32_t)0x00020000)
#define RCC_APB1_USART3 	((uint32_t)0x00040000)
#define RCC_APB1_I2C1 		((uint32_t)0x00200000)
#define RCC_APB1_I2C2 		((uint32_t)0x00400000)
#define RCC_APB1_USB 		((uint32_t)0x00800000)
#define RCC_APB1_CAN1 		((uint32_t)0x02000000)
#define RCC_APB1_CAN2 		((uint32_t)0x04000000)
#define RCC_APB1_BKP 		((uint32_t)0x08000000)
#define RCC_APB1_PWR 		((uint32_t)0x10000000)


void RCC_SystemClock_HSE_72MHz(void);
void RCC_APB2ClockCmd(uint32_t periph_mask, FunctionalState state);
void RCC_APB1ClockCmd(uint32_t periph_mask, FunctionalState state);

#ifdef __cplusplus
}
#endif

#endif /* RCC_H */
