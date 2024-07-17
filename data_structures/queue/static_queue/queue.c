#include "queue.h"
#include <stdio.h>

/*
How it works:

1. Initialization: Initially, both front and rear are set to -1, indicating an empty queue.

2. Enqueue: When an element is enqueued for the first time, front is set to 0 and rear is incremented
   to 0. Subsequent enqueues only increment rear.

3. Dequeue: When an element is dequeued, front is incremented. If all elements are dequeued, front becomes
   greater than rear.
*/

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == SIZE - 1;
}

int isEmpty(Queue *q) {
    // Check if the queue is empty
    // 1. Initially, both front and rear are -1.
    // 2. If all elements are dequeued, front becomes greater than rear.
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }

    // Store the new value on the queue and increment q->rear to 0
    q->items[++q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    // store temporarily the value of q->items[q->front] and after, inrement q->front
    int value = q->items[q->front++];

    // Because of the following instruction, there is actually no need of the test q->front > q->rear
    // on isEmpty() funtion (so, delete it if you want to optimize your code !) 
    if (q->front > q->rear) {
        initializeQueue(q);
    }
    return value;
}