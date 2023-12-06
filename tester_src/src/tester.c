/* -----------------------------------------------------------------------------
 * File: main.c
 * Author: Aaron Shackelford
 * Date: Dec 4, 2023
 * Description:
 *   This program, developed for CSC 193 Operating Systems Assignment 4,
 *   processes data from an input.txt file and generates an output.txt file.
//
 *   To compile the program, use the provided Makefile with the command 'make'.
 *   To run the program, execute the command './a'. Ensure a valid './a'
 *   program is present in the same directory as the executable.
//
 *   To remove all files made by the makefile, run 'make clean'
 *
 * Tested on MACOS ARM_64,
 * Tested on Red Hat Enterprise Linux Server release 7.9 (Maipo) x86_64
 * -----------------------------------------------------------------------------
 */

// Rest of the main.c file...

// local libraries
#include "../include/file_handle.h"

// global libraries
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h> // io
#include <stdio.h>
#include <stdlib.h> // header for stderr and exit()
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// defines
#define MAX_LINE_LENGTH 4096

#define NUMBER_OF_TEST 5

#define PROGRAM "./a"

#define FALSE false
#define TRUE true
#define False false
#define True true

// Stucts

// Globals

// Prototypes

bool duplicateFile(const char *sourceFileName, const char *destinationFileName);
void runProgramA();
bool compareTextFiles(const char *file1, const char *file2);
void run();
void logMessage(const char *message);
bool deleteFile(const char *fileName);
bool createDirectory(const char *path);

// Functions

// removes file from directory
bool deleteFile(const char *fileName) {
  if (remove(fileName) == 0) {
    return true;
  } else {
    perror("tester.c deleteFile Error deleting file");
    return false;
  }
}

// Function to create a directory if it doesn't exist
bool createDirectory(const char *path) {
  if (mkdir(path, 0777) == -1) {
    // fprintf(stderr, "tester.c createDirectory Error creating directory %s\n",
    //         path);
    return false;
  }
  return true;
}

// duplicates old file to new
bool duplicateFile(const char *sourceFileName,
                   const char *destinationFileName) {
  // Check if the source file exists
  FILE *sourceFile = fopen(sourceFileName, "r");
  if (sourceFile == NULL) {
    fprintf(stderr, "tester.c duplicateFile Error opening source file\n%s\n",
            sourceFileName);
    return false;
  }

  // Extract directory from destinationFileName
  char *directory = malloc(strlen(destinationFileName) + 1);
  if (directory == NULL) {
    // Handle memory allocation failure
    fprintf(stderr, "Memory allocation error\n");
    fclose(sourceFile);
    return false;
  }

  strcpy(directory, destinationFileName);
  char *lastSlash = strrchr(directory, '/');
  if (lastSlash != NULL) {
    *lastSlash = '\0';
    createDirectory(directory);
  }

  free(directory);

  // Open the destination file for writing
  FILE *destinationFile = fopen(destinationFileName, "w");
  if (destinationFile == NULL) {
    fprintf(stderr,
            "tester.c duplicateFile Error opening destination file\n%s\n",
            destinationFileName);
    fclose(sourceFile);
    return false;
  }

  // NOTE Could this be redone as just copying the whole block of memory...
  // memcpy or something...
  //   I remember there was a way to do it with bits... maybe do it that way
  // it would probably be faster
  //   see how saving and loading files works for games, should be the same
  //   concept

  //    Copy the contents of the source file to the
  // destination file
  int ch;
  while ((ch = fgetc(sourceFile)) != EOF) {
    fputc(ch, destinationFile);
  }

  // Close the files
  fclose(sourceFile);
  fclose(destinationFile);

  return true;
}

// returns true if both files are the same
bool compareTextFiles(const char *file1, const char *file2) {
  FILE *fp1 = fopen(file1, "r");
  FILE *fp2 = fopen(file2, "r");

  if (fp1 == NULL || fp2 == NULL) {
    perror("tester.c compareTextFiles Error opening files");
    return false;
  }

  char line1[MAX_LINE_LENGTH];
  char line2[MAX_LINE_LENGTH];

  while (fgets(line1, sizeof(line1), fp1) != NULL &&
         fgets(line2, sizeof(line2), fp2) != NULL) {
    if (strcmp(line1, line2) != 0) {
      // Lines differ
      fclose(fp1);
      fclose(fp2);
      return false;
    }
  }

  // Check if one file is longer than the other
  if (fgets(line1, sizeof(line1), fp1) != NULL ||
      fgets(line2, sizeof(line2), fp2) != NULL) {
    // Files have different lengths
    fclose(fp1);
    fclose(fp2);
    return false;
  }

  // Files are identical
  fclose(fp1);
  fclose(fp2);
  return true;
}

