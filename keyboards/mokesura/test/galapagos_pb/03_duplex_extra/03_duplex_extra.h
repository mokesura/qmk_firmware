// Copyright 2022 Chinatsu Chiba (@mokesura)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
    L_D4_to_F5, L_C6_to_F5, \
    L_D4_to_F6, L_C6_to_F6, \
    L_F5_to_D4, L_F5_to_C6, L_Enc \
) { \
    { KC_NO,      KC_NO,      L_D4_to_F5, L_C6_to_F5 ,      KC_NO}, \
    { KC_NO,      KC_NO,      L_D4_to_F6, L_C6_to_F6 ,      KC_NO}, \
    { L_F5_to_D4, KC_NO,      KC_NO,      KC_NO     ,      KC_NO }, \
    { L_F5_to_C6, KC_NO,      KC_NO,      KC_NO     ,      KC_NO }, \
    {       KC_NO,     KC_NO,      KC_NO    ,      KC_NO ,L_Enc }, \
}
