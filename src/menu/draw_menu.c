#include <tblng-config.h>
#include <tblng-intern-config.h>
#include <stddef.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>

void draw_menu(const char **items, size_t itemsz) {
	clear();
	curs_set(0);
	if (tbl_colors_initialized) {
		int sell_pair = look_theme2pair(bl_config.selected_theme);
		int unsell_pair = look_theme2pair(bl_config.unselected_theme);
		for (size_t i = 0; i < itemsz; i++) {
			bool cursell = (i == current) ? true : false;
			int pair = (cursell) ? sell_pair : unsell_pair;
			attron(pair);
			printw("%s %s\n", (cursell) ? ((menu_ptr_sym != NULL || menu_ptr_sym[0] != '\0') ? menu_ptr_sym : ">") : " ", items[i]);
			attroff(pair);
		}
	} else {
		for (size_t i = 0; i < itemsz; i++) {
			printw("%s %s\n", (i == current) ? ((menu_ptr_sym != NULL || menu_ptr_sym[0] != '\0') ? menu_ptr_sym : ">") : " ", items[i]);
		}
	}
	refresh();
	return;
}