// runs PROGRAM a by default, can change with macro
void runProgramA() {
  // Fork a new process
  pid_t pid = fork();

  if (pid == -1) {
    // Forking failed
    perror("tester.c runProgramA Fork failed");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    // This is the child process
    // Replace "a" with the actual name of the program you want to run
    const char *programPath = PROGRAM;

    // Execute program "a"
    execl(programPath, programPath, NULL);

    // If execl fails
    perror("tester.c runProgramA Exec failed");
    exit(EXIT_FAILURE);
  } else {
    // This is the parent process
    // Wait for the child process to complete
    int status;
    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
      // exited normally
      //   printf("tester.c runProgramA Program %s exited with status %d\n",
      //   PROGRAM,
      //          WEXITSTATUS(status));
    } else {
      fprintf(stderr, "tester.c runProgramA Program %s did not exit normally\n",
              PROGRAM);
    }
  }
}

void logMessage(const char *message) {
  FILE *file = fopen("test_log.txt", "a"); // "a" opens the file for appending

  if (file != NULL) {
    fprintf(file, "%s\n", message);
    fclose(file);
  } else {
    // Handle error opening the file
    printf("tester.c logMessage Error opening file for writing.\n");
  }
}

void run() {
  // Specify the number of test cases
  //   int num_tests = 5; // Change this to the actual number of test cases you
  //   have
  // make this change in NUMBER_OF_TEST, made a define so that we can pass it as
  // argument

  char test[50];
  char testo[50];
  char bad_dest_Output[50];
  char bad_dest_test[50];
  char bad_dest_testo[50];
  char errorMessage[MAX_LINE_LENGTH];

  bool all_good = true;

  // make sure input exists
  const char *input_source = "input.txt";
  const char *output_source = "output.txt";
  FILE *tmp = file_creation(input_source, "w");
  fclose(tmp);

  // Loop to iterate through each test case
  // test
  int i;
  for (i = 1; i <= NUMBER_OF_TEST; i++) {
    sprintf(test, "Assignment_4_test_cases/test%d.txt", i);
    sprintf(testo, "Assignment_4_test_cases/test%do.txt", i);

    // copy data into input.txt and output.txt
    duplicateFile(test, input_source);
    duplicateFile(testo, output_source);

    // have program "a" process the data.
    // macro PROGRAM
    runProgramA();

    if (FALSE == compareTextFiles(output_source, testo)) {
      all_good = false;
      // Format the error message
      sprintf(errorMessage, "%s failed\n", testo);

      logMessage(errorMessage);
      printf("%s", errorMessage);

      sprintf(bad_dest_test, "Bad_Output/input%d.txt", i);
      sprintf(bad_dest_Output, "Bad_Output/output%d.txt", i);
      sprintf(bad_dest_testo, "Bad_Output/test%do.txt", i);

      duplicateFile(testo, bad_dest_testo);
      duplicateFile(output_source, bad_dest_Output);
      duplicateFile(test, bad_dest_test);
    }
  }
  if (all_good) {
    const char *flyingColors = "Passed with Flying Colors!";
    logMessage(flyingColors);
    printf("%s", flyingColors);
  }
}

int main() {
  logMessage("=== new run ===");
  bool was_input = false;
  bool was_output = false;

  const char *input_source = "input.txt";
  const char *output_source = "output.txt";

  const char *input_tmp = "input_tmp.txt";
  const char *output_tmp = "output_tmp.txt";

  // copy file over
  was_input = duplicateFile(input_source, input_tmp);
  was_output = duplicateFile(output_source, output_tmp);

  // run test cases
  run();

  // if file existed before return it back to what it was before the program ran
  if (was_input) {
    was_input = duplicateFile(input_tmp, input_source);
    deleteFile(input_tmp);
  }
  if (was_output) {
    was_input = duplicateFile(output_tmp, output_source);
    deleteFile(output_tmp);
  }

  return 0;
}