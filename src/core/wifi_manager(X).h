/*#pragma once

#include <cstdint>

class IPAddress;

class WifiManager {
public:
    WifiManager();


    void APInit(const char* ssid, const char* pass);


    [[nodiscard]] bool STAInit(const char* ssid, const char* pass, std::uint32_t timeout = 10000);

    IPAddress getAPIP() const;
    IPAddress getSTAIP() const;
    bool isConnected() const;

private:
    bool staConnected = false; // initialized inline
};

extern WifiManager wifiManager;*/