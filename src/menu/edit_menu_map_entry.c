#include <tblng-intern-config.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void edit_menu_map_entry(struct menu_map *map, size_t entrynum, const struct menu_map_entry replace_entry) {
	if (!map || !replace_entry.option || entrynum >= map->entry_count) {
		return;
	}
	struct menu_map_entry *targ = &map->entries[entrynum];
	free(targ->option);
	targ->option = strdup(replace_entry.option);
	targ->function = replace_entry.function;
	targ->function_arg = replace_entry.function_arg;
	return;
}
