#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int *array;     // Pointer to the array of heap elements
    int capacity;   // Maximum number of elements in the heap
    int size;       // Current number of elements in the heap
} Heap;

// Function to create a heap of given capacity
Heap* createHeap(int capacity);

// Function to insert a new element into the heap
void insertHeap(Heap* heap, int element);

// Function to delete the root element from the heap
int deleteRoot(Heap* heap);

// Function to heapify a subtree rooted with node i
void heapify(Heap* heap, int index);

// Function to free the memory allocated for the heap
void freeHeap(Heap* heap);

#endif // HEAP_H