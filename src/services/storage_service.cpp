/*#include "storage_service.h"

#include "../drivers/sd_driver.h"
#include "../utils/logger.h"
#include "../config/pins.h"
#include <SD.h>

static bool storageReady = false;
volatile bool sdEventFlag = false;

void IRAM_ATTR sdDetectISR()
{
    sdEventFlag = true;
}

void StorageService_Init()
{
    pinMode(PIN_CARD_DETECT, INPUT_PULLUP);
    attachInterrupt(PIN_CARD_DETECT, sdDetectISR, CHANGE);

    if (SD_Driver_IsCardInserted())
    {
        storageReady = SD_Driver_Init();
        if (storageReady)
            Log_Info("SD mounted at boot");
    }
}

void StorageService_Update()
{
    if (!sdEventFlag)
        return;
    sdEventFlag = false;

    bool inserted = SD_Driver_IsCardInserted();

    if (inserted && !storageReady)
    {
        storageReady = SD_Driver_Init();
        if (storageReady)
            Log_Info("SD mounted");
    }
    else if (!inserted && storageReady)
    {
        SD_Driver_Deinit();
        storageReady = false;
        Log_Warn("SD unmounted");
    }
}

//Verify if storage is ready
bool StorageService_Available()
{
    return storageReady;
}*/