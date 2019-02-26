#include "nk5x5.h"

enum _LAYERS {
  _NUMPAD,
  _SECLAYERS,
  _BEAMNG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_NUMPAD] = {
    {KC_KP_MINUS, KC_KP_SLASH, KC_KP_ASTERISK, KC_CALCULATOR, TO(_SECLAYERS)},
    {KC_KP_7,     KC_KP_8,     KC_KP_9,        KC_NO,         KC_NUMLOCK},
    {KC_KP_4,     KC_KP_5,     KC_KP_6,        KC_NO,         KC_NO},
    {KC_KP_1,     KC_KP_2,     KC_KP_3,        KC_BSPACE,     KC_DELETE},
    {KC_KP_0,     KC_KP_PLUS,  KC_KP_DOT,      KC_KP_EQUAL,   KC_KP_ENTER}
  },

  [_SECLAYERS] = {
    {TO(_BEAMNG),  KC_NO, KC_NO, KC_NO, TO(_NUMPAD)},
    {KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO},
    {KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO},
    {KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO},
    {KC_NO,        KC_NO, KC_NO, KC_NO, RESET}
  },

  [_BEAMNG] = {
    {KC_Q,         KC_V,   LALT(KC_D),  KC_L,       TO(_NUMPAD)},
    {LCTL(KC_Q),   KC_W,   LALT(KC_S),  LSFT(KC_L), KC_HOME},
    {KC_A,         KC_S,   KC_D,        LALT(KC_L), LCTL(KC_HOME)},
    {LCTL(KC_TAB), KC_TAB, KC_C,        KC_F7,      KC_F8},
    {KC_H,         KC_P,   KC_J,        KC_R,       KC_INSERT}
  }

};

void matrix_scan_user(void) {
	uint8_t layer = biton32(layer_state);
	switch (layer) {
  case _NUMPAD:
    leds_off();
    led_on(RLED);
    break;
  case _SECLAYERS:
		leds_off();
		led_on(BLED);
  	break;
  case _BEAMNG:
		leds_off();
		led_on(GLED);
    break;
  default:
		leds_off();
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // No macros :(
  }
  return true;
}
