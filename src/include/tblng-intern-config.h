#ifndef TBLNG_INTERN_CONFIG_H
#define TBLNG_INTERN_CONFIG_H

#include <stddef.h>

#define MAIN_MENU { "Enter shell", "Login", "Manage Users", "Settings", "Advanced Options" }

extern size_t current;
extern size_t ll;

void draw_menu(const char **items, size_t itemsz);

#endif
