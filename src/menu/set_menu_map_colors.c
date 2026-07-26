#include <tblng-intern-config.h>
#include <stddef.h>

void set_menu_map_colors(struct menu_map *map, char *selected, char *unselected) {
	map->selected_color_theme = (selected == NULL) ? "white" : selected;
	map->unselected_color_theme = (unselected == NULL) ? "white" : unselected;
	return;
}
