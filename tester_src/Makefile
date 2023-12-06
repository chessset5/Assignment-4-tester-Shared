CC = gcc
CFLAGS = -Wall -Werror -std=c99
INCLUDES = -Iinclude

SRC_DIR = src
OBJ_DIR = obj

# Use wildcard to find all .c files in the src directory
SRC = $(wildcard $(SRC_DIR)/*.c)

# Generate corresponding object files in the obj directory
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: tester

tester: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule for building object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f tester $(OBJ_DIR)/*.o
