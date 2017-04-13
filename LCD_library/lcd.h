#ifndef LCD_H
#define LCD_H
void LCD_cmd(unsigned char command);
void LCD_write_char(unsigned char character);
void LCD_init();
void LCD_write_text(unsigned char *ptr);
void LCD_write_text_at(unsigned char row,unsigned char column ,char *string);
void LCD_write_char_at(unsigned char row,unsigned char column,unsigned char character);
#endif
