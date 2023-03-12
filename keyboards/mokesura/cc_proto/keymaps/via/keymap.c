/* Copyright 2021 Chinatsu
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
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
      KC_A, KC_B, KC_C, KC_D,
      KC_E, KC_F, KC_G, KC_H,
      KC_1, KC_2, KC_3, KC_4, TO(_FN1),
      KC_6, KC_7, KC_8, KC_9, KC_0
    ),
  [_FN1] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_FN2),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
  [_FN2] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_FN3),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
  [_FN3] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_BASE),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// RGB Layer Setting
const rgblight_segment_t PROGMEM rgb_base_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
const rgblight_segment_t PROGMEM rgb_fn1_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM rgb_fn2_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_BLUE});
const rgblight_segment_t PROGMEM rgb_fn3_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_WHITE});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_base_layer,
    rgb_fn1_layer,
    rgb_fn2_layer,
    rgb_fn3_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN1 ));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FN2 ));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN3 ));
    return state;
}

// キーボード初期化後に呼ばれる関数
void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers; // レイヤーのLED情報を読み込み
}