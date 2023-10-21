#include "StdTypes.h"
#include "DIO_interface.h"

#include "Keypad_cfg.h"
#include "Keypad_interface.h"


void KEYPAD_init(void)
{
	DIO_wright_pin(KEYPAD_FIRST_OUTPUT,HIGH);
	DIO_wright_pin(KEYPAD_FIRST_OUTPUT+1,HIGH);
	DIO_wright_pin(KEYPAD_FIRST_OUTPUT+2,HIGH);
	DIO_wright_pin(KEYPAD_FIRST_OUTPUT+3,HIGH);
}

u8 KEYPAD_get_key(void)
{
	u8 r,c,key=NOT_KEY;
	for (r=0;r<ROWS;r++)
	{
		DIO_wright_pin(KEYPAD_FIRST_OUTPUT+r,LOW);
		for (c=0;c<COLS;c++)
		{
			if (DIO_read_pin(KEYPAD_FIRST_INTPUT+c)==LOW)
			{
				key=Keypad_array[r][c];
				while(DIO_read_pin(KEYPAD_FIRST_INTPUT+c)==LOW);
			}
		}
		DIO_wright_pin(KEYPAD_FIRST_OUTPUT+r,HIGH);
	}
	return key;
}
