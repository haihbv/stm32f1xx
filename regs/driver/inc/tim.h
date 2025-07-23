/**
  ******************************************************************************
  * @file    tim.h
  * @author  STM32 Register Driver
  * @version V1.0.0
  * @date    21-July-2025
  * @brief   This file contains all the functions prototypes for the TIM firmware 
  *          library.
  ******************************************************************************
  * @attention
  *
  * This module provides low-level access to STM32F1xx TIM (Timer) peripheral
  * registers using direct register address definitions for Timer 2 functionality
  * including basic timing, PWM generation, and interrupt handling.
  *
  ******************************************************************************
  */

#ifndef TIMER_H
#define TIMER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32_util.h"

/** @addtogroup STM32F1xx_Register_Driver
  * @{
  */

/** @addtogroup TIM
  * @{
  */ 

/** @defgroup TIM_Register_Structures
  * @brief TIM Register structure definitions
  * @note  These structures provide organized access to TIM peripheral registers
  * @{
  */

/**
  * @brief  Timer register structure definition
  * @note   This structure maps all TIM registers for structured access to
  *         Timer peripherals. Compatible with TIM1, TIM2, TIM3, TIM4, etc.
  */


/** @defgroup TIM_Channel TIM Channel
  * @{
  */
#define TIM_CHANNEL_1 1  /*!< Timer Channel 1 */
#define TIM_CHANNEL_2 2  /*!< Timer Channel 2 */
#define TIM_CHANNEL_3 3  /*!< Timer Channel 3 */
#define TIM_CHANNEL_4 4  /*!< Timer Channel 4 */
/**
  * @}
  */

/** @defgroup TIM_Control_Register_1 TIM CR1 Register Bits
  * @{
  */
#define TIM_CR1_CEN     (1U << 0U)  /*!< Counter enable */
#define TIM_CR1_UDIS    (1 << 1)    /*!< Update disable */
#define TIM_CR1_URS     (1 << 2)    /*!< Update request source */
#define TIM_CR1_OPM     (1 << 3)    /*!< One pulse mode */
#define TIM_CR1_DIR     (1 << 4)    /*!< Direction (0: up-counter, 1: down-counter) */
#define TIM_CR1_CMS_0   (1 << 5)    /*!< Center-aligned mode selection bit 0 */
#define TIM_CR1_CMS_1   (1 << 6)    /*!< Center-aligned mode selection bit 1 */
#define TIM_CR1_ARPE    (1 << 7)    /*!< Auto-reload preload enable */
#define TIM_CR1_CKD_0   (1 << 8)    /*!< Clock division bit 0 */
#define TIM_CR1_CKD_1   (1 << 9)    /*!< Clock division bit 1 */
/**
  * @}
  */

/** @defgroup TIM_Control_Register_2 TIM CR2 Register Bits
  * @{
  */
