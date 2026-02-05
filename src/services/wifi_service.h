#pragma once

class WifiService {
public:
    void beginAP();
    void connectSTA();
    void update();

    bool isConnected();
    bool hasSavedCredentials();
};
