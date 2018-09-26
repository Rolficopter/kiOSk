#include "buffer.h"
#include "../types.h"

uint8_t Buffer64In(Buffer64 *buffer, uint8_t byte) {
	uint8_t next = ((buffer->write + 1) & BUFFER64_MASK);

	if(buffer->read == next)
		return BUFFER_FAIL;

	buffer->data[buffer->write & BUFFER64_MASK] = byte;
	buffer->write = next;

	return BUFFER_SUCCESS;
}

uint8_t Buffer64Out(Buffer64 *buffer, uint8_t *pByte) {
	if(buffer->read == buffer->write)
		return BUFFER_FAIL;

	*pByte = buffer->data[buffer->read];

	buffer->read = (buffer->read + 1) & BUFFER64_MASK;

	return BUFFER_SUCCESS;
}