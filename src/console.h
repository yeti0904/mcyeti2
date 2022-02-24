#pragma once
#include "structures.h"

struct Console_Worker_Args {
	struct Program* program;
};

void*     Console_Worker(void* structure);
pthread_t Console_Worker_Init(struct Program* program);