#include <stdio.h>
#include "BEEP.h"
#include "IIC.h"


void BEEP_Task(void)
{
    printf("BEEP_Task Run !! \r\n");
    IIC_Task();
}



