#include "_components.h"
#include "console.h"
#include "util.h"
#include "safe.h"

void* Console_Worker(void* structure) {
	struct Console_Worker_Args args = *((struct Console_Worker_Args*)structure);
	free(structure);

	while (args.program->run) {
		char* input = readline("> ");
		if (input == NULL) {
			Util_Log("Error: readline returned NULL");
		}
		else {
			if (strcmp(input, "/quit") == 0) {
				Util_Log("Console worker requested shutdown");
				free(input);
				args.program->run = false;
				Util_Log("Ready for shutdown");
			}
		}
	}
	return NULL;
}

pthread_t Console_Worker_Init(struct Program* program) {
	struct Console_Worker_Args* args = (struct Console_Worker_Args*) Safe_Malloc(sizeof(struct Console_Worker_Args));
	args->program = program;

	pthread_t thread;
	pthread_create(&thread, NULL, Console_Worker, args);

	return thread;
}