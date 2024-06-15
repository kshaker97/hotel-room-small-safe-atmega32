#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../UTILS/bit_math.h"
#include "../../UTILS/std_types.h"

#include "timer0_config.h"
#include "timer0_private.h"

void TIMER0_voidInit(void);
void TIMER0_voidDelay_ms(double ms);
void TIMER0_voidDelay_us(double us);

#endif /* TIMER0_INTERFACE_H */
