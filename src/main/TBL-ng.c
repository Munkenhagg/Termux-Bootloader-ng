#include <tblng-intern-config.h>
#include <tblng-config.h>
#include <stdio.h>

int main(void) {
	const char *menu[] = MAIN_MENU;
	const char *selected = interactive_menu(menu, 5);
	printf("%s\n", selected);
	return 0;
}
