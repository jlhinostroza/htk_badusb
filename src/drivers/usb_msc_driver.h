#pragma once

#include "../core/platform_hal.h"
#include <USBMSC.h>

class SDDriver;

class USBMSCDriver {
public:
    USBMSCDriver(SDDriver& sdRef);

    bool begin();

    bool isActive();

private:
    SDDriver& sd;    
    bool active = false;
};