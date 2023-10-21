


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "DIO_interface.h"
#include "StdTypes.h"

#define F_CPU 8000000
#include <util/delay.h>


void LCD_write_instruction(u8 instruction);

void LCD_write_data (u8 data);

//Initialization fun (LCD data sheet)
void LCD_init(void);

/***********/
void LCD_write_number (s32);
void integer_to_string (int num , c8 * str);
void string_reverse_each_char(char *str);
int string_length(char*str);
/***********/
void LCD_write_char(u8 ch);

void LCD_write_string(c8* string);

void LCD_clear(void);

void LCD_clear_cell(u8 line,u8 cell,u8 num_of_cell);

void LCD_write_binary(u8 num);

void LCD_write_hex(u8 num);

void LCD_set_cursor(u8 line,u8 cell); //line>>0 1 _cell>>0 to 15

void LCD_set_cursor_write_string(u8 line,u8 cell,u8 *str);

void LCD_moving_word(u8* str,u8 str_len);


void CreateCustomCharacter (u8 *Pattern, const u8 Location);

void LCD_write_hex2(u8 decimalnum);

void LCD_GoTo ( u8 line , u8 cell); // line 0 , 1


#endif /* LCD_INTERFACE_H_ */