#define TIM_CR2_CCDS      (1 << 3)  /*!< Capture/Compare DMA selection */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Mode TIM Output Compare Mode
  * @{
  */
#define TIM_OCMODE_PWM1 6U  /*!< PWM mode 1 - active if TIMx_CNT < TIMx_CCRx */
#define TIM_OCMODE_PWM2 7U  /*!< PWM mode 2 - active if TIMx_CNT > TIMx_CCRx */
/**
  * @}
  */

/** @defgroup TIM_CCMR1_Register TIM CCMR1 Register - Channel 1 and 2
  * @{
  */
/* Output Compare 1 */
#define TIM_CCMR1_OC1FE     (1 << 2)         /*!< Output compare 1 fast enable */
#define TIM_CCMR1_OC1PE     (1 << 3)         /*!< Output compare 1 preload enable */
#define TIM_CCMR1_OC1M_MASK (0x7U << 4U)     /*!< Output compare 1 mode mask (bits 6:4) */
#define TIM_CCMR1_OC1M_0    (1 << 4)         /*!< Output compare 1 mode bit 0 */
#define TIM_CCMR1_OC1M_1    (1 << 5)         /*!< Output compare 1 mode bit 1 */
#define TIM_CCMR1_OC1M_2    (1 << 6)         /*!< Output compare 1 mode bit 2 */
#define TIM_CCMR1_OC1CE     (1 << 7)         /*!< Output compare 1 clear enable */

/* Output Compare 2 */
#define TIM_CCMR1_OC2FE     (1 << 10)        /*!< Output compare 2 fast enable */
#define TIM_CCMR1_OC2PE     (1 << 11)        /*!< Output compare 2 preload enable */
#define TIM_CCMR1_OC2M_MASK (0x7U << 12U)    /*!< Output compare 2 mode mask (bits 14:12) */
#define TIM_CCMR1_OC2M_0    (1 << 12)        /*!< Output compare 2 mode bit 0 */
#define TIM_CCMR1_OC2M_1    (1 << 13)        /*!< Output compare 2 mode bit 1 */
#define TIM_CCMR1_OC2M_2    (1 << 14)        /*!< Output compare 2 mode bit 2 */
#define TIM_CCMR1_OC2CE     (1 << 15)        /*!< Output compare 2 clear enable */
/**
  * @}
  */

/** @defgroup TIM_CCMR2_Register TIM CCMR2 Register - Channel 3 and 4
  * @{
  */
/* Output Compare 3 */
#define TIM_CCMR2_OC3FE     (1 << 2)         /*!< Output compare 3 fast enable */
#define TIM_CCMR2_OC3PE     (1 << 3)         /*!< Output compare 3 preload enable */
#define TIM_CCMR2_OC3M_MASK (0x7U << 4U)     /*!< Output compare 3 mode mask (bits 6:4) */
#define TIM_CCMR2_OC3M_0    (1 << 4)         /*!< Output compare 3 mode bit 0 */
#define TIM_CCMR2_OC3M_1    (1 << 5)         /*!< Output compare 3 mode bit 1 */
#define TIM_CCMR2_OC3M_2    (1 << 6)         /*!< Output compare 3 mode bit 2 */
#define TIM_CCMR2_OC3CE     (1 << 7)         /*!< Output compare 3 clear enable */

/* Output Compare 4 */
#define TIM_CCMR2_OC4FE     (1 << 10)        /*!< Output compare 4 fast enable */
#define TIM_CCMR2_OC4PE     (1 << 11)        /*!< Output compare 4 preload enable */
#define TIM_CCMR2_OC4M_MASK (0x7U << 12U)    /*!< Output compare 4 mode mask (bits 14:12) */
#define TIM_CCMR2_OC4M_0    (1 << 12)        /*!< Output compare 4 mode bit 0 */
#define TIM_CCMR2_OC4M_1    (1 << 13)        /*!< Output compare 4 mode bit 1 */
#define TIM_CCMR2_OC4M_2    (1 << 14)        /*!< Output compare 4 mode bit 2 */
#define TIM_CCMR2_OC4CE     (1 << 15)        /*!< Output compare 4 clear enable */
/**
  * @}
  */

/** @defgroup TIM_CCER_Register TIM CCER Register - Capture/Compare Enable
  * @{
  */
/* Channel 1 */
#define TIM_CCER_CC1E       (1 << 0)         /*!< Capture/Compare 1 output enable */
#define TIM_CCER_CC1P       (1 << 1)         /*!< Capture/Compare 1 output polarity */
#define TIM_CCER_CC1NE      (1 << 2)         /*!< Complementary Capture/Compare 1 output enable (Advanced timers only) */
#define TIM_CCER_CC1NP      (1 << 3)         /*!< Complementary Capture/Compare 1 output polarity (Advanced timers only) */

/* Channel 2 */
#define TIM_CCER_CC2E       (1 << 4)         /*!< Capture/Compare 2 output enable */
#define TIM_CCER_CC2P       (1 << 5)         /*!< Capture/Compare 2 output polarity */
#define TIM_CCER_CC2NE      (1 << 6)         /*!< Complementary Capture/Compare 2 output enable (Advanced timers only) */
#define TIM_CCER_CC2NP      (1 << 7)         /*!< Complementary Capture/Compare 2 output polarity (Advanced timers only) */

/* Channel 3 */
#define TIM_CCER_CC3E       (1 << 8)         /*!< Capture/Compare 3 output enable */
#define TIM_CCER_CC3P       (1 << 9)         /*!< Capture/Compare 3 output polarity */
#define TIM_CCER_CC3NE      (1 << 10)        /*!< Complementary Capture/Compare 3 output enable (Advanced timers only) */
#define TIM_CCER_CC3NP      (1 << 11)        /*!< Complementary Capture/Compare 3 output polarity (Advanced timers only) */

/* Channel 4 */
#define TIM_CCER_CC4E       (1 << 12)        /*!< Capture/Compare 4 output enable */
#define TIM_CCER_CC4P       (1 << 13)        /*!< Capture/Compare 4 output polarity */
#define TIM_CCER_CC4NP      (1 << 15)        /*!< Complementary Capture/Compare 4 output polarity (Advanced timers only) */
/**
  * @}
  */

/** @defgroup TIM_EGR_Register TIM EGR Register - Event Generation
  * @{
  */
#define TIM_EGR_UG          (1 << 0)         /*!< Update generation */
#define TIM_EGR_CC1G        (1 << 1)         /*!< Capture/Compare 1 generation */
#define TIM_EGR_CC2G        (1 << 2)         /*!< Capture/Compare 2 generation */
#define TIM_EGR_CC3G        (1 << 3)         /*!< Capture/Compare 3 generation */
#define TIM_EGR_CC4G        (1 << 4)         /*!< Capture/Compare 4 generation */
#define TIM_EGR_COMG        (1 << 5)         /*!< Capture/Compare control update generation (Advanced timers only) */
#define TIM_EGR_TG          (1 << 6)         /*!< Trigger generation */
#define TIM_EGR_BG          (1 << 7)         /*!< Break generation (Advanced timers only) */
/**
  * @}
  */

/** @defgroup TIM_DIER_Register TIM DIER Register - DMA/Interrupt Enable
  * @{
  */
#define TIM_DIER_UIE        (1 << 0)         /*!< Update interrupt enable */
#define TIM_DIER_CC1IE      (1 << 1)         /*!< Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE      (1 << 2)         /*!< Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE      (1 << 3)         /*!< Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE      (1 << 4)         /*!< Capture/Compare 4 interrupt enable */
#define TIM_DIER_TIE        (1 << 6)         /*!< Trigger interrupt enable */
#define TIM_DIER_UDE        (1 << 8)         /*!< Update DMA request enable */
/**
  * @}
  */

/** @defgroup TIM_SR_Register TIM SR Register - Status Register
  * @{
  */
#define TIM_SR_UIF          (1 << 0)         /*!< Update interrupt flag */
#define TIM_SR_CC1IF        (1 << 1)         /*!< Capture/Compare 1 interrupt flag */
#define TIM_SR_CC2IF        (1 << 2)         /*!< Capture/Compare 2 interrupt flag */
#define TIM_SR_CC3IF        (1 << 3)         /*!< Capture/Compare 3 interrupt flag */
#define TIM_SR_CC4IF        (1 << 4)         /*!< Capture/Compare 4 interrupt flag */
#define TIM_SR_TIF          (1 << 6)         /*!< Trigger interrupt flag */
#define TIM_SR_CC1OF        (1 << 9)         /*!< Capture/Compare 1 overcapture flag */
#define TIM_SR_CC2OF        (1 << 10)        /*!< Capture/Compare 2 overcapture flag */
/**
  * @}
  */

/** @defgroup TIM_BDTR_Register TIM BDTR Register - Break and Dead-time (Advanced timers only)
  * @{
  */
#define TIM_BDTR_MOE        (1 << 15)        /*!< Main output enable */
#define TIM_BDTR_AOE        (1 << 14)        /*!< Automatic output enable */
#define TIM_BDTR_BKE        (1 << 12)        /*!< Break enable */
#define TIM_BDTR_BKP        (1 << 13)        /*!< Break polarity */
#define TIM_BDTR_OSSR       (1 << 10)        /*!< Off-state selection for Run mode */
#define TIM_BDTR_OSSI       (1 << 11)        /*!< Off-state selection for Idle mode */
#define TIM_BDTR_LOCK_MASK  (0x3 << 8)       /*!< Lock configuration mask */
#define TIM_BDTR_DTG_MASK   (0xFF << 0)      /*!< Dead-time generator setup mask */
/**
  * @}
  */

/**
  * @brief  Timer register structure definition
  * @note   This structure maps all TIM registers for structured access to
  *         Timer peripherals. Compatible with TIM1, TIM2, TIM3, TIM4, etc.
  */
typedef struct {
   __IO uint32_t CR1;    /*!< TIM control register 1,              Address offset: 0x00 */
   __IO uint32_t CR2;    /*!< TIM control register 2,              Address offset: 0x04 */
   __IO uint32_t SMCR;   /*!< TIM slave mode control register,     Address offset: 0x08 */
   __IO uint32_t DIER;   /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
   __IO uint32_t SR;     /*!< TIM status register,                 Address offset: 0x10 */
   __IO uint32_t EGR;    /*!< TIM event generation register,       Address offset: 0x14 */
   __IO uint32_t CCMR1;  /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
   __IO uint32_t CCMR2;  /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
   __IO uint32_t CCER;   /*!< TIM capture/compare enable register, Address offset: 0x20 */
   __IO uint32_t CNT;    /*!< TIM counter register,                Address offset: 0x24 */
   __IO uint32_t PSC;    /*!< TIM prescaler register,              Address offset: 0x28 */
   __IO uint32_t ARR;    /*!< TIM auto-reload register,            Address offset: 0x2C */
   __IO uint32_t RCR;    /*!< TIM repetition counter register,     Address offset: 0x30 */
   __IO uint32_t CCR1;   /*!< TIM capture/compare register 1,      Address offset: 0x34 */
   __IO uint32_t CCR2;   /*!< TIM capture/compare register 2,      Address offset: 0x38 */
   __IO uint32_t CCR3;   /*!< TIM capture/compare register 3,      Address offset: 0x3C */
   __IO uint32_t CCR4;   /*!< TIM capture/compare register 4,      Address offset: 0x40 */
   __IO uint32_t BDTR;   /*!< TIM break and dead-time register,    Address offset: 0x44 */
   __IO uint32_t DCR;    /*!< TIM DMA control register,            Address offset: 0x48 */
   __IO uint32_t DMAR;   /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
} TIM_TypeDef;

/**
  * @}
  */

/** @defgroup TIM_Exported_Types
  * @{
  */

/**
  * @brief  TIM Time base Configuration Structure definition
  */
typedef struct {
    uint16_t Prescaler;   /*!< Specifies the prescaler value used to divide the TIM clock.
                               This parameter can be a number between 0x0000 and 0xFFFF */
    uint16_t AutoReload;  /*!< Specifies the period value to be loaded into the active
                               Auto-Reload Register at the next update event.
                               This parameter can be a number between 0x0000 and 0xFFFF */
} TIM_BaseConfig_t;

/**
  * @brief  TIM Output Compare Configuration Structure definition
  */
typedef struct {
    uint8_t Channel;      /*!< Specifies the TIM channel.
                               This parameter can be a value of @ref TIM_Channel */
    uint8_t OCMode;       /*!< Specifies the TIM mode.
                               This parameter can be a value of @ref TIM_Output_Compare_Mode */
    uint16_t Pulse;       /*!< Specifies the pulse value to be loaded into the Capture Compare Register.
                               This parameter can be a number between 0x0000 and 0xFFFF */
} TIM_OCConfig_t;

/**
  * @}
  */

/** @defgroup TIM_Exported_Functions
  * @{
  */

/**
  * @brief  Enables or disables the specified TIM peripheral.
  * @param  TIMx: where x can be 1 to 17 to select the TIMx peripheral.
  * @param  cmd: specifies whether the TIMx peripheral will be enabled or disabled.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM_Cmd(volatile TIM_TypeDef *TIMx, uint32_t cmd);

/**
  * @brief  Initializes the TIMx Time Base Unit peripheral according to 
  *         the specified parameters in the TIM_BaseConfig_t.
  * @param  TIMx: where x can be 1 to 17 to select the TIM peripheral.
  * @param  config: TIM_BaseConfig_t structure that contains
  *         the configuration information for the specified TIM peripheral.
  * @retval None
  */
void TIM_BaseInit(volatile TIM_TypeDef *TIMx, TIM_BaseConfig_t config);

/**
  * @brief  Initializes the TIMx Channel according to the specified
  *         parameters in the TIM_OCConfig_t.
  * @param  TIMx: where x can be 1 to 17 except 6 and 7 to select the TIM peripheral.
  * @param  config: TIM_OCConfig_t structure that contains
  *         the configuration information for the specified TIM peripheral.
  * @retval None
  */
void TIM_PWMInit(volatile TIM_TypeDef *TIMx, TIM_OCConfig_t config);

/**
  * @brief  Sets the TIMx Capture Compare Register value
  * @param  TIMx: where x can be 1 to 17 except 6 and 7 to select the TIM peripheral.
  * @param  channel: specifies the Capture Compare channel.
  *         This parameter can be one of the following values:
  *           @arg TIM_CHANNEL_1: TIM Channel 1
  *           @arg TIM_CHANNEL_2: TIM Channel 2
  *           @arg TIM_CHANNEL_3: TIM Channel 3
  *           @arg TIM_CHANNEL_4: TIM Channel 4
  * @param  value: specifies the Capture Compare register new value.
  * @retval None
  */
void TIM_SetCompare(volatile TIM_TypeDef *TIMx, uint8_t channel, uint16_t value);

/**
  * @brief  Initializes TIM3 for delay generation.
  * @note   Configures TIM3 to generate accurate microsecond delays.
  * @param  None
  * @retval None
  */
void TIM3_Delay_Init(void);

/**
  * @brief  Inserts a delay time in microseconds.
  * @param  us: specifies the delay time length, in microseconds.
  * @retval None
  */
void delay_us(uint32_t us);

/**
  * @brief  Initializes servo motor control using PWM.
  * @note   Configures timer and GPIO for servo motor control.
  * @param  None
  * @retval None
  */
void Servo_Init(void);

/**
  * @brief  Sets servo motor angle.
  * @param  angle: specifies the servo angle in degrees (0-180).
  * @retval None
  */
void Servo_SetAngle(uint8_t angle);

/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif /* TIMER_H */

