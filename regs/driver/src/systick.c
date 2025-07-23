#include "systick.h"

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

/* SysTick Control Register Bit Definitions */
#define SYS_CTRL_EN (1U << 0)       /*!< Counter enable */
#define SYS_CTRL_TICKINT (1U << 1)  /*!< Enable SysTick exception request */
#define SYS_CTRL_CLKSRC (1U << 2)   /*!< Clock source: 0 = external, 1 = processor clock (AHB) */
#define SYS_CTRL_CNTFLAG (1U << 16) /*!< Returns 1 if timer counted to 0 since last read */

/* Global millisecond counter */
static volatile uint32_t systick_ms = 0;

/**
 * @brief  Initializes the SysTick timer to generate interrupt every `ticks_ms` ticks.
 * @param  ticks_ms: Reload value. Assuming AHB = 72 MHz, for 1ms tick use 72000.
 * @retval None
 */
void SysTick_Init(uint32_t ticks_ms)
{
  /* Disable SysTick during configuration */
  SYSTICK_CTRL = 0;

  /* Set reload register */
  SYSTICK_LOAD = ticks_ms - 1;

  /* Reset current value register */
  SYSTICK_VAL = 0;

  /* Enable SysTick, enable interrupt, select processor clock */
  SYSTICK_CTRL |= SYS_CTRL_EN | SYS_CTRL_TICKINT | SYS_CTRL_CLKSRC;
  // SYSTICK_CTRL |= 0x07; // Also valid, but less clear than using named macros
}

/**
 * @brief  SysTick interrupt handler. Called every 1ms (if configured properly).
 * @note   Toggles PC13 every 500ms as heartbeat blink.
 * @retval None
 */
void SysTick_Handler(void)
{
  systick_ms++;
  if (systick_ms % 500 == 0)
  {
    GPIO_TogglePin(GPIOC, GPIO_PIN_13);
  }
}

/**
 * @brief  Returns number of milliseconds since system start.
 * @retval Milliseconds since SysTick_Init()
 */
uint32_t millis(void)
{
  return systick_ms;
}

/**
 * @brief  Blocking delay for a specified number of milliseconds.
 * @param  ms: Duration in milliseconds
 * @retval None
 */
void delay_ms(uint32_t ms)
{
  uint32_t start = millis();
  while ((millis() - start) < ms)
    ;
}
