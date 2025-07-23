#include "systick.h"

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
