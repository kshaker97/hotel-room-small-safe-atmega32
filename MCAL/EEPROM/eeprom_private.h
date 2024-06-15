#ifndef EEPROM_PRIVATE_H
#define EEPROM_PRIVATE_H

#define EEARH (*(volatile uint8_t*)0x3F)
#define EEARL (*(volatile uint8_t*)0x3E)
#define EEAR (*(volatile uint16_t*)0x3E)

#define EEDR  (*(volatile uint8_t*)0x3D)
#define EECR  (*(volatile uint8_t*)0x3C)

#define EERIE 3
#define EEMWE 2
#define EEWE  1
#define EERE  0

#endif /* EEPROM_PRIVATE_H */
