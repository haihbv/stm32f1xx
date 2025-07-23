/**
  ******************************************************************************
  * @file    rcc.h
  * @author  STM32 Register Driver
  * @version V1.0.0
  * @date    21-July-2025
  * @brief   This file contains all the functions prototypes for the RCC firmware 
  *          library.
  ******************************************************************************
  * @attention
  *
  * This module provides low-level access to STM32F1xx RCC (Reset and Clock Control)
  * peripheral registers using union-based bit-field structures for efficient
  * register manipulation.
  *
  ******************************************************************************
  */

#ifndef RCC_H
#define RCC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32_util.h"

/** @addtogroup STM32F1xx_Register_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */ 

/** @defgroup RCC_Exported_Types
  * @{
  */

/**
  * @brief  Clock control register (RCC_CR)
  * @note   This register provides control over the main clock sources:
  *         - HSI (High Speed Internal) oscillator
  *         - HSE (High Speed External) oscillator  
  *         - PLL (Phase Locked Loop)
  */
typedef union {
	__IO uint32_t REG;
	struct {
		__IO uint32_t HSION     : 1; /*!< Bit 0 HSION: Internal high-speed clock enable */
		__IO uint32_t HSIRDY    : 1; /*!< Bit 1 HSIRDY: Internal high-speed clock ready flag */
		__IO uint32_t RESERVED0 : 1; /*!< Bit 2 Reserved, must be kept at reset value */
		__IO uint32_t HSITRIM   : 5; /*!< Bits 7:3 HSITRIM: Internal high-speed clock trimming */
		__IO uint32_t HSICAL    : 8; /*!< Bits 15:8 HSICAL: Internal high-speed clock calibration */
		__IO uint32_t HSEON     : 1; /*!< Bit 16 HSEON: External high-speed clock enable */
		__IO uint32_t HSERDY    : 1; /*!< Bit 17 HSERDY: External high-speed clock ready flag */
		__IO uint32_t HSEBYP    : 1; /*!< Bit 18 HSEBYP: External high-speed clock bypass */
		__IO uint32_t CSSON     : 1; /*!< Bit 19 CSSON: Clock security system enable */
		__IO uint32_t RESERVED1 : 4; /*!< Bits 23:20 Reserved, must be kept at reset value */
		__IO uint32_t PLLON     : 1; /*!< Bit 24 PLLON: PLL enable */
		__IO uint32_t PLLRDY    : 1; /*!< Bit 25 PLLRDY: PLL clock ready flag */
		__IO uint32_t RESERVED2 : 6; /*!< Bits 31:26 Reserved, must be kept at reset value */
	} BITS;
} RCC_CR_t;

/**
  * @brief  Clock configuration register (RCC_CFGR)
  * @note   This register configures the system clock source and prescalers:
  *         - System clock switch and status
  *         - AHB, APB1, APB2 prescalers
  *         - PLL configuration
  *         - Microcontroller clock output
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t SW        : 2; /*!< Bits 1:0 SW: System clock switch */
		uint32_t SWS       : 2; /*!< Bits 3:2 SWS: System clock switch status */
		uint32_t HPRE      : 4; /*!< Bits 7:4 HPRE: AHB prescaler */
		uint32_t PPRE1     : 3; /*!< Bits 10:8 PPRE1: APB low-speed prescaler (APB1) */
		uint32_t PPRE2     : 3; /*!< Bits 13:11 PPRE2: APB high-speed prescaler (APB2) */
		uint32_t ADCPRE    : 2; /*!< Bits 15:14 ADCPRE: ADC prescaler */
		uint32_t PLLSRC    : 1; /*!< Bit 16 PLLSRC: PLL entry clock source */
		uint32_t PLLXTPRE  : 1; /*!< Bit 17 PLLXTPRE: HSE divider for PLL entry */
		uint32_t PLLMUL    : 4; /*!< Bits 21:18 PLLMUL: PLL multiplication factor */
		uint32_t USBPRE    : 1; /*!< Bit 22 USBPRE: USB prescaler */
		uint32_t RESERVED0 : 1; /*!< Bit 23 Reserved, must be kept at reset value */
		uint32_t MCO       : 3; /*!< Bits 26:24 MCO: Microcontroller clock output */
		uint32_t RESERVED1 : 5; /*!< Bits 31:27 Reserved, must be kept at reset value */
	} BITS;
} RCC_CFGR_t;

