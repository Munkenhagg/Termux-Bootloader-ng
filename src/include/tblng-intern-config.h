#ifndef TBLNG_INTERN_CONFIG_H
#define TBLNG_INTERN_CONFIG_H

#include <stddef.h>
#include <stdbool.h>

#define MAIN_MENU { "Enter shell", "Login", "Manage Users", "Settings", "Advanced Options" }

extern size_t current;
extern size_t ll;
extern char *current_user;

const char *interactive_menu(const char **items, size_t itemsz);
void draw_menu(const char **items, size_t itemsz);
bool has_permission(char *user_id, char *wanted_perm);
int login_user(char *user_id, char *password);


#endif
