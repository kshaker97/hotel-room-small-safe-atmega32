#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define FIRST_LINE  0
#define SECOND_LINE 1

#define LCD_PORT_INIT DDRC |= 0b11111110;

#define RS(x) if(x == 0) CLR_BIT(PORTC, PC1); else SET_BIT(PORTC, PC1);
#define RW(x) if(x == 0) CLR_BIT(PORTC, PC2); else SET_BIT(PORTC, PC2);
#define EN(x) if(x == 0) CLR_BIT(PORTC, PC3); else SET_BIT(PORTC, PC3);
#define D4(x) if(x == 0) CLR_BIT(PORTC, PC4); else SET_BIT(PORTC, PC4);
#define D5(x) if(x == 0) CLR_BIT(PORTC, PC5); else SET_BIT(PORTC, PC5);
#define D6(x) if(x == 0) CLR_BIT(PORTC, PC6); else SET_BIT(PORTC, PC6);
#define D7(x) if(x == 0) CLR_BIT(PORTC, PC7); else SET_BIT(PORTC, PC7);

#endif /* LCD_CONFIG_H */
