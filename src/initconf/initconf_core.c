#include <tblng-intern-config.h>
#include <stdbool.h>

#ifdef MENU_COLOR_SUPPORT
        bool tbl_colors_initialized = false;
#else
        const bool tbl_colors_initialized = false;
#endif
