# Termux-Bootloader Nextgen

## Info

### Rewritten

This is the equivelant to [my old termux-bootloader project](https://github.com/Munkenhagg/Termux-Bootloader) but rewritten in C

### Menu drawing framework

Originally to simplify drawing the menus, i created a interactive_menu function, which has now evolved into using proper dynamic maps.

**note**: the framework has yet to be tested

## Compiling & Usage

To compile the program you use cmake. here is how to use it:

```Shell
mkdir build && cd build
cmake .. -DBUILD_EXPERIMENTAL_FRAMEWORK # Remove -DBUILD_EXPERIMENTAL_FRAMEWORK to only compile the login manager TUI
cmake --build . --parallel $(nproc)
cd ..

```

This will create a binary at `arch/YOUR ARCHITECTURE/manager/termux-bootloader-ng`, and if `-DBUILD_EXPERIMENTAL_FRAMEWORK` was used also `arch/YOUR ARCHITECTURE/framework/libtblng.so` & static library `libtblng.a`

If you encounter errors/warnings then please create a github issue.
(unused variables and cJSON warnings should not be reported)

### Compilation options

Set by using `cmake .. -DOPTION`

`USE_DEBUG_BUILD`: Makes framework and binary more debuggabld using gdb (ON/OFF)
`BUILD_EXPERIMENTAL_FRAMEWORK`: builds experimental framework libs (ON/OFF)
`MENU_COLOR_SUPPORT`: adds native menu color support for both binary and framework using `look_theme2pair();` and `init_theme_colors();`
