#include "beer/framebuffer.h"
#include "beer/keyboard.h"
#include "beer/serial.h"
#include "beer/util/debug.h"

static char HELLO[] = "Hallo Welt!!1!1elf!1!";

int kernel_main() {
	init_debug(SERIAL_COM1);

	kinfo(HELLO);
	kwarn(HELLO);
	kerror(HELLO);

	clear_screen();
	write_with_colors(HELLO, 21, FB_COLOR_GREEN, FB_COLOR_BLACK);
	while (1)
	{
		char c = getc();
		if(c)
			write(&c, 1);
	}
	return 0;
}