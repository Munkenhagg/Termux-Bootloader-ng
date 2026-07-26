#include <tblng-intern-config.h>
#include <stddef.h>
#include <stdlib.h>

const char **menu_map_to_optstrarr(const struct menu_map *map) {
	const char **outbuf = malloc((map->entry_count + 1) * sizeof(const char*));
	for (size_t i = 0; i < map->entry_count; i++) {
		outbuf[i] = map->entries[i].option;
	}
	outbuf[map->entry_count] = NULL;
	return outbuf;
}
