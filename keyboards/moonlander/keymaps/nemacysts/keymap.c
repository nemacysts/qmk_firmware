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
    AT_CARET
};

enum layers {
    BASE,  // default layer
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        TILDE_DOLLAR, AMPERSAND_PERCENT, L_BRACKET_7, L_BRACE_5, R_BRACE_3, L_PAREN_1, EQL_9, /* split */ STAR_0, R_PAREN_2, PLUS_4, R_BRACKET_6, BANG_8, POUND_TICK, KC_BSPACE,
        KC_TAB, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, /* split */ KC_G, KC_C, KC_R, KC_L, KC_SLSH, AT_CARET, KC_ENT,
        KC_LCTRL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, /* split */ KC_H, KC_T, KC_N, KC_S, KC_MINUS, KC_BSLS, KC_ENT,
        KC_LSFT, KC_QUOTE, KC_Q, KC_J, KC_K, KC_X, /* split */ KC_B, KC_M, KC_W, KC_V, KC_Z, KC_LSFT,
        KC_LCTRL, KC_LOPT, KC_LCMD, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, /*thumb*/ KC_HYPR,/* split */ KC_MEH, /* thumb*/ KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_LCMD, KC_LOPT, RGB_TOG,
                                            KC_SPC,  KC_BSPC, KC_LGUI, /* split */ KC_LALT,  KC_TAB,  KC_ENT
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        uint8_t current_mods = get_mods();
        bool shifted = current_mods & MOD_MASK_SHIFT;
        switch (keycode) {
            case TILDE_DOLLAR:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("~");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("$");
                }
                return false;
            case AMPERSAND_PERCENT:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("%");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("&");
                }
                return false;
            case L_BRACKET_7:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("7");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("[");
                }
                return false;
            case L_BRACE_5:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("5");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("{");
                }
                return false;
            case R_BRACE_3:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("3");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("}");
                }
                return false;
            case L_PAREN_1:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("3");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("(");
                }
                return false;
            case EQL_9:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("9");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("=");
                }
                return false;
            case STAR_0:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("0");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("*");
                }
                return false;
            case R_PAREN_2:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("2");
                    set_mods(current_mods);
                } else {
                    SEND_STRING(")");
                }
                return false;
            case PLUS_4:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("4");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("+");
                }
                return false;
            case R_BRACKET_6:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("6");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("]");
                }
                return false;
            case BANG_8:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("8");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("!");
                }
                return false;
            case POUND_TICK:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("`");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("#");
                }
                return false;
            case AT_CARET:
                if (shifted) {
                    clear_mods();
                    SEND_STRING("^");
                    set_mods(current_mods);
                } else {
                    SEND_STRING("@");
                }
                return false;
        }
    }
    return true;
}
