/**
 * @file stack.h
 */

#ifndef STATIC_STACK_H_
#define STATIC_STACK_H_

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to create a stack
Stack* createStack();

// Function to check if the stack is empty
int isEmpty(Stack* stack);

// Function to check if the stack is full
int isFull(Stack* stack);

// Function to add an item to the stack
void push(Stack* stack, int item);

// Function to remove an item from the stack
int pop(Stack* stack);

// Function to get the top item of the stack (wihtout removing it)
int peek(Stack* stack);

#endif