/**
  * @brief  Clock interrupt register (RCC_CIR)
  * @note   This register provides interrupt flags and enable/clear bits for:
  *         - LSI, LSE, HSI, HSE, PLL ready interrupts
  *         - Clock security system interrupt
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t LSIRDYF   : 1; /*!< Bit 0 LSIRDYF: LSI ready interrupt flag */
		uint32_t LSERDYF   : 1; /*!< Bit 1 LSERDYF: LSE ready interrupt flag */
		uint32_t HSIRDYF   : 1; /*!< Bit 2 HSIRDYF: HSI ready interrupt flag */
		uint32_t HSERDYF   : 1; /*!< Bit 3 HSERDYF: HSE ready interrupt flag */
		uint32_t PLLRDYF   : 1; /*!< Bit 4 PLLRDYF: PLL ready interrupt flag */
		uint32_t RESERVED0 : 2; /*!< Bits 6:5 Reserved, must be kept at reset value */
		uint32_t CSSF      : 1; /*!< Bit 7 CSSF: Clock security system interrupt flag */
		uint32_t LSIRDYIE  : 1; /*!< Bit 8 LSIRDYIE: LSI ready interrupt enable */
		uint32_t LSERDYIE  : 1; /*!< Bit 9 LSERDYIE: LSE ready interrupt enable */
		uint32_t HSIRDYIE  : 1; /*!< Bit 10 HSIRDYIE: HSI ready interrupt enable */
		uint32_t HSERDYIE  : 1; /*!< Bit 11 HSERDYIE: HSE ready interrupt enable */
		uint32_t PLLRDYIE  : 1; /*!< Bit 12 PLLRDYIE: PLL ready interrupt enable */
		uint32_t RESERVED1 : 3; /*!< Bits 15:13 Reserved, must be kept at reset value */
		uint32_t LSIRDYC   : 1; /*!< Bit 16 LSIRDYC: LSI ready interrupt clear */
		uint32_t LSERDYC   : 1; /*!< Bit 17 LSERDYC: LSE ready interrupt clear */
		uint32_t HSIRDYC   : 1; /*!< Bit 18 HSIRDYC: HSI ready interrupt clear */
		uint32_t HSERDYC   : 1; /*!< Bit 19 HSERDYC: HSE ready interrupt clear */
		uint32_t PLLRDYC   : 1; /*!< Bit 20 PLLRDYC: PLL ready interrupt clear */
		uint32_t RESERVED2 : 2; /*!< Bits 22:21 Reserved, must be kept at reset value */
		uint32_t CSSC      : 1; /*!< Bit 23 CSSC: Clock security system interrupt clear */
		uint32_t RESERVED3 : 8; /*!< Bits 31:24 Reserved, must be kept at reset value */
	} BITS;
} RCC_CIR_t;

