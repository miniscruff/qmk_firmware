/* Copyright 2020 Ronnie Smith
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "audio.h"
#include "song_list.h"

enum planck_layers {
  _PRIMARY,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_PRIMARY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_NO, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_NO,
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,  KC_SPC,  KC_SPC,  KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

[_RAISE] = LAYOUT_planck_grid(
    KC_GRV, KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,
    KC_NO,  SGUI(KC_1), SGUI(KC_2), SGUI(KC_3), SGUI(KC_4), SGUI(KC_5), KC_NO,   KC_NO,   KC_NO,   KC_MPLY, KC_MSTP, KC_MUTE,
    KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_TRNS,    KC_SPC,     KC_SPC,  KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

[_ADJUST] = LAYOUT_planck_grid(
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5,  KC_F6,  KC_NO,      KC_NO, KC_NO,       KC_PSCR, RESET,
    KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11, KC_F12, C(S(KC_R)), KC_NO, C(A(KC_F2)), KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,      KC_NO, KC_NO,       KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_SPC, KC_SPC, KC_TRNS,    KC_NO, KC_NO,       KC_NO, KC_NO
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}


void matrix_init_user(void) {
    startup_user();
}

void startup_user() {
    PLAY_SONG(STARTUP_SONG);
}
