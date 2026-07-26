#include <tblng-intern-config.h>
#include <ncurses.h>
#include <stdbool.h>

struct interactive_menu_output interactive_menu(const struct menu_map *map) {
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	bool selected = false;
	size_t current = 0;
	while (!selected) {
		draw_menu(map, current);
		switch (getch()) {
			case KEY_UP: {
				if (current == 0) {
					current = map->entry_count - 1;
				} else {
					current--;
				}
				break;
			}
			case KEY_DOWN: {
				if (current == map->entry_count - 1) {
					current = 0;
				} else {
					current++;
				}
				break;
			}
			case '\n': {
				selected = true;
				break;
			}
			default: {
				break;
			}
		}
	}
	void *func_out = NULL;
	if (map->entries[current].function != NULL) {
		#ifdef DEBUG_BUILD
			menu_map_function_t func = map->entries[current].function;
			void *arg = map->entries[current].function_arg;
			func_out = func(arg);
		#else
			func_out = map->entries[current].function(map->entries[current].function_arg);
		#endif
	}
	struct interactive_menu_output output = { .code = INTERACTIVE_MENU_SUCCESS, .selected = map->entries[current].option, .callback_return = func_out };
	return output;
}
