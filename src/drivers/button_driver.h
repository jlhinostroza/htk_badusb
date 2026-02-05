#pragma once

/*
void modeButtonInit(int modeButtonPin);
int modeButtonRead();
*/

class ButtonDriver {
public:
    void begin(int pin);
    void update();
    bool isPressed();
    bool isHeld(uint32_t ms);
};
