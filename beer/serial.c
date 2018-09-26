#include "serial.h"
#include "io.h"


#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

#define SERIAL_LINE_ENABLE_DLAB         0x80

void serial_configure_baud_rate(uint16_t com, uint16_t divisor) {
	outb(SERIAL_LINE_COMMAND_PORT(com),
         SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com),
         (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com),
         divisor & 0x00FF);
}

void serial_configure_line(uint16_t com) {
	/* Bit:     | 7 | 6 | 5 4 3 | 2 | 1 0 |
     * Content: | d | b | prty  | s | dl  |
     * Value:   | 0 | 0 | 0 0 0 | 0 | 1 1 | = 0x03
     */
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

void serial_configure_buffer(uint16_t com) {
	/* Bit:     | 7 6 | 5  | 4 | 3   | 2   | 1   | 0 |
	 * Content: | lvl | bs | r | dma | clt | clr | e |
	 * Value:   | 1 1 | 0  | 0 | 0   |  1  | 1   | 1 | = 0xC7
     */
    outb(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);
}

void serial_configure_modem(uint16_t com) {
	/* Bit:     | 7 | 6 | 5  | 4  | 3   | 2   | 1   | 0   |
	 * Content: | r | r | af | lb | ao2 | ao1 | rts | dtr |
	 * Value:   | 0 | 0 | 0  | 0  | 0   |  0  | 1   |  1  | = 0x03
     */
    outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);
}

int serial_is_transmit_fifo_empty(uint32_t com) {
	return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void serial_write(uint32_t com, char* data, uint32_t len) {
	while(!serial_is_transmit_fifo_empty(com)) ;

	for (uint32_t i = 0; i < len; i++) {
		outb(SERIAL_DATA_PORT(com), data[i]);
	}
}

void serial_print(uint32_t com, char data[]) {
	while(!serial_is_transmit_fifo_empty(com)) ;

	for(uint32_t i = 0; data[i] != 0; i++) {
		outb(SERIAL_DATA_PORT(com), data[i]);
	}
}