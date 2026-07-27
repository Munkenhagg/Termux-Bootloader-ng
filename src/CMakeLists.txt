cmake_minimum_required(VERSION 3.20)

project(Termux-bootloader-ng VERSION 1.3.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_EXTENSIONS OFF)

include(GNUInstallDirs)

find_package(Curses REQUIRED COMPONENTS NCURSES)

if(NOT TARGET Curses::Curses)
	add_library(Curses::Curses INTERFACE IMPORTED)
	set_target_properties(Curses::Curses PROPERTIES
		INTERFACE_INCLUDE_DIRECTORIES "${CURSES_INCLUDE_DIRS}"
		INTERFACE_LINK_LIBRARIES "${CURSES_LIBRARIES}"
	)
endif()

set(ARCH ${CMAKE_SYSTEM_PROCESSOR})
set(OUT "${CMAKE_CURRENT_SOURCE_DIR}/arch/${ARCH}/out")
set(MANAGER_D "${OUT}/manager")
set(LIB_D "${OUT}/framework")
set(COM_GCC FALSE)
set(COM_CLANG FALSE)

set(MAIN_FILES
	TBL-ng.c
	parse_json.c
)
set(MENU_FILES
	draw_menu.c
	interactive_menu.c
	init_menu_map_from_array.c
	delete_menu_map.c
	set_menu_map_colors.c
	set_menu_map_pointer_symbol.c
	set_menu_map_sync_spaces.c
	edit_menu_map_entry.c
	menu_map_to_optstrarr.c
)
set(INITCONF_FILES
	initconf_core.c
	initconf_bl.c
)
set(CJSON_FILES
	cJSON.c
)
set(THEMES_FILES
	init_themes.c
	look_theme2pair.c
)

set(BL_MENU_FILES
	main.c
	main/enter_shell.c
	main/login.c
	main/manage_users.c
	main/settings.c
	main/advanced_options.c
	main/quit.c
)
set(VERSION_FILES
	tblng_get_version_struct.c
	tblng_get_version_str.c
)

list(TRANSFORM MAIN_FILES PREPEND "main/")
list(TRANSFORM MENU_FILES PREPEND "menu/")
list(TRANSFORM INITCONF_FILES PREPEND "initconf/")
list(TRANSFORM CJSON_FILES PREPEND "cJSON/")
list(TRANSFORM THEMES_FILES PREPEND "themes/")
list(TRANSFORM BL_MENU_FILES PREPEND "BLmenus/")
list(TRANSFORM VERSION_FILES PREPEND "version/")

set(FULL_SRC
	${MAIN_FILES}
	${MENU_FILES}
	${VERSION_FILES}
	${THEMES_FILES}
	${INITCONF_FILES}
	${CJSON_FILES}
	${BL_MENU_FILES}
	initconf/initconf_core.c
	initconf/initconf_bl.c
)

set(LIB_SRC
	${MENU_FILES}
	${VERSION_FILES}
	initconf/initconf_core.c
)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        set(COM_GCC TRUE)
        message(STATUS "Using GCC ${CMAKE_C_COMPILER_VERSION}")
elseif(CMAKE_C_COMPILER_ID STREQUAL "Clang" OR CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
        set(COM_CLANG TRUE)
        message(STATUS "Using Clang ${CMAKE_C_COMPILER_VERSION}")
endif()

set(CFLAGS -O2 -march=native -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wformat-security -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wconversion -Wsign-conversion -Wundef -Werror=shadow -Werror=format-security -fno-omit-frame-pointer -Wcast-qual -Wredundant-decls -Winline -Wfloat-equal -Wswitch-default -Wswitch-enum -Wparentheses -Wbad-function-cast -Wpointer-arith -Wtype-limits -Wunreachable-code)

if(COM_GCC)
        set(CFLAGS ${CFLAGS} -Wmaybe-uninitialized -Wlogical-op -Wduplicated-cond -Wduplicated-branches -Wstrict-overflow=3 -Warray-bounds -Wstringop-overflow -Wnull-dereference)
endif()

option(MENU_COLOR_SUPPORT "Adds color support to menus" ON)

option(BUILD_EXPERIMENTAL_FRAMEWORK "Build the experimental framework core" OFF)

option(USE_DEBUG_BUILD "Makes debbugging in gdb or similar easier as more variables are exposed" OFF)

configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/include/tblng-version.h.in"
	"${CMAKE_CURRENT_BINARY_DIR}/include/gen-tblng-version.h"
)
if(BUILD_EXPERIMENTAL_FRAMEWORK)
	add_library(tblng-framework SHARED ${LIB_SRC})
	set_target_properties(tblng-framework PROPERTIES
		LIBRARY_OUTPUT_DIRECTORY ${LIB_D}
		OUTPUT_NAME tblng
	)
	add_library(tblng-framework-static STATIC ${LIB_SRC})
	set_target_properties(tblng-framework-static PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${LIB_D}
		OUTPUT_NAME tblng
	)
	target_include_directories(tblng-framework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include)
	target_include_directories(tblng-framework-static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include)
	target_link_libraries(tblng-framework PRIVATE Curses::Curses)
	target_link_libraries(tblng-framework-static PRIVATE Curses::Curses)
	target_compile_options(tblng-framework PRIVATE "${CFLAGS}")
	target_compile_options(tblng-framework-static PRIVATE "${CFLAGS}")
	if(MENU_COLOR_SUPPORT)
		target_compile_definitions(tblng-framework PRIVATE MENU_COLOR_SUPPORT)
		target_compile_definitions(tblng-framework-static PRIVATE MENU_COLOR_SUPPORT)
	endif()
	if(USE_DEBUG_BUILD)
		target_compile_definitions(tblng-framework PRIVATE DEBUG_BUILD)
		target_compile_definitions(tblng-framework-static PRIVATE DEBUG_BUILD)
	endif()
	install(TARGETS tblng-framework tblng-framework-static
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	)
endif()

add_executable(termux-bootloader-ng ${FULL_SRC})
set_target_properties(termux-bootloader-ng PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${MANAGER_D}
	OUTPUT_NAME termux-bootloader-ng
)
target_include_directories(termux-bootloader-ng PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include)
target_link_libraries(termux-bootloader-ng PRIVATE Curses::Curses)
target_compile_options(termux-bootloader-ng PRIVATE "${CFLAGS}")
if(MENU_COLOR_SUPPORT)
	target_compile_definitions(termux-bootloader-ng PRIVATE MENU_COLOR_SUPPORT)
endif()
if(USE_DEBUG_BUILD)
	target_compile_definitions(termux-bootloader-ng PRIVATE DEBUG_BUILD)
endif()
install(TARGETS termux-bootloader-ng
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
