#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the adjacency list
struct AdjList {
    struct Node* head;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Structure for the stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a new stack
struct Stack* createStack(unsigned capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
bool isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to the stack. It does not check for stack overflow
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to remove an item from the stack. It does not check for stack underflow
int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1; // Return -1 if stack is empty (can be handled differently)
}

// Function to return the top item of the stack without removing it
int peek(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top];
    return -1; // Return -1 if stack is empty (can be handled differently)
}

// Function to create a new adjacency list node
struct Node* newAdjListNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of given vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
    int i;
    for (i = 0; i < numVertices; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest in the adjacency list
    struct Node* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Depth First Search algorithm using a stack
void DFS(struct Graph* graph, int startVertex) {
    int numVertices = graph->numVertices;
    bool* visited = (bool*)malloc(numVertices * sizeof(bool));
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    struct Stack* stack = createStack(numVertices);

    push(stack, startVertex);
    visited[startVertex] = true;
    printf("Visited %d ", startVertex);

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);

        struct Node* adjList = graph->array[currentVertex].head;
        while (adjList != NULL) {
            int neighbor = adjList->data;
            if (!visited[neighbor]) {
                push(stack, neighbor);
                visited[neighbor] = true;
                printf("Visited %d ", neighbor);
            }
            adjList = adjList->next;
        }
    }
    printf("\n");
    free(visited);
    free(stack->array);
    free(stack);
}

int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Depth First Search starting from vertex 0: ");
    DFS(graph, 0);

    return 0;
}