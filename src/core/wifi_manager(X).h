#pragma once

#include <cstdint>

class IPAddress;

/** Simple WiFi manager wrapper */
class WifiManager {
public:
    WifiManager();

    /** Start the device as an Access Point */
    void APInit(const char* ssid, const char* pass);

    /** Attempt to connect in Station mode. Returns true on success. */
    [[nodiscard]] bool STAInit(const char* ssid, const char* pass, std::uint32_t timeout = 10000);

    IPAddress getAPIP() const;
    IPAddress getSTAIP() const;
    bool isConnected() const;

private:
    bool staConnected = false; // initialized inline
};

extern WifiManager wifiManager;