#include "linked_list.h"
#include <stdlib.h>

void push(LinkedNode **head_ref, int new_data) {
    LinkedNode *new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node; // This explain why we need head_ref as pointer of pointer.
                            // We want to change the content of head-ref itself, not the content of it's copy.
}

void deleteNode(LinkedNode **head_ref, int key) {
    if (*head_ref == NULL) // If the linked list is empty
        return;

    LinkedNode *prev;
    LinkedNode *tmp = (*head_ref);

    if (tmp != NULL && tmp->data == key) {
        *head_ref = tmp->next; // Update the head pointer
        free(tmp); // Delete the first node
        return;
    }

    while (tmp != NULL && tmp->data != key) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) return;

    prev->next = tmp->next; // Skip the node which the data is equal to key
    free(tmp); // Delete the node which the data is equal to key
}

void push(DoublyLinkedNode **head_ref, int new_data) {
    DoublyLinkedNode* new_node = (DoublyLinkedNode*)malloc(sizeof(DoublyLinkedNode));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void deleteNode(DoublyLinkedNode **head_ref, DoublyLinkedNode *del) {
    // No need of a int key because we have direct access to previous node and next node from del node.
    // With singly linked list nodes, there is no way to directly modify the `next` pointer element of the previous node
    // seing that we don't know it's address
    if (*head_ref == NULL || del == NULL) // If the linked list is empty or the specified node is empty
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void circular_push(LinkedNode **head_ref, int new_data) {
    LinkedNode* new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
    LinkedNode* tmp = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        while (tmp->next != *head_ref)
            tmp = tmp->next;
        tmp->next = new_node;
    } else
        new_node->next = new_node;

    *head_ref = new_node;
}

void circular_deleteNode(LinkedNode **head_ref, int key) {
    if (*head_ref == NULL) return; // Return if the list contains no node

    LinkedNode* tmp = *head_ref;
    LinkedNode* prev = NULL;

    // Case 1: The node to be deleted is the head node
    if (tmp->data == key) {
        // Find the last node
        LinkedNode* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }

        // Now, last contains the last node

        // Only one node in the list
        if (last == *head_ref) {
            *head_ref = NULL;
            free(tmp);
            return;
        }

        // More than one node in the list
        // Unlink and delete the old head
        *head_ref = tmp->next;
        last->next = *head_ref;
        free(tmp);
        return;
    }

    // Case 2: The node to be deleted is not the head node
    while (tmp->next != *head_ref && tmp->data != key) {
        prev = tmp;
        tmp = tmp->next;
    }

    // Node not found
    if (tmp->data != key) {
        return;
    }

    // Node found, unlink it
    prev->next = tmp->next;
    free(tmp);
}

void circular_push(DoublyLinkedNode **head_ref, int new_data) {
    DoublyLinkedNode* new_node = (DoublyLinkedNode*)malloc(sizeof(DoublyLinkedNode));
    DoublyLinkedNode* last = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        while (last->next != *head_ref)
            last = last->next;
        last->next = new_node;
        (*head_ref)->prev = new_node;
        new_node->prev = last;
        *head_ref = new_node;
    } else {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head_ref = new_node;
    }
}

void circular_deleteNode(DoublyLinkedNode **head_ref, DoublyLinkedNode *del) {
    if (*head_ref == NULL || del == NULL)
        return;
    
    // Case 1: The node to be deleted is the head
    if(*head_ref == del) {
        // Only one node in the list
        if(del->next == *head_ref) {
            *head_ref = NULL;
            free(del);
            return;
        }

        // More than one node in the list
        *head_ref = del->next;
    }

    // Unlink the del node
    del->next->prev = del->prev;
    del->prev->next = del->next;

    free(del);
}