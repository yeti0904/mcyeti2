#include "_components.h"

struct tm* Util_GetTime() {
	time_t t = time(NULL);
	return localtime(&t);
}

void Util_Log(char* format, ...) {
	va_list args;
	va_start(args, format);

	char* print;
	vasprintf(&print, format, args);

	va_end(args);

	struct tm* time = Util_GetTime();

	printf("[%02d:%02d:%02d] %s\n", time->tm_hour, time->tm_min, time->tm_sec, print);

	free(print);
}

void Util_LogWithPrefix(char* prefix, char* format, ...) {
	va_list args;
	va_start(args, format);

	char* print;
	vasprintf(&print, format, args);

	va_end(args);

	struct tm* time = Util_GetTime();

	printf("%s[%02d:%02d:%02d] %s\n", prefix, time->tm_hour, time->tm_min, time->tm_sec, print);

	free(print);
}

void Util_Exit(int code) {
	Util_Log("Util_Exit called with code %d, exiting", code);
	exit(code);
}