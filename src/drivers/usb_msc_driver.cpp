#include "usb_msc_driver.h"

#include <USB.h>
#include <USBMSC.h>
#include <SD.h>

#include "../drivers/sd_driver.h"
#include "../utils/logger.h"

static USBMSC msc;

/* ================= MSC Callbacks ================= */

static int32_t msc_onWrite(uint32_t lba, uint32_t offset,
                           uint8_t *buffer, uint32_t bufsize) {

    uint32_t secSize = SD.sectorSize();
    if (!secSize) return -1;

    for (uint32_t i = 0; i < bufsize / secSize; i++) {
        if (!SD.writeRAW(buffer + (i * secSize), lba + i))
            return -1;
    }
    return bufsize;
}

static int32_t msc_onRead(uint32_t lba, uint32_t offset,
                          void *buffer, uint32_t bufsize) {

    uint32_t secSize = SD.sectorSize();
    if (!secSize) return -1;

    for (uint32_t i = 0; i < bufsize / secSize; i++) {
        if (!SD.readRAW((uint8_t *)buffer + (i * secSize), lba + i))
            return -1;
    }
    return bufsize;
}

static bool msc_onStartStop(uint8_t power_condition,
                            bool start, bool load_eject) {
    return true;
}

/* ================= DRIVER ================= */

USBMSCDriver::USBMSCDriver(SDDriver& sdRef) : sd(sdRef) {}

bool USBMSCDriver::begin() {

    if (active) return true;

    if (!sd.isMounted()) {
        Log_Error("MSC: SD no montada");
        return false;
    }

    Log_Info("MSC: iniciando");

    msc.vendorID("HYTEK");
    msc.productID("MSC_SD");
    msc.productRevision("1.0");

    msc.onRead(msc_onRead);
    msc.onWrite(msc_onWrite);
    msc.onStartStop(msc_onStartStop);
    msc.mediaPresent(true);

    msc.begin(SD.numSectors(), SD.sectorSize());

    USB.begin();

    active = true;
    Log_Info("MSC activo");
    return true;
}