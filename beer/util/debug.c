#include "debug.h"
#include "../serial.h"
#include "string.h"


static char PREF_INFO[] = "INFO: ";
static char PREF_WARN[] = "WARN: ";
static char PREF_ERROR[] = "ERROR: ";
static char SUFF_NL[] = "\n";

uint32_t comPort;

void init_debug(uint32_t com) {
	comPort = com;
	serial_configure_baud_rate(com, 1);
	serial_configure_line(com);
	serial_configure_buffer(com);
	serial_configure_modem(com);
}

void kinfo(char* msg) {
	serial_print(comPort, PREF_INFO);
	serial_print(comPort, msg);
	serial_print(comPort, SUFF_NL);
}

void kwarn(char* msg) {
	serial_print(comPort, PREF_WARN);
	serial_print(comPort, msg);
	serial_print(comPort, SUFF_NL);
}

void kerror(char* msg) {
	serial_print(comPort, PREF_ERROR);
	serial_print(comPort, msg);
	serial_print(comPort, SUFF_NL);
}