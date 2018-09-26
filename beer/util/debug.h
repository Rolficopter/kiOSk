#ifndef INCLUDE_UTIL_DEBUG_H
#define INCLUDE_UTIL_DEBUG_H

#include "../types.h"

void init_debug(uint32_t com);

void kinfo(char* msg);
void kwarn(char* msg);
void kerror(char* msg);

#endif