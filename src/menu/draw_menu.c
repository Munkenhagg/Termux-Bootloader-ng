#include <tblng-config.h>
#include <tblng-intern-config.h>
#include <stddef.h>
#include <stdio.h>
#include <term.h>
#include <unistd.h>

void draw_menu(const char **items, size_t itemsz) {
	size_t lc = 0;;
	setupterm(NULL, STDOUT_FILENO, NULL);
	for (size_t i = 0; i < itemsz; i++) {
		if (i == current) {
			printf("> %s\n", items[i]);
		} else {
			printf("  %s\n", items[i]);
		}
		lc++;
	}
	for (size_t i = lc; i<ll; i++) {
		printf("%s\n", clr_eol);
	}
	fflush(stdout);
	ll = lc;
}
