# STM32F103C8T6 Learning Projects

Đây là repository chứa các project học tập về STM32F103C8T6, bao gồm các ví dụ và bài tập về GPIO, SYSTICK, UART, Timer, ADC và các peripheral khác.

## Cấu trúc thư mục

### `/base` - Các project ví dụ sử dụng HAL Library
- **0.Std** - Standard library examples
- **1.GPIO** - GPIO examples (Input/Output modes, Register-level programming)
- **2.SYSTICK** - SysTick timer examples
- **4.UART** - UART communication examples
- **5.TIM** - Timer examples (Basic, Interrupt, Polling, PWM)
- **6.ADC** - ADC (Analog to Digital Converter) examples

### `/regs` - Register-level driver development
- **driver** - Custom driver implementation
  - **inc** - Header files
  - **src** - Source files
- **mdk** - Keil MDK project files
- **user** - User application code

## Hardware
- **MCU**: STM32F103C8T6
- **Development Board**: Blue Pill hoặc tương tự

## Development Environment
- **IDE**: Keil uVision MDK-ARM
- **Debugger/Programmer**: ST-Link V2

## Cách sử dụng
1. Mở project bằng Keil uVision
2. Build project
3. Flash vào MCU thông qua ST-Link

## Tài liệu tham khảo
- STM32F103C8T6 Datasheet
- STM32F103 Reference Manual
- ARM Cortex-M3 Programming Manual

---
*Repository này được tạo cho mục đích học tập và chia sẻ kiến thức về lập trình STM32.*
