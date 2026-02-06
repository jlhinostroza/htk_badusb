#pragma once

/*
void modeButtonInit(int modeButtonPin);
int modeButtonRead();
*/

class ButtonDriver {
private:
    uint8_t pin;
    bool lastStableState;
    bool lastReading;
    unsigned long lastDebounceTime;
    const unsigned long debounceDelay = 40; // ms

public:
    ButtonDriver(uint8_t gpio);

    void begin();
    void update();

    bool isPressed();        // nivel lógico actual (con debounce)
    bool wasPressed();       // flanco de bajada (evento)
};