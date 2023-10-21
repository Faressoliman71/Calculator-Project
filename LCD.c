#include "LCD_cfg.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "Utils.h"
#include "StdTypes.h"


#if LCD_MOOD == _8_BIT 
void LCD_write_instruction( u8 instruction)
{
	DIO_wright_pin(RS, LOW);
	DIO_wright_port_reg_as_one_byte(LCD_PORT , instruction);
		DIO_wright_pin(ENABLE,HIGH);
		_delay_ms(1);
		DIO_wright_pin(ENABLE,LOW);
		_delay_ms(1);
	
}

void LCD_write_data ( u8 data )
{
		DIO_wright_pin(RS,HIGH);
		DIO_wright_port_reg_as_one_byte(LCD_PORT,data);
		DIO_wright_pin(ENABLE,HIGH);
		_delay_ms(1);
		DIO_wright_pin(ENABLE,LOW);
		_delay_ms(1);
	
}

void LCD_init(void)
{
	_delay_ms(50);
	LCD_write_instruction(0x38); //screen on 8 bit
	_delay_ms(1);
	LCD_write_instruction(0x0c); //cursor off (0x0e>>no blink,0x0f>>blink)
	_delay_ms(1);
	LCD_write_instruction(0x01); //clear screen
	_delay_ms(1);
	LCD_write_instruction(0x06);
	
}
#elif LCD_MOOD ==_4_BIT

void LCD_write_instruction(u8 instruction)
{
	DIO_wright_pin(RS,LOW);
	//data high
	DIO_wright_pin(LCD_D7,READ_BIT(instruction,7));
	DIO_wright_pin(LCD_D6,READ_BIT(instruction,6));
	DIO_wright_pin(LCD_D5,READ_BIT(instruction,5));
	DIO_wright_pin(LCD_D4,READ_BIT(instruction,4));
	DIO_wright_pin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_wright_pin(ENABLE,LOW);
	_delay_ms(1);
	
	//data low
	DIO_wright_pin(LCD_D7,READ_BIT(instruction,3));
	DIO_wright_pin(LCD_D6,READ_BIT(instruction,2));
	DIO_wright_pin(LCD_D5,READ_BIT(instruction,1));
	DIO_wright_pin(LCD_D4,READ_BIT(instruction,0));
	DIO_wright_pin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_wright_pin(ENABLE,LOW);
	_delay_ms(1);
	
}

void LCD_write_data(u8 instruction)
{
	DIO_wright_pin(RS,HIGH);
	//data high
	DIO_wright_pin(LCD_D7,READ_BIT(instruction,7));
	DIO_wright_pin(LCD_D6,READ_BIT(instruction,6));
	DIO_wright_pin(LCD_D5,READ_BIT(instruction,5));
	DIO_wright_pin(LCD_D4,READ_BIT(instruction,4));
	DIO_wright_pin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_wright_pin(ENABLE,LOW);
	_delay_ms(1);
	
	//data low
	DIO_wright_pin(LCD_D7,READ_BIT(instruction,3));
	DIO_wright_pin(LCD_D6,READ_BIT(instruction,2));
	DIO_wright_pin(LCD_D5,READ_BIT(instruction,1));
	DIO_wright_pin(LCD_D4,READ_BIT(instruction,0));
	DIO_wright_pin(ENABLE,HIGH);
	_delay_ms(1);
	DIO_wright_pin(ENABLE,LOW);
	_delay_ms(1);
	
}
void LCD_init(void)
{
	_delay_ms(50);
	LCD_write_instruction(0x02);
	LCD_write_instruction(0x28); //screen on 8 bit
	LCD_write_instruction(0x0c); //cursor off (0x0e>>no blink,0x0f>>blink)
	LCD_write_instruction(0x01); //clear screen
	_delay_ms(1);
	LCD_write_instruction(0x06); //increase address DDRAM
}

#endif


void LCD_write_char(u8 ch)
{
	LCD_write_data(ch);
}

void LCD_write_string(c8*string)
{
	u8 i=0;
	for(i=0;string[i];i++)
	{
		LCD_write_char(string[i]);
	}
}
void LCD_clear(void)
{
	LCD_write_instruction(0x01);
	_delay_ms(1);
}
void LCD_clear_cell(u8 line,u8 cell,u8 num_of_cell)
{
	LCD_set_cursor(line,cell);
	for(u8 i=0;i<num_of_cell;i++)
	{
		LCD_write_char(' ');
	}
}
/****************/
int string_length(char*str)
{
	int i;
	for(i=0; str[i]; i++)
	{
	}
	return i;
}
void string_reverse_each_char(char *str)
{
	int j=string_length(str)-1,temp,i=0;
	for(i=0; i<=j;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}
void integer_to_string(int num,c8*str)
{
	int i=0,rem=0,flag=0;
	if(num==0)
	{
		str[0]='0';
		str[1]=0;
		return;
	}
	if(num<0)
	{
		num=(-1)*num;
		flag=1;
	}
	while(num)
	{
		rem=num%10;
		str[i]=rem+'0';
		i++;
		num=num/10;
	}
	if(flag==1)
	{
		str[i]='-';
		i++;
	}
	str[i]=0;
	string_reverse_each_char(str);
}
void LCD_write_number(s32 num)  //very important
{
	u8 string[16];
	integer_to_string(num,string);
	LCD_write_string(string);
}
/******************************************/
void LCD_write_binary(u8 num)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
		if(READ_BIT(num,i)==1)
		{
			LCD_write_number(1);
		}
		else if(READ_BIT(num,i)==0)
		{
			LCD_write_number(0);
		}
	}
}

