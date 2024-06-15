#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif // F_CPU

#define PRESCALAR (float)64
#define TIMER_TICK (PRESCALAR / F_CPU)

#define TCCR0 (*(volatile uint8_t*)0x53)
#define TCNT0 (*(volatile uint8_t*)0x52)
#define OCR0  (*(volatile uint8_t*)0x5C)
#define TIMSK (*(volatile uint8_t*)0x59)
#define TIFR  (*(volatile uint8_t*)0x58)

#define FOC0 7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0

#define OCIE0 1
#define TOIE0 0

#define OCF0 1
#define TOV0 0

#endif /* TIMER0_PRIVATE_H */
