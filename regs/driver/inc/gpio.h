#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32_util.h"

typedef enum
{
     BIT_RESET = 0, /*!< Pin state is logic low (0V) */
    BIT_SET        /*!< Pin state is logic high (3.3V) */
} GPIO_PinState;

typedef enum
{
    GPIO_MODE_INPUT = 0x00, /*!< Input floating mode */
    GPIO_MODE_OUTPUT_PP,    /*!< General purpose output push-pull */
    GPIO_MODE_OUTPUT_OD,    /*!< General purpose output open-drain */
    GPIO_MODE_AF_PP,        /*!< Alternate function output push-pull */
    GPIO_MODE_AF_OD,        /*!< Alternate function output open-drain */
    GPIO_MODE_ANALOG,       /*!< Analog mode */
    GPIO_MODE_INPUT_PU,     /*!< Input with pull-up */
    GPIO_MODE_INPUT_PD      /*!< Input with pull-down */
} GPIO_Mode_t;

typedef enum
{
    GPIO_SPEED_NONE = 0x00,  /*!< No speed specified (input mode) */
    GPIO_SPEED_10MHZ = 0x01, /*!< Low speed: max 10 MHz output */
    GPIO_SPEED_2MHZ = 0x02,  /*!< Lowest speed: max 2 MHz output */
    GPIO_SPEED_50MHZ = 0x03  /*!< High speed: max 50 MHz output */
} GPIO_Speed_t;


typedef struct
{
     uint16_t Pin;       /*!< Specifies the GPIO pins to be configured.
                            This parameter can be any value of @ref GPIO_pins_define */
    GPIO_Mode_t Mode;   /*!< Specifies the operating mode for the selected pins.
                                 This parameter can be a value of @ref GPIO_Mode_t */
    GPIO_Speed_t Speed; /*!< Specifies the speed for the selected pins.
                            This parameter can be a value of @ref GPIO_Speed_t */
} GPIO_InitTypeDef;

/**
 * @brief  Port configuration register low (GPIOx_CRL)
 * @note   This register controls the configuration of pins 0-7 for each GPIO port.
 *         Each pin uses 4 bits: 2 bits for MODE and 2 bits for CNF.
 *         - MODE: Sets the pin mode (input/output) and output speed
 *         - CNF: Sets the pin configuration (pull-up/down, open-drain, etc.)
 */
typedef union
{
    __IO uint32_t REG;
    struct
    {
        __IO uint32_t MODE0     : 2; /*!< Bits 1:0 MODE0: Port x mode bits (y = 0) */
        __IO uint32_t CNF0      : 2;  /*!< Bits 3:2 CNF0: Port x configuration bits (y = 0) */
        __IO uint32_t MODE1     : 2; /*!< Bits 5:4 MODE1: Port x mode bits (y = 1) */
        __IO uint32_t CNF1      : 2;  /*!< Bits 7:6 CNF1: Port x configuration bits (y = 1) */
        __IO uint32_t MODE2     : 2; /*!< Bits 9:8 MODE2: Port x mode bits (y = 2) */
        __IO uint32_t CNF2      : 2;  /*!< Bits 11:10 CNF2: Port x configuration bits (y = 2) */
        __IO uint32_t MODE3     : 2; /*!< Bits 13:12 MODE3: Port x mode bits (y = 3) */
        __IO uint32_t CNF3      : 2;  /*!< Bits 15:14 CNF3: Port x configuration bits (y = 3) */
        __IO uint32_t MODE4     : 2; /*!< Bits 17:16 MODE4: Port x mode bits (y = 4) */
        __IO uint32_t CNF4      : 2;  /*!< Bits 19:18 CNF4: Port x configuration bits (y = 4) */
        __IO uint32_t MODE5     : 2; /*!< Bits 21:20 MODE5: Port x mode bits (y = 5) */
        __IO uint32_t CNF5      : 2;  /*!< Bits 23:22 CNF5: Port x configuration bits (y = 5) */
        __IO uint32_t MODE6     : 2; /*!< Bits 25:24 MODE6: Port x mode bits (y = 6) */
        __IO uint32_t CNF6      : 2;  /*!< Bits 27:26 CNF6: Port x configuration bits (y = 6) */
        __IO uint32_t MODE7     : 2; /*!< Bits 29:28 MODE7: Port x mode bits (y = 7) */
        __IO uint32_t CNF7      : 2;  /*!< Bits 31:30 CNF7: Port x configuration bits (y = 7) */
    } BITS;
} GPIO_CRL_t;

