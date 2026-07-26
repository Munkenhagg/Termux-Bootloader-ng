#include <tblng-intern-config.h>
#include <stddef.h>
#include <stdlib.h>

void delete_menu_map(struct menu_map *map) {
	if (!map) {
		return;
	}
	free(map->entries);
	free(map);

}
