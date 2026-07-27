#ifndef TBLNG_INTERN_CONFIG_H
#define TBLNG_INTERN_CONFIG_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#define get_menu_map_size(map) (map->entry_count)

typedef void *(*menu_map_function_t)(void *);

#ifdef MENU_COLOR_SUPPORT
        extern bool tbl_colors_initialized;
#else
        extern const bool tbl_colors_initialized;
#endif

struct interactive_menu_output {
        int8_t code;
        const char *selected;
	void *callback_return;
	size_t current_integer;
};

struct menu_map_entry {
	char *option;
	menu_map_function_t function;
	void *function_arg;
};

struct menu_map {
	struct menu_map_entry *entries;
	size_t entry_count;
	char *selected_color_theme;
	char *unselected_color_theme;
	char *ptr_sym;
	uint8_t sync_spaces;
};

struct interactive_menu_output interactive_menu(const struct menu_map *items);
void draw_menu(const struct menu_map *map, size_t current);
const char **menu_map_to_optstrarr(const struct menu_map *map);
void init_theme_colors(void);
int look_theme2pair(const char *name);

struct menu_map *init_menu_map_from_array(const struct menu_map_entry *entries);
void delete_menu_map(struct menu_map *map);
void set_menu_map_colors(struct menu_map *map, char *selected, char *unselected);
void set_menu_map_pointer_symbol(struct menu_map *map, char *sym);
void set_menu_map_sync_spaces(struct menu_map *map, uint8_t spaces);
void edit_menu_map_entry(struct menu_map *map, size_t entrynum, const struct menu_map_entry *replace_entry);

typedef struct interactive_menu_output menu_output_t;

#define INTERACTIVE_MENU_CTRLC_PRESSED -1
#define INTERACTIVE_MENU_INTERNAL_ERROR -2
#define INTERACTIVE_MENU_SUCCESS 0

#endif
