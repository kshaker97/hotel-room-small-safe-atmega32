#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

#include "../../UTILS/bit_math.h"
#include "../../UTILS/std_types.h"

#include "eeprom_config.h"
#include "eeprom_private.h"

void EEPROM_voidWrite(uint16_t address, uint8_t data);
uint8_t EEPROM_voidRead(uint16_t address);

#endif /* EEPROM_INTERFACE_H */
