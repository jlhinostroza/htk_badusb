#pragma once

enum SystemMode {
    MODE_IDLE,
    MODE_BADUSB,
    MODE_MSC,
    MODE_BLE_WAIT
};

class StateMachine {
public:
    void begin();
    void update();

private:
    SystemMode currentMode;

    SystemMode detectBootMode();
    void enterMode(SystemMode mode);

    ModeBadUSB modeBadusb;
    ModeMSC modeMsc;
    ModeIdle modeIdle;
    ModeBLEWait modeBle;
};
