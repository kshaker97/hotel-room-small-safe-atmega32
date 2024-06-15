#include "lcd_interface.h"

void LCD_voidInit(void){
    LCD_PORT_INIT
    _delay_ms(40);
    LCD_voidWriteCommand(0x3);
    _delay_us(39);
    LCD_voidWriteCommand(0x2);
    LCD_voidWriteCommand(0x28);
    _delay_us(37);
    LCD_voidWriteCommand(0x8);
    LCD_voidWriteCommand(0x1);
    LCD_voidWriteCommand(0x6);
    LCD_voidWriteCommand(0xF);
}
void LCD_voidWriteCommand(uint8_t copy_u8Command){
    RS(0);
    RW(0);
    D7(GET_BIT(copy_u8Command, 7));
    D6(GET_BIT(copy_u8Command, 6));
    D5(GET_BIT(copy_u8Command, 5));
    D4(GET_BIT(copy_u8Command, 4));
    EN(1); _delay_ms(1); EN(0); _delay_ms(1);
    D7(GET_BIT(copy_u8Command, 3));
    D6(GET_BIT(copy_u8Command, 2));
    D5(GET_BIT(copy_u8Command, 1));
    D4(GET_BIT(copy_u8Command, 0));
    EN(1); _delay_ms(1); EN(0); _delay_ms(1);

}
void LCD_voidWriteChar(uint8_t copy_u8Char){
    RS(1);
    RW(0);
    D7(GET_BIT(copy_u8Char, 7));
    D6(GET_BIT(copy_u8Char, 6));
    D5(GET_BIT(copy_u8Char, 5));
    D4(GET_BIT(copy_u8Char, 4));
    EN(1); _delay_ms(1); EN(0); _delay_ms(1);
    D7(GET_BIT(copy_u8Char, 3));
    D6(GET_BIT(copy_u8Char, 2));
    D5(GET_BIT(copy_u8Char, 1));
    D4(GET_BIT(copy_u8Char, 0));
    EN(1); _delay_ms(1); EN(0); _delay_ms(1);
}
void LCD_voidWriteString(uint8_t line, uint8_t *str){
    if(line == FIRST_LINE){
        LCD_voidWriteCommand(0x80);
    }
    else if(line == SECOND_LINE){
        LCD_voidWriteCommand(0xC0);
    }
    while(*str != '\0'){
        LCD_voidWriteChar(*str);
        str++;
    }
}
void LCD_voidWriteNumber(uint16_t number){
    if(number == 0){
        LCD_voidWriteChar('0');
    }
    else{
        uint8_t arr[5];
        int8_t i = 0;
        while(number != 0){
            arr[i] = (number % 10) + '0';
            number /= 10;
            ++i;
        }
        --i;
        while(i >= 0){
            LCD_voidWriteChar(arr[i--]);
        }
    }
}
LCD_voidClear(){
    LCD_voidWriteCommand(0x01);
}
