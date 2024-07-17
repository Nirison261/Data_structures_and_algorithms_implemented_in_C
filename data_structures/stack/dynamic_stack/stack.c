#include "stack.h"
#include "linked_list.h"
#include <stdio.h>

int isEmpty(LinkedNode* root) {
    return !root;
}

/*
// We can use the push function of the singly linked list library
void push(LinkedNode** root, int data) {

}
*/

int pop(LinkedNode** root) {
    if (isEmpty(*root)) {
        printf("Stack underflow\n");
        return -1;
    }

    LinkedNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(LinkedNode* root) {
    if (isEmpty(root)) {
        printf("Stack is empty\n");
        return -1;
    }
    return root->data;
}