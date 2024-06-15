#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

#include "buzzer_config.h"
#include "buzzer_private.h"

#include "../../MCAL/DIO/dio_interface.h"

void BUZZER_voidInit(uint8_t u8CopyPort, uint8_t u8CopyPin);
void BUZZER_voidOn(uint8_t u8CopyPort, uint8_t u8CopyPin);
void BUZZER_voidOff(uint8_t u8CopyPort, uint8_t u8CopyPin);

#endif /* BUZZER_INTERFACE_H_ */
