#include "../core/platform_hal.h"
#include "button_driver.h"

#include "../config/pins.h"

void modeButtonInit(int modeButtonPin) {
    pinMode(modeButtonPin, INPUT_PULLUP);
}

int modeButtonRead() {
    return digitalRead(PIN_MODE_BUTTON);
}