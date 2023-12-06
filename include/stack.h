#include "node.h"
#include <stdbool.h>

#define FALSE false
#define TRUE true

#pragma once

// Structure to represent the dynamic stack
typedef struct {
    Node* top;  // Pointer to the top node
    int size;   // Current number of elements in the stack
} Stack;

// Stack Function prototypes
// adds the int to the stack
bool push(Stack * stack, int item);
// removes an int from the stack
int pop(Stack * stack);
// Function to free the memory used by the stack
void freeStack(Stack *stack);
// Function to free all the memory used by the stack, will need to reinit
void destroyStack(Stack * stack);
// Function to check if the stack is empty
int stackIsEmpty(Stack * stack);
// returns the stacks's size
int stackSize(Stack *stack);
// Function to create an empty stack
Stack * createStack();
// swaps two stacks
void swap_stack(Stack ** , Stack ** );
// Function to print the stack
void printStack(Stack * stack);