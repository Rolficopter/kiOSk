#include "keyboard.h"
#include "io.h"
#include "util/buffer.h"

#define KEYBOARD_DATA_PORT	0x60

Buffer64 input_buffer;

char getc() {
	uint8_t output;
	
	if(Buffer64Out(&input_buffer, &output) == BUFFER_SUCCESS) {
		return output;
	}

	return 0;
}

unsigned char read_keyboard_code() {
	return inb(KEYBOARD_DATA_PORT);
}

void INT_keyboard() {
	uint8_t input = read_keyboard_code();

	if(Buffer64In(&input_buffer, input) == BUFFER_SUCCESS) {
		// be happy
	}
}