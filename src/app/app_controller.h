#pragma once

#define MODE_SELECT_TIMEOUT 5000
class AppController {
public:
    void begin();
    void update();

private:
    enum class AppState {
        BOOT,
        MODE_SELECT_WINDOW,
        BADUSB_IDLE,
        BADUSB_ACTIVE,
        MSC_MODE,
        BLE_MODE
    };

    AppState currentState;
    unsigned long stateStartTime;

    // === Métodos de estados ===
    void enterState(AppState newState);

    void handleBoot();
    void handleModeSelectWindow();
    void handleBadUsbIdle();
    void handleBadUsbActive();
    void handleMSCMode();
    void handleBLEMode();

    bool modeButtonHeldAtBoot();


};