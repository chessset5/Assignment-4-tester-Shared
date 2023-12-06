# -----------------------------------------------------------------------------
# Makefile for CSC 193 Operating Systems Assignment 4
# -----------------------------------------------------------------------------
# Author: Aaron Shackelford
# Date: Dec 4, 2023
# -----------------------------------------------------------------------------
# Description:
# This Makefile is designed to compile and build the program for Assignment 4
# in the Operating Systems course (CSC 193). The program processes data from
# an input.txt file and generates an output.txt file.
#
# Instructions:
# - To compile the program, use the command: make
# - To run the program, use the command: ./a
# - Ensure that a valid input.txt file is present in the same directory as ./a
# - The program will generate an output.txt file as a result.
# 
# Debug Instructions:
# - To compile the program, use the command: make debug
# - To run the program, use the command: lldb ./a_debug
# - Ensure that a valid input.txt file is present in the same directory as ./a_debug
# - The program will generate an output.txt file as a result. 
# 
# Clean Instructions:
# - To compile the program, use the command: make clean
# - removes all files created by the makefile
# 
# -----------------------------------------------------------------------------

# Makefile for the project

# Compiler and flags
CC := gcc
CFLAGS := -w -Wall -Iinclude -std=c99

# Debug flags
DEBUG_FLAGS := -g

# Source files
SRC_DIR := src
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ_DIR := obj
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Executable
TARGET := a
DEBUG_TARGET := a_debug

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@


# Debug build rule
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(DEBUG_TARGET)
