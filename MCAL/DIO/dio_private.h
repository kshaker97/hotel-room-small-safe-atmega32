#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define HIGH 1
#define LOW  0

#define OUTPUT_PIN 1
#define INPUT_PIN  0

#define OUTPUT_PORT 0xFF
#define INPUT_PORT  0x00;

#define DIO_PORTA 'A'
#define DIO_PORTB 'B'
#define DIO_PORTC 'C'
#define DIO_PORTD 'D'

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PORTA (*(volatile uint8_t*)0x3B)
#define DDRA  (*(volatile uint8_t*)0x3A)
#define PINA  (*(volatile uint8_t*)0x39)

#define PORTB (*(volatile uint8_t*)0x38)
#define DDRB  (*(volatile uint8_t*)0x37)
#define PINB  (*(volatile uint8_t*)0x36)

#define PORTC (*(volatile uint8_t*)0x35)
#define DDRC  (*(volatile uint8_t*)0x34)
#define PINC  (*(volatile uint8_t*)0x33)

#define PORTD (*(volatile uint8_t*)0x32)
#define DDRD  (*(volatile uint8_t*)0x31)
#define PIND  (*(volatile uint8_t*)0x30)

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

#endif /* DIO_PRIVATE_H */
