#include <tblng-intern-config.h>
#include <tblng-config.h>

int main(void) {
	const char *menu[] = MAIN_MENU;
	draw_menu(menu, 5);
	return 0;
}
