#include <tblng-intern-config.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void edit_menu_map_entry(struct menu_map *map, size_t entrynum, const struct menu_map_entry *replace_entry) {
	if (!map || !replace_entry || !replace_entry->option || entrynum >= map->entry_count) {
		return;
	}
	map->entries[entrynum] = *replace_entry;
}
