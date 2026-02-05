#include "../core/platform_hal.h"

#include "../config/pins.h"
#include "led_driver.h"

void ledStatusInit (int ledStatusPin) {
    pinMode(ledStatusPin, OUTPUT);
    digitalWrite(ledStatusPin, LOW); // Turn off LED initially
}

void ledStatusSet(bool state) {
    digitalWrite(PIN_LED_STATUS, state ? HIGH : LOW);
}   