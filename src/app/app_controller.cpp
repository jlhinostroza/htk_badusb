#include "app_controller.h"
#include "../core/hardware_init.h"
#include "../utils/logger.h"
#include "app_controller.h"
#include "modes/mode_msc.h"

void AppController::begin() {
    enterState(AppState::BOOT);
}

void AppController::update() {

    switch (currentState) {

        case AppState::BOOT:
            handleBoot();
            break;

        case AppState::MODE_SELECT_WINDOW:
            handleModeSelectWindow();
            break;

        case AppState::BADUSB_IDLE:
            handleBadUsbIdle();
            break;

        case AppState::BADUSB_ACTIVE:
            handleBadUsbActive();
            break;

        case AppState::MSC_MODE:
            handleMSCMode();
            break;

        case AppState::BLE_MODE:
            handleBLEMode();
            break;
    }
    
}

void AppController::enterState(AppState newState) {
    currentState = newState;
    stateStartTime = millis();

    if (newState == AppState::MODE_SELECT_WINDOW) {
        waitRelease = true;   // ← aquí sí significa “estoy esperando que suelte”
    }

    Log_Info("State changed → %d", (int)newState);
}


void AppController::handleBoot() {

    statusLed.setColor(50, 0, 0);

    // Esperar un ciclo para que el botón se estabilice
    if (millis() - stateStartTime < 50) {
        return;
    }

    if (modeButton.isPressed()) {
        enterState(AppState::MODE_SELECT_WINDOW);
    } else {
        enterState(AppState::MSC_MODE);
    }
}

void AppController::handleModeSelectWindow() {

    statusLed.blink(200);

    if (waitRelease) {
        if (!modeButton.isPressed()) {
            waitRelease = false;  // ya se soltó
        }
        return;  // NO procesar nada más
    }

    if (modeButton.wasPressed()) {
        enterState(AppState::BLE_MODE);
        return;
    }

    if (millis() - stateStartTime > MODE_SELECT_TIMEOUT) {
        enterState(AppState::BADUSB_IDLE);
    }
}


void AppController::handleBadUsbIdle() {

    statusLed.setColor(50, 0, 0); // rojo

    // Aquí luego irá:
    // wifiManager.startAP();
    // webServer.start();
    // mqtt.begin();

    if (sdCard.isMounted()) {
        enterState(AppState::BADUSB_ACTIVE);
    }
}

void AppController::handleBadUsbActive() {

    statusLed.blink(500); // actividad

    // Aquí luego irá:
    // ScriptEngine.execute("cmds.txt");

    if (!sdCard.isMounted()) {
        enterState(AppState::BADUSB_IDLE);
    }
}

void AppController::handleMSCMode() {

    static ModeMSC modeMSC;
    static bool started = false;

    if (!started) {
        modeMSC.begin();
        started = true;
    }

    modeMSC.loop();
}

void AppController::handleBLEMode() {

    statusLed.setColor(0, 50, 50); // cian

    // BLEService.start();
}
