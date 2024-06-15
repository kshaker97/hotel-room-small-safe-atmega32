#include "app_interface.h"

static uint8_t password[4];

void APP_voidInit(void){

    TIMER0_voidInit();
    LCD_voidInit();
    KEYPAD_voidInit();
    BUZZER_voidInit(BUZZER_PORT, BUZZER_PIN);

}
void APP_voidStart(void){

    do{

        LCD_voidClear();
        LCD_voidWriteString(FIRST_LINE, (uint8_t*)"Enter Password:");
        get_password();

    }while(verify_password() != 0);

    LCD_voidClear(); LCD_voidWriteString(FIRST_LINE, (uint8_t*)"Unlocked"); TIMER0_voidDelay_ms(2000);
    LCD_voidClear(); LCD_voidWriteString(SECOND_LINE, (uint8_t*)"*:EXT 0:RES #:NW");
    LCD_voidWriteString(FIRST_LINE, (uint8_t*)"Choice:");
    uint8_t choice = get_key_press();

    BUZZER_voidOn(BUZZER_PORT, BUZZER_PIN);
    TIMER0_voidDelay_ms(100);
    BUZZER_voidOff(BUZZER_PORT, BUZZER_PIN);

    if(choice == '#'){
        LCD_voidClear(); LCD_voidWriteString(FIRST_LINE, (uint8_t*)"New Password:");
        LCD_voidWriteCommand(0xC0);
        change_password();
        LCD_voidClear(); LCD_voidWriteString(FIRST_LINE, (uint8_t*)"Password changed"); TIMER0_voidDelay_ms(2000);
    }
    else if(choice == '*'){
        return;
    }
    else if(choice == '0'){
        LCD_voidClear();
        LCD_voidWriteChar(choice);
        uint8_t i = 0, reset[10], flag = 0;
        do{
            reset[i] = get_key_press();
            BUZZER_voidOn(BUZZER_PORT, BUZZER_PIN);
            LCD_voidWriteChar(reset[i]);
            TIMER0_voidDelay_ms(100);
            BUZZER_voidOff(BUZZER_PORT, BUZZER_PIN);

            ++i;

        }while(i < 9);

        for(i = 1; i < 9; ++i){
            if(reset[i] != '0'){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            reset_password();
            LCD_voidClear(); LCD_voidWriteString(FIRST_LINE, (uint8_t*)"Password reset"); TIMER0_voidDelay_ms(2000);
        }

    }
}

uint8_t get_key_press(void){
    while(1){
        uint8_t read = KEYPAD_u8GetChar();
        if(read != 0){
            return read;
        }
    }
}

void get_password(void){
    uint8_t i = 0;
    LCD_voidWriteCommand(0xC0);
    while(i < 4){
        uint8_t read = KEYPAD_u8GetChar();
        if(read != 0){
            BUZZER_voidOn(BUZZER_PORT, BUZZER_PIN);
            LCD_voidWriteChar('*');
            TIMER0_voidDelay_ms(100);
            BUZZER_voidOff(BUZZER_PORT, BUZZER_PIN);

            password[i] = read - '0';
            ++i;
        }
    }
}

void change_password(void){
    uint8_t eeprom_address = 0x20;
    uint8_t i = 0;
    while(i < 4){
        uint8_t read = KEYPAD_u8GetChar();
        if(read != 0){
            BUZZER_voidOn(BUZZER_PORT, BUZZER_PIN);
            LCD_voidWriteChar('*');
            TIMER0_voidDelay_ms(100);
            BUZZER_voidOff(BUZZER_PORT, BUZZER_PIN);
            EEPROM_voidWrite(eeprom_address, read - '0');
            ++eeprom_address, ++i;
        }
    }
}

void reset_password(void){
    uint8_t i;
    uint8_t eeprom_address = 0x20;
    for(i = 0; i < 4; ++i){
        EEPROM_voidWrite(eeprom_address, 0);
        eeprom_address++;
    }
}

uint8_t verify_password(void){
    uint8_t i;
    uint8_t eeprom_address = 0x20;
    for(i = 0; i < 4; ++i){
        if(password[i] != EEPROM_voidRead(eeprom_address)){
            return 1;
        }
        eeprom_address++;
    }
    return 0;
}
