#include "_components.h"
#include "util.h"

void* Safe_Malloc(size_t size) {
	void* ret = malloc(size);
	if (ret == NULL) {
		Util_Log("\e[31mFATAL ERROR\e[0m");
		Util_Log("Error: malloc(%ld) returned NULL", size);
		exit(1);
	}
	return ret;
}

void* Safe_Realloc(void* ptr, size_t size) {
	void* ret = realloc(ptr, size);
	if (ret == NULL) {
		Util_Log("\e[31mFATAL ERROR\e[0m");
		Util_Log("Error: realloc(%p, %ld) returned NULL", ptr, size);
		exit(1);
	}
	return ret;
}

void* Safe_Alloc(void* ptr, size_t size) {
	if (ptr == NULL) {
		return Safe_Malloc(size);
	}
	else {
		return Safe_Realloc(ptr, size);
	}
}