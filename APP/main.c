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
PID_t Pos_pid;


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

float LimitAngle(float shaft_angle) 
{
  return (float)((int)shaft_angle % 360);
}


//求电角度
float ElectricalAngle(float shaft_angle, int pole_pairs) 
{
  return (shaft_angle * (float)pole_pairs);
}


void pwmtest(float Uq,float Ud, float Angle)
{
    float Ua,Ub,Uc;
    float Ualpha,Ubeta; 
    float angtmp;

    angtmp = LimitAngle(Angle);
    angtmp = ElectricalAngle(angtmp,6);
    angtmp = LimitAngle(angtmp);

    Ualpha =  -Uq*FastSin(DEGTORAD(angtmp)); 
    Ubeta =   Uq*FastCos(DEGTORAD(angtmp)); 

    // 克拉克逆变换
    Ua = Ualpha + 12.0f/2;
    Ub = (sqrt(3)*Ubeta-Ualpha)/2 + 12.0f/2;
    Uc = (-Ualpha-sqrt(3)*Ubeta)/2 + 12.0f/2;

    printf("AngleIn:%.2f AngleLimt:%.2f I:%d I:%d I:%d\r\n",Angle,angtmp,(unsigned char)(Ua*100/12.0f),(unsigned char)(Ub*100/12.0f),(unsigned char)(Uc*100/12.0f));

}





int main()
{
    u32 i;

  PID_Init(&Pos_pid);

  PID_Change_Kp(&Pos_pid,0.15);
  // PID_Change_Ki(&Pos_pid,0.05);
  PID_Change_Kd(&Pos_pid,0.2);

    for ( i = 0; i < 100; i++)
    {
        //pwmtest(6,0,(float)i);
        printf("%.3f\n",PID_Process(&Pos_pid,100.0));

    }

    while (1)
    {

    }
    
}





