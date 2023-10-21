
#include "DIO_interface.h"





const DIO_PIN_STATUS_TYPE pins_status_array[TOTAL_PINS]=
{
	OUTPUT,      /*port A pin 0 ADC0*/
	OUTPUT,      /*port A pin 1*/
	OUTPUT,      /*port A pin 2*/
	OUTPUT,      /*port A pin 3*/
	INPULL,      /*port A pin 4*/
	INPULL,      /*port A pin 5*/
	INPULL,      /*port A pin 6*/
	INPULL,      /*port A pin 7   ADC7*/
	OUTPUT,      /*port B pin 0*/
	OUTPUT,      /*port B pin 1*/
	OUTPUT,      /*port B pin 2  INT2*/
	OUTPUT,      /*port B pin 3*/
	OUTPUT,      /*port B pin 4*/
	OUTPUT,      /*port B pin 5*/
	OUTPUT,      /*port B pin 6*/
	OUTPUT,      /*port B pin 7*/
	OUTPUT,      /*port C pin 0*/
	OUTPUT,      /*port C pin 1*/
	OUTPUT,      /*port C pin 2*/
	OUTPUT,      /*port C pin 3*/
	OUTPUT,      /*port C pin 4*/
	OUTPUT,      /*port C pin 5*/
	OUTPUT,      /*port C pin 6*/
	OUTPUT,      /*port C pin 7*/
	OUTPUT,      /*port D pin 0*/
	OUTPUT,      /*port D pin 1*/
	INPULL,      /*port D pin 2   INT0 */
	INPULL,     /* port D pin 3   INT1 */
	INPULL,      /*port D pin 4*/
	INPULL,      /*port D pin 5*/
	OUTPUT,      /*port D pin 6    ICP*/
	OUTPUT       /*port D pin 7*/
};
