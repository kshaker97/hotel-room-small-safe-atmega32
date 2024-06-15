#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include <util/delay.h>

#include "../../MCAL/DIO/dio_interface.h"

#include "lcd_config.h"
#include "lcd_private.h"

void LCD_voidInit(void);
void LCD_voidWriteCommand(uint8_t copy_u8Command);
void LCD_voidWriteChar(uint8_t copy_u8Char);
void LCD_voidWriteString(uint8_t line, uint8_t *str);
void LCD_voidWriteNumber(uint16_t number);
void LCD_voidClear(void);

#endif /* LCD_INTERFACE_H */
