#include "Keypad_cfg.h"
#include "Keypad_interface.h"
#include "Utils.h"
#include "DIO_cfg.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "StdTypes.h"
#include "MemMap.h"
#include "Segment.h"
#include "LCD_cfg.h"
#include "LCD_interface.h"
#include "MOTOR_cfg.h"
#include "MOTOR_interface.h"
#include "MOTOR_private.h"
#include <util/delay.h> 



#include <avr/io.h>


int main(void)
{
	DIO_init_all_pins();

     LCD_init();
	 LCD_write_string("Fares Calculator");
	 _delay_ms(50);
	 LCD_clear();
	 KEYPAD_init();
	
	u8 key ='T' ;
	u8 num1 = 0;
	u8 num2 = 0;
	u8 flag = 0;
	u32 result = 0;
	u8 operation = 0;
	  
    while (1) 
    {		
	 key = KEYPAD_get_key();
	 if ( key >= '0' && key <= '9' && flag == 0)
	 {
		 LCD_write_char(key);
		 num1 = num1 * 10 + key - '0';
		 
	 }
	 switch ( key )
	 {
		 case '+' :
		 LCD_write_char('+');
		 flag=1;
		 operation='+';
		 break ;
		 case '-':
		 LCD_write_char('-');
		 flag=1;
		 operation = '-';
		 break ;
		 case '*':
		 LCD_write_char('*');
		 flag=1;
		 operation='*';
		 break;
		 case '/':
		 LCD_write_char('/');
		 flag=1;
		 operation='/';
		 break;
		 
	 }
	 
	 if ( key >= '0' && key <= '9' && flag == 1)
	 {
		 LCD_write_char(key);
		 num2 =  num2 * 10 + key - '0';
	 }
	 
	 if ( key == '=')
	 {
		 LCD_GoTo(1,0);
		 switch (operation)
		 {
			 case '+' :
			 result = num1 + num2 ;
			 break ;
			 case '-':
			 result = num1-num2;
			 break ;
			 case '*':
			 result = num1 * num2;
			 break;
			 case '/':
			 if ( num2 == 0)
			 {
				 LCD_write_string("ERROR") ;
			 }
			 else
			 {
				 result = num1 / num2;
			 }
			 break;
		 }
		 	 LCD_write_number(result);
	 }
	 
	 if ( key == 'c')
	 {
		 	
		 	 key ='T' ;
		    num1 = 0;
		 	 num2 = 0;
		 	flag = 0;
		 	 result = 0;
		 	 operation = 0;
		 LCD_clear();
		 LCD_GoTo(0,0);
		 
	 }


    }

}