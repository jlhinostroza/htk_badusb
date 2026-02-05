#include "../core/platform_hal.h"

#include "../config/config.h"

#include "../core/wifi_manager.h"
#include "../services/wifi_config_service.h"
#include "../utils/logger.h"

#include <WiFi.h>

WifiManager wifiManager; 

void System_Init() {
    WiFi.mode(WIFI_AP_STA);

    wifiManager.APInit(AP_SSID, AP_PASSWORD);

    // Try to start STA only if credentials were previously stored in NVS
    String sta_ssid, sta_pass;
    if (WifiConfig_Load(sta_ssid, sta_pass)) {
        Log_Info(("Stored WiFi creds found. Attempting STA connect to " + sta_ssid).c_str());
        wifiManager.STAInit(sta_ssid.c_str(), sta_pass.c_str());
    } else {
        Log_Info("No stored WiFi credentials found; STA not started");
    }

}
