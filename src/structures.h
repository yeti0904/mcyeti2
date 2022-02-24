#pragma once
#include "_components.h"

struct Server {
	int              mainsock;
	struct addrinfo* address;
};

struct Client {
	int                sock;
	char*              ipString;
	struct sockaddr_in address;
};

struct ServerSettings {
	uint16_t port;
};

struct Array {
	void*  data;
	size_t size;
};

struct Program {
	bool         run;
	pthread_t    consoleWorker;
	pthread_t    packetWorker;
	struct Array packetStack;
};