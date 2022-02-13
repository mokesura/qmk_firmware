/* Copyright 2021 marby3
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
#include "joystick.h"
#include "analog.h"
#include "pointing_device.h"
#include <stdio.h>

/* layer change */
#define FUNC_1    MO(_FN1)
#define FUNC_2    MO(_FN2)
bool re_function = false;

/* short cut */
#define UNDO    LCTL(KC_Z)
#define REDO    C_S_T(KC_Z)
#define CUT     LCTL(KC_X)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
#define SAVE    LCTL(KC_S)

enum layer_names {
    _BASE = 0,
    _GAMER_MODE,
    _CREATOR_MODE,
    _FN1,
    _FN2
};

enum custom_keycodes {
    JS_MODE = SAFE_RANGE,
    RE_MODE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Mode */
    [_BASE] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                            KC_H,    KC_J,    KC_K,    KC_L,    KC_LBRC, KC_RBRC,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_MINS,                       KC_EQL,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, FUNC_2,
                                                        KC_LALT, JS_MODE, KC_SPC,  KC_SPC,      RE_MODE, KC_ENT, FUNC_1,  KC_LGUI
    ),
    /* Game Mode */
    [_GAMER_MODE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______,                       _______,     _______, _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______,     _______, _______, _______,     _______
    ),
    /* Creator Mode */
    [_CREATOR_MODE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,             _______,                       _______,     _______, _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______,     _______, _______, _______,     _______
    ),
    /* Function Mode */
    [_FN1] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NUBS,
        _______, _______, _______, _______, _______, _______,                                                         _______, RGB_TOG, RGB_MOD,RGB_RMOD, KC_SCLN, KC_QUOT,
        _______, _______, _______, _______, _______, KC_GRV,              _______,                       _______,     _______, _______, _______, _______, _______, _______,
                                                        KC_LALT, _______, _______, _______,     _______, _______, FUNC_1,      KC_APP
    ),
    [_FN2] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                                           RGB_HUI, RGB_HUD, _______, KC_PSCR, KC_SCRL, KC_PAUS,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                                                          RGB_SAI, RGB_SAD, _______, KC_HOME, KC_PGUP, KC_INS,
        _______, _______, _______, _______, _______, _______,             _______,                       KC_UP,       RGB_VAI, RGB_VAD, _______, KC_END,  KC_PGDN, FUNC_2,
                                                        _______, _______, _______, _______,     KC_LEFT, KC_DOWN, KC_RGHT,     KC_DEL
    )
};


/* joystick config */
#ifdef JOYSTICK_ENABLE
// Change this
char arrow_keys[4] = {KC_UP, KC_LEFT, KC_DOWN, KC_RIGHT}; // up, left, down, right
//char arrow_keys[4] = {KC_W, KC_A, KC_S, KC_D}; // W, A, S, D
static int joystickThreshold = 6; // Value to prevent joystick drift
static int joystickResolution = 32; // Decide the movement speed of the joystick
// Don't chnage this
static uint8_t joystickMode = 0;
static uint8_t joystick_modes = 3; // amount of modes
static int actuation = 255; // actuation point for arrows (0-511)
bool arrows[4];

joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};

