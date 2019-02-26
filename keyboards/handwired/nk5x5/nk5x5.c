#include "nk5x5.h"
#include "led.h"
#include "pincontrol.h"

void matrix_init_kb(void) {
	matrix_init_user();

	pinMode(RLED, PinDirectionOutput);
	pinMode(GLED, PinDirectionOutput);
	pinMode(BLED, PinDirectionOutput);

	led_on(RLED);
	_delay_ms(200);
	led_off(RLED);
	_delay_ms(200);
	led_on(GLED);
	_delay_ms(200);
	led_off(GLED);
	_delay_ms(200);
	led_on(BLED);
	_delay_ms(200);
	led_off(BLED);
};

void matrix_scan_kb(void) {
	matrix_scan_user();
};

void led_on(int pin) {
	digitalWrite(pin, PinLevelHigh);
}

void led_off(int pin) {
	digitalWrite(pin, PinLevelLow);
}

void leds_on(bool r, bool g, bool b) {
	if (r) { led_on(RLED); }
	if (g) { led_on(GLED); }
	if (b) { led_on(BLED); }
}

void leds_off(void) {
	led_off(RLED);
	led_off(GLED);
	led_off(BLED);
}
