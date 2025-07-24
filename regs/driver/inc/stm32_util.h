#ifndef STM32UTIL_H
#define STM32UTIL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>


#define __I volatile const
#define __O volatile
#define __IO volatile


#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))

typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} FunctionalState;

#define GPIO_PIN_0     	    (0x0001U)
#define GPIO_PIN_1     	    (0x0002U)
#define GPIO_PIN_2     	    (0x0004U)
#define GPIO_PIN_3     	    (0x0008U)
#define GPIO_PIN_4     	    (0x0010U)
#define GPIO_PIN_5     	    (0x0020U)
#define GPIO_PIN_6     	    (0x0040U)
#define GPIO_PIN_7     	    (0x0080U)
#define GPIO_PIN_8     	    (0x0100U)
#define GPIO_PIN_9     	    (0x0200U)
#define GPIO_PIN_10    	    (0x0400U)
#define GPIO_PIN_11    	    (0x0800U)
#define GPIO_PIN_12    	    (0x1000U)
#define GPIO_PIN_13    	    (0x2000U)
#define GPIO_PIN_14    	    (0x4000U)
#define GPIO_PIN_15    	    (0x8000U)
#define GPIO_PIN_ALL   	    (0xFFFFU)


#define GPIOA_BASE 			(0x40010800UL)
#define GPIOB_BASE 			(0x40010C00UL)
#define GPIOC_BASE 			(0x40011000UL)
#define RCC_BASE    		(0x40021000UL)
#define FLASH_BASE 			(0x40022000UL)
#define AFIO_BASE 			(0x40010000UL)
#define NVIC_Base 			(0xE000E100UL)
#define EXTI_Base 			(0x40010400UL)
#define TIM1_Base 			(0x40012C00UL)
#define TIM2_Base 			(0x40000000UL)
#define TIM3_Base 			(0x40000400UL)
#define TIM4_Base 			(0x40000800UL)
#define ADC1_Base 			(0x40012400UL)
#define ADC2_Base 			(0x40012800UL)
#define USART1_Base			(0x40013800UL)
#define USART2_Base			(0x40004400UL)
#define USART3_Base			(0x40004800UL)

#define GPIOA 				((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB 				((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC 				((GPIO_TypeDef *)GPIOC_BASE)
#define RCC 				((RCC_TypeDef *)RCC_BASE)
#define FLASH 				((FLASH_TypeDef *)FLASH_BASE)
#define AFIO 				((AFIO_TypeDef *)AFIO_BASE)
#define NVIC 				((__IO NVIC_TypeDef *)NVIC_Base)
#define EXTI 				((__IO EXTI_TypeDef *)EXTI_Base)
#define TIM1 				((__IO TIM_TypeDef *)TIM1_Base)
#define TIM2 				((__IO TIM_TypeDef *)TIM2_Base)
#define TIM3 				((__IO TIM_TypeDef *)TIM3_Base)
#define TIM4 				((__IO TIM_TypeDef *)TIM4_Base)
#define ADC1 	 			((__IO ADC_TypeDef *)ADC1_Base)
#define ADC2 	 			((__IO ADC_TypeDef *)ADC2_Base)
#define USART1              ((__IO USART_TypeDef *)USART1_Base)
#define USART2              ((__IO USART_TypeDef *)USART2_Base)
#define USART3              ((__IO USART_TypeDef *)USART3_Base)

#ifdef __cplusplus
}
#endif

#endif /* STM32UTIL_H */
