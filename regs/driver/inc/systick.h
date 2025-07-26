#ifndef __SYSTICK_H
#define __SYSTICK_H

#include <stdint.h>
#include "gpio.h"

/* Image
SYST_CSR (0xE000E010)
+--------------------------------------------------------------------+
| Bit | Ten         | Giai thich                                     |
|-----+-------------+------------------------------------------------|
|  0  | ENABLE      | Bat counter                                    |
|  1  | TICKINT     | Cho phet ngat SysTick                          |
|  2  | CLKSOURCE   | 0: AHB/8 | 1: AHB                              |
| 16  | COUNTFLAG   | Set = 1 khi counter ve 0 (tu xoa khi doc)      |
+--------------------------------------------------------------------+
*/


/* SysTick Register Addresses (ARM Cortex-M3 System Timer) */
#define SYSTICK_CTRL (*((volatile uint32_t *)0xE000E010)) /*!< SysTick Control and Status Register */
#define SYSTICK_LOAD (*((volatile uint32_t *)0xE000E014)) /*!< SysTick Reload Value Register */
#define SYSTICK_VAL (*((volatile uint32_t *)0xE000E018))  /*!< SysTick Current Value Register */

void SysTick_Handler(void);
void SysTick_Init(void);
uint32_t millis(void);
void delay_ms(uint32_t ms);

#endif
