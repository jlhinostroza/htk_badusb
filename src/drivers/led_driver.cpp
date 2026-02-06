#include "../core/platform_hal.h"

//#include "../config/pins.h"
#include "led_driver.h"
/*
void ledStatusInit (int ledStatusPin) {
    pinMode(ledStatusPin, OUTPUT);
    digitalWrite(ledStatusPin, LOW); // Turn off LED initially
}

void ledStatusSet(bool state) {
    digitalWrite(PIN_LED_STATUS, state ? HIGH : LOW);
}   */

LedDriver::LedDriver(uint8_t gpio)
    : pin(gpio),
      strip(nullptr),
      curR(0), curG(0), curB(0),
      blinkInterval(0),
      lastToggle(0),
      blinkState(false) {}

void LedDriver::begin() {
    strip = new Adafruit_NeoPixel(1, pin, NEO_GRB + NEO_KHZ800);
    strip->begin();
    strip->show();  // Turn off
}

void LedDriver::setColor(uint8_t r, uint8_t g, uint8_t b) {
    curR = r;
    curG = g;
    curB = b;

    if (!strip) return;

    strip->setPixelColor(0, strip->Color(r, g, b));
    strip->show();
}

void LedDriver::off() {
    setColor(0, 0, 0);
}

void LedDriver::blink(uint16_t interval) {
    blinkInterval = interval;
}

void LedDriver::update() {
    if (blinkInterval == 0 || !strip) return;

    if (millis() - lastToggle >= blinkInterval) {
        lastToggle = millis();
        blinkState = !blinkState;

        if (blinkState)
            strip->setPixelColor(0, strip->Color(curR, curG, curB));
        else
            strip->setPixelColor(0, 0);

        strip->show();
    }
}