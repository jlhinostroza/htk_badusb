#pragma once

void Log_Init();
void Log_Info(const char* fmt, ...);
void Log_Warn(const char* fmt, ...);
void Log_Error(const char* fmt, ...);