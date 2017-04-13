/*  Name     : main.c
 *  Purpose  : Main file for  a demo project for the implentation of LCD interfacing with AT89S8253 controllers.
               the project  file contains the functions to write a character,write a string in the LCD.Specific 
							 functions are there to write string and character in the desired location by specifying the row 
							 and column in the LCD.
							 
 *  Author   : Etiq Technologies
 *  Date     : 04/05/2016 
 *  Revision : None
 */



#include <REG8253.H>                     
#include "delay.h"                          //header file for delay library


/* access the LCD in data write mode and 
command write mode with RS=1,RW=0 & RS=0,RW=0 respectively */
#define LCD_command_mode(); P3_1=0;P3_2=0;
#define LCD_datawrite_mode(); P3_1=0;P3_2=1; 

/* defines the dataport and control port(Enable pin) */
#define DATA_PORT P2
#define ENABLE_PIN P3_0

/* function to write commands to the LCD command register */
void LCD_cmd(unsigned char command)
{
LCD_command_mode();                    //access in command mode
DATA_PORT=command;                     //command in data port
	
/* LCD enabled with high to low transition in enable 	pin
	 latches the command data in to the command register of LCD*/
ENABLE_PIN=1;
Delay_us(5000);	
ENABLE_PIN=0;	
}

/*function to display a single character to the LCD
The character is displayed at the present cursor postion*/
void LCD_write_char(unsigned char character)
{
  LCD_datawrite_mode();               //access in data write mode
	DATA_PORT=character;                //data in the data port
	
/* LCD enabled with high to low transition in enable 	pin
	 latches the data in to the data register of LCD*/
	
	ENABLE_PIN=1;
  Delay_us(5000);	
  ENABLE_PIN=0;	
}

/*function to initialise the LCD in 8 bit 
mode with initialisation commands*/
void LCD_init()
{
 LCD_cmd(0x38);                                  /* LCD command - 5x7 matrix                                 */
 LCD_cmd(0x83);                                  /* LCD command - Force cursor to the begining of first line */
 LCD_cmd(0x0C);                                  /* LCD command - Display ON, cursor OFF                     */
 LCD_cmd(0x01);                                  /* LCD command - Clear display                              */	
 Delay_us(10000);
}

/*function to write a string to the LCD
   at present cursor location */
void LCD_write_text(unsigned char *ptr)
{
while(*ptr)
{
LCD_write_char(*ptr);
ptr++;
}
}

/* function to write string at the specified cursor position */
void LCD_write_text_at(unsigned char row,unsigned char column ,char *string)
{
if(row&0x01)              //if 1st row or-ing the column position
LCD_cmd(0x80|column);
else if(row&0x02)        // if  2nd row or-ing the column position
LCD_cmd(0xC0|column);
LCD_write_text(string);	  //writes the text
}

void LCD_write_char_at(unsigned char row,unsigned char column,unsigned char character)
{
if(row&0x01)                 //if 1st row or-ing the column position
LCD_cmd(0x80|column);
else if(row&0x02)          // if  2nd row or-ing the column position
LCD_cmd(0xC0|column);

LCD_write_char(character);	 //writes the character
}

/*main function */
void main()
{
LCD_init();                     // initialises the LCD
	
LCD_write_text_at(2,5,"hellooo"); //writes haiii at 2nd row third column
LCD_write_char_at(1,3,'K');     //writes S at 1 row 3rd column
while(1);                       //infinite loop
}
