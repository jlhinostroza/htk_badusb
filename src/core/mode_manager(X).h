#pragma once

class ModeManager {
public:
    ModeManager();

    /** Start the device as an Access Point */
    void ModeInit();
private:
};

extern ModeManager modeManager;