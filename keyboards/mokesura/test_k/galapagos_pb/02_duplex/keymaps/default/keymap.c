// Copyright 2022 Chinatsu Chiba (@mokesura)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_1,    KC_2,
        KC_3,    KC_4,
        KC_5,    KC_6
    ),
    [_FN] = LAYOUT(
        _______, _______,
        _______, _______,
        _______, _______
    )
};
