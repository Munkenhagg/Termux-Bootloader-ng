# Usage

## 1.1 - Basics

To use the menu, you need to include ncurses, by using -lncurses(make/gcc) or Curses:Curses(cmake).

You will then have to [create a screen](#21---screens).

### 1.2 - Using menu Framework

To use the framework, you use interactive_menu to create a menu, and assign it to a variable to get what value the user selected.
This is a fully working example:
```C
initscr();
init_theme_colors(); // adds colors
struct menu_map_entry *ents = { {"choice_1", function_1, "Function Argument"}, {"choice_2", function_2, "Function argument"}, {NULL, NULL, NULL} };
struct menu_map *map = init_menu_map_from_array(ents);
menu_output_t output = interactive_menu(map);
endwin();
printf(%s\n, output.selected);
fflush(stdout);

```

## 2.1 - Screens

To use the memu, you will have to manage a screen. this is not hard. you just have to use `initscr();` once at the start and |endwin();` when the program exits.

note - endwin(); doesnt have to be used in the same function as `initscr();` was used in, it can be used in any function.

Also see [text printing advice](#22---text-printing-advice)

### 2.2 - Text Printing Advice

After [setting up a screen](#21---screens) you must not use `printf();` or similar tools, instead the ncurses alternative is the only guranteed to work - `printw();`. with the exact same syntax as `printf();`.
