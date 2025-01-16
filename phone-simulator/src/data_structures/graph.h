#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES];
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function declarations
Graph* createGraph();
void addVertex(Graph* graph, int vertex);
void addEdge(Graph* graph, int src, int dest);
void removeEdge(Graph* graph, int src, int dest);
bool hasEdge(Graph* graph, int src, int dest);
void displayGraph(Graph* graph);
void freeGraph(Graph* graph);

#endif // GRAPH_H