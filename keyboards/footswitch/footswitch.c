#include QMK_KEYBOARD_H

// MUST HAVE BOOTMAGIC ENABLED
void early_init_user(void) {
    setPinInputHigh(F4);  // First footswitch pin, A3 -> Tip + Sleeve
    setPinInputHigh(F5);  // Second footswitch pin, A2 -> Ring + Sleeve

    // Wait a moment to stabilize pin state
    wait_ms(10);

    // Both buttons held = jump to bootloader
    if (!readPin(F4) && !readPin(F5)) {
        bootloader_jump();
    }
}
