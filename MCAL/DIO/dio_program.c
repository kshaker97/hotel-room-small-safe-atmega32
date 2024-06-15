#include "dio_interface.h"

void DIO_voidSetPinDirection(uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Direction){
    if(copy_u8Direction == OUTPUT_PIN){
        switch(copy_u8Port){
            case DIO_PORTA: SET_BIT(DDRA, copy_u8Pin); break;
            case DIO_PORTB: SET_BIT(DDRB, copy_u8Pin); break;
            case DIO_PORTC: SET_BIT(DDRC, copy_u8Pin); break;
            case DIO_PORTD: SET_BIT(DDRD, copy_u8Pin); break;
            default: /* Error Handling */ break;
        }
    }
    else if(copy_u8Direction == INPUT_PIN){
        switch(copy_u8Port){
            case DIO_PORTA: CLR_BIT(DDRA, copy_u8Pin); break;
            case DIO_PORTB: CLR_BIT(DDRB, copy_u8Pin); break;
            case DIO_PORTC: CLR_BIT(DDRC, copy_u8Pin); break;
            case DIO_PORTD: CLR_BIT(DDRD, copy_u8Pin); break;
            default: /* Error Handling */ break;
        }
    }
}
void DIO_voidSetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Value){
    if(copy_u8Value == HIGH){
        switch(copy_u8Port){
            case DIO_PORTA: SET_BIT(PORTA, copy_u8Pin); break;
            case DIO_PORTB: SET_BIT(PORTB, copy_u8Pin); break;
            case DIO_PORTC: SET_BIT(PORTC, copy_u8Pin); break;
            case DIO_PORTD: SET_BIT(PORTD, copy_u8Pin); break;
            default: /* Error Handling */ break;
        }
    }
    else if(copy_u8Value == LOW){
        switch(copy_u8Port){
            case DIO_PORTA: CLR_BIT(PORTA, copy_u8Pin); break;
            case DIO_PORTB: CLR_BIT(PORTB, copy_u8Pin); break;
            case DIO_PORTC: CLR_BIT(PORTC, copy_u8Pin); break;
            case DIO_PORTD: CLR_BIT(PORTD, copy_u8Pin); break;
            default: /* Error Handling */ break;
        }
    }
}
void DIO_voidTogPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin){
    switch(copy_u8Port){
        case DIO_PORTA: TOG_BIT(PORTA, copy_u8Pin); break;
        case DIO_PORTB: TOG_BIT(PORTB, copy_u8Pin); break;
        case DIO_PORTC: TOG_BIT(PORTC, copy_u8Pin); break;
        case DIO_PORTD: TOG_BIT(PORTD, copy_u8Pin); break;
        default: /* Error Handling */ break;
    }
}
uint8_t DIO_u8GetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin){
    switch(copy_u8Port){
        case DIO_PORTA: return GET_BIT(PINA, copy_u8Pin);
        case DIO_PORTB: return GET_BIT(PINB, copy_u8Pin);
        case DIO_PORTC: return GET_BIT(PINC, copy_u8Pin);
        case DIO_PORTD: return GET_BIT(PIND, copy_u8Pin);
        default: /* Error Handling */ break;
    }
    return -1;
}
