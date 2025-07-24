
#ifndef EXTI_H
#define EXTI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32_util.h"
#include "afio.h"
#include "gpio.h"

#define EXTI_MODE_RISING    0x01 /*!< Rising edge trigger selection */
#define EXTI_MODE_FALLING   0x02 /*!< Falling edge trigger selection */
#define EXTI_MODE_BOTH      (EXTI_MODE_RISING | EXTI_MODE_FALLING) /*!< Rising and Falling edge trigger selection */


typedef union
  {
  __IO uint32_t ALL;
  struct
  {
    __IO uint32_t BIT0  : 1;
    __IO uint32_t BIT1  : 1;
    __IO uint32_t BIT2  : 1;
    __IO uint32_t BIT3  : 1;
    __IO uint32_t BIT4  : 1;
    __IO uint32_t BIT5  : 1;
    __IO uint32_t BIT6  : 1;
    __IO uint32_t BIT7  : 1;
    __IO uint32_t BIT8  : 1;
    __IO uint32_t BIT9  : 1;
    __IO uint32_t BIT10 : 1;
    __IO uint32_t BIT11 : 1;
    __IO uint32_t BIT12 : 1;
    __IO uint32_t BIT13 : 1;
    __IO uint32_t BIT14 : 1;
    __IO uint32_t BIT15 : 1;
    __IO uint32_t BIT16 : 1;
    __IO uint32_t BIT17 : 1;
    __IO uint32_t BIT18 : 1;
    __IO uint32_t BIT19 : 1;
    __IO uint32_t BIT20 : 1;
    __IO uint32_t BIT21 : 1;
    __IO uint32_t BIT22 : 1;
    __IO uint32_t BIT23 : 1;
    __IO uint32_t BIT24 : 1;
    __IO uint32_t BIT25 : 1;
    __IO uint32_t BIT26 : 1;
    __IO uint32_t BIT27 : 1;
    __IO uint32_t BIT28 : 1;
    __IO uint32_t BIT29 : 1;
    __IO uint32_t BIT30 : 1;
    __IO uint32_t BIT31 : 1;
  } BITS;
} __32bit;
	
/**
  * @brief  Nested Vector Interrupt Controller (NVIC) register structure definition
  * @note   This structure provides access to NVIC registers for interrupt control.
  *         The NVIC is part of the ARM Cortex-M3 core and manages all system
  *         and peripheral interrupts with configurable priority levels.
  */
typedef struct
{
	__IO uint32_t ISER[8];  /*!< Interrupt Set Enable Registers,           Address offset: 0x00-0x1C */
	uint32_t      RESERVED0[24];

	__IO uint32_t ICER[8];  /*!< Interrupt Clear Enable Registers,         Address offset: 0x80-0x9C */
	uint32_t      RESERVED1[24];

	__IO uint32_t ISPR[8];  /*!< Interrupt Set Pending Registers,          Address offset: 0x100-0x11C */
	uint32_t      RESERVED2[24];

	__IO uint32_t ICPR[8];  /*!< Interrupt Clear Pending Registers,        Address offset: 0x180-0x19C */
	uint32_t      RESERVED3[24];

	__IO uint32_t IABR[8];  /*!< Interrupt Active bit Registers,           Address offset: 0x200-0x21C */
	uint32_t      RESERVED4[56];
                                   
	__IO uint8_t  IPR[240]; /*!< Interrupt Priority Registers,             Address offset: 0x300-0x3EF */
	uint32_t      RESERVED5[644];
                                   
	__O  uint32_t STIR;     /*!< Software Trigger Interrupt Register,      Address offset: 0xE00 */
} NVIC_TypeDef;

/**
  * @brief  External Interrupt/Event Controller (EXTI) register structure definition
  * @note   This structure maps EXTI registers for external interrupt and event management.
  *         EXTI lines 0-15 are connected to GPIO pins, while lines 16-18 are connected
  *         to internal peripherals (PVD, RTC Alarm, USB Wakeup).
  *         Base address: 0x40010400
  */
typedef struct
{
	__32bit IMR;
	__32bit EMR;
	__32bit RTSR;
	__32bit FTSR;
	__32bit SWIER;
	__32bit PR;
} EXTI_TypeDef;

