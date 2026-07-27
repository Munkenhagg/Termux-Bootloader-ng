#include <tblng-intern-config.h>
#include <tblng-config.h>
#include <stdlib.h>
#include <ncurses.h>

struct interactive_menu_output menu_main(void) {
	struct menu_map_entry menu_entries[] = MENU_MAIN;
	struct menu_map *menu_map_main = init_menu_map_from_array(menu_entries);
	/* struct menu_map_entry newent = { "Enter da shell", tblng_enter_shell, NULL };
	edit_menu_map_entry(menu_map_main, 0, newent); */ // testing edit_menu_map_entry
	menu_output_t output = interactive_menu(menu_map_main);
	delete_menu_map(menu_map_main);
	return output;
}

