#include "../core/platform_hal.h"
#include <SPI.h>
#include <SD.h>
#include "sd_driver.h"
#include "../config/pins.h"
#include "../utils/logger.h"


SDDriver::SDDriver(uint8_t sckPin, uint8_t misoPin, uint8_t mosiPin,
                   uint8_t csPin, uint8_t cdPin)
    : sck(sckPin),
      miso(misoPin),
      mosi(mosiPin),
      cs(csPin),
      cd(cdPin),
      mounted(false),
      lastCardState(false) {}

void SDDriver::begin() {
    pinMode(cd, INPUT_PULLUP);
    lastCardState = isCardInserted();
}

bool SDDriver::isCardInserted() {
    return digitalRead(cd) == LOW;
}

bool SDDriver::isMounted() {
    return mounted;
}

void SDDriver::initSPI() {
    SPI.begin(sck, miso, mosi, cs);
}

bool SDDriver::mount() {
    if (mounted) return true;
    if (!isCardInserted()) return false;

    initSPI();

    if (!SD.begin(cs)) {
        Log_Warn("SD mount failed");
        return false;
    }

    mounted = true;
    Log_Info("SD mounted");
    return true;
}

void SDDriver::unmount() {
    if (!mounted) return;

    SD.end();
    mounted = false;
    Log_Info("SD unmounted");
}

void SDDriver::update() {
    bool current = isCardInserted();

    if (current && !lastCardState) {
        mount();
    }

    if (!current && lastCardState) {
        unmount();
    }

    lastCardState = current;
}
/*
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
*/