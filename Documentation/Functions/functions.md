# Functions

## Menu map core

### Init menu map

`init_menu_map_from_array`: initializes a menu map from a provided `struct menu_map_entry[]`
Example usage:

```C
struct menu_map_entry entries[] = { { "Option", "Function, "Function Argument" } };
struct menu_map *map = init_menu_map_from_array(entries);

```

signature: `struct menu_map *init_menu_map_from_array(const struct menu_map_entry *entries);`

### Delete menu map

`delete_menu_map`: deletes a initialized menu map.
Example usage:

```C
struct menu_map *map = init_menu_map_from_array(entries);
delete_menu_map(map);

```

signature: `void delete_menu_map(struct menu_map *map);`

### Edit entry

`edit_menu_map_entry`: takes a given entry and entry number and replaces the entry.
Example usage:

```C
struct menu_map *map = init_menu_map_from_array(entries);
struct menu_map_entry new_entry = { "New option", New_Function, "New Function Argument" }
edit_menu_map_entry(map, 0, new_entry);

```

signature: `void edit_menu_map_entry(struct menu_map *map, size_t entrynum, const struct menu_map_entry *replace_entry);`

## Menu map editing

### Edit colors

`set_menu_map_colors`: edits the selected + unselected colors of the menu from provided color strings.

Example usage:

```C
struct menu_map *map = init_menu_map_from_array(entries);
set_menu_map_colors(map, "black", "blue"); // black selected, blue unselected

```

signature: `void set_menu_map_colors(struct menu_map *map, char *selected, char *unselected);`

### Edit pointer symbol

`set_menu_map_pointer_symbol`: sets the pointer symbol for the menu, e.g. ">"
Example usage:

```C
struct menu_map *map = init_menu_map_from_array(entries);
set_menu_map_pointer_symbol(map, ">");

```

signature: `void set_menu_pointer_symbol(struct menu_map *map, char *sym);`

### Edit spaces to sync

`set_menu_map_sync_spaces`: sets a unsigned int8 value of how many spaces to add to the unselected menu options to sync them in place with the pointer symbol, or make the selected option be indented/outdented.
Example usage:

```C
struct menu_map *map = init_menu_map_from_array(entries);
set_menu_map_pointer_symbol(map, "* *");
set_menu_map_sync_spaces(map, 4);

```

signature: `void set_menu_map_sync_spaces(struct menu_map *map, uint8_t spaces);`

## Menu drawing

### Draw a one-shot non-interactive menu

`draw_menu`: draws a menu based on a map and a current option variable, does not return a option as current is caller handled.
Example usage:

```C
struct menu_map *map = init_menu_map_from_array(entries);
draw_menu(map, 0); // current 0 = first option

```

signature: `void draw_menu(const struct menu_map *map, size_t current);`

### Draw a interactive menu

`interactive_menu`: draws a interactive menu making use of `draw_menu`, handles current, and returns a selected option/integer current + callbacks the selected function.
Example usage:

```C
struct menu_map *map = init_menu_map_from_array(entries);
menu_output_t output = interactive_menu(map); // start a menu and get output from intractive_memu

```

signature: `struct interactive_menu_output interactive_menu(const struct menu_map *map);`

**note**: `menu_output_t` is a typedef of `struct interactive_menu_output`

