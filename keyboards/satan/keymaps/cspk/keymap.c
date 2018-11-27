#include QMK_KEYBOARD_H

#define SHIFT_MASK (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))
#define ALT_MASK (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))

#define LAYER_BASIC 0
#define LAYER_FUNCTION 1

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_BASIC] = LAYOUT_60_ansi(
		KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
		KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
		MO(LAYER_FUNCTION), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,  KC_ENT, \
		KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT, \
		KC_LCTL, KC_LGUI,KC_LALT,   KC_SPC,   KC_RALT,KC_RGUI, KC_APP ,KC_RCTL
	),

	[LAYER_FUNCTION] = LAYOUT_60_ansi(
		KC_TILD,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_DEL, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, BL_DEC, BL_INC,BL_TOGG, \
		_______,_______,_______,_______,_______,_______,KC_LEFT,F(0),F(1),KC_RGHT,_______,KC_GRV ,_______, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,  KC_CAPS,  _______,_______,_______,RESET
	),
};

enum function_id {
	PGDOWN,
	PGUP
};

const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_FUNCTION(PGDOWN),
	[1] = ACTION_FUNCTION(PGUP)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
	uint8_t shift_mask = 0;
	uint8_t alt_mask = 0;
	switch (id) {
	case PGDOWN:
		shift_mask = get_mods() & SHIFT_MASK;
		alt_mask = get_mods() & ALT_MASK;
		if (record->event.pressed) {
			if (shift_mask) {
				add_key(KC_PGDN);
				send_keyboard_report();
			}
			else if (alt_mask) {
				add_key(KC_END);
				send_keyboard_report();
			}
			else {
				add_key(KC_DOWN);
				send_keyboard_report();
			}
		}
		else {
			if (shift_mask) {
				del_key(KC_PGDN);
				send_keyboard_report();
			}
			else if (alt_mask) {
				del_key(KC_END);
				send_keyboard_report();
			}
			else {
				del_key(KC_DOWN);
				send_keyboard_report();
			}
		}
		break;

	case PGUP:
		shift_mask = get_mods() & SHIFT_MASK;
		alt_mask = get_mods() & ALT_MASK;
		if (record->event.pressed) {
			if (shift_mask) {
				add_key(KC_PGUP);
				send_keyboard_report();
			}
			else if (alt_mask) {
				add_key(KC_HOME);
				send_keyboard_report();
			}
			else {
				add_key(KC_UP);
				send_keyboard_report();
			}
		}
		else {
			if (shift_mask) {
				del_key(KC_PGUP);
				send_keyboard_report();
			}
			else if (alt_mask) {
				del_key(KC_HOME);
				send_keyboard_report();
			}
			else {
				del_key(KC_UP);
				send_keyboard_report();
			}
		}
		break;
	}
}
