#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdio.h>


typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;

typedef volatile unsigned char   vu8;
typedef volatile unsigned short  vu16;
typedef volatile unsigned int    vu32;

typedef  char   s8;
typedef  short  s16;
typedef  int    s32;





#define  TRUE       0
#define  FALSE      1
#define  BUSY       2
#define  ILDE       3
#define  OVER_FLOW  4
#define  DATA_ERR   5
#define  OVER_TIME  6


#define  HIGH   1
#define  LOW    0

#define	Bit_0	0x0001
#define	Bit_1	0x0002
#define	Bit_2	0x0004
#define	Bit_3	0x0008
#define	Bit_4	0x0010
#define	Bit_5	0x0020
#define	Bit_6	0x0040
#define	Bit_7	0x0080
#define	Bit_8	0x0100
#define	Bit_9	0x0200
#define	Bit_10	0x0400
#define	Bit_11	0x0800
#define	Bit_12	0x1000
#define	Bit_13	0x2000
#define	Bit_14	0x4000
#define	Bit_15	0x8000



typedef union 
{
    u8  B08[2];
    u16 B16;
}B16_B08;

typedef union 
{
    u8  B08[4];
    u32 B32;
}B32_B08;

typedef union 
{
    u16 B16[2];
    u32 B32;
}B32_B16;



#endif









