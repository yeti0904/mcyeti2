#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#error windows is not supported because i use unix sockets
#endif

// macros
#define _GNU_SOURCE

// standard libraries
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include <math.h>

// socket libraries
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// libraries
#include <pthread.h>
#include <readline/readline.h>