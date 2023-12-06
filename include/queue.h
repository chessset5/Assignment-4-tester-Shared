#include "node.h"
#include <stdbool.h>

#define FALSE false
#define TRUE true

#pragma once

// Structure to represent the queue
typedef struct {
    Node * front;
    Node * rear;
    int size;
}
Queue;

// Queue Function prototypes
// adds int to queue*, returns TRUE if can enqueue
bool enqueue(Queue * queue, int item);
// removes in from queue*, returns QUEUE_EMPTY if queue empty
int dequeue(Queue * queue);
// initializes queue
Queue * createQueue();
// Function to check if the queue is empty
int queueIsEmpty(Queue * queue);
// returns size
int queueSize( Queue *queue) ;
// Function to free the memory used by the queue
void freeQueue(Queue *queue);
// Function to all free the memory used by the queue, will need to init again.
void destroyQueue(Queue * queue);
// swaps two queues
void swap_queue(Queue ** , Queue ** );
// Function to print the queue
void printQueue(Queue * queue);