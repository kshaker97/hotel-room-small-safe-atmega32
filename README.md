<h1 align="center">
  Hotel Room Small Safe System Using ATmega32 Microcontroller
</h1>

<h4 align="center">A hotel room small safe system has been developed, designed to provide secure access to hotel guests, allowing them to unlock the safe with a password, change the password, reset it, or exit the system using specific key sequences, utilizing an ATmega32 microcontroller for control.</h4>

## Table of Contents:
- [Introduction](#introduction)
- [System Components](#system-components)
- [Hardware Connections](#hardware-connections)
- [System Operation](#system-operation)
- [Schematic](#schematic)

## Introduction:
This document outlines the design and implementation of a hotel room small safe system. The system is controlled by an ATmega32 microcontroller and features a 4x3 keypad, a 16x2 LCD, and a buzzer. The system provides secure access to hotel guests, allowing them to unlock the safe with a password, change the password, reset it, or exit the system using specific key sequences. The password is securely stored in the ATmega32's internal EEPROM starting from address 0x20 to 0x23.
## System Components:
1. **ATmega32 Microcontroller:**
   - The central processing unit of the system.
   - Controls all peripheral devices and manages user input and system output.
   - Contains internal EEPROM for storing the password.

2. **4x3 Keypad:**
   - Used for inputting passwords and commands.
   - Consists of 12 keys arranged in a 4-row by 3-column matrix.
   - Keys are: 0-9, #, and *.

3. **16x2 LCD Display:**
   - Provides visual feedback to the user.
   - Displays instructions, password prompts, and status messages.

4. **Buzzer:**
   - Provides auditory feedback for key presses and alerts.
   - Indicates successful or failed operations.

## System Operation:
1. **Initial Setup**
   - The system is initially locked and can be unlocked using the default password 0000.
     
2. **Unlocking the Safe**
   - The user enters the password 0000 using the keypad.
   - The system compares the input with the stored password retrieved from the EEPROM.
   - If the password matches, the safe is unlocked, and a success message is displayed on the LCD.
   - If the password does not match, an error message is displayed, and the user is prompted to try again.
     
3. **Changing the Password**
   - After unlocking the safe, the user can press the # key to initiate the password change process.
   - The LCD prompts the user to enter the new password.
   - The user inputs the new password using the keypad.
   - The new password is saved to the EEPROM, and a success message is displayed.
     
4. **Resetting the Password**
   - The user can reset the password to the default 0000 by entering ten consecutive zeros 0000000000.
   - The system detects this specific sequence and resets the password.
   - A confirmation message is displayed on the LCD, and the default password is stored in the EEPROM.
     
5. **Exiting the System**
   - The user can exit the system at any time by pressing the * key.
   - The system returns to the locked state, ready for the next user interaction.

## Hardware Connections:

| DEVICE    |     |      |     |     |     |     |     |     |     |     |     |
| ------- | ------------ | ------- | ------- |------- |------- |------- |------- |------- |------- |------- |------- |
|   KEYPAD  | R1    | R2     | R3    | R4    | C1    | C2    | C3    | -    | -    | -    | -    |
|   PIN  | PINB0    | PINB1     | PINB2    | PINB3    | PINB4    | PINB5    | PINB6    | -    | -    | -    | -    |
|   16x2 LCD  | RS    | RW     | EN    | D0    | D1    | D2    | D3    | D4    | D5    | D6    | D7    |
|   PIN  | PINC1    | PINC2     | PINC3    | -    | -    | -    | -    | PINC4    | PINC5    | PINC6    | PINC7    |
|   BUZZER  | +ve    | -ve     | -    | -    | -    | -    | -    | -    | -    | -    | -    |
|   PIN  | PIND0    | GND     | -    | -    | -    | -    | -    | -    | -    | -    | -    |

## Schematic
![a](https://github.com/kshaker97/hotel-room-small-safe-atmega32/assets/145481109/2fd6a829-e8ce-4490-b990-06db774654bd)

