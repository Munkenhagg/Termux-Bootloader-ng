#ifndef TBLNG_CONFIG_H
#define TBLNG_CONFIG_H

#define BOOTLOADER_CONFIG "/data/data/com.termux/files/home/.config/termux-bootloader/config.json"

#define MENU_MAIN {{ "Enter Shell", tblng_enter_shell, NULL }, { "Login", tblng_login, NULL }, { "Manage Users", tblng_manage_users, NULL}, { "Settings", tblng_settings, NULL }, { "Advanced Options", tblng_advanced_options, NULL }, { "Quit", tblng_quit, NULL }, { NULL, NULL, NULL }}

#include <stdbool.h>
#include <stddef.h>

struct tbl_user {
        char *id;
        char *password;
        char *permission;
        char *salt;
        char *regdate;
        int failcount;
};

struct tbl_cfg {
	struct tbl_user *users;
	size_t user_count;
	char *figlet_text;
	char *selected_theme;
	char *unselected_theme;
	char *logfile;
	char *main_theme;
	char *shell;
	bool account_lock;
};

extern struct tbl_cfg bl_config;
extern char *current_user;

int parse_json(void);
bool has_permission(char *user_id, char *wanted_perm);
int login_user(char *user_id, char *password);

struct interactive_menu_output menu_main(void);

void *tblng_enter_shell(void *no_use);
void *tblng_login(void *no_use);
void *tblng_manage_users(void *no_use);
void *tblng_settings(void *no_use);
void *tblng_advanced_options(void *no_use);
void *tblng_quit(void *no_use);

#endif
