#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../UTILS/bit_math.h"
#include "../../UTILS/std_types.h"

#include "dio_config.h"
#include "dio_private.h"

void DIO_voidSetPinDirection(uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Direction);
void DIO_voidSetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Value);
void DIO_voidTogPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin);
uint8_t DIO_u8GetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin);

#endif /* DIO_INTERFACE_H */