/**
  * @brief  Interrupt Request Number enumeration
  * @note   This enumeration defines IRQ numbers for EXTI lines according to
  *         STM32F1xx vector table. Each EXTI line has a corresponding IRQ number
  *         used for NVIC configuration and interrupt handling.
  */
typedef enum IRQn
{
	/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
	NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
	MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt             */
	BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                     */
	UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                   */
	SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                      */
	DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                */
	PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                      */
	SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                  */

	/******  STM32 specific Interrupt Numbers *********************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                              */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt              */
  TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt                                       */
  RTC_IRQn                    = 3,      /*!< RTC global Interrupt                                   */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                 */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                   */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                   */
	EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                   */
	EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                   */
	EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                   */
	EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                   */
	DMA_Channel1_IRQn           = 11,     /*!< DMA Channel 0 global Interrupt                         */
  DMA_Channel2_IRQn           = 12,     /*!< DMA Channel 1 global Interrupt                         */
  DMA_Channel3_IRQn           = 13,     /*!< DMA Channel 2 global Interrupt                         */
  DMA_Channel4_IRQn           = 14,     /*!< DMA Channel 3 global Interrupt                         */
  DMA_Channel5_IRQn           = 15,     /*!< DMA Channel 4 global Interrupt                         */
  DMA_Channel6_IRQn           = 16,     /*!< DMA Channel 5 global Interrupt                         */
  DMA_Channel7_IRQn           = 17,     /*!< DMA Channel 6 global Interrupt                         */
  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                         */ 
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                          */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                */ 
	EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                        */
} IRQn_Type;

/**
  * @brief  EXTI Line0 Interrupt Handler
  * @note   This function should be called from the EXTI0_IRQHandler in the
  *         interrupt vector table. It handles the EXTI Line0 interrupt and
  *         must clear the pending bit in EXTI_PR register.
  * @param  None
  * @retval None
  */
void EXTI0_IRQHandler(void);

/**
  * @brief  Get pin number from GPIO pin mask
  * @note   This function extracts the pin number (0-15) from a GPIO pin mask.
  *         It's used internally to determine which EXTI line to configure.
  * @param  GPIO_Pin: GPIO pin mask (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.)
  *         This parameter should be a power of 2 value from 0x0001 to 0x8000
  * @retval Pin number (0-15) or -1 if invalid pin mask
  * @example: get_pin_number(GPIO_PIN_5) returns 5
  */
int8_t get_pin_number(uint16_t GPIO_Pin);

/**
  * @brief  Get EXTI line number from GPIO port
  * @note   This function determines the EXTI port configuration index based on
  *         the GPIO port address. Used for AFIO_EXTICR register configuration.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral
  * @retval EXTI port number (0-6) corresponding to GPIOA-GPIOG, or -1 if invalid
  * @example: get_exti_line(GPIOA) returns 0, get_exti_line(GPIOB) returns 1
  */
int8_t get_exti_line(volatile GPIO_TypeDef *GPIOx);

/**
  * @brief  Initializes EXTI line for specified GPIO pin
  * @note   This function configures:
  *         - AFIO external interrupt configuration register (EXTICR)
  *         - EXTI interrupt mask register (IMR)
  *         - EXTI rising/falling trigger selection registers (RTSR/FTSR)
  *         - NVIC interrupt enable
  *         
  *         The GPIO pin must be configured as input before calling this function.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral
  * @param  GPIO_Pin: specifies the GPIO pin to configure for EXTI
  *         This parameter can be GPIO_PIN_x where x can be (0..15)
  * @param  mode: specifies the trigger mode for the EXTI line
  *         This parameter can be:
  *         @arg EXTI_MODE_RISING: Rising edge trigger
  *         @arg EXTI_MODE_FALLING: Falling edge trigger  
  *         @arg EXTI_MODE_BOTH: Both rising and falling edge trigger
  * @retval None
  * @example:
  *         // Configure PA0 for rising edge external interrupt
  *         EXTI_Init(GPIOA, GPIO_PIN_0, EXTI_MODE_RISING);
  */
void EXTI_Init(volatile GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t mode);
void NVIC_EnableIRQ(IRQn_Type IRQn);
#ifdef __cplusplus
}
#endif

#endif /* EXTI_H */
// EXTI_H --- IGNORE ---


