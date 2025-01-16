#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function declarations
Queue* createQueue();
int isEmpty(Queue* queue);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
void freeQueue(Queue* queue);

#endif // QUEUE_H