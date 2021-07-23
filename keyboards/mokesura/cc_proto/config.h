/*
Copyright 2021 Chinatsu Chiba (azulee/mokesura)

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
#define VENDOR_ID    0x1209
#define PRODUCT_ID   0xCC00
#define DEVICE_VER   0x0001
#define MANUFACTURER Chinatsu Chiba (azulee/mokesura)
#define PRODUCT      CC Proto

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 5

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { B5,B4,E6,D7 }
#define MATRIX_COL_PINS { B6,B2,B3,B1,F7 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* RGB Light*/
#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
#    define RGBLED_NUM 1
#    define RGBLIGHT_LIMIT_VAL 60 /* The maximum brightness level */
#    define RGBLIGHT_LAYERS
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION