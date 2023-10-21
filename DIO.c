#include "Utils.h"
#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_interface.h"
#include "DIO_private.h"

static void DIO_init_pin(DIO_PIN_TYPE pin_name,DIO_PIN_STATUS_TYPE status)
{
	DIO_PORT_TYPE port = pin_name/8;
	u8 pin = pin_name%8 ;
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin);
			CLR_BIT(PORTA,pin);
			break;
			case PB:
			SET_BIT(DDRB,pin);
			CLR_BIT(PORTB,pin);
			break;
			case PC:
			SET_BIT(DDRC,pin);
			CLR_BIT(PORTC,pin);
			break;
			case PD:
			SET_BIT(DDRD,pin);
			CLR_BIT(PORTD,pin);
			break;
		}
		break;
		
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin);
			CLR_BIT(PORTA,pin);
			break;
			case PB:
			CLR_BIT(DDRB,pin);
			CLR_BIT(PORTB,pin);
			break;
			case PC:
			CLR_BIT(DDRC,pin);
			CLR_BIT(PORTC,pin);
			break;
			case PD:
			CLR_BIT(DDRD,pin);
			CLR_BIT(PORTD,pin);
			break;
		}
		break;
		
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin);
			SET_BIT(PORTA,pin);
			break;
			case PB:
			CLR_BIT(DDRB,pin);
			SET_BIT(PORTB,pin);
			break;
			case PC:
			CLR_BIT(DDRC,pin);
			SET_BIT(PORTC,pin);
			break;
			case PD:
			CLR_BIT(DDRD,pin);
			SET_BIT(PORTD,pin);
			break;
		}
		break;
	}
	
}
void DIO_wright_pin(DIO_PIN_TYPE pin_name,DIO_PIN_VOLTAGE_TYPE volt)
{
	DIO_PORT_TYPE port=pin_name/8;
	u8 pin=pin_name%8;
	if(volt==HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin);
			break;
			case PB:
			SET_BIT(PORTB,pin);
			break;
			case PC:
			SET_BIT(PORTC,pin);
			break;
			case PD:
			SET_BIT(PORTD,pin);
			break;
		}
	}
	else if(volt==LOW)
	{
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin);
			break;
			case PB:
			CLR_BIT(PORTB,pin);
			break;
			case PC:
			CLR_BIT(PORTC,pin);
			break;
			case PD:
			CLR_BIT(PORTD,pin);
			break;
		}
	}
}
DIO_PIN_VOLTAGE_TYPE DIO_read_pin(DIO_PIN_TYPE pin_name)
{
	DIO_PORT_TYPE port=pin_name/8;
	u8 pin=pin_name%8;
	DIO_PIN_VOLTAGE_TYPE pin_vol=LOW;
	switch(port)
	{
		case PA:
		pin_vol=READ_BIT(PINA,pin);
		break;
		case PB:
		pin_vol=READ_BIT(PINB,pin);
		break;
		case PC:
		pin_vol=READ_BIT(PINC,pin);
		break;
		case PD:
		pin_vol=READ_BIT(PIND,pin);
		break;
	}
	return pin_vol;
}
void DIO_toggle_pin(DIO_PIN_TYPE pin)
{
	switch(pin)
	{
		case PINA0:
		TOG_BIT(PORTA,pin);
		break;
		case PINA1:
		TOG_BIT(PORTA,pin);
		break;
		case PINA2:
		TOG_BIT(PORTA,pin);
		break;
		case PINA3:
		TOG_BIT(PORTA,pin);
		break;
		case PINA4:
		TOG_BIT(PORTA,pin);
		break;
		case PINA5:
		TOG_BIT(PORTA,pin);
		break;
		case PINA6:
		TOG_BIT(PORTA,pin);
		break;
		case PINA7:
		TOG_BIT(PORTA,pin);
		break;
		
		case PINB0:
		TOG_BIT(PORTB,0);
		break;
		case PINB1:
		TOG_BIT(PORTB,1);
		break;
		case PINB2:
		TOG_BIT(PORTB,2);
		break;
		case PINB3:
		TOG_BIT(PORTB,3);
		break;
		case PINB4:
		TOG_BIT(PORTB,4);
		break;
		case PINB5:
		TOG_BIT(PORTB,5);
		break;
		case PINB6:
		TOG_BIT(PORTB,6);
		break;
		case PINB7:
		TOG_BIT(PORTB,7);
		break;
		
		case PINC0:
		TOG_BIT(PORTC,0);
		break;
		case PINC1:
		TOG_BIT(PORTC,1);
		break;
		case PINC2:
		TOG_BIT(PORTC,2);
		break;
		case PINC3:
		TOG_BIT(PORTC,3);
		break;
		case PINC4:
		TOG_BIT(PORTC,4);
		break;
		case PINC5:
		TOG_BIT(PORTC,5);
		break;
		case PINC6:
		TOG_BIT(PORTC,6);
		break;
		case PINC7:
		TOG_BIT(PORTC,7);
		break;
		
		case PIND0:
		TOG_BIT(PORTD,0);
		break;
		case PIND1:
		TOG_BIT(PORTD,1);
		break;
		case PIND2:
		TOG_BIT(PORTD,2);
		break;
		case PIND3:
		TOG_BIT(PORTD,3);
		break;
		case PIND4:
		TOG_BIT(PORTD,4);
		break;
		case PIND5:
		TOG_BIT(PORTD,5);
		break;
		case PIND6:
		TOG_BIT(PORTD,6);
		break;
		case PIND7:
		TOG_BIT(PORTD,7);
		break;
	}
}
void DIO_wright_port_reg_as_one_byte(DIO_PORT_TYPE port,u8 value)
{
	switch(port)
	{
		case PA:
		PORTA=value;
		break;
		case PB:
		PORTB=value;
		break;
		case PC:
		PORTC=value;
		break;
		case PD:
		PORTD=value;
		break;
	}
}
u8 DIO_read_port_reg_as_one_byte(DIO_PORT_TYPE port)
{
	u8 value=0;
	switch(port)
	{
		case PA:
		value=PORTA;
		break;
		case PB:
		value=PORTB;
		break;
		case PC:
		value=PORTC;
		break;
		case PD:
		value=PORTD;
		break;
	}
	return value;
}
void DIO_init_all_pins(void)
{
	DIO_PIN_TYPE i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_init_pin(i,pins_status_array[i]);
	}
}