/**
 * @brief  Port configuration register high (GPIOx_CRH)
 * @note   This register controls the configuration of pins 8-15 for each GPIO port.
 *         Each pin uses 4 bits: 2 bits for MODE and 2 bits for CNF.
 *         - MODE: Sets the pin mode (input/output) and output speed
 *         - CNF: Sets the pin configuration (pull-up/down, open-drain, etc.)
 */
typedef union
{
    __IO uint32_t REG;
    struct
    {
        __IO uint32_t MODE8     : 2;  /*!< Bits 1:0 MODE8: Port x mode bits (y = 8) */
        __IO uint32_t CNF8      : 2;   /*!< Bits 3:2 CNF8: Port x configuration bits (y = 8) */
        __IO uint32_t MODE9     : 2;  /*!< Bits 5:4 MODE9: Port x mode bits (y = 9) */
        __IO uint32_t CNF9      : 2;   /*!< Bits 7:6 CNF9: Port x configuration bits (y = 9) */
        __IO uint32_t MODE10    : 2; /*!< Bits 9:8 MODE10: Port x mode bits (y = 10) */
        __IO uint32_t CNF10     : 2;  /*!< Bits 11:10 CNF10: Port x configuration bits (y = 10) */
        __IO uint32_t MODE11    : 2; /*!< Bits 13:12 MODE11: Port x mode bits (y = 11) */
        __IO uint32_t CNF11     : 2;  /*!< Bits 15:14 CNF11: Port x configuration bits (y = 11) */
        __IO uint32_t MODE12    : 2; /*!< Bits 17:16 MODE12: Port x mode bits (y = 12) */
        __IO uint32_t CNF12     : 2;  /*!< Bits 19:18 CNF12: Port x configuration bits (y = 12) */
        __IO uint32_t MODE13    : 2; /*!< Bits 21:20 MODE13: Port x mode bits (y = 13) */
        __IO uint32_t CNF13     : 2;  /*!< Bits 23:22 CNF13: Port x configuration bits (y = 13) */
        __IO uint32_t MODE14    : 2; /*!< Bits 25:24 MODE14: Port x mode bits (y = 14) */
        __IO uint32_t CNF14     : 2;  /*!< Bits 27:26 CNF14: Port x configuration bits (y = 14) */
        __IO uint32_t MODE15    : 2; /*!< Bits 29:28 MODE15: Port x mode bits (y = 15) */
        __IO uint32_t CNF15     : 2;  /*!< Bits 31:30 CNF15: Port x configuration bits (y = 15) */
    } BITS;
} GPIO_CRH_t;

/**
 * @brief  Port input data register (GPIOx_IDR)
 * @note   This register provides read access to the input value of GPIO pins.
 *         Each bit represents the input state of the corresponding pin:
 *         - 0: Input is at logic low level
 *         - 1: Input is at logic high level
 */
