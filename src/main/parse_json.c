#include <cJSON.h>
#include <tblng-config.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <string.h>

int parse_json(void) {
	struct stat st;
	const char *blpath = BOOTLOADER_CONFIG;
	if (stat(blpath, &st) != 0) {
		return 1;
	}
	FILE *f = fopen(blpath, "rb");
	if (!f) {
		return 1;
	}
	size_t size = (size_t)st.st_size;
	char *jsonbuf = malloc(size + 1);
	if (!jsonbuf) {
		fclose(f);
		return 1;
	}
	size_t n = fread(jsonbuf, 1, size, f);
	jsonbuf[n] = '\0';
	cJSON *cjroot = cJSON_Parse((const char*)jsonbuf);
	if (!cjroot) {
		free(jsonbuf);
		fclose(f);
		return 1;
	}
	cJSON *it_users, *it_figlet_text, *it_selected_theme, *it_unselected_theme, *it_logfile, *it_main_theme, *it_shell, *it_acc_lock;
	it_main_theme = cJSON_GetObjectItemCaseSensitive(cjroot, "main_theme");
	it_selected_theme = cJSON_GetObjectItemCaseSensitive(cjroot, "selected_theme");
	it_unselected_theme = cJSON_GetObjectItemCaseSensitive(cjroot, "unselected_theme");
	bl_config.selected_theme = strdup(cJSON_GetStringValue(it_selected_theme));
	bl_config.unselected_theme = strdup(cJSON_GetStringValue(it_unselected_theme));
	bl_config.main_theme = strdup(cJSON_GetStringValue(it_main_theme));
	fclose(f);
	free(jsonbuf);
	cJSON_Delete(cjroot);
	return 0;
}
