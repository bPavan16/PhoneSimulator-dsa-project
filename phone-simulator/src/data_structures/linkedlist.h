#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

// Function declarations
LinkedList* createLinkedList();
void insertAtBeginning(LinkedList* list, int data);
void insertAtEnd(LinkedList* list, int data);
void deleteNode(LinkedList* list, int key);
void displayList(LinkedList* list);
void freeList(LinkedList* list);

#endif // LINKEDLIST_H