#ifndef NK5X5_H
#define NK5X5_H

#include "quantum.h"

void matrix_init_user(void);
void matrix_scan_user(void);

void leds_off(void);
void led_off(int pin);
void leds_on(bool r, bool g, bool b);
void led_on(int pin);

#endif
