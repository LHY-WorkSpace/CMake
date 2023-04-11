#include <stdio.h>
#include "BEEP.h"
#include "KEY.h"
#include "LED.h"
#include "SPI.h"
#include "IIC.h"

void main()
{
    BEEP_Task();
    LED_Task();
    KEY_Task();
    IIC_Task();
    SPI_Task();

    while (1)
    {
        /* code */
    }
    
}





