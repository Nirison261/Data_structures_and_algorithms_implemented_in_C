#ifndef DYNAMIC_CIRCULAR_QUEUE_H_
#define DYNAMIC_CIRCULAR_QUEUE_H_

#include "linked_list.h"

// The queue, front stores the front node of LL and rear stores the last node of LL
struct Queue {
    LinkedNode *front, *rear;
};

// A utility function to create a new linked list node.
LinkedNode* newNode(int k);

// A utility function to create an empty queue
struct Queue* createQueue();

// Check if the queue is empty
int isEmpty(Queue* q);

// The function to add a key k to q
void enQueue(struct Queue* q, int k);

// Function to remove a key from given queue q
void deQueue(struct Queue* q);

#endif