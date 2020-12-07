/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"

enum custom_keycodes {
    TILDE_DOLLAR = SAFE_RANGE,
    AMPERSAND_PERCENT,
    L_BRACKET_7,
    L_BRACE_5,
    R_BRACE_3,
    L_PAREN_1,
    EQL_9,
    STAR_0,
    R_PAREN_2,
    PLUS_4,
    R_BRACKET_6,
    BANG_8,
    POUND_TICK,
};

enum layers {
    BASE,  // default layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        TILDE_DOLLAR, AMPERSAND_PERCENT, L_BRACKET_7, L_BRACE_5, R_BRACE_3, L_PAREN_1, EQL_9, /* split */ STAR_0, R_PAREN_2, PLUS_4, R_BRACKET_6, BANG_8, POUND_TICK, KC_BSPACE,
        KC_TAB, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, /* split */ KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_AT, KC_ENT,
        KC_LCTRL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, /* split */ KC_H, KC_T, KC_N, KC_S, KC_MINUS, KC_BSLS, KC_ENT,
        KC_LSFT, KC_QUOTE, KC_Q, KC_J, KC_K, KC_X, /* split */ KC_B, KC_M, KC_W, KC_V, KC_Z, KC_LSFT,
        KC_LCTRL, KC_LOPT, KC_LCMD, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, /*thumb*/ KC_HYPR,/* split */ KC_MEH, /* thumb*/ KC__VOLUP, KC__VOLDOWN, KC_LCMD, KC_LOPT, RGB_TOG,
                                            KC_SPC,  KC_BSPC, KC_LGUI, /* split */ KC_LALT,  KC_TAB,  KC_ENT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case 1:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
