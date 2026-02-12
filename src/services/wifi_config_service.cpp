/*#include "wifi_config_service.h"
#include <Preferences.h>
#include "../utils/logger.h"

bool WifiConfig_Save(const char* sta_ssid, const char* sta_pass) {
    Preferences prefs;
    prefs.begin("wifi", false); // read/write
    prefs.putString("ssid", sta_ssid ? sta_ssid : "");
    prefs.putString("pass", sta_pass ? sta_pass : "");
    prefs.end();
    Log_Info("WiFi credentials saved in NVS");
    return true;
}

bool WifiConfig_Load(String& sta_ssid, String& sta_pass) {
    Preferences prefs;
    prefs.begin("wifi", true); // read-only
    sta_ssid = prefs.getString("ssid", "");
    sta_pass = prefs.getString("pass", "");
    prefs.end();
    return (sta_ssid.length() > 0 && sta_pass.length() > 0);
}

bool WifiConfig_Exists() {
    String sta_ssid, sta_pass;
    return WifiConfig_Load(sta_ssid, sta_pass);
}

void WifiConfig_Clear() {
    Preferences prefs;
    prefs.begin("wifi", false);
    prefs.clear();
    prefs.end();
    Log_Info("WiFi credentials cleared from NVS");
} 
*/