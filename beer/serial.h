#ifndef INCLUDE_SERIAL_H
#define INCLUDE_SERIAL_H

#include "types.h"


#define SERIAL_COM1	0x3F8	/* COM1 base port */


void serial_configure_baud_rate(uint16_t com, uint16_t divisor);
void serial_configure_line(uint16_t com);
void serial_configure_buffer(uint16_t com);
void serial_configure_modem(uint16_t com);

int serial_is_transmit_fifo_empty(uint32_t com);
void serial_write(uint32_t com, char* data, uint32_t len);
void serial_print(uint32_t com, char data[]);

#endif