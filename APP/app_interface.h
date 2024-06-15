#ifndef APP_INTERFACE_H
#define APP_INTERFACE_H

#include "app_config.h"
#include "app_private.h"

#include "../MCAL/EEPROM/eeprom_interface.h"
#include "../MCAL/TIMER0/timer0_interface.h"
#include "../ECUAL/LCD/lcd_interface.h"
#include "../ECUAL/KEYPAD/keypad_interface.h"
#include "../ECUAL/BUZZER/buzzer_interface.h"

void APP_voidInit(void);
void APP_voidStart(void);

uint8_t get_key_press(void);
void get_password(void);
void change_password(void);
void reset_password(void);
uint8_t verify_password(void);

#endif /* APP_INTERFACE_H */
