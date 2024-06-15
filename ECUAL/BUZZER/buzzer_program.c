#include "buzzer_interface.h"

void BUZZER_voidInit(uint8_t u8CopyPort, uint8_t u8CopyPin){
    DIO_voidSetPinDirection(u8CopyPort, u8CopyPin, OUTPUT_PIN);
}
void BUZZER_voidOn(uint8_t u8CopyPort, uint8_t u8CopyPin){
    DIO_voidSetPinValue(u8CopyPort, u8CopyPin, HIGH);
}
void BUZZER_voidOff(uint8_t u8CopyPort, uint8_t u8CopyPin){
    DIO_voidSetPinValue(u8CopyPort, u8CopyPin, LOW);
}
