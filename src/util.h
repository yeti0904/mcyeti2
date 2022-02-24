#pragma once

struct tm* Util_GetTime();
void       Util_Log(const char* format, ...);
void       Util_LogWithPrefix(char* prefix, char* format, ...);
void       Util_Exit(int code);