#include "../core/platform_hal.h"

#include "../config/pins.h"

#include "../drivers/led_driver.h"
#include "../drivers/button_driver.h"


void Hardware_Init() {
    ledStatusInit(PIN_LED_STATUS);
    modeButtonInit(PIN_MODE_BUTTON);
}