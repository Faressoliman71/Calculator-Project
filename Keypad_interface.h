


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_



//Initialization function
void KEYPAD_init(void);

//fun return the ascii of the symbol that its button pressed and return 'T'If there is no button press it.
u8 KEYPAD_get_key(void);




#endif /* KEYPAD_INTERFACE_H_ */