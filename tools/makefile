#
# Makefile for C++ Project
#
MAKEFLAGS += --no-print-directory

SRC_DIR = ../src
INC_DIR = ../include
OBJ_DIR = ../build/bin/release/obj
BIN_DIR = ../build/bin/release
DEBUG_OBJ_DIR = ../build/bin/debug/obj
DEBUG_BIN_DIR = ../build/bin/debug

# Compiler Flags
CC = clang++
CFLAGS = -Wall -c -I$(INC_DIR)
DEBUG_CFLAGS = $(CFLAGS) -g -O0
RELEASE_CFLAGS = $(CFLAGS) -O3
XLIB_CFLAGS = -lX11

# List of Source Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/**/*.cpp)

# List of Object Files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
DEBUG_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(DEBUG_OBJ_DIR)/%.o, $(SRC_FILES))

# List of Dependency Files
DEP_FILES := $(wildcard $(INC_DIR)/*.hpp)

# Main Target
all: $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(XLIB_CFLAGS) -o $(BIN_DIR)/main

debug: $(DEBUG_OBJ_FILES) $(patsubst $(DEBUG_OBJ_DIR)/%.o, $(DEBUG_OBJ_DIR)/%.s, $(DEBUG_OBJ_FILES))
	$(CC) $(DEBUG_OBJ_FILES) -o $(DEBUG_BIN_DIR)/main

%.s: %.o
	objdump -S -M intel $< > $@@

# Compile Source Files
$(OBJ_FILES): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_FILES)
	mkdir -p $(dir $@)
	$(CC) $(RELEASE_CFLAGS) $< -o $@

# Compile Source Files with Debugging Enabled
$(DEBUG_OBJ_FILES): $(DEBUG_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_FILES)
	mkdir -p $(dir $@)
	$(CC) $(DEBUG_CFLAGS) $< -o $@

# Generate assembly files from object files
$(DEBUG_OBJ_DIR)/%.s: $(DEBUG_OBJ_DIR)/%.o
	objdump -S $< > $@

# Clean Target
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)/main $(DEBUG_OBJ_DIR) $(DEBUG_BIN_DIR)/main

run:
ifneq ($(wildcard $(BIN_DIR)/main),)
	@echo -e "\033[1;37;44mRelease Mode\033[0m"
	@echo
	@time "$(BIN_DIR)/main"
else
	@echo -e "\033[1;37;46mDebug Mode\033[0m"
	@echo
	@time "$(DEBUG_BIN_DIR)/main"
endif

# Default Target
.DEFAULT_GOAL := all

.PHONY: clean run