#include "gpio.h"

void GPIO_Init(volatile GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct)
{
    uint32_t pos, config;
    for (pos = 0; pos < 16; pos++)
    {
        if (((uint32_t)GPIO_InitStruct->Pin & (1 << pos)) != 0)
        {
            /* delete old configuration */
            if (pos < 8)
                GPIOx->CRL.REG &= ~((uint32_t)0xF << (pos * 4));
            else
                GPIOx->CRH.REG &= ~((uint32_t)0xF << ((pos - 8) * 4));

            /* create a new configuration */
            switch (GPIO_InitStruct->Mode)
            {
                case GPIO_MODE_OUTPUT_PP:
                    config = ((uint32_t)GPIO_InitStruct->Speed << 0) | (0x00 << 2);
                    break;
                case GPIO_MODE_OUTPUT_OD:
                    config = ((uint32_t)GPIO_InitStruct->Speed << 0) | (0x01 << 2);
                    break;
                case GPIO_MODE_AF_PP:
                    config = ((uint32_t)GPIO_InitStruct->Speed << 0) | (0x02 << 2);
                    break;
                case GPIO_MODE_AF_OD:
                    config = ((uint32_t)GPIO_InitStruct->Speed << 0) | (0x03 << 2);
                    break;
                case GPIO_MODE_ANALOG:
                    config = (0x00 << 0) | (0x00 << 2);
                    break;
                case GPIO_MODE_INPUT:
                    config = (0x00 << 0) | (0x01 << 2);
                    break;
                case GPIO_MODE_INPUT_PU:
                    config = (0x00 << 0) | (0x02 << 2);
                    GPIOx->ODR.REG |= ((uint32_t)1 << pos);
                    break;
                case GPIO_MODE_INPUT_PD:
                    config = (0x00 << 0) | (0x02 << 2);
                    GPIOx->ODR.REG &= ~((uint32_t)1 << pos);
                    break;
            }

            /* write new configuration */
            if (pos < 8)
                GPIOx->CRL.REG |= ((uint32_t)config << (pos * 4));
            else
                GPIOx->CRH.REG |= ((uint32_t)config << ((pos - 8) * 4));
        }
    }
}

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState state)
{
    if (state != BIT_RESET)
        GPIOx->BSRR.REG = (uint32_t)GPIO_Pin;
    else
        GPIOx->BRR.REG = (uint32_t)GPIO_Pin;
}

uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    return (((uint32_t)GPIOx->IDR.REG & GPIO_Pin) != 0) ? 1 : 0;
}

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->ODR.REG ^= (uint32_t)GPIO_Pin;
}



