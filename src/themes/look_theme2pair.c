#include <tblng-config.h>
#include <ncurses.h>

int look_theme2pair(const char *name) {
	if (name == NULL) {
		return COLOR_PAIR(8);
	}
	if (strcmp(name, "black") == 0) return COLOR_PAIR(1);
	if (strcmp(name, "red")  == 0) return COLOR_PAIR(2);
	if (strcmp(name, "green") == 0) return COLOR_PAIR(3);
	if (strcmp(name, "yellow") == 0) return COLOR_PAIR(4);
	if (strcmp(name, "blue") == 0) return COLOR_PAIR(5);
	if (strcmp(name, "magenta") == 0) return COLOR_PAIR(6);
	if (strcmp(name, "cyan") == 0) return COLOR_PAIR(7);
	if (strcmp(name, "bright_black") == 0 || strcmp(name, "grey") == 0 || strcmp(name, "gray") == 0) return COLOR_PAIR(9);
	if (strcmp(name, "bright_red") == 0) return COLOR_PAIR(10);
	if (strcmp(name, "bright_green") == 0) return COLOR_PAIR(11);
	if (strcmp(name, "bright_yellow") == 0) return COLOR_PAIR(12);
	if (strcmp(name, "bright_blue") == 0) return COLOR_PAIR(13);
	if (strcmp(name, "bright_magenta") == 0) return COLOR_PAIR(14);
	if (strcmp(name, "bright_cyan") == 0) return COLOR_PAIR(15);
	if (strcmp(name, "bright_white") == 0) return COLOR_PAIR(16);
	return COLOR_PAIR(8);
}
