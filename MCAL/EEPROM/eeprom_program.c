#include "eeprom_interface.h"

void EEPROM_voidWrite(uint16_t copy_u16Address, uint8_t copy_u8Data){
    while(GET_BIT(EECR, EEWE) == 1);
    EEAR = copy_u16Address;
    EEDR = copy_u8Data;
    SET_BIT(EECR, EEMWE);
    SET_BIT(EECR, EEWE);
}
uint8_t EEPROM_voidRead(uint16_t copy_u16Address){
    while(GET_BIT(EECR, EEWE) == 1);
    EEAR = copy_u16Address;
    SET_BIT(EECR, EERE);
    return EEDR;
}
