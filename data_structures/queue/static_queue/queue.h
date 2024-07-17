#ifndef STATIC_QUEUE_H_
#define STATIC_QUEUE_H_

#define SIZE 100

typedef struct Queue {
    int items[SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q);

int isFull(Queue *q);

int isEmpty(Queue *q);

void enqueue(Queue *q, int value);

int dequeue(Queue *q);

#endif