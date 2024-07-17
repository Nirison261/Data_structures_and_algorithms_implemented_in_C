/**
 * @file stack.h
 */

#ifndef DYNAMIC_STACK_H_
#define DYNAMIC_STACK_H_

#include "linked_list.h"

// Function to check if the stack is empty
int isEmpty(LinkedNode* root);

// Function to push an item to the stack
extern void push(LinkedNode** root, int data);

// Function to pop an item from the stack
int pop(LinkedNode** root);

// Function to get the top item of the stack
int peek(LinkedNode* root);

#endif