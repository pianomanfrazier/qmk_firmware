#include QMK_KEYBOARD_H

// MUST HAVE BOOTMAGIC ENABLED
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