void joystick_task(){
	switch (joystickMode) {
	case 0: // gamepad
		joystick_status.axes[0] = 128 - analogReadPin(F4)/4;
		joystick_status.axes[1] = analogReadPin(F5)/4 - 128;
		joystick_status.status |= JS_UPDATED;
        send_joystick_packet(&joystick_status);
		break;
    case 1: // arrows
        if (!arrows[0] && analogReadPin(F5) - 512 > actuation){
            arrows[0] = true;
            register_code16(arrow_keys[2]);
        }
        else if (arrows[0] &&  analogReadPin(F5) - 512 < actuation){
            arrows[0] = false;
            unregister_code16(arrow_keys[2]);
        }
        if (!arrows[1] && analogReadPin(F5) - 512 < -actuation){
            arrows[1] = true;
            register_code16(arrow_keys[0]);
        }
        else if (arrows[1] && analogReadPin(F5) - 512 > -actuation){
            arrows[1] = false;
            unregister_code16(arrow_keys[0]);
        }
        if (!arrows[2] && analogReadPin(F4) - 512 > actuation){
            arrows[2] = true;
            register_code16(arrow_keys[1]);
        }
        else if (arrows[2] &&  analogReadPin(F4) - 512 < actuation){
            arrows[2] = false;
            unregister_code16(arrow_keys[1]);
        }
        if (!arrows[3] && analogReadPin(F4) - 512 < -actuation){
            arrows[3] = true;
            register_code16(arrow_keys[3]);
        }
        else if (arrows[3] && analogReadPin(F4) - 512 > -actuation){
            arrows[3] = false;
            unregister_code16(arrow_keys[3]);
        }
        break;
    case 2: // mouse
        ;
        report_mouse_t currentReport = pointing_device_get_report();
        currentReport.x = (512 - analogReadPin(F4)) / joystickResolution;
        currentReport.y = (analogReadPin(F5) - 512) / joystickResolution;
        if (currentReport.x < joystickThreshold && currentReport.x > -joystickThreshold){
            currentReport.x = 0;
        }
        if (currentReport.y < joystickThreshold && currentReport.y > -joystickThreshold){
            currentReport.y = 0;
        }
        pointing_device_set_report(currentReport);
        pointing_device_send();
        break;
	}
};
#endif


