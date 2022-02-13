/*
Copyright 2021 marby3

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

#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x4346
#define PRODUCT_ID   0x4346
#define DEVICE_VER   0x0001
#define MANUFACTURER marby3
#define PRODUCT      formy46

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { B1, B3, B2, B6 }
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4}
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2

/* Split hand configration */
#define SPLIT_HAND_MATRIX_GRID B5, B6
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT

/* RGB Matrix define */
#define RGB_DI_PIN D3
#ifdef RGB_MATRIX_ENABLE
    #define RGBLED_NUM 46
    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
    #define RGBLED_SPLIT { 23, 23 }
    #define RGB_MATRIX_SPLIT RGBLED_SPLIT
#endif
#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 46
#    define RGBLED_SPLIT { 23, 23 }
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 128 /* The maximum brightness level */
#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
//#    define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
//#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

/* Joystick define */
#define JOYSTICK_BUTTON_COUNT 0
#define JOYSTICK_AXES_COUNT 2

/* Rotary encoder define */
#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F7 }
#define ENCODER_RESOLUTION 4  //Default Setting

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Feature disable options */
//#define NO_DEBUG                //disable debugging
//#define NO_PRINT                //disable printing/debugging using hid_listen
//#define NO_ACTION_LAYER         //disable layers
//#define NO_ACTION_TAPPING       //disable tap dance and other tapping features
//#define NO_ACTION_ONESHOT       //disable one-shot modifiers
#define NO_ACTION_MACRO           //disable old-style macro handling using MACRO(), action_get_macro() (deprecated)
#define NO_ACTION_FUNCTION        //disable old-style function handling using fn_actions, action_function() (deprecated)


/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0

