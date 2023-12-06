/* -----------------------------------------------------------------------------
 * File: main.c
 * Author: name last
 * Date: 
 * Description:
 *   This program, developed for CSC 193 Operating Systems Assignment 4,
 *   processes data from an input.txt file and generates an output.txt file.
//
 *   To compile the program, use the provided Makefile with the command 'make'.
 *   To run the program, execute the command './a'. Ensure a valid input.txt
 *   file is present in the same directory as the executable.
//
 *   To debug the program, use the provided Makefile with the command
 *   'make debug'. Then execute the command 'lldb ./a_debug'.
 *   Ensure a valid input.txt file is present in the same directory
 *   as the executable.
//
 *   To remove all files made by the makefile, run 'make clean'
 *
 * Tested on 
 * Tested on Red Hat Enterprise Linux Server release 7.9 (Maipo) x86_64
 *    ecs-pa-coding1.ecs.csus.edu
 * -----------------------------------------------------------------------------
 */

// Rest of the main.c file...

// local libraries
#include "../include/queue.h"
#include "../include/stack.h"
#include "example.c"

// global libraries


// defines


// Stucts


// Globals


// Share Globals


// Prototypes


// Functions


int main() {

    // Stack Queue example:
    Stack *stack_var =  createStack();
    Queue *queue_var =  createQueue();

    int tmp = 10;
    // defined outside a loop for REDHAT stdc99
    //  which is what the ECS server runs on
    int i; 

    // Queue functions example
    for(i = 0; i<10;i++){
        enqueue(queue_var, tmp);
    }

    for(i = 0; i<10;i++){
        tmp =  dequeue(queue_var);
    }

    // Stack functions example
    for(i = 0; i<10;i++){
        push(stack_var, tmp);
    }
    for(i = 0; i<10;i++){
        tmp = pop(stack_var);
    }

    // see queue.h and stack.h in include/ for more functions

    // to avoid memory leaks remember to destroy your queues and stacks
    // once finished with them at the end of a function
    destroyQueue(queue_var);
    destroyStack(stack_var);

  return 0;
}