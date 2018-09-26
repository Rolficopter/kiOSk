#ifndef INCLUDE_FRAMEBUFFER_H
#define INCLUDE_FRAMEBUFFER_H

#define FB_COLOR_BLACK			0
#define FB_COLOR_BLUE			1
#define FB_COLOR_GREEN			2
#define FB_COLOR_CYAN			3
#define FB_COLOR_RED			4
#define FB_COLOR_MAGENTA		5
#define FB_COLOR_BROWN			6
#define FB_COLOR_LIGHT_GREY		7
#define FB_COLOR_DARK_GREY		8
#define FB_COLOR_LIGHT_BLUE		9
#define FB_COLOR_LIGHT_GREEN	10
#define FB_COLOR_LIGHT_CYAN		11
#define FB_COLOR_LIGHT_RED		12
#define FB_COLOR_LIGHT_MAGENTA	13
#define FB_COLOR_LIGHT_BROWN	14
#define FB_COLOR_WHITE			15

void set_cursor_position(unsigned char row, unsigned char col);

int write_with_colors(char *buf, unsigned int len, unsigned char fg, unsigned char bg);
int write(char *buf, unsigned int len);
void set_fg_color(unsigned char color);
void set_bg_color(unsigned char color);

#endif