/**
  * @brief  APB2 peripheral reset register (RCC_APB2RSTR)
  * @note   This register provides reset control for APB2 peripherals including:
  *         - GPIO ports, AFIO
  *         - ADC1/2/3, TIM1/8/9/10/11
  *         - SPI1, USART1
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t AFIORST   : 1; /*!< Bit 0 AFIORST: Alternate function I/O reset */
		uint32_t RESERVED0 : 1; /*!< Bit 1 Reserved, must be kept at reset value */
		uint32_t IOPARST   : 1; /*!< Bit 2 IOPARST: I/O port A reset */
		uint32_t IOPBRST   : 1; /*!< Bit 3 IOPBRST: I/O port B reset */
		uint32_t IOPCRST   : 1; /*!< Bit 4 IOPCRST: I/O port C reset */
		uint32_t IOPDRST   : 1; /*!< Bit 5 IOPDRST: I/O port D reset */
		uint32_t IOPERST   : 1; /*!< Bit 6 IOPERST: I/O port E reset */
		uint32_t IOPFRST   : 1; /*!< Bit 7 IOPFRST: I/O port F reset */
		uint32_t IOPGRST   : 1; /*!< Bit 8 IOPGRST: I/O port G reset */
		uint32_t ADC1RST   : 1; /*!< Bit 9 ADC1RST: ADC 1 interface reset */
		uint32_t ADC2RST   : 1; /*!< Bit 10 ADC2RST: ADC 2 interface reset */
		uint32_t TIM1RST   : 1; /*!< Bit 11 TIM1RST: TIM1 timer reset */
		uint32_t SPI1RST   : 1; /*!< Bit 12 SPI1RST: SPI 1 reset */
		uint32_t TIM8RST   : 1; /*!< Bit 13 TIM8RST: TIM8 timer reset */
		uint32_t USART1RST : 1; /*!< Bit 14 USART1RST: USART1 reset */
		uint32_t ADC3RST   : 1; /*!< Bit 15 ADC3RST: ADC3 interface reset */
		uint32_t RESERVED1 : 3; /*!< Bits 18:16 Reserved, must be kept at reset value */
		uint32_t TIM9RST   : 1; /*!< Bit 19 TIM9RST: TIM9 timer reset */
		uint32_t TIM10RST  : 1; /*!< Bit 20 TIM10RST: TIM10 timer reset */
		uint32_t TIM11RST  : 1; /*!< Bit 21 TIM11RST: TIM11 timer reset */
		uint32_t RESERVED2 : 10; /*!< Bits 31:22 Reserved, must be kept at reset value */
	} BITS;
} RCC_APB2RSTR_t;

/**
  * @brief  APB1 peripheral reset register (RCC_APB1RSTR) 
  * @note   This register provides reset control for APB1 peripherals including:
  *         - TIM2/3/4/5/6/7/12/13/14
  *         - WWDG, SPI2/3, USART2/3, UART4/5
  *         - I2C1/2, USB, CAN, BKP, PWR, DAC
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t TIM2RST   : 1; /*!< Bit 0 TIM2RST: Timer 2 reset */
		uint32_t TIM3RST   : 1; /*!< Bit 1 TIM3RST: Timer 3 reset */
		uint32_t TIM4RST   : 1; /*!< Bit 2 TIM4RST: Timer 4 reset */
		uint32_t TIM5RST   : 1; /*!< Bit 3 TIM5RST: Timer 5 reset */
		uint32_t TIM6RST   : 1; /*!< Bit 4 TIM6RST: Timer 6 reset */
		uint32_t TIM7RST   : 1; /*!< Bit 5 TIM7RST: Timer 7 reset */
		uint32_t TIM12RST  : 1; /*!< Bit 6 TIM12RST: Timer 12 reset */
		uint32_t TIM13RST  : 1; /*!< Bit 7 TIM13RST: Timer 13 reset */
		uint32_t TIM14RST  : 1; /*!< Bit 8 TIM14RST: Timer 14 reset */
		uint32_t RESERVED0 : 2; /*!< Bits 10:9 Reserved, must be kept at reset value */
		uint32_t WWDGRST   : 1; /*!< Bit 11 WWDGRST: Window watchdog reset */
		uint32_t RESERVED1 : 2; /*!< Bits 13:12 Reserved, must be kept at reset value */
		uint32_t SPI2RST   : 1; /*!< Bit 14 SPI2RST: SPI 2 reset */
		uint32_t SPI3RST   : 1; /*!< Bit 15 SPI3RST: SPI 3 reset */
		uint32_t RESERVED2 : 1; /*!< Bit 16 Reserved, must be kept at reset value */
		uint32_t USART2RST : 1; /*!< Bit 17 USART2RST: USART 2 reset */
		uint32_t USART3RST : 1; /*!< Bit 18 USART3RST: USART 3 reset */
		uint32_t UART4RST  : 1; /*!< Bit 19 UART4RST: UART 4 reset */
		uint32_t UART5RST  : 1; /*!< Bit 20 UART5RST: UART 5 reset */
		uint32_t I2C1RST   : 1; /*!< Bit 21 I2C1RST: I2C 1 reset */
		uint32_t I2C2RST   : 1; /*!< Bit 22 I2C2RST: I2C 2 reset */
		uint32_t USBRST    : 1; /*!< Bit 23 USBRST: USB reset */
		uint32_t RESERVED3 : 1; /*!< Bit 24 Reserved, must be kept at reset value */
		uint32_t CANRST    : 1; /*!< Bit 25 CANRST: CAN reset */
		uint32_t RESERVED4 : 1; /*!< Bit 26 Reserved, must be kept at reset value */
		uint32_t BKPRST    : 1; /*!< Bit 27 BKPRST: Backup interface reset */
		uint32_t PWRRST    : 1; /*!< Bit 28 PWRRST: Power interface reset */
		uint32_t DACRST    : 1; /*!< Bit 29 DACRST: DAC interface reset */
		uint32_t RESERVED5 : 2; /*!< Bits 31:30 Reserved, must be kept at reset value */
	} BITS;
} RCC_APB1RSTR_t;

