#include <tblng-intern-config.h>
#include <stddef.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>

void draw_menu(const struct menu_map *map, size_t current) {
	clear();
	curs_set(0);
	char spaces[map->sync_spaces + 1];
	memset(spaces, ' ', map->sync_spaces);
	spaces[map->sync_spaces] = '\0';
	if (tbl_colors_initialized) {
		int sell_pair = look_theme2pair(map->selected_color_theme);
		int unsell_pair = look_theme2pair(map->unselected_color_theme);
		for (size_t i = 0; i < map->entry_count; i++) {
			bool cursell = (i == current) ? true : false;
			int pair = (cursell) ? sell_pair : unsell_pair;
			attron(pair);
			printw("%s %s\n", (cursell) ? ((map->ptr_sym != NULL && map->ptr_sym[0] != '\0') ? map->ptr_sym : ">") : spaces, map->entries[i].option);
			attroff(pair);
		}
	} else {
		for (size_t i = 0; i < map->entry_count; i++) {
			printw("%s %s\n", (i == current) ? ((map->ptr_sym != NULL && map->ptr_sym[0] != '\0') ? map->ptr_sym : ">") : spaces, map->entries[i].option);
		}
	}
	refresh();
	return;
}
