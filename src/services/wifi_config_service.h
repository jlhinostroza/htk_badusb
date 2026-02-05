#pragma once

/*#include "../core/platform_hal.h"

bool WifiConfig_Save(const char* sta_ssid, const char* sta_pass);

bool WifiConfig_Load(String& sta_ssid, String& sta_pass);

bool WifiConfig_Exists();

void WifiConfig_Clear();
*/

class WebConfigService {
public:
    void begin(WebServerService& server);
    void update();
};
