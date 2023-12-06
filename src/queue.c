#include "../include/queue.h"

#include <stdio.h>
#include <stdlib.h>

// QUEUE Data Structure Functions:

// Function to create an empty queue
Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (!queue) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  queue->front = queue->rear = NULL;
  queue->size = 0;
  return queue;
}

// Function to check if the queue is empty
int queueIsEmpty(Queue *queue) { return queue->front == NULL; }

// Function to enqueue an element into the queue
bool enqueue(Queue *queue, int item) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    fprintf(stderr, "Memory allocation failed.\n");
    return FALSE;
  }
  newNode->data = item;
  newNode->next = NULL;

  if (queueIsEmpty(queue)) {
    queue->front = queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }

  queue->size++;
  return TRUE;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue) {
  if (queueIsEmpty(queue)) {
    fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
    exit(1);
  }
  Node *frontNode = queue->front;
  int item = frontNode->data;

  if (queue->front == queue->rear) {
    queue->front = queue->rear = NULL;
  } else {
    queue->front = frontNode->next;
  }

  free(frontNode);

  queue->size--;
  return item;
}

// Function to get the size of the queue
int queueSize(Queue *queue) { return queue->size; }

// Function to free the memory allocated for the queue nodes
void freeQueue(Queue *queue) {
  while (!queueIsEmpty(queue)) {
    dequeue(queue);
  }
}

// Function to free the memory used by the queue
void destroyQueue(Queue *queue) {
  while (!queueIsEmpty(queue)) {
    dequeue(queue);
  }
  free(queue);
}

void swap_queue(Queue **ptr1, Queue **ptr2) {
  // If this fails, just dequeue one into a tmp and do a swappero.
  Queue *temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

// Function to print the queue
void printQueue(Queue *queue) {
  Node *current = queue->front;
  printf("Queue: ");
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}