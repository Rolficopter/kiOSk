#include "io.h"
#include "framebuffer.h"

#define FB_COMMAND_PORT			0x3D4
#define FB_DATA_PORT			0x3D5

#define FB_HIGH_BYTE_COMMAND	14
#define FB_LOW_BYTE_COMMAND		15

char *fb = (char *) 0x000B8000;

unsigned short cursor_position = 0;
unsigned char bg_color = FB_COLOR_BLACK;
unsigned char fg_color = FB_COLOR_WHITE;

void fb_move_cursor(unsigned short pos) 
{
	cursor_position = pos;
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

void fb_write_cell(unsigned int pos, char c, unsigned char fg, unsigned char bg) {
	fb[pos] = c;
	fb[pos + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

void set_cursor_position(unsigned char row, unsigned char col)
{
	fb_move_cursor(80 * row + col);
}

int write_with_colors(char *buf, unsigned int len, unsigned char fg, unsigned char bg)
{
	for (unsigned int i = 0; i < len; i++) {
		fb_write_cell(cursor_position + i, buf[i], fg, bg);
	}
	cursor_position += len;
	return cursor_position;
}

void set_fg_color(unsigned char color)
{
	fg_color = color;
}


void set_bg_color(unsigned char color)
{
	bg_color = color;
}

int write(char *buf, unsigned int len)
{
	return write_with_colors(buf, len, fg_color, bg_color);
}