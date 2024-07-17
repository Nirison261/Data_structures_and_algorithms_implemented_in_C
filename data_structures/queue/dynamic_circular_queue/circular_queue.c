#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

/*
In fact, the only element from the linked list library that is used here is the LinkedNode
structure. There is no need of functions like push or delete, because the set of pointers used here are not
exactly the same as those used on classical linked list.
The 'front' pointer behaves similarly like HEAD pointer but not completely.
*/

LinkedNode* newNode(int k) {
    LinkedNode* temp = (LinkedNode*)malloc(sizeof(LinkedNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enQueue(struct Queue* q, int k) {
    // Create a new LL node
    LinkedNode* temp = newNode(k);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        q->rear->next = q->front; // Making it circular
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
    q->rear->next = q->front; // Maintaining the circular nature
}

void deQueue(struct Queue* q) {
    // If queue is empty, return NULL.
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    // If the queue has only one node
    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        // Store the previous front and move front one node ahead
        LinkedNode* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front; // Maintaining the circular nature
        free(temp);
    }
}