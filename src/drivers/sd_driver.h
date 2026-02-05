#pragma once


/*bool SD_Driver_Init();
void SD_Driver_Deinit();

bool SD_Driver_IsCardInserted();
bool SD_Driver_IsMounted();
*/

class SDDriver {
public:
    bool begin();
    bool isInserted();
};