typedef union
{
    __IO uint32_t REG;
    struct
    {
        __IO uint32_t IDR0      : 1;      /*!< Bit 0 IDR0: Port input data (y = 0) */
        __IO uint32_t IDR1      : 1;      /*!< Bit 1 IDR1: Port input data (y = 1) */
        __IO uint32_t IDR2      : 1;      /*!< Bit 2 IDR2: Port input data (y = 2) */
        __IO uint32_t IDR3      : 1;      /*!< Bit 3 IDR3: Port input data (y = 3) */
        __IO uint32_t IDR4      : 1;      /*!< Bit 4 IDR4: Port input data (y = 4) */
        __IO uint32_t IDR5      : 1;      /*!< Bit 5 IDR5: Port input data (y = 5) */
        __IO uint32_t IDR6      : 1;      /*!< Bit 6 IDR6: Port input data (y = 6) */
        __IO uint32_t IDR7      : 1;      /*!< Bit 7 IDR7: Port input data (y = 7) */
        __IO uint32_t IDR8      : 1;      /*!< Bit 8 IDR8: Port input data (y = 8) */
        __IO uint32_t IDR9      : 1;      /*!< Bit 9 IDR9: Port input data (y = 9) */
        __IO uint32_t IDR10     : 1;     /*!< Bit 10 IDR10: Port input data (y = 10) */
        __IO uint32_t IDR11     : 1;     /*!< Bit 11 IDR11: Port input data (y = 11) */
        __IO uint32_t IDR12     : 1;     /*!< Bit 12 IDR12: Port input data (y = 12) */
        __IO uint32_t IDR13     : 1;     /*!< Bit 13 IDR13: Port input data (y = 13) */
        __IO uint32_t IDR14     : 1;     /*!< Bit 14 IDR14: Port input data (y = 14) */
        __IO uint32_t IDR15     : 1;     /*!< Bit 15 IDR15: Port input data (y = 15) */
        __IO uint32_t RESERVED  : 16; /*!< Bits 31:16 Reserved, must be kept at reset value */
    } BITS;
} GPIO_IDR_t;

/**
 * @brief  Port output data register (GPIOx_ODR)
 * @note   This register provides read/write access to the output value of GPIO pins.
 *         Each bit controls the output state of the corresponding pin:
 *         - 0: Output pin driven to logic low level
 *         - 1: Output pin driven to logic high level
 */
typedef union
{
    __IO uint32_t REG;
    struct
    {
        __IO uint32_t ODR0      : 1;      /*!< Bit 0 ODR0: Port output data (y = 0) */
        __IO uint32_t ODR1      : 1;      /*!< Bit 1 ODR1: Port output data (y = 1) */
        __IO uint32_t ODR2      : 1;      /*!< Bit 2 ODR2: Port output data (y = 2) */
        __IO uint32_t ODR3      : 1;      /*!< Bit 3 ODR3: Port output data (y = 3) */
        __IO uint32_t ODR4      : 1;      /*!< Bit 4 ODR4: Port output data (y = 4) */
        __IO uint32_t ODR5      : 1;      /*!< Bit 5 ODR5: Port output data (y = 5) */
        __IO uint32_t ODR6      : 1;      /*!< Bit 6 ODR6: Port output data (y = 6) */
        __IO uint32_t ODR7      : 1;      /*!< Bit 7 ODR7: Port output data (y = 7) */
        __IO uint32_t ODR8      : 1;      /*!< Bit 8 ODR8: Port output data (y = 8) */
        __IO uint32_t ODR9      : 1;      /*!< Bit 9 ODR9: Port output data (y = 9) */
        __IO uint32_t ODR10     : 1;     /*!< Bit 10 ODR10: Port output data (y = 10) */
        __IO uint32_t ODR11     : 1;     /*!< Bit 11 ODR11: Port output data (y = 11) */
        __IO uint32_t ODR12     : 1;     /*!< Bit 12 ODR12: Port output data (y = 12) */
        __IO uint32_t ODR13     : 1;     /*!< Bit 13 ODR13: Port output data (y = 13) */
        __IO uint32_t ODR14     : 1;     /*!< Bit 14 ODR14: Port output data (y = 14) */
        __IO uint32_t ODR15     : 1;     /*!< Bit 15 ODR15: Port output data (y = 15) */
        __IO uint32_t RESERVED  : 16; /*!< Bits 31:16 Reserved, must be kept at reset value */
    } BITS;
} GPIO_ODR_t;

/**
 * @brief  Port bit set/reset register (GPIOx_BSRR)
 * @note   This register provides atomic bit manipulation for GPIO pins.
 *         Writing 1 to BSy bits sets the corresponding pin to high.
 *         Writing 1 to BRy bits resets the corresponding pin to low.
 *         Writing 0 has no effect. This allows atomic pin manipulation.
 */
