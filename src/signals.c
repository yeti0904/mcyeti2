#include "_components.h"
#include "util.h"
#include "constants.h"

void SignalHandler_SIGINT(int signal) {
	Util_LogWithPrefix("\n", "Exit (SIGINT)");
	exit(0);
}

void SignalHandler_SIGSEGV(int signal) {
	Util_Log("\e[31mFATAL ERROR\e[0m");
	Util_Log("Error: Segmentation fault (SIGSEGV)");
	Util_Log("Run again and reproduce this issue while running under valgrind, then report the valgrind erorrs to %s", APP_AUTHOR);
	exit(1);
}

void SignalHandler_Init() {
	signal(SIGINT, SignalHandler_SIGINT);
	signal(SIGSEGV, SignalHandler_SIGSEGV);
}