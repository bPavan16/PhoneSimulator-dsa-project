#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Create an adjacency matrix
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize with 0
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Add edge from src to dest
    graph->adjMatrix[dest][src] = 1; // Add edge from dest to src (for undirected graph)
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}