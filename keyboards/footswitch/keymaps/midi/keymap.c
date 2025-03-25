#include QMK_KEYBOARD_H

extern MidiDevice midi_device;

enum custom_keycodes {
    MIDI_C4 = SAFE_RANGE,
    MIDI_D4,
    SUSTAIN,
    MIDI_CC80
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MIDI_C4:
            if (record->event.pressed) {
                midi_send_noteon(&midi_device, 0, 60, 127);  // Note on: C4
            } else {
                midi_send_noteoff(&midi_device, 0, 60, 127); // Note off: C4
            }
            return false;
        case MIDI_D4:
            if (record->event.pressed) {
                midi_send_noteon(&midi_device, 0, 62, 127);  // Note on: D4
            } else {
                midi_send_noteoff(&midi_device, 0, 62, 127); // Note off: D4
            }
            return false;
        case MIDI_CC80:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_OFF);
            }
            return true;
        case SUSTAIN:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 64, 127);  // Sustain ON
            } else {
                midi_send_cc(&midi_device, 0, 64, 0);    // Sustain OFF
            }
            return false;

    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MIDI_C4, MIDI_D4
    )
};

// // MUST HAVE BOOTMAGIC ENABLED
void early_init_user(void) {
    setPinInputHigh(F4);  // First footswitch pin
    setPinInputHigh(F5);  // Second footswitch pin

    // Wait a moment to stabilize pin state
    wait_ms(10);

    if (!readPin(F4) && !readPin(F5)) {
        // Both buttons held = jump to bootloader
        bootloader_jump();
    }
}
