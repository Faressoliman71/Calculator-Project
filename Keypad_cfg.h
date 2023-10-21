
#include "StdTypes.h"

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
/**********************************KeyPad Matrix Config **********************************/
#define COLS 4
#define ROWS 4

/***********************************Symbols ON BUTTONS CONFIGURE*****************/


static u8 Keypad_array[ROWS][COLS]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'},
};




/*********************************** OUTPUT AND INPUTS PINS CONFIGURE*****************/
#define KEYPAD_FIRST_OUTPUT PINA0
#define KEYPAD_FIRST_INTPUT PINA4
#define NOT_KEY 'T'                // If there is no button pressed




#endif /* KEYPAD_CFG_H_ */