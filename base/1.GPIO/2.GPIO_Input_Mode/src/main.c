#include "button.h"

int main(void)
{
    Led_Init();
    Button_Init();

    while (1)
    {
        
        if (Button_IsPressed() && Button2_IsPressed())
        {
            LED_MIXED();
            continue; 
        }

        Button_Update();     
        LED_PIN_13();        
        LED_PIN_14();       
        LED_PIN_15();        
    }
}