typedef union
{
    __IO uint32_t REG;
    struct
    {
        __IO uint32_t BS0       : 1;  /*!< Bit 0 BS0: Port x Set bit 0 */
        __IO uint32_t BS1       : 1;  /*!< Bit 1 BS1: Port x Set bit 1 */
        __IO uint32_t BS2       : 1;  /*!< Bit 2 BS2: Port x Set bit 2 */
        __IO uint32_t BS3       : 1;  /*!< Bit 3 BS3: Port x Set bit 3 */
        __IO uint32_t BS4       : 1;  /*!< Bit 4 BS4: Port x Set bit 4 */
        __IO uint32_t BS5       : 1;  /*!< Bit 5 BS5: Port x Set bit 5 */
        __IO uint32_t BS6       : 1;  /*!< Bit 6 BS6: Port x Set bit 6 */
        __IO uint32_t BS7       : 1;  /*!< Bit 7 BS7: Port x Set bit 7 */
        __IO uint32_t BS8       : 1;  /*!< Bit 8 BS8: Port x Set bit 8 */
        __IO uint32_t BS9       : 1;  /*!< Bit 9 BS9: Port x Set bit 9 */
        __IO uint32_t BS10      : 1; /*!< Bit 10 BS10: Port x Set bit 10 */
        __IO uint32_t BS11      : 1; /*!< Bit 11 BS11: Port x Set bit 11 */
        __IO uint32_t BS12      : 1; /*!< Bit 12 BS12: Port x Set bit 12 */
        __IO uint32_t BS13      : 1; /*!< Bit 13 BS13: Port x Set bit 13 */
        __IO uint32_t BS14      : 1; /*!< Bit 14 BS14: Port x Set bit 14 */
        __IO uint32_t BS15      : 1; /*!< Bit 15 BS15: Port x Set bit 15 */
        __IO uint32_t BR0       : 1;  /*!< Bit 16 BR0: Port x Reset bit 0 */
        __IO uint32_t BR1       : 1;  /*!< Bit 17 BR1: Port x Reset bit 1 */
        __IO uint32_t BR2       : 1;  /*!< Bit 18 BR2: Port x Reset bit 2 */
        __IO uint32_t BR3       : 1;  /*!< Bit 19 BR3: Port x Reset bit 3 */
        __IO uint32_t BR4       : 1;  /*!< Bit 20 BR4: Port x Reset bit 4 */
        __IO uint32_t BR5       : 1;  /*!< Bit 21 BR5: Port x Reset bit 5 */
        __IO uint32_t BR6       : 1;  /*!< Bit 22 BR6: Port x Reset bit 6 */
        __IO uint32_t BR7       : 1;  /*!< Bit 23 BR7: Port x Reset bit 7 */
        __IO uint32_t BR8       : 1;  /*!< Bit 24 BR8: Port x Reset bit 8 */
        __IO uint32_t BR9       : 1;  /*!< Bit 25 BR9: Port x Reset bit 9 */
        __IO uint32_t BR10      : 1; /*!< Bit 26 BR10: Port x Reset bit 10 */
        __IO uint32_t BR11      : 1; /*!< Bit 27 BR11: Port x Reset bit 11 */
        __IO uint32_t BR12      : 1; /*!< Bit 28 BR12: Port x Reset bit 12 */
        __IO uint32_t BR13      : 1; /*!< Bit 29 BR13: Port x Reset bit 13 */
        __IO uint32_t BR14      : 1; /*!< Bit 30 BR14: Port x Reset bit 14 */
        __IO uint32_t BR15      : 1; /*!< Bit 31 BR15: Port x Reset bit 15 */
    } BITS;
} GPIO_BSRR_t;

/**
 * @brief  Port bit reset register (GPIOx_BRR)
 * @note   This register provides write-only access to reset GPIO pins to low.
 *         Writing 1 to BRy bits resets the corresponding pin to low.
 *         Writing 0 has no effect. This register is provided for compatibility.
 */
