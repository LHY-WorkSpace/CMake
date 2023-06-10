#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
#include "BEEP.h"
#include "KEY.h"
#include "LED.h"
#include "SPI.h"
#include "IIC.h"
#include "MathFun.h"
#include "DataType.h"


#define iq	(10.0f)
#define id	(100.0f)


float IA(float Angle)
{
	float Temp;
	Temp = id * FastCos(DEGTORAD(Angle)) + iq * FastSin(DEGTORAD(Angle));
	return Temp;
}

float IB(float Angle)
{
	float Temp;
	Temp = iq *( 0.866f * FastCos(DEGTORAD(Angle)) + 0.5f * FastSin(DEGTORAD(Angle)) ) + id * (0.866f * FastSin(DEGTORAD(Angle)) - 0.5f * FastCos(DEGTORAD(Angle)));
	return Temp;
}

float IC(float Angle)
{
	float Temp;
	Temp = iq *( 0.5f * FastSin(DEGTORAD(Angle)) - 0.866f * FastCos(DEGTORAD(Angle))) + id * ( 0.5f * FastCos(DEGTORAD(Angle)) + 0.866f * FastSin(DEGTORAD(Angle)) );
	return Temp;
}




void main()
{

	static float Angle  = 0.0f;
	float I[3];
    u8 i;


    for ( i = 0; i < 365; i++)
    {
        I[0] = IA(Angle);
        I[1] = IB(Angle);
        I[2] = IC(Angle);
        
        Angle++;

        printf("Angle:%.2f          Ia:%.2f        Ib:%.2f          Ic:%.2f\r\n",Angle,I[0],I[1],I[2]);

        if(Angle >= 360.0f)
        {
           break;
        }

    }
    



    while (1)
    {
        /* code */
    }
    
}





