#include "../include/file_handle.h"

#include <stdlib.h>

// creates and returns the file for the given arguments.
FILE *file_creation(const char *file_name, const char *arg) {
  FILE *return_file = fopen(file_name, arg);

  if (return_file == NULL) {
    fprintf(stderr, "Failed to open the file: %s\n", file_name);
    // Exiting the program due to the error
    exit(EXIT_FAILURE);
  }

  return return_file;
}