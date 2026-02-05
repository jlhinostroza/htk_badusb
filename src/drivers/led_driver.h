#pragma once

/*
void ledStatusInit (int ledStatusPin);
void ledStatusSet(bool state);
*/

class LedDriver {
public:
    void begin(int r, int g, int b);
    void setColor(uint8_t r, uint8_t g, uint8_t b);
    void blink(uint16_t interval);
    void update();
};
