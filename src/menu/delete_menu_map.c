#include <tblng-intern-config.h>
#include <stddef.h>
#include <stdlib.h>

void delete_menu_map(struct menu_map *map) {
	if (!map) {
		return;
	}
	for (size_t i = 0; i < map->entry_count; i++) {
		free(map->entries[i].option);
	}
	free(map->entries);
	free(map);

}
