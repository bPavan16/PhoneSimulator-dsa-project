#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(unsigned capacity);

// Stack is full when top is equal to the last index
int isFull(Stack* stack);

// Stack is empty when top is -1
int isEmpty(Stack* stack);

// Function to add an item to stack. It increases top by 1
void push(Stack* stack, int item);

// Function to remove an item from stack. It decreases top by 1
int pop(Stack* stack);

// Function to return the top from stack without removing it
int peek(Stack* stack);

#endif // STACK_H