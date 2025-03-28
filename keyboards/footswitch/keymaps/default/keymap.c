#include QMK_KEYBOARD_H

// Keymap definition
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        // LCTL(LALT(KC_J)),
        // LCTL(LALT(KC_T))
        KC_A,
        KC_B
    )
};
