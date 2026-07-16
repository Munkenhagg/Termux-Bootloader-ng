#ifndef TBLNG_CONFIG_H
#define TBLNG_CONFIG_H

#define BOOTLOADER_CONFIG "/data/data/com.termux/files/home/.config/termux-bootloader/config.json"

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
extern bool tbl_colors_initialized;

int parse_json(void);
void init_theme_colors(void);

#endif
