# Makefile for a project using SDL2 on macOS

# Compiler
CC = clang

# SDL2 version
SDL2_VERSION = 2.30.7

# Directories
SDL2_INCLUDE_DIR = /usr/local/Cellar/sdl2/$(SDL2_VERSION)/include
SDL2_LIB_DIR = /usr/local/Cellar/sdl2/$(SDL2_VERSION)/lib

# Compiler and linker flags
CFLAGS = -Wall -Wextra -I$(SDL2_INCLUDE_DIR)
LDFLAGS = -L$(SDL2_LIB_DIR) -lSDL2

# Source files
SRCS = main.c

# Output binary
TARGET = main

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Clean rule to remove generated files
clean:
	rm -f $(TARGET)