/**
  * @brief  AHB peripheral clock enable register (RCC_AHBENR)
  * @note   This register enables clock for AHB peripherals:
  *         - DMA1/2, SRAM, Flash interface
  *         - CRC calculation unit, FSMC, SDIO
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t DMA1EN    : 1; /*!< Bit 0 DMA1EN: DMA1 clock enable */
		uint32_t DMA2EN    : 1; /*!< Bit 1 DMA2EN: DMA2 clock enable */
		uint32_t SRAMEN    : 1; /*!< Bit 2 SRAMEN: SRAM interface clock enable */
		uint32_t RESERVED0 : 1; /*!< Bit 3 Reserved, must be kept at reset value */
		uint32_t FLITFEN   : 1; /*!< Bit 4 FLITFEN: FLITF clock enable */
		uint32_t RESERVED1 : 1; /*!< Bit 5 Reserved, must be kept at reset value */
		uint32_t CRCEN     : 1; /*!< Bit 6 CRCEN: CRC clock enable */
		uint32_t RESERVED2 : 1; /*!< Bit 7 Reserved, must be kept at reset value */
		uint32_t FSMCEN    : 1; /*!< Bit 8 FSMCEN: FSMC clock enable */
		uint32_t RESERVED3 : 1; /*!< Bit 9 Reserved, must be kept at reset value */
		uint32_t SDIOEN    : 1; /*!< Bit 10 SDIOEN: SDIO clock enable */
		uint32_t RESERVED4 : 21; /*!< Bits 31:11 Reserved, must be kept at reset value */
	} BITS;
} RCC_AHBENR_t;

/**
  * @brief  APB2 peripheral clock enable register (RCC_APB2ENR)
  * @note   This register enables clock for APB2 peripherals including:
  *         - GPIO ports, AFIO
  *         - ADC1/2/3, TIM1/8/9/10/11
  *         - SPI1, USART1  
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t AFIOEN    : 1; /*!< Bit 0 AFIOEN: Alternate function I/O clock enable */
		uint32_t RESERVED0 : 1; /*!< Bit 1 Reserved, must be kept at reset value */
		uint32_t IOPAEN    : 1; /*!< Bit 2 IOPAEN: I/O port A clock enable */
		uint32_t IOPBEN    : 1; /*!< Bit 3 IOPBEN: I/O port B clock enable */
		uint32_t IOPCEN    : 1; /*!< Bit 4 IOPCEN: I/O port C clock enable */
		uint32_t IOPDEN    : 1; /*!< Bit 5 IOPDEN: I/O port D clock enable */
		uint32_t IOPEEN    : 1; /*!< Bit 6 IOPEEN: I/O port E clock enable */
		uint32_t IOPFEN    : 1; /*!< Bit 7 IOPFEN: I/O port F clock enable */
		uint32_t IOPGEN    : 1; /*!< Bit 8 IOPGEN: I/O port G clock enable */
		uint32_t ADC1EN    : 1; /*!< Bit 9 ADC1EN: ADC 1 interface clock enable */
		uint32_t ADC2EN    : 1; /*!< Bit 10 ADC2EN: ADC 2 interface clock enable */
		uint32_t TIM1EN    : 1; /*!< Bit 11 TIM1EN: TIM1 timer clock enable */
		uint32_t SPI1EN    : 1; /*!< Bit 12 SPI1EN: SPI 1 clock enable */
		uint32_t TIM8EN    : 1; /*!< Bit 13 TIM8EN: TIM8 timer clock enable */
		uint32_t USART1EN  : 1; /*!< Bit 14 USART1EN: USART1 clock enable */
		uint32_t ADC3EN    : 1; /*!< Bit 15 ADC3EN: ADC3 interface clock enable */
		uint32_t RESERVED1 : 3; /*!< Bits 18:16 Reserved, must be kept at reset value */
		uint32_t TIM9EN    : 1; /*!< Bit 19 TIM9EN: TIM9 timer clock enable */
		uint32_t TIM10EN   : 1; /*!< Bit 20 TIM10EN: TIM10 timer clock enable */
		uint32_t TIM11EN   : 1; /*!< Bit 21 TIM11EN: TIM11 timer clock enable */
		uint32_t RESERVED2 : 10; /*!< Bits 31:22 Reserved, must be kept at reset value */
	} BITS;
} RCC_APB2ENR_t;

