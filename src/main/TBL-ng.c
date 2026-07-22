#include <tblng-intern-config.h>
#include <tblng-config.h>
#include <stdio.h>
#include <ncurses.h>

int main(void) {
	initscr();
	if (parse_json() != 0) {
		printf("Failed to parse config! exiting.");
		return 1;
	}
	init_theme_colors();
	const char *menu[] = MENU_MAIN;
	const char *selected = interactive_menu(menu, get_menu_size(menu));
	endwin();
	printf("%s\n", selected);
	fflush(stdout);
	return 0;
}
