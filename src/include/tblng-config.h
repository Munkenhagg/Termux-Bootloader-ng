#ifndef TBLNG_CONFIG_H
#define TBLNG_CONFIG_H

#define BOOTLOADER_CONFIG "/data/data/com.termux/files/home/.config/termux-bootloader/config.json"

#define MENU_MAIN { "Enter shell", "Login", "Manage Users", "Settings", "Advanced Options" }

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
#ifdef MENU_COLOR_SUPPORT
        extern bool tbl_colors_initialized;
#else
        extern const bool tbl_colors_initialized;
#endif
extern char *current_user;

int parse_json(void);
void init_theme_colors(void);
int look_theme2pair(const char *name);
bool has_permission(char *user_id, char *wanted_perm);
int login_user(char *user_id, char *password);

#endif
