#include "logger.h"
#include <Arduino.h>
#include <stdarg.h>

static void logPrint(const char* level, const char* fmt, va_list args) {
    char buffer[128];

    vsnprintf(buffer, sizeof(buffer), fmt, args);

    Serial.print("[");
    Serial.print(level);
    Serial.print("] ");
    Serial.println(buffer);
}

void Log_Init() {
    Serial.begin(115200);
}

void Log_Info(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logPrint("INFO", fmt, args);
    va_end(args);
}

void Log_Warn(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logPrint("WARN", fmt, args);
    va_end(args);
}

void Log_Error(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    logPrint("ERR", fmt, args);
    va_end(args);
}
