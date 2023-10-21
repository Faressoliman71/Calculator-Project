


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

extern const DIO_PIN_STATUS_TYPE pins_status_array[TOTAL_PINS];


//1-choose the pin status (OUTPUT - Input & pull up - Input & free)
static void DIO_init_pin(DIO_PIN_TYPE pin_name,DIO_PIN_STATUS_TYPE status);




#endif /* DIO_PRIVATE_H_ */