/**
  * @brief  APB1 peripheral clock enable register (RCC_APB1ENR)
  * @note   This register enables clock for APB1 peripherals including:
  *         - TIM2/3/4/5/6/7/12/13/14
  *         - WWDG, SPI2/3, USART2/3, UART4/5
  *         - I2C1/2, USB, CAN, BKP, PWR, DAC
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t TIM2EN    : 1; /*!< Bit 0 TIM2EN: Timer 2 clock enable */
		uint32_t TIM3EN    : 1; /*!< Bit 1 TIM3EN: Timer 3 clock enable */
		uint32_t TIM4EN    : 1; /*!< Bit 2 TIM4EN: Timer 4 clock enable */
		uint32_t TIM5EN    : 1; /*!< Bit 3 TIM5EN: Timer 5 clock enable */
		uint32_t TIM6EN    : 1; /*!< Bit 4 TIM6EN: Timer 6 clock enable */
		uint32_t TIM7EN    : 1; /*!< Bit 5 TIM7EN: Timer 7 clock enable */
		uint32_t TIM12EN   : 1; /*!< Bit 6 TIM12EN: Timer 12 clock enable */
		uint32_t TIM13EN   : 1; /*!< Bit 7 TIM13EN: Timer 13 clock enable */
		uint32_t TIM14EN   : 1; /*!< Bit 8 TIM14EN: Timer 14 clock enable */
		uint32_t RESERVED0 : 2; /*!< Bits 10:9 Reserved, must be kept at reset value */
		uint32_t WWDGEN    : 1; /*!< Bit 11 WWDGEN: Window watchdog clock enable */
		uint32_t RESERVED1 : 2; /*!< Bits 13:12 Reserved, must be kept at reset value */
		uint32_t SPI2EN    : 1; /*!< Bit 14 SPI2EN: SPI 2 clock enable */
		uint32_t SPI3EN    : 1; /*!< Bit 15 SPI3EN: SPI 3 clock enable */
		uint32_t RESERVED2 : 1; /*!< Bit 16 Reserved, must be kept at reset value */
		uint32_t USART2EN  : 1; /*!< Bit 17 USART2EN: USART 2 clock enable */
		uint32_t USART3EN  : 1; /*!< Bit 18 USART3EN: USART 3 clock enable */
		uint32_t UART4EN   : 1; /*!< Bit 19 UART4EN: UART 4 clock enable */
		uint32_t UART5EN   : 1; /*!< Bit 20 UART5EN: UART 5 clock enable */
		uint32_t I2C1EN    : 1; /*!< Bit 21 I2C1EN: I2C 1 clock enable */
		uint32_t I2C2EN    : 1; /*!< Bit 22 I2C2EN: I2C 2 clock enable */
		uint32_t USBEN     : 1; /*!< Bit 23 USBEN: USB clock enable */
		uint32_t RESERVED3 : 1; /*!< Bit 24 Reserved, must be kept at reset value */
		uint32_t CANEN     : 1; /*!< Bit 25 CANEN: CAN clock enable */
		uint32_t RESERVED4 : 1; /*!< Bit 26 Reserved, must be kept at reset value */
		uint32_t BKPEN     : 1; /*!< Bit 27 BKPEN: Backup interface clock enable */
		uint32_t PWREN     : 1; /*!< Bit 28 PWREN: Power interface clock enable */
		uint32_t DACEN     : 1; /*!< Bit 29 DACEN: DAC interface clock enable */
		uint32_t RESERVED5 : 2; /*!< Bits 31:30 Reserved, must be kept at reset value */
	} BITS;
} RCC_APB1ENR_t;

