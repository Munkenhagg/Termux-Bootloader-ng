cmake_minimum_required(VERSION 3.20)

project(Termux-bootloader-ng LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
)
set(INITCONF_FILES
	initconf.c
)
set(CJSON_FILES
	cJSON.c
)
set(THEMES_FILES
	init_themes.c
	look_theme2pair.c
)
list(TRANSFORM MAIN_FILES PREPEND "main/")
list(TRANSFORM MENU_FILES PREPEND "menu/")
list(TRANSFORM INITCONF_FILES PREPEND "initconf/")
list(TRANSFORM CJSON_FILES PREPEND "cJSON/")
list(TRANSFORM THEMES_FILES PREPEND "themes/")

set(FULL_SRC
	${MAIN_FILES}
	${MENU_FILES}
	${THEMES_FILES}
	${INITCONF_FILES}
	${CJSON_FILES}
)

set(LIB_SRC
	${MENU_FILES}
	${INITCONF_FILES}
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

option(BUILD_EXPERIMENTAL_FRAMEWORK "Build the experimental framework core" OFF)

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
	target_include_directories(tblng-framework PUBLIC include)
	target_include_directories(tblng-framework-static PUBLIC include)
	target_link_libraries(tblng-framework PRIVATE Curses::Curses)
	target_link_libraries(tblng-framework-static PRIVATE Curses::Curses)
	target_compile_options(tblng-framework PRIVATE "${CFLAGS}")
	target_compile_options(tblng-framework-static PRIVATE "${CFLAGS}")
endif()

add_executable(termux-bootloader-ng ${FULL_SRC})
set_target_properties(termux-bootloader-ng PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${MANAGER_D}
    OUTPUT_NAME termux-bootloader-ng
)
target_include_directories(termux-bootloader-ng PRIVATE include)
target_link_libraries(termux-bootloader-ng PRIVATE Curses::Curses)
target_compile_options(termux-bootloader-ng PRIVATE "${CFLAGS}")
