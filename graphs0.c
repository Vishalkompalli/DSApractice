#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct graph
{
    int numvertices;
    struct node** adjlist; 
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

struct graph* creategraph(int vertices)
{
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->numvertices = vertices;
    graph->adjlist = (struct node**)malloc(vertices * sizeof(struct node*));
    int i;
    for(i=0;i<vertices;i++)
    {
        graph->adjlist[i] = NULL; //initialize each adjacency list as empty
    }
    return graph;
} 

void addedge(struct graph* graph, int src, int dest)
{
    struct node* newnode = createnode(dest);
    newnode->next = graph->adjlist[src];
    graph->adjlist[src]=newnode;

    newnode = createnode(src);
    newnode->next = graph->adjlist[dest];
    graph->adjlist[dest] = newnode;

}
