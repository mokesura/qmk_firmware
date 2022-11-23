#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case USER00:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"1D4\n");
        } else {
        }
        break;
    case USER01:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"1D6\n");
        } else {
        }
        break;
    case USER02:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"1D8\n");
        } else {
        }
        break;
    case USER03:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"1D10\n");
        } else {
        }
        break;
    case USER04:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"1D12\n");
        } else {
        }
        break;
    case USER05:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"1D20\n");
        } else {
        }
        break;
    case USER06:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"2D6\n");
        } else {
        }
        break;
    case USER07:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"3D6\n");
        } else {
        }
        break;
    case USER08:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)"1D100\n");
        } else {
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬─────────┬───────┐
     * │ 1D6  │ Mouse Wheel Up   │ Ctrl+Shift+M │
     * ├───┼─────────┼───────┤
     * │ 2D6  │ Mouse Wheel Down │ Ctrl+Shift+M │
     * └───┴─────────┴───────┘
     */
    [0] = LAYOUT_ortho_2x3(
        USER01, KC_MS_WH_UP,   LCTL(LSFT(KC_M)),
        USER06, KC_MS_WH_DOWN, LCTL(LSFT(KC_D))
    ),
    [1] = LAYOUT_ortho_2x3(
        _______, _______, _______,
        _______, _______, _______
    ),
    [2] = LAYOUT_ortho_2x3(
        _______, _______, _______,
        _______, _______, _______
    ),
    [3] = LAYOUT_ortho_2x3(
        _______, _______, _______,
        _______, _______, _______
    )
};
