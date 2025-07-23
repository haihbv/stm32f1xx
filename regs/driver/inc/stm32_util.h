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

#define GPIO_PIN_0     	0x0001
#define GPIO_PIN_1     	0x0002
#define GPIO_PIN_2     	0x0004
#define GPIO_PIN_3     	0x0008
#define GPIO_PIN_4     	0x0010
#define GPIO_PIN_5     	0x0020
#define GPIO_PIN_6     	0x0040
#define GPIO_PIN_7     	0x0080
#define GPIO_PIN_8     	0x0100
#define GPIO_PIN_9     	0x0200
#define GPIO_PIN_10    	0x0400
#define GPIO_PIN_11    	0x0800
#define GPIO_PIN_12    	0x1000
#define GPIO_PIN_13    	0x2000
#define GPIO_PIN_14    	0x4000
#define GPIO_PIN_15    	0x8000
#define GPIO_PIN_ALL   	0xFFFF


#define GPIOA_BASE 			(0x40010800UL)
#define GPIOB_BASE 			(0x40010C00UL)
#define GPIOC_BASE 			(0x40011000UL)
#define GPIOD_BASE 			(0x40011400UL)
#define GPIOE_BASE 			(0x40011800UL)
#define GPIOF_BASE 			(0x40011C00UL)
#define GPIOG_BASE 			(0x40012000UL)

#define RCC_BASE    		(0x40021000UL)
#define FLASH_BASE 			(0x40022000UL)
#define AFIO_BASE 			(0x40010000UL)
#define NVIC_Base 			(0xE000E100UL)
#define EXTI_Base 			(0x40010400UL)
#define TIM1_Base 			(0x40012C00UL)
#define TIM2_Base 			(0x40000000UL)
#define TIM3_Base 			(0x40000400UL)
#define TIM4_Base 			(0x40000800UL)
#define ADC1_BASE 			(0x40012400UL)
#define ADC2_BASE 			(0x40012800UL)


#define GPIOA 					((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB 					((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC 					((GPIO_TypeDef *)GPIOC_BASE)
#define RCC 						((RCC_TypeDef *)RCC_BASE)
#define FLASH 					((FLASH_TypeDef *)FLASH_BASE)
#define AFIO 						((AFIO_TypeDef *)AFIO_BASE)
#define NVIC 						((volatile NVIC_TypeDef *)NVIC_Base)
#define EXTI 						((volatile EXTI_TypeDef *)EXTI_Base)
#define TIM1 						((volatile TIM_TypeDef *)TIM1_Base)
#define TIM2 						((volatile TIM_TypeDef *)TIM2_Base)
#define TIM3 						((volatile TIM_TypeDef *)TIM3_Base)
#define TIM4 						((volatile TIM_TypeDef *)TIM4_Base)
#define ADC1 	 					((volatile ADC_TypeDef *)ADC1_BASE)
#define ADC2 	 					((volatile ADC_TypeDef *)ADC2_BASE)


#ifdef __cplusplus
}
#endif

#endif /* STM32UTIL_H */
