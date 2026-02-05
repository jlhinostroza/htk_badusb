#pragma once

class USBMSCDriver {
public:
    bool begin();
    void update();
    void setStorageCallbacks();
};
