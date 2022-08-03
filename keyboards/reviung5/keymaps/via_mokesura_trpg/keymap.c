/* Copyright 2021 gtips
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LAYER1,
    _LAYER2,
    _LAYER3
};

enum custom_keycodes {
    KEY_2D6 = SAFE_RANGE
  };

#define L1_VD LT(_LAYER1, KC_VOLD)
#define L2_VU LT(_LAYER2, KC_VOLU)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KEY_2D6:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"2D6\n");
        } else {
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_reviung5(
        L1_VD,         KC_MPRV,       KC_MPLY,       KC_MNXT,       L2_VU
    ),
    [_LAYER1] = LAYOUT_reviung5(
        _______,       RGB_HUI,       RGB_MOD,       RGB_TOG,       KEY_2D6
    ),
    [_LAYER2] = LAYOUT_reviung5(
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______
    ),
    [_LAYER3] = LAYOUT_reviung5(
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX
    )
};
