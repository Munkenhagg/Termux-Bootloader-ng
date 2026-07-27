#include <tblng-intern-config.h>
#include <tblng-config.h>
#include <gen-tblng-version.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc > 1) {
		if (strcmp(argv[1], "-v") == 0) {
			const char *version = tblng_get_version_str();
			printf("%s\n", version);
			fflush(stdout);
		}
		return 0;
	}
	initscr();
	if (parse_json() != 0) {
		printf("Failed to parse config! exiting.");
		return 1;
	}
	init_theme_colors();
	menu_output_t out = menu_main();
	endwin();
	printf("selected: %s, int: %zu\n", out.selected, out.current_integer);
	fflush(stdout);
	return 0;
}
