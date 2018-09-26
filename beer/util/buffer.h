#ifndef INCLUDE_UTIL_BUFFER_H
#define INCLUDE_UTIL_BUFFER_H

#include "../types.h"

#define BUFFER_FAIL		0
#define BUFFER_SUCCESS	1

#define BUFFER64_MASK (64 - 1)

typedef struct {
	uint8_t data[64];
	uint8_t read;
	uint8_t write;
} Buffer64;

uint8_t Buffer64In(Buffer64 *buffer, uint8_t byte);
uint8_t Buffer64Out(Buffer64 *buffer, uint8_t *pByte);

#endif