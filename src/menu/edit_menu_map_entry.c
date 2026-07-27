#include <tblng-intern-config.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void edit_menu_map_entry(struct menu_map *map, int entrynum, struct menu_map_entry replace_entry) {
	if (!map || !replace_entry.option) {
		return;
	}
	struct menu_map_entry *entries = calloc(map->entry_count + 1, sizeof(*entries));
	if (!entries) {
		return;
	}
	char *selected = map->selected_color_theme;
	char *unselected = map->unselected_color_theme;
	char *oldptrsym = map->ptr_sym;
	uint8_t spcs = map->sync_spaces;
	memcpy(entries, map->entries, (map->entry_count + 1) * sizeof(struct menu_map_entry));
	entries[entrynum] = replace_entry;
	delete_menu_map(map);
	map = init_menu_map_from_array(entries);
	free(entries);
	set_menu_map_colors(map, selected, unselected);
	set_menu_map_pointer_symbol(map, oldptrsym);
	set_menu_map_sync_spaces(map, spcs);
}
