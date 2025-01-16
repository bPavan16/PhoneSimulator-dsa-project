#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// Structure to represent a heap
struct Heap {
    int *array;     // Pointer to array of heap elements
    int capacity;   // Maximum number of elements in the heap
    int size;       // Current number of elements in the heap
};

// Function to create a heap of given capacity
struct Heap* createHeap(int capacity) {
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree rooted with node i
void heapify(struct Heap* heap, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);
    }
}

// Function to insert a new key 'k'
void insert(struct Heap* heap, int k) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    // First insert the new key at the end
    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove the element with the highest priority (root)
int extractMax(struct Heap* heap) {
    if (heap->size <= 0)
        return -1; // Heap is empty
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    // Store the maximum value, and remove it from heap
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Function to free the heap
void freeHeap(struct Heap* heap) {
    free(heap->array);
    free(heap);
}