# STM32F103C8T6 Register Programming Guide

🚀 **Repository chuyên về lập trình STM32F103C8T6 ở mức thanh ghi (Register Level)**

Tài liệu và code mẫu này sẽ giúp bạn hiểu sâu về cách hoạt động của vi điều khiển STM32 thông qua việc trực tiếp thao tác với các thanh ghi, không sử dụng HAL Library.

## ⭐ Điểm nổi bật của folder `/regs`

### 📚 **Tài liệu học tập chi tiết**
- `document.md` - Hướng dẫn lập trình register level từ cơ bản đến nâng cao
- Hình ảnh minh họa trong folder `image/` và `images/`
- Giải thích chi tiết về memory map, clock system, và các peripheral

### 🔧 **Driver tự viết hoàn chỉnh**
- **driver/inc/** - Header files cho các peripheral:
  - `rcc.h` - Reset and Clock Control
  - `gpio.h` - General Purpose Input/Output  
  - `uart.h` - Universal Asynchronous Receiver/Transmitter
  - `adc.h` - Analog to Digital Converter
  - `tim.h` - Timer/Counter
  - `exti.h` - External Interrupt
  - `afio.h` - Alternate Function I/O
  - `systick.h` - System Tick Timer

- **driver/src/** - Source code implementation cho tất cả peripheral trên

### 💼 **Project thực hành**
- **mdk/** - Keil MDK project files với cấu hình đầy đủ
- **user/** - Code ví dụ sử dụng driver tự viết
- Ví dụ: Chớp tắt LED sử dụng GPIO và SysTick delay

## 🎯 Tại sao học lập trình Register Level?

✅ **Hiểu sâu về phần cứng** - Nắm rõ cách vi điều khiển hoạt động bên trong  
✅ **Tối ưu hiệu năng** - Code chạy nhanh hơn, tốn ít bộ nhớ hơn  
✅ **Debug hiệu quả** - Dễ dàng tìm và sửa lỗi khi hiểu rõ register  
✅ **Không phụ thuộc library** - Tự chủ hoàn toàn trong việc phát triển  
✅ **Kiến thức nền tảng** - Chuẩn bị tốt cho embedded system engineer  

## 📖 Cách học hiệu quả

🎯 **Bước 1:** Đọc tài liệu `regs/document.md` để nắm kiến thức cơ bản  
🎯 **Bước 2:** Xem code trong `regs/driver/` để hiểu cách implement  
🎯 **Bước 3:** Chạy ví dụ trong `regs/user/main.c` để thực hành  
🎯 **Bước 4:** Tự viết driver cho peripheral khác dựa trên template có sẵn  

## 🔍 Nội dung chi tiết trong `/regs`

### 📋 Danh sách peripheral được hỗ trợ:
- **RCC** - Cấu hình clock system cho toàn bộ MCU
- **GPIO** - Điều khiển chân input/output với các mode khác nhau  
- **SysTick** - Timer hệ thống cho delay và scheduling
- **UART** - Giao tiếp serial với máy tính hoặc thiết bị khác
- **Timer** - PWM, capture, compare và đếm thời gian
- **ADC** - Đọc giá trị analog từ sensor
- **EXTI** - Xử lý ngắt ngoài từ button hoặc sensor
- **AFIO** - Cấu hình chức năng alternate cho GPIO

### 🛠️ Cấu trúc code mẫu:
```c
#include "rcc.h"     // Clock configuration
#include "gpio.h"    // GPIO control  
#include "systick.h" // Delay functions

// Khởi tạo peripheral
RCC_APB2ClockCmd(RCC_APB2_GPIOC, ENABLE);
GPIO_Init(GPIOC, &GPIO_InitStruct);

// Sử dụng peripheral  
GPIO_WritePin(GPIOC, GPIO_PIN_13, BIT_RESET);
delay_ms(1000);
```

## ⚙️ Hardware và Development Environment

### 🔧 Hardware Requirements:
- **MCU**: STM32F103C8T6 (Blue Pill board)
- **Debugger**: ST-Link V2 hoặc tương tự
- **Components**: LED, resistor, breadboard cho testing

### 💻 Software Requirements:
- **IDE**: Keil uVision MDK-ARM (recommended)
- **Alternative**: STM32CubeIDE, PlatformIO, hoặc makefile
- **Documentation**: STM32F103 Reference Manual (có sẵn trong `/doc`)

## 🚀 Quick Start Guide

### Bước 1: Mở project
```bash
# Điều hướng đến folder regs
cd regs/mdk
# Mở file .uvprojx bằng Keil uVision
```

### Bước 2: Build và flash
1. Build project (F7)
2. Kết nối ST-Link với Blue Pill
3. Flash code vào MCU (F8)
4. Quan sát LED PC13 chớp tắt mỗi giây

### Bước 3: Tùy chỉnh code
- Sửa `regs/user/main.c` để thay đổi logic
- Thêm peripheral mới bằng cách include header tương ứng
- Tham khảo `regs/document.md` để hiểu cách cấu hình register

## � Tài liệu tham khảo

### 📄 Documents trong repository:
- `doc/stm32f103_reference_manual.pdf` - Reference Manual chính thức
- `doc/datasheet_cd00161566.pdf` - STM32F103C8T6 Datasheet  
- `doc/pm0056_arm_cortex_m3_programming_manual.pdf` - ARM Cortex-M3 Manual
- `doc/STM32F103C8T6-Schematic.pdf` - Sơ đồ mạch Blue Pill

### 🌐 Resources online:
- [STM32F103 Reference Manual](https://www.st.com/resource/en/reference_manual/rm0008-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)
- [ARM Cortex-M3 Technical Reference](https://developer.arm.com/documentation/ddi0337/latest/)
- [Blue Pill Pinout](https://os.mbed.com/users/hudakz/code/STM32F103C8T6_Hello/)

## 🤝 Đóng góp và phát triển

### 🔄 Cách đóng góp:
1. Fork repository này
2. Tạo branch mới cho feature/bugfix
3. Commit và push changes
4. Tạo Pull Request

### 💡 Ý tưởng phát triển:
- [ ] Thêm driver cho CAN, I2C, SPI
- [ ] Tạo examples phức tạp hơn (RTOS, USB)  
- [ ] Viết unit tests cho driver
- [ ] Port sang compiler khác (GCC, IAR)

---

## 🎯 Mục tiêu học tập

✨ **Sau khi hoàn thành course này, bạn sẽ có thể:**
- Đọc hiểu Reference Manual và Datasheet một cách thành thạo
- Viết driver cho bất kỳ peripheral nào của STM32
- Debug lỗi ở mức register một cách hiệu quả  
- Tối ưu code để đạt hiệu năng cao nhất
- Chuyển đổi sang các dòng STM32 khác một cách dễ dàng

---

> 💬 **"Hiểu sâu một chút, áp dụng được nhiều"** - Đây là triết lý của việc học lập trình register level.

*Repository này được tạo cho mục đích học tập và chia sẻ kiến thức về lập trình STM32 register level.*
