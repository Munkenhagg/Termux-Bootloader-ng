#include <ncurses.h>
#include <tblng-config.h>

void init_theme_colors(void) {
	if (tbl_colors_initialized) {
		return;
	}
	start_color();
	use_default_colors();
	init_pair(1,  COLOR_BLACK, -1);
	init_pair(2,  COLOR_RED, -1);
	init_pair(3,  COLOR_GREEN, -1);
	init_pair(4,  COLOR_YELLOW, -1);
	init_pair(5,  COLOR_BLUE, -1);
	init_pair(6,  COLOR_MAGENTA, -1);
	init_pair(7,  COLOR_CYAN, -1);
	init_pair(8,  COLOR_WHITE, -1);
	init_pair(9,  8 + COLOR_BLACK, -1);
	init_pair(10, 8 + COLOR_RED, -1);
	init_pair(11, 8 + COLOR_GREEN, -1);
	init_pair(12, 8 + COLOR_YELLOW, -1);
	init_pair(13, 8 + COLOR_BLUE, -1);
	init_pair(14, 8 + COLOR_MAGENTA, -1);
	init_pair(15, 8 + COLOR_CYAN, -1);
	init_pair(16, 8 + COLOR_WHITE, -1);
	tbl_colors_initialized = true;
}
