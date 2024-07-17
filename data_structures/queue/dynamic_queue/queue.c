#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
In fact, the only element from the linked list library that is used here is the LinkedNode
structure. There is no need of functions like push or delete, because the set of pointers used here are not
exactly the same as those used on classical linked list.
The 'front' pointer behaves similarly like HEAD pointer but not completely.

HEAD vs front:

[SIMILARITIES]
- When elements are removed from the beginning of a linked list, the HEAD pointer is moved to the next
  node in the list. Similarly, when elements are dequeued from a queue, the front pointer is moved to the
  next node in the list.

[DIFFERENCES]
- On a classical linked list, when elements are added to the beginning of the list, the HEAD pointer
  is updated to the new element. But on a queue, there is no element added on the beginning (on front).

- In a queue, there's also a rear pointer that points to the last element, facilitating enqueue operations
  at the end of the list. A classical linked list might not have a rear pointer unless it's a special case like a doubly linked list or a circular linked list
*/

LinkedNode* createNode(int value) {
    LinkedNode* newNode = (LinkedNode*)malloc(sizeof(LinkedNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initializeQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int value) {
    LinkedNode* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("Enqueued %d\n", value);
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued %d\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    LinkedNode* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}