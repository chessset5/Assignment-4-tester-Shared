
#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

// Stack Data Structure Functions:

// Function to create an empty stack
Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (!stack) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

// Function to check if the stack is empty
int stackIsEmpty(Stack *stack) { return stack->top == NULL; }

// Function to get the current size of the stack
int stackSize(Stack *stack) { return stack->size; }

// Function to push an element onto the stack
bool push(Stack *stack, int item) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  // linking new top
  newNode->data = item;
  newNode->next = stack->top;

  // updating top and size
  stack->top = newNode;
  stack->size++;
  return TRUE;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
  if (stackIsEmpty(stack)) {
    fprintf(stderr, "Stack is empty. Cannot pop.\n");
    exit(1);
  }
  Node *topNode = stack->top;
  int item = topNode->data;
  stack->top = topNode->next;
  free(topNode);

  // update size
  stack->size--;
  return item;
}

// Function to free the memory used by the stack
void freeStack(Stack *stack) {
  while (stack->top != NULL) {
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
  }

  stack->size = 0;
}

// Function to free the memory used by the stack
void destroyStack(Stack *stack) {
  while (!stackIsEmpty(stack)) {
    Node *topNode = stack->top;
    stack->top = topNode->next;
    free(topNode);
  }
  free(stack);
}

void swap_stack(Stack **ptr1, Stack **ptr2) {
  // If this fails, just pop one into a tmp and do a swappero.
  Stack *temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

// Function to print the stack
void printStack(Stack *stack) {
  Node *current = stack->top;
  printf("Stack: ");
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}