typedef union
{
    __IO uint32_t REG;
    struct
    {
        __IO uint32_t BR0       : 1;       /*!< Bit 0 BR0: Port x Reset bit 0 */
        __IO uint32_t BR1       : 1;       /*!< Bit 1 BR1: Port x Reset bit 1 */
        __IO uint32_t BR2       : 1;       /*!< Bit 2 BR2: Port x Reset bit 2 */
        __IO uint32_t BR3       : 1;       /*!< Bit 3 BR3: Port x Reset bit 3 */
        __IO uint32_t BR4       : 1;       /*!< Bit 4 BR4: Port x Reset bit 4 */
        __IO uint32_t BR5       : 1;       /*!< Bit 5 BR5: Port x Reset bit 5 */
        __IO uint32_t BR6       : 1;       /*!< Bit 6 BR6: Port x Reset bit 6 */
        __IO uint32_t BR7       : 1;       /*!< Bit 7 BR7: Port x Reset bit 7 */
        __IO uint32_t BR8       : 1;       /*!< Bit 8 BR8: Port x Reset bit 8 */
        __IO uint32_t BR9       : 1;       /*!< Bit 9 BR9: Port x Reset bit 9 */
        __IO uint32_t BR10      : 1;      /*!< Bit 10 BR10: Port x Reset bit 10 */
        __IO uint32_t BR11      : 1;      /*!< Bit 11 BR11: Port x Reset bit 11 */
        __IO uint32_t BR12      : 1;      /*!< Bit 12 BR12: Port x Reset bit 12 */
        __IO uint32_t BR13      : 1;      /*!< Bit 13 BR13: Port x Reset bit 13 */
        __IO uint32_t BR14      : 1;      /*!< Bit 14 BR14: Port x Reset bit 14 */
        __IO uint32_t BR15      : 1;      /*!< Bit 15 BR15: Port x Reset bit 15 */
        __IO uint32_t RESERVED : 16; /*!< Bits 31:16 Reserved, must be kept at reset value */
    } BITS;
} GPIO_BRR_t;

/**
 * @brief  Port configuration lock register (GPIOx_LCKR)
 * @note   This register allows freezing the GPIO configuration until next reset.
 *         The lock mechanism requires a specific write sequence to LCKK bit:
 *         1. Write '1' to LCKK + desired LCKy bits
 *         2. Write '0' to LCKK + desired LCKy bits
 *         3. Write '1' to LCKK + desired LCKy bits
 *         4. Read LCKK bit (should return '1')
 */
typedef union
{
    __IO uint32_t REG;
    struct
    {
    __IO uint32_t LCK0      : 1;      /*!< Bit 0 LCK0: Port x Lock bit 0 */
    __IO uint32_t LCK1      : 1;      /*!< Bit 1 LCK1: Port x Lock bit 1 */
    __IO uint32_t LCK2      : 1;      /*!< Bit 2 LCK2: Port x Lock bit 2 */
    __IO uint32_t LCK3      : 1;      /*!< Bit 3 LCK3: Port x Lock bit 3 */
    __IO uint32_t LCK4      : 1;      /*!< Bit 4 LCK4: Port x Lock bit 4 */
    __IO uint32_t LCK5      : 1;      /*!< Bit 5 LCK5: Port x Lock bit 5 */
    __IO uint32_t LCK6      : 1;      /*!< Bit 6 LCK6: Port x Lock bit 6 */
    __IO uint32_t LCK7      : 1;      /*!< Bit 7 LCK7: Port x Lock bit 7 */
    __IO uint32_t LCK8      : 1;      /*!< Bit 8 LCK8: Port x Lock bit 8 */
    __IO uint32_t LCK9      : 1;      /*!< Bit 9 LCK9: Port x Lock bit 9 */
    __IO uint32_t LCK10     : 1;     /*!< Bit 10 LCK10: Port x Lock bit 10 */
    __IO uint32_t LCK11     : 1;     /*!< Bit 11 LCK11: Port x Lock bit 11 */
    __IO uint32_t LCK12     : 1;     /*!< Bit 12 LCK12: Port x Lock bit 12 */
    __IO uint32_t LCK13     : 1;     /*!< Bit 13 LCK13: Port x Lock bit 13 */
    __IO uint32_t LCK14     : 1;     /*!< Bit 14 LCK14: Port x Lock bit 14 */
    __IO uint32_t LCK15     : 1;     /*!< Bit 15 LCK15: Port x Lock bit 15 */
    __IO uint32_t LCKK      : 1;      /*!< Bit 16 LCKK: Lock key bit */
    __IO uint32_t RESERVED  : 15; /*!< Bits 31:17 Reserved, must be kept at reset value */
    } BITS;
} GPIO_LCKR_t;

