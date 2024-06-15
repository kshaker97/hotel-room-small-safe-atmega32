#include "keypad_interface.h"

static const uint8_t KEYPAD_DATA[][3] = {{'1', '2', '3'},
                                         {'4', '5', '6'},
                                         {'7', '8', '9'},
                                         {'*', '0', '#'}};

void KEYPAD_voidInit(void){

    DIO_voidSetPinDirection(KEYPAD_PORT, R1, OUTPUT_PIN);
    DIO_voidSetPinDirection(KEYPAD_PORT, R2, OUTPUT_PIN);
    DIO_voidSetPinDirection(KEYPAD_PORT, R3, OUTPUT_PIN);
    DIO_voidSetPinDirection(KEYPAD_PORT, R4, OUTPUT_PIN);

    DIO_voidSetPinDirection(KEYPAD_PORT, C1, INPUT_PIN);
    DIO_voidSetPinDirection(KEYPAD_PORT, C2, INPUT_PIN);
    DIO_voidSetPinDirection(KEYPAD_PORT, C3, INPUT_PIN);
    //Enabling internal pull-up resistors
    DIO_voidSetPinValue(KEYPAD_PORT, C1, HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, C2, HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, C3, HIGH);

}
uint8_t KEYPAD_u8GetChar(void){
    uint8_t i, j;
    DIO_voidSetPinValue(KEYPAD_PORT, R1, HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, R2, HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, R3, HIGH);
    DIO_voidSetPinValue(KEYPAD_PORT, R4, HIGH);
    for(i = 0; i < 4; ++i){
        DIO_voidSetPinValue(KEYPAD_PORT, i, LOW);
        for(j = 4; j < 7; ++j){
            if(DIO_u8GetPinValue(KEYPAD_PORT, j) == 0){
                while(DIO_u8GetPinValue(KEYPAD_PORT, j) == 0);
                return KEYPAD_DATA[i-0][j-4];
            }
        }
        DIO_voidSetPinValue(KEYPAD_PORT, i, HIGH);
    }
    return 0;
}
