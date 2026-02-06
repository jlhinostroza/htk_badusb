#include "../core/platform_hal.h"
#include "../core/hardware_init.h"

#include "../utils/logger.h"

void System_Init() {

    Log_Init();
    delay(200);
    
    Log_Info("System booting...");

    Hardware_Init();

    statusLed.setColor(0, 0, 40); //Color: Blue
   
    Log_Info("Hardware init complete");
    /*
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
*/
}
