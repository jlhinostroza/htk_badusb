#pragma once

class ModeIdle {
public:
    void begin();
    void update();
    void end();

private:
    WifiService wifi;
    WebServerService webServer;
    WebConfigService webConfig;
};
