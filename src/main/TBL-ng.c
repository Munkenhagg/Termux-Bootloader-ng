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
	const char *menu[] = MAIN_MENU;
	const char *selected = interactive_menu(menu, 5);
	printf("%s\n", selected);
	endwin();
	return 0;
}
