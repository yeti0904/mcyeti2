#include "_components.h"
#include "util.h"
#include "structures.h"

struct Server Server_Init(struct Program* program, struct ServerSettings* settings) {
	struct Server server;

	char* portString = (char*) malloc((int)((ceil(log10(settings->port))+1)));
	sprintf(portString, "%d", settings->port);

	struct addrinfo* addrInfoResult = NULL;
	struct addrinfo  hints;

	memset(&hints, 0, sizeof(hints));

	hints.ai_family   = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags    = AI_PASSIVE;

	if (getaddrinfo(NULL, portString, &hints, &addrInfoResult) != 0) {
		Util_Log("Error: getaddrinfo failed");
		Util_Exit(1);
	}
	free(portString);
	
	server.mainsock = socket(addrInfoResult->ai_family, addrInfoResult->ai_socktype, addrInfoResult->ai_protocol);
	if (server.mainsock < 0) {
		Util_Log("Error: socket creation failed");
		perror("socket");
		Util_Exit(1);
	}

	int32_t reuse = 1;
	if (setsockopt(server.mainsock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
		Util_Log("Error: setsockopt failed");
		Util_Exit(1);
	}

	if (bind(server.mainsock, addrInfoResult->ai_addr, addrInfoResult->ai_addrlen) < 0) {
		Util_Log("Error: bind failed");
		Util_Exit(1);
	}

	if (listen(server.mainsock, SOMAXCONN) < 0) {
		Util_Log("Error: listen failed");
		perror("listen");
		Util_Exit(1);
	}

	server.address = addrInfoResult;
}