void LCD_set_cursor(u8 line,u8 cell)
{
	if(line==0)
	{
		LCD_write_instruction(0x80|cell);
	}
	else if(line==1)
	{
		LCD_write_instruction(0x80|0x40|cell);
	}
}
void LCD_write_hex2(u8 decimalnum)
{
	LCD_write_char('0');
	LCD_write_char('x');
	u32  quotient, remainder;
	s16 i, j = 0;
	char hexadecimalnum[100];
	quotient = decimalnum;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
		{
			hexadecimalnum[j++] = 48 + remainder;
		}
		else
		{
			hexadecimalnum[j++] = 55 + remainder;
		}
		quotient = quotient / 16;
	}
	for (i=j-1; i>=0;i--)
	{
		LCD_write_char(hexadecimalnum[i]);
	}
}
void LCD_write_hex(u8 num)
{
	LCD_write_char('0');
	LCD_write_char('X');

     u8 Hnibble =num>>4;
	 u8 Lnibble = num &0x0f ;
	 if (Hnibble <= 9)
	 {
		 LCD_write_char(Hnibble);
		
	 }
	 else 
	 {
		 LCD_write_char(Hnibble-10+'A');
	 }
	  if (Lnibble <= 9)
	  {
		  LCD_write_char(Lnibble);
		  
	  }
	  else
	  {
		  LCD_write_char(Lnibble-10+'A');
	  }
	 

}
void LCD_set_cursor_write_string(u8 line,u8 cell,u8 *str)
{
	LCD_set_cursor(line,cell);
	LCD_write_string(str);
}
 void LCD_moving_word(u8*str,u8 str_length)
 {
	 static u8 line=0;
	 static u8 cell=0;
	 u8 i=0;
	 LCD_set_cursor(line,cell);
	 LCD_write_string(str);
	 _delay_ms(300);
	 LCD_clear();
	 if(cell==16)
	 {
		 if(line==0)
		 {
			 line=1;
		 }
		 else
		 {
			 line=0;
		 }
		 for(i=0;str[i];i++)
		 {
			 LCD_set_cursor(line,1);
			 LCD_write_string(&str[str_length-i]);
			 _delay_ms(300);
			 LCD_clear();
		 }
		 cell=0;
	 }
	 cell++;
 }

 void LCD_moving_word2(u8*str,u8 str_length)
 {
	 static u8 line=0;
	 static u8 cell=1;
	 u8 i=0,l=0;
	 
	 LCD_set_cursor(line,cell);
	 LCD_write_string(str);
	 _delay_ms(500);
	 LCD_clear();
	 if(cell==16-str_length+1)
	 {
		 if(line==0)
		 {
			 l=1;
		 }
		 else
		 {
			 l=0;
		 }
		 for(i=1;str[i];i++)
		 {
			 cell++;
			 LCD_set_cursor(line,cell);
			 LCD_write_string(str);
			 LCD_set_cursor(l,0);
			 LCD_write_string(&str[str_length-i]);
			 _delay_ms(500);
			 LCD_clear();
		 }
	 }
	 if(cell==16)
	 {
		 if(line==0)
		 {
			 line=1;
		 }
		 else
		 {
			 line=0;
		 }
		 
		 cell=0;
	 }
	 cell++;
 }

 void CreateCustomCharacter (unsigned char *Pattern, const unsigned char Location) //pattern is arr of the shape
 {
	 if(Location>7)
	 {
		 //do nothing
	 }
	 int i=0;
	 LCD_write_instruction(0x40+(Location*8));     //Send the Address of CGRAM
	 _delay_ms(1);
	 for (i=0; i<8; i++)
	 LCD_write_data(Pattern[ i ]);         //Pass the bytes of pattern on LCD
	 LCD_write_instruction(0x80);
 }
 void LCD_GoTo ( u8 line , u8 cell)
 {
	 if ( line ==0)
	 {
		 LCD_write_instruction(0x80|cell);
	 }
	 if ( line ==1)
	 {
		 LCD_write_instruction(0x80|0x40|cell);
	 }
	 
 }
 
 