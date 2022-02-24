#include "_components.h"
#include "constants.h"
#include "util.h"
#include "structures.h"
#include "signals.h"
#include "console.h"
#include "safe.h"
#include "server.h"

int main(void) {
	Util_Log("Welcome to %s %s", APP_NAME, APP_VERSION);
	Util_Log("Written by %s", APP_AUTHOR);

	struct Program program = {
		.run = true,
		.packetStack = {
			.data = NULL,
			.size = 0
		}
	};

	struct ServerSettings serverSettings = {
		.port = 25565
	};

	// initialize everything
	SignalHandler_Init();
	Util_Log("Started signal handlers");
	program.consoleWorker = Console_Worker_Init(&program);
	Util_Log("Started console worker");
	rl_clear_signals();
	Util_Log("Set up readline");
	struct Server server = Server_Init(&program, &serverSettings);
	Util_Log("Started server on port %d", serverSettings.port);

	int                newsock;
	struct sockaddr_in clientAddress;
	struct Client      newclient;
	Util_Log("Ready");

	while (program.run) {
		newsock = accept(server.mainsock, &clientAddress, NULL);
		if (newsock < 0) {
			Util_Log("Error: accept failed");
			perror("accept");
			program.run = false;
		}
		else {
			// get address of client
			newclient.sock     = newsock;
			newclient.address  = clientAddress;
			newclient.ipString = inet_ntoa(clientAddress.sin_addr);
			Util_Log("Accepted connection from %s", newclient.ipString);
		}
	}

	Util_Log("Exit (sent from main thread)");
	return 0;
}