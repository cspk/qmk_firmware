#include QMK_KEYBOARD_H

#define LAYER_BASIC 0
#define LAYER_FUNCTION 1
#define LAYER_PGUPDOWN 2
#define LAYER_NUMBERS 3
#define LAYER_ARROWS 4

#define _______ KC_TRNS

void td_fn1_fn2_finished(qk_tap_dance_state_t *state, void *user_data);
void td_fn1_fn2_reset(qk_tap_dance_state_t *state, void *user_data);

enum tap_dance {
	TD_FN1_FN2
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_FN1_FN2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_fn1_fn2_finished, td_fn1_fn2_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_BASIC] = LAYOUT_60_ansi(
		KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
		KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
		TD(TD_FN1_FN2), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,  KC_ENT, \
		KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT, \
		KC_LALT, KC_LGUI,KC_LCTL,   KC_SPC,   KC_RCTL,KC_RGUI, KC_APP ,KC_RALT
	),

	[LAYER_FUNCTION] = LAYOUT_60_ansi(
		KC_TILD,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_DEL, \
		_______,_______,_______,_______,_______,_______,_______,KC_MPRV,KC_MPLY,KC_MSTP,KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, \
		_______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______,KC_GRV ,_______, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,  KC_CAPS,  TG(LAYER_ARROWS),KC_PSCR,KC_INS,RESET
	),

	[LAYER_PGUPDOWN] = LAYOUT_60_ansi(
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,TG(LAYER_ARROWS),_______,_______,_______,_______
	),

	[LAYER_NUMBERS] = LAYOUT_60_ansi(
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,KC_1   ,KC_2   ,KC_3   ,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,KC_4   ,KC_5   ,KC_6   ,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,KC_7   ,KC_8   ,KC_9   ,_______,_______, \
		_______,_______,_______,KC_0,_______,_______,_______,_______
	),

	[LAYER_ARROWS] = LAYOUT_60_ansi(
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,_______,KC_UP  ,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT ,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,_______
	)
};

void td_fn1_fn2_finished(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		layer_on(LAYER_FUNCTION);
	}
	else if (state->count == 2) {
		layer_on(LAYER_PGUPDOWN);
	}
	else {
		layer_on(LAYER_NUMBERS);
	}
}

void td_fn1_fn2_reset(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		layer_off(LAYER_FUNCTION);
	}
	else if (state->count == 2) {
		layer_off(LAYER_PGUPDOWN);
	}
	else {
		layer_off(LAYER_NUMBERS);
	}
}
