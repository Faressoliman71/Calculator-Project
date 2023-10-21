#include "StdTypes.h"


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}DIO_PIN_STATUS_TYPE;

typedef enum{
	PA,
	PB,
	PC,
	PD
}DIO_PORT_TYPE;

typedef enum
{
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_PIN_TYPE;

typedef enum{
	LOW=0,
	HIGH
}DIO_PIN_VOLTAGE_TYPE;



//1-choose the pin voltage type will be ground or 5 v.
extern void DIO_wright_pin(DIO_PIN_TYPE pin_name,DIO_PIN_VOLTAGE_TYPE volt);

//2-read pin reg if it is input pin(if i interface with button or sensor)
extern DIO_PIN_VOLTAGE_TYPE DIO_read_pin(DIO_PIN_TYPE pin_name);

//3-toggle port reg if it is (high to low OR low to high)
extern void DIO_toggle_pin(DIO_PIN_TYPE pin_name);

//4-write on port reg as one byte (output pins)
extern void DIO_wright_port_reg_as_one_byte(DIO_PORT_TYPE port,u8 value);

//5-read from port reg as one byte (output pins)
extern u8 DIO_read_port_reg_as_one_byte(DIO_PORT_TYPE port);

//6-choose the pins status one time(OUTPUT - Input & pull up - Input & free) by app layer(con)
extern void DIO_init_all_pins(void);

#endif /* DIO_INTERFACE_H_ */