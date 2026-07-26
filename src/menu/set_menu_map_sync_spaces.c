#include <tblng-intern-config.h>
#include <stdint.h>

void set_menu_map_sync_spaces(struct menu_map *map, uint8_t spaces) {
	map->sync_spaces = (!spaces) ? map->sync_spaces : spaces;
	return;
}
