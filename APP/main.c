#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "MathFun.h"
#include "DataType.h"
#include "PID.h"


float Ualpha =  0.0; 
float Ubeta =   0.0; 

float iq;
float id;



// 帕克逆变换+克拉克逆变换
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



void Mypwmtest(float Uq,float Ud, float Angle)
{	
    float I[3];

    iq = Uq;
    id = Ud;

    I[0] = IA(Angle)+12.0f/2;
    I[1] = IB(Angle)+12.0f/2;
    I[2] = IC(Angle)+12.0f/2;

	printf("Angle:%.2f Ia:%.2f Ib:%.2f Ic:%.2f\r\n",Angle,I[0]*100/12.0f,I[1]*100/12.0f,I[2]*100/12.0f);
}



void pwmtest(float Uq,float Ud, float Angle)
{
    float Ua,Ub,Uc;
    float Ualpha,Ubeta; 

    Ualpha =  -Uq*FastSin(DEGTORAD(Angle)); 
    Ubeta =   Uq*FastCos(DEGTORAD(Angle)); 

    // 克拉克逆变换
    Ua = Ualpha + 12.0f/2;
    Ub = (sqrt(3)*Ubeta-Ualpha)/2 + 12.0f/2;
    Uc = (-Ualpha-sqrt(3)*Ubeta)/2 + 12.0f/2;

    printf("Angle:%.2f Ia:%d Ib:%d Ic:%d\r\n",Angle,(unsigned char)(Ua*100/12.0f),(unsigned char)(Ub*100/12.0f),(unsigned char)(Uc*100/12.0f));

}





int main()
{
    u16 i;

    for ( i = 0; i < 359; i++)
    {
        pwmtest(4,0,i);
    }
    printf("========================\r\n");
    for ( i = 0; i < 359; i++)
    {
        Mypwmtest(4,0,i);
    }

    while (1)
    {

    }
    
}





