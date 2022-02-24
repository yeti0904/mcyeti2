#pragma once

void SignalHandler_SIGINT(int signal);
void SignalHandler_SIGSEGV(int signal);

void SignalHandler_Init();