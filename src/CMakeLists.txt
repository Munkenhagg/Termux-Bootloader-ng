cmake_minimum_required(VERSION 3.20)

project(Termux-bootloader-ng LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

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

file(MAKE_DIRECTORY "${MANAGER_D}")
file(MAKE_DIRECTORY "${LIB_D}")

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
    target_include_directories(tblng-framework PRIVATE include)
    target_include_directories(tblng-framework-static PRIVATE include)
    target_link_libraries(tblng-framework PRIVATE Curses::Curses)
    target_link_libraries(tblng-framework-static PRIVATE Curses::Curses)
endif()

add_executable(termux-bootloader-ng ${FULL_SRC})
set_target_properties(termux-bootloader-ng PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${MANAGER_D}
    OUTPUT_NAME termux-bootloader-ng
)
target_include_directories(termux-bootloader-ng PRIVATE include)
target_link_libraries(termux-bootloader-ng PRIVATE Curses::Curses)

