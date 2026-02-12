#include "../core/platform_hal.h"
#include "button_driver.h"

ButtonDriver::ButtonDriver(uint8_t gpio)
    : pin(gpio),
      lastStableState(HIGH),
      lastReading(HIGH),
      lastDebounceTime(0) {}

void ButtonDriver::begin() {
    pinMode(pin, INPUT_PULLUP);
}

void ButtonDriver::update() {
    bool reading = digitalRead(pin);

    if (reading != lastReading) {
        lastDebounceTime = millis();
        lastReading = reading;
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        lastStableState = reading;
    }
}

bool ButtonDriver::isPressed() {
    return (lastStableState == LOW);
}

bool ButtonDriver::wasPressed() {
    static bool previousState = HIGH;
    bool currentState = lastStableState;
    bool event = false;

    if (previousState == HIGH && currentState == LOW) {
        event = true;
    }

    previousState = currentState;
    return event;
}

bool ButtonDriver::readRaw() {
    return digitalRead(pin);
}