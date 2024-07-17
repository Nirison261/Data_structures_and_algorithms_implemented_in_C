#include <stdio.h>
#include "circular_queue.h"

void initializeQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

int isFull(CircularQueue* q) {
    return ((q->rear + 1) % SIZE == q->front);
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }

    // update q->rear and set it to be always inferior to SIZE
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, so reset the queue
        q->front = -1;
        q->rear = -1;
    } else {
        // Update q->front and ensure it to be always inferior to SIZE
        q->front = (q->front + 1) % SIZE;
    }
    return value;
}