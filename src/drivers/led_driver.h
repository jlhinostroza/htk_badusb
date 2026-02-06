#pragma once

#include <Adafruit_NeoPixel.h>

/*
void ledStatusInit (int ledStatusPin);
void ledStatusSet(bool state);
*/

class LedDriver {
private:
    uint8_t pin;
    Adafruit_NeoPixel* strip;

    uint8_t curR, curG, curB;

    uint16_t blinkInterval;
    unsigned long lastToggle;
    bool blinkState;

public:
    LedDriver(uint8_t gpio);

    void begin();
    void setColor(uint8_t r, uint8_t g, uint8_t b);
    void off();

    void blink(uint16_t interval); // ms (0 = sin parpadeo)
    void update();
};