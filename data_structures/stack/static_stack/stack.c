#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linked_list.h"

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->items[stack->top];
}