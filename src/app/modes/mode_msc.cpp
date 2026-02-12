#include "mode_msc.h"

#include "../../core/hardware_init.h"
#include "../../drivers/sd_driver.h"
#include "../../drivers/usb_msc_driver.h"
#include "../../drivers/led_driver.h"
#include "../../utils/logger.h"

extern SDDriver sdCard;
extern USBMSCDriver usbMSC;
extern LedDriver statusLed;

void ModeMSC::begin() {

    Log_Info("[MODE] MSC");

    statusLed.setColor(0, 40, 0);
    statusLed.blink(200);

    if (!sdCard.mount()) {
        Log_Warn("MSC: No SD card");
        statusLed.setColor(40, 0, 0);
        return;
    }

    if (!usbMSC.begin()) {
        Log_Error("MSC init failed");
        statusLed.setColor(40, 0, 0);
        return;
    }

    Log_Info("MSC ready");
}

void ModeMSC::loop() {

    sdCard.update();     // detectar extracción
    statusLed.update();

    if (!sdCard.isMounted()) {
        statusLed.setColor(40, 0, 0);
    }
}
