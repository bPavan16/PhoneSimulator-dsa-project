#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack. It decreases top by 1
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return an invalid value
    }
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return an invalid value
    }
    return stack->array[stack->top];
}