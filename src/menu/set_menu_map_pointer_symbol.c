#include <tblng-intern-config.h>

void set_menu_map_pointer_symbol(struct menu_map *map, char *sym) {
	map->ptr_sym = sym;
	return;
}
