#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QK_KB_0:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LNG2)"1D6\n");
        } else {
        }
        break;
    case QK_KB_1:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LNG2)"1D6\n");
        } else {
        }
        break;
    case QK_KB_2:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LNG2)"1D8\n");
        } else {
        }
        break;
    case QK_KB_3:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LNG2)"1D10\n");
        } else {
        }
        break;
    case QK_KB_4:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LNG2)"1D12\n");
        } else {
        }
        break;
    case QK_KB_5:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LNG2)"1D20\n");
        } else {
        }
        break;
    case QK_KB_6:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LNG2)"2D6\n");
        } else {
        }
        break;
    case QK_KB_7:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LNG2)"3D6\n");
        } else {
        }
        break;
    case QK_KB_8:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LNG2)"1D100\n");
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
        QK_KB_1, KC_MS_WH_UP,   LCTL(LSFT(KC_M)),
        QK_KB_6, KC_MS_WH_DOWN, LCTL(LSFT(KC_D))
    ),
    [1] = LAYOUT_ortho_2x3(
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [2] = LAYOUT_ortho_2x3(
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [3] = LAYOUT_ortho_2x3(
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    )
};
