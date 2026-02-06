#include "../core/platform_hal.h"

#include "hardware_init.h"
#include "../config/pins.h"

#include "../drivers/led_driver.h"
#include "../drivers/button_driver.h"
#include "../drivers/sd_driver.h"

LedDriver statusLed(PIN_LED_STATUS);
ButtonDriver modeButton(PIN_MODE_BUTTON);
SDDriver sdCard(
    PIN_SD_SCK,
    PIN_SD_MISO,
    PIN_SD_MOSI,
    PIN_SD_CS,
    PIN_SD_CD
);

void Hardware_Init() {
    statusLed.begin();
    modeButton.begin();
    sdCard.begin();
}

void Hardware_Update() {
    statusLed.update();
    modeButton.update();
    sdCard.update();
}