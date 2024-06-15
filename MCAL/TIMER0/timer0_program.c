#include "timer0_interface.h"

void TIMER0_voidInit(void){
    TCCR0 = 0x00;
    TCNT0 = 0x00;
    SET_BIT(TIMSK, TOIE0);
    SET_BIT(TCCR0, CS00); SET_BIT(TCCR0, CS01);
}
void TIMER0_voidDelay_ms(double ms){
    double max_delay = TIMER_TICK * 256;
    uint16_t number_overflow = (ms/1000) / max_delay;
    uint16_t i;
    for(i = 0; i < number_overflow; ++i){
        while(GET_BIT(TIFR, TOV0) == 0);
        SET_BIT(TIFR, TOV0);
    }
}
void TIMER0_voidDelay_us(double us){
    double max_delay = TIMER_TICK * 256;
    uint16_t number_overflow = (us/1000000) / max_delay;
    uint16_t i;
    for(i = 0; i < number_overflow; ++i){
        while(GET_BIT(TIFR, TOV0) == 0);
        SET_BIT(TIFR, TOV0);
    }
}
