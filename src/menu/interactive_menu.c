#include <tblng-intern-config.h>
#include <ncurses.h>

const char *interactive_menu(const char **items, size_t itemsz) {
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	const char *selected = NULL;
	while (selected == NULL) {
		draw_menu(items, itemsz);
		switch (getch()) {
			case KEY_UP: {
				current--;
				break;
			}
			case KEY_DOWN: {
				current++;
				break;
			}
			case '\n': {
				selected = items[current];
				break;
			}
			default: {
				break;
			}
		}
	}
	endwin();
	return selected;
}
