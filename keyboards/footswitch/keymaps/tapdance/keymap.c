#include QMK_KEYBOARD_H

// Tap Dance Definitions
enum {
    TD_KEY1 = 0,
    TD_KEY2
};

// Tap Dance function
void td_key_1(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(LCTL(LALT(KC_J)));
    } else if (state->count == 2 && !state->pressed) {
        // DOUBLE TAP
        tap_code16(LCTL(LALT(KC_T)));
    }
}

void td_key_2(tap_dance_state_t *state, void *user_data) {
}


// Tap-dance actions
tap_dance_action_t tap_dance_actions[] = {
    // [TD_KEY1] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_B), // Tap for 'A', double-tap for 'B'
    [TD_KEY1] = ACTION_TAP_DANCE_FN(td_key_1), // Tap for 'A', double-tap for 'B'
    [TD_KEY2] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_D)  // Tap for 'C', double-tap for 'D'
};

// Keymap definition
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        // CA_J, // a single key without tapdance
        TD(TD_KEY1),
        TD(TD_KEY2)
        // KC_A,
        // KC_B
    )
};
