#include "string.h"
#include "../types.h"

uint32_t strlen(char* str) {
	uint32_t i = 0;

	for(; str[i] != 0; i++) ;

	return i;
}