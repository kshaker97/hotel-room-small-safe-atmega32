#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#include <util/delay.h>

#include "../../MCAL/DIO/dio_interface.h"

#include "keypad_config.h"
#include "keypad_private.h"

void KEYPAD_voidInit(void);
uint8_t KEYPAD_u8GetChar(void);

#endif /* KEYPAD_INTERFACE_H */
