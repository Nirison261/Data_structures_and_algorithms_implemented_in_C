#ifndef DYNAMIC_QUEUE_H_
#define DYNAMIC_QUEUE_H_

#include "linked_list.h"

typedef struct Queue {
    LinkedNode* front;
    LinkedNode* rear;
} Queue;

// Function to create a new node
LinkedNode* createNode(int value);

// Function to initialize the queue
void initializeQueue(Queue* q);

// Function to check if the queue is empty
int isEmpty(Queue* q);

// Function to enqueue an element
void enqueue(Queue* q, int value);

// Function to dequeue an element
int dequeue(Queue* q);

#endif