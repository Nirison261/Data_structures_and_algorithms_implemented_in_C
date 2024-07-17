#ifndef STATIC_CIRCULAR_QUEUE_H_
#define STATIC_CIRCULAR_QUEUE_H_

/*
Advantages of array-based circular queue over array-based standard queue:

- allows efficient use of memory because it wrap around when it reaches the end of the array. On standard
  queue, when there is a dequeueing operation, the front pointer increments and some memoies are left unused.
  In circular queue, these hanging memory caused by dequeuing can be used on enqueuing (for array-based queue
  only).

- It is easy to manage circular processes like round-robin scheduling, buffering, or circular list management.
  The cyclic nature simplifies these implementations.

- Usefull with operations that need to loop through the queue like iin circular buffer applications, thus you
  can keep reusing the buffer without needing to reset or manage the ends (no need to reimplement the wrap
  around functionnality).
*/

#define SIZE 5

typedef struct CircularQueue {
    int items[SIZE];
    int front, rear;
} CircularQueue;

// Function to initialize the queue
void initializeQueue(CircularQueue* q);

// Function to check if the queue is empty
int isEmpty(CircularQueue* q);

// Function to check if the queue is full
int isFull(CircularQueue* q);

// Function to add an element to the queue
void enqueue(CircularQueue* q, int value);

// Function to remove an element from the queue
int dequeue(CircularQueue* q);

#endif