/* rotary encorder config */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state)){
        case _BASE:
            if (re_function){
                if (clockwise) {
                    layer_move(_GAMER_MODE);
                } else {
                    layer_move(_CREATOR_MODE);
                }
            } else {
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
            }
            break;
        case _GAMER_MODE:
            if (re_function){
                if (clockwise) {
                    layer_move(_CREATOR_MODE);
                } else {
                    layer_move(_BASE);
                }
            } else {
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
            }
            break;
        case _CREATOR_MODE:
            if (re_function){
                if (clockwise) {
                    layer_move(_BASE);
                } else {
                    layer_move(_GAMER_MODE);
                }
            } else {
                if (clockwise) {
                    //Redo
                    tap_code16(C(S(KC_Z)));
                } else {
                    //Undo
                    tap_code16(C(KC_Z));
                }
            }
            break;
        case _FN1:
            if (re_function){
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else {
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
            }
            break;
        case _FN2:
            if (re_function){
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else {
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
            }
            break;
    }
    return false;
};
#endif


/* OLED config */
//This configuration is for a 128x32 display.
#ifdef OLED_ENABLE
void render_logo(void) {
    static const char PROGMEM logo[] = {
	0x8c, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8c, 0x98, 0x8c, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8c, 0x98,
	0x8c, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8c, 0x98, 0x8c, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8c, 0x98,
	0x00, 0x78, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xfc, 0xf8, 0xc0, 0xf8, 0xf8, 0xc0, 0xc0, 0xc0, 0xc0,
	0xc0, 0x00, 0x80, 0xe0, 0xf8, 0xfc, 0x9c, 0x0e, 0x06, 0x06, 0xf6, 0xf6, 0x06, 0x06, 0xf6, 0xf6,
	0x06, 0x06, 0xf6, 0xf6, 0x06, 0x36, 0x76, 0x66, 0x86, 0x06, 0x06, 0xf6, 0xf6, 0x06, 0x86, 0xe6,
	0x66, 0x36, 0x36, 0x36, 0x36, 0x66, 0xe6, 0x86, 0x06, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x98,
	0x8c, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8c, 0x98, 0x8c, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8c, 0x98,
	0x8c, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8c, 0x98, 0x8c, 0x86, 0x86, 0x86, 0x86, 0x86, 0x8c, 0x98,
	0x01, 0x11, 0x11, 0x6d, 0x11, 0x11, 0x01, 0x01, 0x01, 0x11, 0x11, 0x6d, 0x11, 0x11, 0x01, 0x01,
	0x01, 0x11, 0x11, 0x6d, 0x11, 0x11, 0x01, 0x01, 0x01, 0x11, 0x11, 0x6d, 0x11, 0x11, 0x01, 0x01,
	0x00, 0x00, 0x38, 0x38, 0x38, 0x38, 0x38, 0x1f, 0x0f, 0x00, 0xff, 0xff, 0xe0, 0x78, 0x3e, 0x27,
	0x31, 0x3c, 0x3f, 0x0f, 0x83, 0x8f, 0xbf, 0x3c, 0x38, 0x20, 0x0f, 0x3f, 0x30, 0x30, 0x3f, 0x3f,
	0x30, 0xb0, 0x3f, 0x8f, 0x00, 0x0e, 0x1f, 0xbf, 0xb1, 0xb1, 0x30, 0x3f, 0x3f, 0x80, 0x87, 0x9f,
	0x98, 0xb0, 0xb0, 0xb0, 0xb0, 0x98, 0x9f, 0x87, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01,
	0x01, 0x11, 0x11, 0x6d, 0x11, 0x11, 0x01, 0x01, 0x01, 0x11, 0x11, 0x6d, 0x11, 0x11, 0x01, 0x01,
	0x01, 0x11, 0x11, 0x6d, 0x11, 0x11, 0x01, 0x01, 0x01, 0x11, 0x11, 0x6d, 0x11, 0x11, 0x01, 0x01,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x00, 0x0a, 0x0a, 0x0a, 0x15, 0x15, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00,
	0x02, 0x07, 0x03, 0x02, 0x00, 0x1c, 0x13, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x20, 0x70, 0x78, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x3e, 0x3f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    oled_write_raw_P(logo, sizeof(logo));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()){
    return OLED_ROTATION_270;
    }
    return rotation;  // flips the display 180 degrees if offhand
}

void render_layer_state(void) {
    oled_write_P(PSTR("Mode:\n"), false);
    oled_write_P(PSTR("Main\n"), get_highest_layer(layer_state) == _BASE);
    oled_write_P(PSTR("Game\n"), layer_state_is(_GAMER_MODE));
    oled_write_P(PSTR("Crea\n"), layer_state_is(_CREATOR_MODE));
    oled_write_P(PSTR("Fn 1\n"), layer_state_is(_FN1));
    oled_write_P(PSTR("Fn 2\n"), layer_state_is(_FN2));
/*
    #ifdef RGB_MATRIX_ENABLE
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("LED:"), false);
        oled_write_ln_P(PSTR(""), false);
        char     rgblight_mode[1];
        char     rgblight_hue[1];
        char     rgblight_sat[1];
        char     rgblight_val[1];
        uint16_t rgb_mode =  rgblight_get_mode();
        uint16_t rgb_hue  =  rgblight_get_hue();
        uint16_t rgb_sat  =  rgblight_get_sat();
        uint16_t rgb_val  =  rgblight_get_val();
        rgblight_mode[0]  =  rgb_mode;
        rgblight_hue[0]   =  rgb_hue;
        rgblight_sat[0]   =  rgb_sat;
        rgblight_val[0]   =  rgb_val;
        oled_write_P(PSTR("M:"), false);
        oled_write(rgblight_mode, false);
        oled_write_P(PSTR("H:"), false);
        oled_write(rgblight_hue, false);
        oled_write_P(PSTR("S:"), false);
        oled_write(rgblight_sat, false);
        oled_write_P(PSTR("V:"), false);
        oled_write(rgblight_val, false);
    #endif
    */
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
    } else {
        render_logo();
        oled_scroll_right();  // Turns on scrolling
    }
    return false;
}
#endif


/* keycord */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
    case JS_MODE:
        if (record->event.pressed) {
            joystickMode++;
            if (joystickMode == joystick_modes){
                joystickMode = 0;
            }
        }
        return false; // Skip all further processing of this key
    case RE_MODE:
        if (record->event.pressed) {
            re_function = !re_function;
    }
        return true; // Skip all further processing of this key
    default:
        return true; // Process all other keycodes normally
    }
}
