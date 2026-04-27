/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

enum custom_keycodes {
    SCRN_SHOT = SAFE_RANGE,
    SCRN_REC,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCRN_SHOT:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LGUI("4")));
            }
            break;

        case SCRN_REC:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LGUI("5")));
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
                 LGUI_T(KC_TAB), KC_Q,  KC_W,  KC_E,   KC_R,        KC_T,  LCTL(KC_GRV),    KC_DEL,   KC_Y,    KC_U,      KC_I,    KC_O,     KC_P,          KC_BSPC,
                 KC_LCTL,        KC_A,  KC_S,  KC_D,   KC_F,  LT(3,KC_G),       KC_HOME,    KC_END,   KC_H,    KC_J,      KC_K,    KC_L,  KC_SCLN,  LALT_T(KC_QUOT),
                 KC_LSFT,        KC_Z,  KC_X,  KC_C,   KC_V,        KC_B,     SCRN_SHOT,  SCRN_REC,   KC_N,    KC_M,   KC_COMM,  KC_DOT,  LT(3,KC_SLSH),    KC_ENT,
                 LALT_T(KC_ESC),   KC_LGUI,    MO(2),   LT(1,KC_SPC),                LT(1,KC_SPC),    MO(2),   KC_LGUI,   KC_LALT
                 ),

    [1] = LAYOUT(
                 LGUI_T(KC_TAB),  KC_EXLM,    KC_AT,    KC_HASH,    KC_DLR,    KC_PERC,    XXXXXXX, XXXXXXX, KC_CIRC,    KC_AMPR,      KC_ASTR,    KC_LPRN,    KC_RPRN,      KC_BSPC,
                 KC_LCTL,         _______,    _______,    KC_UP,    _______,    KC_LGUI,    XXXXXXX, XXXXXXX, KC_LEFT,    KC_DOWN,      KC_UP,    KC_RIGHT,    KC_LBRC, LALT_T(KC_QUOT),
                 KC_LSFT,         _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,  LGUI(KC_LALT),  XXXXXXX, XXXXXXX, _______,    _______,   KC_COMM,  KC_DOT,    KC_SLSH,          KC_ENT,
                 LALT_T(KC_ESC), KC_LGUI, MO(2),  LT(1,KC_SPC),                LT(1,KC_SPC), MO(2),   KC_LGUI, KC_LALT
                 ),

    [2] = LAYOUT(
                 LGUI_T(KC_TAB),  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,      KC_8,    KC_9,    KC_0,            KC_PLUS,
                 KC_LCTL,         KC_GRV,    KC_LBRC,    KC_LCBR,    KC_LPRN,    KC_MINUS,    XXXXXXX, XXXXXXX, KC_EQL,    KC_RPRN,      KC_RCBR,    KC_RBRC,    KC_BACKSLASH, LALT_T(KC_QUOT),
                 KC_LSFT,         KC_TILDE,    _______,    _______,    _______,  KC_UNDS,    XXXXXXX, XXXXXXX, KC_PLUS,    _______,   KC_COMM,  KC_DOT,    KC_PIPE,          KC_ENT,
                 LALT_T(KC_ESC), KC_LGUI, MO(2),  LT(1,KC_SPC),                LT(1,KC_SPC), MO(2),   KC_LGUI, KC_LALT
                 ),

    [3] = LAYOUT(
                 LGUI_T(KC_TAB),  KC_F1,    KC_F2,    KC_F3,    KC_F4,  KC_F5,    QK_BOOT, QK_BOOT, KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,
                 KC_LCTL,         KC_BRIU,    KC_BRID,    KC_MCTL,    KC_MCTL,    _______,    XXXXXXX, XXXXXXX,  _______,    KC_MPRV,    KC_MPLY,   KC_MNXT,    KC_MUTE,  KC_F12,
                 KC_LSFT,        _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    _______,    XXXXXXX, XXXXXXX, KC_N,    KC_M,   KC_COMM,  KC_DOT,    KC_SLSH,          KC_ENT,
                 LALT_T(KC_ESC), KC_LGUI, MO(2),  LT(1,KC_SPC),                LT(1,KC_SPC), MO(2),   KC_LGUI, KC_LALT
                 ),
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(2,KC_SPC):
        return QUICK_TAP_TERM - 100;
    case LT(1,KC_SPC):
        return QUICK_TAP_TERM - 100;
    default:
        return QUICK_TAP_TERM;
    }
}
