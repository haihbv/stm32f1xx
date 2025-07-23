#include "stm32f10x.h" // Device header


void delay_ms(unsigned int timeout);


int main(void)
{
	/* ___GPIO___ */

	/* Bat Clock PortC */

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	/* Cau hinh PC13 */
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	/* Set PC13 */
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET); // Led OFF

	while (1)
	{
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET); // LED ON

		/* Tao tre */
		delay_ms(100);
	
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);

		/* Tao tre */
		delay_ms(100);
		
	}
}

void delay_ms(unsigned int timeout)
{
	volatile unsigned int t1, t2;
	for (t1 = 0; t1 < timeout; t1++)
	{
		for (t2 = 0; t2 < 0x2aff; t2++)
		{
			__asm__("nop"); // tao delay ngan mat dung 1 chu ky CPU
		}
	}
}