/**
  * @brief  Backup domain control register (RCC_BDCR)
  * @note   This register controls the backup domain including:
  *         - LSE oscillator control
  *         - RTC clock source selection
  *         - RTC clock enable and backup domain reset
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t LSEON     : 1; /*!< Bit 0 LSEON: External low-speed oscillator enable */
		uint32_t LSERDY    : 1; /*!< Bit 1 LSERDY: External low-speed oscillator ready */
		uint32_t LSEBYP    : 1; /*!< Bit 2 LSEBYP: External low-speed oscillator bypass */
		uint32_t RESERVED0 : 5; /*!< Bits 7:3 Reserved, must be kept at reset value */
		uint32_t RTCSEL    : 2; /*!< Bits 9:8 RTCSEL: RTC clock source selection */
		uint32_t RESERVED1 : 5; /*!< Bits 14:10 Reserved, must be kept at reset value */
		uint32_t RTCEN     : 1; /*!< Bit 15 RTCEN: RTC clock enable */
		uint32_t BDRST     : 1; /*!< Bit 16 BDRST: Backup domain software reset */
		uint32_t RESERVED2 : 15; /*!< Bits 31:17 Reserved, must be kept at reset value */
	} BITS;
} RCC_BDCR_t;

/**
  * @brief  Control/status register (RCC_CSR)
  * @note   This register provides control and status for:
  *         - LSI oscillator
  *         - Reset flags and reset flag clear
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t LSION     : 1; /*!< Bit 0 LSION: Internal low-speed oscillator enable */
		uint32_t LSIRDY    : 1; /*!< Bit 1 LSIRDY: Internal low-speed oscillator ready */
		uint32_t RESERVED0 : 22; /*!< Bits 23:2 Reserved, must be kept at reset value */
		uint32_t RMVF      : 1; /*!< Bit 24 RMVF: Remove reset flag */
		uint32_t RESERVED1 : 1; /*!< Bit 25 Reserved, must be kept at reset value */
		uint32_t PINRSTF   : 1; /*!< Bit 26 PINRSTF: PIN reset flag */
		uint32_t PORRSTF   : 1; /*!< Bit 27 PORRSTF: POR/PDR reset flag */
		uint32_t SFTRSTF   : 1; /*!< Bit 28 SFTRSTF: Software reset flag */
		uint32_t IWDGRSTF  : 1; /*!< Bit 29 IWDGRSTF: Independent watchdog reset flag */
		uint32_t WWDGRSTF  : 1; /*!< Bit 30 WWDGRSTF: Window watchdog reset flag */
		uint32_t LPWRRSTF  : 1; /*!< Bit 31 LPWRRSTF: Low-power reset flag */
	} BITS;
} RCC_CSR_t;

/**
  * @brief  RCC register structure definition
  * @note   This structure maps all RCC registers for direct access to the
  *         Reset and Clock Control peripheral at base address 0x40021000
  */
typedef struct {
	RCC_CR_t        CR;        /*!< RCC clock control register,                offset: 0x00 */
	RCC_CFGR_t      CFGR;      /*!< RCC clock configuration register,          offset: 0x04 */
	RCC_CIR_t       CIR;       /*!< RCC clock interrupt register,              offset: 0x08 */
	RCC_APB2RSTR_t  APB2RSTR;  /*!< RCC APB2 peripheral reset register,        offset: 0x0C */
	RCC_APB1RSTR_t  APB1RSTR;  /*!< RCC APB1 peripheral reset register,        offset: 0x10 */
	RCC_AHBENR_t    AHBENR;    /*!< RCC AHB peripheral clock enable register,  offset: 0x14 */
	RCC_APB2ENR_t   APB2ENR;   /*!< RCC APB2 peripheral clock enable register, offset: 0x18 */
	RCC_APB1ENR_t   APB1ENR;   /*!< RCC APB1 peripheral clock enable register, offset: 0x1C */
	RCC_BDCR_t      BDCR;      /*!< RCC backup domain control register,        offset: 0x20 */
	RCC_CSR_t       CSR;       /*!< RCC control/status register,               offset: 0x24 */
} RCC_TypeDef;

