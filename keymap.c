/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
#    include "oled.c"
#endif

#include "raw_hid.h"
// #include "rgblight.h"

enum combos {
	JK_TAB
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[JK_TAB] = COMBO(jk_combo, KC_TAB)
};

enum custom_keycodes {
	DE_1 = SAFE_RANGE,
	DE_2,
	DE_3,
	DE_4,
	DE_5,
	DE_6,
	NVIM_BL,
	NVIM_BR,
};

#define DO_ESC LALT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       DO_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F2,    DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                      NVIM_BL,   KC_UP, NVIM_BR, XXXXXXX, KC_MPLY, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------|
        KC_F3,    DE_6, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, KC_MUTE, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RSFT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       DO_ESC, KC_EXLM,  KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  KC_GRV, KC_MINS,  KC_EQL, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------|--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+
      KC_LSFT, KC_TILD, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                       KC_DEL, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN,  KC_END, XXXXXXX, XXXXXXX,   TG(4),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

  // Games, just starcraft for now

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       DO_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TG(0),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(5),  KC_SPC,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [5] = LAYOUT_split_3x6_3(
  //|----------+----------+----------+----------+----------+----------|                    |--------+--------+--------+--------+--------+--------|
           KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|----------+----------+----------+----------+----------+----------|                    |--------+--------+--------+--------+--------+--------|
     LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),LSFT(KC_6),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|----------+----------+----------+----------+----------+----------|                    |--------+--------+--------+--------+--------+--------|
     LCTL(KC_1),LCTL(KC_2),LCTL(KC_3),LCTL(KC_4),LCTL(KC_5),LCTL(KC_6),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|----------+----------+----------+----------+----------+----------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                      KC_LGUI, _______,  KC_SPC,    XXXXXXX, _______, XXXXXXX
                                                  //`--------------------------'  `--------------------------'
  )

};

bool process_record_user (uint16_t keycode, keyrecord_t *record)
{
	if (record->event.pressed)
	{
		oled_timer = timer_read ();

		switch (keycode)
		{
			case DE_1:
				tap_code16 (LCMD (KC_1));
			break;
			case DE_2:
				tap_code16 (LCMD (KC_2));
			break;
			case DE_3:
				tap_code16 (LCMD (KC_3));
			break;
			case DE_4:
				tap_code16 (LCMD (KC_4));
			break;
			case DE_5:
				tap_code16 (LCMD (KC_5));
			break;
			case DE_6:
				tap_code16 (LCMD (KC_6));
			break;
			case NVIM_BL:
				tap_code16 (LALT (KC_LBRC));
			break;
			case NVIM_BR:
				tap_code16 (LALT (KC_RBRC));
			break;
			default:
			break;
		}
	}
	return true;
}

uint32_t layer_state_set_user (uint32_t state)
{
	switch (biton32(state)) {//biton32 returns highest significant bit
		case 0:
			rgblight_sethsv_noeeprom (5, 255, 155);
			break;
		case 1:
			rgblight_sethsv_noeeprom (185, 255, 155);
			break;
		case 2:
			rgblight_sethsv_noeeprom (131, 255, 155);
			break;
		case 3:
			rgblight_sethsv_noeeprom (45, 255, 155);
			break;
		case 4:
			rgblight_sethsv_noeeprom (210, 100, 48);
			break;
		case 5:
			rgblight_sethsv_noeeprom (39, 85, 91);
			break;
		default: //  for any other layers, or the default layer
			break;
	}
	return state;
}

enum {
	CMD_RGB,
};

void raw_hid_receive (uint8_t *data, uint8_t length)
{
	switch (data[0])
	{
		case CMD_RGB:
			data[0] = length;
			rgblight_sethsv_noeeprom (data[1], data[2], data[3]);
		break;
	}

	raw_hid_send (data, length);

}

void keyboard_post_init_user (void)
{
	// Set RGB to known state
	rgblight_enable_noeeprom ();
	rgblight_sethsv_noeeprom (5, 255, 155);
}

