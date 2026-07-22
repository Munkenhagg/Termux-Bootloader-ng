# Special variables

the main special global variables in the framework.

## 1 - Variables to be edited

these are variables that can/should be edited manually

### 1.1 - Pointer

`menu_ptr_sym`: What symbol is used as the pointer in the menu, e.g. >(SYMBOL) Settings(CURRENT OPTIOM)
menu\_ptr\_sym should only ever be one symbol. but most be a char* not single char asunicode characters are more than 1 byte. but it also allows for any amount long string, which will result in the selected option to not be aligned with the others.

Defaults to `>`

Also see [Color init variable](#22---color-init-bool) (related)

## 2 - Variables to not override

these are variables that generally ahould nkt be manually edited but reserved. 

### 2.1 - Current Option

`current`: which option is currently selected. always size_t(on posix systems, unsigned int/unsigned long int) which comes from stddef.h.
editing current will result in a different option choice in the TUI and is not recommended without caution of limits.

### 2.2 - Color Init Bool

`tbl_colors_initialized`: holds a bool determining if color themes are initialized. if `MENU_COLOR_SUPPORT` is off then is const bool to ensure no edits.
editing tbl\_colors\_initialized may result in `init_themes();` to be duplicate pairs if called multiple times.

Also see [Pointer variable](#11---pointer) (related)
