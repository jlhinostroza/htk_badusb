#include "../core/platform_hal.h"
#include "logger.h"

void Log_Init()
{
    Serial.begin(115200);
}

void Log_Info(const char *msg)
{
    Serial.print("[INFO] ");
    Serial.println(msg);
}

void Log_Warn(const char *msg)
{
    Serial.print("[WARN] ");
    Serial.println(msg);
}

void Log_Error(const char *msg)
{
    Serial.print("[ERROR] ");
    Serial.println(msg);
}
