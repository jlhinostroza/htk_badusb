#pragma once

class ModeMSC {
public:
    void begin();
    void update();
    void end();

private:
    USBMSCDriver usbMsc;
    SDDriver sd;
    LedDriver led;
};
