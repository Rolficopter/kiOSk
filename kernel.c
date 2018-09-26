#include "beer/framebuffer.h"
#include "beer/keyboard.h"

static char HELLO[] = "Hallo Welt!!1!1elf!1!";

int kernel_main() {
	clear_screen();
	write_with_colors(HELLO, 21, FB_COLOR_GREEN, FB_COLOR_BLACK);
	while (1)
	{
		char c = read_keyboard_code();
		write(&c, 1);
	}
	return 0;
}