/**
  * @}
  */

/**
  * @brief  Flash access control register (FLASH_ACR)
  * @note   This register controls Flash memory access timing and prefetch buffer
  */
typedef union {
	__IO uint32_t REG;
	struct {
		uint32_t LATENCY  : 3; /*!< Bits 2:0 LATENCY: Latency */
		uint32_t HLFCYA   : 1; /*!< Bit 3 HLFCYA: Flash half cycle access enable */
		uint32_t PRFTBE   : 1; /*!< Bit 4 PRFTBE: Prefetch buffer enable */
		uint32_t PRFTBS   : 1; /*!< Bit 5 PRFTBS: Prefetch buffer status */
		uint32_t RESERVED : 26; /*!< Bits 31:6 Reserved, must be kept at reset value */
	} BITS;
} FLASH_ACR_t;

/**
  * @brief  Flash register structure definition
  * @note   This structure maps Flash control registers at base address 0x40022000
  */
typedef struct {
	FLASH_ACR_t ACR; /*!< Flash access control register, offset: 0x00 */
} FLASH_TypeDef;


/**
  * @}
  */

/** @defgroup RCC_Exported_Functions
  * @{
  */

/**
  * @brief  RCC Peripheral type for unified clock control
  * @note   Used with RCC_PeripheralClockCmd() to select the peripheral
  */
#define RCC_PERIPH_GPIOA   (1UL << 2)   // APB2ENR bit 2: IOPAEN
#define RCC_PERIPH_GPIOB   (1UL << 3)   // APB2ENR bit 3: IOPBEN
#define RCC_PERIPH_GPIOC   (1UL << 4)   // APB2ENR bit 4: IOPCEN
#define RCC_PERIPH_AFIO    (1UL << 0)   // APB2ENR bit 0: AFIOEN
#define RCC_PERIPH_ADC1    (1UL << 9)   // APB2ENR bit 9: ADC1EN
#define RCC_PERIPH_ADC2    (1UL << 10)  // APB2ENR bit 10: ADC2EN
#define RCC_PERIPH_TIM1    (1UL << 11)  // APB2ENR bit 11: TIM1EN
#define RCC_PERIPH_TIM2    (1UL << 16)  // APB1ENR bit 0: TIM2EN (shifted by 16)
#define RCC_PERIPH_TIM3    (1UL << 17)  // APB1ENR bit 1: TIM3EN (shifted by 16)
#define RCC_PERIPH_TIM4    (1UL << 18)  // APB1ENR bit 2: TIM4EN (shifted by 16)


/**
  * @brief  Configures the system clock to 72MHz using HSE as PLL source
  * @note   This function:
  *         - Enables HSE oscillator
  *         - Configures PLL to multiply HSE by 9 (8MHz * 9 = 72MHz)
  *         - Sets Flash latency to 2 wait states for 72MHz operation
  *         - Switches system clock to PLL
  * @param  None
  * @retval None
  */
void RCC_SystemClock_HSE_72MHz(void);

/**
 * @brief  Enables or disables clock for a given peripheral (GPIO, AFIO, TIMx)
 * @note   This function provides a unified interface for enabling/disabling
 *         clocks for GPIO ports, AFIO, and timers (TIM1-4).
 * @param  periph: Peripheral to control, see @ref RCC_PeriphType
 * @param  enable: ENABLE to enable, DISABLE to disable
 * @retval None
 * @example RCC_PeripheralClockCmd(RCC_PERIPH_GPIOA, ENABLE); // Enable GPIOA clock
 * @example RCC_PeripheralClockCmd(RCC_PERIPH_TIM2, DISABLE);  // Disable TIM2 clock
 */
void RCC_PeripheralClockCmd(uint32_t periph_mask, uint8_t enable);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* RCC_H */
