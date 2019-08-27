#include QMK_KEYBOARD_H

enum layers {
    _DEFAULT,
    _LAYER1
};

enum custom_keycodes {
  WS_1 = SAFE_RANGE,
  WS_2,
  WS_3,
  WS_4,
  WS_5,
  WS_6,
  WS_7,
  WS_8,
  WS_9,
  WS_10,
  WS_11,
  WS_12,
  FS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_ortho_4x4(
        WS_1, WS_2,   WS_3,   WS_4,
        WS_5, WS_6,   WS_7,   WS_8,
        WS_9, WS_10,  WS_11,   WS_12,
        KC_LSHIFT, KC_LOCK, MO(_LAYER1), FS
    ),
    [_LAYER1]=LAYOUT_ortho_4x4(
        _______, KC_UP, _______, _______,
        KC_LEFT, KC_DOWN, KC_RIGHT, _______,
        _______, _______, _______, _______,
        _______, RESET, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WS_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("1"));
                return false;
            }
            break;
        case WS_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("2"));
                return false;
            }
            break;
        case WS_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("3"));
                return false;
            }
            break;
        case WS_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("4"));
                return false;
            }
            break;
        case WS_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("5"));
                return false;
            }
            break;
        case WS_6:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("6"));
                return false;
            }
            break;
        case WS_7:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("7"));
                return false;
            }
            break;
        case WS_8:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("8"));
                return false;
            }
            break;
        case WS_9:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("9"));
                return false;
            }
            break;
        case WS_10:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("0"));
                return false;
            }
            break;
        case FS:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("f"));
                return false;
            }
            break;
        /* case WS_11: */
        /*     if (record->event.pressed) { */
        /*         SEND_STRING(SS_LGUI("11")); */
        /*         return false; */
        /*     } */
        /*     break; */
        /* case WS_12: */
        /*     if (record->event.pressed) { */
        /*         SEND_STRING(SS_LGUI("12")); */
        /*         return false; */
        /*     } */
        /*     break; */

    }
    return true;
}

void led_set_user(uint8_t usb_led) {

  #ifndef CONVERT_TO_PROTON_C
  /* Map RXLED to USB_LED_NUM_LOCK */
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		DDRB |= (1 << 0); PORTB &= ~(1 << 0);
	} else {
		DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
	}

  /* Map TXLED to USB_LED_CAPS_LOCK */
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRD |= (1 << 5); PORTD &= ~(1 << 5);
	} else {
		DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
	}
  #endif
}
