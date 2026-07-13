#include <tblng-config.h>
#include <tblng-intern-config.h>
#include <stddef.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

void draw_menu(const char **items, size_t itemsz) {
	clear();
	curs_set(0);
	fflush(stdout);
	for (size_t i = 0; i < itemsz; i++) {
		if (i == current) {
			printw("> %s%s\n", bl_config.selected_theme, items[i]);
		} else {
			printw("  %s%s\n", bl_config.unselected_theme, items[i]);
		}
	}
	fflush(stdout);
	return;
}
