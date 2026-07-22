#ifndef TBLNG_INTERN_CONFIG_H
#define TBLNG_INTERN_CONFIG_H

#include <stddef.h>
#include <stdbool.h>

#define get_menu_size(arr) (sizeof(arr) / sizeof(arr[0]))

extern size_t current;
extern char *menu_ptr_sym;

const char *interactive_menu(const char **items, size_t itemsz);
void draw_menu(const char **items, size_t itemsz);

#endif