/**
 * @brief  GPIO register structure definition
 * @note   This structure maps all GPIO registers for direct access to
 *         GPIO peripherals. Each GPIO port has its own base address:
 *         - GPIOA: 0x40010800
 *         - GPIOB: 0x40010C00
 *         - GPIOC: 0x40011000
 *         - GPIOD: 0x40011400
 *         - etc.
 */
typedef struct
{
    GPIO_CRL_t CRL;   /*!< GPIO port configuration register low,     offset: 0x00 */
    GPIO_CRH_t CRH;   /*!< GPIO port configuration register high,    offset: 0x04 */
    GPIO_IDR_t IDR;   /*!< GPIO port input data register,            offset: 0x08 */
    GPIO_ODR_t ODR;   /*!< GPIO port output data register,           offset: 0x0C */
    GPIO_BSRR_t BSRR; /*!< GPIO port bit set/reset register,         offset: 0x10 */
    GPIO_BRR_t BRR;   /*!< GPIO port bit reset register,             offset: 0x14 */
    GPIO_LCKR_t LCK;  /*!< GPIO port configuration lock register,    offset: 0x18 */
} GPIO_TypeDef;
/**
 * @}
 */
/** @defgroup GPIO_Exported_Functions
 * @{
 */
/**
 * @brief  Initializes the GPIO peripheral according to the specified parameters
 * @note   This function configures the selected pins with the specified mode,
 *         speed, and pull-up/pull-down settings. It automatically handles
 *         the MODE and CNF bit field calculations for CRL/CRH registers.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral
 * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that
 *         contains the configuration information for the specified GPIO pins
 * @retval None
 * @example:
 *         GPIO_InitTypeDef GPIO_InitStruct;
 *         GPIO_InitStruct.Pin = GPIO_PIN_13;
 *         GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 *         GPIO_InitStruct.Speed = GPIO_SPEED_50MHZ;
 *         GPIO_Init(GPIOC, &GPIO_InitStruct);
 */
void GPIO_Init(volatile GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);
/**
 * @brief  Sets or clears the selected data port bit
 * @note   This function uses the BSRR register for atomic bit manipulation,
 *         which is safer in multithreaded environments than direct ODR access.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral
 * @param  GPIO_Pin: specifies the port bit to write
 *         This parameter can be any combination of GPIO_PIN_x where x can be (0..15)
 * @param  state: specifies the value to be written to the selected bit
 *         This parameter can be one of the GPIO_PinState enum values:
 *         @arg BIT_RESET: to clear the port pin
 *         @arg BIT_SET: to set the port pin
 * @retval None
 */
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState state);
/**
 * @brief  Reads the specified input port pin
 * @note   This function reads the IDR register to get the current pin state
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral
 * @param  GPIO_Pin: specifies the port bit to read
 *         This parameter can be GPIO_PIN_x where x can be (0..15)
 * @retval The input pin value (BIT_RESET or BIT_SET)
 */
uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
/**
 * @brief  Toggles the specified GPIO pin
 * @note   This function reads the current ODR state and toggles the specified pin
 *         using the BSRR register for atomic operation
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral
 * @param  GPIO_Pin: specifies the pins to be toggled
 *         This parameter can be any combination of GPIO_PIN_x where x can be (0..15)
 * @retval None
 */
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);


#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
