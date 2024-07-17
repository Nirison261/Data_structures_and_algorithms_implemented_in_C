/**
 * @file linked_list.h
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct {
    int data;
    LinkedNode *next;
} LinkedNode;

typedef struct {
    int data;
    DoublyLinkedNode *prev;
    DoublyLinkedNode *next;
}DoublyLinkedNode;

/**
 * @brief  Function to insert a new node at the beginning of a singly linked list.
 * @param  head_ref address of the head pointer.
 * @param  new_data the data of the new linked list node.
 * @return none.
 */
void push(LinkedNode **head_ref, int new_data);

/**
 * @brief  Function to delete a singly linked list node where the data is the first occurence of a key
 * @param  head_ref address of the head pointer.
 * @param  key the key
 * @return none.
 */
void deleteNode(LinkedNode **head_ref, int key);

/**
 * @brief  Function to insert a new node at the beginning of a doubly linked list.
 * @param  head_ref address of the head pointer.
 * @param  new_data the data of the new linked list node.
 * @return none.
 */
void push(DoublyLinkedNode **head_ref, int new_data);

/**
 * @brief  Function to delete a doubly linked list node.
 * @param  head_ref address of the head pointer.
 * @param  del addres of the node to be deleted
 * @return none.
 */
void deleteNode(DoublyLinkedNode **head_ref, DoublyLinkedNode* del);

/**
 * @brief  Function to insert a new node at the beginning of a circular singly linked list.
 * @param  head_ref address of the head pointer.
 * @param  new_data the data of the new linked list node.
 * @return none.
 */
void circular_push(LinkedNode **head_ref, int new_data);

/**
 * @brief  Function to delete a circular singly linked list node where the data is the first occurence of a key
 * @param  head_ref address of the head pointer.
 * @param  key the key
 * @return none.
 */
void circular_deleteNode(LinkedNode **head_ref, int key);

/**
 * @brief  Function to insert a new node at the beginning of a circular doubly linked list.
 * @param  new_data the data of the new linked list node.
 * @param  head_ref address of the head pointer.
 * @return none.
 */
void circular_push(DoublyLinkedNode **head_ref, int new_data);

/**
 * @brief  Function to delete a circular doubly linked list node.
 * @param  head_ref address of the head pointer.
 * @param  del addres of the node to be deleted
 * @return none.
 */
void circular_deleteNode(DoublyLinkedNode **head_ref, DoublyLinkedNode* del);

#endif