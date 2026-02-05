#include "../core/platform_hal.h"

#include "wifi_manager.h"
#include <WiFi.h>
#include <cstdint>
#include "../config/config.h"
#include "../utils/logger.h"
#include "../services/web_server.h"


WifiManager::WifiManager() : staConnected(false) {}

void WifiManager::APInit(const char* ssid, const char* pass) {
    WiFi.softAP(ssid, pass);

    Log_Info(("WiFi AP started. SSID: " + String(ssid) +
          ", IP: " + getAPIP().toString()).c_str());

    // Start web server to serve the configuration page (index.html)
    WebServer_Start();
}
bool WifiManager::STAInit(const char* ssid, const char* pass, std::uint32_t timeout) {
    Log_Info(("WiFi STA attempting to connect to " + String(ssid ? ssid : "")).c_str());

    WiFi.begin(ssid, pass);

    std::uint32_t start = millis();

    while (WiFi.status() != WL_CONNECTED && millis() - start < timeout) {
        delay(500);
    }

    staConnected = (WiFi.status() == WL_CONNECTED);

    if (staConnected) {
        Log_Info(("WiFi STA connected to " + String(ssid ? ssid : "") + ", IP: " + getSTAIP().toString()).c_str());
    } else {
        Log_Warn(("WiFi STA failed to connect to " + String(ssid ? ssid : "")).c_str());
    }

    return staConnected;
}

IPAddress WifiManager::getAPIP() const {
    return WiFi.softAPIP();
}

IPAddress WifiManager::getSTAIP() const {
    return WiFi.localIP();
}

bool WifiManager::isConnected() const {
    return staConnected;
}