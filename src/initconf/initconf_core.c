#include <tblng-intern-config.h>
#include <tblng-config.h>
#include <stddef.h>
#include <stdbool.h>

size_t current = 0;
#ifdef MENU_COLOR_SUPPORT
        bool tbl_colors_initialized = false;
#else
        const bool tbl_colors_initialized = false;
#endif
char *menu_ptr_sym = ">";
