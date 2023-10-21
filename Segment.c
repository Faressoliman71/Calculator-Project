#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "Segment.h"
void one_segment_display_comm_anode(u8 n)
{
	u8 segment_num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	SEGMENT_PORT1=~segment_num[n];
}
void two_segment_display(u8 n) //n=35
{
	u8 segment_num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	SEGMENT_PORT1=segment_num[n/10];   //dozens >>3
	SEGMENT_PORT2=segment_num[n%10];   //ones   >>5
}
void two_segment_display_shifted(u8 n)
{
	u8 segment_num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	SEGMENT_PORT1=segment_num[n/10];
	SEGMENT_PORT2=segment_num[n%10]<<1;
}
void two_segments_display_one_anode_one_cath(u8 n)
{
	u8 segment_num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	SEGMENT_PORT1=segment_num[n/10];     //com cathode
	SEGMENT_PORT2=~(segment_num[n%10]);  //com anode
}

/**************************************** 7_Seg_BCD******************/
void one_segment_display_BCD(u8 n)
{
	SEGMENT_PORT1=n;
}
void two_segments_display_BCD_on_same_port(u8 n)  //task 1
{
	u8 dig0=n%10;
	u8 dig1=n/10;
	SEGMENT_PORT1=dig0|(dig1<<4);
}

void two_segments_display_BCD_HEXA(u8 n)
{
	SEGMENT_PORT1=n;
}
/********************************************* 7_Seg_MPX*********************/
void segment_MPX_two_digit_display(u8 n)
{
	u8 i=0,segment_num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	u8 d0=n/10;
	u8 d1=n%10;
	for(i=0;i<50;i++)
	{
		SET_BIT(PORTC,7);
		SEGMENT_PORT1=segment_num[d0]<<1;
		CLR_BIT(PORTC,6);
		
		_delay_ms(10);
		SET_BIT(PORTC,6);
		SEGMENT_PORT1=segment_num[d1]<<1;
		CLR_BIT(PORTC,7);
		_delay_ms(10);
	}
}
void segment_MPX_two_digit_display_MCU(u8 n)
{
	u8 arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	u8 d0=n%10;
	u8 d1=n/10;
	SEGMENT_PORT1=arr[d1]<<1;
	SET_BIT(PORTC,7);
	CLR_BIT(PORTC,6);
	_delay_ms(10);
	SEGMENT_PORT1=arr[d0]<<1;
	SET_BIT(PORTC,6);
	CLR_BIT(PORTC,7);
	_delay_ms(10);
}
void traffic(void)
{
	static u8 x=0,i;
	x++;
	if(x==1)
	{
		SET_BIT(PORTA,0);
	}
	if(x==30)
	{
		SET_BIT(PORTA,1);
		CLR_BIT(PORTA,0);
	}
	if(x==60)
	{
		SET_BIT(PORTA,2);
		CLR_BIT(PORTA,1);
	}
	if(x==90)
	{
		x=0;
		CLR_BIT(PORTA,2);
	}
	for(i=0;i<50;i++)
	{
		segment_MPX_two_digit_display_Proteus(x);
	}
}

void seg_MPX2Dig_B1_increment_B2_decrement_1(void)
{
	static u8 x=0,i=0;
	if(x==100)
	{
		x=0;
	}
	else if(!READ_BIT(PINB,0))
	{
		while(!READ_BIT(PINB,0));
		x++;
	}
	else if(!READ_BIT(PINB,1))
	{
		while(!READ_BIT(PINB,1));
		x--;
	}
	for(i=0;i<10;i++)
	{
		segment_MPX_two_digit_display_Proteus(x);
	}
}

void seg_MPX2Dig_B1_increment_B2_decrement_2(void)
{
	static u8 x=0,i=0;
	if(x==100)
	{
		x=0;
	}
	else if(!READ_BIT(PINB,0))
	{
		x++;
	}
	else if(!READ_BIT(PINB,1))
	{
		x--;
	}
	for(i=0;i<10;i++)
	{
		segment_MPX_two_digit_display_Proteus(x);
	}
}


