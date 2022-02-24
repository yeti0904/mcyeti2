#pragma once
#include "_components.h"

void* Safe_Malloc(size_t size);
void* Safe_Realloc(void* ptr, size_t size);
void* Safe_Alloc(void* ptr, size_t size);