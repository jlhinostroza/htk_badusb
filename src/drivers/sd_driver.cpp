#include "../core/platform_hal.h"
#include <SPI.h>
#include <SD.h>
#include "sd_driver.h"
#include "../config/pins.h"

static bool mounted = false;

bool SD_Driver_IsCardInserted()
{
    return digitalRead(PIN_CARD_DETECT) == LOW;
}

bool SD_Driver_Init()
{
    if (mounted) return true;
    if (!SD_Driver_IsCardInserted()) return false;

    SPI.begin(PIN_SD_SCK, PIN_SD_MISO, PIN_SD_MOSI, PIN_SD_CS);

    if (!SD.begin(PIN_SD_CS)) {
        return false;
    }

    mounted = true;
    return true;
}

void SD_Driver_Deinit()
{
    if (!mounted) return;

    SD.end();
    mounted = false;
}

// Check if SD card is mounted
bool SD_Driver_IsMounted()
{
    return mounted;
}
