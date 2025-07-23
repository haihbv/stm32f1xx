#ifndef ANALOG_H
#define ANALOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32_util.h"
#include "rcc.h"
#include "systick.h"

typedef struct
{
  volatile uint32_t SR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMPR1;
	volatile uint32_t SMPR2;
	volatile uint32_t JOFR1;
	volatile uint32_t JOFR2; 
	volatile uint32_t JOFR3; 
	volatile uint32_t JOFR4; 
	volatile uint32_t HTR;
	volatile uint32_t LTR;
	volatile uint32_t SQR1;
	volatile uint32_t SQR2;
	volatile uint32_t SQR3;
	volatile uint32_t JSQR;
	volatile uint32_t JDR1;
	volatile uint32_t JDR2;
	volatile uint32_t JDR3;
	volatile uint32_t JDR4;
	volatile uint32_t DR;
} ADC_TypeDef;

#define CR2_ADON_Set                ((uint32_t)0x00000001)
#define CR2_ADON_Reset              ((uint32_t)0xFFFFFFFE)
#define ADC_CR2_CONT								((uint32_t)0x00000002)
#define ADC_CONT_Continuous 				((uint32_t)0x00000002)
#define ADC_CONT_Single			  			((uint32_t)0x00000000)
#define ADC_DataAlign_Right      		((uint32_t)0x00000000)
#define ADC_DataAlign_Left       		((uint32_t)0x00000800)
#define CR2_RSTCAL_Set              ((uint32_t)0x00000008)
#define CR2_CAL_Set                 ((uint32_t)0x00000004) 
#define CR2_DMA_Set                 ((uint32_t)0x00000100)
#define CR2_DMA_Reset               ((uint32_t)0xFFFFFEFF)
#define CR2_SWSTART_Set             ((uint32_t)0x00400000)
#define ADC_CR2_EXTTRIG							(1U << 20) 

#define ADC_CR1_EOCIE								(1U << 5) 
#define ADC_CR1_SCAN 								(1U << 8)  

#define ADC_SMP_CYCLES_1_5					((uint8_t)0x00)
#define ADC_SMP_CYCLES_7_5					((uint8_t)0x01)
#define ADC_SMP_CYCLES_13_5					((uint8_t)0x02)			
#define ADC_SMP_CYCLES_28_5					((uint8_t)0x03)
#define ADC_SMP_CYCLES_41_5					((uint8_t)0x04)
#define ADC_SMP_CYCLES_55_5					((uint8_t)0x05)
#define ADC_SMP_CYCLES_71_5					((uint8_t)0x06)
#define ADC_SMP_CYCLES_239_5				((uint8_t)0x07)

#define ADC_Channel_0               ((uint8_t)0x00)
#define ADC_Channel_1               ((uint8_t)0x01)
#define ADC_Channel_2               ((uint8_t)0x02)
#define ADC_Channel_3               ((uint8_t)0x03)
#define ADC_Channel_4               ((uint8_t)0x04)
#define ADC_Channel_5               ((uint8_t)0x05)
#define ADC_Channel_6               ((uint8_t)0x06)
#define ADC_Channel_7               ((uint8_t)0x07)
#define ADC_Channel_8               ((uint8_t)0x08)
#define ADC_Channel_9               ((uint8_t)0x09)
#define ADC_Channel_10              ((uint8_t)0x0A)
#define ADC_Channel_11              ((uint8_t)0x0B)
#define ADC_Channel_12              ((uint8_t)0x0C)
#define ADC_Channel_13              ((uint8_t)0x0D)
#define ADC_Channel_14              ((uint8_t)0x0E)
#define ADC_Channel_15              ((uint8_t)0x0F)
#define ADC_Channel_16              ((uint8_t)0x10)
#define ADC_Channel_17              ((uint8_t)0x11)

#define ADC_SR_EOC 									(1U << 1)
#define ADC_SR_STRT									(1U << 4)


#ifdef __cplusplus
}
#endif

#endif /* ANALOG_H */
