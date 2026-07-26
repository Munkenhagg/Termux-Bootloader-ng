#include <tblng-intern-config.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct menu_map *init_menu_map_from_array(const struct menu_map_entry *entries) {
	if (!entries) {
		return NULL;
	}
	size_t count = 0;
	while (entries[count].option != NULL) {
		count++;
	}
	struct menu_map *map = malloc(sizeof(struct menu_map));
	if (!map) {
		return NULL;
	}
	map->entries = malloc((count + 1) * sizeof(struct menu_map_entry));
	if (!map->entries) {
		free(map);
		return NULL;
	}
	memcpy(map->entries, entries, (count + 1) * sizeof(struct menu_map_entry));
	map->entry_count = count;
	map->selected_color_theme = "green";
	map->unselected_color_theme = "white";
	map->ptr_sym = ">";
	map->sync_spaces = 1;
	return map;
}
