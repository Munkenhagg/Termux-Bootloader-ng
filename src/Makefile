CC = gcc
CFLAGS = -O2 -march=native -Wall -Wextra -Wmaybe-uninitialized -Winit-self -Wpedantic -Wshadow -Wformat=2 -Wformat-security -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wconversion -Wsign-conversion -Wundef -Werror=shadow -Werror=format-security -fno-omit-frame-pointer -Wcast-qual -Wlogical-op -Wduplicated-cond -Wduplicated-branches -Wstrict-overflow=3 -Warray-bounds -Wstringop-overflow -Wnull-dereference -Wwrite-strings -Wold-style-definition -Wredundant-decls -Wnested-externs -Winline -Wdisabled-optimization -Wfloat-equal -Wswitch-default -Wswitch-enum -Wparentheses -Wsequence-point -Wbad-function-cast -Wpointer-arith -Wtype-limits -Wunreachable-code -MMD -MP
INCLUDE = -Iinclude
LDLIBS = -lncurses
ARCH = x86_64
OUT = arch/$(ARCH)/manager
BIN := $(OUT)/termux-bootloader-ng
SRC_MAIN := $(addprefix main/, TBL-ng.c)
SRC_MENU := $(addprefix menu/, draw_menu.c)
SRC_GLOBALINIT := initconf/initconf.c
SRC := $(SRC_GLOBALINIT) $(SRC_MENU) $(SRC_MAIN)
OBJ := $(patsubst %.c, build/%.o, $(SRC))

all: $(BIN)

build/%.o: %.c
	@printf "CC  %-40s => %s\n" "$<" "$@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BIN): $(OBJ)
	@mkdir -p $(dir $(BIN))
	@$(CC) $(OBJ) $(LDLIBS) -o $(BIN)

clean:
	rm -rf $(BIN) $(OBJ)

-include $(OBJ:.o=.d)

.PHONY: clean
